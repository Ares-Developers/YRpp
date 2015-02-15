#pragma once

class Randomizer
{
public:
	// for any randomization happening inside a match (odds of a survivor, crate, etc), use the ScenarioClass::Random object instead!
	// this object should only be used for RMG and other randomness outside a match
	static Randomizer* Global()
		{ return reinterpret_cast<Randomizer*>(0x886B88); }

public:
	DWORD Random()
		{ JMP_THIS(0x65C780); }

	int RandomRanged(int nMin, int nMax)
		{ JMP_THIS(0x65C7E0); }

	Randomizer(DWORD dwSeed = GetTickCount())
		{ JMP_THIS(0x65C6D0); }

	// helper methods
	double RandomDouble()
	{
		return this->RandomRanged(1, 2147483647) / 2147483648.0;
	}

	//Properties

public:

	bool unknown_00;
	int Next1; //from Table
	int Next2; //from Table
	DWORD Table [0xFA];
};
