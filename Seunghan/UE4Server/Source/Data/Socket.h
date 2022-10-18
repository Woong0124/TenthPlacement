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

struct SpawnActorInfo
{
	int Key;
	char Name[10];
	int x;
	int y;
	int z;

	SpawnActorInfo() { Key = 0; };
	SpawnActorInfo(int _key, const char* _Name, int _x, int _y, int _z)
	{
		Key = _key;
		strcpy_s(Name,_Name);
		x = _x;
		y = _y;
		z = _z;
	}
};

class DATA_API Socket
{
public:
	Socket();
	~Socket();

	// ���� �ʱ�ȭ ���� ���� 2.2 ����
	bool InitSocket();

	// ���� ����
	bool CreatSocket();

	// ���� ���ε�
	bool BindSocket(const char* _BindIP, int _BindPort);

	// ���� ���·� ����
	bool ListenSocket();

	// �������� Ŭ���̾�Ʈ ���� ����
	bool AcceptSocket();

	// Ŭ���̾�Ʈ���� ������ ����
	bool ConnectSocket(const char* _ServerIP, int _ConnectPort);

	// ������ ����
	bool SendSocket();

	// ������ ����
	bool ReciveSocket();

	// ����ü �ޱ�
	SpawnActorInfo ReciveStruct(SpawnActorInfo* _ActorInfo);

	void SendStruct(SpawnActorInfo _ActorInfo);

	SOCKET _Socket;

	SOCKET _SocketConnected;

};