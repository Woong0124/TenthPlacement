#include "MySocket.h"
#include <iostream>

#define PORT 3307

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

bool MySocket::InitSocket()
{
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cout << "Winsock Error : " << GetLastError() << std::endl;
		return false;
	}
	return true;
}

bool MySocket::CreateSocket()
{
	
	// Socket 생성
	ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "fail create Socket : " << GetLastError() << std::endl;
		return false;
	}

	return true;
}

bool MySocket::BindSocket(const char* _BindIP, int _BindPort)
{
	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(SOCKADDR_IN));
	ServerSockAddr.sin_family = PF_INET;
	ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY); //host to network long( 4byte)
	ServerSockAddr.sin_port = htons(PORT); //host to network short(2 byte). 이 함수를 거치면 무조건 빅엔디안 방식으로 데이터를 변환하여 설정.

	// Socket 바인드
	int BindServerSock = bind(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR_IN));
	if (BindServerSock == SOCKET_ERROR)
	{
		std::cout << "fail bind : " << GetLastError() << std::endl;
		return false;
	}
	return true;
}

bool MySocket::ListenSocket()
{

	// Socket 수신대기
	int BindServerSock = listen(ServerSocket, 0); // 2번째 인자는 한꺼번에 요청 가능한 최대 접속 승인 수. 0이나 SOMAXCONN. 요즘은 컴퓨터 성능이 좋아 의미 없음.
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

bool MySocket::ConnectSocket(const char* _ServerIP, int _ConnectPort)
{
	CToSSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "fail Create : " << GetLastError() << std::endl;
	}

	SOCKADDR_IN ClientSocketAddr;
	memset(&ClientSocketAddr, 0, sizeof(SOCKADDR_IN));
	ClientSocketAddr.sin_family = AF_INET;
	ClientSocketAddr.sin_port = htons(_ConnectPort);
	ClientSocketAddr.sin_addr.s_addr = inet_addr(_ServerIP);

	int Result = connect(CToSSocket, (SOCKADDR*)&ClientSocketAddr, sizeof(SOCKADDR_IN));

	if (Result == SOCKET_ERROR)
	{
		std::cout << "fail connect : " << GetLastError() << std::endl;
	}

	return true;
}

bool MySocket::SendSocket()
{
	char Buffer[] = "Nunu";
	int SendBuffer = sizeof(Buffer);
	SendBuffer = send(ClientSocket, Buffer, SendBuffer, 0);
	if (SendBuffer == SOCKET_ERROR)
	{
		std::cout << "Send Error" << GetLastError() << std::endl;
	}
	return true;
}

bool MySocket::RecvSocket()
{
	char	Buffer[1024] = { 0, };
	int RecvBuffer = recv(ClientSocket, Buffer, 1024, 0);
	std::cout << "Recive Message : " << Buffer << std::endl;

	if (RecvBuffer <= 0)
	{
		std::cout << " fail send : " << GetLastError() << std::endl; 
		exit(-1);
		
	}
	return true;
}

void MySocket::SendStruct(SpawnActorInfo Actorinfo)
{
	int SendInt;
	int SendIntLength = sizeof(Actorinfo);
	SendInt = send(ClientSocket, (char*)&SendIntLength, sizeof(int), 0);

	SendInt = send(ClientSocket, (char*)&Actorinfo, sizeof(SpawnActorInfo), 0);

}

SpawnActorInfo MySocket::ReciveStruct(SpawnActorInfo* ActorInfo)
{
	int len = 0;
	recv(ClientSocket, (char*)&len, sizeof(int), 0);

	char Buffer[1024] = { 0, };
	recv(ClientSocket, Buffer, len, 0);

	ActorInfo = (SpawnActorInfo*)Buffer;

	return SpawnActorInfo();
}

