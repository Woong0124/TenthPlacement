// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MySocket.h"
#include "Tenth_TutorialGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TENTH_TUTORIAL_API ATenth_TutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	MySocket MySock;
	bool SocketCheck;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
};
