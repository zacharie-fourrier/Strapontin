// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UglTFRuntimeAsset;
struct FglTFRuntimeConfig;
 
#ifdef GLTFRUNTIME_glTFRuntimeFunctionLibrary_generated_h
#error "glTFRuntimeFunctionLibrary.generated.h already included, missing '#pragma once' in glTFRuntimeFunctionLibrary.h"
#endif
#define GLTFRUNTIME_glTFRuntimeFunctionLibrary_generated_h

#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_10_DELEGATE \
struct _Script_glTFRuntime_eventglTFRuntimeHttpResponse_Parms \
{ \
	UglTFRuntimeAsset* Asset; \
}; \
static inline void FglTFRuntimeHttpResponse_DelegateWrapper(const FScriptDelegate& glTFRuntimeHttpResponse, UglTFRuntimeAsset* Asset) \
{ \
	_Script_glTFRuntime_eventglTFRuntimeHttpResponse_Parms Parms; \
	Parms.Asset=Asset; \
	glTFRuntimeHttpResponse.ProcessDelegate<UObject>(&Parms); \
}


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_SPARSE_DATA
#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execglTFLoadAssetFromData); \
	DECLARE_FUNCTION(execglTFLoadAssetFromUrl); \
	DECLARE_FUNCTION(execglTFLoadAssetFromString); \
	DECLARE_FUNCTION(execglTFLoadAssetFromFilename);


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execglTFLoadAssetFromData); \
	DECLARE_FUNCTION(execglTFLoadAssetFromUrl); \
	DECLARE_FUNCTION(execglTFLoadAssetFromString); \
	DECLARE_FUNCTION(execglTFLoadAssetFromFilename);


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUglTFRuntimeFunctionLibrary(); \
	friend struct Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UglTFRuntimeFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/glTFRuntime"), NO_API) \
	DECLARE_SERIALIZER(UglTFRuntimeFunctionLibrary)


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUglTFRuntimeFunctionLibrary(); \
	friend struct Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UglTFRuntimeFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/glTFRuntime"), NO_API) \
	DECLARE_SERIALIZER(UglTFRuntimeFunctionLibrary)


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UglTFRuntimeFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UglTFRuntimeFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UglTFRuntimeFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UglTFRuntimeFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UglTFRuntimeFunctionLibrary(UglTFRuntimeFunctionLibrary&&); \
	NO_API UglTFRuntimeFunctionLibrary(const UglTFRuntimeFunctionLibrary&); \
public:


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UglTFRuntimeFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UglTFRuntimeFunctionLibrary(UglTFRuntimeFunctionLibrary&&); \
	NO_API UglTFRuntimeFunctionLibrary(const UglTFRuntimeFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UglTFRuntimeFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UglTFRuntimeFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UglTFRuntimeFunctionLibrary)


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_15_PROLOG
#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_SPARSE_DATA \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_RPC_WRAPPERS \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_INCLASS \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_SPARSE_DATA \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_INCLASS_NO_PURE_DECLS \
	FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GLTFRUNTIME_API UClass* StaticClass<class UglTFRuntimeFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
