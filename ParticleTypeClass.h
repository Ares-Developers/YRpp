/*
	ParticleTypes are initialized by INI files.
*/

#ifndef PARTICLETYPE_H
#define PARTICLETYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class RGBClass; //???
class WarheadTypeClass;

class ParticleTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(ParticleTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x645620, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x645660, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x6457A0, HRESULT); }

	//AbstractClass
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x6458B0); }
	virtual eAbstractType WhatAmI()
		{ return abs_ParticleType; }
	virtual int Size()
		{ return sizeof(ParticleTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6454E0); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* ini)
		{ PUSH_VAR32(ini); THISCALL_RET(0x644F50, bool); }

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* mcoords, HouseClass* owner)
		{ return false; }
	virtual ObjectClass* CreateObject(HouseClass* owner)
		{ return NULL; }

	//Destructor
	virtual ~ParticleTypeClass()
		{ PUSH_VAR32(SDDTOR_NODELETE); THISCALL(0x645950); };

	//Constructor
	ParticleTypeClass(const char* id):ObjectTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x644BE0); }

protected:
	ParticleTypeClass()
		{ };
	ParticleTypeClass(bool X):ObjectTypeClass(false)
		{ };

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
