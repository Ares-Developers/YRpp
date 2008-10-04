#ifndef RANDOM_H
#define RANDOM_H

class Randomizer
{
public:
	static Randomizer* Global()
		{ return (Randomizer*)0x886B88; }

	DWORD Random()
		{ THISCALL(0x65C780); }

	int RandomRanged(int nMin, int nMax)
		{
			PUSH_VAR32(nMax);
			PUSH_VAR32(nMin);
			THISCALL(0x65C7E0);
		}

	Randomizer(DWORD dwSeed)
	{
		PUSH_VAR32(dwSeed);
		THISCALL(0x65C6D0);
	}

	//Properties
	PROPERTY(bool, unknown_00);
	PROPERTY(int, Next1); //from Table
	PROPERTY(int, Next2); //from Table
	PROPERTY_ARRAY(DWORD, Table, 0xFA);
};

#endif
