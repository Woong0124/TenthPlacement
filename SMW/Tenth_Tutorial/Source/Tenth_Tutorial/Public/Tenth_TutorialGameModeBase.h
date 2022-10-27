// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MySocket.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Actor.h"
#include "Tenth_TutorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TENTH_TUTORIAL_API ATenth_TutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATenth_TutorialGameModeBase();
	~ATenth_TutorialGameModeBase();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void SpawnActor(FVector ActorVector);

	void Process();
	Package ReceivePack;
	FTimerHandle TimerHandle;

private:

	class AMyActor* MyActor[5];

	class MultiThread* Worker;
	MySocket _Sock;
	bool IsConnected;
};
