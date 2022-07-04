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

#include "Channel3DProperties.h"
#include "Internationalization/Regex.h"
#include "VivoxCore.h"

Channel3DProperties::Channel3DProperties()
{
    _audibleDistance = 2700;
    _conversationalDistance = 90;
    _audioFadeIntensityByDistance = 1.0;
    _audioFadeModel = EAudioFadeModel::InverseByDistance;
}

Channel3DProperties::Channel3DProperties(int32 audibleDistance, int32 conversationalDistance, double audioFadeIntensityByDistance, EAudioFadeModel audioFadeModel)
{
    ensure(audibleDistance > 0);
    ensure(conversationalDistance > 0);
    ensure(audioFadeIntensityByDistance > 0);
    _audibleDistance = audibleDistance;
    _conversationalDistance = conversationalDistance;
    _audioFadeIntensityByDistance = (audioFadeIntensityByDistance <= 0) ? audioFadeIntensityByDistance : FGenericPlatformMath::Max(0.001, FGenericPlatformMath::RoundToDouble(audioFadeIntensityByDistance * 1000) / 1000); // round to three decimal places
    _audioFadeModel = audioFadeModel;
}

Channel3DProperties Channel3DProperties::CreateFromString(FString propsString)
{
    const FRegexPattern regex("!p-([^-]+)-([^-]+)-([^-]+)-(1|2|3)");
    FRegexMatcher matcher(regex, propsString);
    bool found = matcher.FindNext();
    if (!found)
    {
        return Channel3DProperties();
    }
    EAudioFadeModel fadeModel;
    switch (int32(FCString::Atoi(*matcher.GetCaptureGroup(4))))
    {
    case 1:
        fadeModel = EAudioFadeModel::InverseByDistance;
        break;
    case 2:
        fadeModel = EAudioFadeModel::LinearByDistance;
        break;
    case 3:
        fadeModel = EAudioFadeModel::ExponentialByDistance;
        break;
    default:
        //InverseByDistance is the default value for fadeModel in Vivox Positional Channels
        fadeModel = EAudioFadeModel::InverseByDistance;
        break;
    }
    return Channel3DProperties(FCString::Atoi(*matcher.GetCaptureGroup(1)), FCString::Atoi(*matcher.GetCaptureGroup(2)), FCString::Atof(*matcher.GetCaptureGroup(3)), fadeModel);
}

bool Channel3DProperties::IsValid() const
{
    // NB: As of UE4.24, an enum with no 0 entry is considered a compilation error, so we shifted EaudioFadeModel to start at 0 and add back 1 when casting to compensate.
    return 0 < _audibleDistance
        && 0 <= _conversationalDistance && _conversationalDistance <= _audibleDistance
        && 0 <= _audioFadeIntensityByDistance
        && 1 <= (int)_audioFadeModel+1 && (int)_audioFadeModel+1 <= 3;
}

FString Channel3DProperties::ToString() const
{
    // NB: As of UE4.24, an enum with no 0 entry is considered a compilation error, so we shifted EaudioFadeModel to start at 0 and add back 1 when casting to compensate.
    return FString::Printf(TEXT("p-%d-%d-%.3f-%d"), static_cast<int>(_audibleDistance), static_cast<int>(_conversationalDistance), _audioFadeIntensityByDistance, static_cast<int>(_audioFadeModel) + 1).Replace(TEXT(","), TEXT("."));
}
