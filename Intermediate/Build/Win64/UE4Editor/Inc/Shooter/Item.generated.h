// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef SHOOTER_Item_generated_h
#error "Item.generated.h already included, missing '#pragma once' in Item.h"
#endif
#define SHOOTER_Item_generated_h

#define Shooter_Source_Shooter_Item_h_24_SPARSE_DATA
#define Shooter_Source_Shooter_Item_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSphereEndOverlap); \
	DECLARE_FUNCTION(execOnSphereOverlap);


#define Shooter_Source_Shooter_Item_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSphereEndOverlap); \
	DECLARE_FUNCTION(execOnSphereOverlap);


#define Shooter_Source_Shooter_Item_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Shooter"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define Shooter_Source_Shooter_Item_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Shooter"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define Shooter_Source_Shooter_Item_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public:


#define Shooter_Source_Shooter_Item_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItem)


#define Shooter_Source_Shooter_Item_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ItemMesh() { return STRUCT_OFFSET(AItem, ItemMesh); } \
	FORCEINLINE static uint32 __PPO__CollisionBox() { return STRUCT_OFFSET(AItem, CollisionBox); } \
	FORCEINLINE static uint32 __PPO__AreaSphere() { return STRUCT_OFFSET(AItem, AreaSphere); } \
	FORCEINLINE static uint32 __PPO__PickupWidget() { return STRUCT_OFFSET(AItem, PickupWidget); } \
	FORCEINLINE static uint32 __PPO__ItemName() { return STRUCT_OFFSET(AItem, ItemName); } \
	FORCEINLINE static uint32 __PPO__ItemCount() { return STRUCT_OFFSET(AItem, ItemCount); } \
	FORCEINLINE static uint32 __PPO__ItemRarity() { return STRUCT_OFFSET(AItem, ItemRarity); } \
	FORCEINLINE static uint32 __PPO__ActiveStars() { return STRUCT_OFFSET(AItem, ActiveStars); }


#define Shooter_Source_Shooter_Item_h_21_PROLOG
#define Shooter_Source_Shooter_Item_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Shooter_Source_Shooter_Item_h_24_PRIVATE_PROPERTY_OFFSET \
	Shooter_Source_Shooter_Item_h_24_SPARSE_DATA \
	Shooter_Source_Shooter_Item_h_24_RPC_WRAPPERS \
	Shooter_Source_Shooter_Item_h_24_INCLASS \
	Shooter_Source_Shooter_Item_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Shooter_Source_Shooter_Item_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Shooter_Source_Shooter_Item_h_24_PRIVATE_PROPERTY_OFFSET \
	Shooter_Source_Shooter_Item_h_24_SPARSE_DATA \
	Shooter_Source_Shooter_Item_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	Shooter_Source_Shooter_Item_h_24_INCLASS_NO_PURE_DECLS \
	Shooter_Source_Shooter_Item_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHOOTER_API UClass* StaticClass<class AItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Shooter_Source_Shooter_Item_h


#define FOREACH_ENUM_EITEMRARITY(op) \
	op(EItemRarity::EIR_Damaged) \
	op(EItemRarity::EIR_Common) \
	op(EItemRarity::EIR_Uncommon) \
	op(EItemRarity::EIR_Rare) \
	op(EItemRarity::EIR_Legendary) 

enum class EItemRarity : uint8;
template<> SHOOTER_API UEnum* StaticEnum<EItemRarity>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
