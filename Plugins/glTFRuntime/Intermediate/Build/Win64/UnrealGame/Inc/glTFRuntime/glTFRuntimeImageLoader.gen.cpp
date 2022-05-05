// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "glTFRuntime/Public/glTFRuntimeImageLoader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeglTFRuntimeImageLoader() {}
// Cross Module References
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeImageLoader_NoRegister();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeImageLoader();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_glTFRuntime();
// End Cross Module References
	void UglTFRuntimeImageLoader::StaticRegisterNativesUglTFRuntimeImageLoader()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UglTFRuntimeImageLoader);
	UClass* Z_Construct_UClass_UglTFRuntimeImageLoader_NoRegister()
	{
		return UglTFRuntimeImageLoader::StaticClass();
	}
	struct Z_Construct_UClass_UglTFRuntimeImageLoader_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_glTFRuntime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "glTFRuntimeImageLoader.h" },
		{ "ModuleRelativePath", "Public/glTFRuntimeImageLoader.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UglTFRuntimeImageLoader>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::ClassParams = {
		&UglTFRuntimeImageLoader::StaticClass,
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
		0x001000A1u,
		METADATA_PARAMS(Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UglTFRuntimeImageLoader()
	{
		if (!Z_Registration_Info_UClass_UglTFRuntimeImageLoader.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UglTFRuntimeImageLoader.OuterSingleton, Z_Construct_UClass_UglTFRuntimeImageLoader_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UglTFRuntimeImageLoader.OuterSingleton;
	}
	template<> GLTFRUNTIME_API UClass* StaticClass<UglTFRuntimeImageLoader>()
	{
		return UglTFRuntimeImageLoader::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UglTFRuntimeImageLoader);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeImageLoader_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeImageLoader_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UglTFRuntimeImageLoader, UglTFRuntimeImageLoader::StaticClass, TEXT("UglTFRuntimeImageLoader"), &Z_Registration_Info_UClass_UglTFRuntimeImageLoader, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UglTFRuntimeImageLoader), 3861450567U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeImageLoader_h_2855591851(TEXT("/Script/glTFRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeImageLoader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeImageLoader_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
