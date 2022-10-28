// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiThread.h"
#include "MySocket.h"
#include "MyActor.h"
#include "Tenth_TutorialGameModeBase.h"

#define PORT 3307
#define PACKED_SIZE 1024
#define SERVER_IP "192.168.0.177"
#pragma region Main Thread Code

MultiThread::MultiThread()
{
    Thread = FRunnableThread::Create(this, TEXT("SocketSeerver"));
}

MultiThread::MultiThread(ATenth_TutorialGameModeBase* a)
{
    MyGameModeBase = a;
    Thread = FRunnableThread::Create(this, TEXT("SocketServer"));
}

MultiThread::~MultiThread()
{
    if (Thread)
    {
        Thread->Kill();
        delete Thread;
    }
}

#pragma endregion

bool MultiThread::Init()
{
    UE_LOG(LogTemp, Warning, TEXT("My custom thread has been initialized"));

    return true;
}

uint32 MultiThread::Run()
{
    MySocket* _Sock = new MySocket;
    _Sock->InitSocket();
    _Sock->CreateSocket();
    _Sock->ConnectSocket(SERVER_IP, PORT);
    UE_LOG(LogTemp, Warning, TEXT("My Custom thread is running"));

    Package ReceivePack;

    int i = 0;
    while (bRunThread)
    {
        FPlatformProcess::Sleep(0.01f);

        ReceivePack = _Sock->TReciveStruct<Package>(&ReceivePack);

        UE_LOG(LogTemp, Log, TEXT("Header : %d X : %d Z : %d"), ReceivePack.Header, ReceivePack.X, ReceivePack.Z);

        MyGameModeBase->ReceivePack = ReceivePack;
    }
    delete _Sock;
    return 0;
}

void MultiThread::Stop()
{
    bRunThread = false;
}
