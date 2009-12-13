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
	enum {AbsID = abs_ParticleSystemType};

	//Array
	ABSTRACTTYPE_ARRAY(ParticleSystemTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParticleSystemTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* mcoords, HouseClass* owner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Constructor
	ParticleSystemTypeClass(const char* pID) : ObjectTypeClass(false)
		JMP_THIS(0x6440A0);

protected:
	ParticleSystemTypeClass() : ObjectTypeClass(false) { }

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
