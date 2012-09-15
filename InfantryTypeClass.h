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
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//Constructor
	InfantryTypeClass(const char* pID) : TechnoTypeClass(false)
		{ JMP_THIS(0x5236A0); }

protected:
	//default contructor, only used by polymorphism
	InfantryTypeClass() : TechnoTypeClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int Pip; //see PIP definitions
	int OccupyPip; //see PIP definitions
	WeaponStruct OccupyWeapon;
	WeaponStruct EliteOccupyWeapon;
	SequenceStruct* Sequence;
	int FireUp;
	int FireProne;
	int SecondaryFire;
	int SecondaryProne;
	TypeList<AnimTypeClass*> DeadBodies;
	TypeList<AnimTypeClass*> DeathAnims;
	TypeList<int> VoiceComment;
	int EnterWaterSound;
	int LeaveWaterSound;
	bool Cyborg;
	bool NotHuman;
	bool Ivan; //used for the bomb attack cursor...
	int DirectionDistance;
	bool Occupier;
	bool Assaulter;
	int HarvestRate;
	bool Fearless;
	bool Crawls;
	bool Infiltrate;
	bool Fraidycat;
	bool TiberiumProof;
	bool Civilian;
	bool C4;
	bool Engineer;
	bool Agent;
	bool Thief;
	bool VehicleThief;
	bool Doggie;
	bool Deployer;
	bool DeployedCrushable;
	bool UseOwnName;
	bool JumpJetTurn;
private: DWORD align_ECC;
};

#endif
