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

#include "ChannelSession.h"
#include "VivoxCore.h"
#include "LoginSession.h"
#include "VxcErrors.h"
#include "VivoxNativeSdk.h"
#include "Participant.h"
#include "ChannelTextMessage.h"
#include "TranscribedMessage.h"
#include "ChannelConnectionState.h"

#define CHECK_ATTACHED ensure(!_detached); if(_detached) return;
#define CUR_CLASS_FUNC (FString(__FUNCTION__))

ChannelSession::ChannelSession(LoginSession &parent, const FString &sessionGroupHandle, const ChannelId &id) :
    _loginSession(parent),
    _audioState(ConnectionState::Disconnected),
    _textState(ConnectionState::Disconnected),
    _channelState(ConnectionState::Disconnected),
    _typing(false),
    _isSessionBeingTranscribed(false),
    _channel(id),
    _groupHandle(sessionGroupHandle),
    _detached(false)
{
    UE_LOG(VivoxCore, Log, TEXT("ChannelSession created for %s"), *_channel.ToString());
    ensure(_channel.IsValid());
    _sessionHandle = _groupHandle + TEXT("_") + id.Name();
    _eventSdkEventRaised = VivoxNativeSdk::Get().EventSdkEventRaised.AddLambda([this](const vx_evt_base_t &evt)
    {
        if (_detached) return;
        HandleEvent(evt);
    });
}

ChannelSession::~ChannelSession()
{
    UE_LOG(VivoxCore, Log, TEXT("ChannelSession destroyed for %s"), *_channel.ToString());
    CleanupEventHandler();
}

void ChannelSession::CleanupEventHandler()
{
    if (_eventSdkEventRaised.IsValid()) {
        VivoxNativeSdk::Get().EventSdkEventRaised.Remove(_eventSdkEventRaised);
        _eventSdkEventRaised = FDelegateHandle();
    }
}

FString ChannelSession::SessionHandle()
{
    ensure(!_detached);
    return _sessionHandle;
}

ILoginSession & ChannelSession::Parent()
{
    ensure(!_detached);
    return _loginSession;
}

ConnectionState ChannelSession::AudioState() const
{
    ensure(!_detached);
    return _audioState;
}

ConnectionState ChannelSession::TextState() const
{
    ensure(!_detached);
    return _textState;
}

ConnectionState ChannelSession::ChannelState() const
{
    ensure(!_detached);
    return _channelState;
}

const TMap<FString, IParticipant*>& ChannelSession::Participants() const
{
    ensure(!_detached);
    return _participants;
}

bool ChannelSession::Typing() const
{
    ensure(!_detached);
    return _typing;
}

void ChannelSession::SetTyping(bool value)
{
    ensure(!_detached);
    unimplemented();
}

bool ChannelSession::IsTransmitting() const
{
    ensure(!_detached);
    return _loginSession.GetTransmittingChannels().Contains(_channel);
}

void ChannelSession::HandleEvent(const vx_evt_base_t& evt)
{
    ensure(!_detached);
    switch (evt.type)
    {
    case evt_participant_added:
    {
        const vx_evt_participant_added_t &tevt(reinterpret_cast<const vx_evt_participant_added_t &>(evt));
        if (!IsMine(tevt)) return;
        if (!_participants.Contains(AccountId::AccountNameFromUri(tevt.participant_uri)))
        {
            Participant *participant = new Participant(*this, tevt);
            _participants.Add(participant->Account().Name(), participant);
            EventAfterParticipantAdded.Broadcast(*participant);
            if (participant->IsSelf())
                CheckSessionConnection();
        } else {
            UE_LOG(VivoxCore, Warning, TEXT("Dropping participant added event for participant already in session (%s)"), *FString(tevt.participant_uri));
        }
    }
    break;
    case evt_participant_removed:
    {
        const vx_evt_participant_removed_t &tevt(reinterpret_cast<const vx_evt_participant_removed_t &>(evt));
        if (!IsMine(tevt)) return;
        FString ParticipantKey = AccountId::AccountNameFromUri(tevt.participant_uri);
        if (_participants.Contains(ParticipantKey)) {
        Participant *participant = static_cast<Participant*>(_participants[ParticipantKey]);
            participant->HandleEvent(tevt);
            EventBeforeParticipantRemoved.Broadcast(*participant);
            _participants.Remove(ParticipantKey);
            delete participant;
        } else {
            UE_LOG(VivoxCore, Warning, TEXT("Dropping participant removed event for participant not in session (%s)"), *FString(tevt.participant_uri));
        }
    }
    break;
    case evt_participant_updated:
    {
        const vx_evt_participant_updated_t &tevt(reinterpret_cast<const vx_evt_participant_updated_t &>(evt));
        if (!IsMine(tevt)) return;
        FString ParticipantKey = AccountId::AccountNameFromUri(tevt.participant_uri);
        if (_participants.Contains(ParticipantKey)) {
            Participant *participant = static_cast<Participant*>(_participants[ParticipantKey]);
            if (participant->HandleEvent(tevt)) {
                EventAfterParticipantUpdated.Broadcast(*participant);
            }
        } else {
            UE_LOG(VivoxCore, Warning, TEXT("Dropping participant updated event for participant not in session (%s)"), *FString(tevt.participant_uri));
        }
    }
    break;
    case evt_media_stream_updated:
    {
        const vx_evt_media_stream_updated_t &tevt(reinterpret_cast<const vx_evt_media_stream_updated_t &>(evt));
        if (!IsMine(tevt)) return;
        if (tevt.state == session_media_connected && _audioState == ConnectionState::Connecting)
        {
            SetAudioState(ConnectionState::Connected);
        } else if (tevt.state == session_media_disconnected)
        {
            if (AudioState() == ConnectionState::Connecting && ChannelState() != ConnectionState::Connected)
            {
                Disconnect();
            }
            SetAudioState(ConnectionState::Disconnected);
        }
    }
    break;
    case evt_text_stream_updated:
    {
        const vx_evt_text_stream_updated_t &tevt(reinterpret_cast<const vx_evt_text_stream_updated_t &>(evt));
        if (!IsMine(tevt)) return;
        if (tevt.state == session_text_connected && _textState == ConnectionState::Connecting)
        {
            SetTextState(ConnectionState::Connected);
        } else if (tevt.state == session_text_disconnected)
        {
            if (TextState() == ConnectionState::Connecting && ChannelState() != ConnectionState::Connected)
            {
                Disconnect();
            }
            SetTextState(ConnectionState::Disconnected);
        }
    }
    break;
    case evt_session_removed:
    {
        const vx_evt_session_removed_t &tevt(reinterpret_cast<const vx_evt_session_removed_t &>(evt));
        if (!IsMine(tevt)) return;
        SetAudioState(ConnectionState::Disconnected);
        SetTextState(ConnectionState::Disconnected);
        SetChannelState(ConnectionState::Disconnected);
        _participants.Empty();
        _typing = false;
        if (_toBeDeleted)
        {
            Parent().DeleteChannelSession(_channel);
        }
    }
    break;
    case evt_message:
    {
        const vx_evt_message_t &tevt(reinterpret_cast<const vx_evt_message_t &>(evt));
        if (!IsMine(tevt)) return;

        if(_textState == ConnectionState::Connected) {
            ChannelTextMessage msg(*this, tevt);
            EventTextMessageReceived.Broadcast(msg);
        }
    }
    break;
    case evt_transcribed_message:
    {
        const vx_evt_transcribed_message_t &tevt(reinterpret_cast<const vx_evt_transcribed_message_t &>(evt));
        if (!IsMine(tevt)) return;

        // ignore transcribed messages if we've disconnected audio
        if (_audioState == ConnectionState::Connected) {
            TranscribedMessage msg(*this, tevt);
            EventTranscribedMessageReceived.Broadcast(msg);
        }
    }
    break;
    default:
        break;
    }
}

ChannelId ChannelSession::Channel() const
{
    ensure(!_detached);
    return _channel;
}

VivoxCoreError ChannelSession::BeginConnect(bool connectAudio, bool connectText, bool switchTransmission, const FString& accessToken, FOnBeginConnectCompletedDelegate theDelegate)
{
    ensure(!_detached);

    if (accessToken.IsEmpty()) return VxErrorInvalidArgument;
    if (!connectAudio && !connectText) return VxErrorInvalidArgument;
    if (!_channel.IsValid()) return VxErrorInvalidArgument;
    if (ChannelState() != ConnectionState::Disconnected)
    {
        return VxErrorInvalidState;
    }
    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    TSharedPtr<ChannelSession> protect = SharedThis(this);
    innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
    {
        if (_detached) return;

        if(resp.return_code != 0) {
            SetAudioState(ConnectionState::Disconnected);
            SetTextState(ConnectionState::Disconnected);
        }
        theDelegate.ExecuteIfBound(resp.status_code);
    });
    VivoxCoreError error = VivoxNativeSdk::Get().AddSession(
        _loginSession.LoginSessionId().ToString(),
        _groupHandle,
        _sessionHandle,
        accessToken,
        _channel, connectAudio, connectText, innerDelegate);
    if(error != VxErrorSuccess) {
        return error;
    }

    // set connecting state before switching transmission
    if (connectAudio)
        SetAudioState(ConnectionState::Connecting);
    if (connectText)
        SetTextState(ConnectionState::Connecting);
    SetChannelState(ConnectionState::Connecting);

    if (switchTransmission)
    {
        if (!connectAudio)
            UE_LOG(VivoxCore, Warning, TEXT("Switching audio transmission exclusively to text-only channel -- this is allowed but unusual."));
        error = _loginSession.SetTransmissionMode(TransmissionMode::Single, _channel);
    } else { // make tx requests based on stored state (this is the first opportunity to make ones set up ahead of time)
        error = _loginSession.SetTransmissionInCore();
    }    
    return error;
}

void ChannelSession::Disconnect(bool deleteOnDisconnect)
{
    ensure(!_detached);
    _toBeDeleted = deleteOnDisconnect;
    _loginSession.ClearTransmittingChannel(_channel);
    if (AudioState() == ConnectionState::Connecting || AudioState() == ConnectionState::Connected ||
        TextState() == ConnectionState::Connecting || TextState() == ConnectionState::Connected)
    {
        VivoxNativeSdk::Get().RemoveSession(_groupHandle, _sessionHandle, VivoxNativeSdk::FOnRequestCompletedDelegate());
    }

    if (AudioState() != ConnectionState::Disconnected)
        SetAudioState(ConnectionState::Disconnecting);
    if (TextState() != ConnectionState::Disconnected)
        SetTextState(ConnectionState::Disconnecting);
    if (ChannelState() != ConnectionState::Disconnected)
        SetChannelState(ConnectionState::Disconnecting);
}

static bool AlreadyDone(bool connect, ConnectionState state)
{
    if (connect)
    {
        return state == ConnectionState::Connected || state == ConnectionState::Connecting;
    } else
    {
        return state == ConnectionState::Disconnected || state == ConnectionState::Disconnecting;
    }
}

VivoxCoreError ChannelSession::BeginSetAudioConnected(bool value, bool switchTransmission, FOnBeginSetAudioConnectedCompletedDelegate theDelegate)
{
    ensure(!_detached);
    if (value && switchTransmission)
    {
        _loginSession.SetTransmissionMode(TransmissionMode::Single, _channel);
    }
    if (AlreadyDone(value, _audioState))
    {
        theDelegate.ExecuteIfBound(VxErrorSuccess);
        return VxErrorSuccess;
    }
    if (value)
    {
        VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
        TSharedPtr<ChannelSession> protect = SharedThis(this);
        innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
        {
            if (_detached) return;
            theDelegate.ExecuteIfBound(resp.status_code);
        });
        VivoxCoreError error = VivoxNativeSdk::Get().ConnectMedia(_sessionHandle, innerDelegate);
        if (error != VxErrorSuccess)
            return error;
        SetAudioState(ConnectionState::Connecting);
        return error;
    } else {
        _loginSession.ClearTransmittingChannel(_channel);
        VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
        TSharedPtr<ChannelSession> protect = SharedThis(this);
        innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
        {
            if (_detached) return;
            theDelegate.ExecuteIfBound(resp.status_code);
        });
        VivoxCoreError error = VivoxNativeSdk::Get().DisconnectMedia(_sessionHandle, innerDelegate);
        if (error != VxErrorSuccess)
            return error;
        SetAudioState(ConnectionState::Disconnecting);
        return error;
    }
}

VivoxCoreError ChannelSession::BeginSetTextConnected(bool value, FOnBeginSetTextConnectedCompletedDelegate theDelegate)
{
    ensure(!_detached);

    if (AlreadyDone(value, _textState))
    {
        theDelegate.ExecuteIfBound(VxErrorSuccess);
        return VxErrorSuccess;
    }
    if (value)
    {
        VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
        TSharedPtr<ChannelSession> protect = SharedThis(this);
        innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
        {
            if (_detached) return;

            theDelegate.ExecuteIfBound(resp.status_code);
        });
        VivoxCoreError error = VivoxNativeSdk::Get().ConnectText(_sessionHandle, innerDelegate);
        if (error != VxErrorSuccess)
            return error;
        SetTextState(ConnectionState::Connecting);
        return error;
    } else {
        VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
        TSharedPtr<ChannelSession> protect = SharedThis(this);
        innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
        {
            if (_detached) return;

            theDelegate.ExecuteIfBound(resp.status_code);
        });
        VivoxCoreError error = VivoxNativeSdk::Get().DisconnectText(_sessionHandle, innerDelegate);
        if (error != VxErrorSuccess)
            return error;
        SetTextState(ConnectionState::Disconnecting);
        return error;
    }
}

VivoxCoreError ChannelSession::BeginSendText(const FString& language,
    const FString& message,
    const FString& applicationStanzaNamespace,
    const FString& applicationStanzaBody,
    FOnBeginSendTextCompletedDelegate theDelegate)
{
    ensure(!_detached);

    if (message.IsEmpty()) return VxErrorInvalidArgument;

    if (TextState() != ConnectionState::Connected) return VxErrorInvalidState;
    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    TSharedPtr<ChannelSession> protect = SharedThis(this);
    innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
    {
        if (_detached) return;

        theDelegate.ExecuteIfBound(resp.status_code);
    });
    VivoxCoreError error = VivoxNativeSdk::Get().SendMessage(_sessionHandle, language, message, applicationStanzaNamespace, applicationStanzaBody, innerDelegate);
    return error;
}

VivoxCoreError ChannelSession::BeginSendText(const FString& message, FOnBeginSendTextCompletedDelegate theDelegate)
{
    return BeginSendText(FString(), message, FString(), FString(), theDelegate);
}

VivoxCoreError ChannelSession::Set3DPosition(const FVector &speakerPosition, const FVector &listenerPosition, const FVector &listenerForwardVector, const FVector &listenerUpVector)
{
    ensure(!_detached);

    // Session must have Audio Connected for 3D position data to be processed correctly
    if (AudioState() != ConnectionState::Connected)
    {
        UE_LOG(VivoxCore, Error, TEXT("%s: failed for InvalidState - Channel AudioState Disconnected"), *CUR_CLASS_FUNC);
        return VxErrorInvalidState;
    }
    else if (_channel.Type() != ChannelType::Positional)
    {
        UE_LOG(VivoxCore, Error, TEXT("%s: failed for InvalidState - Channel Type must be Positional"), *CUR_CLASS_FUNC);
        return VxErrorInvalidState;
    }

    return VivoxNativeSdk::Get().Set3DPosition(_sessionHandle, speakerPosition, listenerPosition, listenerForwardVector, listenerUpVector);
}

FString ChannelSession::GetConnectToken(const FString& tokenSigningKey, FTimespan tokenExpirationDuration) const
{
    ensure(!_detached);

    return VivoxNativeSdk::GetJoinToken(this->_loginSession.LoginSessionId(), _channel, tokenSigningKey, tokenExpirationDuration);
}

void ChannelSession::Detach()
{
    ensure(!_detached);
    if(!_detached)
    {
        _detached = true;
    }
}

void ChannelSession::SetAudioState(ConnectionState value)
{
    if (value == _audioState)
        return;
    _audioState = value;
    ChannelConnectionState state(*this, _audioState);
    EventAudioStateChanged.Broadcast(state);
    if (value == ConnectionState::Connected)
        CheckSessionConnection();
}

void ChannelSession::SetTextState(ConnectionState value)
{
    if (value == _textState)
        return;
    _textState = value;
    ChannelConnectionState state(*this, _textState);
    EventTextStateChanged.Broadcast(state);
    if(value == ConnectionState::Connected)
        CheckSessionConnection();
}

void ChannelSession::SetChannelState(ConnectionState value)
{
    if (value == _channelState)
        return;
    _channelState = value;
    ChannelConnectionState state(*this, value);
    EventChannelStateChanged.Broadcast(state);
}

bool ChannelSession::IsSessionBeingTranscribed() const
{
    ensure(!_detached);
    return _isSessionBeingTranscribed;
}

void ChannelSession::CheckSessionConnection()
{
    if (AudioState() != ConnectionState::Connecting && TextState() != ConnectionState::Connecting && Participants().Find(_loginSession.LoginSessionId().Name()))
    {
        SetChannelState(ConnectionState::Connected);
        return;
    }
}

VivoxCoreError ChannelSession::BeginSetChannelTranscription(bool value, const FString &accessToken, FOnBeginSetChannelTranscriptionCompletedDelegate theDelegate)
{
    ensure(!_detached);
    if (value == _isSessionBeingTranscribed)
    {
        theDelegate.ExecuteIfBound(VxErrorSuccess);
        return VxErrorSuccess;
    }
    else if (value && (AudioState() == ConnectionState::Disconnecting || AudioState() == ConnectionState::Disconnected))
    {
        // print warning and continue
        UE_LOG(VivoxCore, Warning, TEXT("%s: Transcription events will not occur unless Channel AudioState is Connected (since there is no speech)."), *CUR_CLASS_FUNC);
    }

    VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
    TSharedPtr<ChannelSession> protect = SharedThis(this);
    innerDelegate.BindLambda([this, theDelegate, protect](const vx_resp_base_t &resp)
    {
        if (_detached) return;

        if (resp.return_code == 0) { // if successful, set current state to requested state, otherwise no change
            _isSessionBeingTranscribed = (bool)reinterpret_cast<vx_req_session_transcription_control_t *>(resp.request)->enable;
        }
        theDelegate.ExecuteIfBound(resp.status_code);
    });
    VivoxCoreError error = VivoxNativeSdk::Get().SetTranscription(value, _sessionHandle, accessToken, innerDelegate);
    return error;
}

FString ChannelSession::GetTranscriptionToken(const FString& tokenSigningKey, FTimespan tokenExpirationDuration) const
{
    ensure(!_detached);

    return VivoxNativeSdk::GetTranscriptionToken(this->_loginSession.LoginSessionId(), _channel, tokenSigningKey, tokenExpirationDuration);
}