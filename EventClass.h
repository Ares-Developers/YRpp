#ifndef EVENT_H
#define EVENT_H

#include <AbstractClass.h>

//forward declarations
class SuperClass;
class TechnoClass;
class AITeamTypeClass; // TODO: define

class EventClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<EventClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x71FA60, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x71F8C0, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x71F930, HRESULT); }

	//Destructor
	virtual ~EventClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x71FA80); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return ABS_EVENT; }
	virtual int Size()
		{ return sizeof(EventClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x71F820); }

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
		{ SET_REG32(ecx, eventKind); CALL_RET(0x71F680, int); }

	// used in TriggerClass::HaveEventsOccured , when trigger is repeating
	// both need to be true to check this event as done
	bool GetStateA()
		{ THISCALL_RET(0x71F950, bool); }
	bool GetStateB()
		{ THISCALL_RET(0x71F9C0, bool); }

	// main brain
	bool HasOccured(int eventKind, HouseClass *pHouse, ObjectClass *Object,
	                TimerStruct *ActivationFrame, bool *isRepeating)
		{ PUSH_VAR8(isRepeating); 
		  PUSH_VAR32(ActivationFrame);
		  PUSH_VAR32(Object); 
		  PUSH_VAR32(pHouse); 
		  PUSH_VAR32(eventKind);
		  THISCALL_RET(0x71E940, bool); }

	//Constructor
	EventClass()
		{ THISCALL(0x71E6A0); }

protected:
	EventClass():AbstractClass(false){}
	EventClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,               indexInArray);
	PROPERTY(EventClass*,       NextEvent);
	PROPERTY(int,               EventKind);
	PROPERTY(void*,             TeamType); // AITeamTypeClass*, really
	PROPERTY(int,               arg);
	PROPERTY_STRING(TechnoName, 0x1C); // YR introduced this sort of referencing
	                                   // must've been to hard to follow the old convention of simple indexing
	PROPERTY(HouseClass*,       House);

};

#endif
