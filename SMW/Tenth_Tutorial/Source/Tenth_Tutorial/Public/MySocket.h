// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma comment(lib, "ws2_32.lib")

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/prewindowsapi.h"
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include "Windows/PostWindowsApi.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "CoreMinimal.h"

#pragma pack(1)
struct Package
{
	int Packsize;
	int Header;
	int X;
	int Y;
	int Z;
};

#pragma pack()

enum PackageHeader
{
	HSpawn = 0,
	HActorMove = 1,

	None = 9
};
/**
 * 
 */
class TENTH_TUTORIAL_API MySocket
{
public:
	MySocket();
	~MySocket();

	

	
	bool InitSocket();

	bool CreateSocket();

	//bool BindSocket(const char* _BindIP, int _BindPort);

	//bool ListenSocket();

	//bool AcceptSocket();

	bool ConnectSocket(const char* _ServerIP, int _ConnectPort);

	bool SendSocket();

	FString ReciveSocket();
	
	template<typename T>
	T TReciveStruct(T* _Struct);

	template<typename T>
	void TSendStruct(T _Struct);

	SOCKET _Socket;
	SOCKET _SocketConnected;

};

template<typename T>
inline T MySocket::TReciveStruct(T* _Struct)
{
	int len;
	recv(_Socket, (char*)len, sizeof(int), 0);

	char Buffer[1024] = { 0, };
	recv(_Socket, Buffer, len, 0);

	_Struct = (T*)Buffer;

	return *_Struct;
}

template<typename T>
inline void MySocket::TSendStruct(T _Struct)
{
	int SendInt;
	int SendIntLength = sizeof(_Struct);
	SendInt = send(_Socket, (char*)&SendIntLength, sizeof(int), 0);
	SendInt = send(_Socket, (char*)&_Struct, sizeof(_Struct), 0);
}