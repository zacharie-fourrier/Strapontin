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
#include "Engine/Blueprint.h"
#include "IAudioDevices.h"

/**
 * \brief The type of device
 */
UENUM(BlueprintType)
enum class DeviceType : uint8
{
    /**
     * This is the null device, which means that either input or output from/to that device will not occur.
     */
    NullDevice = 0,
    /**
     * This type is a specific device.
     */
    SpecificDevice,
    /**
     * This type means to use what ever the system has configured as a default, at the time of the call.
     * Don't switch devices mid-call if the default system device changes.
     */
    DefaultSystemDevice,
    /**
     * This type means to use what ever the system has configured as a default communication device, at the time of the call.
     * Don't switch devices mid-call if the default communication device changes.
     */
    DefaultCommunicationDevice
};

/**
 *
 */
class AudioDeviceImpl : public IAudioDevice
{
    FString _name;
    FString _id;
    DeviceType _type;

public:
	AudioDeviceImpl();
    AudioDeviceImpl(const FString &name, const FString &id, DeviceType type);
    ~AudioDeviceImpl();
    const FString& Name() const override { return _name; }
    const FString& Id() const override { return _id; }
    DeviceType Type() const { return _type; } // no override: not in interface
    bool IsEmpty() const override { return _name.IsEmpty() && _id.IsEmpty(); } // don't consider _type
};
