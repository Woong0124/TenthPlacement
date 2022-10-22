// Copyright Epic Games, Inc. All Rights Reserved.


#include "SocketPracGameModeBase.h"
#include "MyActor01.h"



void ASocketPracGameModeBase::BeginPlay()
{
	MySock = new MySocket(this);

	//SocketCheck = MySock.InitSocket();
	//if (SocketCheck == false)
	//{
	//	exit(-1);
	//}
	//
	//SocketCheck = MySock.ConnectSocket();

	//MyDataStruct = new DataStruct;

	//// 서버로부터 받아온 정보를 가지고 액터 스폰
	//*MyDataStruct = MySock.RecvStructSocket(MyDataStruct);
	//if (MyDataStruct->AInfo == SpawnActor)
	//{
	//	//thread t1{ &ASocketPracGameModeBase::MySpawnActor, MyDataStruct };
	//	MySpawnActor(MyDataStruct);
	//}
	//*MyDataStruct = MySock.RecvStructSocket(MyDataStruct);
	//if (MyDataStruct->AInfo == SpawnActor)
	//{
	//	MySpawnActor(MyDataStruct);
	//}
}

void ASocketPracGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	delete MySock;
	//closesocket(MySock.ClientSocket);
	//WSACleanup();
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
