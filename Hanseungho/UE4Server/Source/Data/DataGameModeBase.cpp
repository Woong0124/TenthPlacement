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



ADataGameModeBase::ADataGameModeBase()
{
	SpawnActorCount=0;
}

ADataGameModeBase::~ADataGameModeBase()
{

}

void ADataGameModeBase::BeginPlay()
{
	
}

void ADataGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("EndPlay!"));
	GetWorldTimerManager().ClearTimer(TimerHandle);
	if(!Worker)
	{
		delete Worker;
		Worker = nullptr;
	}
}

void ADataGameModeBase::Process()
{
	if (ReceivePack.Header == PackageHeader::HSpawn && SpawnActorCount == 0)
	{
		FVector SpawnVector;
		SpawnVector.X = ReceivePack.X;
		SpawnVector.Y = ReceivePack.Y;
		SpawnVector.Z = ReceivePack.Z;
		MyActor[SpawnActorCount] = (GetWorld()->SpawnActor<AMyActor>(SpawnVector, FRotator::ZeroRotator));
		++SpawnActorCount;
	}
	else if (ReceivePack.Header == PackageHeader::HActorMove)
	{
		UE_LOG(LogTemp, Warning, TEXT("Move"));
		FVector MoveVector;
		MoveVector.X = ReceivePack.X;
		MoveVector.Y = ReceivePack.Y;
		MoveVector.Z = ReceivePack.Z;
		if (MyActor[0] != nullptr)
		{
			MyActor[0]->MyActorMove_Implementation(MoveVector);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NotData"));
	}
	if (SpawnActorCount == 0)
	{
		FVector SpawnVector;
		SpawnVector.X = 100;
		SpawnVector.Y = 100;
		SpawnVector.Z = 100;
		MyActor[SpawnActorCount] = (GetWorld()->SpawnActor<AMyActor>(SpawnVector, FRotator::ZeroRotator));
		++SpawnActorCount;
	}
}


void ADataGameModeBase::RunTherad()
{
	static int32 i = 0;
	if (i == 0)
	{
		Worker = new MultiThread(this);
		UE_LOG(LogTemp, Warning, TEXT("RunThread!"));
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADataGameModeBase::Process, 0.2f, true);
		++i;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(TimerHandle);
		GetWorldTimerManager().SetTimer(GoStopHandle, this, &ADataGameModeBase::ActorGo, 0.2f, true);
	}


}

void ADataGameModeBase::StopTherad()
{
	static int32 i = 0;
	if (i == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("StopThread!"));
		GetWorldTimerManager().ClearTimer(TimerHandle);
		delete Worker;
		Worker = nullptr;
		++i;
	}
	else
	{
		GetWorldTimerManager().ClearTimer(GoStopHandle);
	}
}

void ADataGameModeBase::ActorGo()
{
	UE_LOG(LogTemp, Warning, TEXT("Move"));
	FVector MoveVector;
	MoveVector.X = 40;
	MoveVector.Y = ReceivePack.Y;
	MoveVector.Z = ReceivePack.Z;
	if (MyActor[0] != nullptr)
	{
		MyActor[0]->MyActorMove_Implementation(MoveVector);
	}
}

