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

	PROPERTY(int, unknown_int_6C0);
	PROPERTY(UnitTypeClass*, Type);
	PROPERTY(UnitClass*, FollowerCar); // groovy - link defined in the map's [Units] section, looked up on startup
	PROPERTY(int, FlagHouseIndex); //Carrying the flag of this House
	PROPERTY(bool, HasFollowerCar); // yes, this vehicle has a another vehicle (a train's locomotive towing the cars)
	PROPERTY(bool, Unloading);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(bool, TerrainPalette);
	PROPERTY(int, unknown_int_6D4);
	PROPERTY(int, DeathFrameCounter);
	PROPERTY(EBolt*, ElectricBolt); //Unit is the owner of this
	PROPERTY(bool, Deployed);
	PROPERTY(bool, Deploying);
	PROPERTY(bool, Undeploying);
	PROPERTY(int, unknown_int_6E4);

// isn't this what PROPERTY_UNICODE was for?
protected:
	wchar_t ToolTipText[0x100];

public:
	const wchar_t* get_ToolTipText()
		{ return ToolTipText; }
	void set_ToolTipText(const wchar_t* src)
		{ wcsncpy(ToolTipText, src, 0x100); }
};

#endif
