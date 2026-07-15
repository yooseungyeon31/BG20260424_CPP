// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_CheckCombo_CPP.generated.h"

/**
 * 
 */
UCLASS()
//특정 타이밍에 이벤트를 발생시키는 기능 물려받음
class BG20260424_CPP_API UAnimNotify_CheckCombo_CPP : public UAnimNotify
{
	GENERATED_BODY()
public:
	//시퀀스 창에서 노티파이가 CheckCombo_CPP라는 이름으로 보이게 ㅎ ㅐ줌
	FString GetNotifyName_Implementation() const
	{
		return TEXT("CheckCombo_CPP");
	}
	//애니메이션 재생중에 이 노티파이가 배치된 지점에 도달하면 실제로 실행될 로직을 담음
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const
		FAnimNotifyEventReference& EventReference) override;
	
};
