// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasicPC.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class BG20260424_CPP_API ABasicPC : public APlayerController
{
	GENERATED_BODY()

public:

	//IMC_Basic 언리얼엔진에게 알렺기
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TArray<TSoftObjectPtr<UInputMappingContext>>IMC_Basic;

protected:

	virtual void OnPossess(APawn* aPawn)override;

	virtual void OnUnPossess() override;
	
};
