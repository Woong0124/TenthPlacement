// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Networking.h"
/**
 * 
 */
class DATA_API TestTCPFSocket
{
public:
	TestTCPFSocket();
	~TestTCPFSocket();

public:

	FSocket* ListenerSocket;
	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;

	bool StartTCPReceiver(const FString& SocketName, const FString& TheIP, const int32 ThePort, const int32 ReceiveBufferSize = 2 * 1024 * 1024);



};
