#pragma once

class GetCDClass
{
public:
	static GetCDClass * const Instance;

	int Drives[26];
	int Count;
	int unknown_6C;
};
