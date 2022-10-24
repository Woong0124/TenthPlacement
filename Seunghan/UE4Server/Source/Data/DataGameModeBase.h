// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Socket.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "windows/AllowWindowsPlatformTypes.h"
#include "windows/prewindowsapi.h"

#pragma comment(lib, "ws2_32.lib")
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include "Runtime/Core/Public/Math/Vector.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"


#include "windows/PostWindowsApi.h"
#include "windows/HideWindowsPlatformTypes.h"
#include "DataGameModeBase.generated.h"


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

private:

	class AMyActor* MyActor[5];
	
	class MultiThread* Worker;
	Socket _Sock;
	bool IsConnected;
};
