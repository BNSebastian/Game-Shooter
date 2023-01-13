// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	EIR_Damaged UMETA(DisplayName = "Damaged"),
	EIR_Common UMETA(DisplayName = "Common"),
	EIR_Uncommon UMETA(DisplayName = "Uncommon"),
	EIR_Rare UMETA(DisplayName = "Rare"),
	EIR_Legendary UMETA(DisplayName = "Legendary"),
	EIR_MAX UMETA(DisplayName = "DefaultMAX")
};

UCLASS()
class SHOOTER_API AItem : public AActor
{
	GENERATED_BODY()

///***********************************************************
/* default class functions */
///***********************************************************

public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


///***********************************************************
/* colissions */
///***********************************************************

public:

protected:

private:
	// skeletal mesh for the item
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* ItemMesh;

	// line trace colides with box to show HUD widgets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CollisionBox;

	// enables item tracing when overlapped
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* AreaSphere;


///***********************************************************
/* HUD pick-up */
///***********************************************************

public:
	/// PickupWidget getter
	UWidgetComponent* GetPickupWidget() const { return PickupWidget; }

protected:
	/// called when overlapping AreaSphere 
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/// called when overlapping AreaSphere ends
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/// sets the ActiveStars array of bools based on ItemRarity
	void SetActiveStars();

private:
	// pop-up widget for when the player looks at the item
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* PickupWidget;

	// the name which appears on the pick-up widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	FString ItemName;

	// item count (ammo, etc)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	int32 ItemCount;

	// item rarity determines number of stars in pick-up widget
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	EItemRarity ItemRarity;

	// 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	TArray<bool> ActiveStars;
};
