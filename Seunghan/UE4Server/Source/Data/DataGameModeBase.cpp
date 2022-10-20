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

	for (int i = 0; i < 2; ++i)
	{
		SpawnActorInfo b;
		b = _Sock.TReciveStruct<SpawnActorInfo>(&b);

		FVector Fv;
		Fv.X = b.x;
		Fv.Y = b.y;
		Fv.Z = b.z;

		FRotator Fr;

		GetWorld()->SpawnActor<AMyActor>(Fv, Fr);

		SpawnActorInfo ActorInfo(3,"real",300,140,600);

		_Sock.TSendStruct<SpawnActorInfo>(ActorInfo);
	}
	
}
