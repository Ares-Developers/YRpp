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
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SuperWeaponTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//SuperWeaponTypeClass
	virtual eAction MouseOverObject(DWORD dwUnk, ObjectClass* pObjBelowMouse) const R0;

	// non-virtual
	static SuperWeaponTypeClass * __fastcall FindFirstOfAction(eAction Action)
		{ JMP_STD(0x6CEEB0); }

	//Constructor
	SuperWeaponTypeClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x6CE5B0); }

protected:
	SuperWeaponTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int     ArrayIndex;
	WeaponTypeClass* WeaponType;

	//I believe these four are the leftover TS sounds
	int     RechargeVoice; // not read, unused
	int     ChargingVoice; // not read, unused
	int     ImpatientVoice; // not read, unused
	int     SuspendVoice; // not read, unused
	//---

	int     RechargeTime; //in frames
	int     Type; //SWTYPE definitions
	SHPStruct* SidebarImage;
	eAction Action; //ACTION definitions
	int     SpecialSound;
	int     StartSound;
	BuildingTypeClass* AuxBuilding;
	char SidebarImageFile [0x18];
	PROTECTED_PROPERTY(BYTE, zero_E4);
	bool    UseChargeDrain;
	bool    IsPowered;
	bool    DisableableFromShell;
	int     FlashSidebarTabFrames;
	bool    AIDefendAgainst;
	bool    PreClick;
	bool    PostClick;
	int		PreDependent;
	bool    ShowTimer;
	bool    ManualControl;
	float   Range;
	int     LineMultiplier;

};

#endif
