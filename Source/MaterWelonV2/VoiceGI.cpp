// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceGI.h"

#include "Kismet/KismetSystemLibrary.h"

bool UVoiceGI::s_bEnableVivox = true;

UVoiceGI::UVoiceGI() :
	m_bIsVivoxInitialized(false),
	m_bIsVivoxInitializing(false),
	m_bVivoxLoggedIn(false),
	m_bIsVivoxLoggingIn(false)
#if WITH_VIVOXCORE
	, m_VivoxVoiceClient(&static_cast<FVivoxCoreModule*>(&FModuleManager::Get().LoadModuleChecked(TEXT("VivoxCore")))->VoiceClient())
#endif
{
}

void UVoiceGI::Init()
{
#if WITH_VIVOXCORE
	if (s_bEnableVivox && !UKismetSystemLibrary::IsDedicatedServer(GetWorld()))
	{
		InitializeVivox(EVivoxInit::All);
	}
#endif

	UGameInstance::Init();
}

void UVoiceGI::StartGameInstance()
{
	UGameInstance::StartGameInstance();
}

#if WITH_VIVOXCORE
VivoxCoreError UVoiceGI::JoinVoiceChannels(const uint8 TeamChannelToJoin, ChannelType ChannelType, AVoicePC* PC, Channel3DProperties SpaceProperties, const FString& SessionID)
{
	if (!s_bEnableVivox) return VxErrorNotInitialized;

	if (!m_bVivoxLoggedIn)
	{
		return VxErrorNotLoggedIn;
	}

	// Player is already in a channel so let's change that
	if (m_bIsInVoiceChannel)
	{
		LeaveVoiceChannels(PC);

		JoinVoiceChannels(TeamChannelToJoin, ChannelType, PC, SpaceProperties, SessionID);
		return VxErrorInternalError;  // There's no error for being already in a channel so let's just throw an internal error
	}

	ensure(!m_VivoxLoggedInPlayerName.IsEmpty());

	// Create the channel name for the player to join. If the SessionID is empty we generate a random guid for the channel name so the player is put into a "private" room else put them into the actual team room
	const FString GeneratedChannelName = FGuid::NewGuid().ToString(EGuidFormats::DigitsWithHyphens);
	m_VivoxChannelName = FString::Printf(TEXT("TN%d_%s"), TeamChannelToJoin, SessionID.IsEmpty() ? *FString::Printf(TEXT("G_%s"), *GeneratedChannelName) : *SessionID);

	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);


	// It's perfectly safe to add 3D properties to any channel type (they don't have any effect if the channel type is not Positional)
	ChannelId Channel = ChannelId(VIVOX_ISSUER, m_VivoxChannelName, VIVOX_DOMAIN, ChannelType, SpaceProperties /* Channel3DProperties(8100, 270, 1.0, EAudioFadeModel::InverseByDistance)*/);
	IChannelSession& ChannelSession = LoginSession.GetChannelSession(Channel);

	// This is insecure and should be done via game server
	const FString JoinToken = ChannelSession.GetConnectToken(VIVOX_SECRET, FTimespan::FromSeconds(TOKEN_EXPIRY));

	IChannelSession::FOnBeginConnectCompletedDelegate OnBeginConnectCompleteCallback;
	OnBeginConnectCompleteCallback.BindLambda([this, &LoginSession, &ChannelSession, PC](VivoxCoreError Status) {
		if (VxErrorSuccess != Status)
		{
			BindChannelSessionHandlers(false, ChannelSession);
			LoginSession.DeleteChannelSession(ChannelSession.Channel());

			m_bIsInVoiceChannel = false;

			// Log the error
			UE_LOG(LogTemp, Error, TEXT("Failed to connect to channel"));
		}
		else
		{
			LoginSession.SetTransmissionMode(TransmissionMode::Single);
			BindChannelSessionHandlers(true, ChannelSession);

			m_bIsInVoiceChannel = true;

			// Log the success
			UE_LOG(LogTemp, Log, TEXT("Connected to channel"));

			// Call the event on the player controller
			if (AVoicePC* VoicePC = Cast<AVoicePC>(PC))
			{
				VoicePC->OnJoinChannel_Implementation(ChannelSession.Channel().Type(), ChannelSession.Channel().Name());
			}
		}
		});

	UE_LOG(LogTemp, Log, TEXT("Trying to connect to channel: %s"), *m_VivoxChannelName);

	m_LastKnownTransmittingChannel = Channel;
	return ChannelSession.BeginConnect(true, false, true, JoinToken, OnBeginConnectCompleteCallback);
}
#endif 

void UVoiceGI::LeaveVoiceChannels(AVoicePC* PC)
{
#if WITH_VIVOXCORE
	if (!s_bEnableVivox || !m_bVivoxLoggedIn) return;

	TArray<ChannelId> ChannelSessionKeys;
	m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).ChannelSessions().GenerateKeyArray(ChannelSessionKeys);
	for (const ChannelId& SessionKey : ChannelSessionKeys)
	{
		ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);
		IChannelSession& ChannelSession = LoginSession.GetChannelSession(SessionKey);

		PC->OnLeaveChannel(ChannelSession.Channel().Name());

		ChannelSession.Disconnect();
		BindChannelSessionHandlers(false, ChannelSession);
		LoginSession.DeleteChannelSession(SessionKey);
	}

	m_LastKnownTransmittingChannel = ChannelId();
	m_bIsInVoiceChannel = false;
#endif
}

void UVoiceGI::LoginVivoxWithID(FString UserID)
{
#if WITH_VIVOXCORE
	LoginVivox(UserID);
#endif
}

TArray<FString> UVoiceGI::GetConnectedClients(const FString& ChannelName) const
{
#if WITH_VIVOXCORE
	if (!s_bEnableVivox) return {};
	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);
	TArray<FString> clients;

	for (const auto& client : ChannelSession.Participants())
	{
		clients.Add(client.Key);
	}

	return clients;
#endif
	return {};
}

TArray<FString> UVoiceGI::GetClientsTalking(const FString& ChannelName) const
{
#if WITH_VIVOXCORE
	if (!s_bEnableVivox) return {};
	TArray<FString> clients;

	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);
	for (const auto& client : ChannelSession.Participants())
	{
		if (client.Value->SpeechDetected())
		{
			clients.Add(client.Key);
		}
	}

	return clients;
#endif
	return {};
}

void UVoiceGI::ToggleMuteClient(const FString& ClientToMute, bool bMute /*= true*/)
{
#if WITH_VIVOXCORE
	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);

	IParticipant* client = *ChannelSession.Participants().Find(ClientToMute);
	if (client)
	{
		client->SetLocalMute(bMute);
	}
#endif
}

void UVoiceGI::ToggleMuteSelfInput(bool bMute)
{
#if WITH_VIVOXCORE
	m_VivoxVoiceClient->AudioInputDevices().SetMuted(bMute);
#endif
}

bool UVoiceGI::IsMutedSelfInput() const
{
#if WITH_VIVOXCORE
	return m_VivoxVoiceClient->AudioInputDevices().Muted();
#endif
}

void UVoiceGI::ToggleMuteSelfOutput(bool bMute)
{
#if WITH_VIVOXCORE
	m_VivoxVoiceClient->AudioOutputDevices().SetMuted(bMute);
#endif
}

TransmissionMode UVoiceGI::GetTransmissionMode() const
{
#if WITH_VIVOXCORE
	return m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetTransmissionMode();
#endif
	return TransmissionMode();
}

TArray<FString> UVoiceGI::GetTransmittingChannels() const
{
#if WITH_VIVOXCORE
	TArray<ChannelId> channels = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetTransmittingChannels();

	TArray <FString> channelNames;

	for (const auto channel : channels) {
		channelNames.Add(channel.Name());
	}

	return channelNames;
#endif
	return TArray<FString>();
}

void UVoiceGI::SetTransmissionMode(TransmissionMode NewMode)
{
#if WITH_VIVOXCORE
	m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).SetTransmissionMode(NewMode);
#endif
}

bool UVoiceGI::IsMutedSelfOutput() const
{
#if WITH_VIVOXCORE
	return m_VivoxVoiceClient->AudioOutputDevices().Muted();
#endif
}

TArray<FVivoxAudioDevice> UVoiceGI::GetAudioInputDevices() const
{
#if WITH_VIVOXCORE
	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioInputDevices().AvailableDevices();

	TArray<FVivoxAudioDevice> NewDevices;
	for (const auto& device : devices)
	{
		NewDevices.Add({ device.Value->Name(), device.Value->Id() });
	}

	return NewDevices;
#endif 
	return {};
}

FVivoxAudioDevice UVoiceGI::GetCurrentAudioInputDevice() const
{
#if WITH_VIVOXCORE
	FString Name = m_VivoxVoiceClient->AudioInputDevices().EffectiveDevice().Name();
	FString Id = m_VivoxVoiceClient->AudioInputDevices().EffectiveDevice().Id();
	return { Name, Id };
#endif 
	return FVivoxAudioDevice();
}

TArray<FVivoxAudioDevice> UVoiceGI::GetAudioOutputDevices() const
{
#if WITH_VIVOXCORE
	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioOutputDevices().AvailableDevices();

	TArray<FVivoxAudioDevice> NewDevices;
	for (const auto& device : devices)
	{
		NewDevices.Add({ device.Value->Name(), device.Value->Id() });
	}

	return NewDevices;
#endif
	return {};
}

FVivoxAudioDevice UVoiceGI::GetCurrentAudioOutputDevice() const
{
#if WITH_VIVOXCORE
	FString Name = m_VivoxVoiceClient->AudioOutputDevices().EffectiveDevice().Name();
	FString Id = m_VivoxVoiceClient->AudioOutputDevices().EffectiveDevice().Id();
	return { Name, Id };
#endif
	return FVivoxAudioDevice();
}

void UVoiceGI::SetAudioInputDevice(const FString& AudioDeviceID)
{
#if WITH_VIVOXCORE
	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioInputDevices().AvailableDevices();
	for (const auto& device : devices) {
		if (device.Value->Id() == AudioDeviceID) {
			m_VivoxVoiceClient->AudioInputDevices().SetActiveDevice(*(device.Value));
			return;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Unable to set the input device"));
#endif
}

int32 UVoiceGI::GetAudioInputDeviceVolume() const
{
#if WITH_VIVOXCORE
	return m_VivoxVoiceClient->AudioInputDevices().VolumeAdjustment();
#endif
}

void UVoiceGI::SetAudioOutputDevice(const FString& AudioDeviceID)
{
#if WITH_VIVOXCORE
	TMap<FString, IAudioDevice*> devices = m_VivoxVoiceClient->AudioOutputDevices().AvailableDevices();
	for (const auto& device : devices) {
		if (device.Value->Id() == AudioDeviceID) {
			m_VivoxVoiceClient->AudioOutputDevices().SetActiveDevice(*(device.Value));
			return;
		}
	}
	UE_LOG(LogTemp, Log, TEXT("Unable to set the output device"));
#endif
}

int32 UVoiceGI::GetAudioOutputDeviceVolume() const
{
#if WITH_VIVOXCORE
	return m_VivoxVoiceClient->AudioOutputDevices().VolumeAdjustment();
#endif
}

void UVoiceGI::SetAudioInputDeviceVolume(int32 NewVolume)
{
#if WITH_VIVOXCORE
	m_VivoxVoiceClient->AudioInputDevices().SetVolumeAdjustment(FMath::Clamp<int32>(NewVolume, -50, 50));
#endif
}

void UVoiceGI::SetAudioOutputDeviceVolume(int32 NewVolume)
{
#if WITH_VIVOXCORE
	m_VivoxVoiceClient->AudioOutputDevices().SetVolumeAdjustment(FMath::Clamp<int32>(NewVolume, -50, 50));
#endif
}

#if WITH_VIVOXCORE
VivoxCoreError UVoiceGI::InitializeVivox(EVivoxInit logLevel)
{
	if (m_bIsVivoxInitialized || m_bIsVivoxInitializing)
	{
		return VxErrorSuccess;
	}

	VivoxConfig Config;
	Config.SetLogLevel((vx_log_level)logLevel);
	VivoxCoreError Status = m_VivoxVoiceClient->Initialize(Config);
	if (Status != VxErrorSuccess)
	{
		// Something went wrong so we should log
		UE_LOG(LogTemp, Error, TEXT("Vivox Initialization failed"));
	}
	else
	{
		m_bIsVivoxInitialized = true;
	}

	return Status;
}

VivoxCoreError UVoiceGI::LoginVivox(const FString& PlayerName)
{
	if (!s_bEnableVivox) return VxErrorNotInitialized;

	if (m_bVivoxLoggedIn)
	{
		return VxErrorSuccess;
	}

	if (m_bIsVivoxLoggingIn)
	{
		return VxErrorSuccess;
	}

	if (!m_bIsVivoxInitialized)
	{
		return VxErrorNotInitialized;
	}

	if (m_VivoxVoiceClient == nullptr)
	{
		return VxErrorTargetObjectDoesNotExist;
	}

	m_VivoxLoggedInPlayerName = PlayerName;
	UE_LOG(LogTemp, Log, TEXT("Logging in to Vivox with the player name: %s"), *PlayerName);

	m_LoggedInAccountID = AccountId(VIVOX_ISSUER, m_VivoxLoggedInPlayerName, VIVOX_DOMAIN);
	UE_LOG(LogTemp, Log, TEXT("Account ID: %s"), *(m_LoggedInAccountID.ToString()));

	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);

	ILoginSession::FOnBeginLoginCompletedDelegate OnBeginLoginCompleteCallback;
	OnBeginLoginCompleteCallback.BindLambda([this, &LoginSession](VivoxCoreError Status) {
		m_bIsVivoxLoggingIn = false;
		if (VxErrorSuccess != Status)
		{
			BindLoginSessionHandlers(false, LoginSession);
			m_LoggedInAccountID = AccountId();
			m_VivoxLoggedInPlayerName = FString();
			m_bVivoxLoggedIn = false;

			// Something went wrong so we should log
			UE_LOG(LogTemp, Log, TEXT("Vivox Login Error"));
		}
		else
		{
			m_bIsVivoxLoggingIn = true;
			m_bVivoxLoggedIn = true;
			BindLoginSessionHandlers(true, LoginSession);

			// Log the success
			UE_LOG(LogTemp, Log, TEXT("Vivox Login Success"));
		}
		});

	const FString LoginToken = LoginSession.GetLoginToken(VIVOX_SECRET, FTimespan::FromSeconds(TOKEN_EXPIRY));
	UE_LOG(LogTemp, Log, TEXT("Login Token: %s"), *LoginToken);

	return LoginSession.BeginLogin(VIVOX_SERVER, LoginToken, OnBeginLoginCompleteCallback);
}
#endif

void UVoiceGI::LogoutVivox()
{
#if WITH_VIVOXCORE
	if (!s_bEnableVivox) return;
	if (!m_bVivoxLoggedIn && !m_bIsVivoxLoggingIn)
	{
		return;
	}

	ILoginSession& LoginSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID);

	LoginSession.Logout();

	m_LoggedInAccountID = AccountId();
	m_VivoxLoggedInPlayerName = FString();
	m_bIsVivoxLoggingIn = false;
	m_bVivoxLoggedIn = false;
#endif
}

void UVoiceGI::Update3DPosition(FVector SpeakerLocation, FVector EarsLocation, FVector Forward, FVector Up)
{
#if WITH_VIVOXCORE
	if (!m_bIsInVoiceChannel) {
		return;
	}

	// Check if the channel that we are in is a positional channel
	IChannelSession& ChannelSession = m_VivoxVoiceClient->GetLoginSession(m_LoggedInAccountID).GetChannelSession(m_LastKnownTransmittingChannel);
	if (ChannelSession.Channel().Type() == ChannelType::Positional)
	{
		// Update the position of the speaker
		ChannelSession.Set3DPosition(SpeakerLocation, EarsLocation, Forward, Up);
	}
#endif
	return;
}

#if WITH_VIVOXCORE
void UVoiceGI::BindLoginSessionHandlers(bool DoBind, ILoginSession& LoginSession)
{
	if (DoBind)
	{
		LoginSession.EventStateChanged.AddUObject(this, &UVoiceGI::OnLoginSessionStateChanged);
	}
	else
	{
		LoginSession.EventStateChanged.RemoveAll(this);
	}
}

void UVoiceGI::BindChannelSessionHandlers(bool DoBind, IChannelSession& ChannelSession)
{
	if (DoBind)
	{
		ChannelSession.EventAfterParticipantAdded.AddUObject(this, &UVoiceGI::OnChannelParticipantAdded);
		ChannelSession.EventBeforeParticipantRemoved.AddUObject(this, &UVoiceGI::OnChannelParticipantRemoved);
		ChannelSession.EventAfterParticipantUpdated.AddUObject(this, &UVoiceGI::OnChannelParticipantUpdated);
		ChannelSession.EventAudioStateChanged.AddUObject(this, &UVoiceGI::OnChannelAudioStateChanged);
		ChannelSession.EventTextStateChanged.AddUObject(this, &UVoiceGI::OnChannelTextStateChanged);
		ChannelSession.EventTextMessageReceived.AddUObject(this, &UVoiceGI::OnChannelTextMessageReceived);
	}
	else
	{
		ChannelSession.EventAfterParticipantAdded.RemoveAll(this);
		ChannelSession.EventBeforeParticipantRemoved.RemoveAll(this);
		ChannelSession.EventAfterParticipantUpdated.RemoveAll(this);
		ChannelSession.EventAudioStateChanged.RemoveAll(this);
		ChannelSession.EventTextStateChanged.RemoveAll(this);
		ChannelSession.EventTextMessageReceived.RemoveAll(this);
	}
}

void UVoiceGI::OnLoginSessionStateChanged(LoginState State)
{
	switch (State)
	{
	case LoginState::LoggedOut:
		m_LoggedInAccountID = AccountId();
		m_VivoxLoggedInPlayerName = FString();
		m_bIsVivoxLoggingIn = false;
		m_bVivoxLoggedIn = false;
		break;
	}
}

void UVoiceGI::OnChannelParticipantAdded(const IParticipant& Participant)
{
	ChannelId Channel = Participant.ParentChannelSession().Channel();
	UE_LOG(LogTemp, Log, TEXT("User %s has joined channel %s (self = %s)"), *Participant.Account().Name(), *Channel.Name(), Participant.IsSelf() ? TEXT("true") : TEXT("false"));
}

void UVoiceGI::OnChannelParticipantRemoved(const IParticipant& Participant)
{
}

void UVoiceGI::OnChannelParticipantUpdated(const IParticipant& Participant)
{
	if (Participant.IsSelf())
	{
		UE_LOG(LogTemp, Log, TEXT("Self Participant Updated (audio=%d, text=%d, speaking=%d)"), Participant.InAudio(), Participant.InText(), Participant.SpeechDetected());
	}
}

void UVoiceGI::OnChannelAudioStateChanged(const IChannelConnectionState& State)
{
}

void UVoiceGI::OnChannelTextStateChanged(const IChannelConnectionState& State)
{
}

void UVoiceGI::OnChannelTextMessageReceived(const IChannelTextMessage& Message)
{
}
#endif
