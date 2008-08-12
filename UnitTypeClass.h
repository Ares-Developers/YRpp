#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <TechnoTypeClass.h>

class UnitTypeClass : public TechnoTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(UnitTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x747F30); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x748010); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x7480B0); }

	//Destructor
	virtual ~UnitTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x748190); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_UnitType; }
	virtual int Size()
		{ return sizeof(UnitTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x747F70); }
	virtual int GetArrayIndex()
		{ return ArrayIndex; }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x747620); }

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest, CoordStruct* pSrc)
		{ PUSH_VAR32(pSrc); PUSH_VAR32(pDest); THISCALL(0x747EB0); }

	virtual void vt_entry_78(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x747590); }
	virtual void vt_entry_7C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x7475D0); }
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner)
		{ PUSH_VAR32(pMapCoords); PUSH_VAR32(pOwner); THISCALL(0x7474B0); }
	virtual UnitClass* CreateObject(HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); THISCALL(0x747560); }
	virtual void vt_entry_90(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x41CB70); }

	//TechnoTypeClass
	virtual int GetRepairStep()
		{ return RulesClass::Global()->get_RepairStep(); }

	//Constructor
	UnitTypeClass(const char* id):TechnoTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x7470D0); }

protected:
	//default contructor, only used by polymorphism
	UnitTypeClass():TechnoTypeClass(false)
		{ }
	UnitTypeClass(bool X):TechnoTypeClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(eLandType, MovementRestrictedTo);
	PROPERTY_STRUCT(CoordStruct, HalfDamageSmokeLocation);
	PROPERTY(bool, Passive);
	PROPERTY(bool, CrateGoodie);
	PROPERTY(bool, Harvester);
	PROPERTY(bool, Weeder);
	PROPERTY(bool, unknown_E10);
	PROPERTY(bool, HasTurret); //not read from the INIs
	PROPERTY(bool, DeployToFire);
	PROPERTY(bool, IsSimpleDeployer);
	PROPERTY(bool, IsTilter);
	PROPERTY(bool, UseTurretShadow);
	PROPERTY(bool, TooBigToFitUnderBridge);
	PROPERTY(bool, CanBeach);
	PROPERTY(bool, SmallVisceroid);
	PROPERTY(bool, LargeVisceroid);
	PROPERTY(bool, CarriesCrate);
	PROPERTY(bool, NonVehicle);
	PROPERTY(int, StandingFrames);
	PROPERTY(int, DeathFrames);
	PROPERTY(int, DeathFrameRate);
	PROPERTY(int, StartStandFrame);
	PROPERTY(int, StartWalkFrame);
	PROPERTY(int, StartFiringFrame);
	PROPERTY(int, StartDeathFrame);
	PROPERTY(int, MaxDeathCounter);
	PROPERTY(int, Facings);
	PROPERTY(int, FiringSyncFrame0);
	PROPERTY(int, FiringSyncFrame1);
	PROPERTY(int, BurstDelay0);
	PROPERTY(int, BurstDelay1);
	PROPERTY(int, BurstDelay2);
	PROPERTY(int, BurstDelay3);
	PROPERTY(SHPStruct*, AltImage);
	PROPERTY(char, WalkFrames);
	PROPERTY(char, FiringFrames);
	PROPERTY_STRING(AltImageFile, 0x19);
};

#endif
