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
	//Array
	ABSTRACTTYPE_ARRAY(SuperWeaponTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6CE7C0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6CE800); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6CE8D0); }

	//Destructor
	virtual ~SuperWeaponTypeClass()
		{ THISCALL(0x6CE740); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_SuperWeaponType; }
	virtual int Size()
		{ return sizeof(SuperWeaponTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6CE910); }
	virtual int GetArrayIndex()
		{ return ArrayIndex; }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* ini)
		{ PUSH_VAR32(ini); THISCALL(0x6CEA20); }

	//SuperWeaponTypeClass
	virtual eAction MouseOverObject(DWORD dwUnk, ObjectClass* pObjBelowMouse)
		{ PUSH_VAR32(pObjBelowMouse); PUSH_VAR32(dwUnk); THISCALL(0x6CEF80); }

	// non-virtual
	static SuperWeaponTypeClass *FindFirstOfAction(eAction Action)
		{ SET_REG32(ECX, Action); CALL(0x6CEEB0); }

	//Constructor
	SuperWeaponTypeClass(const char* id):AbstractTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x6CE5B0); }

protected:
	SuperWeaponTypeClass():AbstractTypeClass(false)
		{ }
	SuperWeaponTypeClass(bool X):AbstractTypeClass(X)
		{ }

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
