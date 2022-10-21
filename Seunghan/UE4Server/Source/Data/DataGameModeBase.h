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

	virtual void BeginPlay() override;
private:
	Socket _Sock;
	bool IsConnected;
};
