#pragma comment (lib, "libmysql.lib")
#pragma comment (lib, "ws2_32.lib")

#include <mysql.h>
#include <iostream>
#include "MyDB.h"
#include "MySocket.h"



int main()
{
	// DB 변수 생성
	MyDB* MyDataBase = new(MyDB);

	// DB 오류 체크
	bool DBCheck;

	// DB 연결
	DBCheck = MyDataBase->ConnectDataBase();
	if (DBCheck == false)
	{
		return 1;
	}





	// 소켓 변수 생성
	MySocket* MySock = new(MySocket);

	// 소켓 오류 체크
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






	while (true)
	{
		DataStruct* DStruct = new DataStruct;
		MyDataBase->QueryTransmission("SELECT * FROM DATATABLE");

		DStruct->AInfo = SpawnActor;
		while ((MyDataBase->SqlRow = mysql_fetch_row(MyDataBase->SqlResult)) != NULL)
		{
			MyDataBase->QueryStructInsert(DStruct);
			MySock->SendStructSocket(DStruct);
			}
		delete DStruct;
	}



	// 테스트 중
	/*while (true)
	{
		char Buffer[1024] = "1";
		int BufferSize = sizeof(Buffer);
		send(MySock->ClientSocket, (char*)Buffer, BufferSize, 0);
	}*/



	//delete DStruct;

	// 소켓 해제
	delete MySock;

	// DB 해제
	delete MyDataBase;

	return 0;
}