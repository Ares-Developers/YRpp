/*
	Factories are responsible for producing units and buildings.
*/

#ifndef FACTORY_H
#define FACTORY_H

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;
class TechnoTypeClass;

class FactoryClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~FactoryClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	FactoryClass() : AbstractClass(false)
		{ THISCALL(0x4C98B0); }

	//non-virtual
	bool DemandProduction(TechnoTypeClass* pType, HouseClass* pOwner, bool bShouldQueue)
		{ PUSH_VAR8(bShouldQueue); PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x4C9C70); }
	bool AbandonProduction()
		{ THISCALL(0x4C9FF0); }
	unsigned int CountQueued(TechnoTypeClass * pType)
		{ PUSH_VAR32(pType); THISCALL(0x4CA670); }

protected:
	FactoryClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(int,                ProductionStatus); // hardcoded to be 54 steps (so cameo clock should be 54 frames)
	PROPERTY(bool,               unknown_bool_28);
	PROPERTY_STRUCT(TimerStruct,        ProductionTimer);
	PROPERTY(DWORD,              ProductionRemainingFrames);
	PROPERTY(int,                unknown_int_3C);
	PROPERTY_STRUCT(DynamicVectorClass<TechnoTypeClass*>, QueuedObjects);
	PROPERTY(TechnoClass*,       InProduction);
	PROPERTY(bool,               OnHold); // paused when out of money, restored when funds available
	PROPERTY(bool,               IsDifferent);	//Not sure what this means.
	PROPERTY(int,                Balance); // credits house still owes us for building this
	PROPERTY(int,                OriginalBalance);
	PROPERTY(int,                SpecialItem); // only case of it being used is 0x6AB2D9:
	                                           // if(SpecialItem != -1) { Map->CurrentSWType = 1; }
	PROPERTY(HouseClass*,        Owner);
	PROPERTY(bool,               IsCompleteAndSuspended);	//completed production, before next (or waiting to place)
};

#endif
