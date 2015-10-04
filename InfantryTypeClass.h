/*
	AnimTypes are initialized by INI files.
*/

#pragma once

#include <TechnoTypeClass.h>

struct SubSequenceStruct
{
	int StartFrame;
	int CountFrames;
	int FacingMultiplier;
	SequenceFacing Facing;
	int SoundCount;
	int Sound1StartFrame;
	int Sound1Index; // VocClass
	int Sound2StartFrame;
	int Sound2Index; // VocClass
};

struct SequenceStruct
{
	SubSequenceStruct& GetSequence(Sequence sequence) {
		return this->Sequences[static_cast<int>(sequence)];
	}

	const SubSequenceStruct& GetSequence(Sequence sequence) const {
		return this->Sequences[static_cast<int>(sequence)];
	}

	SubSequenceStruct Sequences[42];
};

class NOVTABLE InfantryTypeClass : public TechnoTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::InfantryType;

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
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//Constructor
	InfantryTypeClass(const char* pID) noexcept
		: InfantryTypeClass(noinit_t())
	{ JMP_THIS(0x5236A0); }

protected:
	explicit __forceinline InfantryTypeClass(noinit_t) noexcept
		: TechnoTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int ArrayIndex;
	PipIndex Pip;
	PipIndex OccupyPip;
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
