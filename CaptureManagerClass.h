/*
	CaptureManager - used for mind control.
*/

#ifndef CAPMANAGER_H
#define CAPMANAGER_H

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;

struct ControlNode
{
	TechnoClass* Unit;
	HouseClass* OriginalOwner;
	TimerStruct LinkDrawTimer;
};

class CaptureManagerClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~CaptureManagerClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	CaptureManagerClass(TechnoClass* pOwner, int nMaxControlNodes, bool bInfiniteControl) : AbstractClass(false)
		JMP_THIS(0x4717D0);

	//non-virtual
	bool CaptureUnit(TechnoClass* pUnit)
		JMP_THIS(0x471D40);
	bool FreeUnit(TechnoClass* pUnit)
		JMP_THIS(0x471FF0);
	void FreeAll()
		JMP_THIS(0x472140);

	int NumControlNodes()
		{ return ControlNodes.Count; }

	bool CanCapture(TechnoClass *Target)
		JMP_THIS(0x471C90);
	bool CannotControlAnyMore()
		JMP_THIS(0x4722A0);
	bool IsControllingSomething()
		JMP_THIS(0x4722C0);
	bool IsOverloading(bool *result)
		JMP_THIS(0x4726C0);
	void HandleOverload()
		JMP_THIS(0x471A50);
	bool NeedsToDrawLinks()
		JMP_THIS(0x472640);
	bool DrawLinks()
		JMP_THIS(0x472160);
	void DecideUnitFate(TechnoClass *Unit)
		JMP_THIS(0x4723B0);

protected:
	CaptureManagerClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY_STRUCT(DynamicVectorClass<ControlNode*>, ControlNodes);
	PROPERTY(int, MaxControlNodes);
	PROPERTY(bool, InfiniteMindControl);
	PROPERTY(bool, IsOwnerDead);
	PROPERTY(DWORD, unknown_44);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(int, unknown_int_4C);	//defaults to 30
};

#endif
