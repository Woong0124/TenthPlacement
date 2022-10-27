// Copyright Epic Games, Inc. All Rights Reserved.


#include "SocketPracGameModeBase.h"
#include "MyActor01.h"
#include "MyRunnable.h"

//class AMyRunnable;

void ASocketPracGameModeBase::BeginPlay()
{
	MyRun = new MyRunnable();
	MyDataStruct = new DataStruct();

	// 스폰되게 구현해보기
	GetWorldTimerManager().SetTimer(SocketTimerHandle, this, &ASocketPracGameModeBase::MyProcess, 0.1f, true);




	/*SocketCheck = MySock->InitSocket();
	SocketCheck = MySock->ConnectSocket();
	//
	// 서버로부터 받아온 정보를 가지고 액터 스폰
	*MyDataStruct = MySock->RecvStructSocket(MyDataStruct);
	if (MyDataStruct->AInfo == SpawnActor)
	{
		MySpawnActor(MyDataStruct);
	}
	*MyDataStruct = MySock->RecvStructSocket(MyDataStruct);
	if (MyDataStruct->AInfo == SpawnActor)
	{
		MySpawnActor(MyDataStruct);
	}
	*MyDataStruct = MySock->RecvStructSocket(MyDataStruct);
	if (MyDataStruct->AInfo == SpawnActor)
	{
		MySpawnActor(MyDataStruct);
	}*/
}

void ASocketPracGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	delete MyRun;
}

void ASocketPracGameModeBase::MyProcess()
{
	MyDataStruct = MyRun->MyDataStruct;
	if (MyDataStruct->AInfo == SpawnActor)
	{
		MySpawnActor(MyDataStruct);
	}
	if (MyDataStruct->AInfo == MoveActor)
	{

	}
}

void ASocketPracGameModeBase::MySpawnActor(DataStruct* DStruct)
{
	if (strcmp(DStruct->ActorType, "AMyActor01") == 0)
	{
		FActorSpawnParameters SpawnParam;
		GetWorld()->SpawnActor<AMyActor01>(AMyActor01::StaticClass(), FVector(DStruct->LocX, DStruct->LocY, DStruct->LocZ), FRotator(0.f, 0.f, 0.f), SpawnParam);
	}
}

void ASocketPracGameModeBase::MyMoveActor(DataStruct* DStruct)
{
	
}
