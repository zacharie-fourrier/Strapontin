// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FglTFRuntimeImagesConfig;
class UTexture2D;
struct FglTFRuntimeStaticMeshConfig;
struct FglTFRuntimeAudioEmitter;
class UAudioComponent;
struct FglTFRuntimePathItem;
class UProceduralMeshComponent;
struct FglTFRuntimeProceduralMeshConfig;
class USkeletalMesh;
class UStaticMesh;
struct FglTFRuntimeMaterialsConfig;
class UMaterialInterface;
class UCameraComponent;
class UObject;
class ACameraActor;
class UglTFRuntimeAnimationCurve;
struct FglTFRuntimeSkeletalAnimationConfig;
class UAnimMontage;
class UAnimSequence;
struct FglTFRuntimeSkeletalMeshConfig;
struct FglTFRuntimeSkeletonConfig;
class USkeleton;
struct FglTFRuntimeNode;
struct FglTFRuntimeScene;
#ifdef GLTFRUNTIME_glTFRuntimeAsset_generated_h
#error "glTFRuntimeAsset.generated.h already included, missing '#pragma once' in glTFRuntimeAsset.h"
#endif
#define GLTFRUNTIME_glTFRuntimeAsset_generated_h

#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_SPARSE_DATA
#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetExtensionsRequired); \
	DECLARE_FUNCTION(execGetExtensionsUsed); \
	DECLARE_FUNCTION(execLoadImage); \
	DECLARE_FUNCTION(execLoadStaticMeshLODsAsync); \
	DECLARE_FUNCTION(execLoadStaticMeshAsync); \
	DECLARE_FUNCTION(execLoadEmitterIntoAudioComponent); \
	DECLARE_FUNCTION(execLoadAudioEmitter); \
	DECLARE_FUNCTION(execGetArraySizeFromPath); \
	DECLARE_FUNCTION(execGetBooleanFromPath); \
	DECLARE_FUNCTION(execGetFloatFromPath); \
	DECLARE_FUNCTION(execGetIntegerFromPath); \
	DECLARE_FUNCTION(execGetStringFromPath); \
	DECLARE_FUNCTION(execLoadStaticMeshIntoProceduralMeshComponent); \
	DECLARE_FUNCTION(execOnSkeletalMeshCreatedProxy); \
	DECLARE_FUNCTION(execOnStaticMeshCreatedProxy); \
	DECLARE_FUNCTION(execOnErrorProxy); \
	DECLARE_FUNCTION(execLoadMaterial); \
	DECLARE_FUNCTION(execBuildTransformFromNodeForward); \
	DECLARE_FUNCTION(execBuildTransformFromNodeBackward); \
	DECLARE_FUNCTION(execNodeIsBone); \
	DECLARE_FUNCTION(execLoadCamera); \
	DECLARE_FUNCTION(execGetNumImages); \
	DECLARE_FUNCTION(execGetNumMeshes); \
	DECLARE_FUNCTION(execGetCameraNodesIndices); \
	DECLARE_FUNCTION(execLoadNodeCamera); \
	DECLARE_FUNCTION(execGetCamerasNames); \
	DECLARE_FUNCTION(execLoadAllNodeAnimationCurves); \
	DECLARE_FUNCTION(execLoadNodeAnimationCurve); \
	DECLARE_FUNCTION(execLoadSkeletalAnimationAsMontage); \
	DECLARE_FUNCTION(execLoadNodeSkeletalAnimation); \
	DECLARE_FUNCTION(execLoadSkeletalAnimationByName); \
	DECLARE_FUNCTION(execLoadSkeletalAnimation); \
	DECLARE_FUNCTION(execLoadSkeletalMeshLODs); \
	DECLARE_FUNCTION(execLoadSkeleton); \
	DECLARE_FUNCTION(execLoadSkeletalMeshRecursiveAsync); \
	DECLARE_FUNCTION(execLoadSkeletalMeshRecursive); \
	DECLARE_FUNCTION(execLoadSkeletalMeshAsync); \
	DECLARE_FUNCTION(execLoadSkeletalMesh); \
	DECLARE_FUNCTION(execLoadStaticMeshesFromPrimitives); \
	DECLARE_FUNCTION(execLoadStaticMeshByNodeName); \
	DECLARE_FUNCTION(execLoadStaticMeshByName); \
	DECLARE_FUNCTION(execLoadStaticMeshLODs); \
	DECLARE_FUNCTION(execLoadStaticMesh); \
	DECLARE_FUNCTION(execFindNodeByNameInArray); \
	DECLARE_FUNCTION(execGetNodeByName); \
	DECLARE_FUNCTION(execGetNode); \
	DECLARE_FUNCTION(execGetNodes); \
	DECLARE_FUNCTION(execGetScenes);


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetExtensionsRequired); \
	DECLARE_FUNCTION(execGetExtensionsUsed); \
	DECLARE_FUNCTION(execLoadImage); \
	DECLARE_FUNCTION(execLoadStaticMeshLODsAsync); \
	DECLARE_FUNCTION(execLoadStaticMeshAsync); \
	DECLARE_FUNCTION(execLoadEmitterIntoAudioComponent); \
	DECLARE_FUNCTION(execLoadAudioEmitter); \
	DECLARE_FUNCTION(execGetArraySizeFromPath); \
	DECLARE_FUNCTION(execGetBooleanFromPath); \
	DECLARE_FUNCTION(execGetFloatFromPath); \
	DECLARE_FUNCTION(execGetIntegerFromPath); \
	DECLARE_FUNCTION(execGetStringFromPath); \
	DECLARE_FUNCTION(execLoadStaticMeshIntoProceduralMeshComponent); \
	DECLARE_FUNCTION(execOnSkeletalMeshCreatedProxy); \
	DECLARE_FUNCTION(execOnStaticMeshCreatedProxy); \
	DECLARE_FUNCTION(execOnErrorProxy); \
	DECLARE_FUNCTION(execLoadMaterial); \
	DECLARE_FUNCTION(execBuildTransformFromNodeForward); \
	DECLARE_FUNCTION(execBuildTransformFromNodeBackward); \
	DECLARE_FUNCTION(execNodeIsBone); \
	DECLARE_FUNCTION(execLoadCamera); \
	DECLARE_FUNCTION(execGetNumImages); \
	DECLARE_FUNCTION(execGetNumMeshes); \
	DECLARE_FUNCTION(execGetCameraNodesIndices); \
	DECLARE_FUNCTION(execLoadNodeCamera); \
	DECLARE_FUNCTION(execGetCamerasNames); \
	DECLARE_FUNCTION(execLoadAllNodeAnimationCurves); \
	DECLARE_FUNCTION(execLoadNodeAnimationCurve); \
	DECLARE_FUNCTION(execLoadSkeletalAnimationAsMontage); \
	DECLARE_FUNCTION(execLoadNodeSkeletalAnimation); \
	DECLARE_FUNCTION(execLoadSkeletalAnimationByName); \
	DECLARE_FUNCTION(execLoadSkeletalAnimation); \
	DECLARE_FUNCTION(execLoadSkeletalMeshLODs); \
	DECLARE_FUNCTION(execLoadSkeleton); \
	DECLARE_FUNCTION(execLoadSkeletalMeshRecursiveAsync); \
	DECLARE_FUNCTION(execLoadSkeletalMeshRecursive); \
	DECLARE_FUNCTION(execLoadSkeletalMeshAsync); \
	DECLARE_FUNCTION(execLoadSkeletalMesh); \
	DECLARE_FUNCTION(execLoadStaticMeshesFromPrimitives); \
	DECLARE_FUNCTION(execLoadStaticMeshByNodeName); \
	DECLARE_FUNCTION(execLoadStaticMeshByName); \
	DECLARE_FUNCTION(execLoadStaticMeshLODs); \
	DECLARE_FUNCTION(execLoadStaticMesh); \
	DECLARE_FUNCTION(execFindNodeByNameInArray); \
	DECLARE_FUNCTION(execGetNodeByName); \
	DECLARE_FUNCTION(execGetNode); \
	DECLARE_FUNCTION(execGetNodes); \
	DECLARE_FUNCTION(execGetScenes);


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUglTFRuntimeAsset(); \
	friend struct Z_Construct_UClass_UglTFRuntimeAsset_Statics; \
public: \
	DECLARE_CLASS(UglTFRuntimeAsset, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/glTFRuntime"), NO_API) \
	DECLARE_SERIALIZER(UglTFRuntimeAsset)


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUglTFRuntimeAsset(); \
	friend struct Z_Construct_UClass_UglTFRuntimeAsset_Statics; \
public: \
	DECLARE_CLASS(UglTFRuntimeAsset, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/glTFRuntime"), NO_API) \
	DECLARE_SERIALIZER(UglTFRuntimeAsset)


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UglTFRuntimeAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UglTFRuntimeAsset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UglTFRuntimeAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UglTFRuntimeAsset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UglTFRuntimeAsset(UglTFRuntimeAsset&&); \
	NO_API UglTFRuntimeAsset(const UglTFRuntimeAsset&); \
public:


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UglTFRuntimeAsset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UglTFRuntimeAsset(UglTFRuntimeAsset&&); \
	NO_API UglTFRuntimeAsset(const UglTFRuntimeAsset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UglTFRuntimeAsset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UglTFRuntimeAsset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UglTFRuntimeAsset)


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_15_PROLOG
#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_SPARSE_DATA \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_RPC_WRAPPERS \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_INCLASS \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_SPARSE_DATA \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GLTFRUNTIME_API UClass* StaticClass<class UglTFRuntimeAsset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeAsset_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
