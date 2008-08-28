/*
	EMP - no, you're NOT seeing things :P
*/

#ifndef EMPULSE_H
#define EMPULSE_H

#include <AbstractClass.h>

class EMPulseClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<EMPulseClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x4C59F0);}

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x4C5A30); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x4C5A80); }

	//Destructor
	virtual ~EMPulseClass()
		{ THISCALL(0x4C53E0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_EMPulse; }
	virtual int Size()
		{ return sizeof(EMPulseClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x4C59A0); }

	//Constructor
	EMPulseClass(CellStruct dwCrd,int nSpread,int nDuration):AbstractClass(false)
		{ PUSH_IMM(0); PUSH_VAR32(nDuration); PUSH_VAR32(nSpread); PUSH_VAR32(dwCrd); THISCALL(0x4C52B0); }

protected:
	EMPulseClass():AbstractClass(false){}
	EMPulseClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRUCT(CellStruct,		BaseCoords);
	PROPERTY(int,				Spread);
	PROPERTY(int,				CreationTime);	//frame in which this EMP got created
	PROPERTY(int,				Duration);
};

#endif
