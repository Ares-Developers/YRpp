/*
	ParticleTypes are initialized by INI files.
*/

#pragma once

#include <ObjectTypeClass.h>

//forward declarations
class WarheadTypeClass;

class NOVTABLE ParticleTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::ParticleType;

	//Array
	ABSTRACTTYPE_ARRAY(ParticleTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* mcoords, HouseClass* owner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Destructor
	virtual ~ParticleTypeClass() RX;

	//Constructor
	ParticleTypeClass(const char* pID) noexcept
		: ParticleTypeClass(noinit_t())
	{ JMP_THIS(0x644BE0); }

protected:
	explicit __forceinline ParticleTypeClass(noinit_t) noexcept
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CoordStruct NextParticleOffset;
	int    XVelocity;
	int    YVelocity;
	int    MinZVelocity;
	int    ZVelocityRange;
	double ColorSpeed;
	TypeList<RGBClass*> ColorList;
	ColorStruct StartColor1;
	ColorStruct StartColor2;
	int    MaxDC;
	int    MaxEC;
	WarheadTypeClass* Warhead;
	int    Damage;
	int    StartFrame;
	int    NumLoopFrames;
	int    Translucency;
	int    WindEffect;
	float  Velocity;
	float  Deacc;
	int    Radius;
	bool   DeleteOnStateLimit;
	BYTE   EndStateAI;
	BYTE   StartStateAI;
	BYTE   StateAIAdvance;
	BYTE   FinalDamageState;
	BYTE   Translucent25State;
	BYTE   Translucent50State;
	bool   Normalized;
	ParticleTypeClass* NextParticle;
	BehavesLike BehavesLike;

};
