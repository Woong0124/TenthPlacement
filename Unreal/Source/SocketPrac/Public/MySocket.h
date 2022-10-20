// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma comment(lib, "ws2_32.lib")

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/prewindowsapi.h"
#include <WinSock2.h>
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "CoreMinimal.h"



struct DataStruct
{
	int Key;
	char ActorType[50];
	float LocX;
	float LocY;
	float LocZ;

	DataStruct()
	{
		memset(this, 0, sizeof(DataStruct));
	};
};



/**
 * 
 */
class SOCKETPRAC_API MySocket
{
public:
	MySocket();
	~MySocket();

	SOCKET ClientSocket;

	// 소켓 초기화
	bool InitSocket();

	// 소켓 연결
	bool ConnectSocket();

	// 소켓 통신
	bool CommunicateSocket();

	// recv
	DataStruct RecvStructSocket(DataStruct* DStruct);

	// send
	void SendStructSocket(DataStruct* DStruct);
};
