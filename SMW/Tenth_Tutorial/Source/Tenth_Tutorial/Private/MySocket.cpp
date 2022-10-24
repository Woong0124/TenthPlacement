// Fill out your copyright notice in the Description page of Project Settings.


#include "MySocket.h"

#define CP "127.0.0.1"
#define PORT 3307

MySocket::MySocket()
{
	_Socket = INVALID_SOCKET;
	_SocketConnected = INVALID_SOCKET;
}

MySocket::~MySocket()
{
	//소켓을 담아줌
	UE_LOG(LogTemp, Log, TEXT("Close Socket"));
	closesocket(_Socket);
	closesocket(_SocketConnected);
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

	return true;
	
}

bool MySocket::CreateSocket()
{
	_Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (_Socket == INVALID_SOCKET)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Create"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Success : Socket Load"));
	return true;

}

bool MySocket::ConnectSocket(const char* _ServerIP, int _ConnectPort)
{
	
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr(CP);
	ServerSOCKADDR.sin_port = htons(PORT);

	
	int Result = connect(_Socket, (SOCKADDR*)&ServerSOCKADDR, sizeof(SOCKADDR_IN));
	if (Result == SOCKET_ERROR)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Connect"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("Success : Socket Connect"));
	return true;
}

bool MySocket::SendSocket()
{
	char Buffer[] = "Nunu";
	int SendBytes = send(_Socket, Buffer, sizeof(Buffer), 0);
	FString MSG = Buffer;

	UE_LOG(LogTemp, Log, TEXT("Send MSG : % s"), *(MSG));

	if (SendBytes <= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Winsock Error : %s"), GetLastError());
		return false;
	}
	return true;
}

FString MySocket::ReciveSocket()
{
	char Buffer[1024] = { 0, };
	int RecvBytes = recv(_Socket, Buffer, 1024, 0);
	FString MSG = Buffer;

	UE_LOG(LogTemp, Log, TEXT("Recive MSG : %s"), *(MSG));

	if (RecvBytes <= 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Winsock Error : %s"), GetLastError());
		
	}
	return MSG;
	
}
