// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReadyPlayerMe/Public/ReadyPlayerMeTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReadyPlayerMeTypes() {}
// Cross Module References
	READYPLAYERME_API UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarGender();
	UPackage* Z_Construct_UPackage__Script_ReadyPlayerMe();
	READYPLAYERME_API UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType();
	READYPLAYERME_API UScriptStruct* Z_Construct_UScriptStruct_FAvatarMetadata();
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature();
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_AvatarGender;
	static UEnum* AvatarGender_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_AvatarGender.OuterSingleton)
		{
			Z_Registration_Info_UEnum_AvatarGender.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReadyPlayerMe_AvatarGender, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarGender"));
		}
		return Z_Registration_Info_UEnum_AvatarGender.OuterSingleton;
	}
	template<> READYPLAYERME_API UEnum* StaticEnum<AvatarGender>()
	{
		return AvatarGender_StaticEnum();
	}
	struct Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enumerators[] = {
		{ "Masculine", (int64)Masculine },
		{ "Feminine", (int64)Feminine },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Feminine.DisplayName", "GENDER_FEMININE" },
		{ "Feminine.Name", "Feminine" },
		{ "Masculine.DisplayName", "GENDER_MASCULINE" },
		{ "Masculine.Name", "Masculine" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
		nullptr,
		"AvatarGender",
		"AvatarGender",
		Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarGender()
	{
		if (!Z_Registration_Info_UEnum_AvatarGender.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_AvatarGender.InnerSingleton, Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_AvatarGender.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_AvatarBodyType;
	static UEnum* AvatarBodyType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_AvatarBodyType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_AvatarBodyType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarBodyType"));
		}
		return Z_Registration_Info_UEnum_AvatarBodyType.OuterSingleton;
	}
	template<> READYPLAYERME_API UEnum* StaticEnum<AvatarBodyType>()
	{
		return AvatarBodyType_StaticEnum();
	}
	struct Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enumerators[] = {
		{ "Undefined", (int64)Undefined },
		{ "Fullbody", (int64)Fullbody },
		{ "Halfbody", (int64)Halfbody },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Fullbody.DisplayName", "TYPE_FULLBODY" },
		{ "Fullbody.Name", "Fullbody" },
		{ "Halfbody.DisplayName", "TYPE_HALFBODY" },
		{ "Halfbody.Name", "Halfbody" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
		{ "Undefined.DisplayName", "TYPE_UNDEFINED" },
		{ "Undefined.Name", "Undefined" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
		nullptr,
		"AvatarBodyType",
		"AvatarBodyType",
		Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType()
	{
		if (!Z_Registration_Info_UEnum_AvatarBodyType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_AvatarBodyType.InnerSingleton, Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_AvatarBodyType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AvatarMetadata;
class UScriptStruct* FAvatarMetadata::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AvatarMetadata.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AvatarMetadata.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAvatarMetadata, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarMetadata"));
	}
	return Z_Registration_Info_UScriptStruct_AvatarMetadata.OuterSingleton;
}
template<> READYPLAYERME_API UScriptStruct* StaticStruct<FAvatarMetadata>()
{
	return FAvatarMetadata::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAvatarMetadata_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bodyType_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_bodyType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_outfitGender_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_outfitGender;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_outfitVersion_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_outfitVersion;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAvatarMetadata>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType = { "bodyType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, bodyType), Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType, METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData)) }; // 1119318149
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender = { "outfitGender", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, outfitGender), Z_Construct_UEnum_ReadyPlayerMe_AvatarGender, METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData)) }; // 1602813852
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion = { "outfitVersion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, outfitVersion), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAvatarMetadata_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
		nullptr,
		&NewStructOps,
		"AvatarMetadata",
		sizeof(FAvatarMetadata),
		alignof(FAvatarMetadata),
		Z_Construct_UScriptStruct_FAvatarMetadata_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAvatarMetadata()
	{
		if (!Z_Registration_Info_UScriptStruct_AvatarMetadata.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AvatarMetadata.InnerSingleton, Z_Construct_UScriptStruct_FAvatarMetadata_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AvatarMetadata.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics
	{
		struct _Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms
		{
			FAvatarMetadata AvataMetadata;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AvataMetadata_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AvataMetadata;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata = { "AvataMetadata", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms, AvataMetadata), Z_Construct_UScriptStruct_FAvatarMetadata, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData)) }; // 2044767001
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe, nullptr, "AvatarMetadataHttpResponse__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::_Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics
	{
		struct _Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms
		{
			FString errorMessage;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_errorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_errorMessage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage = { "errorMessage", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms, errorMessage), METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe, nullptr, "AvatarLoadFailed__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::_Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::EnumInfo[] = {
		{ AvatarGender_StaticEnum, TEXT("AvatarGender"), &Z_Registration_Info_UEnum_AvatarGender, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1602813852U) },
		{ AvatarBodyType_StaticEnum, TEXT("AvatarBodyType"), &Z_Registration_Info_UEnum_AvatarBodyType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1119318149U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::ScriptStructInfo[] = {
		{ FAvatarMetadata::StaticStruct, Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewStructOps, TEXT("AvatarMetadata"), &Z_Registration_Info_UScriptStruct_AvatarMetadata, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAvatarMetadata), 2044767001U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_2637756132(TEXT("/Script/ReadyPlayerMe"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_TestReadyPlayerMe_Plugins_ReadyPlayerMe_Source_ReadyPlayerMe_Public_ReadyPlayerMeTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
