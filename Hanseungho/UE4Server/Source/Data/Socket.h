//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "windows/AllowWindowsPlatformTypes.h"
//#include "windows/prewindowsapi.h"
//
//#pragma comment(lib, "ws2_32.lib")
//#define WIN32_LEAN_AND_MEAN
//#include <WinSock2.h>
//#include "Runtime/Core/Public/Math/Vector.h"
//#include "CoreMinimal.h"
//
//#include "windows/PostWindowsApi.h"
//#include "windows/HideWindowsPlatformTypes.h"
//
///**
// * 
// */
//#pragma pack(1)
//struct Package
//{
//	int PackSize;
//	int Header;
//	int Key;
//	int X;
//	int Y;
//	int Z;
//};
//#pragma pack()
//
//enum PackageHeader
//{
//	HSpawn = 0,
//	HActorMove = 1,
//
//	None = 9
//};
//
//class DATA_API Socket
//{
//public:
//	Socket();
//	~Socket();
//
//	// 소켓 초기화 소켓 버전 2.2 설정
//	bool InitSocket();
//
//	// 소켓 생성
//	bool CreatSocket();
//
//	// 소켓 바인드
//	bool BindSocket(const char* _BindIP, int _BindPort);
//
//	// 리슨 상태로 변경
//	bool ListenSocket();
//
//	// 서버에서 클라이언트 연결 승인
//	bool AcceptSocket();
//
//	// 클라이언트에서 서버로 연결
//	bool ConnectSocket(const char* _ServerIP, int _ConnectPort);
//
//	// 데이터 전송
//	bool SendSocket();
//
//	// 데이터 받음
//	FString ReceiveSocket();
//
//	template<typename T>
//	T TReceiveStruct(T* _Struct);
//
//	template<typename T>
//	void TSendStruct(T _Struct);
//
//	SOCKET _Socket;
//
//	SOCKET _SocketConnected;
//
//};
//
//template<typename T>
//inline T Socket::TReceiveStruct(T* _Struct)
//{
//	int len;
//	recv(_Socket, (char*)&len, sizeof(int), 0);
//
//	char	Buffer[1024] = { 0, };
//	recv(_Socket, Buffer, len, 0);
//
//	_Struct = (T*)Buffer;
//
//	return *_Struct;
//}
//
//template<typename T>
//inline void Socket::TSendStruct(T _Struct)
//{
//	int SendInt;
//	int SendIntLength = sizeof(_Struct);
//	SendInt = send(_Socket, (char*)&SendIntLength, sizeof(int), 0);
//	SendInt = send(_Socket, (char*)&_Struct, sizeof(_Struct), 0);
//}
