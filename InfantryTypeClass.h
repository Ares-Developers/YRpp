/*
	AnimTypes are initialized by INI files.
*/

#ifndef INFANTRYTYPE_H
#define INFANTRYTYPE_H

#include <TechnoTypeClass.h>

struct SubSequenceStruct
{
	int StartFrame;
	int CountFrames;
	int FacingMultiplier;
	eSequenceFacing Facing;
	int SoundCount;
	int Sound1StartFrame;
	int Sound1Index; // VocClass
	int Sound2StartFrame;
	int Sound2Index; // VocClass
};

struct SequenceStruct
{
	SubSequenceStruct Sequences[42];
};

class InfantryTypeClass : public TechnoTypeClass
{
public:
	enum {AbsID = abs_InfantryType};

	//Array
	ABSTRACTTYPE_ARRAY(InfantryTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~InfantryTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//Constructor
	InfantryTypeClass(const char* pID) : TechnoTypeClass(false)
		JMP_THIS(0x5236A0);

protected:
	//default contructor, only used by polymorphism
	InfantryTypeClass() : TechnoTypeClass(false)
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
