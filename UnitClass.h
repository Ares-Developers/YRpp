/*
	Ground & Naval Vehicles
*/

#ifndef UNIT_H
#define UNIT_H

#include <FootClass.h>
#include <UnitTypeClass.h>

//forward declarations
class EBolt;

class UnitClass : public FootClass
{
public:
	enum {AbsID = abs_Unit};

	//Static
	static DynamicVectorClass<UnitClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~UnitClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//UnitClass
	// main drawing functions - Draw() calles one of these, they call parent's Draw_A_smth
	virtual void DrawAsVXL(Point2D Coords, RectangleStruct BoundingRect, DWORD dwUnk7, DWORD dwUnk8)
		{ JMP_THIS(0x73B470); }

	virtual void DrawAsSHP(Point2D Coords, RectangleStruct BoundingRect, DWORD dwUnk7, DWORD dwUnk8)
		{ JMP_THIS(0x73C5F0); }

	//Constructor
	UnitClass(UnitTypeClass* pType, HouseClass* pOwner) : FootClass(false)
		{ JMP_THIS(0x7353C0); }

protected:
	UnitClass() : FootClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int unknown_int_6C0;
	UnitTypeClass* Type;
	UnitClass* FollowerCar; // groovy - link defined in the map's [Units] section, looked up on startup
	int FlagHouseIndex; //Carrying the flag of this House
	bool HasFollowerCar; // yes, this vehicle has a another vehicle (a train's locomotive towing the cars)
	bool Unloading;
	bool unknown_bool_6D2;
	bool TerrainPalette;
	int unknown_int_6D4;
	int DeathFrameCounter;
	EBolt* ElectricBolt; //Unit is the owner of this
	bool Deployed;
	bool Deploying;
	bool Undeploying;
	int unknown_int_6E4;

	wchar_t ToolTipText[0x100];
};

#endif
