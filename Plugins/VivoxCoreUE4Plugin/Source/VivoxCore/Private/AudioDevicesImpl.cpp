/* Copyright (c) 2014-2018 by Mercer Road Corp
 *
 * Permission to use, copy, modify or distribute this software in binary or source form
 * for any purpose is allowed only under explicit prior consent in writing from Mercer Road Corp
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND MERCER ROAD CORP DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL MERCER ROAD CORP
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#include "AudioDevicesImpl.h"
#include "VivoxCore.h"
#include "VxcErrors.h"
#include "VivoxNativeSdk.h"

static const FString NULL_DEVICE_ID = "No Device";
static const FString SYSTEM_DEVICE_ID = "Default System Device";
static const FString COMMUNICATION_DEVICE_ID = "Default Communication Device";

AudioDevicesImpl::AudioDevicesImpl(AudioDeviceType type): _noDevice(NULL_DEVICE_ID, NULL_DEVICE_ID, DeviceType::NullDevice), _systemDevice(SYSTEM_DEVICE_ID, SYSTEM_DEVICE_ID, DeviceType::DefaultSystemDevice),
                                                          _communicationDevice(COMMUNICATION_DEVICE_ID, COMMUNICATION_DEVICE_ID, DeviceType::DefaultCommunicationDevice), _volumeAdjustment(0), _muted(false)
{
    _type = type;
}

AudioDevicesImpl::~AudioDevicesImpl()
{
    for (auto item : _availableDevices)
    {
        delete item.Value;
    }
}

void AudioDevicesImpl::Initialize()
{
    VivoxNativeSdk::Get().EventSdkEventRaised.AddLambda([this](const vx_evt_base_t &evt)
    {
        Handle(evt);
    });
}

const IAudioDevice& AudioDevicesImpl::SystemDevice() const
{
    return _systemDevice;
}

const IAudioDevice& AudioDevicesImpl::CommunicationDevice() const
{
    return _communicationDevice;
}

const IAudioDevice& AudioDevicesImpl::NullDevice() const
{
    return _noDevice;
}

const TMap<FString, IAudioDevice*>& AudioDevicesImpl::AvailableDevices() const
{
    return _availableDevices;
}

static bool MaybeChangeDeviceId(FString &currentId, const FString &newerId)
{
    if (newerId.IsEmpty() || !newerId.Compare(NULL_DEVICE_ID))
    {
        if (currentId.IsEmpty())
            return false;
        currentId.Empty();
        return true;
    }
    if (currentId.Compare(newerId))
    {
        currentId = newerId;
        return true;
    }
    return false;
}

VivoxCoreError AudioDevicesImpl::SetActiveDevice(const IAudioDevice& device, const FOnSetActiveDeviceCompletedDelegate& theDelegate)
{
    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    innerDelegate.BindLambda([this, theDelegate](const vx_resp_base_t &resp)
    {
        FString deviceId;
        if(resp.type == resp_aux_set_capture_device)
        {
            deviceId = reinterpret_cast<const vx_req_aux_set_capture_device_t *>(resp.request)->capture_device_specifier;
        } else
        {
            deviceId = reinterpret_cast<const vx_req_aux_set_render_device_t *>(resp.request)->render_device_specifier;
        }
        if(resp.return_code == 0)
        {
            ensure(deviceId == NULL_DEVICE_ID || _availableDevices.Contains(deviceId));
            _activeDeviceId = deviceId;

            // If switching a virtual device to active, we must set _effectiveDeviceId to the underlying physical device Id.
            FString physicalId = (deviceId == SYSTEM_DEVICE_ID) ? _systemDevice.Id() : (deviceId == COMMUNICATION_DEVICE_ID) ? _communicationDevice.Id() : (deviceId == NULL_DEVICE_ID) ? "" : deviceId;
            //ensure(physicalId.IsEmpty() || _availableDevices.Contains(physicalId)); /* Disabling check. Revisit in VCUNR-1222 */
            if (MaybeChangeDeviceId(_effectiveDeviceId, physicalId))
            {
                if (_effectiveDeviceId.IsEmpty())
                {
                    EventEffectiveDeviceChanged.Broadcast(AudioDeviceImpl());
                }
                else {
                    EventEffectiveDeviceChanged.Broadcast(**_availableDevices.Find(_effectiveDeviceId));
                }
            }
        }
        theDelegate.ExecuteIfBound(resp.status_code, deviceId);
    });
    // In order to allow the use of both virtual devices from the AvailableDevices() collection and devices
    // returned by special accessors e.g. SystemDevice(), we must standardize the specifier before passing to Core.
    FString virtualId = (static_cast<const AudioDeviceImpl&>(device).Type() == DeviceType::DefaultSystemDevice) ? SYSTEM_DEVICE_ID :
                 (static_cast<const AudioDeviceImpl&>(device).Type() == DeviceType::DefaultCommunicationDevice) ? COMMUNICATION_DEVICE_ID :
                 (static_cast<const AudioDeviceImpl&>(device).Type() == DeviceType::NullDevice) ? NULL_DEVICE_ID : device.Id();
    if(_type == AudioDeviceType::Input)
        return VivoxNativeSdk::Get().SetActiveAudioInputDevice(virtualId, innerDelegate);
    else
        return VivoxNativeSdk::Get().SetActiveAudioOutputDevice(virtualId, innerDelegate);
}

const IAudioDevice& AudioDevicesImpl::ActiveDevice()
{
    if (_activeDeviceId.IsEmpty())
        return _noDevice;
    ensure(_activeDeviceId == NULL_DEVICE_ID || _availableDevices.Contains(_activeDeviceId));
    if (!_availableDevices.Contains(_activeDeviceId))
        return _noDevice;
    return **_availableDevices.Find(_activeDeviceId);
}

const IAudioDevice& AudioDevicesImpl::EffectiveDevice()
{
    if (_effectiveDeviceId.IsEmpty())
        return _noDevice;
    ensure(_effectiveDeviceId == NULL_DEVICE_ID || _availableDevices.Contains(_effectiveDeviceId));
    if (!_availableDevices.Contains(_effectiveDeviceId))
        return _noDevice;
    return **_availableDevices.Find(_effectiveDeviceId);
}

int AudioDevicesImpl::VolumeAdjustment()
{
    return _volumeAdjustment;
}

VivoxCoreError AudioDevicesImpl::SetVolumeAdjustment(int value)
{
    if (_type == AudioDeviceType::Input) {
        VivoxCoreError error = VivoxNativeSdk::Get().SetAudioInputVolumeAdjustment(value);
        if (error == VxErrorSuccess) {
            _volumeAdjustment = value;
        }
        return error;
    } else {
        VivoxCoreError error = VivoxNativeSdk::Get().SetAudioOutputVolumeAdjustment(value);
        if (error == VxErrorSuccess) {
            _volumeAdjustment = value;
        }
        return error;
    }
}

bool AudioDevicesImpl::Muted() const
{
    return _muted;
}

void AudioDevicesImpl::SetMuted(bool value)
{
    int status;
    // there is little chance that this could fail.
    if (_type == AudioDeviceType::Input)
        status = VivoxNativeSdk::Get().SetInputDeviceMuted(value);
    else
        status = VivoxNativeSdk::Get().SetOutputDeviceMuted(value);
    ensure(status == 0);
    if (status == 0)
        _muted = value;
}

void AudioDevicesImpl::Refresh()
{
    if (_type == AudioDeviceType::Input) {
        VivoxNativeSdk::FOnRequestCompletedDelegate theDelegate;
        theDelegate.BindLambda([this](const vx_resp_base_t &resp)
        {
            Handle(reinterpret_cast<const vx_resp_aux_get_capture_devices_t &>(resp));
        });
        VivoxNativeSdk::Get().RefreshAudioInputDevices(theDelegate);
    } else {
        VivoxNativeSdk::FOnRequestCompletedDelegate theDelegate;
        theDelegate.BindLambda([this](const vx_resp_base_t &resp)
        {
            Handle(reinterpret_cast<const vx_resp_aux_get_render_devices_t &>(resp));
        });
        VivoxNativeSdk::Get().RefreshAudioOutputDevices(theDelegate);
    }
}

void AudioDevicesImpl::Handle(const vx_evt_base_t &message)
{
    if (message.type == evt_audio_device_hot_swap)
        Handle(reinterpret_cast<const vx_evt_audio_device_hot_swap_t &>(message));
    return;
}

void AudioDevicesImpl::Handle(const vx_evt_audio_device_hot_swap_t &e)
{
    Refresh();
}

static bool Contains(vx_device_t **items, int count, const FString &id)
{
    for(int i=0;i<count;++i)
    {
        if (items[i]->device == id)
            return true;
    }
    return false;
}

static IAudioDevice *IAudioDeviceFromVxDevice(vx_device_t *device)
{
    DeviceType type;
    switch (device->device_type)
    {
    case vx_device_type_t::vx_device_type_default_communication:
        type = DeviceType::DefaultCommunicationDevice;
        break;
    case vx_device_type_t::vx_device_type_default_system:
        type = DeviceType::DefaultSystemDevice;
        break;
    case vx_device_type_t::vx_device_type_specific_device:
        type = DeviceType::SpecificDevice;
        break;
    case vx_device_type_t::vx_device_type_null:
    default:
        //type = DeviceType::NullDevice;
        return new AudioDeviceImpl();
    }
    return new AudioDeviceImpl(UTF8_TO_TCHAR(device->display_name), device->device, type);
}

void AudioDevicesImpl::Handle(const vx_resp_aux_get_capture_devices_t &r)
{
    ensure(_type == AudioDeviceType::Input);
    for (int i = 0; i < r.count; ++i)
    {
        if (r.capture_devices[i]->device_type == vx_device_type_null)
            continue;
        if (_availableDevices.Contains(r.capture_devices[i]->device))
            continue;
        IAudioDevice *device = IAudioDeviceFromVxDevice(r.capture_devices[i]);

        _availableDevices.Add(device->Id(), device);
        EventAfterDeviceAvailableAdded.Broadcast(*device);
    }
    _systemDevice = AudioDeviceImpl(UTF8_TO_TCHAR(r.default_capture_device->display_name), r.default_capture_device->device, DeviceType::DefaultSystemDevice);
    _communicationDevice = AudioDeviceImpl(UTF8_TO_TCHAR(r.default_communication_capture_device->display_name), r.default_communication_capture_device->device, DeviceType::DefaultCommunicationDevice);
    if (_systemDevice.IsEmpty())
    {
        UE_LOG(VivoxCore, Warning, TEXT("No system default capture device found. This usually means no physical device is present (or on Xbox One, that no user is signed in). Use of a capture device is not required, but you should check your setup if you were expecting one."));
    }
    if (_activeDeviceId != r.current_capture_device->device)
    {
        _activeDeviceId = r.current_capture_device->device;
    }
    if (MaybeChangeDeviceId(_effectiveDeviceId, r.effective_capture_device->device))
    {
        if(_effectiveDeviceId.IsEmpty())
        {
            EventEffectiveDeviceChanged.Broadcast(AudioDeviceImpl());
        } else {
            EventEffectiveDeviceChanged.Broadcast(**_availableDevices.Find(_effectiveDeviceId));
        }
    }
    TDoubleLinkedList<IAudioDevice *> toBeRemoved;
    // process the deletes last
    for(auto item : _availableDevices)
    {
        if(!Contains(r.capture_devices, r.count, item.Value->Id()))
        {
            toBeRemoved.AddTail(item.Value);
        }
    }
    for(auto item : toBeRemoved)
    {
        EventBeforeAvailableDeviceRemoved.Broadcast(*item);
        _availableDevices.Remove(item->Id());
        delete item;
    }
}
void AudioDevicesImpl::Handle(const vx_resp_aux_get_render_devices_t &r)
{
    ensure(_type == AudioDeviceType::Output);
    for (int i = 0; i < r.count; ++i)
    {
        if (r.render_devices[i]->device_type == vx_device_type_null)
            continue;
        if (_availableDevices.Contains(r.render_devices[i]->device))
            continue;
        IAudioDevice *device = IAudioDeviceFromVxDevice(r.render_devices[i]);

        _availableDevices.Add(device->Id(), device);
        EventAfterDeviceAvailableAdded.Broadcast(*device);
    }
    _systemDevice = AudioDeviceImpl(UTF8_TO_TCHAR(r.default_render_device->display_name), r.default_render_device->device, DeviceType::DefaultSystemDevice);
    _communicationDevice = AudioDeviceImpl(UTF8_TO_TCHAR(r.default_communication_render_device->display_name), r.default_communication_render_device->device, DeviceType::DefaultCommunicationDevice);
    if (_systemDevice.IsEmpty())
    {
        UE_LOG(VivoxCore, Warning, TEXT("No system default render device found. This usually means no physical device is present (or on Xbox One, that no user is signed in). Use of a render device is not required, but you should check your setup if you were expecting one."));
    }
    if (_activeDeviceId != r.current_render_device->device)
    {
        _activeDeviceId = r.current_render_device->device;
    }
    if (_effectiveDeviceId != r.effective_render_device->device)
    {
        if (MaybeChangeDeviceId(_effectiveDeviceId, r.effective_render_device->device))
        {
            if (_effectiveDeviceId.IsEmpty())
            {
                EventEffectiveDeviceChanged.Broadcast(AudioDeviceImpl());
            } else {
                EventEffectiveDeviceChanged.Broadcast(**_availableDevices.Find(_effectiveDeviceId));
            }
        }
    }
    TDoubleLinkedList<IAudioDevice *> toBeRemoved;
    // process the deletes last
    for (auto item : _availableDevices)
    {
        if (!Contains(r.render_devices, r.count, item.Value->Id()))
        {
            toBeRemoved.AddTail(item.Value);
        }
    }
    for (auto item : toBeRemoved)
    {
        EventBeforeAvailableDeviceRemoved.Broadcast(*item);
        _availableDevices.Remove(item->Id());
        delete item;
    }
}
