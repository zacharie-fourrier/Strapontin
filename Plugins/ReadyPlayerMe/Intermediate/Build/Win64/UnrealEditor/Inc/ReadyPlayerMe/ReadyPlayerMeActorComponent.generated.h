// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USkeletalMesh;
class UglTFRuntimeAsset;
struct FAvatarMetadata;
#ifdef READYPLAYERME_ReadyPlayerMeActorComponent_generated_h
#error "ReadyPlayerMeActorComponent.generated.h already included, missing '#pragma once' in ReadyPlayerMeActorComponent.h"
#endif
#define READYPLAYERME_ReadyPlayerMeActorComponent_generated_h

#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_SPARSE_DATA
#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSkeletalMeshLoaded); \
	DECLARE_FUNCTION(execOnAssetLoaded); \
	DECLARE_FUNCTION(execOnMetadataReceived); \
	DECLARE_FUNCTION(execLoadNewAvatar); \
	DECLARE_FUNCTION(execRunAvatarSetup);


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSkeletalMeshLoaded); \
	DECLARE_FUNCTION(execOnAssetLoaded); \
	DECLARE_FUNCTION(execOnMetadataReceived); \
	DECLARE_FUNCTION(execLoadNewAvatar); \
	DECLARE_FUNCTION(execRunAvatarSetup);


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReadyPlayerMeActorComponent(); \
	friend struct Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics; \
public: \
	DECLARE_CLASS(UReadyPlayerMeActorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReadyPlayerMe"), NO_API) \
	DECLARE_SERIALIZER(UReadyPlayerMeActorComponent)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUReadyPlayerMeActorComponent(); \
	friend struct Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics; \
public: \
	DECLARE_CLASS(UReadyPlayerMeActorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReadyPlayerMe"), NO_API) \
	DECLARE_SERIALIZER(UReadyPlayerMeActorComponent)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReadyPlayerMeActorComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReadyPlayerMeActorComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReadyPlayerMeActorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReadyPlayerMeActorComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReadyPlayerMeActorComponent(UReadyPlayerMeActorComponent&&); \
	NO_API UReadyPlayerMeActorComponent(const UReadyPlayerMeActorComponent&); \
public:


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReadyPlayerMeActorComponent(UReadyPlayerMeActorComponent&&); \
	NO_API UReadyPlayerMeActorComponent(const UReadyPlayerMeActorComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReadyPlayerMeActorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReadyPlayerMeActorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UReadyPlayerMeActorComponent)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_15_PROLOG
#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_SPARSE_DATA \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_RPC_WRAPPERS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_INCLASS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_SPARSE_DATA \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_INCLASS_NO_PURE_DECLS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> READYPLAYERME_API UClass* StaticClass<class UReadyPlayerMeActorComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeActorComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
