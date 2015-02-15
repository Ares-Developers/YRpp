#pragma once

class GetCDClass
{
public:
	static GetCDClass *Instance;

	int Drives[26];
	int Count;
	int unknown_6C;
};
