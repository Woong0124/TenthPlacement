// Fill out your copyright notice in the Description page of Project Settings.


#include "MySocket.h"
#include "SocketPracGameModeBase.h"

#define CP "127.0.0.1"
#define PORT 3307

MySocket::MySocket()
{
	ClientSocket = INVALID_SOCKET;
	MyDataStruct = new DataStruct();
}

MySocket::~MySocket()
{
	closesocket(ClientSocket);
	WSACleanup();
}


bool MySocket::InitSocket()
{
	// Winsock 로드
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Winsock Load"));
		return false;
	}

	// Socket 생성
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
	// 연결할 서버 요소
	SOCKADDR_IN ServerSOCKADDR;
	memset(&ServerSOCKADDR, 0, sizeof(SOCKADDR_IN));
	ServerSOCKADDR.sin_family = PF_INET;
	ServerSOCKADDR.sin_addr.s_addr = inet_addr(CP);
	ServerSOCKADDR.sin_port = htons(PORT);

	// Socket 연결
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
	char Buffer[1024] = { 0, };
	int BufferSize = sizeof(Buffer);
	BufferSize = recv(ClientSocket, Buffer, BufferSize, 0);
	if (BufferSize == SOCKET_ERROR)
	{
		UE_LOG(LogTemp, Log, TEXT("Error : Socket Communicate"));
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("%s"),&Buffer);
	UE_LOG(LogTemp, Log, TEXT("Success : Socket Communicate"));
	return true;
}

DataStruct MySocket::RecvStructSocket(DataStruct* DStruct)
{
	char Buffer[1024] = { 0, };
	int Length = sizeof(Buffer);
	recv(ClientSocket, Buffer, Length, 0);

	DStruct = (DataStruct*)Buffer;
	return *DStruct;
}

void MySocket::SendStructSocket(DataStruct* DStruct)
{
	int SendInt;

	SendInt = send(ClientSocket, (char*)DStruct, sizeof(DataStruct), 0);
}














////////////////////////////////////////////////
//////////////////////////////////////////////////
//bool MySocket::Init()
//{
//	
//	UE_LOG(LogTemp, Log, TEXT("Thread Init "));
//	CheckThread = InitSocket();
//	if (CheckThread == false)
//	{
//		
//		return false;
//	}
//	CheckThread = ConnectSocket();
//	if (CheckThread == false)
//	{
//		return false;
//	}
//	return true;
//}
//
//uint32 MySocket::Run()
//{
//	if (MyThread != nullptr)
//	{
//		auto a = MyThread->GetThreadID();
//		UE_LOG(LogTemp, Log, TEXT("aaaaaaaaaaaaaaaaaaaa Init %d"), a);
//	}
//	//while (true)
//	//{
//	//	UE_LOG(LogTemp, Log, TEXT("Thread Run"))
//	//	//*MyDataStruct = RecvStructSocket(MyDataStruct);
//	//}
//	UE_LOG(LogTemp, Log, TEXT("Thread Finish"))
//
//
//
//	/*for (int i = 0; i < 100; ++i)
//	{
//		*MyDataStruct = RecvStructSocket(MyDataStruct);
//		UE_LOG(LogTemp, Log, TEXT("%i"), MyDataStruct->Key);
//		*MyDataStruct = RecvStructSocket(MyDataStruct);
//		UE_LOG(LogTemp, Log, TEXT("%i"), MyDataStruct->Key);
//		*MyDataStruct = RecvStructSocket(MyDataStruct);
//		UE_LOG(LogTemp, Log, TEXT("%i"), MyDataStruct->Key);
//
//		char Buffer[1024] = { 0, };
//		int BufferSize = sizeof(Buffer);
//		BufferSize = recv(ClientSocket, Buffer, BufferSize, 0);
//		UE_LOG(LogTemp, Log, TEXT("%s"), &Buffer);
//	}
//	UE_LOG(LogTemp, Log, TEXT("Thread Finish"));*/
//	return 0;
//}
//
////void MySocket::Exit()
////{
////	if (ClientSocket)
////	{
////		closesocket(ClientSocket);
////		WSACleanup();
////	}
////}
//
//void MySocket::Stop()
//{
//
//}
//////////////////////////////////////////////////
//////////////////////////////////////////////////
