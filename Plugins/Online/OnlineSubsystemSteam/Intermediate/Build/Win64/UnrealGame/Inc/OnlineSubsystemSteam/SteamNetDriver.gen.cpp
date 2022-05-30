// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Classes/SteamNetDriver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSteamNetDriver() {}
// Cross Module References
	ONLINESUBSYSTEMSTEAM_API UClass* Z_Construct_UClass_USteamNetDriver_NoRegister();
	ONLINESUBSYSTEMSTEAM_API UClass* Z_Construct_UClass_USteamNetDriver();
	ONLINESUBSYSTEMUTILS_API UClass* Z_Construct_UClass_UIpNetDriver();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemSteam();
// End Cross Module References
	void USteamNetDriver::StaticRegisterNativesUSteamNetDriver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USteamNetDriver);
	UClass* Z_Construct_UClass_USteamNetDriver_NoRegister()
	{
		return USteamNetDriver::StaticClass();
	}
	struct Z_Construct_UClass_USteamNetDriver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USteamNetDriver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UIpNetDriver,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemSteam,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USteamNetDriver_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SteamNetDriver.h" },
		{ "ModuleRelativePath", "Classes/SteamNetDriver.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USteamNetDriver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USteamNetDriver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USteamNetDriver_Statics::ClassParams = {
		&USteamNetDriver::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000ACu,
		METADATA_PARAMS(Z_Construct_UClass_USteamNetDriver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USteamNetDriver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USteamNetDriver()
	{
		if (!Z_Registration_Info_UClass_USteamNetDriver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USteamNetDriver.OuterSingleton, Z_Construct_UClass_USteamNetDriver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USteamNetDriver.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMSTEAM_API UClass* StaticClass<USteamNetDriver>()
	{
		return USteamNetDriver::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USteamNetDriver);
	struct Z_CompiledInDeferFile_FID_Strapontin_Plugins_Online_OnlineSubsystemSteam_Source_Classes_SteamNetDriver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Strapontin_Plugins_Online_OnlineSubsystemSteam_Source_Classes_SteamNetDriver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USteamNetDriver, USteamNetDriver::StaticClass, TEXT("USteamNetDriver"), &Z_Registration_Info_UClass_USteamNetDriver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USteamNetDriver), 2167908470U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Strapontin_Plugins_Online_OnlineSubsystemSteam_Source_Classes_SteamNetDriver_h_425493749(TEXT("/Script/OnlineSubsystemSteam"),
		Z_CompiledInDeferFile_FID_Strapontin_Plugins_Online_OnlineSubsystemSteam_Source_Classes_SteamNetDriver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Strapontin_Plugins_Online_OnlineSubsystemSteam_Source_Classes_SteamNetDriver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
