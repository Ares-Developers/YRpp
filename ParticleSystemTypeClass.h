/*
	ParticleSystemTypes are initialized by INI files.
*/

#ifndef PARTICLESYSTEMTYPE_H
#define PARTICLESYSTEMTYPE_H

#include <ObjectTypeClass.h>

//forward declarations

class ParticleSystemTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(ParticleSystemTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x6447A0, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x6447E0, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x644830, HRESULT); }

	//Destructor
	virtual ~ParticleSystemTypeClass()
		{ THISCALL(0x644250); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_ParticleSystemType; }
	virtual int Size()
		{ return sizeof(ParticleSystemTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x644700); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* ini)
		{ PUSH_VAR32(ini); THISCALL_RET(0x6442D0, bool); }

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* mcoords, HouseClass* owner)
		{ return false; }
	virtual ObjectClass* CreateObject(HouseClass* owner)
		{ return NULL; }

	//Constructor
	ParticleSystemTypeClass(const char* id):ObjectTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x6440A0); }

protected:
	ParticleSystemTypeClass()
		{ };
	ParticleSystemTypeClass(bool X):ObjectTypeClass(false)
		{ };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,      HoldsWhat); //ParticleType Array index
	PROPERTY(bool,     Spawns);
	PROPERTY(int,      SpawnFrames);
	PROPERTY(float,    Slowdown);
	PROPERTY(int,      ParticleCap);
	PROPERTY(int,      SpawnRadius);
	PROPERTY(float,    SpawnCutoff);
	PROPERTY(float,    SpawnTranslucencyCutoff);
	PROPERTY(eBehavesLike, BehavesLike);
	PROPERTY(int,      Lifetime);
	PROPERTY_STRUCT(Vector3D<float>, SpawnDirection);
	PROPERTY(double,   ParticlesPerCoord);
	PROPERTY(double,   SpiralDeltaPerCoord);
	PROPERTY(double,   SpiralRadius);
	PROPERTY(double,   PositionPerturbationCoefficient);
	PROPERTY(double,   MovementPerturbationCoefficient);
	PROPERTY(double,   VelocityPerturbationCoefficient);
	PROPERTY(double,   SpawnSparkPercentage);
	PROPERTY(int,      SparkSpawnFrames);
	PROPERTY(int,      LightSize);
	PROPERTY_STRUCT(ColorStruct, LaserColor);
	PROPERTY(bool,     Laser);
	PROPERTY(bool,     OneFrameLight);
};

#endif
