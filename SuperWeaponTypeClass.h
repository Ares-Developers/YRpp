/*
	SuperWeaponTypes!! =D
*/

#pragma once

#include <FileSystem.h>
#include <AbstractTypeClass.h>

//forward declarations
class BuildingTypeClass;
class ObjectClass;
class WeaponTypeClass;

class NOVTABLE SuperWeaponTypeClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::SuperWeaponType;

	//Array
	ABSTRACTTYPE_ARRAY(SuperWeaponTypeClass, 0xA8E330u);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SuperWeaponTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//SuperWeaponTypeClass
	virtual Action MouseOverObject(CellStruct const& cell, ObjectClass* pObjBelowMouse) const RT(::Action);

	// non-virtual
	static SuperWeaponTypeClass * __fastcall FindFirstOfAction(Action Action)
		{ JMP_STD(0x6CEEB0); }

	//Constructor
	SuperWeaponTypeClass(const char* pID) noexcept
		: SuperWeaponTypeClass(noinit_t())
	{ JMP_THIS(0x6CE5B0); }

protected:
	explicit __forceinline SuperWeaponTypeClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

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
	SuperWeaponType Type;
	SHPStruct* SidebarImage;
	Action Action;
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
