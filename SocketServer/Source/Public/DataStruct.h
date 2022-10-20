#pragma once

struct DataStruct
{
	int Key;
	char ActorType[50];
	float LocX;
	float LocY;
	float LocZ;

	DataStruct()
	{
		memset(this, 0, sizeof(DataStruct));
	};
};