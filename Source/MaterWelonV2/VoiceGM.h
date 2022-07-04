// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#if WITH_VIVOXCORE
#include "VivoxCore.h"
#endif

#include "VoiceGM.generated.h"


UCLASS()
class MATERWELONV2_API AVoiceGM : public AGameMode
{
	GENERATED_BODY()
		
public:
	AVoiceGM();

private:
	FString m_VivoxServerGuid;
};
