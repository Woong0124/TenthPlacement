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
}

void ATenth_TutorialGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

void ATenth_TutorialGameModeBase::SpawnActor(FVector ActorVector)
{
}

void ATenth_TutorialGameModeBase::Process()
{
}
