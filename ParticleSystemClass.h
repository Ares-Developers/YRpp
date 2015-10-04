/*
	ParticleSystems
*/

#pragma once

#include <ObjectClass.h>
#include <ParticleSystemTypeClass.h>
#include <ParticleClass.h>

class NOVTABLE ParticleSystemClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::ParticleSystem;

	//Static
	static DynamicVectorClass<ParticleSystemClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParticleSystemClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	ParticleSystemClass(
		ParticleSystemTypeClass* pParticleSystemType,
		const CoordStruct& coords,
		AbstractClass* pTarget,
		TechnoClass* pOwner,
		const CoordStruct& targetCoords,
		HouseClass* pOwnerHouse) noexcept : ParticleSystemClass(noinit_t())
			{ JMP_THIS(0x62DC50); }

protected:
	explicit __forceinline ParticleSystemClass(noinit_t) noexcept
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ParticleSystemTypeClass* Type;
	CoordStruct  SpawnDistanceToOwner;
	DynamicVectorClass<ParticleClass*> Particles;
	CoordStruct TargetCoords;
	TechnoClass* Owner;
	AbstractClass* Target; // CellClass or TechnoClass
	int          SpawnFrames; //from ParSysTypeClass
	int          Lifetime; //from ParSysTypeClass
	int          SparkSpawnFrames; //from ParSysTypeClass
	int          SpotlightRadius; //defaults to 29
	bool         TimeToDie;
	bool         unknown_bool_F9;
	HouseClass*  OwnerHouse;
};
