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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x62D930, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x62D7A0, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x62D810, HRESULT); }

	//Destructor
	virtual ~ParticleClass()
		{ THISCALL(0x62BCC0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_Particle; }
	virtual int Size()
		{ return sizeof(ParticleClass); }

	//ObjectClass
	virtual eLayer InWhichLayer()
		{ return lyr_Air; }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual DWORD vt_entry_108(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x62D710, DWORD); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x62CEC0); }
	virtual bool SetLayer(eLayer nValue)
		{ PUSH_VAR32(nValue); THISCALL_RET(0x62D6F0, bool); }

	//ParticleClass
	virtual int vt_entry_1E8()
		{ THISCALL_RET(0x62D830, int); }

	//Constructor
	ParticleClass(ParticleTypeClass* pParticleType, CoordStruct Crd1, CoordStruct Crd2,
	  ParticleSystemClass* pParticleSystem):ObjectClass(false)
		{
			PUSH_VAR32(pParticleSystem);
			PUSH_PTR(Crd2);
			PUSH_PTR(Crd1);
			PUSH_VAR32(pParticleType);
			THISCALL(0x62B5E0);
		}

protected:
	ParticleClass():ObjectClass(false)
		{ }
	ParticleClass(bool X):ObjectClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ParticleTypeClass*, Type);
	PROPERTY(BYTE, unknown_B0);
	PROPERTY(BYTE, unknown_B1);
	PROPERTY(BYTE, unknown_B2);
	PROPERTY(DWORD, unknown_B4);
	PROPERTY(DWORD, unknown_B8);
	PROPERTY(DWORD, unknown_BC);
	PROPERTY(DWORD, unknown_C0);
	PROPERTY(DWORD, unknown_C4);
	PROPERTY(DWORD, unknown_C8);
	PROPERTY(DWORD, unknown_CC);
	PROPERTY(double, unknown_double_D0);
	PROPERTY(DWORD, unknown_D8);
	PROPERTY(DWORD, unknown_DC);
	PROPERTY(DWORD, unknown_E0);
	PROPERTY(float, Velocity);
	PROPERTY_STRUCT(CoordStruct, unknown_coords_E4); //Crd2 in CTOR
	PROPERTY(DWORD, unknown_F0); //unused
	PROPERTY_STRUCT(CoordStruct, unknown_coords_F4); //Crd1 in CTOR
	PROPERTY_STRUCT(CoordStruct, unknown_coords_100); //{ 0, 0, 0} in CTOR
	PROPERTY_STRUCT(Vector3D<float>, unknown_vector3d_10C);
	PROPERTY_STRUCT(Vector3D<float>, unknown_vector3d_118);
	PROPERTY(ParticleSystemClass*, ParticleSystem);
	PROPERTY(BYTE, StateAIAdvance);
	PROPERTY(BYTE, unknown_12D);
	PROPERTY(BYTE, StartStateAI);
	PROPERTY(BYTE, Translucency);
	PROPERTY(BYTE, unknown_130);
	PROPERTY(BYTE, unknown_131);
	PROTECTED_PROPERTY(DWORD, unused_134); //??
};

#endif
