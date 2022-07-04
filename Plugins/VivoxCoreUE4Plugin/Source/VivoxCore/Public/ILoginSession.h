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
#include "VivoxCoreCommon.h"
#include "ITextToSpeech.h"

/**
 * \brief The state of the login session.
 */
UENUM(BlueprintType)
enum class LoginState : uint8
{
    /**
     * \brief The login session is signed out.
     */
    LoggedOut,
    /**
     * \brief The login session is in the process of signing in.
     */
    LoggingIn,
    /**
     * \brief The login session is signed in.
     */
    LoggedIn,
    /**
     * \brief The login Session is in the process of signing out.
     */
    LoggingOut
};

/**
 * \brief Determine how to handle incoming subscriptions (friend/follower requests).
 */
UENUM(BlueprintType)
enum class SubscriptionMode : uint8
{
    /**
     * \brief Automatically accept all incoming subscription requests.
     */
    Accept,
    /**
     * \brief Automatically block all incoming subscription requests.
     */
    Block,
    /**
     * \brief Defer incoming subscription request handling to the application.
     * This results in EventSubscriptionRequestReceived firing.
     */
    Defer
};

UENUM(BlueprintType)
enum class SubscriptionReply : uint8
{
    /**
     * \brief Allow the incoming subscription.
     */
    Allow,
    /**
     * \brief Block the incoming subscription.
     */
    Block
};

/**
 * \brief Define the policy of where microphone audio and injected audio get broadcast to.
 */
UENUM(BlueprintType)
enum class TransmissionMode : uint8
{
    /**
     * \brief Adopt a policy of transmission into no channels.
     */
    None,
    /**
     * \brief Adopt a policy of transmission into one channel at a time.
     */
    Single,
    /**
     * \brief Adopt a policy of transmission into all channels simultaneously.
     */
    All
};

/**
 * \brief Define how often the SDK raises speech-related IChannelSession::EventAfterParticipantUpdated events while in channel.
 * \remarks Use a per second rate (at the fidelity of your choice) when implementing a real-time audio energy meter.
 * This only controls participant update events due to changes in speech detection or changes in audio energy.
 * Other participant property state change events (for example, active media or muted state) occur regardless of setting.
 */
UENUM(BlueprintType)
enum class ParticipantSpeakingUpdateRate : uint8
{
    /**
     * \brief On participant state change in speech detection only (excludes audio energy).
     */
    StateChange,
    /**
     * \brief Do not raise events for changes in participant speech detection or audio energy (use with caution).
     */
    Never,
    /**
     * \brief Update participant properties up to 1 time per second (includes audio energy).
     */
    Update1Hz,
    /**
     * \brief Update participant properties up to 5 times per second (includes audio energy).
     */
    Update5Hz,
    /**
     * \brief Update participant properties up to 10 times per second (includes audio energy).
     */
    Update10Hz
};

/**
 * \brief An instance of an account that is signing in to the Vivox network.
 */
class VIVOXCORE_API ILoginSession
{
public:
    /* @cond */
    DECLARE_EVENT_OneParam(ILoginSession, SubscriptionRequestReceived, const AccountId &)
    DECLARE_EVENT_OneParam(ILoginSession, DirectedTextMessageReceived, const IDirectedTextMessage &)
    DECLARE_EVENT_TwoParams(ILoginSession, SendDirectedTextMessageFailed, VivoxCoreError, const FString &)
    DECLARE_EVENT_OneParam(ILoginSession, StateChanged, LoginState)
    DECLARE_EVENT(ILoginSession, AudioInjectionCompleted)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSetCrossMutedCommunicationsCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginClearCrossMutedCommunicationsCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginAddBlockedSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginRemoveBlockedSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginAddAllowedSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginRemoveAllowedSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginAddPresenceSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginRemovePresenceSubscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSendSubscriptionReplyCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateBeginSendDirectedMessageCompleted, VivoxCoreError, const FString &)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginStartAudioInjectionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginLoginCompleted, VivoxCoreError)
    /* @endcond */
public:
    /**
     * \brief Destructor
     */
    virtual ~ILoginSession() = default;
    /**
     * \brief The list of channel sessions associated with this login session.
     */
    virtual const TMap<ChannelId, TSharedPtr<IChannelSession> > &ChannelSessions() const = 0;

    /**
     * \brief The list of presence subscriptions associated with this login session.
     * \remarks This typically corresponds to a list of friends or followers.
     */
    virtual const TMap <AccountId, TSharedPtr<IPresenceSubscription> > &PresenceSubscriptions() const = 0;

    /**
     * \brief The list of accounts blocked from seeing this account's online status.
     */
    virtual const TSet<AccountId> &BlockedSubscriptions() const = 0;

    /**
     * \brief The list of accounts allowed to see this account's online status.
     */
    virtual const TSet<AccountId> &AllowedSubscriptions() const = 0;

    /**
     * \brief The list of accounts which have bi-directionally muted communications with this login session.
     */
    virtual const TSet<AccountId> &CrossMutedCommunications() const = 0;

    /**
    * \brief An event that indicates a new subscription request has been received.
    * \remarks An example of this is when another player would like to be your buddy.
    */
    SubscriptionRequestReceived EventSubscriptionRequestReceived;
    /**
     * \brief An event that indicates another player has sent you a text message.
     */
    DirectedTextMessageReceived EventDirectedTextMessageReceived;

    /**
     * \brief The current state of this login session.
     */
    virtual LoginState State() const = 0;
    /**
    * \brief The event that fires when State() changes, except on player-initiated sign outs.
    * \remarks Loss of network connectivity causes this event to fire.
    */
    StateChanged EventStateChanged;

    /**
     * \brief The online status that is sent to accounts that subscribe to the presence of this account.
     */
    virtual const Presence &CurrentPresence() = 0;
    /**
    * \brief Set this player's online status.
    */
    virtual VivoxCoreError SetCurrentPresence(const Presence &value) = 0;

    /**
     * \brief The unique identifier for this login session.
     */
    virtual const AccountId &LoginSessionId() const = 0;

    /**
    * \brief The delegate that is called when BeginLogin() completes.
    */
    typedef FDelegateBeginLoginCompleted::FDelegate FOnBeginLoginCompletedDelegate;

    /**
    * \brief Begin the sign in process for this session with presence.
    *
    * \param server The URI of the Vivox instance assigned to you.
    * \param accessToken An access token provided by your game server that enables the sign in process.
    * \param subscriptionMode Determine how to handle incoming subscriptions (friend/follower requests).
    * \param presenceSubscriptions A list of accounts for which this user wants to monitor online status.
    * \param blockedPresenceSubscriptions A list of accounts that are not allowed to see this user's online status.
    * \param allowedPresenceSubscriptions A list of accounts that are allowed to see this user's online status.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success.
    * \remarks Developers of games that do not have secure communications requirements
    * can use GetLoginToken to generate the required access token.
    */
    virtual VivoxCoreError BeginLogin(
        const FString &server,
        const FString & accessToken,
        SubscriptionMode subscriptionMode,
        const TSet<AccountId> & presenceSubscriptions,
        const TSet<AccountId> & blockedPresenceSubscriptions,
        const TSet<AccountId> & allowedPresenceSubscriptions,
        FOnBeginLoginCompletedDelegate theDelegate = FOnBeginLoginCompletedDelegate()) = 0;

    /**
     * \brief Begin the sign in process for this session with no presence.
      *
     * \param server The URI of the Vivox instance assigned to you.
     * \param accessToken An access token provided by your game server that enables the sign in process.
     * \param theDelegate A delegate to call when this operation completes.
     * \return 0 on success.
     * \remarks Developers of games that do not have secure communications requirements
     * can use GetLoginToken to generate the required access token.
     */
    virtual VivoxCoreError BeginLogin(
        const FString &server,
        const FString & accessToken,
        FOnBeginLoginCompletedDelegate theDelegate = FOnBeginLoginCompletedDelegate()) = 0;

    /**
     * \brief Gets the channel session for this channelId. If necessary, this creates a channel session.
     *
     * \param channelId The channel ID.
     * \return The channel session.
     */
    virtual IChannelSession &GetChannelSession(const ChannelId &channelId) = 0;

    /**
     * \brief Delete the channel session for this channelId, and disconnect the session if necessary.
     *
     * \param channelId The channel ID.
     * \remarks For timing restrictions related to the process of joining or rejoining channels during a disconnect,
     *  see IChannelSession::Disconnect(). Note that there are no timing restrictions when using this method to remove
     *  a session which already has a ChannelState() of Disconnected.
     * \see IChannelSession::Disconnect()
     */
    virtual void DeleteChannelSession(const ChannelId &channelId) = 0;

    /**
     * \brief The delegate to call when BeginSetCrossMutedCommunications completes.
     */
    typedef FDelegateBeginSetCrossMutedCommunicationsCompleted::FDelegate FOnBeginSetCrossMutedCommunicationsCompletedDelegate;

    /**
     * \brief Crossmute an AccountId, which bi-directionally mutes audio and text between that account and this login session.
     *
     * \param accountId The AccountId to bi-directionally mute or unmute.
     * \param muted The status to set: true to mute, false to unmute.
     * \return 0 on success.
     */
    virtual VivoxCoreError BeginSetCrossMutedCommunications(const AccountId &accountId, const bool &muted, FOnBeginSetCrossMutedCommunicationsCompletedDelegate theDelegate) = 0;

    /**
     * \brief Crossmute a set of AccountIds, which bi-directionally mutes audio and text between those accounts and this login session.
     *
     * \param accountIdSet The TSet of AccountIds to bi-directionally mute or unmute
     * \param muted The status to set: true to mute, false to unmute.
     * \return 0 on success.
     */
    virtual VivoxCoreError BeginSetCrossMutedCommunications(const TSet<AccountId> &accountIdSet, const bool &muted, FOnBeginSetCrossMutedCommunicationsCompletedDelegate theDelegate) = 0;

    /**
     * \brief The delegate to call when BeginClearCrossMutedCommunications completes.
     */
    typedef FDelegateBeginClearCrossMutedCommunicationsCompleted::FDelegate FOnBeginClearCrossMutedCommunicationsCompletedDelegate;

    /**
     * \brief Clear the bi-directionally muted communications list. This unmutes all AccountIds and allows audio and text through any means that are not otherwise prevented.
     *
     * \return 0 on success.
     */
    virtual VivoxCoreError BeginClearCrossMutedCommunications(FOnBeginClearCrossMutedCommunicationsCompletedDelegate theDelegate) = 0;

    /**
     * \brief The delegate to call when BeginAddBlockedSubscription completes.
     */
    typedef FDelegateBeginAddBlockedSubscriptionCompleted::FDelegate FOnBeginAddBlockedSubscriptionCompletedDelegate;

    /**
     * \brief Block incoming subscription requests from the specified account.
     *
     * \param accountId The account ID to block.
     * \param theDelegate A delegate to call when this operation completes.
     * \return 0 on success.
     */
    virtual VivoxCoreError BeginAddBlockedSubscription(const AccountId &accountId, FOnBeginAddBlockedSubscriptionCompletedDelegate theDelegate = FOnBeginAddBlockedSubscriptionCompletedDelegate()) = 0;

    /**
     * \brief The delegate to call when BeginRemoveBlockedSubscription completes.
     */
    typedef FDelegateBeginRemoveBlockedSubscriptionCompleted::FDelegate FOnBeginRemoveBlockedSubscriptionCompletedDelegate;

    /**
     * \brief Unblock incoming subscription requests from the specified account. Subscription requests from the specified account cause an event to be raised to the application.
     *
     * \param accountId The account ID to unblock.
     * \param theDelegate A delegate to call when this operation completes.
     * @return 0 on success.
     */
    virtual VivoxCoreError  BeginRemoveBlockedSubscription(const AccountId & accountId, FOnBeginRemoveBlockedSubscriptionCompletedDelegate theDelegate = FOnBeginRemoveBlockedSubscriptionCompletedDelegate()) = 0;

    /**
     * \brief The delegate to call when BeginAddAllowedSubscription completes.
     */
    typedef FDelegateBeginAddAllowedSubscriptionCompleted::FDelegate FOnBeginAddAllowedSubscriptionCompletedDelegate;

    /**
     * \brief Allow incoming subscription requests from the specified account.
     *
     * \param accountId The account ID to allow.
     * \param theDelegate A delegate to call when this operation completes.
     * \return 0 on success.
     */
    virtual VivoxCoreError  BeginAddAllowedSubscription(const AccountId & accountId, FOnBeginAddAllowedSubscriptionCompletedDelegate theDelegate = FOnBeginAddAllowedSubscriptionCompletedDelegate()) = 0;

    /**
     * \brief The delegate to call when BeginRemoveAllowedSubscription completes.
     */
    typedef FDelegateBeginRemoveAllowedSubscriptionCompleted::FDelegate FOnBeginRemoveAllowedSubscriptionCompletedDelegate;

    /**
     * \brief Disallow automatic acceptance of incoming subscription requests from the specified account. Subscription requests from the specified account cause an event to be raised to the application.
     *
     * \param accountId The account ID to disallow.
     * \param theDelegate A delegate to call when this operation completes.
     * \return 0 on success.
     */
    virtual VivoxCoreError  BeginRemoveAllowedSubscription(const AccountId & accountId, FOnBeginRemoveAllowedSubscriptionCompletedDelegate theDelegate = FOnBeginRemoveAllowedSubscriptionCompletedDelegate()) = 0;

    /**
     * \brief The delegate to call when BeginAddPresenceSubscription completes.
     */
    typedef FDelegateBeginAddPresenceSubscriptionCompleted::FDelegate FOnBeginAddPresenceSubscriptionCompletedDelegate;

    /**
    * \brief Subscribe to the specified account.
    *
    * \param accountId The account ID to subscribe to.
    * \param theDelegate A delegate to call when this operation completes.
    * \remarks This method automatically allows accountId to see the subscriber's online status.
    * \return 0 on success.
    */
    virtual VivoxCoreError  BeginAddPresenceSubscription(const AccountId & accountId, FOnBeginAddPresenceSubscriptionCompletedDelegate theDelegate = FOnBeginAddPresenceSubscriptionCompletedDelegate()) = 0;
    /**
    * \brief The delegate to call when BeginRemovePresenceSubscription completes.
    */
    typedef FDelegateBeginRemovePresenceSubscriptionCompleted::FDelegate FOnBeginRemovePresenceSubscriptionCompletedDelegate;
    /**
    * \brief Unsubscribe from the specified account.
    *
    * \param accountId The account ID to subscribe to.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success.
    */
    virtual VivoxCoreError BeginRemovePresenceSubscription(const AccountId & accountId, FOnBeginRemovePresenceSubscriptionCompletedDelegate theDelegate = FOnBeginRemovePresenceSubscriptionCompletedDelegate()) = 0;

    /**
    * \brief The delegate to call when BeginSendSubscriptionReply completes.
    */
    typedef FDelegateBeginSendSubscriptionReplyCompleted::FDelegate FOnBeginSendSubscriptionReplyCompletedDelegate;

    /**
    * \brief Reply to a subscription request received from EventSubscriptionRequestReceived.
    *
    * \param accountId The accountId to reply to.
    * \param replyType The SubscriptionReply type to use: Allow or Block.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success.
    */
    virtual VivoxCoreError BeginSendSubscriptionReply(const AccountId & accountId, const SubscriptionReply & replyType, FOnBeginSendSubscriptionReplyCompletedDelegate theDelgate = FOnBeginSendSubscriptionReplyCompletedDelegate()) = 0;
    /**
     * \brief The delegate to call when BeginSendDirectedMessage completes.
     *
     * \remarks The VivoxCoreError parameter is a status code for the request, and the FString parameter
     *  is a request ID unique to the directed message that is sent. If the message cannot be delivered 
     *  to the intended recipient, then EventSendDirectedTextMessageFailed is raised with an error code
     *  and a matching request ID. You can compare this request ID with the ID returned by this delegate
     *  to determine which message failed to be delivered.
     */
    typedef FDelegateBeginSendDirectedMessageCompleted::FDelegate FOnBeginSendDirectedMessageCompletedDelegate;
    /**
    * \brief Send a message to a specific account.
    *
    * \param accountId The intended recipient of the message.
    * \param language The language of the message, for example: "en". To use the default language ("en" for most systems), set this to null. This must conform to BCP 47 (https://tools.ietf.org/html/bcp47).
    * \param message The body of the message.
    * \param applicationStanzaNamespace An optional namespace element for additional application data.
    * \param applicationStanzaBody The additional application data body.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success, or VxErrorInvalidOperation if BeginLogin was called with no presence enabled (short form).
    */
    virtual VivoxCoreError BeginSendDirectedMessage(const AccountId & accountId, const FString &language, const FString & message, const FString & applicationStanzaNamespace, const FString & applicationStanzaBody, FOnBeginSendDirectedMessageCompletedDelegate theDelegate = FOnBeginSendDirectedMessageCompletedDelegate()) = 0;

    /**
    * \brief Send a message to a specific account.
    *
    * \param accountId The intended recipient of the message.
    * \param message The body of the message.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success, or VxErrorInvalidOperation if BeginLogin was called with no presence enabled (short form).
    */
    virtual VivoxCoreError BeginSendDirectedMessage(const AccountId & accountId, const FString & message, FOnBeginSendDirectedMessageCompletedDelegate theDelegate = FOnBeginSendDirectedMessageCompletedDelegate()) = 0;

    /**
     * \brief An event that indicates a directed message delivery failed.
     *
     * \remarks The VivoxCoreError parameter specifies the reason for failure, and the FString parameter
     *  is a request ID that matches the ID returned in FOnBeginSendDirectedMessageCompletedDelegate when
     *  the message was sent. You can compare this request ID with the ID returned in the delegate to determine
     *  which directed message failed to be delivered.
     */
    SendDirectedTextMessageFailed EventSendDirectedTextMessageFailed;

    /**
    * \brief The delegate to call when BeginStartAudioInjection completes.
    */
    typedef FDelegateBeginStartAudioInjectionCompleted::FDelegate FOnBeginStartAudioInjectionCompletedDelegate;
    /**
    * \brief Start broadcasting audio from a file to all connected ChannelSessions.
    *
    * \param filePath The full pathname for the .wav file to play (this must be single channel, 16-bit PCM).
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 on success, or VxErrorInvalidState if not in an audio-connected ChannelSession.
    *
    * \remarks Injected audio is treated like a second microphone that you are speaking into.
    *  Muting or disconnecting your input device does not stop others from hearing the file audio.
    *  Muting yourself in a channel, stopping transmission to a channel,
    *  or disconnecting the channel AudioState does stop others from hearing the file audio.
    */
    virtual VivoxCoreError BeginStartAudioInjection(const FString &filePath, FOnBeginStartAudioInjectionCompletedDelegate theDelegate = FOnBeginStartAudioInjectionCompletedDelegate()) = 0;

    /**
    * \brief Stop broadcasting audio from a file.
    */
    virtual VivoxCoreError StopAudioInjection() = 0;

    /**
    * \brief True if currently broadcasting audio from a file.
    */
    virtual bool IsAudioInjecting() = 0;

    /**
    * \brief An event that indicates you are no longer injecting audio.
    * \remarks This event is raised if injection is stopped early with StopAudioInjection()
    *  or if the file that you are injecting audio from has reached its natural end.
    */
    AudioInjectionCompleted EventAudioInjectionCompleted;

    /**
     * \brief Set whether microphone audio and injected audio should be transmitted to no channels, all channels, or a specific single channel.
     * \param mode An enum that specifies a transmission policy.
     * \param singleChannel The specific channel to transmit to when TransmissionMode::Single is set (this is otherwise ignored).
     * \remarks Audio transmission changes take effect immediately in all channels this user is already connected to. The changes also affect future channels that are joined:
     * - None: Audio does not automatically transmit to new channels or to text-only channels when audio is added.
     * - All: Audio automatically transmits to new channels and to text-only channels when audio is added.
     * - Single: Audio only transmits into the specified channel, and does not automatically switch to new channels even if this channel is disconnected.
     *
     * Important: You can override and change this setting by passing "true" for the switchTransmission argument in IChannelSession::BeginConnect() and IChannelSession::BeginSetAudioConnected().
     * \return VxErrorInvalidArgument if the mode is TransmissionMode::Single and the default or no ChannelId argument is provided.
     */
    virtual VivoxCoreError SetTransmissionMode(TransmissionMode mode, ChannelId singleChannel = ChannelId()) = 0;

    /**
     * \brief Get the transmission policy that is set for the player.
     * \return The active TransmissionMode.
     * \see SetTransmissionMode()
     */
    virtual TransmissionMode GetTransmissionMode() const = 0;

    /**
     * \brief Get the ChannelId of each channel that will broadcast non-muted microphone input and injected audio.
     * \return An array of transmitting ChannelIds.
     * \see SetTransmissionMode()
     */
    virtual TArray<ChannelId> GetTransmittingChannels() const = 0;

    /**
     * \brief Set how often the SDK raises IChannelSession::EventAfterParticipantUpdated events that relate to speaking activity.
     * \param rate An enum that specifies the frequency of participant events due to changes in speech detection or audio energy.
     * \remarks By default, the Vivox SDK supports a simple speaking/not-speaking indicator for channel participants;
     * for this use case, keeping the default value of ParticipantSpeakingUpdateRate::StateChange is sufficient.
     * If you want to create a dynamic voice activity indicator or other real-time visual representation of audio energy levels,
     * supply this function with a ParticipantSpeakingUpdateRate value of Update1Hz, Update5Hz, or Update10Hz for updates of up to 1, 5, or 10
     * times per second as audio energy and other participant properties change. For more information, see the Vivox Unreal Developer Documentation.
     *
     * Important: Setting a ParticipantSpeakingUpdateRate of any per second rate
     * will necessarily increase network traffic between the application and the Vivox servers.
     * \return 0 on success
     */
    virtual VivoxCoreError SetParticipantSpeakingUpdateRate(ParticipantSpeakingUpdateRate rate) = 0;

    /**
     * \brief Get the frequency set for speech-related participant events for all participants in all connected channels.
     * \return The current ParticipantSpeakingUpdateRate.
     * \see SetParticipantSpeakingUpdateRate()
     */
    virtual ParticipantSpeakingUpdateRate GetParticipantSpeakingUpdateRate() const = 0;

    /**
     * \brief The text-to-speech (TTS) subsystem instance associated with this login session.
     */
    virtual ITextToSpeech &TTS() = 0;

    /**
    * \brief Sign the account out of the Vivox system. This does not raise a property event for changing the State to LoginState.LoggedOut,
    * although the state will be set to that upon completion of the function.
    */
    virtual void Logout() = 0;

    /**
    * \brief Get a login token for this account.
    *
    * \param tokenSigningKey The key that corresponds to the issuer for this account that is used to sign the token.
    * \param tokenExpirationDuration The length of time the token is valid for.
    * \return An access token that can be used to sign in this account.
    * \remarks To be used only by applications without secure communications requirements.
    */
    virtual FString GetLoginToken(const FString &tokenSigningKey, FTimespan tokenExpirationDuration) const = 0;
};
