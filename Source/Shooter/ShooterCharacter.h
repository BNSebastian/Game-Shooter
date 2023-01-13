// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h" 
#include "GameFramework/SpringArmComponent.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

///***********************************************************
/* default class functions */
///***********************************************************

public:
	/// constructor
	AShooterCharacter();

	/// delta function - called every frame
	virtual void Tick(float DeltaTime) override;

	/// keybindings function - called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	/// Called when the game starts or when spawned
	virtual void BeginPlay() override;


///***********************************************************
/* camera properties */
///***********************************************************

public:
	/// spring arm positioned behind the character
	USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/// camera attached to the spring arm
	UCameraComponent* GetFollowerCamera() const { return FollowCamera; }

private:
	// spring arm positioned behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	class USpringArmComponent* CameraBoom;

	// camera attached to the spring arm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	class UCameraComponent* FollowCamera;


///***********************************************************
/* camera properties while aiming */
///***********************************************************

public:
	/// getter to check if character is aiming
	FORCEINLINE bool GetAiming() const { return bAiming; }

protected:
	/// aim toggle
	void AimingButtonPressed();
	void AimingButtonReleased();

	/// camera zoom while aiming
	void CameraInterpZoom(float DeltaTime);

	/// set BaseTurnRate and BaseLookUpRate based on aiming
	void SetLookRates();
	
	/// rotate controller based on mouse x movement
	void Turn(float Value);

	/// rotate controller based on mouse y movement
	void LookUp(float Value);

private:
	// true when aiming
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "True"))
	bool bAiming;

	// default camera field of view value
	float CameraDefaultFOV;

	// FOV value for when zoomed in
	float CameraZoomedFOV;

	// current FOV this frame
	float CameraCurrentFOV;

	// interpolation speed while zooming while aiming
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	float ZoomInterpSpeed;

///***********************************************************
/* controller properties */
///***********************************************************

protected:
	/// called for forwards / backwards input
	void MoveForward(float Value);

	/// called for right / left input
	void MoveRight(float Value);

	/// called via input to turn at a given rate
	void TurnAtRate(float Rate);

	/// called via input to look up/down at a given rate
	void LookUpAtRate(float Rate);

private:
	// base turn rate in degrees/second. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float BaseTurnRate;

	// base look up/down rate in degrees/second. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float BaseLookUpRate;


///***********************************************************
/* controller properties while aiming */
///***********************************************************

private:
	// turn rate while not aiming
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float HipTurnRate;

	// look up rate while not aiming 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float HipLookUpRate;

	// turn rate when aiming
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float AimingTurnRate;

	// look up rate while aiming
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"))
	float AimingLookUpRate;

	// scale factor for mouse look sensitivy, turn rate when not aiming
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseHipTurnRate;

	// scale factor for mouse look sensitivy, look up rate when not aiming
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseHipLookUpRate;

	// scale factor for mouse look sensitivy, turn rate when aiming
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseAimingTurnRate;

	// scale factor for mouse look sensitivy, look up rate when aiming
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "True"), meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float MouseAimingLookUpRate;

///***********************************************************
/* weapon properties */
///***********************************************************

protected:
	/// called when the FireButton is pressed
	void FireWeapon();

	/// helper function for ray-tracing
	bool GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation);

	/// performs a line trace under the crosshair and checks if item is present
	bool TraceUnderCrosshairs(FHitResult& OutHitResult, FVector& OutHitLocation);

	/// spawn default weapon
	void SpawnDefaultWeapon();

private:
	// randomized gunshot weapon sounds
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	class USoundCue* FireSound;

	// flash FX spawned at barrel socket
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	class UParticleSystem* MuzzleFlash;

	// recoil animation montage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	class UAnimMontage* HipFireMontage;

	// particle FX spawned at impact location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	UParticleSystem* ImpactParticles;

	// smoke particle FX for the weapon trail
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "True"))
	UParticleSystem* BeamParticles;

	// Currently equipped weapon
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "True"))
	class AWeapon* EquippedWeapon;

	// set the default weapon class in blueprint
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "True"))
	TSubclassOf<AWeapon> DefaultWeaponClass;

///***********************************************************
/* HUD pick-up */
///***********************************************************

public:
	/// getter for OverlappedItemCount
	int8 GetOverlappedItemCount() const { return OverlappedItemCount; }

	/// adds / subtracts to / from OverlappedItemCount and updates bShouldTraceForItems
	void IncrementOverlappedItemCount(int8 Amount);

protected:
	/// trace for items if OverlappedItemCount is > 0
	void TraceForItems();

private:
	// true if we should trace every frame for items
	bool bShouldTraceForItems;

	// number of overlapped items
	int8 OverlappedItemCount;

	// saved reference to the AItem we hit last frame
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items, meta = (AllowPrivateAccess = "true"))
	class AItem* TraceHitItemLastFrame;

///***********************************************************
/* crosshair */
///***********************************************************

public:
	/// get the spread
	UFUNCTION(BlueprintCallable)
	float GetCrosshairSpreadMultiplier() const;

protected:
	/// calculate the spread
	void CalculateCrosshairSpread(float DeltaTime);

	///
	void StartCrosshairBulletFire();

	/// 
	UFUNCTION()
	void FinishCrosshairBulletFire();

private:
	// spread of the crosshairs
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshairs, meta = (AllowPrivateAccess = "True"))
	float CrosshairSpreadMultiplier;

	// velocity component for crosshairs spread
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshairs, meta = (AllowPrivateAccess = "True"))
	float CrosshairVelocityFactor;

	// in air component for crosshairs spread
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshairs, meta = (AllowPrivateAccess = "True"))
	float CrosshairInAirFactor; 

	// aim component for crosshairs spread
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshairs, meta = (AllowPrivateAccess = "True"))
	float CrosshairAimFactor;

	// shooting component for crosshairs spread
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Crosshairs, meta = (AllowPrivateAccess = "True"))
	float CrosshairShootingFactor;

	// how long the character has been firing
	float ShootTimeDuration;

	// check if bullet is being fired
	bool bFiringBullet;

	// timer
	FTimerHandle CrosshairShootTimer;
};