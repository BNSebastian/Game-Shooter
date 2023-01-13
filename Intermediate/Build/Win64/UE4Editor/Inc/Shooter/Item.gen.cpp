// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/Item.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItem() {}
// Cross Module References
	SHOOTER_API UEnum* Z_Construct_UEnum_Shooter_EItemRarity();
	UPackage* Z_Construct_UPackage__Script_Shooter();
	SHOOTER_API UClass* Z_Construct_UClass_AItem_NoRegister();
	SHOOTER_API UClass* Z_Construct_UClass_AItem();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
// End Cross Module References
	static UEnum* EItemRarity_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_Shooter_EItemRarity, Z_Construct_UPackage__Script_Shooter(), TEXT("EItemRarity"));
		}
		return Singleton;
	}
	template<> SHOOTER_API UEnum* StaticEnum<EItemRarity>()
	{
		return EItemRarity_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EItemRarity(EItemRarity_StaticEnum, TEXT("/Script/Shooter"), TEXT("EItemRarity"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_Shooter_EItemRarity_Hash() { return 1029510030U; }
	UEnum* Z_Construct_UEnum_Shooter_EItemRarity()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_Shooter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EItemRarity"), 0, Get_Z_Construct_UEnum_Shooter_EItemRarity_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EItemRarity::EIR_Damaged", (int64)EItemRarity::EIR_Damaged },
				{ "EItemRarity::EIR_Common", (int64)EItemRarity::EIR_Common },
				{ "EItemRarity::EIR_Uncommon", (int64)EItemRarity::EIR_Uncommon },
				{ "EItemRarity::EIR_Rare", (int64)EItemRarity::EIR_Rare },
				{ "EItemRarity::EIR_Legendary", (int64)EItemRarity::EIR_Legendary },
				{ "EItemRarity::EIR_MAX", (int64)EItemRarity::EIR_MAX },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EIR_Common.DisplayName", "Common" },
				{ "EIR_Common.Name", "EItemRarity::EIR_Common" },
				{ "EIR_Damaged.DisplayName", "Damaged" },
				{ "EIR_Damaged.Name", "EItemRarity::EIR_Damaged" },
				{ "EIR_Legendary.DisplayName", "Legendary" },
				{ "EIR_Legendary.Name", "EItemRarity::EIR_Legendary" },
				{ "EIR_MAX.DisplayName", "DefaultMAX" },
				{ "EIR_MAX.Name", "EItemRarity::EIR_MAX" },
				{ "EIR_Rare.DisplayName", "Rare" },
				{ "EIR_Rare.Name", "EItemRarity::EIR_Rare" },
				{ "EIR_Uncommon.DisplayName", "Uncommon" },
				{ "EIR_Uncommon.Name", "EItemRarity::EIR_Uncommon" },
				{ "ModuleRelativePath", "Item.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_Shooter,
				nullptr,
				"EItemRarity",
				"EItemRarity",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(AItem::execOnSphereEndOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSphereEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AItem::execOnSphereOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSphereOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void AItem::StaticRegisterNativesAItem()
	{
		UClass* Class = AItem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnSphereEndOverlap", &AItem::execOnSphereEndOverlap },
			{ "OnSphereOverlap", &AItem::execOnSphereOverlap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics
	{
		struct Item_eventOnSphereEndOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::NewProp_OtherBodyIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// called when overlapping AreaSphere ends\n" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "called when overlapping AreaSphere ends" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItem, nullptr, "OnSphereEndOverlap", nullptr, nullptr, sizeof(Item_eventOnSphereEndOverlap_Parms), Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItem_OnSphereEndOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItem_OnSphereEndOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AItem_OnSphereOverlap_Statics
	{
		struct Item_eventOnSphereOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((Item_eventOnSphereOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Item_eventOnSphereOverlap_Parms), &Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Item_eventOnSphereOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/// called when overlapping AreaSphere \n" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "called when overlapping AreaSphere" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AItem, nullptr, "OnSphereOverlap", nullptr, nullptr, sizeof(Item_eventOnSphereOverlap_Parms), Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AItem_OnSphereOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AItem_OnSphereOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AItem_NoRegister()
	{
		return AItem::StaticClass();
	}
	struct Z_Construct_UClass_AItem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ItemMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionBox_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AreaSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AreaSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ItemName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ItemCount;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ItemRarity_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ItemRarity_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ItemRarity;
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ActiveStars_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveStars_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActiveStars;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AItem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AItem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AItem_OnSphereEndOverlap, "OnSphereEndOverlap" }, // 2964452791
		{ &Z_Construct_UFunction_AItem_OnSphereOverlap, "OnSphereOverlap" }, // 3003223024
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Item.h" },
		{ "ModuleRelativePath", "Item.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_ItemMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// skeletal mesh for the item\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "skeletal mesh for the item" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ItemMesh = { "ItemMesh", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, ItemMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_ItemMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_ItemMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_CollisionBox_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// line trace colides with box to show HUD widgets\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "line trace colides with box to show HUD widgets" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x004000000008001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, CollisionBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_CollisionBox_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_CollisionBox_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_AreaSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// enables item tracing when overlapped\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "enables item tracing when overlapped" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_AreaSphere = { "AreaSphere", nullptr, (EPropertyFlags)0x004000000008001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, AreaSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_AreaSphere_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_AreaSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_PickupWidget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// pop-up widget for when the player looks at the item\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "pop-up widget for when the player looks at the item" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_PickupWidget = { "PickupWidget", nullptr, (EPropertyFlags)0x004000000008001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, PickupWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_PickupWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_PickupWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_ItemName_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// the name which appears on the pick-up widget\n" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "the name which appears on the pick-up widget" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0040000000000015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, ItemName), METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_ItemName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_ItemName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_ItemCount_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// item count (ammo, etc)\n" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "item count (ammo, etc)" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ItemCount = { "ItemCount", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, ItemCount), METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_ItemCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_ItemCount_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// item rarity determines number of stars in pick-up widget\n" },
		{ "ModuleRelativePath", "Item.h" },
		{ "ToolTip", "item rarity determines number of stars in pick-up widget" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity = { "ItemRarity", nullptr, (EPropertyFlags)0x0040000000000015, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, ItemRarity), Z_Construct_UEnum_Shooter_EItemRarity, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity_MetaData)) };
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars_Inner = { "ActiveStars", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Properties" },
		{ "Comment", "// \n" },
		{ "ModuleRelativePath", "Item.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars = { "ActiveStars", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AItem, ActiveStars), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ItemMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_CollisionBox,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_AreaSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_PickupWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ItemName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ItemCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ItemRarity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_ActiveStars,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AItem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AItem_Statics::ClassParams = {
		&AItem::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AItem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AItem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AItem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AItem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AItem, 454725749);
	template<> SHOOTER_API UClass* StaticClass<AItem>()
	{
		return AItem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AItem(Z_Construct_UClass_AItem, &AItem::StaticClass, TEXT("/Script/Shooter"), TEXT("AItem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AItem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
