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

};

#endif
