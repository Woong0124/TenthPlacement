// Copyright Epic Games, Inc. All Rights Reserved.


#include "Tenth_TutorialGameModeBase.h"

void ATenth_TutorialGameModeBase::BeginPlay()
{
	SocketCheck = MySock.InitSocket();
	if (SocketCheck == false)
	{
		exit(-1);
	}

}

void ATenth_TutorialGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	
	WSACleanup();
}