// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AnimNotifyState_CheckAttack.generated.h"

/**
 * 
 */
UCLASS()
class BG20260424_CPP_API UAnimNotifyState_CheckAttack : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	FString GetNotifyName_Implementation() const
	{
		return TEXT("CheckAttack");
	}

	
	//노티파이 시작, 진행, 끝 판단 함수를 부모에게서 가져옴

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

};
