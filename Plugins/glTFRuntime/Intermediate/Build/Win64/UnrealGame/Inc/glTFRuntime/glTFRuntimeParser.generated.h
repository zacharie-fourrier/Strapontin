// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UStaticMesh;
class USkeletalMesh;
#ifdef GLTFRUNTIME_glTFRuntimeParser_generated_h
#error "glTFRuntimeParser.generated.h already included, missing '#pragma once' in glTFRuntimeParser.h"
#endif
#define GLTFRUNTIME_glTFRuntimeParser_generated_h

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_22_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeError_Parms \
{ \
	FString ErrorContext; \
	FString ErrorMessage; \
}; \
static inline void FglTFRuntimeError_DelegateWrapper(const FMulticastScriptDelegate& glTFRuntimeError, const FString& ErrorContext, const FString& ErrorMessage) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeError_Parms Parms; \
	Parms.ErrorContext=ErrorContext; \
	Parms.ErrorMessage=ErrorMessage; \
	glTFRuntimeError.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_24_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeOnStaticMeshCreated_Parms \
{ \
	UStaticMesh* StaticMesh; \
}; \
static inline void FglTFRuntimeOnStaticMeshCreated_DelegateWrapper(const FMulticastScriptDelegate& glTFRuntimeOnStaticMeshCreated, UStaticMesh* StaticMesh) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeOnStaticMeshCreated_Parms Parms; \
	Parms.StaticMesh=StaticMesh; \
	glTFRuntimeOnStaticMeshCreated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_25_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeOnSkeletalMeshCreated_Parms \
{ \
	USkeletalMesh* SkeletalMesh; \
}; \
static inline void FglTFRuntimeOnSkeletalMeshCreated_DelegateWrapper(const FMulticastScriptDelegate& glTFRuntimeOnSkeletalMeshCreated, USkeletalMesh* SkeletalMesh) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeOnSkeletalMeshCreated_Parms Parms; \
	Parms.SkeletalMesh=SkeletalMesh; \
	glTFRuntimeOnSkeletalMeshCreated.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_66_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeBasisMatrix_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeBasisMatrix>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_89_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_179_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeScene_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeScene>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_198_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeNode_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeNode>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_268_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeSocket_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeSocket>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_280_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeBone_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeBone>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_295_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeMorphTarget_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeMorphTarget>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_310_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeImagesConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeImagesConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_336_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeMaterialsConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeMaterialsConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_391_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeStaticMeshConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeStaticMeshConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_459_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeProceduralMeshConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeProceduralMeshConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_494_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeSkeletonConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeSkeletonConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_540_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeCapsule_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeCapsule>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_566_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimePhysicsBody_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimePhysicsBody>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_591_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeSkeletalMeshConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeSkeletalMeshConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_679_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeSkeletalAnimationConfig_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeSkeletalAnimationConfig>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_772_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeLOD_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeLOD>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_1000_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimePathItem_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimePathItem>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_1033_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FglTFRuntimeAudioEmitter_Statics; \
	GLTFRUNTIME_API static class UScriptStruct* StaticStruct();


template<> GLTFRUNTIME_API UScriptStruct* StaticStruct<struct FglTFRuntimeAudioEmitter>();

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_1051_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeStaticMeshAsync_Parms \
{ \
	UStaticMesh* StaticMesh; \
}; \
static inline void FglTFRuntimeStaticMeshAsync_DelegateWrapper(const FScriptDelegate& glTFRuntimeStaticMeshAsync, UStaticMesh* StaticMesh) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeStaticMeshAsync_Parms Parms; \
	Parms.StaticMesh=StaticMesh; \
	glTFRuntimeStaticMeshAsync.ProcessDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h_1052_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeSkeletalMeshAsync_Parms \
{ \
	USkeletalMesh* SkeletalMesh; \
}; \
static inline void FglTFRuntimeSkeletalMeshAsync_DelegateWrapper(const FScriptDelegate& glTFRuntimeSkeletalMeshAsync, USkeletalMesh* SkeletalMesh) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeSkeletalMeshAsync_Parms Parms; \
	Parms.SkeletalMesh=SkeletalMesh; \
	glTFRuntimeSkeletalMeshAsync.ProcessDelegate<UObject>(&Parms); \
}


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeParser_h


#define FOREACH_ENUM_EGLTFRUNTIMETRANSFORMBASETYPE(op) \
	op(EglTFRuntimeTransformBaseType::Default) \
	op(EglTFRuntimeTransformBaseType::Matrix) \
	op(EglTFRuntimeTransformBaseType::Transform) \
	op(EglTFRuntimeTransformBaseType::YForward) \
	op(EglTFRuntimeTransformBaseType::BasisMatrix) \
	op(EglTFRuntimeTransformBaseType::Identity) 

enum class EglTFRuntimeTransformBaseType : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeTransformBaseType>();

#define FOREACH_ENUM_EGLTFRUNTIMENORMALSGENERATIONSTRATEGY(op) \
	op(EglTFRuntimeNormalsGenerationStrategy::IfMissing) \
	op(EglTFRuntimeNormalsGenerationStrategy::Never) \
	op(EglTFRuntimeNormalsGenerationStrategy::Always) 

enum class EglTFRuntimeNormalsGenerationStrategy : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeNormalsGenerationStrategy>();

#define FOREACH_ENUM_EGLTFRUNTIMETANGENTSGENERATIONSTRATEGY(op) \
	op(EglTFRuntimeTangentsGenerationStrategy::IfMissing) \
	op(EglTFRuntimeTangentsGenerationStrategy::Never) \
	op(EglTFRuntimeTangentsGenerationStrategy::Always) 

enum class EglTFRuntimeTangentsGenerationStrategy : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeTangentsGenerationStrategy>();

#define FOREACH_ENUM_EGLTFRUNTIMEMORPHTARGETSDUPLICATESTRATEGY(op) \
	op(EglTFRuntimeMorphTargetsDuplicateStrategy::Ignore) \
	op(EglTFRuntimeMorphTargetsDuplicateStrategy::Merge) \
	op(EglTFRuntimeMorphTargetsDuplicateStrategy::AppendMorphIndex) \
	op(EglTFRuntimeMorphTargetsDuplicateStrategy::AppendDuplicateCounter) 

enum class EglTFRuntimeMorphTargetsDuplicateStrategy : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeMorphTargetsDuplicateStrategy>();

#define FOREACH_ENUM_EGLTFRUNTIMEMATERIALTYPE(op) \
	op(EglTFRuntimeMaterialType::Opaque) \
	op(EglTFRuntimeMaterialType::Translucent) \
	op(EglTFRuntimeMaterialType::TwoSided) \
	op(EglTFRuntimeMaterialType::TwoSidedTranslucent) 

enum class EglTFRuntimeMaterialType : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeMaterialType>();

#define FOREACH_ENUM_EGLTFRUNTIMECACHEMODE(op) \
	op(EglTFRuntimeCacheMode::ReadWrite) \
	op(EglTFRuntimeCacheMode::None) \
	op(EglTFRuntimeCacheMode::Read) \
	op(EglTFRuntimeCacheMode::Write) 

enum class EglTFRuntimeCacheMode : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimeCacheMode>();

#define FOREACH_ENUM_EGLTFRUNTIMEPIVOTPOSITION(op) \
	op(EglTFRuntimePivotPosition::Asset) \
	op(EglTFRuntimePivotPosition::Center) \
	op(EglTFRuntimePivotPosition::Top) \
	op(EglTFRuntimePivotPosition::Bottom) 

enum class EglTFRuntimePivotPosition : uint8;
template<> GLTFRUNTIME_API UEnum* StaticEnum<EglTFRuntimePivotPosition>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
