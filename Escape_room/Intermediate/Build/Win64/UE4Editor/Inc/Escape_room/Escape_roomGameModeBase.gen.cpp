// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Escape_room/Escape_roomGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEscape_roomGameModeBase() {}
// Cross Module References
	ESCAPE_ROOM_API UClass* Z_Construct_UClass_AEscape_roomGameModeBase_NoRegister();
	ESCAPE_ROOM_API UClass* Z_Construct_UClass_AEscape_roomGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Escape_room();
// End Cross Module References
	void AEscape_roomGameModeBase::StaticRegisterNativesAEscape_roomGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AEscape_roomGameModeBase_NoRegister()
	{
		return AEscape_roomGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AEscape_roomGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEscape_roomGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Escape_room,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEscape_roomGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Escape_roomGameModeBase.h" },
		{ "ModuleRelativePath", "Escape_roomGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEscape_roomGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEscape_roomGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEscape_roomGameModeBase_Statics::ClassParams = {
		&AEscape_roomGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEscape_roomGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEscape_roomGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEscape_roomGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEscape_roomGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEscape_roomGameModeBase, 4003735219);
	template<> ESCAPE_ROOM_API UClass* StaticClass<AEscape_roomGameModeBase>()
	{
		return AEscape_roomGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEscape_roomGameModeBase(Z_Construct_UClass_AEscape_roomGameModeBase, &AEscape_roomGameModeBase::StaticClass, TEXT("/Script/Escape_room"), TEXT("AEscape_roomGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEscape_roomGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
