/*
	CaptureManager - used for mind control.
*/

#pragma once

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;

struct ControlNode
{
	TechnoClass* Unit;
	HouseClass* OriginalOwner;
	TimerStruct LinkDrawTimer;
};

class NOVTABLE CaptureManagerClass : public AbstractClass
{
public:

	static DynamicVectorClass<CaptureManagerClass *>* const Array;

	static const AbstractType AbsID = AbstractType::CaptureManager;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~CaptureManagerClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//non-virtual
	bool CaptureUnit(TechnoClass* pUnit)
		{ JMP_THIS(0x471D40); }
	bool FreeUnit(TechnoClass* pUnit)
		{ JMP_THIS(0x471FF0); }
	void FreeAll()
		{ JMP_THIS(0x472140); }

	int NumControlNodes() const
		{ return ControlNodes.Count; }

	bool CanCapture(TechnoClass *Target) const
		{ JMP_THIS(0x471C90); }
	bool CannotControlAnyMore() const
		{ JMP_THIS(0x4722A0); }
	bool IsControllingSomething() const
		{ JMP_THIS(0x4722C0); }
	bool IsOverloading(bool *wasDamageApplied) const
		{ JMP_THIS(0x4726C0); }
	void HandleOverload()
		{ JMP_THIS(0x471A50); }
	bool NeedsToDrawLinks() const
		{ JMP_THIS(0x472640); }
	bool DrawLinks()
		{ JMP_THIS(0x472160); }
	void DecideUnitFate(TechnoClass *Unit)
		{ JMP_THIS(0x4723B0); }
	HouseClass* GetOriginalOwner(TechnoClass *Unit) const
		{ JMP_THIS(0x4722F0); }

	//Constructor
	CaptureManagerClass(TechnoClass* pOwner, int nMaxControlNodes, bool bInfiniteControl) noexcept
		: CaptureManagerClass(noinit_t())
	{ JMP_THIS(0x4717D0); }

protected:
	explicit __forceinline CaptureManagerClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DynamicVectorClass<ControlNode*> ControlNodes;
	int MaxControlNodes;
	bool InfiniteMindControl;
	bool OverloadDeathSoundPlayed; // Has the mind control death sound played already?
	int OverloadPipState; // Used to create the red overloading pip by returning true in IsOverloading's wasDamageApplied for 10 frames.
	TechnoClass* Owner;
	int OverloadDamageDelay; // Decremented every frame. If it reaches zero, OverloadDamage is applied.
};
