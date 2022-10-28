// Fill out your copyright notice in the Description page of Project Settings.


#include "Socket.h"
#include "MySocket.h"
#include "Sockets.h"
#include "Networking.h"
#include "SocketSubsystem.h"
#include "MyActor.h"
#include "DataGameModeBase.h"

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"

#pragma region Main Thread Code
MySocket::MySocket()
{
	//FSocket* TestSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(SOCK_STREAM, TEXT("default"), false);
	//FString address = TEXT("127.0.0.1");
	//int32 port = PORT;
	//FIPv4Address ip;
	//FIPv4Address::Parse(address, ip);
	//TSharedRef<FInternetAddr> addr =ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//addr->SetIp(ip.GetValue());
	//addr->SetPort(port);
	//bool connected = Socket->Connect(*addr);
	Thread = FRunnableThread::Create(this, TEXT("SocketServer"));
}

MySocket::MySocket(ADataGameModeBase* a)
{
	MyGameModeBase = a;
	Thread = FRunnableThread::Create(this, TEXT("SocketServer"));
}

MySocket::~MySocket()
{
	if (Thread)
	{
		// Kill() is a blocking call, it waits for the thread to finish.
		// Hopefully that doesn't take too long
		Thread->Kill();
		delete Thread;
	}

}
#pragma endregion

bool MySocket::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("My custom thread has been initialized"));

	// Return false if you want to abort the thread
	return true;
}

uint32 MySocket::Run()
{
	FSocket* Socket;

	// 소켓 생성
	// 소켓 타입과 설명을 인자로 넣는다.TEXT("Stream")을 주면 TCP 프로토콜을 사용하겠다는 뜻이다. (UDP는 TEXT("DGram")을 인자로 주면 된다.)
	//두 번째 인자 TEXT("Client Socket") 은 디버그 이름이다.알기 쉬운 이름으로 지정해주자.
	// 세 번째 인자는 UDP는 true TCP는 flase이다.

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));

	// IP 설정
	FString address = TEXT("127.0.0.1");
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	int32 port = PORT;	// 포트는 4000번

	// 포트와 소켓을 담는 클래스
	// FInternetAddr에 네트워크 정보를 저장하고, 이클래스에서 네트워크 바이트로 정렬이 된다.

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);



	// 연결시도, 결과를 받아옴
	bool isConnetcted = Socket->Connect(*addr);
	if (isConnetcted)
	{
		UE_LOG(LogTemp, Log, TEXT("Connect Success"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Connect fail"));
	}

	Package ReceivePack;

	while (bRunThread)
	{

		FPlatformProcess::Sleep(0.3f);

		uint8	Buffer[1024] = { 0 };
		int32	temp = 0;
		Socket->Recv(Buffer, 1024, temp);

		Package* a = (Package*)Buffer;
		ReceivePack = *a;

		UE_LOG(LogTemp, Log, TEXT("Header : %d X : %d Z : %d"), ReceivePack.Header, ReceivePack.X, ReceivePack.Z);

		MyGameModeBase->ReceivePack = ReceivePack;
	}


	return 0;
}

void MySocket::Stop()
{
	bRunThread = false;
}
