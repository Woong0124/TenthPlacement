// Fill out your copyright notice in the Description page of Project Settings.


#include "MySocket.h"

#define CP "127.0.0.1"
#define PORT 3307

MySocket::MySocket()
{
	ClientSocket = INVALID_SOCKET;
}

MySocket::~MySocket()
{
	closesocket(ClientSocket);
	WSACleanup();
}

bool MySocket::InitSocket()
{
	
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Winsock Load"));
		return false;
	}

	
	ClientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ClientSocket == INVALID_SOCKET)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Create"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Success : Socket Load"));
	return true;
}

bool MySocket::ConnectSocket()
{
	
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr(CP);
	ServerSOCKADDR.sin_port = htons(PORT);

	
	int Result = connect(ClientSocket, (SOCKADDR*)&ServerSOCKADDR, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Connect"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Success : Socket Connect"));
	return true;
}

bool MySocket::CommunicateSocket()
{
	char Buffer[1024];
	int BufferSize = sizeof(Buffer);
	BufferSize = recv(ClientSocket, Buffer, BufferSize, 0);
	if (BufferSize == SOCKET_ERROR)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Communicate"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("%s"), &Buffer);
	UE_LOG(LogTemp, Log, TEXT("Success : Socket Communicate"));
	return true;
}
