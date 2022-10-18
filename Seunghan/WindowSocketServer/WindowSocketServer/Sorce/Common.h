#pragma once
#include <string>

struct SpawnActorInfo
{
	int Key;
	char Name[10];
	int x;
	int y;
	int z;

	SpawnActorInfo() { Key = 0; x = 0; y = 0; z = 0; Name[10] = {0}; }
};
