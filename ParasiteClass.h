#ifndef PARASITE_H
#define PARASITE_H

#include <AbstractClass.h>

class AnimClass;
class FootClass;

class ParasiteClass : public AbstractClass
{
public:
	enum {AbsID = abs_Parasite};

	static DynamicVectorClass<ParasiteClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParasiteClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//Constructor
	ParasiteClass(FootClass* pOwner = nullptr) : AbstractClass(false)
		{ JMP_THIS(0x6292B0); }

	//non-virtual
	void UpdateSquid()
		{ JMP_THIS(0x6297F0); }

	bool UpdateGrapple()
		{ JMP_THIS(0x629720); }

	void ExitUnit()
		{ JMP_THIS(0x62A4A0); }

	bool CanInfect(FootClass *pTarget) const
		{ JMP_THIS(0x62A8E0); }

	void TryInfect(FootClass *pTarget)
		{ JMP_THIS(0x62A980); }

	bool CanExistOnVictimCell() const
		{ JMP_THIS(0x62AB40); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	FootClass*      Owner;
	FootClass*      Victim;
	TimerStruct     SuppressionTimer;
	TimerStruct     DamageDeliveryTimer;
	AnimClass*      GrappleAnim;
	ParasiteState   GrappleState;
	int             GrappleAnimFrame;
	int             GrappleAnimDelay;
	bool            GrappleAnimGotInvalid;
};

#endif
