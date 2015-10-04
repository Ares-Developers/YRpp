/*
	Ground & Naval Vehicles
*/

#pragma once

#include <FootClass.h>
#include <UnitTypeClass.h>

//forward declarations
class EBolt;

class NOVTABLE UnitClass : public FootClass
{
public:
	static const AbstractType AbsID = AbstractType::Unit;

	//Static
	static DynamicVectorClass<UnitClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~UnitClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//UnitClass
	// main drawing functions - Draw() calles one of these, they call parent's Draw_A_smth
	virtual void DrawAsVXL(Point2D Coords, RectangleStruct BoundingRect, DWORD dwUnk7, DWORD dwUnk8)
		{ JMP_THIS(0x73B470); }

	virtual void DrawAsSHP(Point2D Coords, RectangleStruct BoundingRect, DWORD dwUnk7, DWORD dwUnk8)
		{ JMP_THIS(0x73C5F0); }

	// non-virtual

	bool IsDeactivated() const
		{ JMP_THIS(0x70FBD0); }

	//Constructor
	UnitClass(UnitTypeClass* pType, HouseClass* pOwner) noexcept
		: UnitClass(noinit_t())
	{ JMP_THIS(0x7353C0); }

protected:
	explicit __forceinline UnitClass(noinit_t) noexcept
		: FootClass(noinit_t())
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
	int NonPassengerCount; // Set when unloading passengers. Units with TurretCount>0 will not unload the gunner.

	wchar_t ToolTipText[0x100];
};
