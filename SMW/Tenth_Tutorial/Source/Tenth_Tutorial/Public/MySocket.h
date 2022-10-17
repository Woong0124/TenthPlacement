// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma comment(lib, "ws2_32.lib")

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/prewindowsapi.h"
#include <WinSock2.h>
#include "Windows/PostWindowsApi.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "CoreMinimal.h"

/**
 * 
 */
class TENTH_TUTORIAL_API MySocket
{
public:
	MySocket();
	~MySocket();

	SOCKET ClientSocket;

	
	bool InitSocket();

	
	bool ConnectSocket();

	
	bool CommunicateSocket();

};
