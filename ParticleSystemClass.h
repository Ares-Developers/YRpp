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
	//Static
	static DynamicVectorClass<ParticleSystemClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6301A0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x62FF20); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x630090); }

	//Destructor
	virtual ~ParticleSystemClass()
		{ THISCALL(0x62E070); }

	//AbstractClass
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x62FE90); }
	virtual eAbstractType WhatAmI()
		{ return abs_ParticleSystem; }
	virtual int Size()
		{ return sizeof(ParticleSystemClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x630100); }
	virtual bool IsDead()
		{ THISCALL(0x62FE60); }
	virtual void Update()
		{ THISCALL(0x62FD60); }

	//ObjectClass
	virtual eLayer InWhichLayer()
		{ return lyr_Ground; }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual void UnInit()
		{ THISCALL(0x6301E0); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x62E280); }

	//Constructor
	ParticleSystemClass(ParticleSystemTypeClass* pParticleSystemType, CoordStruct Crd1, 
	  AbstractClass* pTarget, TechnoClass* pOwner, CoordStruct Crd2, DWORD dwUnk):ObjectClass(false)
		{
			PUSH_VAR32(dwUnk);
			PUSH_PTR(Crd2);
			PUSH_VAR32(pOwner);
			PUSH_VAR32(pTarget);
			PUSH_PTR(Crd1);
			PUSH_VAR32(pParticleSystemType);
			THISCALL(0x62DC50);
		}

protected:
	ParticleSystemClass():ObjectClass(false)
		{ }
	ParticleSystemClass(bool X):ObjectClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ParticleSystemTypeClass*, Type);
	PROPERTY(DWORD, unknown_B0);
	PROPERTY(DWORD, unknown_B4);
	PROPERTY(DWORD, unknown_B8);
	PROPERTY_STRUCT(DynamicVectorClass<ParticleClass*>, Particles);
	PROPERTY_STRUCT(CoordStruct, unknown_coords_D4);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(CellClass*, unknown_cell_E4);
	PROPERTY(int, SpawnFrames); //from ParSysTypeClass
	PROPERTY(int, Lifetime); //from ParSysTypeClass
	PROPERTY(int, SparkSpawnFrames); //from ParSysTypeClass
	PROPERTY(int, unknown_int_F4); //defaults to 29
	PROPERTY(bool, unknown_bool_F8);
	PROPERTY(bool, unknown_bool_F9);
	PROPERTY(DWORD, unknown_FC);
};

#endif
