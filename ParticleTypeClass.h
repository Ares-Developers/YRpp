/*
	ParticleTypes are initialized by INI files.
*/

#ifndef PARTICLETYPE_H
#define PARTICLETYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class WarheadTypeClass;

class ParticleTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(ParticleTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* mcoords, HouseClass* owner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Destructor
	virtual ~ParticleTypeClass() RX;

	//Constructor
	ParticleTypeClass(const char* pID = NULL) : ObjectTypeClass(false)
		JMP_THIS(0x644BE0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(CoordStruct, NextParticleOffset);
	PROPERTY(int,    XVelocity);
	PROPERTY(int,    YVelocity);
	PROPERTY(int,    MinZVelocity);
	PROPERTY(int,    ZVelocityRange);
	PROPERTY(double, ColorSpeed);
	PROPERTY_STRUCT(TypeList<RGBClass*>, ColorList);
	PROPERTY_STRUCT(ColorStruct, StartColor1);
	PROPERTY_STRUCT(ColorStruct, StartColor2);
	PROPERTY(int,    MaxDC);
	PROPERTY(int,    MaxEC);
	PROPERTY(WarheadTypeClass*, Warhead);
	PROPERTY(int,    Damage);
	PROPERTY(int,    StartFrame);
	PROPERTY(int,    NumLoopFrames);
	PROPERTY(int,    Translucency);
	PROPERTY(int,    WindEffect);
	PROPERTY(float,  Velocity);
	PROPERTY(float,  Deacc);
	PROPERTY(int,    Radius);
	PROPERTY(bool,   DeleteOnStateLimit);
	PROPERTY(BYTE,   EndStateAI);
	PROPERTY(BYTE,   StartStateAI);
	PROPERTY(BYTE,   StateAIAdvance);
	PROPERTY(BYTE,   FinalDamageState);
	PROPERTY(BYTE,   Translucent25State);
	PROPERTY(BYTE,   Translucent50State);
	PROPERTY(bool,   Normalized);
	PROPERTY(ParticleTypeClass*, NextParticle);
	PROPERTY(eBehavesLike, BehavesLike);

};

#endif
