#include "MySQL.h"
#pragma comment (lib, "libmysql.lib")
#include <iostream>
#include <mysql.h>



using namespace std;

MySQL::MySQL()
{
	memset(this, 0, sizeof(MySQL)); //(객체, 값, 사이즈(어디까지 초기화 할 것인지)
	mysql_init(&conn);				// MySQL 정보 초기화
}

MySQL::~MySQL()
{

	mysql_close(ConnPtr);			// MySQL 연결 해제
}

bool MySQL::ConncetMySQL()
{	// 데이터 베이스와 연결
	ConnPtr = mysql_real_connect(&conn, "localhost", "root", "smwbs1570", "tutorial", 3307, NULL, 0);

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
	const char* Query = "SELECT * FROM tosocketdb";
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

	// 요청 결과 출력
	while ((Row = mysql_fetch_row(mysqlResult)) != NULL)
	{
		for (int i = 0; i < mysql_num_fields(mysqlResult); ++i)
		{
			cout << Row[i] << "  ";
		}
		cout << endl;
	}
}
void MySQL::Insert(SpawnActorInfo& ActorInfo)
{
	
	Row = mysql_fetch_row(mysqlResult);

	for (unsigned int i = 0; i < mysql_num_fields(mysqlResult); ++i)
	{
		switch (i)
		{
		case 0:
			ActorInfo.Key = stoi(Row[i]);
			break;
		case 1:
			ActorInfo.Name = Row[i];
			break;
		case 2:
			ActorInfo.VectorInfo.x = stoi(Row[i]);
			break;
		case 3:
			ActorInfo.VectorInfo.y = stoi(Row[i]);
			break;
		case 4:
			ActorInfo.VectorInfo.z = stoi(Row[i]);
			break;

		}


	}
}
