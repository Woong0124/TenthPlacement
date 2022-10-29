#define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings

#pragma once
// ���� ���̺귯�� ��ũ �ɱ� �����θ� ���̳ʸ�ȭ ��Ų ������ Ȯ���� lib
#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>


class TCP_Socket
{
public:
	TCP_Socket();
	~TCP_Socket();

	// ���� �ʱ�ȭ ���� ���� 2.2 ����
	bool InitSocket();

	// ���� ����
	bool CreatSocket();

	// ���� ���ε�
	bool BindSocket(const char* _BindIP,int _BindPort);

	// ���� ���·� ����
	bool ListenSocket();

	// �������� Ŭ���̾�Ʈ ���� ����
	bool AcceptSocket();

	
	// ������ ����
	bool SendSocket();

	// ������ ����
	bool ReciveSocket();

	// ����ü ����
	template<typename T>
	void TSendStruct(T Struct);

	template<typename T>
	T TReciveStruct(T* Struct);


	SOCKET _Socket;

	SOCKET _SocketConnected;
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
