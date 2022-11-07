#pragma once

#pragma pack(1)
struct Package
{
	int PackSize;
	int Header;
	int Key;
	int X;
	int Y;
	int Z;
};
#pragma pack()

enum PackageHeader
{
	Spawn = 0,
	Move =1,

	None = 9
};