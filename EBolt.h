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
		{ JMP_THIS(0x4C1E10); }

	~EBolt() {/*???*/}

	void Fire(CoordStruct P1, CoordStruct P2, DWORD arg18)
		{ JMP_THIS(0x4C2A60); }

//	static void DeleteAll()
//		JUMP_STD(0x4C2930);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CoordStruct Point1;
	CoordStruct Point2;
	DWORD unknown_18;	//Duration?
	int Random;	//Random number between 0 and 256
	TechnoClass* Owner;
	DWORD unknown_24;
	int Lifetime; // this is >>= 1 each time DrawAll() is called, 0 => dtor (inline). Hi, welcome to dumb ideas.
	bool AlternateColor;

};

#endif
