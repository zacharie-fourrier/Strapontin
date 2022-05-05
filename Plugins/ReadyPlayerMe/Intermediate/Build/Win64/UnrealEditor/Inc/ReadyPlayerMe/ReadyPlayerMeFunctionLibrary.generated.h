// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USkeletalMeshComponent;
 
class UglTFRuntimeAsset;
struct FglTFRuntimeConfig;
struct FAvatarMetadata;
class USkeleton;
struct FglTFRuntimeSkeletalMeshConfig;
struct FglTFRuntimeMaterialsConfig;
struct FglTFRuntimeSkeletonConfig;
class AActor;
class USkeletalMesh;
#ifdef READYPLAYERME_ReadyPlayerMeFunctionLibrary_generated_h
#error "ReadyPlayerMeFunctionLibrary.generated.h already included, missing '#pragma once' in ReadyPlayerMeFunctionLibrary.h"
#endif
#define READYPLAYERME_ReadyPlayerMeFunctionLibrary_generated_h

#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_SPARSE_DATA
#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetMorphTarget); \
	DECLARE_FUNCTION(execSetMorphTargets); \
	DECLARE_FUNCTION(execLoadAvatarMetadata); \
	DECLARE_FUNCTION(execGetBodyTypeFromAsset); \
	DECLARE_FUNCTION(execGetRootBoneName); \
	DECLARE_FUNCTION(execGetglTFRuntimeConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeSkeletalMeshConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeMaterialsConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeSkeletonConfig); \
	DECLARE_FUNCTION(execIsUrl); \
	DECLARE_FUNCTION(execGetUrlFromShortcode); \
	DECLARE_FUNCTION(execGetValidatedUrlShortCode); \
	DECLARE_FUNCTION(execSetupSkeletalMeshComponent); \
	DECLARE_FUNCTION(execAddSkeletalMeshComponent);


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetMorphTarget); \
	DECLARE_FUNCTION(execSetMorphTargets); \
	DECLARE_FUNCTION(execLoadAvatarMetadata); \
	DECLARE_FUNCTION(execGetBodyTypeFromAsset); \
	DECLARE_FUNCTION(execGetRootBoneName); \
	DECLARE_FUNCTION(execGetglTFRuntimeConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeSkeletalMeshConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeMaterialsConfig); \
	DECLARE_FUNCTION(execGetglTFRuntimeSkeletonConfig); \
	DECLARE_FUNCTION(execIsUrl); \
	DECLARE_FUNCTION(execGetUrlFromShortcode); \
	DECLARE_FUNCTION(execGetValidatedUrlShortCode); \
	DECLARE_FUNCTION(execSetupSkeletalMeshComponent); \
	DECLARE_FUNCTION(execAddSkeletalMeshComponent);


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUReadyPlayerMeFunctionLibrary(); \
	friend struct Z_Construct_UClass_UReadyPlayerMeFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UReadyPlayerMeFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReadyPlayerMe"), NO_API) \
	DECLARE_SERIALIZER(UReadyPlayerMeFunctionLibrary)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUReadyPlayerMeFunctionLibrary(); \
	friend struct Z_Construct_UClass_UReadyPlayerMeFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UReadyPlayerMeFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReadyPlayerMe"), NO_API) \
	DECLARE_SERIALIZER(UReadyPlayerMeFunctionLibrary)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReadyPlayerMeFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReadyPlayerMeFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReadyPlayerMeFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReadyPlayerMeFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReadyPlayerMeFunctionLibrary(UReadyPlayerMeFunctionLibrary&&); \
	NO_API UReadyPlayerMeFunctionLibrary(const UReadyPlayerMeFunctionLibrary&); \
public:


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UReadyPlayerMeFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UReadyPlayerMeFunctionLibrary(UReadyPlayerMeFunctionLibrary&&); \
	NO_API UReadyPlayerMeFunctionLibrary(const UReadyPlayerMeFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UReadyPlayerMeFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UReadyPlayerMeFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UReadyPlayerMeFunctionLibrary)


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_12_PROLOG
#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_SPARSE_DATA \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_RPC_WRAPPERS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_INCLASS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_SPARSE_DATA \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
	FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> READYPLAYERME_API UClass* StaticClass<class UReadyPlayerMeFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
