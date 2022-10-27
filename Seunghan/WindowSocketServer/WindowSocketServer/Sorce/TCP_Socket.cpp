// 소켓 라이브러리 링크 걸기 구현부를 바이너리화 시킨 파일의 확장자 lib
#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <string.h>
#include "TCP_Socket.h"
#include <iostream>



TCP_Socket::TCP_Socket()
{
	memset(this, 0, sizeof(TCP_Socket));
	_Socket = INVALID_SOCKET;
	_SocketConnected = INVALID_SOCKET;
}

TCP_Socket::~TCP_Socket()
{
	// 소켓을 닫아준다.
	closesocket(_Socket);
	closesocket(_SocketConnected);

	WSACleanup();
}


bool TCP_Socket::InitSocket()
{
	// WSADATA windows 소켓 초기화 정보를 저장하기 위한 구조체
	WSADATA wsaData;

	// 윈도우즈에 어느 소켓을 활용할 것인지 선언
	// 첫 인자는 WORD는 unsigned Short Typedef 이다.
	// 소컷 버전 2.2 버전은 실수 임으로 MAKE WORD를 사용하여 정수로 넣어준다.
	// 두 번째 인자는 WSADATA의 포인터 타입
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cout << " Winsock Error: " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	return true;
}


bool TCP_Socket::CreatSocket()
{
	// 소켓은 핸들이다. 핸들이란 운영체제가 관리하는 커널 오브젝트 중 한 종류이다.
	// OS는 핸들을 이용하여 프로그램의 종류등을 구별한다.

	// TCP 소켓은 크게 2가지로 나뉜다.
	// 첫 번째 다른 컴퓨터로 부터 들어오는 접속 승인 요청을 수락해주는 소켓
	// 두 번째는 다른 컴퓨터와 연결된 소켓이 있어야한다.

	// 컴퓨터는 IP주소라는 개념을 이용하여 해당 컴퓨터의 주소정보를 만들어낸다.
	// IP 주소는 크게 2가지로 나뉜다. IPV4 IPV6
	// IPV4 타입은 32bit 즉 4byte를 활용한다. 일반적으로 사용하는 IP주소이다.
	// IPV4의 표현 한계로 인한 IPV6 타입 16byte 주소 체계를 만들게 되었는다.

	// PF_INET은 IPV4 타입을 만들것이고, SOCK_STREAM은 빨대를 만들어 연결 지향적 소켓을 만들겠다는 의미이다.
	// 마지막 인자는 protocol 즉 통신 규약이 들어간다. TCP를 사용함으로 IPPROTOCOL_TCP를 사용한다고 지정한다.

	_Socket = socket(PF_INET, SOCK_STREAM, 0);
	if (_Socket == INVALID_SOCKET) // 직역하면 유효하지 않은 소켓.
	{
		std::cout << " fail create Socket : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	return true;
}


bool TCP_Socket::BindSocket(const char* _BindIP, int _BindPort)
{
	// 소켓의 구성요소를 담을 구조체 생성 및 값 할당
	// 주소를 구성하는 것은 IP 와 PORT 2가지로 구성된다.
	// IP는 주소 PORT는 구멍이다. 포트를 정확하게 구성해야한다.

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(SOCKADDR_IN));

	// family는 소켓을 연결할 로컬 또는 원격 주소를 지정하는 데 사용된다.
	// 주소 정보를 담아두는 구조체이다.
	// 메모리에 데이터를 저장할 때는 2가지 방식이 있는데, 빅엔디안과 리틀엔디안이란 방식이다.
	// 빅엔디안은 네트워크상 표준 프로토콜, 리틀엔디안은 주로 인텔 프로세스 계열이다.
	// 혹여나 다른 방식을 사용하는 컴퓨터간 데이터를 주고 받게 될 경우 문제가 발생할 수 있으니 네트워크 표준을 사용한다.
	// AF_INET은 UDP TCP등 연결지향형 소켓이면 반드시 AF_INET이어야 함을 알 수 있다.
	ServerSockAddr.sin_family = AF_INET;


	// 서버는 서버 컴퓨터의 IP주소를 넣어야한다.
	// s_addr은 IPv4 internet address이다.
	ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// 포트 번호를 설정한다. 포트는 2바이트 안에서 표현할 수 있는 숫자여야한다.
	// htons host to networkshort 즉 빅엔디안 방식으로 데이터를 변환하여 설정한다.
	ServerSockAddr.sin_port = htons(_BindPort);

	// 바인드 함수는 소켓에 주소 정보를 연결한다.
	// 리슨 소켓의 역할은 접속승인만을 해준다.
	// 첫 인자로는 선언한 소켓을 2번째 인자는 주소정보를 세번째 인자는 두번째 인자로 넣은 구조체의 크기가 들어간다.
	int Result = bind(_Socket, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR_IN));

	if (Result == SOCKET_ERROR)
	{
		std::cout << " fail bind : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}

	return true;
}


bool TCP_Socket::ListenSocket()
{
	// listen 함수는 연결을 수신하는 상태로 소켓의 상태를 변경해준다.
	// 현재 연결을 기다리는 상태가 되는 것이다.
	// 2번째 인자는 한꺼번에 요청 가능한 최대 접속 승인 수를 뜻한다.
	int Result = listen(_Socket, SOMAXCONN);

	if (Result == SOCKET_ERROR)
	{
		std::cout << " fail listen : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	return true;
}

bool TCP_Socket::AcceptSocket()
{
	SOCKADDR_IN ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
	int ClientSockAddrLength = sizeof(ClientSockAddr);
	
	// accept 함수를 이용하여 접속 요청을 수락한다. 이 함수는 동기화된 방식으로 동작한다.
	// 동기화된 방식이란 요청을 마무리하기 전까지는 계속 대기 상태에 놓이는 것을 뜻한다.
	// 즉 요청이 오기전까지는 이 함수는 안빠져나온다.
	// 접속 요청을 승인하면 연결된 소켓이 만들어져서 리턴된다.
	// 첫 인자로는 소켓 두번째 인자로는 승인된 소켓의 주소 세번째는 구조체의 크기가 들어간다.

	_SocketConnected = accept(_Socket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);

	if (_SocketConnected == SOCKET_ERROR)
	{
		std::cout << " fail accept : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	
	return true;
}

bool TCP_Socket::ConnectSocket(const char* _ServerIP, int _ConnectPort)
{
	_ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_Socket == INVALID_SOCKET)
	{
		std::cout << " fail create Socket : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}

	SOCKADDR_IN ClinetSocketAddr;
	memset(&ClinetSocketAddr, 0, sizeof(SOCKADDR_IN));
	ClinetSocketAddr.sin_family = AF_INET;
	ClinetSocketAddr.sin_port = htons(_ConnectPort);
	ClinetSocketAddr.sin_addr.s_addr = inet_addr(_ServerIP);

	int Result = connect(_ServerSocket, (SOCKADDR*)&ClinetSocketAddr, sizeof(SOCKADDR_IN));

	if (Result == SOCKET_ERROR)
	{
		std::cout << " fail connect : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
	}
	return true;
}

bool TCP_Socket::SendSocket()
{
	char	Buffer[] = "1";

	int SendBytes = send(_SocketConnected, Buffer, sizeof(Buffer), 0);

	if (SendBytes <= 0)
	{
		std::cout << " fail recv : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	return true;
}

bool TCP_Socket::ReciveSocket()
{
	// 클라이언트측 정보를 수신하기 위해 기존에 정의해둔 패킷 크기만큼 버퍼를 생성한다.
	// recv(소켓, 수신 정보를 담을 배열 주소, 배열의 크기, flag)
	// recv 함수는 대상 소켓으로부터 보내온 정보를 받아주는 역할을 한다.
	// 보내준 데이터가 없다면 여기서 받을 때까지 계속 대기상태로 있는다.
	// flag 값으로는 활성하지 않음으로 0을 한다.
	char	Buffer[1024] = {0,};
	int RecvBytes = recv(_SocketConnected, Buffer, 1024, 0);

	std::cout << "Recive Message : " << Buffer << std::endl;

	if (RecvBytes <= 0)
	{
		std::cout << " fail send : " << GetLastError() << std::endl; // 마지막 에러 문제 확인
		exit(-1);
		return false;
	}
	return true;
}