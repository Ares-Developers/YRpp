#ifndef TEMPORAL_H
#define TEMPORAL_H

#include <AbstractClass.h>

//forward declarations
class SuperClass;
class TechnoClass;

//The AirstrikeClass handles the airstrikes Boris calls in.
class TemporalClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<TemporalClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x71A720, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x71A660, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x71A700, HRESULT); }

	//Destructor
	virtual ~TemporalClass()	{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x71B1B0); }

	//AbstractClass
	virtual eAbstractType		WhatAmI()        { return abs_Temporal; }
	virtual int					Size()               { return sizeof(TemporalClass); }
	virtual void				CalculateChecksum(void* pChkSum) { PUSH_VAR32(pChkSum); THISCALL(0x71A650); }
	virtual void				Update()             { THISCALL(0x71A760); }

	//Constructor
	TemporalClass(TechnoClass* pOwnerUnit)   { PUSH_VAR32(pOwnerUnit); THISCALL(0x71A4E0); }

	//non-virtual
	void Fire(TechnoClass* pTarget)          { PUSH_VAR32(pTarget); THISCALL(0x71AF20); }
	bool CanWarpTarget(TechnoClass* pTarget)
		{ PUSH_VAR32(pTarget); THISCALL_RET(0x71AE50, bool); }

	// hardcoded to accumulate only up to 50 helpers
	int GetWarpPerStep( int nHelperCount )
		{ PUSH_VAR32(nHelperCount); THISCALL_RET(0x71AB10, int); }

	void LetGo()     { THISCALL(0x71ABC0); }
	void JustLetGo() { THISCALL(0x71AD40); }
	void Detach()    { THISCALL(0x71ADE0); }

protected:
	TemporalClass():AbstractClass(false){}
	TemporalClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TechnoClass*,		OwningUnit);
	PROPERTY(TechnoClass*,		TargetUnit);
	PROPERTY_STRUCT(TimerStruct,		LifeTimer);
	PROPERTY(void*,				unknown_pointer_38);
	PROPERTY(SuperClass*,		SourceSW);

	PROPERTY(TemporalClass*,	NextTemporal);
	PROPERTY(TemporalClass*,	PrevTemporal);

	PROPERTY(int,				WarpRemaining);
	PROPERTY(int,				WarpPerStep);
};

#endif
