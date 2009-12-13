/*
	SuperWeaponTypes!! =D
*/

#ifndef SUPERWEAPONTYPE_H
#define SUPERWEAPONTYPE_H

#include <FileSystem.h>
#include <AbstractTypeClass.h>

//forward declarations
class BuildingTypeClass;
class ObjectClass;
class WeaponTypeClass;

class SuperWeaponTypeClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_SuperWeaponType};

	//Array
	ABSTRACTTYPE_ARRAY(SuperWeaponTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SuperWeaponTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//SuperWeaponTypeClass
	virtual eAction MouseOverObject(DWORD dwUnk, ObjectClass* pObjBelowMouse) R0;

	// non-virtual
	static SuperWeaponTypeClass * __fastcall FindFirstOfAction(eAction Action)
		JMP_STD(0x6CEEB0);

	//Constructor
	SuperWeaponTypeClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x6CE5B0);

protected:
	SuperWeaponTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,     ArrayIndex);
	PROPERTY(WeaponTypeClass*, WeaponType);

	//I believe these four are the leftover TS sounds
	PROPERTY(int,     unknown_A0);
	PROPERTY(int,     unknown_A4);
	PROPERTY(int,     unknown_A8);
	PROPERTY(int,     unknown_AC);
	//---

	PROPERTY(int,     RechargeTime); //in frames
	PROPERTY(int,     Type); //SWTYPE definitions
	PROPERTY(SHPStruct*, SidebarImage);
	PROPERTY(eAction, Action); //ACTION definitions
	PROPERTY(int,     SpecialSound);
	PROPERTY(int,     StartSound);
	PROPERTY(BuildingTypeClass*, AuxBuilding);
	PROPERTY_STRING(SidebarImageFile, 0x18);
	PROTECTED_PROPERTY(BYTE, zero_E4);
	PROPERTY(bool,    UseChargeDrain);
	PROPERTY(bool,    IsPowered);
	PROPERTY(bool,    DisableableFromShell);
	PROPERTY(int,     FlashSidebarTabFrames);
	PROPERTY(bool,    AIDefendAgainst);
	PROPERTY(bool,    PreClick);
	PROPERTY(bool,    PostClick);
	PROPERTY(SuperWeaponTypeClass*, PreDependent);
	PROPERTY(bool,    ShowTimer);
	PROPERTY(bool,    ManualControl);
	PROPERTY(float,   Range);
	PROPERTY(int,     LineMultiplier);

};

#endif
