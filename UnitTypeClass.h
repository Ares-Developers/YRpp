#ifndef UNITTYPE_H
#define UNITTYPE_H

#include <TechnoTypeClass.h>

class UnitTypeClass : public TechnoTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(UnitTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~UnitTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner)
		{ PUSH_VAR32(pMapCoords); PUSH_VAR32(pOwner); THISCALL(0x7474B0); }
	virtual TechnoClass* CreateObject(HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); THISCALL(0x747560); }

	//TechnoTypeClass

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
