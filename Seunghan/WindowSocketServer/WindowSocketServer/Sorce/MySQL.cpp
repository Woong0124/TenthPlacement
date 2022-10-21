#include "MySQL.h"
#pragma comment (lib, "libmysql.lib")
#include <iostream>
#include <mysql.h>



using namespace std;

MySQL::MySQL()
{

	mysql_init(&conn);				// MySQL 정보 초기화
}

MySQL::~MySQL()
{

	mysql_close(ConnPtr);			// MySQL 연결 해제
}

bool MySQL::ConncetMySQL()
{	// 데이터 베이스와 연결
	ConnPtr = mysql_real_connect(&conn, "localhost", "root", "Mytmdgh0910!", "seung0910", 3306, NULL, 0);

	// 연결 결과 확인 Null일 경우 실패
	if (ConnPtr == NULL)
	{
		std::cout << stderr << "Mysql Connection Error : " << mysql_error(&conn);
		return false;
	}

	return true;
}

bool MySQL::RecQueryResult()
{
	// 쿼리 요청 (테이블 검색)
	const char* Query = "SELECT * FROM seunghan9";
	Stat = mysql_query(ConnPtr, Query);
	if (Stat != 0)
	{
		std::cout << stderr << "Mysql Connection Error : " << mysql_error(&conn);
		return false;
	}

	// 요청 결과 저장
	mysqlResult = mysql_store_result(ConnPtr);

	return true;
}

void MySQL::OutResult()
{
	while ((Row = mysql_fetch_row(mysqlResult)) != NULL)
	{
		for (unsigned int i = 0; i < mysql_num_fields(mysqlResult); ++i)
		{
			std::cout << Row[i] << "  ";
		}
		std::cout << std::endl;
	}
}

void MySQL::Insert(SpawnActorInfo& ActorInfo)
{
	//while ((Row = mysql_fetch_row(mysqlResult)) != NULL)
	//{
	Row = mysql_fetch_row(mysqlResult);

	for (unsigned int i = 0; i < mysql_num_fields(mysqlResult); ++i)
	{
		switch (i)
		{
		case 0:
			ActorInfo.Key = stoi(Row[i]);
			break;
		case 1:
			strcpy_s(ActorInfo.Name, Row[i]);
			break;
		case 2:
			ActorInfo.x = stoi(Row[i]);
			break;
		case 3:
			ActorInfo.y = stoi(Row[i]);
			break;
		case 4:
			ActorInfo.z = stoi(Row[i]);
			break;
		}
	}
}

void MySQL::DataTableInsert(const char* value)
{
	char InsertQuery[100] = "insert into seunghan9 ";
	strcat_s(InsertQuery, value);
	cout << InsertQuery << endl;
	mysql_query(ConnPtr, InsertQuery);
}


