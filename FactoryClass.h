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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x4CA230); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x4CA270); }
	virtual HRESULT _stdcall	Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x4CA3C0); }

	//Destructor
	virtual ~FactoryClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x4CA770); }

	//AbstractClass
	virtual void PointerExpired(void* p,bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x4CA580); }
	virtual eAbstractType WhatAmI()
		{ return abs_Factory; }
	virtual int Size()
		{ return sizeof(FactoryClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x4CA430); }
	virtual void Update()
		{ THISCALL(0x4C9B20); }

	//Constructor
	FactoryClass():AbstractClass(false)
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
	PROPERTY(int,                Balance);
	PROPERTY(int,                OriginalBalance);
	PROPERTY(int,                SpecialItem);
	PROPERTY(HouseClass*,        Owner);
	PROPERTY(bool,               IsSuspended);	//Paused?
};

#endif
