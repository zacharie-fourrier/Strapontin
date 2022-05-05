// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeglTFRuntime_init() {}
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeError__DelegateSignature();
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature();
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeOnSkeletalMeshCreated__DelegateSignature();
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeOnStaticMeshCreated__DelegateSignature();
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeSkeletalMeshAsync__DelegateSignature();
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeStaticMeshAsync__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_glTFRuntime;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_glTFRuntime()
	{
		if (!Z_Registration_Info_UPackage__Script_glTFRuntime.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeError__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeOnSkeletalMeshCreated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeOnStaticMeshCreated__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeSkeletalMeshAsync__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeStaticMeshAsync__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/glTFRuntime",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x4E0CD728,
				0x077749FB,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_glTFRuntime.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_glTFRuntime.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_glTFRuntime(Z_Construct_UPackage__Script_glTFRuntime, TEXT("/Script/glTFRuntime"), Z_Registration_Info_UPackage__Script_glTFRuntime, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x4E0CD728, 0x077749FB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
