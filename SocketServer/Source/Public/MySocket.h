#pragma once

#include <mysql.h>
#include "DataStruct.h"

class MySocket
{
public:
	MySocket();
	~MySocket();

	// 바인드 소켓
	SOCKET ServerSocket;

	// 연결 소켓
	SOCKET ClientSocket;

	// Winsock 로드, Socket 생성
	bool CreateSocket();

	// Bind, Listen
	bool BindListenSocket();

	// 접속 승인
	bool AcceptSocket();

	// Send Struct
	void SendStructSocket(DataStruct* SpawnDataStruct);

	// Recv Struct
	DataStruct RecvStructSocket(DataStruct* SpawnDataStruct);
};