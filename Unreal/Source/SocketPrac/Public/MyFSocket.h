// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Runtime/Networking/Public/Interfaces/IPv4/IPv4Address.h"
#include "MySocket.h"


/**
 * 
 */
class SOCKETPRAC_API MyFSocket
{
public:
	MyFSocket();
	~MyFSocket();
	
	FSocket* MyFSock;
	FIPv4Address IP;
	
	bool InitSocket();
	bool ConnectSocket();

	DataStruct RecvStructSocket(DataStruct* DStruct);
};
