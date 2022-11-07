#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <stdio.h>
// 소켓 라이브러리 링크 걸기
#include <iostream>
#include "MySocket.h"
#include "MySQL.h"
#include <string>
using namespace std;



#define PORT	3307
#define PACKED_SIZE 1024
#define MyIP "127.0.0.1"

int main()
{


	MySQL* sql = new MySQL;

	Package a;

	sql->ConncetMySQL();
	

	sql->RecQueryResult();

	sql->Insert(a);

	


	MySocket* Socket = new MySocket;

	Socket->InitSocket();

	Socket->CreateSocket();


	Socket->BindSocket(MyIP,3307);

	Socket->ListenSocket();

	Socket->AcceptSocket();

	Socket->ReciveSocket();

	Socket->SendSocket();

	

	mysql_free_result(sql->mysqlResult);

	delete Socket;
	delete sql;

	return 0;
}