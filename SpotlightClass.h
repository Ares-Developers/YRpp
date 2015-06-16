#pragma once

#include <GeneralStructures.h>

class SpotlightClass
{
public:
	//Static
	static DynamicVectorClass<SpotlightClass*>* const Array;

	//Destructor
	~SpotlightClass()
		{ THISCALL(0x5FF2D0); }

	void Draw()
		{ JMP_THIS(0x5FF850); }

	void Update()
		{ JMP_THIS(0x5FF320); }

	//Constructor
	SpotlightClass(CoordStruct coords, int size)
		{ JMP_THIS(0x5FF250); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CoordStruct Coords;
	int MovementRadius;
	int Size;
	SpotlightFlags DisableFlags;
};
