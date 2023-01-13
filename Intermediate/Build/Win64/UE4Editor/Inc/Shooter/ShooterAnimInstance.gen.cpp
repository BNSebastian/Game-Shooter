// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Shooter/ShooterAnimInstance.h"
#include "Engine/Classes/Components/SkeletalMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooterAnimInstance() {}
// Cross Module References
	SHOOTER_API UClass* Z_Construct_UClass_UShooterAnimInstance_NoRegister();
	SHOOTER_API UClass* Z_Construct_UClass_UShooterAnimInstance();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
	UPackage* Z_Construct_UPackage__Script_Shooter();
	SHOOTER_API UClass* Z_Construct_UClass_AShooterCharacter_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UShooterAnimInstance::execUpdateAnimationProperties)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAnimationProperties(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	void UShooterAnimInstance::StaticRegisterNativesUShooterAnimInstance()
	{
		UClass* Class = UShooterAnimInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateAnimationProperties", &UShooterAnimInstance::execUpdateAnimationProperties },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics
	{
		struct ShooterAnimInstance_eventUpdateAnimationProperties_Parms
		{
			float DeltaTime;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ShooterAnimInstance_eventUpdateAnimationProperties_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UShooterAnimInstance, nullptr, "UpdateAnimationProperties", nullptr, nullptr, sizeof(ShooterAnimInstance_eventUpdateAnimationProperties_Parms), Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UShooterAnimInstance_NoRegister()
	{
		return UShooterAnimInstance::StaticClass();
	}
	struct Z_Construct_UClass_UShooterAnimInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShooterCharacter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShooterCharacter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsInAir_MetaData[];
#endif
		static void NewProp_bIsInAir_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsInAir;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsAccelerating_MetaData[];
#endif
		static void NewProp_bIsAccelerating_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsAccelerating;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementOffsetYaw_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MovementOffsetYaw;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastMovementOffsetYaw_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LastMovementOffsetYaw;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAiming_MetaData[];
#endif
		static void NewProp_bAiming_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAiming;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UShooterAnimInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_Shooter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UShooterAnimInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UShooterAnimInstance_UpdateAnimationProperties, "UpdateAnimationProperties" }, // 2476424979
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "ShooterAnimInstance.h" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_ShooterCharacter_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_ShooterCharacter = { "ShooterCharacter", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UShooterAnimInstance, ShooterCharacter), Z_Construct_UClass_AShooterCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_ShooterCharacter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_ShooterCharacter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_Speed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// the speed of the character\n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "the speed of the character" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UShooterAnimInstance, Speed), METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_Speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_Speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// whether or not the character is jumping \n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "whether or not the character is jumping" },
	};
#endif
	void Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir_SetBit(void* Obj)
	{
		((UShooterAnimInstance*)Obj)->bIsInAir = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir = { "bIsInAir", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UShooterAnimInstance), &Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir_SetBit, METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// whether or not the character is moving \n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "whether or not the character is moving" },
	};
#endif
	void Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating_SetBit(void* Obj)
	{
		((UShooterAnimInstance*)Obj)->bIsAccelerating = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating = { "bIsAccelerating", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UShooterAnimInstance), &Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating_SetBit, METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_MovementOffsetYaw_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// offset yaw used for strafing\n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "offset yaw used for strafing" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_MovementOffsetYaw = { "MovementOffsetYaw", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UShooterAnimInstance, MovementOffsetYaw), METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_MovementOffsetYaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_MovementOffsetYaw_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_LastMovementOffsetYaw_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// offset yaw the frame before we stopped moving\n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "offset yaw the frame before we stopped moving" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_LastMovementOffsetYaw = { "LastMovementOffsetYaw", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UShooterAnimInstance, LastMovementOffsetYaw), METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_LastMovementOffsetYaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_LastMovementOffsetYaw_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Movement" },
		{ "Comment", "// check if the character is aiming\n" },
		{ "ModuleRelativePath", "ShooterAnimInstance.h" },
		{ "ToolTip", "check if the character is aiming" },
	};
#endif
	void Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming_SetBit(void* Obj)
	{
		((UShooterAnimInstance*)Obj)->bAiming = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming = { "bAiming", nullptr, (EPropertyFlags)0x0040000000020015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UShooterAnimInstance), &Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming_SetBit, METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UShooterAnimInstance_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_ShooterCharacter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_Speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsInAir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bIsAccelerating,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_MovementOffsetYaw,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_LastMovementOffsetYaw,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShooterAnimInstance_Statics::NewProp_bAiming,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UShooterAnimInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShooterAnimInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UShooterAnimInstance_Statics::ClassParams = {
		&UShooterAnimInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UShooterAnimInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UShooterAnimInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UShooterAnimInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UShooterAnimInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UShooterAnimInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UShooterAnimInstance, 484176475);
	template<> SHOOTER_API UClass* StaticClass<UShooterAnimInstance>()
	{
		return UShooterAnimInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UShooterAnimInstance(Z_Construct_UClass_UShooterAnimInstance, &UShooterAnimInstance::StaticClass, TEXT("/Script/Shooter"), TEXT("UShooterAnimInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UShooterAnimInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
