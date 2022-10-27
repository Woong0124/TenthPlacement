// Copyright Epic Games, Inc. All Rights Reserved.


#include "DataGameModeBase.h"
#include "Socket.h"
#include <iostream>
#include <string>
#include "MyActor.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MutiThread.h"
#include "GameFramework/Actor.h"
using namespace std;

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"


ADataGameModeBase::ADataGameModeBase()
{

}

ADataGameModeBase::~ADataGameModeBase()
{

}

void ADataGameModeBase::BeginPlay()
{
	/*GetWorld()->SpawnActor<AMyActor>(FVector::ZeroVector, FRotator::ZeroRotator);*/
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	Worker = new MultiThread(this);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADataGameModeBase::Process, 0.01f, true);
}

void ADataGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));
	delete Worker;
}

void ADataGameModeBase::SpawnActor(FVector ActorVector)
{
	UE_LOG(LogTemp, Warning, TEXT("Spawn!"));
}

void ADataGameModeBase::Process()
{
	static int i = 0;
	if (ReceivePack.Header == PackageHeader::HSpawn)
	{
		FVector SpawnVector;
		SpawnVector.X = ReceivePack.X;
		SpawnVector.Y = ReceivePack.Y;
		SpawnVector.Z = ReceivePack.Z;
		MyActor[i] = (GetWorld()->SpawnActor<AMyActor>(SpawnVector, FRotator::ZeroRotator));
		++i;
	}
	else if (ReceivePack.Header == PackageHeader::HActorMove)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move"));
		FVector MoveVector;
		MoveVector.X = ReceivePack.X;
		MoveVector.Y = ReceivePack.Y;
		MoveVector.Z = ReceivePack.Z;
		MyActor[0]->AddActorWorldOffset(MoveVector);
	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NotData"));
	}

}

