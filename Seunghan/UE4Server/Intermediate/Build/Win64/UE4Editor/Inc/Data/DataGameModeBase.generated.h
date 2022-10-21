// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DATA_DataGameModeBase_generated_h
#error "DataGameModeBase.generated.h already included, missing '#pragma once' in DataGameModeBase.h"
#endif
#define DATA_DataGameModeBase_generated_h

#define UE4Server_Source_Data_DataGameModeBase_h_29_SPARSE_DATA
#define UE4Server_Source_Data_DataGameModeBase_h_29_RPC_WRAPPERS
#define UE4Server_Source_Data_DataGameModeBase_h_29_RPC_WRAPPERS_NO_PURE_DECLS
#define UE4Server_Source_Data_DataGameModeBase_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADataGameModeBase(); \
	friend struct Z_Construct_UClass_ADataGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ADataGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Data"), NO_API) \
	DECLARE_SERIALIZER(ADataGameModeBase)


#define UE4Server_Source_Data_DataGameModeBase_h_29_INCLASS \
private: \
	static void StaticRegisterNativesADataGameModeBase(); \
	friend struct Z_Construct_UClass_ADataGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ADataGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Data"), NO_API) \
	DECLARE_SERIALIZER(ADataGameModeBase)


#define UE4Server_Source_Data_DataGameModeBase_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADataGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADataGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADataGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADataGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADataGameModeBase(ADataGameModeBase&&); \
	NO_API ADataGameModeBase(const ADataGameModeBase&); \
public:


#define UE4Server_Source_Data_DataGameModeBase_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADataGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADataGameModeBase(ADataGameModeBase&&); \
	NO_API ADataGameModeBase(const ADataGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADataGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADataGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADataGameModeBase)


#define UE4Server_Source_Data_DataGameModeBase_h_29_PRIVATE_PROPERTY_OFFSET
#define UE4Server_Source_Data_DataGameModeBase_h_26_PROLOG
#define UE4Server_Source_Data_DataGameModeBase_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4Server_Source_Data_DataGameModeBase_h_29_PRIVATE_PROPERTY_OFFSET \
	UE4Server_Source_Data_DataGameModeBase_h_29_SPARSE_DATA \
	UE4Server_Source_Data_DataGameModeBase_h_29_RPC_WRAPPERS \
	UE4Server_Source_Data_DataGameModeBase_h_29_INCLASS \
	UE4Server_Source_Data_DataGameModeBase_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UE4Server_Source_Data_DataGameModeBase_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UE4Server_Source_Data_DataGameModeBase_h_29_PRIVATE_PROPERTY_OFFSET \
	UE4Server_Source_Data_DataGameModeBase_h_29_SPARSE_DATA \
	UE4Server_Source_Data_DataGameModeBase_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	UE4Server_Source_Data_DataGameModeBase_h_29_INCLASS_NO_PURE_DECLS \
	UE4Server_Source_Data_DataGameModeBase_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DATA_API UClass* StaticClass<class ADataGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UE4Server_Source_Data_DataGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
