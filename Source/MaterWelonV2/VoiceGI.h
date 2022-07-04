// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "VoicePC.h"

#if WITH_VIVOXCORE
#include "VivoxCore.h"
#endif

#include "VoiceGI.generated.h"

#define VIVOX_SERVER "https://mt1s.www.vivox.com/api2"
#define VIVOX_ISSUER "jouzib6576-ma15-dev"
#define VIVOX_DOMAIN "mt1s.vivox.com"
#define VIVOX_SECRET "much986"
#define TOKEN_EXPIRY (30 * 60)

USTRUCT(Blueprintable)
struct FVivoxAudioDevice
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly)
		FString Name;

	UPROPERTY(BlueprintReadOnly)
		FString UUID;
};

enum class EVivoxInit
{
	None = -1,
	Errors = 0,
	Warnings = 1,
	Info = 2,
	Debug = 3,
	Trace = 4,
	All = 5
};


UCLASS()
class MATERWELONV2_API UVoiceGI : public UGameInstance
{
	GENERATED_BODY()

		static bool s_bEnableVivox;

public:
	UVoiceGI();

	virtual void Init() override;
	virtual void StartGameInstance() override;

	// LOGIN

	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void LoginVivoxWithID(FString UserID);

	UFUNCTION(BlueprintPure, Category = "Vivox")
		bool IsVivoxLoggedIn() const { return m_bVivoxLoggedIn; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
		FString GetVivoxLoggedInPlayerName() const { return m_VivoxLoggedInPlayerName; }


	// CHANNELS

	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void LeaveVoiceChannels(AVoicePC* PC);
	
	void Update3DPosition(FVector SpeakerLocation, FVector EarsLocation, FVector Forward, FVector Up);

	UFUNCTION(BlueprintPure, Category = "Vivox")
		bool IsInVoiceChannel() const { return m_bIsInVoiceChannel; }

	UFUNCTION(BlueprintPure, Category = "Vivox")
		FString GetVivoxChannelName() const { return m_VivoxChannelName; }

#if WITH_VIVOXCORE
	VivoxCoreError JoinVoiceChannels(const uint8 TeamChannelToJoin, ChannelType ChannelType, AVoicePC* PC, Channel3DProperties SpaceProperties, const FString& SessionID = "");
#endif

	UFUNCTION(BlueprintPure, Category = "Vivox")
		TArray<FString> GetConnectedClients(const FString& ChannelName) const;

	UFUNCTION(BlueprintPure, Category = "Vivox")
		TArray<FString> GetClientsTalking(const FString& ChannelName) const;




	// DEVICES

		// Input devices

	// Returns all the audio devices that are available for input.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		TArray<FVivoxAudioDevice> GetAudioInputDevices() const;

	// Returns the currently used audio input device.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		FVivoxAudioDevice GetCurrentAudioInputDevice() const;

	// Sets the device used for input. Takes the ID of the device.
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void SetAudioInputDevice(const FString& AudioDeviceID);

	// Returns the current input device volume (-50 to 50)
	UFUNCTION(BlueprintPure, Category = "Vivox")
		int32 GetAudioInputDeviceVolume() const;

	// Sets the input device volume level (-50 = completely muted, 0 = normal, 50 = loud)
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void SetAudioInputDeviceVolume(int32 NewVolume = 0);

	// Returns weather or not the input device is currently muted.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		bool IsMutedSelfInput() const;

	// Mutes or unmutes the input device.
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void ToggleMuteSelfInput(bool bMute = true);


	// Output

// Returns all the audio devices that are available for output.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		TArray<FVivoxAudioDevice> GetAudioOutputDevices() const;

	// Returns the currently used audio output device.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		FVivoxAudioDevice GetCurrentAudioOutputDevice() const;

	// Sets the device used for output. Takes the ID of the device.
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void SetAudioOutputDevice(const FString& AudioDeviceID);

	// Returns the current output device volume (-50 to 50)
	UFUNCTION(BlueprintPure, Category = "Vivox")
		int32 GetAudioOutputDeviceVolume() const;

	// Sets the output device volume level (-50 = completely muted, 0 = normal, 50 = loud)
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void SetAudioOutputDeviceVolume(int32 NewVolume = 0);

	// Returns weather or not the output device is currently muted.
	UFUNCTION(BlueprintPure, Category = "Vivox")
		bool IsMutedSelfOutput() const;

	// Mutes or unmutes the output device.
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void ToggleMuteSelfOutput(bool bMute = true);


	// Voice info

// Returns the current transmission mode
	UFUNCTION(BlueprintPure, Category = "Vivox")
		TransmissionMode GetTransmissionMode() const;

	// Returns all the channels that the client is transmitting to
	UFUNCTION(BlueprintPure, Category = "Vivox")
		TArray<FString> GetTransmittingChannels() const;

	// Sets the current transmission mode
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void SetTransmissionMode(TransmissionMode NewMode);


	// Client mute

// Mutes or unmutes a remote client. 
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void ToggleMuteClient(const FString& ClientToMute, bool bMute = true);

private:
	void LogoutVivox();


#if WITH_VIVOXCORE
	VivoxCoreError InitializeVivox(EVivoxInit logLevel);
	VivoxCoreError LoginVivox(const FString& PlayerName);

	void BindLoginSessionHandlers(bool DoBind, ILoginSession& LoginSession);
	void BindChannelSessionHandlers(bool DoBind, IChannelSession& ChannelSession);

	/** Vivox Delegates */
	void OnLoginSessionStateChanged(LoginState State);
	void OnChannelParticipantAdded(const IParticipant& Participant);
	void OnChannelParticipantRemoved(const IParticipant& Participant);
	void OnChannelParticipantUpdated(const IParticipant& Participant);
	void OnChannelAudioStateChanged(const IChannelConnectionState& State);
	void OnChannelTextStateChanged(const IChannelConnectionState& State);
	void OnChannelTextMessageReceived(const IChannelTextMessage& Message);
#endif

	FString m_VivoxChannelName;
	FString m_VivoxLoggedInPlayerName;

	bool m_bIsVivoxInitialized;
	bool m_bIsVivoxInitializing;
	bool m_bVivoxLoggedIn;
	bool m_bIsVivoxLoggingIn;
	bool m_bIsInVoiceChannel;

#if WITH_VIVOXCORE
	IClient* m_VivoxVoiceClient;
	AccountId m_LoggedInAccountID;
	ILoginSession* m_LoginSession;
	ChannelId m_LastKnownTransmittingChannel;
#endif
};