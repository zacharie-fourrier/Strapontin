// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "glTFRuntime/Public/glTFRuntimeFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeglTFRuntimeFunctionLibrary() {}
// Cross Module References
	GLTFRUNTIME_API UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_glTFRuntime();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeAsset_NoRegister();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeFunctionLibrary_NoRegister();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	GLTFRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FglTFRuntimeConfig();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics
	{
		struct _Script_glTFRuntime_eventglTFRuntimeHttpResponse_Parms
		{
			UglTFRuntimeAsset* Asset;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Asset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_glTFRuntime_eventglTFRuntimeHttpResponse_Parms, Asset), Z_Construct_UClass_UglTFRuntimeAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::NewProp_Asset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_glTFRuntime, nullptr, "glTFRuntimeHttpResponse__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::_Script_glTFRuntime_eventglTFRuntimeHttpResponse_Parms), Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromData)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Data);
		P_GET_STRUCT_REF(FglTFRuntimeConfig,Z_Param_Out_LoaderConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UglTFRuntimeAsset**)Z_Param__Result=UglTFRuntimeFunctionLibrary::glTFLoadAssetFromData(Z_Param_Out_Data,Z_Param_Out_LoaderConfig);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromUrl)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Url);
		P_GET_TMAP_REF(FString,FString,Z_Param_Out_Headers);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Completed);
		P_GET_STRUCT_REF(FglTFRuntimeConfig,Z_Param_Out_LoaderConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		UglTFRuntimeFunctionLibrary::glTFLoadAssetFromUrl(Z_Param_Url,Z_Param_Out_Headers,FglTFRuntimeHttpResponse(Z_Param_Completed),Z_Param_Out_LoaderConfig);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_JsonData);
		P_GET_STRUCT_REF(FglTFRuntimeConfig,Z_Param_Out_LoaderConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UglTFRuntimeAsset**)Z_Param__Result=UglTFRuntimeFunctionLibrary::glTFLoadAssetFromString(Z_Param_JsonData,Z_Param_Out_LoaderConfig);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromFilename)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
		P_GET_UBOOL(Z_Param_bPathRelativeToContent);
		P_GET_STRUCT_REF(FglTFRuntimeConfig,Z_Param_Out_LoaderConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UglTFRuntimeAsset**)Z_Param__Result=UglTFRuntimeFunctionLibrary::glTFLoadAssetFromFilename(Z_Param_Filename,Z_Param_bPathRelativeToContent,Z_Param_Out_LoaderConfig);
		P_NATIVE_END;
	}
	void UglTFRuntimeFunctionLibrary::StaticRegisterNativesUglTFRuntimeFunctionLibrary()
	{
		UClass* Class = UglTFRuntimeFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "glTFLoadAssetFromData", &UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromData },
			{ "glTFLoadAssetFromFilename", &UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromFilename },
			{ "glTFLoadAssetFromString", &UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromString },
			{ "glTFLoadAssetFromUrl", &UglTFRuntimeFunctionLibrary::execglTFLoadAssetFromUrl },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics
	{
		struct glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromData_Parms
		{
			TArray<uint8> Data;
			FglTFRuntimeConfig LoaderConfig;
			UglTFRuntimeAsset* ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoaderConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LoaderConfig;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromData_Parms, Data), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_LoaderConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_LoaderConfig = { "LoaderConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromData_Parms, LoaderConfig), Z_Construct_UScriptStruct_FglTFRuntimeConfig, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_LoaderConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_LoaderConfig_MetaData)) }; // 4274980303
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromData_Parms, ReturnValue), Z_Construct_UClass_UglTFRuntimeAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_Data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_LoaderConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "LoaderConfig" },
		{ "Category", "glTFRuntime" },
		{ "DisplayName", "glTF Load Asset from Data" },
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UglTFRuntimeFunctionLibrary, nullptr, "glTFLoadAssetFromData", nullptr, nullptr, sizeof(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromData_Parms), Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics
	{
		struct glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms
		{
			FString Filename;
			bool bPathRelativeToContent;
			FglTFRuntimeConfig LoaderConfig;
			UglTFRuntimeAsset* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPathRelativeToContent_MetaData[];
#endif
		static void NewProp_bPathRelativeToContent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPathRelativeToContent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoaderConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LoaderConfig;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_Filename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms, Filename), METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_Filename_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_Filename_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent_SetBit(void* Obj)
	{
		((glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms*)Obj)->bPathRelativeToContent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent = { "bPathRelativeToContent", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms), &Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent_SetBit, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_LoaderConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_LoaderConfig = { "LoaderConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms, LoaderConfig), Z_Construct_UScriptStruct_FglTFRuntimeConfig, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_LoaderConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_LoaderConfig_MetaData)) }; // 4274980303
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms, ReturnValue), Z_Construct_UClass_UglTFRuntimeAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_Filename,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_bPathRelativeToContent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_LoaderConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "LoaderConfig" },
		{ "Category", "glTFRuntime" },
		{ "DisplayName", "glTF Load Asset from Filename" },
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UglTFRuntimeFunctionLibrary, nullptr, "glTFLoadAssetFromFilename", nullptr, nullptr, sizeof(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromFilename_Parms), Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics
	{
		struct glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromString_Parms
		{
			FString JsonData;
			FglTFRuntimeConfig LoaderConfig;
			UglTFRuntimeAsset* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JsonData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_JsonData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoaderConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LoaderConfig;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_JsonData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_JsonData = { "JsonData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromString_Parms, JsonData), METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_JsonData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_JsonData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_LoaderConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_LoaderConfig = { "LoaderConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromString_Parms, LoaderConfig), Z_Construct_UScriptStruct_FglTFRuntimeConfig, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_LoaderConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_LoaderConfig_MetaData)) }; // 4274980303
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromString_Parms, ReturnValue), Z_Construct_UClass_UglTFRuntimeAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_JsonData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_LoaderConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "LoaderConfig" },
		{ "Category", "glTFRuntime" },
		{ "DisplayName", "glTF Load Asset from String" },
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UglTFRuntimeFunctionLibrary, nullptr, "glTFLoadAssetFromString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromString_Parms), Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics
	{
		struct glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms
		{
			FString Url;
			TMap<FString,FString> Headers;
			FScriptDelegate Completed;
			FglTFRuntimeConfig LoaderConfig;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Url_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Url;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_Headers;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_Completed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoaderConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LoaderConfig;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Url_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Url = { "Url", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms, Url), METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Url_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Url_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers_ValueProp = { "Headers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers_Key_KeyProp = { "Headers_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers = { "Headers", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms, Headers), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Completed = { "Completed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms, Completed), Z_Construct_UDelegateFunction_glTFRuntime_glTFRuntimeHttpResponse__DelegateSignature, METADATA_PARAMS(nullptr, 0) }; // 3591441070
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_LoaderConfig_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_LoaderConfig = { "LoaderConfig", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms, LoaderConfig), Z_Construct_UScriptStruct_FglTFRuntimeConfig, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_LoaderConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_LoaderConfig_MetaData)) }; // 4274980303
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Url,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Headers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_Completed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::NewProp_LoaderConfig,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "LoaderConfig, Headers" },
		{ "Category", "glTFRuntime" },
		{ "DisplayName", "glTF Load Asset from Url" },
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UglTFRuntimeFunctionLibrary, nullptr, "glTFLoadAssetFromUrl", nullptr, nullptr, sizeof(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::glTFRuntimeFunctionLibrary_eventglTFLoadAssetFromUrl_Parms), Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UglTFRuntimeFunctionLibrary);
	UClass* Z_Construct_UClass_UglTFRuntimeFunctionLibrary_NoRegister()
	{
		return UglTFRuntimeFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_glTFRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromData, "glTFLoadAssetFromData" }, // 2109107200
		{ &Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromFilename, "glTFLoadAssetFromFilename" }, // 1092089576
		{ &Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromString, "glTFLoadAssetFromString" }, // 1749429894
		{ &Z_Construct_UFunction_UglTFRuntimeFunctionLibrary_glTFLoadAssetFromUrl, "glTFLoadAssetFromUrl" }, // 2339481662
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "glTFRuntimeFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/glTFRuntimeFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UglTFRuntimeFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::ClassParams = {
		&UglTFRuntimeFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UglTFRuntimeFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UglTFRuntimeFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UglTFRuntimeFunctionLibrary.OuterSingleton, Z_Construct_UClass_UglTFRuntimeFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UglTFRuntimeFunctionLibrary.OuterSingleton;
	}
	template<> GLTFRUNTIME_API UClass* StaticClass<UglTFRuntimeFunctionLibrary>()
	{
		return UglTFRuntimeFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UglTFRuntimeFunctionLibrary);
	struct Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UglTFRuntimeFunctionLibrary, UglTFRuntimeFunctionLibrary::StaticClass, TEXT("UglTFRuntimeFunctionLibrary"), &Z_Registration_Info_UClass_UglTFRuntimeFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UglTFRuntimeFunctionLibrary), 1844720561U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_838191954(TEXT("/Script/glTFRuntime"),
		Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projet_unreal_engine_Plugins_glTFRuntime_Source_glTFRuntime_Public_glTFRuntimeFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
