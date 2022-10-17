// Copyright Epic Games, Inc. All Rights Reserved.


#include "DataGameModeBase.h"
#include "Socket.h"
#include <iostream>
#include <string>
#include "MyActor.h"
using namespace std;

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"



void ADataGameModeBase::BeginPlay()
{
	_Sock.InitSocket();
	_Sock.CreatSocket();
	_Sock.ConnectSocket(SERVER_IP, PORT);
		
	int len;
	recv(_Sock._Socket, (char*)&len, sizeof(int), 0);

	char	Buffer[1024] = { 0, };
	recv(_Sock._Socket, Buffer, len, 0);
	SpawnActorInfo* b;
	b = (SpawnActorInfo*)Buffer;
	
	FVector Fv;
	Fv.X = b->x;
	Fv.Y = b->y;
	Fv.Z = b->z;

	FRotator Fr;

	GetWorld()->SpawnActor<AMyActor>(Fv, Fr);

	UE_LOG(LogTemp, Log, TEXT("Begin Event : %i"), b->Key);
	UE_LOG(LogTemp, Log, TEXT("Begin Event : %i"), b->x);
	UE_LOG(LogTemp, Log, TEXT("Begin Event : %i"), b->y);
	UE_LOG(LogTemp, Log, TEXT("Begin Event : %i"), b->z);
}
