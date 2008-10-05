#ifndef PARASITE_H
#define PARASITE_H

#include <AbstractClass.h>

class AnimClass;
class FootClass;

class ParasiteClass : public AbstractClass
{
public:

	static DynamicVectorClass<ParasiteClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParasiteClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	ParasiteClass(FootClass* pOwner = NULL) : AbstractClass(false)
		JMP_THIS(0x6292B0);

	//non-virtual
	void UpdateSquid()
		JMP_THIS(0x6297F0);

	void ExitUnit()
		JMP_THIS(0x62A4A0);

	bool CanInfect(FootClass *pTarget)
		JMP_THIS(0x62A8E0);

	void TryInfect(FootClass *pTarget)
		JMP_THIS(0x62A980);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(FootClass*,         Owner);
	PROPERTY(FootClass*,         Victim);
	PROPERTY_STRUCT(TimerStruct, SuppressionTimer);
	PROPERTY_STRUCT(TimerStruct, DamageDeliveryTimer);
	PROPERTY(AnimClass*,         SomeAnim); // squid grapple?
	PROPERTY(DWORD,              unknown_48);
	PROPERTY(DWORD,              unknown_4C);
	PROPERTY(DWORD,              unknown_50);
	PROPERTY(BYTE,               unknown_54);
};

#endif
