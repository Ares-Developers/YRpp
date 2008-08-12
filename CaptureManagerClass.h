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
	TechnoClass*	Unit;
	HouseClass*	OriginalOwner;
	TimerStruct	LinkDrawTimer;
};

class CaptureManagerClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x472960); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x472720); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x4728E0); }

	//Destructor
	virtual ~CaptureManagerClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x4729C0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_CaptureManager; }
	virtual int Size()
		{ return sizeof(CaptureManagerClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x4726F0); }

	//Constructor
	CaptureManagerClass(TechnoClass* pOwner,int nMaxControlNodes,bool bInfiniteControl):AbstractClass(false)
	{
		PUSH_VAR8(bInfiniteControl);
		PUSH_VAR32(nMaxControlNodes);
		PUSH_VAR32(pOwner);
		THISCALL(0x4717D0);
	}

	//non-virtual
	bool CaptureUnit(TechnoClass* pUnit)
		{ PUSH_VAR32(pUnit); THISCALL(0x471D40); }
	bool FreeUnit(TechnoClass* pUnit)
		{ PUSH_VAR32(pUnit); THISCALL(0x471FF0); }
	void FreeAll()
		{ THISCALL(0x472140); }

	int NumControlNodes()
		{ return ControlNodes.get_Count(); }

	bool CanCapture(TechnoClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x471C90); }
	bool CannotControlAnyMore()
		{ THISCALL(0x4722A0); }
	bool IsControllingSomething()
		{ THISCALL(0x4722C0); }
	bool IsOverloading(bool *result)
		{ PUSH_VAR32(result); THISCALL(0x4726C0); } 
	void HandleOverload()
		{ THISCALL(0x471A50); }
	bool NeedsToDrawLinks()
		{ THISCALL(0x472640); }
	bool DrawLinks()
		{ THISCALL(0x472160); }
	void DecideUnitFate(TechnoClass *Unit)
		{ PUSH_VAR32(Unit); THISCALL(0x4723B0); }


protected:
	CaptureManagerClass():AbstractClass(false){}
	CaptureManagerClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY_STRUCT(DynamicVectorClass<ControlNode*>, ControlNodes);
	PROPERTY(int,                              MaxControlNodes);
	PROPERTY(bool,                             InfiniteMindControl);
	PROPERTY(bool,                             IsOwnerDead);
	PROPERTY(DWORD,                            unknown_44);
	PROPERTY(TechnoClass*,                     Owner);
	PROPERTY(int,                              unknown_int_4C);	//defaults to 30

};

#endif
