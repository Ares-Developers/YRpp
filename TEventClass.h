#ifndef TEVENT_H
#define TEVENT_H

#include <AbstractClass.h>

//forward declarations
class SuperClass;
class TechnoClass;
class AITeamTypeClass; // TODO: define

class TEventClass : public AbstractClass
{
public:
	enum {AbsID = abs_Event};

	//Static
	static DynamicVectorClass<TEventClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TEventClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;


	// you are responsible for doing INI::ReadString and strtok'ing it before calling
	// this func only calls strtok again, doesn't know anything about buffers
	void LoadFromINI()
		JMP_THIS(0x71F4A0);

	// you allocate the buffer for this, and save it to ini yourself after this returns
	// this func only sprintf's the stuff it needs into buffer
	void PrepareSaveToINI(char *buffer)
		JMP_THIS(0x71F390);

	// fuck if I know what's the purpose of this, returns a bitfield of flags for trigger logic
	static int __fastcall GetFlags(int eventKind)
		JMP_STD(0x71F680);

	// used in TriggerClass::HaveEventsOccured , when trigger is repeating
	// both need to be true to check this event as done
	bool GetStateA() JMP_THIS(0x71F950);
	bool GetStateB() JMP_THIS(0x71F9C0);

	// main brain
	bool HasOccured(
		int eventKind,
		HouseClass *pHouse,
		ObjectClass *Object,
		TimerStruct *ActivationFrame,
		bool *isRepeating)
			JMP_THIS(0x71E940);

	//Constructor
	TEventClass() : AbstractClass(false)
		JMP_THIS(0x71E6A0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,               indexInArray);
	PROPERTY(TEventClass*,       NextEvent);
	PROPERTY(int,               EventKind);
	PROPERTY(void*,             TeamType); // AITeamTypeClass*, really
	PROPERTY(int,               arg);
	PROPERTY_STRING(TechnoName, 0x1C); // YR introduced this sort of referencing
	                                   // must've been to hard to follow the old convention of simple indexing
	PROPERTY(HouseClass*,       House);

};

#endif
