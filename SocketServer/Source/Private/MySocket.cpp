#include "MySocket.h"
#include <iostream>

MySocket::MySocket()
{
	ServerSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;
}

MySocket::~MySocket()
{
	closesocket(ServerSocket);
	closesocket(ClientSocket);
	WSACleanup();
}

bool MySocket::CreateSocket()
{
	// Winsock 로드
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cout << "Winsock Error : " << GetLastError() << std::endl;
		return false;
	}

	// Socket 생성
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "fail create Socket : " << GetLastError() << std::endl;
		return false;
	}

	return true;
}

bool MySocket::BindListenSocket()
{
	// Socket 구성 요소
	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(SOCKADDR_IN));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ServerSockAddr.sin_port = htons(3307);

	// Socket 바인드
	int BindServerSock = bind(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR_IN));
	if (BindServerSock == SOCKET_ERROR)
	{
		std::cout << "fail bind : " << GetLastError() << std::endl;
		return false;
	}

	// Socket 수신대기
	BindServerSock = listen(ServerSocket, 0);
	if (BindServerSock == SOCKET_ERROR)
	{
		std::cout << "fail listen : " << GetLastError() << std::endl;
		return false;
	}

	return true;
}

bool MySocket::AcceptSocket()
{
	// Client socket 생성
	// 클라이언트 접속 요청 시, 승인해 주는 역할
	SOCKADDR_IN ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
	int ClientSockAddrLength = sizeof(ClientSockAddr);

	// Client 접속 승인
	ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
	if (ClientSocket == SOCKET_ERROR)
	{
		std::cout << "fail accept : " << GetLastError() << std::endl;
		return false;
	}

	return true;
}

void MySocket::SendSocket()
{
}

void MySocket::RecvSocket()
{
}
