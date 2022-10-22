#pragma once

enum ActiveInfo
{
	SpawnActor = 1,
	MoveActor = 2
};

struct DataStruct
{
	int Key;
	ActiveInfo AInfo;
	char ActorType[50];
	float LocX;
	float LocY;
	float LocZ;

	DataStruct()
	{
		memset(this, 0, sizeof(DataStruct));
	};
};