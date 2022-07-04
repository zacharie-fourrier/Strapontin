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
#include "ConnectionState.h"
#include "VivoxCoreCommon.h"

class ILoginSession;

/**
 * \brief A connection to a channel.
 */
class VIVOXCORE_API IChannelSession
{
public:
    /* @cond */
    DECLARE_EVENT_OneParam(IChannelSession, AudioStateChanged, const IChannelConnectionState &)
    DECLARE_EVENT_OneParam(IChannelSession, TextStateChanged, const IChannelConnectionState &)
    DECLARE_EVENT_OneParam(IChannelSession, ChannelStateChanged, const IChannelConnectionState &)
    DECLARE_EVENT_OneParam(IChannelSession, AfterParticipantAdded, const IParticipant &)
    DECLARE_EVENT_OneParam(IChannelSession, BeforeParticipantRemoved, const IParticipant &)
    DECLARE_EVENT_OneParam(IChannelSession, AfterParticipantUpdated, const IParticipant &)
    DECLARE_EVENT_OneParam(IChannelSession, TextMessageReceived, const IChannelTextMessage &)
    DECLARE_EVENT_OneParam(IChannelSession, TranscribedMessageReceived, const ITranscribedMessage &)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginConnectCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSetChannelTranscriptionCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSetAudioConnectedCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSetTextConnectedCompleted, VivoxCoreError)
    DECLARE_MULTICAST_DELEGATE_OneParam(FDelegateBeginSendTextCompleted, VivoxCoreError)
    /* @endcond */
public:
    virtual ~IChannelSession() = default;
    /**
     * \brief The login session that owns this channel session.
     */
    virtual ILoginSession &Parent() = 0;

    /**
     * \brief The state of the audio portion of this channel session.
     * \remarks Changes to this value can occur at any time due to network or moderator events.
     */
    virtual ConnectionState AudioState() const = 0;

    /**
     * \brief This event fires when the audio state changes.
     */
    AudioStateChanged EventAudioStateChanged;

    /**
     * \brief The state of the text portion of this channel session.
     * \remarks Changes to this value can occur at any time due to network or moderator events.
     */
    virtual ConnectionState TextState() const = 0;

    /**
     * \brief This event fires when the text state changes.
     */
    TextStateChanged EventTextStateChanged;

    /**
    * \brief The state of the overall connection of this channel session.
    * \remarks Changes to this value can occur at any time due to network or moderator events.
    *  It is not safe to join this user to another channel or to rejoin this channel while this
    *  property is in the ConnectionState::Disconnecting state, unless another IChannelSession
    *  is already connected. If not connected to another channel, then calls to BeginConnect() for
    *  this user should be avoided until this property is set to ConnectionState::Disconnected.
    *  Use EventChannelStateChanged to monitor state changes.
    */
    virtual ConnectionState ChannelState() const = 0;

    /**
    * \brief This event fires when the channel connection state changes.
    */
    ChannelStateChanged EventChannelStateChanged;

    /**
     * \brief The list of participants in this channel, including the current user.
     * \remarks Changes to this list can occur at any time. Key equals the participant's AccountId::Name().
     */
    virtual const TMap<FString, IParticipant *> & Participants() const = 0;

    /**
     * \brief This event is raised after a participant is added to the Participants() collection.
     */
    AfterParticipantAdded EventAfterParticipantAdded;

    /**
     * \brief This event is raised before a participant is removed from the Participants() collection.
     */
    BeforeParticipantRemoved EventBeforeParticipantRemoved;

    /**
     * \brief This event is raised after a participant property changes.
     */
    AfterParticipantUpdated EventAfterParticipantUpdated;

    /**
     * \brief Indicates if this user is typing.
     */
    virtual bool Typing() const = 0;
    /**
     * \brief Set whether this user is typing. Setting or clearing this causes IParticipantProperties.IsTyping to change for other users in the channel.
     */
    virtual void SetTyping(bool value) = 0;

    /**
     * \brief An event that indicates another player has sent the channel a text message.
     */
    TextMessageReceived EventTextMessageReceived;

    /**
     * \brief Indicates that microphone audio and injected audio will transmit to this session.
     * @see ILoginSession::SetTransmissionMode()
     */
    virtual bool IsTransmitting() const = 0;

    /**
     * \brief The channel ID of this session.
     */
    virtual ChannelId Channel() const = 0;

    /**
     * \brief The delegate called when BeginConnect() completes.
     */
    typedef FDelegateBeginConnectCompleted::FDelegate FOnBeginConnectCompletedDelegate;

    /**
     * \brief Perform the initial connection to the channel.
     *
     * \param connectAudio True to connect audio.
     * \param connectText True to connect text.
     * \param switchTransmission When connected, transmit only into this channel. This overrides and changes the TransmissionMode set in ILoginSession.
     * \param accessToken The access token that grants the user access to the channel.
     * \param theDelegate A delegate to call when this operation completes.
     * \return VxErrorInvalidArgument if:
     * - accessToken is empty
     * - connectAudio and connectText are both false
     * - Channel().IsValid() is false
     * \remarks Developers that do not have secure communications requirements can use GetConnectToken() to generate the required access token.
     */
    virtual VivoxCoreError BeginConnect(bool connectAudio, bool connectText, bool switchTransmission, const FString &accessToken, FOnBeginConnectCompletedDelegate theDelegate = FOnBeginConnectCompletedDelegate()) = 0;

    /**
     * \brief Disconnect the user from this channel.
     *
     * \remarks You should not try to join this user to another channel or to rejoin this channel while this session's ChannelState()
     *  property is set to ConnectionState::Disconnecting, unless another IChannelSession is already connected. If not connected to
     *  another channel, use EventChannelStateChanged to monitor property changes and wait for ConnectionState::Disconnected before
     *  calling BeginConnect() again. This object remains in the ILoginSession::ChannelSessions() list in the disconnected state.
     *  Use ILoginSession::DeleteChannelSession() to remove it from the list.
     *  Note: If transmission is specifically set to this channel, then TransmissionMode changes to "None" when disconnected.
     * \param deleteOnDisconnect Set to true to cause the channel to be removed from ILoginSession::ChannelSessions() immediately after sending out the EventChannelStateChanged event to disconnected.
     * \see ILoginSession::DeleteChannelSession()
     */
    virtual void Disconnect(bool deleteOnDisconnect = false) = 0;

    /**
    * \brief The delegate called when BeginSetAudioConnected() completes.
    */
    typedef FDelegateBeginSetAudioConnectedCompleted::FDelegate FOnBeginSetAudioConnectedCompletedDelegate;
    /**
     * \brief Add or remove audio from the channel session.
     *
     * \param value True to add audio, false to remove audio.
     * \param switchTransmission When audio is added, transmit only into this channel. This overrides and changes the TransmissionMode set in ILoginSession.
     * \param callback A delegate to call when this operation completes.
     * \remarks If transmission is specifically set to this channel, then when audio is removed, TransmissionMode changes to "None".
     * \return 0 for success.
     */
    virtual VivoxCoreError BeginSetAudioConnected(bool value, bool switchTransmission, FOnBeginSetAudioConnectedCompletedDelegate callback = FOnBeginSetAudioConnectedCompletedDelegate()) = 0;

    /**
    * \brief The delegate called when BeginSetTextConnected() completes.
    */
    typedef FDelegateBeginSetTextConnectedCompleted::FDelegate FOnBeginSetTextConnectedCompletedDelegate;
    /**
     * \brief Add or remove text from the channel session.
     *
     * \param value True to add text, false to remove text.
     * \param callback A delegate to call when this operation completes.
     * \return 0 for success.
     */
    virtual VivoxCoreError BeginSetTextConnected(bool value, FOnBeginSetTextConnectedCompletedDelegate callback = FOnBeginSetTextConnectedCompletedDelegate()) = 0;

    /**
    * \brief The delegate called when BeginSendText() completes.
    */
    typedef FDelegateBeginSendTextCompleted::FDelegate FOnBeginSendTextCompletedDelegate;
    /**
     * \brief Send a message to this channel.
     *
     * \param language The language of the message, for example, "en". To use the default language ("en" for most systems), set this to null. Note: This must conform to BCP 47 (https://tools.ietf.org/html/bcp47).
     * \param message The body of the message.
     * \param applicationStanzaNamespace An optional namespace element for additional application data.
     * \param applicationStanzaBody The additional application data body.
     * \param theDelegate A delegate to call when this operation completes.
     * \return 0 for success.
     */
    virtual VivoxCoreError BeginSendText(const FString &language,
        const FString &message,
        const FString &applicationStanzaNamespace = FString(),
        const FString &applicationStanzaBody = FString(),
        FOnBeginSendTextCompletedDelegate theDelegate = FOnBeginSendTextCompletedDelegate()) = 0;

    /**
    * \brief Send a message to this channel.
    *
    * \param message The body of the message.
    * \param theDelegate A delegate to call when this operation completes.
    * \return 0 for success.
    */
    virtual VivoxCoreError BeginSendText(const FString &message,
        FOnBeginSendTextCompletedDelegate theDelegate = FOnBeginSendTextCompletedDelegate()) = 0;

    /**
    * \brief Set the 3D position of the speaker, and the position and orientation of the listener.
    * \remarks For most applications, the speaker and listener positions are expected to be the same.
    *  Note that the SDK supports the decoupling of these positions (for example, the virtual "mouth"
    *  might be where the avatar is located, and the virtual "ears" are where the camera view is located).
    *  Because this is the most frequently used VivoxCore method (when using positional channels),
    *  you do not see any voice server response logged unless an error occurs (no reply is sent for success).
    *
    * \param speakerPosition The position of the virtual "mouth".
    * \param listenerPosition The position of the virtual "ear".
    * \param listenerForwardVector A unit vector that represents the forward (X) direction, or heading, of the listener.
    * \param listenerUpVector A unit vector that represents the up (Z) direction of the listener. Use FVector(0, 0, 1) for a "global" up in world space.
    *
    * \return 0 for success, or VxErrorInvalidState if IChannelSession AudioState is not Connected or if ChannelType is not Positional.
    */
    virtual VivoxCoreError Set3DPosition(const FVector &speakerPosition,
        const FVector &listenerPosition,
        const FVector &listenerForwardVector,
        const FVector &listenerUpVector) = 0;

    /**
     * \brief Get a token that can be used to connect to this channel.
     *
     * \param tokenSigningKey The key that corresponds to the issuer for this account that is used to sign the token.
     * \param tokenExpirationDuration The length of time the token is valid for.
     * \return A token that can be used to join this channel.
     * \remarks This is only to be used by applications without secure communications requirements.
     */
    virtual FString GetConnectToken(const FString & tokenSigningKey, FTimespan tokenExpirationDuration) const = 0;

    /**
     * \brief An event that indicates incoming transcribed text from a participant in a channel session.
     */
    TranscribedMessageReceived EventTranscribedMessageReceived;

    /**
     * \brief Indicates that this session is being transcibed.
     * \remarks To set this value, use BeginSetChannelTranscription().
     */
    virtual bool IsSessionBeingTranscribed() const = 0;

    /**
     * \brief The delegate called when BeginSetChannelTranscription() completes.
     */
    typedef FDelegateBeginSetChannelTranscriptionCompleted::FDelegate FOnBeginSetChannelTranscriptionCompletedDelegate;
    /**
     * \brief Enable or disable transcription for this channel session.
     * \param value True to enable channel transcription, false to disable transcription.
     * \param accessToken The access token that grants the user access to set transciption for the channel.
     * \param callback A delegate to call when this operation completes.
     * \return 0 for success.
     */
    virtual VivoxCoreError BeginSetChannelTranscription(bool value, const FString &accessToken, FOnBeginSetChannelTranscriptionCompletedDelegate callback = FOnBeginSetChannelTranscriptionCompletedDelegate()) = 0;

    /**
     * \brief Get a token that can be used to enable or disable transcription for this channel.
     * \param tokenSigningKey The key that corresponds to the issuer for this account that is used to sign the token.
     * \param tokenExpirationDuration The length of time the token is valid for.
     * \return A token that can be used to set transcriptions in this channel.
     * \remarks This is only to be used by applications without secure communications requirements.
     */
    virtual FString GetTranscriptionToken(const FString & tokenSigningKey, FTimespan tokenExpirationDuration) const = 0;
};
