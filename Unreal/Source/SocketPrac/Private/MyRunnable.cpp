// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRunnable.h"

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

#pragma endregion

bool MyRunnable::Init()
{
	UE_LOG(LogTemp, Log, TEXT("Thread Init"));
	return true;
}

uint32 MyRunnable::Run()
{
	MySock = new MySocket();
	bSocketCheck = MySock->InitSocket();
	bSocketCheck = MySock->ConnectSocket();

	if (bSocketCheck)
	{
		bRunThread = true;
		while (bRunThread)
		{
			MyDataStruct = new DataStruct();
			*MyDataStruct = MySock->RecvStructSocket(MyDataStruct);

			UE_LOG(LogTemp, Warning, TEXT("Thread Run"))
				FPlatformProcess::Sleep(0.1f);
		}
	}
	return 0;
}

void MyRunnable::Stop()
{
	bRunThread = false;
}
