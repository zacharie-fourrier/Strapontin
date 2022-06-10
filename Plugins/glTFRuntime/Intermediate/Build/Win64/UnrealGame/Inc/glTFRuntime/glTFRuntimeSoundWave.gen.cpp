// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "glTFRuntime/Public/glTFRuntimeSoundWave.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeglTFRuntimeSoundWave() {}
// Cross Module References
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeSoundWave_NoRegister();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeSoundWave();
	ENGINE_API UClass* Z_Construct_UClass_USoundWave();
	UPackage* Z_Construct_UPackage__Script_glTFRuntime();
// End Cross Module References
	void UglTFRuntimeSoundWave::StaticRegisterNativesUglTFRuntimeSoundWave()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UglTFRuntimeSoundWave);
	UClass* Z_Construct_UClass_UglTFRuntimeSoundWave_NoRegister()
	{
		return UglTFRuntimeSoundWave::StaticClass();
	}
	struct Z_Construct_UClass_UglTFRuntimeSoundWave_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USoundWave,
		(UObject* (*)())Z_Construct_UPackage__Script_glTFRuntime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object Object" },
		{ "IncludePath", "glTFRuntimeSoundWave.h" },
		{ "ModuleRelativePath", "Public/glTFRuntimeSoundWave.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UglTFRuntimeSoundWave>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::ClassParams = {
		&UglTFRuntimeSoundWave::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UglTFRuntimeSoundWave()
	{
		if (!Z_Registration_Info_UClass_UglTFRuntimeSoundWave.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UglTFRuntimeSoundWave.OuterSingleton, Z_Construct_UClass_UglTFRuntimeSoundWave_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UglTFRuntimeSoundWave.OuterSingleton;
	}
	template<> GLTFRUNTIME_API UClass* StaticClass<UglTFRuntimeSoundWave>()
	{
		return UglTFRuntimeSoundWave::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UglTFRuntimeSoundWave);
	struct Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeSoundWave_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeSoundWave_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UglTFRuntimeSoundWave, UglTFRuntimeSoundWave::StaticClass, TEXT("UglTFRuntimeSoundWave"), &Z_Registration_Info_UClass_UglTFRuntimeSoundWave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UglTFRuntimeSoundWave), 1773451554U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeSoundWave_h_1878440296(TEXT("/Script/glTFRuntime"),
		Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeSoundWave_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeSoundWave_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
