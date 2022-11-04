// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "MySocket.h"
#include "MyFSocket.h"

/**
 * 
 */
class SOCKETPRAC_API MyRunnable : public FRunnable
{
public:
	MyRunnable();
	~MyRunnable();
	MyRunnable(ASocketPracGameModeBase* SocketPracGM);

	bool Init() override;
	uint32 Run() override;
	void Stop() override;

	MySocket* MySock;
	DataStruct* MyDataStruct;
	bool bSocketCheck;
	ASocketPracGameModeBase* MyGM;

	///////////////////////////////
	//
	MyFSocket* MyFSock;
	//
	///////////////////////////////

private:
	FRunnableThread* MyThread;
	bool bRunThread;
};
