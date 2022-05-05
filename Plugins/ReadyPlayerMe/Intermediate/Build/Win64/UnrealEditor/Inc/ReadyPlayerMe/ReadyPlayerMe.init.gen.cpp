// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReadyPlayerMe_init() {}
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature();
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ReadyPlayerMe;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ReadyPlayerMe()
	{
		if (!Z_Registration_Info_UPackage__Script_ReadyPlayerMe.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ReadyPlayerMe",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xFF3547CE,
				0x8E17A927,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ReadyPlayerMe.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ReadyPlayerMe.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ReadyPlayerMe(Z_Construct_UPackage__Script_ReadyPlayerMe, TEXT("/Script/ReadyPlayerMe"), Z_Registration_Info_UPackage__Script_ReadyPlayerMe, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xFF3547CE, 0x8E17A927));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
