// Fill out your copyright notice in the Description page of Project Settings.


#include "VoicePC.h"

#include "VoiceGI.h"

void AVoicePC::ClientJoinVoice_Implementation(const uint8 TeamNumber, ChannelType ChanType, const FSpaceAudioProperties& SpaceProps, const FString& SessionID)
{
	if (!IsPrimaryPlayer())
	{
		return;
	}

	if (IsLocalController())
	{
		if (UVoiceGI* const GI = GetWorld()->GetGameInstance<UVoiceGI>())
		{
#if WITH_VIVOXCORE
			GI->JoinVoiceChannels(TeamNumber, ChanType, this, Channel3DProperties(SpaceProps.AudibleDistance, SpaceProps.ConversationalDistance, SpaceProps.AudioFadeIntensityByDistance, SpaceProps.AudioFadeModel), SessionID);
#endif
		}
	}
}

void AVoicePC::Set3DRefreshRate(float RefreshRate)
{
	if (!IsPrimaryPlayer())
	{
		return;
	}

	// Set Timer3DPosInterval to RefreshRate (0 if its negative)
	Timer3DPosInterval = RefreshRate < 0.0f ? 0.0f : RefreshRate;

	// Check if the timer is running
	if (Timer3DPos.IsValid())
	{
		// If it is, invalidate it then start it again with the new RefreshRate
		Timer3DPos.Invalidate();
		GetWorldTimerManager().SetTimer(Timer3DPos, this, &AVoicePC::Update3DPosition, Timer3DPosInterval, true);

	}
}

void AVoicePC::Set3DVoiceComponents(UStaticMeshComponent* newSpeakerComponent, UStaticMeshComponent* newListenerComponent)
{
	if (!IsPrimaryPlayer())
	{
		return;
	}

	// Set SpeakerComponent and ListenerComponent
	SpeakerComponent = newSpeakerComponent;
	ListenerComponent = newListenerComponent;
	b_AreComponentsSet = true;
}

void AVoicePC::Reset3DVoiceComponents()
{
	if (!IsPrimaryPlayer())
	{
		return;
	}

	// Reset SpeakerComponent and ListenerComponent
	SpeakerComponent = nullptr;
	ListenerComponent = nullptr;
	b_AreComponentsSet = false;
}

void AVoicePC::OnJoinChannel_Implementation(ChannelType ChanType, const FString& ChanName)
{
	// Check that the timer isn't already running
	if (Timer3DPos.IsValid()) {
		// If it is, invalidate it 
		Timer3DPos.Invalidate();
	}

	OnJoinChannel(ChanType, ChanName);

	if (ChanType == ChannelType::Positional) {
		// The channel is positional, so we need to set the position of the player and loop it
		if (IsLocalController()) {
			GetWorldTimerManager().SetTimer(Timer3DPos, this, &AVoicePC::Update3DPosition, Timer3DPosInterval, true);
		}
	}
}

void AVoicePC::Update3DPosition()
{
	// Get the pawn of the player controller
	APawn* character = GetPawn();

	// Check if the character is valid
	if (!character) {
		return;
	}

	// Get the location of the character
	FVector location = character->GetActorLocation();

	// Get the forward vector of the character
	FVector forward = character->GetActorForwardVector();

	// Get the up vector of the character
	FVector up = character->GetActorUpVector();

	// If any of the vectors are different from the cache
	if (location != c_Loc || forward != c_For || up != c_Up) {
		// Update the cache
		c_Loc = location;
		c_For = forward;
		c_Up = up;

		// Update the position of the player
		if (UVoiceGI* const GI = GetWorld()->GetGameInstance<UVoiceGI>())
		{
#if WITH_VIVOXCORE
			// If the 3D components are defined
			if (b_AreComponentsSet) {
				// Update the position of the speaker and listener
				GI->Update3DPosition(SpeakerComponent->GetComponentLocation(), ListenerComponent->GetComponentLocation(), forward, up);
				UE_LOG(LogTemp, Log, TEXT("3D Position Updated: Speaker: %s, Listener: %s"), *SpeakerComponent->GetComponentLocation().ToString(), *ListenerComponent->GetComponentLocation().ToString());
				return;
			}
			GI->Update3DPosition(location, location, forward, up);
			UE_LOG(LogTemp, Log, TEXT("3D Position Updated: %s"), *location.ToString());
			return;
#endif
		}
	}
}
