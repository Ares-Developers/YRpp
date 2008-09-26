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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6296D0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6295B0); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6296B0); }

	//Destructor
	virtual ~ParasiteClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x62AF70); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_Parasite; }
	virtual int Size()
		{ return sizeof(ParasiteClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6294D0); }

	virtual void Update()
		{ THISCALL(0x629FD0); }

	//Constructor
	ParasiteClass(FootClass* pOwner):AbstractClass(false)
	{
		PUSH_VAR32(pOwner);
		THISCALL(0x6292B0);
	}

	//non-virtual
	void UpdateSquid()
		{ THISCALL(0x6297F0); }

	void ExitUnit()
		{ THISCALL(0x62A4A0); }

	bool CanInfect(FootClass *pTarget)
		{ PUSH_VAR32(pTarget); THISCALL(0x62A8E0); }

	void TryInfect(FootClass *pTarget)
		{ PUSH_VAR32(pTarget); THISCALL(0x62A980); }

protected:
	ParasiteClass():AbstractClass(false){}
	ParasiteClass(bool X):AbstractClass(X){}

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
