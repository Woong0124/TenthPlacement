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

	SpawnActorInfo a;

	sql->ConncetMySQL();

	sql->RecQueryResult();

	sql->Insert(a);

	cout << a.Key << endl;
	cout << a.Name << endl;
	cout << a.VectorInfo.x << endl;
	cout << a.VectorInfo.y << endl;
	cout << a.VectorInfo.z << endl;


	MySocket* Socket = new MySocket;


	Socket->CreateSocket();


	Socket->BindListenSocket();

	Socket->AcceptSocket();

	Socket->SendSocket();

	Socket->RecvSocket();

	mysql_free_result(sql->mysqlResult);

	delete Socket;
	delete sql;

	return 0;
}