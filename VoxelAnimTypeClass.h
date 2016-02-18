/*
	VoxelAnimTypes are initialized by INI files.
*/

#pragma once

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;
class ParticleSystemTypeClass;
class WarheadTypeClass;

class NOVTABLE VoxelAnimTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::VoxelAnimType;

	//Array
	ABSTRACTTYPE_ARRAY(VoxelAnimTypeClass, 0xA8EB28u);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0; // ! this just returns NULL instead of creating the anim, fucking slackers

	//VoxelAnimTypeClass

	//Destructor
	virtual ~VoxelAnimTypeClass() RX;

	//Constructor
	VoxelAnimTypeClass(const char* pID)
		: VoxelAnimTypeClass(noinit_t())
	{ JMP_THIS(0x74AD80); }

protected:
	explicit __forceinline VoxelAnimTypeClass(noinit_t)
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	bool Normalized;
	bool Translucent;
	bool SourceShared;
	PROTECTED_PROPERTY(BYTE, unused_297);
	int VoxelIndex;
	int Duration;
	double Elasticity;
	double MinAngularVelocity;
	double MaxAngularVelocity;
	double MinZVel;
	double MaxZVel;
	double MaxXYVel;
	bool IsMeteor;
	PROTECTED_PROPERTY(BYTE, unused_2D1[3]);
	VoxelAnimTypeClass* Spawns;
	int SpawnCount;
	int StartSound;
	int StopSound;
	AnimTypeClass* BounceAnim;
	AnimTypeClass* ExpireAnim;
	AnimTypeClass* TrailerAnim;
	int Damage;
	int DamageRadius;
	WarheadTypeClass* Warhead;
	ParticleSystemTypeClass* AttachedSystem;
	bool IsTiberium;
	PROTECTED_PROPERTY(BYTE, unused_301[3]);
};
