// Fill out your copyright notice in the Description page of Project Settings.


#include "MutiThread.h"
#include "Socket.h"
#include "DataGameModeBase.h""

#include "Sockets.h"
#include "Networking.h"
#include "SocketSubsystem.h"

#define PORT	4000
#define PACKED_SIZE 1024
#define SERVER_IP	"192.168.0.178"

#pragma region Main Thread Code
// This code will be run on the thread that invoked this thread (i.e. game thread)
MultiThread::MultiThread()
{
	// Constructs the actual thread object. It will begin execution immediately
	// If you've passed in any inputs, set them up before calling this.
	Thread = FRunnableThread::Create(this, TEXT("SocketServer"));
}

MultiThread::MultiThread(ADataGameModeBase* GameModeBase)
{
	MyGameModeBase = GameModeBase;
	Thread = FRunnableThread::Create(this, TEXT("SocketServer"));
}


MultiThread::~MultiThread()
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
// The code below will run on the new thread.

bool MultiThread::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("My custom thread has been initialized"));

		// Return false if you want to abort the thread
		return true;
}


uint32 MultiThread::Run()
{

	FSocket* Socket;

	// ���� ����
	// ���� Ÿ�԰� ������ ���ڷ� �ִ´�.TEXT("Stream")�� �ָ� TCP ���������� ����ϰڴٴ� ���̴�. (UDP�� TEXT("DGram")�� ���ڷ� �ָ� �ȴ�.)
	//�� ��° ���� TEXT("Client Socket") �� ����� �̸��̴�.�˱� ���� �̸����� ����������.
	// �� ��° ���ڴ� UDP�� true TCP�� flase�̴�.

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Stream"), TEXT("Client Socket"));

	// IP ����
	FString address = TEXT("127.0.0.1");
	FIPv4Address ip;
	FIPv4Address::Parse(address, ip);

	int32 port = PORT;	// ��Ʈ�� 4000��

	// ��Ʈ�� ������ ��� Ŭ����
	// FInternetAddr�� ��Ʈ��ũ ������ �����ϰ�, ��Ŭ�������� ��Ʈ��ũ ����Ʈ�� ������ �ȴ�.

	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(port);



	// ����õ�, ����� �޾ƿ�
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

		uint8 len;
		int32	temp1 = 0;
		Socket->Recv(&len, 4 , temp1);

		uint8	Buffer[1024] = { 0 };
		int32	temp = 0;
		Socket->Recv(Buffer, len , temp);

		ReceivePack = *(Package*)Buffer;

		UE_LOG(LogTemp, Log, TEXT("Header : %d X : %d Z : %d"), ReceivePack.Header, ReceivePack.X, ReceivePack.Z);

		MyGameModeBase->ReceivePack = ReceivePack;
	}

	Socket->Close();

	return 0;



	// Peform your processor intensive task here. In this example, a neverending
	// task is created, which will only end when Stop is called.
	//Socket* _Sock = new Socket;
	//_Sock->InitSocket();
	//_Sock->CreatSocket();
	//_Sock->ConnectSocket(SERVER_IP, PORT);
	//UE_LOG(LogTemp, Warning, TEXT("My custom thread is running!"));
	//
	//Package ReceivePack;

	//while (bRunThread)
	//{
	//	
	//	FPlatformProcess::Sleep(0.3f);

	//	ReceivePack = _Sock->TReceiveStruct<Package>(&ReceivePack);

	//	UE_LOG(LogTemp, Log, TEXT("Header : %d X : %d Z : %d"), ReceivePack.Header, ReceivePack.X, ReceivePack.Z);

	//	MyGameModeBase->ReceivePack = ReceivePack;
	//}

	//delete _Sock;
	//return 0;
}


// This function is NOT run on the new thread!
void MultiThread::Stop()
{
	// Clean up memory usage here, and make sure the Run() function stops soon
	// The main thread will be stopped until this finishes!

	// For this example, we just need to terminate the while loop
	// It will finish in <= 1 sec, due to the Sleep()
	bRunThread = false;
}
