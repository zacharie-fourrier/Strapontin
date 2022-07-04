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
#include "VivoxCoreCommon.h"
#include "TTSMessageImpl.h"
#include "VxcRequests.h"
#include "VxcEvents.h"

enum class SubscriptionMode : uint8;

/**
 *
 */
class VivoxNativeSdk
{
public:
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateRequestCompleted, const vx_resp_base_t &)
    typedef FDelegateRequestCompleted::FDelegate FOnRequestCompletedDelegate;

private:
    static VivoxNativeSdk *_instance;

    VivoxNativeSdk();
	~VivoxNativeSdk();

    static vx_message_base_t *Read();
    static vx_evt_base_t *ToEvent(vx_message_base_t *message);
    static vx_resp_base_t *ToResponse(vx_message_base_t *message);

    VivoxCoreError IssueRequest(vx_req_base_t *request, FOnRequestCompletedDelegate theDelegate);
public:

    static VivoxNativeSdk &Get();

    DECLARE_EVENT_OneParam(VivoxNativeSdk, SdkEventRaised, const vx_evt_base_t &)

    SdkEventRaised EventSdkEventRaised;

    void Tick();
    VivoxCoreError ConnectMedia(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError DisconnectMedia(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError ConnectText(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError DisconnectText(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError SendMessage(const FString &sessionHandle,
        const FString& language,
        const FString& message,
        const FString& applicationStanzaNamespace,
        const FString& applicationStanzaBody,
        FOnRequestCompletedDelegate theDelegate);

    VivoxCoreError ControlCommunications(const FString& accountHandle, vx_control_communications_operation operation, const FString& user_uris, vx_mute_scope scope, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError SetParticipantVolume(const FString &sessionHandle, const FString &participantUri, int volume, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError SetParticipantMuted(const FString &sessionHandle, const FString &participantUri, bool muted, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError SetParticipantMutedForAll(const FString& accountHandle, const FString& channelUri, const FString& participantUri, bool muted, const FString &accessToken, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError SetPresence(const FString &accountHandle, const FString &message, vx_buddy_presence_state state, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError Set3DPosition(const FString& sessionHandle,
        const FVector &speakerPosition,
        const FVector &listenerPosition,
        const FVector &listenerForwardVector,
        const FVector &listenerUpVector);
    VivoxCoreError AddSession(
        const FString &accountHandle,
        const FString &groupHandle,
        const FString &sessionHandle,
        const FString &accessToken,
        const ChannelId &channel,
        bool audio,
        bool text,
        FOnRequestCompletedDelegate theDelegate);

    VivoxCoreError StartAudioInjection(const FString &groupHandle, const FString &filePath, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError StopAudioInjection(const FString &groupHandle);

    VivoxCoreError SetTranscription(bool value, const FString &sessionHandle, const FString &accessToken, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());

    VivoxCoreError TTSGetVoices(const vx_tts_manager_id &managerId, int *num_voices, vx_tts_voice_t **voices);
    VivoxCoreError TTSSpeak(const vx_tts_manager_id &managerId, const ITTSVoice &voice, const FString &text, const TTSDestination &destination, ITTSMessage **outMessage);
    VivoxCoreError TTSSpeakToBuffer(const vx_tts_manager_id &managerId, const ITTSVoice &voice, const FString &text, ITTSAudioBuffer **outBuffer);
    VivoxCoreError TTSCancelMessage(const vx_tts_manager_id &managerId, const ITTSMessage &message);
    VivoxCoreError TTSCancelDestination(const vx_tts_manager_id &managerId, const TTSDestination &destination);
    VivoxCoreError TTSCancelAll(const vx_tts_manager_id &managerId);

    VivoxCoreError AddBlockRule(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError DeleteBlockRule(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError AddAcceptRule(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError DeleteAcceptRule(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError AddPresenceSubscription(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError DeletePresenceSubscription(const FString &accountHandle, const AccountId &account, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError SendSubscriptionReply(const FString &accountHandle, const AccountId &account, const vx_rule_type ruleType, FOnRequestCompletedDelegate theDelegate = FOnRequestCompletedDelegate());

    VivoxCoreError SendUserToUserMessage(const FString &accountHandle, const AccountId& dest, const FString& language, const FString& message, const FString& applicationStanzaNamespace, const FString& applicationStanzaBody, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError SetLoginProperties(const FString &accountHandle, int participantPropertyFrequency);

    VivoxCoreError SetNoSessionTransmitting(const FString &groupId);
    VivoxCoreError SetAllSessionsTransmitting(const FString &groupId);
    VivoxCoreError SetTransmittingSession(const FString &sessionId);
    VivoxCoreError RemoveSession(const FString &groupId, const FString &sessionId, FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError SetAudioInputVolumeAdjustment(int32_t volume);
    VivoxCoreError SetAudioOutputVolumeAdjustment(int32_t volume);
    VivoxCoreError SetActiveAudioInputDevice(const FString &deviceId, FOnRequestCompletedDelegate);
    VivoxCoreError SetActiveAudioOutputDevice(const FString &deviceId, FOnRequestCompletedDelegate);
    VivoxCoreError SetInputDeviceMuted(bool value, FOnRequestCompletedDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError SetOutputDeviceMuted(bool value, FOnRequestCompletedDelegate = FOnRequestCompletedDelegate());
    VivoxCoreError RefreshAudioInputDevices(FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError RefreshAudioOutputDevices(FOnRequestCompletedDelegate theDelegate);
    VivoxCoreError Login(
        const FString& connectorHandle,
        const AccountId &account,
        const FString& accessToken,
        int participantPropertyFrequency,
        bool enablePresence,
        SubscriptionMode subscriptionMode,
        const TSet<AccountId>& presenceSubscriptions,
        const TSet<AccountId>& blockedPresenceSubscriptions,
        const TSet<AccountId>& allowedPresenceSubscriptions,
        FOnRequestCompletedDelegate theDelegate);
    void Logout(const FString &accountHandle);

    VivoxCoreError ConnectorCreate(const FString &server, FOnRequestCompletedDelegate theDelegate);

    // Test Helper Functions
    static AccountId GetRandomAccountId(const FString &issuer, const FString &domain, const FString &prefix);
    static ChannelId GetRandomChannelId(const FString &issuer, const FString &domain, const FString &prefix, ChannelType type);
    static FString GetLoginToken(const AccountId &account, const FString &key, const FTimespan &expiration = FTimespan::FromSeconds(30 * 60));
    static FString GetJoinToken(const AccountId &account, const ChannelId &channel, const FString &key, const FTimespan &expiration = FTimespan::FromSeconds(30 * 60));
    static FString GetMuteForAllToken(const AccountId &account, const ChannelId &channel, const AccountId &subject, const FString &key, const FTimespan &expiration = FTimespan::FromSeconds(30 * 60));
    static FString GetTranscriptionToken(const AccountId &account, const ChannelId &channel, const FString &key, const FTimespan &expiration = FTimespan::FromSeconds(30 * 60));
};
