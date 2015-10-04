#pragma once

#include <TechnoTypeClass.h>

class NOVTABLE AircraftTypeClass : public TechnoTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::AircraftType;

	//Array
	ABSTRACTTYPE_ARRAY(AircraftTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~AircraftTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//TechnoTypeClass

	//Constructor
	AircraftTypeClass(const char* pID) noexcept
		: AircraftTypeClass(noinit_t())
	{ JMP_THIS(0x41C8B0); }

protected:
	explicit __forceinline AircraftTypeClass(noinit_t) noexcept
		: TechnoTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int ArrayIndex;
	bool Carryall;
	AnimTypeClass* Trailer;
	int SpawnDelay;
	bool Rotors;
	bool CustomRotor;
	bool Landable;
	bool FlyBy;
	bool FlyBack;
	bool AirportBound;
	bool Fighter;
};
