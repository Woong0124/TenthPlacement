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

}

ADataGameModeBase::~ADataGameModeBase()
{

}

void ADataGameModeBase::BeginPlay()
{
	
}

void ADataGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	
}

void ADataGameModeBase::Process()
{
	static int i = 0;
	
	if (ReceivePack.Header == PackageHeader::HSpawn && i == 0)
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
		if (MyActor[0] != nullptr)
		{
			MyActor[0]->AddActorWorldOffset(MoveVector);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NotData"));
	}

	if (i == 0)
	{
		FVector SpawnVector;
		SpawnVector.X = 100;
		SpawnVector.Y = 100;
		SpawnVector.Z = 100;
		MyActor[i] = (GetWorld()->SpawnActor<AMyActor>(SpawnVector, FRotator::ZeroRotator));
		++i;
	}


}


void ADataGameModeBase::RunTherad()
{
	Worker = new MultiThread(this);
	UE_LOG(LogTemp, Warning, TEXT("RunThread!"));
	IsConnected = true;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADataGameModeBase::Process, 0.2f, IsConnected);
}

void ADataGameModeBase::StopTherad()
{
	UE_LOG(LogTemp, Warning, TEXT("StopThread!"));
	/*delete Worker;*/
	/*Worker = nullptr;*/
}

