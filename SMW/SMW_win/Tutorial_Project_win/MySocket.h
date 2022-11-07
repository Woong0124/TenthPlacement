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

	
	// Send
	bool SendSocket();

	// Recv
	bool ReciveSocket();

	



	template<typename T> //템플릿은 헤더에 정의. cpp에 하면 못찾음. 
	void TSendStruct(T Struct);

	template<typename T>
	T TReciveStruct(T* Struct);
};

template<typename T>
inline void MySocket::TSendStruct(T Struct)
{
	int SendInt;
	int SendIntLength = sizeof(Struct);
	SendInt = send(CToSSocket, (char*)&SendIntLength, sizeof(int), 0);

	SendInt = send(CToSSocket, (char*)&Struct, sizeof(Struct), 0);

}
template<typename T>
inline T MySocket::TReciveStruct(T* Struct)
{
	char Buffer[1024] = { 0, };
	int len = 0;
	recv(CToSSocket, (char*)&len, sizeof(int), 0);
	
	recv(CToSSocket, sizeof(Struct), 1024, 0);
	Struct = (T*)Buffer;

	return *Struct;
}