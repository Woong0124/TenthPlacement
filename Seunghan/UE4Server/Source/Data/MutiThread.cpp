// Fill out your copyright notice in the Description page of Project Settings.


#include "MutiThread.h"
#include "Socket.h"
#include "MyActor.h"
#include "DataGameModeBase.h"

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
	// Peform your processor intensive task here. In this example, a neverending
	// task is created, which will only end when Stop is called.
	Socket* _Sock = new Socket;
	_Sock->InitSocket();
	_Sock->CreatSocket();
	_Sock->ConnectSocket(SERVER_IP, PORT);
	UE_LOG(LogTemp, Warning, TEXT("My custom thread is running!"))

	while (bRunThread)
	{
		
		FPlatformProcess::Sleep(1.0f);
		
		FString MSG = _Sock->ReciveSocket();
		UE_LOG(LogTemp, Warning, TEXT("Recive MSG : %s"), *MSG);
	}

	delete _Sock;
	return 0;
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
