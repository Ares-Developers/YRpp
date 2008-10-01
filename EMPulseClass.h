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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~EMPulseClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	EMPulseClass(CellStruct dwCrd,int nSpread,int nDuration) : AbstractClass(false)
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
