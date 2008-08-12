/*
	AnimTypes are initialized by INI files.
*/

#ifndef INFANTRYTYPE_H
#define INFANTRYTYPE_H

#include <TechnoTypeClass.h>

//forward declarations
struct SequenceStruct;

class InfantryTypeClass : public TechnoTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(InfantryTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x524C70); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x524960); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x524B60); }

	//Destructor
	virtual ~InfantryTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x524D70); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_InfantryType; }
	virtual int Size()
		{ return sizeof(InfantryTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x524840); }
	virtual int GetArrayIndex()
		{ return ArrayIndex; }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x5240A0); }

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest, CoordStruct* pSrc)
		{ PUSH_VAR32(pSrc); PUSH_VAR32(pDest); THISCALL(0x5247D0); }

	virtual void vt_entry_7C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x524760); }
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner)
		{ PUSH_VAR32(pMapCoords); PUSH_VAR32(pOwner); THISCALL(0x523B40); }
	virtual InfantryClass* CreateObject(HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); THISCALL(0x523B10); }
	virtual void vt_entry_90(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x523C20); }

	//TechnoTypeClass
	virtual int vt_entry_B4()
		{ return 0; }
	virtual int GetRepairStep()
		{ return RulesClass::Global()->get_IRepairStep(); }

	//Constructor
	InfantryTypeClass(const char* pID):TechnoTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x5236A0); }

protected:
	//default contructor, only used by polymorphism
	InfantryTypeClass():TechnoTypeClass(false)
		{ }
	InfantryTypeClass(bool X):TechnoTypeClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int, Pip); //see PIP definitions
	PROPERTY(int, OccupyPip); //see PIP definitions
	PROPERTY_STRUCT(WeaponStruct, OccupyWeapon);
	PROPERTY_STRUCT(WeaponStruct, EliteOccupyWeapon);
	PROPERTY(SequenceStruct*, Sequence);
	PROPERTY(int, FireUp);
	PROPERTY(int, FireProne);
	PROPERTY(int, SecondaryFire);
	PROPERTY(int, SecondaryProne);
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, DeadBodies);
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, DeathAnims);
	PROPERTY_STRUCT(TypeList<int>, VoiceComment);
	PROPERTY(int, EnterWaterSound);
	PROPERTY(int, LeaveWaterSound);
	PROPERTY(bool, Cyborg);
	PROPERTY(bool, NotHuman);
	PROPERTY(bool, Ivan); //used for the bomb attack cursor...
	PROPERTY(int, DirectionDistance);
	PROPERTY(bool, Occupier);
	PROPERTY(bool, Assaulter);
	PROPERTY(int, HarvestRate);
	PROPERTY(bool, Fearless);
	PROPERTY(bool, Crawls);
	PROPERTY(bool, Infiltrate);
	PROPERTY(bool, Fraidycat);
	PROPERTY(bool, TiberiumProof);
	PROPERTY(bool, Civilian);
	PROPERTY(bool, C4);
	PROPERTY(bool, Engineer);
	PROPERTY(bool, Agent);
	PROPERTY(bool, Thief);
	PROPERTY(bool, VehicleThief);
	PROPERTY(bool, Doggie);
	PROPERTY(bool, Deployer);
	PROPERTY(bool, DeployedCrushable);
	PROPERTY(bool, UseOwnName);
	PROPERTY(bool, JumpJetTurn);
private: DWORD align_ECC;
};

#endif
