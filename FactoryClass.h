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

	static DynamicVectorClass<FactoryClass *> *Array;

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
		JMP_THIS(0x4C98B0);

	//non-virtual
	bool DemandProduction(TechnoTypeClass* pType, HouseClass* pOwner, bool bShouldQueue)
		JMP_THIS(0x4C9C70);
	bool AbandonProduction()
		JMP_THIS(0x4C9FF0);
	unsigned int CountQueued(TechnoTypeClass * pType)
		JMP_THIS(0x4CA670);

	static bool FindThisOwnerAndProduct(HouseClass *pHouse, TechnoTypeClass *pItem)
	{
		for(int i = 0; i < Array->get_Count(); ++i)
		{
			FactoryClass *Fact = Array->GetItem(i);
			if(Fact->get_Owner() == pHouse)
			{
				if(Fact->CountQueued(pItem) > 0)
				{
					return true;
				}
			}
		}
		return false;
	}

protected:
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
