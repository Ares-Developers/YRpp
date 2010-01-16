#ifndef RANDOM_H
#define RANDOM_H

class Randomizer
{
	// DO NOT USE THIS!!! Really.
	// Use the ScenarioClass::Random object instead!
	static Randomizer* Global()
		{ return (Randomizer*)0x886B88; }
public:
	DWORD Random()
		{ JMP_THIS(0x65C780); }

	int RandomRanged(int nMin, int nMax)
		{ JMP_THIS(0x65C7E0); }

	Randomizer(DWORD dwSeed = GetTickCount())
		{ JMP_THIS(0x65C6D0); }

	//Properties
	PROPERTY(bool, unknown_00);
	PROPERTY(int, Next1); //from Table
	PROPERTY(int, Next2); //from Table
	PROPERTY_ARRAY(DWORD, Table, 0xFA);
};

#endif
