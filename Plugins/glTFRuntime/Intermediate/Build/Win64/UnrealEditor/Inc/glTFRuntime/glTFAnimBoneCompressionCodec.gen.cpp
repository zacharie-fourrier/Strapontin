// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "glTFRuntime/Public/glTFAnimBoneCompressionCodec.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeglTFAnimBoneCompressionCodec() {}
// Cross Module References
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFAnimBoneCompressionCodec_NoRegister();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFAnimBoneCompressionCodec();
	ENGINE_API UClass* Z_Construct_UClass_UAnimBoneCompressionCodec();
	UPackage* Z_Construct_UPackage__Script_glTFRuntime();
// End Cross Module References
	void UglTFAnimBoneCompressionCodec::StaticRegisterNativesUglTFAnimBoneCompressionCodec()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UglTFAnimBoneCompressionCodec);
	UClass* Z_Construct_UClass_UglTFAnimBoneCompressionCodec_NoRegister()
	{
		return UglTFAnimBoneCompressionCodec::StaticClass();
	}
	struct Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimBoneCompressionCodec,
		(UObject* (*)())Z_Construct_UPackage__Script_glTFRuntime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Object" },
		{ "IncludePath", "glTFAnimBoneCompressionCodec.h" },
		{ "ModuleRelativePath", "Public/glTFAnimBoneCompressionCodec.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UglTFAnimBoneCompressionCodec>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::ClassParams = {
		&UglTFAnimBoneCompressionCodec::StaticClass,
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
		0x001010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UglTFAnimBoneCompressionCodec()
	{
		if (!Z_Registration_Info_UClass_UglTFAnimBoneCompressionCodec.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UglTFAnimBoneCompressionCodec.OuterSingleton, Z_Construct_UClass_UglTFAnimBoneCompressionCodec_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UglTFAnimBoneCompressionCodec.OuterSingleton;
	}
	template<> GLTFRUNTIME_API UClass* StaticClass<UglTFAnimBoneCompressionCodec>()
	{
		return UglTFAnimBoneCompressionCodec::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UglTFAnimBoneCompressionCodec);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFAnimBoneCompressionCodec_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFAnimBoneCompressionCodec_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UglTFAnimBoneCompressionCodec, UglTFAnimBoneCompressionCodec::StaticClass, TEXT("UglTFAnimBoneCompressionCodec"), &Z_Registration_Info_UClass_UglTFAnimBoneCompressionCodec, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UglTFAnimBoneCompressionCodec), 3558723784U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFAnimBoneCompressionCodec_h_3189882207(TEXT("/Script/glTFRuntime"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFAnimBoneCompressionCodec_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFAnimBoneCompressionCodec_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
