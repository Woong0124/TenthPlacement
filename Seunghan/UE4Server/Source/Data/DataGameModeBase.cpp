// Copyright Epic Games, Inc. All Rights Reserved.


#include "DataGameModeBase.h"
#include "Socket.h"
#include <iostream>
#include <string>
#include "MyActor.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MutiThread.h"
using namespace std;

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"




void ADataGameModeBase::BeginPlay()
{
	MultiThread* Worker = new MultiThread();
	//SpawnActorInfo ActorInfo(3, "real", 300, 140, 600);
	//_Sock.TSendStruct<SpawnActorInfo>(ActorInfo);
}




