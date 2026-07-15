// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BasicPlayer.h"
#include "BasicAnimInstance.generated.h"


/**
 * 
 */
UCLASS()
class BG20260424_CPP_API UBasicAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	//virtual void NativeInitializeAnimation() override;

	//virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float TargetLeanAngle = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float CurrentLeanAngle = 0;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float BigHeadScale = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float CurrentBigHeadScale = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float AimPitch = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	float AimYaw= 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	EPoseState CurrentPoseState = EPoseState::Stand;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsWeaponEquipped : 1 = false;

	UFUNCTION()
	void AnimNotify_CheckCombo_SK_CPP(UAnimNotify* Notify);
	
};
