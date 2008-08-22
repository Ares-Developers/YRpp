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
		{ THISCALL(0x556A20); }

	~LineTrail()
		{ THISCALL(0x556B30); }


	void SetDecrement(int val)
		{ PUSH_VAR32(val); THISCALL(0x556B50); }

	void Update()
		{ THISCALL(0x556B70); }

	void Draw()
		{ THISCALL(0x556C00); }

	static void DrawAll()
		{ CALL(0x556D40); }

	static void DeleteAll()
		{ CALL(0x556DF0); }


	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(ColorStruct,  Color);
	PROPERTY(ObjectClass*, Owner);
	PROPERTY(DWORD,        Decrement);
	PROPERTY(DWORD,        ActiveSlot);
	PROPERTY_STRUCT_ARRAY(LineTrailNode, Trails, 32);
};

#endif
