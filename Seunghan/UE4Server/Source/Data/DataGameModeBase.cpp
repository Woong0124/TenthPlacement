// Copyright Epic Games, Inc. All Rights Reserved.


#include "DataGameModeBase.h"
#include "Socket.h"
#include <iostream>
#include <string>
using namespace std;

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"



void ADataGameModeBase::BeginPlay()
{
	SpawnActorInfo a;
	_Sock.InitSocket();
	_Sock.CreatSocket();
	_Sock.ConnectSocket(SERVER_IP, PORT);

	_Sock.ReciveStruct(&a);
	
	UE_LOG(LogTemp, Log, TEXT("Begin Event : %i"), a.Key);
}
