/*
	Particles
*/

#ifndef PARTICLE_H
#define PARTICLE_H

#include <ObjectClass.h>
#include <ParticleTypeClass.h>

//forward declarations
class ParticleSystemClass;

class ParticleClass : public ObjectClass
{
public:
	//Static
	static DynamicVectorClass<ParticleClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParticleClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ParticleClass
	virtual int vt_entry_1E8() R0;

	//Constructor
	ParticleClass(
		ParticleTypeClass* pParticleType,
		CoordStruct* pCrd1,
		CoordStruct* pCrd2,
		ParticleSystemClass* pParticleSystem) : ObjectClass(false)
			JMP_THIS(0x62B5E0);

protected:
	ParticleClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ParticleTypeClass*, Type);
	PROPERTY(BYTE,   unknown_B0);
	PROPERTY(BYTE,   unknown_B1);
	PROPERTY(BYTE,   unknown_B2);
	PROPERTY(DWORD,  unknown_B4);
	PROPERTY(DWORD,  unknown_B8);
	PROPERTY(DWORD,  unknown_BC);
	PROPERTY(DWORD,  unknown_C0);
	PROPERTY(DWORD,  unknown_C4);
	PROPERTY(DWORD,  unknown_C8);
	PROPERTY(DWORD,  unknown_CC);
	PROPERTY(double, unknown_double_D0);
	PROPERTY(DWORD,  unknown_D8);
	PROPERTY(DWORD,  unknown_DC);
	PROPERTY(DWORD,  unknown_E0);
	PROPERTY(float,  Velocity);
	PROPERTY_STRUCT(CoordStruct,     unknown_coords_E4); //Crd2 in CTOR
	PROPERTY(DWORD,  unknown_F0); //unused
	PROPERTY_STRUCT(CoordStruct,     unknown_coords_F4); //Crd1 in CTOR
	PROPERTY_STRUCT(CoordStruct,     unknown_coords_100); //{ 0, 0, 0} in CTOR
	PROPERTY_STRUCT(Vector3D<float>, unknown_vector3d_10C);
	PROPERTY_STRUCT(Vector3D<float>, unknown_vector3d_118);
	PROPERTY(ParticleSystemClass*,   ParticleSystem);
	PROPERTY(BYTE,   StateAIAdvance);
	PROPERTY(BYTE,   unknown_12D);
	PROPERTY(BYTE,   StartStateAI);
	PROPERTY(BYTE,   Translucency);
	PROPERTY(BYTE,   unknown_130);
	PROPERTY(BYTE,   unknown_131);
	PROTECTED_PROPERTY(DWORD,        unused_134); //??
};

#endif
