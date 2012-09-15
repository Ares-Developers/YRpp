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
	enum {AbsID = abs_Particle};

	//Static
	static DynamicVectorClass<ParticleClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParticleClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//ParticleClass
	virtual int vt_entry_1E8() R0;

	//Constructor
	ParticleClass(
		ParticleTypeClass* pParticleType,
		CoordStruct* pCrd1,
		CoordStruct* pCrd2,
		ParticleSystemClass* pParticleSystem) : ObjectClass(false)
			{ JMP_THIS(0x62B5E0); }

protected:
	ParticleClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ParticleTypeClass* Type;
	BYTE   unknown_B0;
	BYTE   unknown_B1;
	BYTE   unknown_B2;
	DWORD  unknown_B4;
	DWORD  unknown_B8;
	DWORD  unknown_BC;
	DWORD  unknown_C0;
	DWORD  unknown_C4;
	DWORD  unknown_C8;
	DWORD  unknown_CC;
	double unknown_double_D0;
	DWORD  unknown_D8;
	DWORD  unknown_DC;
	DWORD  unknown_E0;
	float  Velocity;
	CoordStruct unknown_coords_E8; //Crd2 in CTOR
	CoordStruct unknown_coords_F4; //Crd1 in CTOR
	CoordStruct unknown_coords_100; //{ 0, 0, 0} in CTOR
	Vector3D<float> unknown_vector3d_10C;
	Vector3D<float> unknown_vector3d_118;
	ParticleSystemClass*   ParticleSystem;
	WORD   RemainingEC;
	WORD   RemainingDC;
	BYTE   StateAIAdvance;
	BYTE   unknown_12D;
	BYTE   StartStateAI;
	BYTE   Translucency;
	BYTE   unknown_130;
	BYTE   unknown_131;
	PROTECTED_PROPERTY(DWORD,        unused_134); //??
};

#endif
