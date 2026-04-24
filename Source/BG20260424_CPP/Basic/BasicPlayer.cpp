// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "../BG20260424_CPP.h"


// Sets default values
ABasicPlayer::ABasicPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//매쉬 불러오기
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),
		FRotator(0, -90.f, 0)

	);

}

// Called when the game starts or when spawned
void ABasicPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//입력 신호 연결
	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (UIC)
	{
		UIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABasicPlayer::Move);
		UIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABasicPlayer::Look);
		UIC->BindAction(IA_Lean, ETriggerEvent::Triggered, this, &ABasicPlayer::Lean);
		UIC->BindAction(IA_Lean, ETriggerEvent::Completed, this, &ABasicPlayer::Lean);


		UIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ABasicPlayer::Jump);
		UIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ABasicPlayer::Jump);
		UIC->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &ABasicPlayer::Jump);
	}

}

void ABasicPlayer::BigHead()
{
	//빅헤드가 트루면 트루 펄스면 펄스
	//bIsBigHead = bIsBigHead ? false : true;
	bIsBigHead = ~bIsBigHead;

}

void ABasicPlayer::Move(const FInputActionValue& Value)
{
	FVector2D Direction = Value.Get<FVector2D>();

	FRotator CameraRotation = GetControlRotation();

	FRotator CameraRotationInFloor = FRotator(0, CameraRotation.Yaw, 0);

	FVector CameraForwardInFloor = UKismetMathLibrary::GetForwardVector(CameraRotationInFloor);
	FVector CameraRightInFloor = UKismetMathLibrary::GetRightVector(CameraRotationInFloor);

	AddMovementInput(CameraForwardInFloor * Direction.X);
	AddMovementInput(CameraRightInFloor * Direction.Y);
}

void ABasicPlayer::Look(const FInputActionValue& Value)
{
	FVector2D RotationDirection = Value.Get<FVector2D>();

	AddControllerPitchInput(RotationDirection.Y * -1.f);
	AddControllerYawInput(RotationDirection.X);
}

void ABasicPlayer::Lean(const FInputActionValue& Value)
{

	float Direction = Value.Get<float>();
	
	TargetLeanAngle = 30.f * Direction;
	UE_LOG(LogBG20260424, Warning,TEXT("Direction %f"),Direction)

}



