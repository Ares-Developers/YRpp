/*
	ParticleSystems
*/

#ifndef PARTICLESYS_H
#define PARTICLESYS_H

#include <ObjectClass.h>
#include <ParticleSystemTypeClass.h>

class ParticleSystemClass : public ObjectClass
{
public:
	enum {AbsID = abs_ParticleSystem};

	//Static
	static DynamicVectorClass<ParticleSystemClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParticleSystemClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	ParticleSystemClass(
		ParticleSystemTypeClass* pParticleSystemType,
		CoordStruct Crd1, 
		AbstractClass* pTarget,
		TechnoClass* pOwner,
		CoordStruct Crd2,
		DWORD dwUnk) : ObjectClass(false)
			JMP_THIS(0x62DC50);

protected:
	ParticleSystemClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ParticleSystemTypeClass*, Type);
	PROPERTY(DWORD,        unknown_B0);
	PROPERTY(DWORD,        unknown_B4);
	PROPERTY(DWORD,        unknown_B8);
	PROPERTY_STRUCT(DynamicVectorClass<ParticleClass*>, Particles);
	PROPERTY_STRUCT(CoordStruct, unknown_coords_D4);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(CellClass*,   unknown_cell_E4);
	PROPERTY(int,          SpawnFrames); //from ParSysTypeClass
	PROPERTY(int,          Lifetime); //from ParSysTypeClass
	PROPERTY(int,          SparkSpawnFrames); //from ParSysTypeClass
	PROPERTY(int,          unknown_int_F4); //defaults to 29
	PROPERTY(bool,         unknown_bool_F8);
	PROPERTY(bool,         unknown_bool_F9);
	PROPERTY(DWORD,        unknown_FC);
};

#endif
