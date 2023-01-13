// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "ShooterAnimInstance.h"
#include "ShooterCharacter.h"


void UShooterAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	// if in any given frame, the ShooterCharacter is null, try to get the ShooterCharacter again
	if (ShooterCharacter == nullptr)
	{
		ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
	}

	if (ShooterCharacter != nullptr)
	{
		// get the lateral speed of the character from velocity
		FVector Velocity = ShooterCharacter->GetVelocity();
		Velocity.Z = 0;
		Speed = Velocity.Size();

		// is the character in the air?
		bIsInAir = ShooterCharacter->GetCharacterMovement()->IsFalling();

		// is the character accelerating?
		if (ShooterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			// whether or not a character is moving
			bIsAccelerating = true;
		}
		else
		{
			// whether or not a character is moving
			bIsAccelerating = false;
		}

		// get the rotation coresponding to the direction we're looking in
		FRotator AimRotation = ShooterCharacter->GetBaseAimRotation();
		// get the rotation coresponding to our velocity
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(ShooterCharacter->GetVelocity());
		// get the movement offset between rotators
		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
		// last movement offset
		if (ShooterCharacter->GetVelocity().Size() > 0.f)
		{
			LastMovementOffsetYaw = MovementOffsetYaw;
		}
		// update every frame
		bAiming = ShooterCharacter->GetAiming();
	}
}

void UShooterAnimInstance::NativeInitializeAnimation()
{
	ShooterCharacter = Cast<AShooterCharacter>(TryGetPawnOwner());
}
