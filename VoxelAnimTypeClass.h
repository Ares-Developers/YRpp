/*
	VoxelAnimTypes are initialized by INI files.
*/

#ifndef VOXELANIMTYPE_H
#define VOXELANIMTYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;
class ParticleSystemTypeClass;
class WarheadTypeClass;

class VoxelAnimTypeClass : public ObjectTypeClass
{
public:
	enum {AbsID = abs_VoxelAnimType};

	//Array
	ABSTRACTTYPE_ARRAY(VoxelAnimTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0; // ! this just returns NULL instead of creating the anim, fucking slackers

	//VoxelAnimTypeClass

	//Destructor
	virtual ~VoxelAnimTypeClass() RX;

	//Constructor
	VoxelAnimTypeClass(const char* pID) : ObjectTypeClass(false)
		{ JMP_THIS(0x74AD80); }

protected:
	VoxelAnimTypeClass() : ObjectTypeClass(false) { };

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

#endif
