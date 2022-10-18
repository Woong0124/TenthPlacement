// 소켓 라이브러리 링크 걸기 구현부를 바이너리화 시킨 파일의 확장자 lib
#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <stdio.h>
// 소켓 라이브러리 링크 걸기
#include <iostream>
#include "TCP_Socket.h"
#include "MySQL.h"
#include <string>
using namespace std;



#define PORT	4000
#define PACKED_SIZE 1024
#define MyIP "127.0.0.1"

int main()
{
	MySQL* sql = new MySQL;

	SpawnActorInfo a;

	sql->ConncetMySQL();

	sql->RecQueryResult();

	sql->Insert(a);

	TCP_Socket* Socket = new TCP_Socket;

	Socket->InitSocket();

	Socket->CreatSocket();

	Socket->BindSocket(MyIP, 4000);

	Socket->ListenSocket();

	Socket->AcceptSocket();

	Socket->SendStruct(a);



	SpawnActorInfo b;

	b = Socket->ReciveStruct(&b);

	char MSG[100] = {};
	sprintf_s(MSG, "VALUES (%i,\"%s\",%i,%i,%i)", b.Key, b.Name, b.x, b.y, b.z);
	cout << MSG;

	sql->DataTableInsert(MSG);

	Socket->SendStruct(a);

	Socket->ReciveSocket();

	mysql_free_result(sql->mysqlResult);

	delete Socket;
	delete sql;

	return 0;
}