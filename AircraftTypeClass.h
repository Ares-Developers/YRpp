#ifndef AIRCRAFTTYPE_H
#define AIRCRAFTTYPE_H

#include <TechnoTypeClass.h>

class AircraftTypeClass : public TechnoTypeClass
{
public:
	enum {AbsID = abs_AircraftType};

	//Array
	ABSTRACTTYPE_ARRAY(AircraftTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~AircraftTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//TechnoTypeClass

	//Constructor
	AircraftTypeClass(const char* pID) : TechnoTypeClass(false)
		JMP_THIS(0x41C8B0);

protected:
	//default contructor, only used by polymorphism
	AircraftTypeClass() : TechnoTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(bool, Carryall);
	PROPERTY(AnimTypeClass*, Trailer);
	PROPERTY(int, SpawnDelay);
	PROPERTY(bool, Rotors);
	PROPERTY(bool, CustomRotor);
	PROPERTY(bool, Landable);
	PROPERTY(bool, FlyBy);
	PROPERTY(bool, FlyBack);
	PROPERTY(bool, AirportBound);
	PROPERTY(bool, Fighter);
};

#endif
