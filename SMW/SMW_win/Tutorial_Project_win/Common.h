#pragma once
#include <string>



struct SpawnActorInfo
{
	int ID;
	char ActorType[10];
	int x;
	int y;
	int z;

	SpawnActorInfo() { memset(this, 0, sizeof(SpawnActorInfo)); };
};

