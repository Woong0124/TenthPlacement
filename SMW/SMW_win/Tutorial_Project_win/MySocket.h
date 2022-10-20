#pragma once
#include "Common.h"
#include <mysql.h>

class MySocket
{
public:
	MySocket();
	~MySocket();

	// 바인드 소켓
	SOCKET ServerSocket;


	SOCKET CToSSocket;

	// 연결 소켓
	SOCKET ClientSocket;

	//소켓 초기화 소켓 버전 2.2 설정
	bool InitSocket();

	// 소켓 생성
	bool CreateSocket();

	// Bind Socket
	bool BindSocket(const char* _BindIP,int _BindPort);


	//리슨 상태로 변경
	bool ListenSocket();

	// 접속 승인
	bool AcceptSocket();

	//클라이언트에서 서버로 연결
	bool ConnectSocket(const char* _ServerIP, int _ConnectPort);

	// Send
	bool SendSocket();

	// Recv
	bool RecvSocket();

	//구조체 전송
	void SendStruct(SpawnActorInfo Actorinfo);

	// 구조체 받기
	SpawnActorInfo ReciveStruct(SpawnActorInfo* ActorInfo);
};