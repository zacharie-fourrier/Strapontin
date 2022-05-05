// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReadyPlayerMe/Public/ReadyPlayerMeActorComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReadyPlayerMeActorComponent() {}
// Cross Module References
	READYPLAYERME_API UClass* Z_Construct_UClass_UReadyPlayerMeActorComponent_NoRegister();
	READYPLAYERME_API UClass* Z_Construct_UClass_UReadyPlayerMeActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ReadyPlayerMe();
	READYPLAYERME_API UFunction* Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature();
	GLTFRUNTIME_API UClass* Z_Construct_UClass_UglTFRuntimeAsset_NoRegister();
	READYPLAYERME_API UScriptStruct* Z_Construct_UScriptStruct_FAvatarMetadata();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeleton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UReadyPlayerMeActorComponent::execOnSkeletalMeshLoaded)
	{
		P_GET_OBJECT(USkeletalMesh,Z_Param_skeletalMesh);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSkeletalMeshLoaded(Z_Param_skeletalMesh);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UReadyPlayerMeActorComponent::execOnAssetLoaded)
	{
		P_GET_OBJECT(UglTFRuntimeAsset,Z_Param_asset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnAssetLoaded(Z_Param_asset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UReadyPlayerMeActorComponent::execOnMetadataReceived)
	{
		P_GET_STRUCT_REF(FAvatarMetadata,Z_Param_Out_metadata);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnMetadataReceived(Z_Param_Out_metadata);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UReadyPlayerMeActorComponent::execLoadNewAvatar)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_url);
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_onLoadFailed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadNewAvatar(Z_Param_url,FAvatarLoadFailed(Z_Param_Out_onLoadFailed));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UReadyPlayerMeActorComponent::execRunAvatarSetup)
	{
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_onSetupFailed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RunAvatarSetup(FAvatarLoadFailed(Z_Param_Out_onSetupFailed));
		P_NATIVE_END;
	}
	void UReadyPlayerMeActorComponent::StaticRegisterNativesUReadyPlayerMeActorComponent()
	{
		UClass* Class = UReadyPlayerMeActorComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadNewAvatar", &UReadyPlayerMeActorComponent::execLoadNewAvatar },
			{ "OnAssetLoaded", &UReadyPlayerMeActorComponent::execOnAssetLoaded },
			{ "OnMetadataReceived", &UReadyPlayerMeActorComponent::execOnMetadataReceived },
			{ "OnSkeletalMeshLoaded", &UReadyPlayerMeActorComponent::execOnSkeletalMeshLoaded },
			{ "RunAvatarSetup", &UReadyPlayerMeActorComponent::execRunAvatarSetup },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics
	{
		struct ReadyPlayerMeActorComponent_eventLoadNewAvatar_Parms
		{
			FString url;
			FScriptDelegate onLoadFailed;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_url;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_onLoadFailed_MetaData[];
#endif
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_onLoadFailed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_url = { "url", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventLoadNewAvatar_Parms, url), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_onLoadFailed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_onLoadFailed = { "onLoadFailed", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventLoadNewAvatar_Parms, onLoadFailed), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_onLoadFailed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_onLoadFailed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_url,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::NewProp_onLoadFailed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "onLoadFailed" },
		{ "Category", "Ready Player Me" },
		{ "DisplayName", "Load New Avatar" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReadyPlayerMeActorComponent, nullptr, "LoadNewAvatar", nullptr, nullptr, sizeof(ReadyPlayerMeActorComponent_eventLoadNewAvatar_Parms), Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics
	{
		struct ReadyPlayerMeActorComponent_eventOnAssetLoaded_Parms
		{
			UglTFRuntimeAsset* asset;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_asset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::NewProp_asset = { "asset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventOnAssetLoaded_Parms, asset), Z_Construct_UClass_UglTFRuntimeAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::NewProp_asset,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReadyPlayerMeActorComponent, nullptr, "OnAssetLoaded", nullptr, nullptr, sizeof(ReadyPlayerMeActorComponent_eventOnAssetLoaded_Parms), Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics
	{
		struct ReadyPlayerMeActorComponent_eventOnMetadataReceived_Parms
		{
			FAvatarMetadata metadata;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_metadata_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_metadata;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::NewProp_metadata_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::NewProp_metadata = { "metadata", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventOnMetadataReceived_Parms, metadata), Z_Construct_UScriptStruct_FAvatarMetadata, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::NewProp_metadata_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::NewProp_metadata_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::NewProp_metadata,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReadyPlayerMeActorComponent, nullptr, "OnMetadataReceived", nullptr, nullptr, sizeof(ReadyPlayerMeActorComponent_eventOnMetadataReceived_Parms), Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics
	{
		struct ReadyPlayerMeActorComponent_eventOnSkeletalMeshLoaded_Parms
		{
			USkeletalMesh* skeletalMesh;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_skeletalMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::NewProp_skeletalMesh = { "skeletalMesh", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventOnSkeletalMeshLoaded_Parms, skeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::NewProp_skeletalMesh,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReadyPlayerMeActorComponent, nullptr, "OnSkeletalMeshLoaded", nullptr, nullptr, sizeof(ReadyPlayerMeActorComponent_eventOnSkeletalMeshLoaded_Parms), Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics
	{
		struct ReadyPlayerMeActorComponent_eventRunAvatarSetup_Parms
		{
			FScriptDelegate onSetupFailed;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_onSetupFailed_MetaData[];
#endif
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_onSetupFailed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::NewProp_onSetupFailed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::NewProp_onSetupFailed = { "onSetupFailed", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ReadyPlayerMeActorComponent_eventRunAvatarSetup_Parms, onSetupFailed), Z_Construct_UDelegateFunction_ReadyPlayerMe_AvatarLoadFailed__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::NewProp_onSetupFailed_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::NewProp_onSetupFailed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::NewProp_onSetupFailed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "onSetupFailed" },
		{ "Category", "Ready Player Me" },
		{ "DisplayName", "Run Avatar Setup" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UReadyPlayerMeActorComponent, nullptr, "RunAvatarSetup", nullptr, nullptr, sizeof(ReadyPlayerMeActorComponent_eventRunAvatarSetup_Parms), Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UReadyPlayerMeActorComponent_NoRegister()
	{
		return UReadyPlayerMeActorComponent::StaticClass();
	}
	struct Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UrlShortcode_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_UrlShortcode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetSkeleton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_targetSkeleton;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UReadyPlayerMeActorComponent_LoadNewAvatar, "LoadNewAvatar" }, // 3796978954
		{ &Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnAssetLoaded, "OnAssetLoaded" }, // 3748546698
		{ &Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnMetadataReceived, "OnMetadataReceived" }, // 3113091248
		{ &Z_Construct_UFunction_UReadyPlayerMeActorComponent_OnSkeletalMeshLoaded, "OnSkeletalMeshLoaded" }, // 1504186754
		{ &Z_Construct_UFunction_UReadyPlayerMeActorComponent_RunAvatarSetup, "RunAvatarSetup" }, // 2201659718
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "ReadyPlayerMeActorComponent.h" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_UrlShortcode_MetaData[] = {
		{ "Category", "Ready Player Me" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_UrlShortcode = { "UrlShortcode", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UReadyPlayerMeActorComponent, UrlShortcode), METADATA_PARAMS(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_UrlShortcode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_UrlShortcode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_targetSkeleton_MetaData[] = {
		{ "Category", "Ready Player Me" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActorComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_targetSkeleton = { "targetSkeleton", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UReadyPlayerMeActorComponent, targetSkeleton), Z_Construct_UClass_USkeleton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_targetSkeleton_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_targetSkeleton_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_UrlShortcode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::NewProp_targetSkeleton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReadyPlayerMeActorComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::ClassParams = {
		&UReadyPlayerMeActorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UReadyPlayerMeActorComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UReadyPlayerMeActorComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UReadyPlayerMeActorComponent, 2043813521);
	template<> READYPLAYERME_API UClass* StaticClass<UReadyPlayerMeActorComponent>()
	{
		return UReadyPlayerMeActorComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UReadyPlayerMeActorComponent(Z_Construct_UClass_UReadyPlayerMeActorComponent, &UReadyPlayerMeActorComponent::StaticClass, TEXT("/Script/ReadyPlayerMe"), TEXT("UReadyPlayerMeActorComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReadyPlayerMeActorComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
