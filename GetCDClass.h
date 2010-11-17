#ifndef GETCDCLASS_H_
#define GETCDCLASS_H_

class GetCDClass
{
public:
	static GetCDClass *Instance;

	int Drives[26];
	int Count;
	int unknown_6C;
};

#endif
