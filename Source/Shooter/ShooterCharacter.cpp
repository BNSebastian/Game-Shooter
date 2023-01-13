// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "ShooterCharacter.h"
#include "Sound/SoundCue.h"

#include "Item.h"
#include "Weapon.h"

///***********************************************************
/* default class functions */
///***********************************************************

/// constructor
AShooterCharacter::AShooterCharacter() :
	// base rates for turning / looking up
	BaseTurnRate(45.f),
	BaseLookUpRate(45.f),
	// turn rate for aiming / not aiming
	HipTurnRate(90.f),
	HipLookUpRate(90.f),
	AimingTurnRate(20.f),
	AimingLookUpRate(20.f),
	// mouse look sensitivity scale factors
	MouseHipTurnRate(1.0f),
	MouseHipLookUpRate(1.0f),
	MouseAimingTurnRate(0.4f),
	MouseAimingLookUpRate(0.4f),
	// true when aiming the weapon
	bAiming(false),
	// camera FOV values
	CameraDefaultFOV(0.f), // set in BeginPlay
	CameraZoomedFOV(35.f),
	CameraCurrentFOV(0.f),
	ZoomInterpSpeed(20.f),
	// crosshair spread factors
	CrosshairSpreadMultiplier(0.f),
	CrosshairVelocityFactor(0.f),
	CrosshairInAirFactor(0.f),
	CrosshairAimFactor(0.f),
	CrosshairShootingFactor(0.f),
	// bullet fire timer variables
	ShootTimeDuration(0.05f),
	bFiringBullet(false),
	// item trace variables
	bShouldTraceForItems(false)
{
	// Set this character to call Tick() every frame.  
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*************************************************************
	* Setting up the spring arm that follows the character
	**************************************************************/
	// create the spring arm
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// attach the camera to the charactetr
	CameraBoom->SetupAttachment(RootComponent);
	// distance from the character
	CameraBoom->TargetArmLength = 180.f;
	// rotate the arm based on character movement
	CameraBoom->bUsePawnControlRotation = true;
	// translate camera upwards and forward 50 units
	CameraBoom->SocketOffset = FVector(0.f, 50.f, 70.f);

	/*************************************************************
	* Setting up the camera attached to the spring arm
	**************************************************************/
	// create the camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamer"));
	// attach camera to spring arm & set end of the spring arm (SocketName)
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// don't rotate the camera based on the rotation of the spring arm
	FollowCamera->bUsePawnControlRotation = false;

	/*************************************************************
	* Stop the character from rotating when the controller rotates
	* Controller only affects the camera
	**************************************************************/
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	/*************************************************************
	* Rotate the character to the direction of movement
	**************************************************************/
	// character moves in the direction of input
	GetCharacterMovement()->bOrientRotationToMovement = false;
	// set the yaw rotation rate
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	// initial velocity when jumping
	GetCharacterMovement()->JumpZVelocity = 600.f;
	// amount of lateral control when falling 
	GetCharacterMovement()->AirControl = 0.2f;

}

/// called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();

	/*************************************************************
	* camera zoom while aiming
	**************************************************************/

	// get the default value when spawning
	if (FollowCamera)
	{
		// store the default value
		CameraDefaultFOV = GetFollowerCamera()->FieldOfView;
		CameraCurrentFOV = CameraDefaultFOV;
	}

	// spawn the default weapon and attach it to the meshg
	SpawnDefaultWeapon();
}

/// called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*************************************************************
	* camera zoom while aiming
	**************************************************************/
	// handle interpolation for zoom when aiming
	CameraInterpZoom(DeltaTime);
	// change look sensitivity based
	SetLookRates();

	/*************************************************************
	* crosshair
	**************************************************************/
	// calculate crosshair spread multiplier
	CalculateCrosshairSpread(DeltaTime);

	///***********************************************************
	/* weapon functions */
	///***********************************************************

	/// check if item is under cursor
	TraceForItems();

}

/// input bindings
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	// bind moving forward
	PlayerInputComponent->BindAxis("MoveForward", this, &AShooterCharacter::MoveForward);
	// bind moving right
	PlayerInputComponent->BindAxis("MoveRight", this, &AShooterCharacter::MoveRight);
	// bind turn rate
	PlayerInputComponent->BindAxis("TurnRate", this, &AShooterCharacter::TurnAtRate);
	// bind turn
	PlayerInputComponent->BindAxis("Turn", this, &AShooterCharacter::Turn);
	// bind look up rate
	PlayerInputComponent->BindAxis("LookUpRate", this, &AShooterCharacter::LookUpAtRate);
	// bind look up
	PlayerInputComponent->BindAxis("LookUp", this, &AShooterCharacter::LookUp);
	// bind jump start & end
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	// bind FireButton
	PlayerInputComponent->BindAction("FireButton", IE_Released, this, &AShooterCharacter::FireWeapon);
	// bind aim toggle
	PlayerInputComponent->BindAction("AimingButton", IE_Pressed, this, &AShooterCharacter::AimingButtonPressed);
	PlayerInputComponent->BindAction("AimingButton", IE_Released, this, &AShooterCharacter::AimingButtonReleased);
}


///***********************************************************
/* controller properties */
///***********************************************************

/// pushes the character forward
void AShooterCharacter::MoveForward(float Value)
{
	// check if controller is valid
	if (Controller != nullptr && Value != 0.f)
	{
		// find out which way is forward & get the controller rotation
		const FRotator Rotation = Controller->GetControlRotation();
		// get yaw from the rotation
		const FRotator YawRotation{ 0, Rotation.Yaw, 0 };
		// create a rotation matrix from the orientation && get the x axis from the matrix
		const FVector Direction = FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::X);
		// move the character
		AddMovementInput(Direction, Value);
	}
}

/// pushes the character to the right
void AShooterCharacter::MoveRight(float Value)
{
	// check if controller is valid
	if (Controller != nullptr && Value != 0.f)
	{
		// find out which way is right, get the controller rotation
		const FRotator Rotation =Controller->GetControlRotation();
		// get yaw from the rotation
		const FRotator YawRotation{ 0, Rotation.Yaw, 0 };
		// create a rotation matrix from the orientation && get the x axis from the matrix
		const FVector Direction = FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::Y);
		// move the character
		AddMovementInput(Direction, Value);
	}
}

/// change yaw of the controller by calculating the delta for this frame from the rate information 
void AShooterCharacter::TurnAtRate(float Rate)
{
	/**
	* @param Rate - this is a normalized rate, i.e. 1.0 means 100% of desire turn rate
	* @param BaseTurnRate [degrees/seconds]
	* @param DeltaTime [seconds/frame]
	*/
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

/// Change pitch of the controller by calculating the delta for this frame from the rate information
void AShooterCharacter::LookUpAtRate(float Rate)
{
	/**
	* @param Rate - this is a normalized rate, i.e. 1.0 means 100% of desire turn rate 
	* @param BaseLookUpRate [degrees/seconds]
	* @param DeltaTime [seconds/frame]
	*/
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

/// X mouse sensitivity
void AShooterCharacter::Turn(float Value)
{
	float TurnScaleFactor{};
	if (bAiming)
	{
		TurnScaleFactor = MouseAimingTurnRate;
	}
	else
	{
		TurnScaleFactor = MouseHipTurnRate;
	}
	AddControllerYawInput(Value * TurnScaleFactor);
}

/// Y mouse sensitivity
void AShooterCharacter::LookUp(float Value)
{
	float LookUpScaleFactor{};
	if (bAiming)
	{
		LookUpScaleFactor = MouseAimingTurnRate;
	}
	else
	{
		LookUpScaleFactor = MouseHipTurnRate;
	}
	AddControllerPitchInput(Value * LookUpScaleFactor);
}


///***********************************************************
/* weapon functions */
///***********************************************************

/// fires the weapon
void AShooterCharacter::FireWeapon()
{
	/*************************************************************
	* sound effects
	**************************************************************/

	// check if sound asset is set
	if (FireSound != nullptr)
	{
		// play a sound with no attenuation
		UGameplayStatics::PlaySound2D(this, FireSound);
	}

	/*************************************************************
	* generate FX origin socket
	**************************************************************/
	// generate a mesh from the skeletal mesh BarrelSocket bone
	const USkeletalMeshSocket* BarrelSocket = GetMesh()->GetSocketByName("BarrelSocket");
	// check if the BarrelSocket could be created
	if (BarrelSocket != nullptr)
	{
		/*************************************************************
		* muzzle flash
		**************************************************************/

		// transform that containst location, rotation and scale data
		const FTransform SocketTransform = BarrelSocket->GetSocketTransform(GetMesh());
		if (MuzzleFlash != nullptr)
		{
			// attach FX to socket
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFlash, SocketTransform);
		}

		/*************************************************************
		* ray tracing
		**************************************************************/

		FVector BeamEnd; 
		bool bBeamEnd = GetBeamEndLocation(SocketTransform.GetLocation(), BeamEnd);
		if (bBeamEnd)
		{
			/*************************************************************
			* impact particles
			**************************************************************/

			// check if ImpactParticles are selected
			if (ImpactParticles)
			{
				// spawn FX at location after updating BeamEndPoint
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, BeamEnd);
			}

			/*************************************************************
			* smoke trail
			**************************************************************/

			// check to see if FX exists
			if (BeamParticles)
			{
				UParticleSystemComponent* Beam = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), BeamParticles, SocketTransform);
				// check to see if Beam got created
				if (Beam)
				{
					// the "Target" is a FX component
					Beam->SetVectorParameter(FName("Target"), BeamEnd);
				}
			}
		}
	}

	/*************************************************************
	* recoil animation
	**************************************************************/

	// play animation from montage
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance != nullptr && HipFireMontage != nullptr)
	{
		AnimInstance->Montage_Play(HipFireMontage);
		AnimInstance->Montage_JumpToSection(FName("StartFire"));
	}

	///***********************************************************
	/* crosshair spread based on bullets fired */
	///***********************************************************

	// start bullet fire timer for crosshairs
	StartCrosshairBulletFire();
}

/// ray-cast to location
bool AShooterCharacter::GetBeamEndLocation(const FVector& MuzzleSocketLocation, FVector& OutBeamLocation)
{
	// check for crosshair trace hit
	FHitResult CrosshairHitResult;
	bool bCrosshairHit = TraceUnderCrosshairs(CrosshairHitResult, OutBeamLocation);

	// trace from center of screen to location
	if (bCrosshairHit)
	{
		OutBeamLocation = CrosshairHitResult.Location;
	}
	else // no crosshair trace hit
	{
		// OutBeamLocation is the end location for the line trace
	}

	// trace from gun barrel to location
	FHitResult WeaponTraceHit;
	const FVector WeaponTraceStart = MuzzleSocketLocation;
	const FVector StartToEnd = OutBeamLocation - MuzzleSocketLocation;
	const FVector WeaponTraceEnd = MuzzleSocketLocation + StartToEnd * 1.25f;
	GetWorld()->LineTraceSingleByChannel(WeaponTraceHit, WeaponTraceStart, WeaponTraceEnd, ECollisionChannel::ECC_Visibility);

	// check if there's an object between the barrel and the BeamEndPoint
	if (WeaponTraceHit.bBlockingHit)
	{
		// change the BeamEndPoint to the new location
		OutBeamLocation = WeaponTraceHit.Location;
		return true;
	}

	return false;
}

/// performs a line trace under the crosshair and checks if item is present
bool AShooterCharacter::TraceUnderCrosshairs(FHitResult& OutHitResult, FVector& OutHitLocation)
{
	// get current sizeviewport size
	FVector2D ViewportSize;
	if (GEngine != nullptr && GEngine->GameViewport != nullptr)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	// get crosshair screen location
	FVector2D CrosshairLocation(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);
	FVector CrosshairWorldPosition;
	FVector CrosshairWorldDirection;

	// get world position and direction of crosshair
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0), CrosshairLocation, CrosshairWorldPosition, CrosshairWorldDirection);

	if (bScreenToWorld)
	{
		// perform a first trace hit from the center of the screen
		const FVector Start = CrosshairWorldPosition;
		const FVector End = CrosshairWorldPosition + CrosshairWorldDirection * 50000.f;
		OutHitLocation = End;

		// trace outward from crosshairs world location and store the line trace in ScreenTraceHit
		GetWorld()->LineTraceSingleByChannel(OutHitResult, Start, End, ECollisionChannel::ECC_Visibility);

		// check if there was a trace hit
		if (OutHitResult.bBlockingHit)
		{
			OutHitLocation = OutHitResult.Location;
			return true;
		}
	}

	return false;
}

/// spawns default weapon
void AShooterCharacter::SpawnDefaultWeapon()
{
	if (DefaultWeaponClass)
	{
		// spawn the weapon
		AWeapon* DefaultWeapon = GetWorld()->SpawnActor<AWeapon>(DefaultWeaponClass);
		// get the socket
		const USkeletalMeshSocket* HandSocket = GetMesh()->GetSocketByName(FName("RightHandSocket"));
		// check if socket exists
		if (HandSocket)
		{
			// attach the weapon to the hand socket RightHandSocket
			HandSocket->AttachActor(DefaultWeapon, GetMesh());
		}

		// set EquippedWeapon to the newly spawned weapon
		EquippedWeapon = DefaultWeapon;
	}
}


///***********************************************************
/* crosshair */
///***********************************************************

/// calculates the crosshair spread
void AShooterCharacter::CalculateCrosshairSpread(float DeltaTime)
{
	// create a range for the char speed
	FVector2D WalkSpeedRange{ 0.f, 600.f };

	// percentage range for char speed
	FVector2D VelocityMultiplierRange{ 0.f, 1.f };

	// velocity of the character
	FVector Velocity = GetVelocity();
	Velocity.Z = 0.f;

	// percentage velocity factor
	CrosshairVelocityFactor = FMath::GetMappedRangeValueClamped(WalkSpeedRange, VelocityMultiplierRange, Velocity.Size());

	// check if char is in air
	if (GetCharacterMovement()->IsFalling())
	{
		// spread the crosshair slowly while in air
		CrosshairInAirFactor = FMath::FInterpTo(CrosshairInAirFactor, 2.25f, DeltaTime, 2.25f);
	}
	else
	{
		// character is on the ground
		CrosshairInAirFactor = FMath::FInterpTo(CrosshairInAirFactor, 0.f, DeltaTime, 30.f);
	}

	// check if aiming, calculate crosshair aim factor
	if (bAiming)
	{
		// shrink crosshair a small amount very quickly
		CrosshairAimFactor = FMath::FInterpTo(CrosshairAimFactor, 0.6f, DeltaTime, 30.f);
	}
	else
	{
		// spread crosshair back to normal very quickly
		CrosshairAimFactor = FMath::FInterpTo(CrosshairAimFactor, 0.6f, DeltaTime, 30.f);
	}

	// true 0.05 seconds after firing
	if (bFiringBullet)
	{
		CrosshairShootingFactor = FMath::FInterpTo(CrosshairShootingFactor, 0.3f, DeltaTime, 60.f);
	}
	else
	{
		CrosshairShootingFactor = FMath::FInterpTo(CrosshairShootingFactor, 0.f, DeltaTime, 60.f);
	}

	// determine spread based on movement speed (CrosshairVelocityFactor)
	CrosshairSpreadMultiplier = 0.5f + CrosshairVelocityFactor + CrosshairInAirFactor - CrosshairAimFactor + CrosshairShootingFactor;
}

/// getter for CrosshairSpreadMultiplier
float AShooterCharacter::GetCrosshairSpreadMultiplier() const
{
	return CrosshairSpreadMultiplier;
}

/// called when starting to fire the weapon
void AShooterCharacter::StartCrosshairBulletFire()
{
	bFiringBullet = true;

	GetWorldTimerManager().SetTimer(CrosshairShootTimer, this, &AShooterCharacter::FinishCrosshairBulletFire, ShootTimeDuration);
}

/// called when the character stops firing
void AShooterCharacter::FinishCrosshairBulletFire()
{
	bFiringBullet = false;
}

///***********************************************************
/* camera zoom while aiming */
///***********************************************************

/// set bool to true if button pressed
void AShooterCharacter::AimingButtonPressed()
{
	bAiming = true;
}

/// set bool to false if button released
void AShooterCharacter::AimingButtonReleased()
{
	bAiming = false;
}

/// handle interpolation while zooming
void AShooterCharacter::CameraInterpZoom(float DeltaTime)
{
	// set current camera field of view
	if (bAiming)
	{
		// interpolate to zoomed FOV
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraZoomedFOV, DeltaTime, ZoomInterpSpeed);
	}
	else
	{
		// interpolate to default FOV
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraDefaultFOV, DeltaTime, ZoomInterpSpeed);
	}
	GetFollowerCamera()->SetFieldOfView(CameraCurrentFOV);
}

/// set BaseTurnRate and BaseLookUpRate based on aiming
void AShooterCharacter::SetLookRates()
{
	if (bAiming)
	{
		BaseTurnRate = AimingTurnRate;
		BaseLookUpRate = AimingLookUpRate;
	}
	else
	{
		BaseTurnRate = HipTurnRate;
		BaseLookUpRate = HipLookUpRate;
	}
}

///***********************************************************
/* HUD pick-up */
///***********************************************************

/// adds / subtracts to / from OverlappedItemCount and updates bShouldTraceForItems
void AShooterCharacter::IncrementOverlappedItemCount(int8 Amount)
{
	if (OverlappedItemCount + Amount <= 0)
	{
		OverlappedItemCount = 0;
		bShouldTraceForItems = false;
	}
	else
	{
		OverlappedItemCount += Amount;
		bShouldTraceForItems = true;
	}
}

/// trace for items if OverlappedItemCount is > 0
void AShooterCharacter::TraceForItems()
{
	if (bShouldTraceForItems)
	{
		FHitResult ItemTraceResult;
		FVector HitLocation;
		TraceUnderCrosshairs(ItemTraceResult, HitLocation);
		if (ItemTraceResult.bBlockingHit)
		{
			AItem* HitItem = Cast<AItem>(ItemTraceResult.Actor);
			if (HitItem && HitItem->GetPickupWidget())
			{
				// show item's pickup widget
				HitItem->GetPickupWidget()->SetVisibility(true);
			}

			// check if we hit an AItem last frame
			if (TraceHitItemLastFrame)
			{
				if (HitItem != TraceHitItemLastFrame)
				{
					// we are hitting a different AItem this frame from last frame
					// or AItem is null
					TraceHitItemLastFrame->GetPickupWidget()->SetVisibility(false);
				}
			}

			// store a reference to HitItem for next frame
			TraceHitItemLastFrame = HitItem;
		}
	}
	else if (TraceHitItemLastFrame)
	{
		// no longer overlapping any items
		// Item last frame should not show widget
		TraceHitItemLastFrame->GetPickupWidget()->SetVisibility(false);
	}
}
