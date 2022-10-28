// Fill out your copyright notice in the Description page of Project Settings.
#include "MySocket.h"
#include "MultiThread.h"
#include "MyActor.h"
#include "Tenth_TutorialGameModeBase.h"

ATenth_TutorialGameModeBase::ATenth_TutorialGameModeBase()
{

}
ATenth_TutorialGameModeBase::~ATenth_TutorialGameModeBase()
{

}

void ATenth_TutorialGameModeBase::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
	Worker = new MultiThread(this);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATenth_TutorialGameModeBase::Process, 0.01f, true);
}

void ATenth_TutorialGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));
	delete Worker;
}

void ATenth_TutorialGameModeBase::SpawnActor(FVector ActorVector)
{
	UE_LOG(LogTemp, Warning, TEXT("Spawn!"));
}

void ATenth_TutorialGameModeBase::Process()
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
