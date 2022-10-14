// Copyright Epic Games, Inc. All Rights Reserved.


#include "SocketPracGameModeBase.h"

void ASocketPracGameModeBase::BeginPlay()
{
	SocketCheck = MySock.InitSocket();
	if (SocketCheck == false)
	{
		exit(-1);
	}

	SocketCheck = MySock.ConnectSocket();
	MySock.CommunicateSocket();
}

void ASocketPracGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	closesocket(MySock.ClientSocket);
	WSACleanup();
}
