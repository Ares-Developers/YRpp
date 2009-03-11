/*
	Electric Bolts
*/

#ifndef EBOLT_H
#define EBOLT_H

#include <GeneralDefinitions.h>

class EBolt
{
public:
	static DynamicVectorClass<EBolt*>* Array;

	//Constructor, Destructor
	EBolt()
		JMP_THIS(0x4C1E10);

	~EBolt() {/*???*/}

	void Fire(CoordStruct P1, CoordStruct P2, DWORD arg18)
		JMP_THIS(0x4C2A60);

//	static void DeleteAll()
//		JUMP_STD(0x4C2930);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY_STRUCT(CoordStruct, Point1);
	PROPERTY_STRUCT(CoordStruct, Point2);
	PROPERTY(DWORD, unknown_18);	//Duration?
	PROPERTY(int, Random);	//Random number between 0 and 256
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(DWORD, unknown_24);
	PROPERTY(int, unknown_int_28);
	PROPERTY(bool, AlternateColor);

};

#endif
