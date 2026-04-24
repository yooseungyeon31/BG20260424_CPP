// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "BasicPlayer.h"

//void UBasicAnimInstance::NativeInitializeAnimation()
//{
//}

//void UBasicAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
//{
//
//}

void UBasicAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	ABasicPlayer* Player = Cast<ABasicPlayer>(TryGetPawnOwner());
	if (Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size2D();
		Direction = UKismetAnimationLibrary::CalculateDirection(Player->GetCharacterMovement()->Velocity, Player->GetActorRotation());

		TargetLeanAngle = Player->TargetLeanAngle;
		//보간을 통한 속력 구하기
		CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, TargetLeanAngle, DeltaSeconds, 5.0f);


		if (Player->bIsBigHead)
		{
			CurrentBigHeadScale = FMath::FInterpTo(CurrentBigHeadScale, BigHeadScale, DeltaSeconds, 10.0f);
		}
		else
		{
			CurrentBigHeadScale = FMath::FInterpTo(CurrentBigHeadScale, 1.0f, DeltaSeconds, 10.0f);
		}
	}
}
