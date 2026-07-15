// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BasicPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;

UENUM(BlueprintType)
enum class EPoseState : uint8
{
	Stand = 0 UMETA(DisplayName = "Stand"),
	Crouch = 10 UMETA(DisplayName = "Crouch"),
	Prone = 20 UMETA(DisplayName = "Prone")
};


UCLASS()
class BG20260424_CPP_API ABasicPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Jump;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> IA_Lean;

	UFUNCTION(Exec)
	void BigHead();

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Lean(const FInputActionValue& Value);

	FRotator GetAimOffset() const;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	float TargetLeanAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsBigHead : 1 = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	EPoseState CurrentPoseState = EPoseState::Stand;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsWeaponEquipped : 1 = false;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 ComboCount = 0;

	

	UFUNCTION(BlueprintCallable)
	void CheckCombo();

	UFUNCTION(BlueprintCallable)
	void ComboAttack();

	void PlayComboMontage();


	//몽타주 쓰도록 설정
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	TObjectPtr<UAnimMontage> ComboMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 bIsAttacking : 1 = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
	uint8 PlayingComboIndex = 0;

	


	

};
