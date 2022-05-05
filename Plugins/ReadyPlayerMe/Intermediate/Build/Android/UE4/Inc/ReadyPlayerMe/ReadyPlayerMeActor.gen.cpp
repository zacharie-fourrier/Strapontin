// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReadyPlayerMe/Public/ReadyPlayerMeActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReadyPlayerMeActor() {}
// Cross Module References
	READYPLAYERME_API UClass* Z_Construct_UClass_AReadyPlayerMeActor_NoRegister();
	READYPLAYERME_API UClass* Z_Construct_UClass_AReadyPlayerMeActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ReadyPlayerMe();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	READYPLAYERME_API UClass* Z_Construct_UClass_UReadyPlayerMeActorComponent_NoRegister();
// End Cross Module References
	void AReadyPlayerMeActor::StaticRegisterNativesAReadyPlayerMeActor()
	{
	}
	UClass* Z_Construct_UClass_AReadyPlayerMeActor_NoRegister()
	{
		return AReadyPlayerMeActor::StaticClass();
	}
	struct Z_Construct_UClass_AReadyPlayerMeActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SkeletalMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SkeletalMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReadyPlayerMeComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReadyPlayerMeComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AReadyPlayerMeActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ReadyPlayerMe,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReadyPlayerMeActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ReadyPlayerMeActor.h" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_SkeletalMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ReadyPlayerMe" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Ready Player Me" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_SkeletalMeshComponent = { "SkeletalMeshComponent", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AReadyPlayerMeActor, SkeletalMeshComponent), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_SkeletalMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_SkeletalMeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_ReadyPlayerMeComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "ReadyPlayerMe" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Ready Player Me" },
		{ "ModuleRelativePath", "Public/ReadyPlayerMeActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_ReadyPlayerMeComponent = { "ReadyPlayerMeComponent", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AReadyPlayerMeActor, ReadyPlayerMeComponent), Z_Construct_UClass_UReadyPlayerMeActorComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_ReadyPlayerMeComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_ReadyPlayerMeComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AReadyPlayerMeActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_SkeletalMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReadyPlayerMeActor_Statics::NewProp_ReadyPlayerMeComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AReadyPlayerMeActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReadyPlayerMeActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AReadyPlayerMeActor_Statics::ClassParams = {
		&AReadyPlayerMeActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AReadyPlayerMeActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AReadyPlayerMeActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AReadyPlayerMeActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AReadyPlayerMeActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AReadyPlayerMeActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReadyPlayerMeActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AReadyPlayerMeActor, 3704906716);
	template<> READYPLAYERME_API UClass* StaticClass<AReadyPlayerMeActor>()
	{
		return AReadyPlayerMeActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AReadyPlayerMeActor(Z_Construct_UClass_AReadyPlayerMeActor, &AReadyPlayerMeActor::StaticClass, TEXT("/Script/ReadyPlayerMe"), TEXT("AReadyPlayerMeActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AReadyPlayerMeActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
