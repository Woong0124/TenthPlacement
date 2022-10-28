#define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings

#pragma once
// 소켓 라이브러리 링크 걸기 구현부를 바이너리화 시킨 파일의 확장자 lib
#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include "Common.h"


class TCP_Socket
{
public:
	TCP_Socket();
	~TCP_Socket();

	// 소켓 초기화 소켓 버전 2.2 설정
	bool InitSocket();

	// 소켓 생성
	bool CreatSocket();

	// 소켓 바인드
	bool BindSocket(const char* _BindIP,int _BindPort);

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

	// 구조체 변경
	template<typename T>
	void TSendStruct(T Struct);

	template<typename T>
	T TReciveStruct(T* Struct);


	SOCKET _Socket;

	SOCKET _SocketConnected;

	SOCKET _ServerSocket;
};

template<typename T>
inline void TCP_Socket::TSendStruct(T Struct)
{
	int SendInt;
	int SendIntLength = sizeof(Struct);
	SendInt = send(_SocketConnected, (char*)&SendIntLength, sizeof(int), 0);
	SendInt = send(_SocketConnected, (char*)&Struct, sizeof(Struct), 0);
}

template<typename T>
inline T TCP_Socket::TReciveStruct(T* Struct)
{
	int		len = 0;
	char	Buffer[1024] = { 0, };
	
	recv(_SocketConnected, (char*)&len, sizeof(int), 0);
	recv(_SocketConnected, sizeof(Struct), 1024 , 0);

	Struct = (T*)Buffer;

	return *Struct;
}
