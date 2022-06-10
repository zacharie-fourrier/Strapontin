// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FAvatarMetadata;
#ifdef READYPLAYERME_ReadyPlayerMeTypes_generated_h
#error "ReadyPlayerMeTypes.generated.h already included, missing '#pragma once' in ReadyPlayerMeTypes.h"
#endif
#define READYPLAYERME_ReadyPlayerMeTypes_generated_h

#define FID_Projet_unreal_engine_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_25_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAvatarMetadata_Statics; \
	READYPLAYERME_API static class UScriptStruct* StaticStruct();


template<> READYPLAYERME_API UScriptStruct* StaticStruct<struct FAvatarMetadata>();

#define FID_Projet_unreal_engine_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_42_DELEGATE \
struct _Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms \
{ \
	FAvatarMetadata AvataMetadata; \
}; \
static inline void FAvatarMetadataHttpResponse_DelegateWrapper(const FScriptDelegate& AvatarMetadataHttpResponse, FAvatarMetadata const& AvataMetadata) \
{ \
	_Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms Parms; \
	Parms.AvataMetadata=AvataMetadata; \
	AvatarMetadataHttpResponse.ProcessDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_44_DELEGATE \
struct _Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms \
{ \
	FString errorMessage; \
}; \
static inline void FAvatarLoadFailed_DelegateWrapper(const FScriptDelegate& AvatarLoadFailed, const FString& errorMessage) \
{ \
	_Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms Parms; \
	Parms.errorMessage=errorMessage; \
	AvatarLoadFailed.ProcessDelegate<UObject>(&Parms); \
}


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projet_unreal_engine_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h


#define FOREACH_ENUM_AVATARGENDER(op) \
	op(Masculine) \
	op(Feminine) 
#define FOREACH_ENUM_AVATARBODYTYPE(op) \
	op(Undefined) \
	op(Fullbody) \
	op(Halfbody) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
