// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataGameModeBase.generated.h"

#pragma pack(1)
struct Package
{
	int PackSize;
	int Header;
	int Key;
	int Index;
	int X;
	int Y;
	int Z;
};
#pragma pack()

enum PackageHeader
{
	HSpawn = 1,
	HActorMove = 2,

	None = 9
};

/**
 * 
 */
UCLASS()
class DATA_API ADataGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ADataGameModeBase();
	~ADataGameModeBase();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void SpawnActor(FVector ActorVector);

	void Process();

	Package ReceivePack;
	FTimerHandle TimerHandle;

	UFUNCTION(BlueprintCallable)
	void RunTherad();

	UFUNCTION(BlueprintCallable)
	void StopTherad();

	bool IsConnected;
private:

	class AMyActor* MyActor[5];
	class MultiThread* Worker;
	
};
