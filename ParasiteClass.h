#pragma once

#include <AbstractClass.h>

class AnimClass;
class FootClass;

class NOVTABLE ParasiteClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Parasite;

	static DynamicVectorClass<ParasiteClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ParasiteClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

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

	//Constructor
	ParasiteClass(FootClass* pOwner = nullptr) noexcept
		: ParasiteClass(noinit_t())
	{ JMP_THIS(0x6292B0); }

protected:
	explicit __forceinline ParasiteClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

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
