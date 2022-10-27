// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tenth_Tutorial/Public/Tenth_TutorialGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTenth_TutorialGameModeBase() {}
// Cross Module References
	TENTH_TUTORIAL_API UClass* Z_Construct_UClass_ATenth_TutorialGameModeBase_NoRegister();
	TENTH_TUTORIAL_API UClass* Z_Construct_UClass_ATenth_TutorialGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Tenth_Tutorial();
// End Cross Module References
	void ATenth_TutorialGameModeBase::StaticRegisterNativesATenth_TutorialGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ATenth_TutorialGameModeBase_NoRegister()
	{
		return ATenth_TutorialGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Tenth_Tutorial,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Tenth_TutorialGameModeBase.h" },
		{ "ModuleRelativePath", "Public/Tenth_TutorialGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATenth_TutorialGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::ClassParams = {
		&ATenth_TutorialGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATenth_TutorialGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATenth_TutorialGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATenth_TutorialGameModeBase, 1376190922);
	template<> TENTH_TUTORIAL_API UClass* StaticClass<ATenth_TutorialGameModeBase>()
	{
		return ATenth_TutorialGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATenth_TutorialGameModeBase(Z_Construct_UClass_ATenth_TutorialGameModeBase, &ATenth_TutorialGameModeBase::StaticClass, TEXT("/Script/Tenth_Tutorial"), TEXT("ATenth_TutorialGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATenth_TutorialGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
