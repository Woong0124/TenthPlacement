// Copyright Epic Games, Inc. All Rights Reserved.


#include "SocketPracGameModeBase.h"
#include "MyActor01.h"
#include "MyRunnable.h"

//class AMyRunnable;

void ASocketPracGameModeBase::BeginPlay()
{

	MyRun = new MyRunnable(this);
	MyDataStruct = new DataStruct();


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

void ASocketPracGameModeBase::Tick(float DeltaSeconds)
{
	//MyProcess();
}

void ASocketPracGameModeBase::MyProcess()
{
	MyDataStruct = MyRun->MyDataStruct;
	if (MyDataStruct->Key != NULL)
	{
		if (MyDataStruct->AInfo == SpawnActor)
		{
			MySpawnActor(MyDataStruct);
		}
		if (MyDataStruct->AInfo == MoveActor)
		{
			MyMoveActor(MyDataStruct);
		}
	}
}

void ASocketPracGameModeBase::MySpawnActor(DataStruct* DStruct)
{
	DataStruct MyData = *DStruct;
	static unsigned int MyActorCount = 0;
	bool DoubleCheck = false;

	if (MyData.Key != NULL)
	{
		// 중복되는 녀석인지 아닌지 확인
		for (unsigned int i = 0; i < MyActorCount; ++i)
		{
			if (MyActorArr[i]->MyKey == MyData.Key)
			{
				DoubleCheck = true;
			}
		}

		if (strcmp(MyData.ActorType, "AMyActor01") == 0 && DoubleCheck == false)
		{
			FActorSpawnParameters SpawnParam;
			MyActorArr[MyActorCount] = GetWorld()->SpawnActor<AMyActor01>(AMyActor01::StaticClass(), FVector(MyData.LocX, MyData.LocY, MyData.LocZ), FRotator(0.f, 0.f, 0.f), SpawnParam);
			MyActorArr[MyActorCount]->MyKey = MyData.Key;
		}

		if (MyActorArr[MyActorCount] != NULL)
		{
			++MyActorCount;
		}
	}
}

void ASocketPracGameModeBase::MyMoveActor(DataStruct* DStruct)
{
	DataStruct MyData = *DStruct;
	if (MyActorArr[0] != NULL)
	{
		MyActorArr[0]->AddActorWorldOffset(FVector(MyData.LocX, MyData.LocY, MyData.LocZ));
	}
}
