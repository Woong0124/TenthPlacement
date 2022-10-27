#pragma once

#pragma comment (lib, "libmysql.lib")

#include <string>
#include <mysql.h>
#include "Common.h"

class MySQL
{
public:
	MySQL();
	~MySQL();

public:
	// MySQL 정보를 담을 구조체
	MYSQL conn;
	// MySQL 핸들
	MYSQL* ConnPtr = NULL;
	// 쿼리 성공시 결과를 담는 구조체 포인터
	MYSQL_RES* mysqlResult;
	// 쿼리 성공시 결과로 나온 행의 정보를 담는 구조체
	MYSQL_ROW Row;
	// 쿼리 요청 후 결과 (성공, 실패)
	int Stat;

public:
	// Query 연결
	bool ConncetMySQL();
	// Query 결과 받기
	bool RecQueryResult();
	// Query 결과 출력
	void OutResult();

	void Insert(Package& Package);

	void DataTableInsert(const char* value);
};

