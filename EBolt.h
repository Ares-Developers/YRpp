/*
	Electric Bolts
*/

#pragma once

#include <GeneralDefinitions.h>

class UnitClass;

class EBolt
{
public:
	static constexpr constant_ptr<DynamicVectorClass<EBolt*>, 0x8A0E88u> const Array{};

	//Constructor, Destructor
	EBolt()
		{ JMP_THIS(0x4C1E10); }

	~EBolt()
		{ JMP_THIS(0x4C2C10); }

	void SetOwner(UnitClass* pOwner, int idxWeapon)
		{ JMP_THIS(0x4C2BD0); }

	void ClearOwner()
		{ JMP_THIS(0x4C1E50); }

	CoordStruct* GetSourceCoords(CoordStruct* outBuffer) const
		{ JMP_THIS(0x4C2B40); }

	CoordStruct GetSourceCoords() const {
		CoordStruct buffer;
		GetSourceCoords(&buffer);
		return buffer;
	}

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
	TechnoClass* Owner;	//ingame this is a UnitClass but needed to circumvent some issues
	int WeaponSlot; // which weapon # to use from owner
	int Lifetime; // this is >>= 1 each time DrawAll() is called, 0 => dtor (inline). Hi, welcome to dumb ideas.
	bool AlternateColor;

};
