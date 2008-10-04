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
	//Static
	static DynamicVectorClass<TEventClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TEventClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;


	// you are responsible for doing INI::ReadString and strtok'ing it before calling
	// this func only calls strtok again, doesn't know anything about buffers
	void LoadFromINI()
		{ THISCALL(0x71F4A0); }

	// you allocate the buffer for this, and save it to ini yourself after this returns
	// this func only sprintf's the stuff it needs into buffer
	void PrepareSaveToINI(char *buffer)
		{ PUSH_VAR32(buffer); THISCALL(0x71F390); }

	// fuck if I know what's the purpose of this, returns a bitfield of flags for trigger logic
	static int GetFlags(int eventKind)
		{ SET_REG32(ecx, eventKind); CALL(0x71F680); }

	// used in TriggerClass::HaveEventsOccured , when trigger is repeating
	// both need to be true to check this event as done
	bool GetStateA() { THISCALL(0x71F950); }
	bool GetStateB() { THISCALL(0x71F9C0); }

	// main brain
	bool HasOccured(int eventKind, HouseClass *pHouse, ObjectClass *Object,
	                TimerStruct *ActivationFrame, bool *isRepeating)
		{ PUSH_VAR8(isRepeating); 
		  PUSH_VAR32(ActivationFrame);
		  PUSH_VAR32(Object); 
		  PUSH_VAR32(pHouse); 
		  PUSH_VAR32(eventKind);
		  THISCALL(0x71E940); }

	//Constructor
	TEventClass()
		{ THISCALL(0x71E6A0); }

protected:
	TEventClass(bool X):AbstractClass(X){}

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
