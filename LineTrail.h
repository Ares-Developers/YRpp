#ifndef LINETRAIL_H
#define LINETRAIL_H

#include <GeneralDefinitions.h>

struct LineTrailNode
{
	CoordStruct Position;
	DWORD unknown;
};

class LineTrail
{
public:
	static DynamicVectorClass<LineTrail*>* Array;

	//Constructor, Destructor
	LineTrail()
		JMP_THIS(0x556A20);

	~LineTrail()
		JMP_THIS(0x556B30);

	void SetDecrement(int val)
		JMP_THIS(0x556B50);

	static void DeleteAll()
		JMP_STD(0x556DF0);


	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(ColorStruct, Color);
	PROPERTY(ObjectClass*, Owner);
	PROPERTY(DWORD, Decrement);
	PROPERTY(DWORD, ActiveSlot);
	PROPERTY_STRUCT_ARRAY(LineTrailNode, Trails, 32);
};

#endif
