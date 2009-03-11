#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include <GeneralStructures.h>

class SpotlightClass
{
public:
	//Static
	static DynamicVectorClass<SpotlightClass*>* Array;

	//Destructor
	~SpotlightClass()
		{ THISCALL(0x5FF2D0); }

	void Draw()
		{	JMP_THIS(0x5FF850); }

	//Constructor
	SpotlightClass(TintStruct ColorTint, int size)
		{ JMP_THIS(0x5FF250); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(TintStruct, Color);
	PROPERTY(int, MovementRadius);
	PROPERTY(int, Size);
	PROPERTY(eSpotlightFlags, DisableFlags);
};

#endif
