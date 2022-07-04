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

#include "Participant.h"
#include "VivoxCore.h"
#include "VxcEvents.h"
#include "VxcErrors.h"
#include "VivoxNativeSdk.h"
#include "ChannelSession.h"

template<class DST, class SRC>
static bool assign(DST &dst, SRC src)
{
    if(dst != src) {
        dst = src;
        return true;
    }
    return false;
}

Participant::Participant(ChannelSession &parentChannel, const vx_evt_participant_added &evt) :  _parentChannelSession(parentChannel)
{
    _isSelf = evt.is_current_user == 1;
    _account = AccountId::CreateFromUri(evt.participant_uri, FString(UTF8_TO_TCHAR(evt.displayname)));
    _audioEnergy = 0.0;
    _inAudio = false;
    _inText = false;
    _isMutedForAll = false;
    _isTyping = false;
    _localMute = false;
    _unavailableRenderDevice = false;
    _unavailableCaptureDevice = false;
    _localVolumeAdjustment = 0;
    _speechDetected = false;
    _participantId = evt.encoded_uri_with_tag;
}

Participant::~Participant()
{
}

//DEPRECATED: Use IParticipantProperties::BeginSetLocalVolumeAdjustment() instead; will be removed in a future release.
VivoxCoreError Participant::SetLocalVolumeAdjustment(int value)
{
	return BeginSetLocalVolumeAdjustment(value, FOnBeginSetLocalVolumeAdjustmentCompletedDelegate());
}

VivoxCoreError Participant::BeginSetLocalVolumeAdjustment(int value, FOnBeginSetLocalVolumeAdjustmentCompletedDelegate theDelegate)
{
    if (value < -50 || value > 50)
        return VxErrorInvalidArgument;
    if (_localVolumeAdjustment == value)
        return VxErrorSuccess;

    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    innerDelegate.BindLambda([this, value, theDelegate](const vx_resp_base_t& resp)
        {
            if (resp.return_code == 0)
            {
                _localVolumeAdjustment = value;
            }
            theDelegate.ExecuteIfBound(resp.status_code);
        });
    VivoxCoreError error = VivoxNativeSdk::Get().SetParticipantVolume(_parentChannelSession.SessionHandle(), _account.ToString(), value, innerDelegate);
    return error;
}

//DEPRECATED: Use IParticipantProperties::BeginSetLocalMute() instead; will be removed in a future release.
void Participant::SetLocalMute(bool value)
{
	BeginSetLocalMute(value, FOnBeginSetLocalMuteCompletedDelegate());
}

VivoxCoreError Participant::BeginSetLocalMute(bool value, FOnBeginSetLocalMuteCompletedDelegate theDelegate)
{
    if (_localMute == value)
        return VxErrorSuccess;

    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    innerDelegate.BindLambda([this, value, theDelegate](const vx_resp_base_t& resp)
        {
            if (resp.return_code == 0)
            {
                _localMute = value;
            }
            theDelegate.ExecuteIfBound(resp.status_code);
        });
    VivoxCoreError error = VivoxNativeSdk::Get().SetParticipantMuted(_parentChannelSession.SessionHandle(), _account.ToString(), value, innerDelegate);
    return error;
}

VivoxCoreError Participant::BeginSetIsMutedForAll(bool setMuted, const FString& accessToken, FOnBeginSetIsMutedForAllCompletedDelegate theDelegate) const
{
    if (accessToken.IsEmpty()) return VxErrorInvalidArgument;

    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    innerDelegate.BindLambda([this, theDelegate](const vx_resp_base_t &resp)
    {
        theDelegate.ExecuteIfBound(resp.status_code);
    });
    VivoxCoreError error = VivoxNativeSdk::Get().SetParticipantMutedForAll(_parentChannelSession.Parent().LoginSessionId().ToString(), _parentChannelSession.Channel().ToString(), _account.ToString(), setMuted, accessToken, innerDelegate);
    return error;
}

FString Participant::GetMuteForAllToken(const FString& tokenSigningKey, FTimespan tokenExpirationDuration) const
{
    return VivoxNativeSdk::GetMuteForAllToken(_parentChannelSession.Parent().LoginSessionId(), _parentChannelSession.Channel(), _account, tokenSigningKey, tokenExpirationDuration);
}

bool Participant::HandleEvent(const vx_evt_participant_updated &evt)
{
    bool changed = false;
    changed |= assign(this->_audioEnergy, evt.energy);
    changed |= assign(this->_inAudio, (evt.active_media & VX_MEDIA_FLAGS_AUDIO) == VX_MEDIA_FLAGS_AUDIO);
    changed |= assign(this->_inText, (evt.active_media & VX_MEDIA_FLAGS_TEXT) == VX_MEDIA_FLAGS_TEXT);
    changed |= assign(this->_speechDetected, evt.is_speaking != 0);
    changed |= assign(this->_isMutedForAll, evt.is_moderator_muted != 0);
    changed |= assign(this->_unavailableCaptureDevice, evt.has_unavailable_capture_device != 0);
    changed |= assign(this->_unavailableRenderDevice, evt.has_unavailable_render_device != 0);
    return changed;
}

bool Participant::HandleEvent(const vx_evt_participant_removed& evt)
{
    return false;
}
