#pragma once
#include <string>

struct MyFVector
{
	int x;
	int y;
	int z;
};

struct SpawnActorInfo
{
	int Key;
	std::string Name;
	MyFVector VectorInfo;
};
