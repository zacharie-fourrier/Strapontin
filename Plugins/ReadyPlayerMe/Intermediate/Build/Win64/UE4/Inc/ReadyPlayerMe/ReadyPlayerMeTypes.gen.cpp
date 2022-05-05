// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReadyPlayerMe/Public/ReadyPlayerMeTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReadyPlayerMeTypes() {}
// Cross Module References
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ReadyPlayerMe();
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature();
	READYPLAYERME_API UScriptStruct* Z_Construct_UScriptStruct_FAvatarMetadata();
	READYPLAYERME_API UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType();
	READYPLAYERME_API UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarGender();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics
	{
		struct _Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms
		{
			FString errorMessage;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_errorMessage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_errorMessage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage = { "errorMessage", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms, errorMessage), METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::NewProp_errorMessage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe, nullptr, "AvatarLoadFailed__DelegateSignature", nullptr, nullptr, sizeof(_Script_ReadyPlayerMe_eventAvatarLoadFailed_Parms), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics
	{
		struct _Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms
		{
			FAvatarMetadata AvataMetadata;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AvataMetadata_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AvataMetadata;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata = { "AvataMetadata", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms, AvataMetadata), Z_Construct_UScriptStruct_FAvatarMetadata, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::NewProp_AvataMetadata,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe, nullptr, "AvatarMetadataHttpResponse__DelegateSignature", nullptr, nullptr, sizeof(_Script_ReadyPlayerMe_eventAvatarMetadataHttpResponse_Parms), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarMetadataHttpResponse__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* AvatarBodyType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarBodyType"));
		}
		return Singleton;
	}
	template<> READYPLAYERME_API UEnum* StaticEnum<AvatarBodyType>()
	{
		return AvatarBodyType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_AvatarBodyType(AvatarBodyType_StaticEnum, TEXT("/Script/ReadyPlayerMe"), TEXT("AvatarBodyType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Hash() { return 548077496U; }
	UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ReadyPlayerMe();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("AvatarBodyType"), 0, Get_Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Undefined", (int64)Undefined },
				{ "Fullbody", (int64)Fullbody },
				{ "Halfbody", (int64)Halfbody },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
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
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
				nullptr,
				"AvatarBodyType",
				"AvatarBodyType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* AvatarGender_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ReadyPlayerMe_AvatarGender, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarGender"));
		}
		return Singleton;
	}
	template<> READYPLAYERME_API UEnum* StaticEnum<AvatarGender>()
	{
		return AvatarGender_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_AvatarGender(AvatarGender_StaticEnum, TEXT("/Script/ReadyPlayerMe"), TEXT("AvatarGender"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Hash() { return 939002995U; }
	UEnum* Z_Construct_UEnum_ReadyPlayerMe_AvatarGender()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ReadyPlayerMe();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("AvatarGender"), 0, Get_Z_Construct_UEnum_ReadyPlayerMe_AvatarGender_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Masculine", (int64)Masculine },
				{ "Feminine", (int64)Feminine },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Feminine.DisplayName", "GENDER_FEMININE" },
				{ "Feminine.Name", "Feminine" },
				{ "Masculine.DisplayName", "GENDER_MASCULINE" },
				{ "Masculine.Name", "Masculine" },
				{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
				nullptr,
				"AvatarGender",
				"AvatarGender",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FAvatarMetadata::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern READYPLAYERME_API uint32 Get_Z_Construct_UScriptStruct_FAvatarMetadata_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAvatarMetadata, Z_Construct_UPackage__Script_ReadyPlayerMe(), TEXT("AvatarMetadata"), sizeof(FAvatarMetadata), Get_Z_Construct_UScriptStruct_FAvatarMetadata_Hash());
	}
	return Singleton;
}
template<> READYPLAYERME_API UScriptStruct* StaticStruct<FAvatarMetadata>()
{
	return FAvatarMetadata::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAvatarMetadata(FAvatarMetadata::StaticStruct, TEXT("/Script/ReadyPlayerMe"), TEXT("AvatarMetadata"), false, nullptr, nullptr);
static struct FScriptStruct_ReadyPlayerMe_StaticRegisterNativesFAvatarMetadata
{
	FScriptStruct_ReadyPlayerMe_StaticRegisterNativesFAvatarMetadata()
	{
		UScriptStruct::DeferCppStructOps<FAvatarMetadata>(FName(TEXT("AvatarMetadata")));
	}
} ScriptStruct_ReadyPlayerMe_StaticRegisterNativesFAvatarMetadata;
	struct Z_Construct_UScriptStruct_FAvatarMetadata_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bodyType_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_bodyType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_outfitGender_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_outfitGender;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_outfitVersion_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_outfitVersion;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAvatarMetadata>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType = { "bodyType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, bodyType), Z_Construct_UEnum_ReadyPlayerMe_AvatarBodyType, METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender = { "outfitGender", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, outfitGender), Z_Construct_UEnum_ReadyPlayerMe_AvatarGender, METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData[] = {
		{ "Category", "ReadyPlayerMe" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeTypes.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion = { "outfitVersion", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAvatarMetadata, outfitVersion), METADATA_PARAMS(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAvatarMetadata_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_bodyType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitGender,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAvatarMetadata_Statics::NewProp_outfitVersion,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAvatarMetadata_Statics::ReturnStructParams = {
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
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAvatarMetadata_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ReadyPlayerMe();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AvatarMetadata"), sizeof(FAvatarMetadata), Get_Z_Construct_UScriptStruct_FAvatarMetadata_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAvatarMetadata_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAvatarMetadata_Hash() { return 3188100586U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
