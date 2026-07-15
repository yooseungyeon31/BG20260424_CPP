// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_CheckCombo_CPP.h"
#include "BasicPlayer.h"

void UAnimNotify_CheckCombo_CPP::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	//매쉬의 주인을 찾고 우리가 만든 클래스가 맞는지 확인
	ABasicPlayer* Pawn = Cast<ABasicPlayer>(MeshComp->GetOwner());

	if (Pawn) //주인이 맞다면
	{
		Pawn->CheckCombo();//폰에서 매쉬 호출-> 다음 공격 애니메이션으로 전환하세요
	}
}
