/*
	Voxel Animations
*/

#pragma once

#include <ObjectClass.h>
#include <VoxelAnimTypeClass.h>
#include <BounceClass.h>

//forward declarations
class HouseClass;
class ParticleSystemClass;

class NOVTABLE VoxelAnimClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::VoxelAnim;

	//Static
	static DynamicVectorClass<VoxelAnimClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~VoxelAnimClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectClass
	//VoxelAnimClass

	//Constructor
	VoxelAnimClass(
		VoxelAnimTypeClass* pVoxelAnimType, CoordStruct* pLocation,
		HouseClass* pOwnerHouse) : VoxelAnimClass(noinit_t())
	{ JMP_THIS(0x7493B0); }

protected:
	explicit __forceinline VoxelAnimClass(noinit_t)
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	PROTECTED_PROPERTY(DWORD, unused_AC);
	BounceClass Bounce;
	int unknown_int_100;
	VoxelAnimTypeClass* Type;
	ParticleSystemClass* AttachedSystem;
	HouseClass* OwnerHouse;
	bool TimeToDie; // remove on next update
	PROTECTED_PROPERTY(BYTE, unused_111[3]);
	AudioController Audio3;
	AudioController Audio4;
	bool Invisible; // don't draw, but Update state anyway
	PROTECTED_PROPERTY(BYTE, unused_13D[3]);
	int Duration; // counting down to zero
	PROTECTED_PROPERTY(DWORD, unused_144);
};
