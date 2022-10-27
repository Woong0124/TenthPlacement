#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <iostream>
#include "MyDB.h"
#include "MySocket.h"



int main()
{
	// DB 函荐 积己
	MyDB* MyDataBase = new(MyDB);

	// DB 坷幅 眉农
	bool DBCheck;

	// DB 楷搬
	DBCheck = MyDataBase->ConnectDataBase();
	if (DBCheck == false)
	{
		return 1;
	}





	// 家南 函荐 积己
	MySocket* MySock = new(MySocket);

	// 家南 坷幅 眉农
	bool SocketCheck;

	// Socket
	SocketCheck = MySock->CreateSocket();
	if (SocketCheck == false)
	{
		exit(-1);
	}

	// Bind, Listen
	SocketCheck = MySock->BindListenSocket();
	if (SocketCheck == false)
	{
		exit(-1);
	}

	// Accept
	SocketCheck = MySock->AcceptSocket();
	if (SocketCheck == false)
	{
		exit(-1);
	}





	DataStruct* DStruct = new DataStruct;

	while (true)
	{
		MyDataBase->QueryTransmission("SELECT * FROM DATATABLE");

		DStruct->AInfo = SpawnActor;
		while ((MyDataBase->SqlRow = mysql_fetch_row(MyDataBase->SqlResult)) != NULL)
		{
			MyDataBase->QueryStructInsert(DStruct);
			MySock->SendStructSocket(DStruct);
		}

		DStruct->Key = 9;
		DStruct->AInfo = MoveActor;
		DStruct->LocX = 1;
		DStruct->LocY = 0;
		DStruct->LocZ = 0;

		MySock->SendStructSocket(DStruct);
	}

	delete DStruct;



	// 家南 秦力
	delete MySock;

	// DB 秦力
	delete MyDataBase;

	return 0;
}