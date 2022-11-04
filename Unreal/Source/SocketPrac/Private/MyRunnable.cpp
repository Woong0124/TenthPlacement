// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRunnable.h"
#include "SocketPracGameModeBase.h"

#pragma region Main Thread Code

MyRunnable::MyRunnable()
{
	MyThread = FRunnableThread::Create(this, TEXT("Newtwork Thread"));
}

MyRunnable::~MyRunnable()
{
	if (MyThread)
	{
		MyThread->Kill();
		delete MyThread;
	}
}

MyRunnable::MyRunnable(ASocketPracGameModeBase* SocketPracGM)
{
	MyGM = SocketPracGM;
	MyThread = FRunnableThread::Create(this, TEXT("Newtwork Thread"));
}

#pragma endregion

bool MyRunnable::Init()
{
	UE_LOG(LogTemp, Log, TEXT("Thread Init"));
	return true;
}

uint32 MyRunnable::Run()
{
	////////////////////////////////////////////////
	// FSocket 으로 구현
	MyFSock = new MyFSocket();
	MyDataStruct = new DataStruct();
	bSocketCheck = MyFSock->InitSocket();
	bSocketCheck = MyFSock->ConnectSocket();

	if (bSocketCheck)
	{
		UE_LOG(LogTemp, Log, TEXT("Success : Thread")); 

		bRunThread = true;
		while (bRunThread)
		{
			*MyDataStruct = MyFSock->RecvStructSocket(MyDataStruct);
		}
	}
	delete MyDataStruct;
	delete MyFSock;


	////////////////////////////////////////////////
	// Winsock 으로 구현
	/*MySock = new MySocket();
	MyDataStruct = new DataStruct();
	bSocketCheck = MySock->InitSocket();
	bSocketCheck = MySock->ConnectSocket();

	if (bSocketCheck)
	{
		bRunThread = true;
		while (bRunThread)
		{
			*MyDataStruct = MySock->RecvStructSocket(MyDataStruct);
		}
	}
	delete MyDataStruct;
	delete MySock;*/

	return 0;
}

void MyRunnable::Stop()
{
	bRunThread = false;
}
