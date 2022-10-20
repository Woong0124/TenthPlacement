#include "MyDB.h"
#include <iostream>
#include <string>



#define Host "localhost"
#define User "root"
#define PW "0000"
#define DB "UE4SocketDB"
#define Port 3306



MyDB::MyDB()
{
	MySql = NULL;
	mysql_init(&mysql);
	SqlResult = NULL;
	SqlRow = NULL;
	SqlStat = true;
}

MyDB::~MyDB()
{
	mysql_close(MySql);
}

bool MyDB::ConnectDataBase()
{
	// Database 연결
	MySql = mysql_real_connect(&mysql, Host, User, PW, DB, Port, NULL, 0);

	// 성공 or 실패 처리
	if (!MySql)
	{
		std::cout << "Connect Failed : Error" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Connect Success\n" << std::endl;
		return true;
	}
}

bool MyDB::QueryTransmission(const char* Value)
{
	// Query 요청
	SqlStat = mysql_query(MySql, Value);

	// Query 실패 시
	if (SqlStat)
	{
		fprintf(stderr, "Query Error : %s", mysql_error(MySql));
		return false;
	}

	return true;
}

bool MyDB::QueryOutput()
{
	// Query 요청 결과 저장
	SqlResult = mysql_store_result(MySql);

	// Query 결과 출력
	while ((SqlRow = mysql_fetch_row(SqlResult)) != NULL)
	{
		for (unsigned int i = 0; i < mysql_num_fields(SqlResult); ++i)
		{
			std::cout << SqlRow[i] << "  ";
		}
		std::cout << std::endl;
	}

	return true;
}

void MyDB::QueryStructInsert(DataStruct* DStruct)
{
	SqlResult = mysql_store_result(MySql);
	SqlRow = mysql_fetch_row(SqlResult);

	for (unsigned int i = 0; i < mysql_num_fields(SqlResult); ++i)
	{
		switch (i)
		{
		case 0:
			DStruct->Key = std::stoi(SqlRow[i]);
			break;
		case 1:
			strcpy_s(DStruct->ActorType, SqlRow[i]);
			break;
		case 2:
			DStruct->LocX = std::stof(SqlRow[i]);
			break;
		case 3:
			DStruct->LocY = std::stof(SqlRow[i]);
			break;
		case 4:
			DStruct->LocZ = std::stof(SqlRow[i]);
			break;
		}
	}
}

void MyDB::QueryInit()
{
	mysql_free_result(SqlResult);
}
