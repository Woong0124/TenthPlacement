#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <iostream>



int main()
{
	// MYSQL 생성
	MYSQL* MySql = NULL, mysql;

	// 쿼리문 성공 시, 결과 담는 구조체
	MYSQL_RES* SqlResult;

	// 결과의 행 정보
	MYSQL_ROW SqlRow;

	// 쿼리문 성공 여부
	bool SqlStat;

	// MYSQL 초기화
	mysql_init(&mysql);

	// Database 연결
	MySql = mysql_real_connect(&mysql, "localhost", "root", "0000", "UE4SocketDB", 3306, NULL, 0);

	// 성공 or 실패 처리
	if (!MySql)
	{
		std::cout << "Connect Failed : Error" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Connect Success\n" << std::endl;
	}





	// Winsock 로드
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		std::cout << "Winsock Error : " << GetLastError() << std::endl;
		exit(-1);
	}

	// Socket 생성
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::cout << "fail create Socket : " << GetLastError() << std::endl;
		exit(-1);
	}

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
		exit(-1);
	}

	// Socket 수신대기
	BindServerSock = listen(ServerSocket, 0);
	if (BindServerSock == SOCKET_ERROR)
	{
		std::cout << "fail listen : " << GetLastError() << std::endl;
		exit(-1);
	}

	// Client socket 생성
	// 클라이언트 접속 요청 시, 승인해 주는 역할
	SOCKADDR_IN ClientSockAddr;
	memset(&ClientSockAddr, 0, sizeof(SOCKADDR_IN));
	int ClientSockAddrLength = sizeof(ClientSockAddr);

	// Client 접속 승인
	SOCKET ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientSockAddr, &ClientSockAddrLength);
	if (ClientSocket == SOCKET_ERROR)
	{
		std::cout << "fail accept : " << GetLastError() << std::endl;
		exit(-1);
	}





	// Send / Recive
	// 구조체 통신 연습 
	/*StData SendStData;
	SendStData.ActorType = "Sphere";
	SendStData.LocX = 299;
	SendStData.LocY = 199;
	SendStData.LocZ = 399;

	int SendInt;
	int SendIntLength = sizeof(SendStData);

	SendInt = send(ClientSocket, (char*)&SendIntLength, sizeof(int), 0);
	if (SendInt == SOCKET_ERROR)
	{
		std::cout << "Send Error" << std::endl;
		exit(-1);
	}

	SendInt = send(ClientSocket, (char*)&SendStData, sizeof(StData), 0);
	if (SendInt == SOCKET_ERROR)
	{
		std::cout << "Send Error" << std::endl;
		exit(-1);
	}*/





	// Query 요청 (테이블 검색)
	SqlStat = mysql_query(MySql, "SELECT * FROM DATATABLE");

	// Query 실패 시
	if (SqlStat)
	{
		fprintf(stderr, "Query Error : %s", mysql_error(&mysql));
		return 1;
	}

	// Query 요청 결과 저장
	SqlResult = mysql_store_result(MySql);

	// Query 결과 출력
	while ((SqlRow = mysql_fetch_row(SqlResult)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(SqlResult); ++i)
		{
			std::cout << SqlRow[i] << "  ";
		}
		std::cout << std::endl;
	}

	// Query 결과 초기화
	mysql_free_result(SqlResult);





	// Socket 해제
	closesocket(ServerSocket);
	closesocket(ClientSocket);
	WSACleanup();

	// Database 해제
	mysql_close(MySql);
	return 0;
}