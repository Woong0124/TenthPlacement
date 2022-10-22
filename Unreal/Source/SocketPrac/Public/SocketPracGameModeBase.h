// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MySocket.h"
#include "HAL/RunnableThread.h"
#include "MultichannelTcpReceiver.h"
#include "SocketPracGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class SOCKETPRAC_API ASocketPracGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	MySocket* MySock;
	bool SocketCheck;

	DataStruct* MyDataStruct;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	void MySpawnActor(DataStruct* DStruct);

	void MyMoveActor(DataStruct* DStruct);

};
