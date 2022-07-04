// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TimerManager.h"

#if WITH_VIVOXCORE
#include "VivoxCore.h"
#endif

#include "VoicePC.generated.h"

USTRUCT(BlueprintType)
struct FSpaceAudioProperties
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 AudibleDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ConversationalDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		double AudioFadeIntensityByDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAudioFadeModel AudioFadeModel;
};


UCLASS()
class MATERWELONV2_API AVoicePC : public APlayerController
{
	GENERATED_BODY()
		
public:
	UFUNCTION(BlueprintCallable, Client, Unreliable)
		void ClientJoinVoice(const uint8 TeamNumber, ChannelType ChanType, const FSpaceAudioProperties& SpaceProps, const FString& SessionID);
	void ClientJoinVoice_Implementation(const uint8 TeamNumber, ChannelType ChanType, const FSpaceAudioProperties& SpaceProps, const FString& SessionID);

	// Function to set the 3d timer interval 
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void Set3DRefreshRate(float RefreshRate);

	// Function to set the 3d components
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void Set3DVoiceComponents(UStaticMeshComponent* newSpeakerComponent, UStaticMeshComponent* newListenerComponent);

	// Function to reset the 3d components
	UFUNCTION(BlueprintCallable, Category = "Vivox")
		void Reset3DVoiceComponents();

	// Event called whenever the player controller joins a channel
	UFUNCTION(BlueprintImplementableEvent, Category = "Voice")
		void OnJoinChannel(ChannelType ChanType, const FString& ChanName);
	void OnJoinChannel_Implementation(ChannelType ChanType, const FString& ChanName);

	// Event called whenever the player controller leaves a channel
	UFUNCTION(BlueprintImplementableEvent, Category = "Voice")
		void OnLeaveChannel(const FString& ChanName);
	void OnLeaveChannel_Implementation(const FString& ChanName);

private:
	FTimerHandle Timer3DPos;

	float Timer3DPosInterval = 0.1f;

	FVector c_Loc = FVector::ZeroVector;
	FVector c_For = FVector::ZeroVector;
	FVector c_Up = FVector::ZeroVector;

	// Actor components for the speaker and the listner
	UStaticMeshComponent* SpeakerComponent = nullptr;
	UStaticMeshComponent* ListenerComponent = nullptr;
	bool b_AreComponentsSet = false;

	void Update3DPosition();
};
