// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "windows/AllowWindowsPlatformTypes.h"
#include "windows/prewindowsapi.h"

#pragma comment(lib, "ws2_32.lib")
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include "Runtime/Core/Public/Math/Vector.h"
#include "CoreMinimal.h"

#include "windows/PostWindowsApi.h"
#include "windows/HideWindowsPlatformTypes.h"

/**
 * 
 */
struct MyFVector
{
	int x;
	int y;
	int z;
};

struct SpawnActorInfo
{
	int Key;
	FString Name;
	MyFVector VectorInfo;

	SpawnActorInfo() { Key = 0; };
};

class DATA_API Socket
{
public:
	Socket();
	~Socket();

	// 소켓 초기화 소켓 버전 2.2 설정
	bool InitSocket();

	// 소켓 생성
	bool CreatSocket();

	// 소켓 바인드
	bool BindSocket(const char* _BindIP, int _BindPort);

	// 리슨 상태로 변경
	bool ListenSocket();

	// 서버에서 클라이언트 연결 승인
	bool AcceptSocket();

	// 클라이언트에서 서버로 연결
	bool ConnectSocket(const char* _ServerIP, int _ConnectPort);

	// 데이터 전송
	bool SendSocket();

	// 데이터 받음
	bool ReciveSocket();

	// 구조체 받기
	void ReciveStruct(SpawnActorInfo* ActorInfo);

	SOCKET _Socket;

	SOCKET _SocketConnected;

};