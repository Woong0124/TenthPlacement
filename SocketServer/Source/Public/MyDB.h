#pragma once

#include <mysql.h>
#include "DataStruct.h"

class MyDB
{
public:
	MyDB();
	~MyDB();

	// MYSQL 생성
	MYSQL* MySql;

	// MYSQL 연결 핸들
	MYSQL mysql;

	// 쿼리문 성공 시, 결과 담는 구조체
	MYSQL_RES* SqlResult;

	// 결과의 행 정보
	MYSQL_ROW SqlRow;

	// 쿼리문 성공 여부
	bool SqlStat;

	// DB연결
	bool ConnectDataBase();

	// 쿼리문 전달
	bool QueryTransmission(const char* Value);

	// 쿼리 결과 출력
	bool QueryOutput();

	// 쿼리 결과 구조체에 삽입
	void QueryStructInsert(DataStruct* DStruct);

	// 쿼리 초기화
	void QueryInit();
};