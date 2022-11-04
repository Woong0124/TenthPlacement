// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFSocket.h"

#define CP "127.0.0.1"
#define PORT 3307


MyFSocket::MyFSocket()
{
	
}

MyFSocket::~MyFSocket()
{
	
}

bool MyFSocket::InitSocket()
{
	MyFSock = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"), false);

	UE_LOG(LogTemp, Log, TEXT("Success : Socket Load"));
	
	return true;
}

bool MyFSocket::ConnectSocket()
{
	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	FIPv4Address::Parse(TEXT(CP), IP);
	
	Addr->SetIp(IP.Value);
	Addr->SetPort(PORT);

	bool isConnect = MyFSock->Connect(*Addr);
	if (!isConnect)
	{
		UE_LOG(LogTemp, Log, TEXT("Failed : Socket Connect"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Success : Socket Connect"));
	}

	return isConnect;
}

DataStruct MyFSocket::RecvStructSocket(DataStruct* DStruct)
{
	uint8 Buffer[1024] = { 0, };
	uint32 Length = sizeof(Buffer);
	int32 BytesRead = 0;
	MyFSock->Recv(Buffer, Length, BytesRead);

	DStruct = (DataStruct*)Buffer;

	return *DStruct;
}
