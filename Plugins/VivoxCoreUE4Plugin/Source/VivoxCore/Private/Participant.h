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
#include "IParticipant.h"
#include "LoginSession.h"
#include "ChannelSession.h"

struct vx_evt_participant_updated;
struct vx_evt_participant_added;
struct vx_evt_participant_removed;
class ChannelSession;

/**
 *
 */
class Participant : public IParticipant
{
    bool _isSelf;
    bool _inAudio;
    bool _inText;
    bool _speechDetected;
    double _audioEnergy;
    int _localVolumeAdjustment;
    bool _localMute;
    bool _isTyping;
    bool _isMutedForAll;
    bool _unavailableRenderDevice;
    bool _unavailableCaptureDevice;
    FString _participantId;
    ChannelSession &_parentChannelSession;
    AccountId _account;
public:
    Participant(ChannelSession &parentChannel, const vx_evt_participant_added &evt);
    ~Participant();
    // IParticipant overrides
    bool IsSelf() const override { return _isSelf; }
    bool InAudio() const override { return _inAudio; }
    bool InText() const override { return _inText; }
    bool UnavailableRenderDevice() const override { return _unavailableRenderDevice; }
    bool UnavailableCaptureDevice() const override { return _unavailableCaptureDevice; }
    bool SpeechDetected() const override { return _speechDetected; }
    double AudioEnergy() const override {
        if (_parentChannelSession.Parent().GetParticipantSpeakingUpdateRate() == ParticipantSpeakingUpdateRate::StateChange)
            UE_LOG(VivoxCore, Warning, TEXT("You must call ILoginSession::SetParticipantSpeakingUpdateRate() first to get real-time audio energy!"));
        return _audioEnergy;
    }
    int LocalVolumeAdjustment() const override { return _localVolumeAdjustment; }
	VivoxCoreError SetLocalVolumeAdjustment(int value) override;//deprecated
    VivoxCoreError BeginSetLocalVolumeAdjustment(int value, FOnBeginSetLocalVolumeAdjustmentCompletedDelegate theDelegate) override;
    bool LocalMute() const override { return _localMute; }
	void SetLocalMute(bool value) override;//deprecated
    VivoxCoreError BeginSetLocalMute(bool value, FOnBeginSetLocalMuteCompletedDelegate theDelegate) override;
    bool IsTyping() const override { return _isTyping; }
    bool IsMutedForAll() const override { return _isMutedForAll; }
    VivoxCoreError BeginSetIsMutedForAll(bool setMuted, const FString& accessToken, FOnBeginSetIsMutedForAllCompletedDelegate theDelegate) const override;
    FString GetMuteForAllToken(const FString & tokenSigningKey, FTimespan tokenExpirationDuration) const override;
    const FString& ParticipantId() const override { return _participantId; }
    IChannelSession& ParentChannelSession() const override { return _parentChannelSession; }
    const AccountId& Account() const override { return _account; }

    // Module Private
    bool HandleEvent(const vx_evt_participant_updated &evt);
    bool HandleEvent(const vx_evt_participant_removed &evt);
};
