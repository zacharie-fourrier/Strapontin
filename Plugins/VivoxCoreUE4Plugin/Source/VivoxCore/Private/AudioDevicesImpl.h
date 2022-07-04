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

#pragma once
#include "IAudioDevices.h"
#include "AudioDeviceImpl.h"
#include "VivoxCoreCommonImpl.h"
#include "VxcEvents.h"
#include "VxcResponses.h"

enum class AudioDeviceType : uint8
{
    Input,
    Output
};
/**
 *
 */
class AudioDevicesImpl : public IAudioDevices
{
    AudioDeviceImpl _noDevice;
    AudioDeviceImpl _systemDevice;
    AudioDeviceImpl _communicationDevice;
    TMap<FString, IAudioDevice*> _availableDevices;
    FString _activeDeviceId;
    FString _effectiveDeviceId;
    int _volumeAdjustment;
    bool _muted;
    AudioDeviceType _type;

    void Handle(const vx_evt_audio_device_hot_swap_t &r);
    void Handle(const vx_resp_aux_get_capture_devices_t &r);
    void Handle(const vx_resp_aux_get_render_devices_t &r);
    void Handle(const vx_evt_base_t &message);

public:
	AudioDevicesImpl(AudioDeviceType type);
	~AudioDevicesImpl();

    void Initialize();

    const IAudioDevice& SystemDevice() const override;
    const IAudioDevice& CommunicationDevice() const override;
    const IAudioDevice& NullDevice() const override;
    const TMap<FString, IAudioDevice*>& AvailableDevices() const override;
    VivoxCoreError SetActiveDevice(const IAudioDevice &deviceId, const FOnSetActiveDeviceCompletedDelegate& Delegate) override;
    const IAudioDevice& ActiveDevice() override;
    const IAudioDevice& EffectiveDevice() override;
    int VolumeAdjustment() override;
    VivoxCoreError SetVolumeAdjustment(int value) override;
    bool Muted() const override;
    void SetMuted(bool value) override;

    void Refresh();
};
