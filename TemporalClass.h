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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TemporalClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	TemporalClass(TechnoClass* pOwnerUnit = NULL) : AbstractClass(false)
		JMP_THIS(0x71A4E0);

	//non-virtual
	void Fire(TechnoClass* pTarget)
		JMP_THIS(0x71AF20);
	bool CanWarpTarget(TechnoClass* pTarget)
		JMP_THIS(0x71AE50);

	// hardcoded to accumulate only up to 50 helpers
	int GetWarpPerStep( int nHelperCount )
		JMP_THIS(0x71AB10);

	void LetGo()
		JMP_THIS(0x71ABC0);
	void JustLetGo()
		JMP_THIS(0x71AD40);
	void Detach()
		JMP_THIS(0x71ADE0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TechnoClass*,       OwningUnit);
	PROPERTY(TechnoClass*,       TargetUnit);
	PROPERTY_STRUCT(TimerStruct, LifeTimer);
	PROPERTY(void*,              unknown_pointer_38);
	PROPERTY(SuperClass*,        SourceSW);

	PROPERTY(TemporalClass*,     NextTemporal);
	PROPERTY(TemporalClass*,     PrevTemporal);

	PROPERTY(int,                WarpRemaining);
	PROPERTY(int,                WarpPerStep);
};

#endif
