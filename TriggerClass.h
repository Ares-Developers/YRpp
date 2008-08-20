#ifndef TRIGGER_H
#define TRIGGER_H

#include <AbstractClass.h>

//forward declarations
class SuperClass;
class TechnoClass;
class TriggerTypeClass; // TODO: define
class AITeamTypeClass; // TODO: define

class TriggerClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<TriggerClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x726820); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x726860); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x7268D0); }

	//Destructor
	virtual ~TriggerClass()	{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x726950); }

	//AbstractClass
	virtual eAbstractType		WhatAmI()        { return ABS_TRIGGER; }
	virtual int					Size()               { return sizeof(TriggerClass); }
	virtual void				CalculateChecksum(void* pChkSum) { PUSH_VAR32(pChkSum); THISCALL(0x726790); }

	// events include 25 (Cross_Horizontal_Line) ?
	bool InvolvesCrossingHorizontal() { THISCALL(0x726250); }

	// events include 26 (Cross_Vertical_Line) ?
	bool InvolvesCrossingVertical() { THISCALL(0x726290); }

	// events include 24 (Entered_Zone) ? // fuck knows what "Zone" is
	bool InvolvesZoneEntry() { THISCALL(0x7262D0); }

	// events include 14 (Allow_Win) ? // god awful logic, creator should curl up and die
	bool InvolvesAllowWin() { THISCALL(0x726310); }

	// events include 27/28 (Global_Set/Cleared) ? 
	bool InvolvesGlobalChecking(int idx) { PUSH_VAR32(idx); THISCALL(0x726350); }

	void GlobalUpdated(int idx) { PUSH_VAR32(idx); THISCALL(0x7263A0); }
	void LocalUpdated(int idx) { PUSH_VAR32(idx); THISCALL(0x7263D0); }

	void ResetTimers() { THISCALL(0x726400); }

	static TriggerTypeClass * FindInstance(TriggerTypeClass *Type) { PUSH_VAR32(Type); THISCALL(0x726630); }

	void MarkEventAsOccured(int idx) { this->EventsAlreadyFired |= (1 << idx); }
	void MarkEventAsNotOccured(int idx) { this->EventsAlreadyFired &= ~(1 << idx); }
	bool HasEventOccured(int idx) { return (this->EventsAlreadyFired & (1 << idx)) != 0; }
	
	bool HasBeenDestroyed() { return this->Destroyed; }

	void SetHouse(HouseClass *House) { this->House = House; }
	HouseClass * GetHouse() { return this->House; }

	// called whenever an event bubbles up , returns true if all of this trigger's events are up
	bool UpdateEvents(int eventKind, ObjectClass *Object, char a4, bool isRepeating, int a6)
		{ PUSH_VAR32(a6); PUSH_VAR8(isRepeating); PUSH_VAR8(a4); PUSH_VAR32(Object); PUSH_VAR32(eventKind); 
			THISCALL(0x7246C0); }

	bool FireActions(ObjectClass *Obj, CellStruct Pos)
		{ PUSH_VAR32(Pos

	//Constructor
	TriggerClass(TriggerTypeClass *Type)     { PUSH_VAR32(Type); THISCALL(0x725FA0); }

protected:
	TriggerClass():AbstractClass(false){}
	TriggerClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TriggerTypeClass *,	Type);
	PROPERTY(TriggerClass*,	      AttachedTrigger);
	PROPERTY(HouseClass *,	      House);
	PROPERTY(bool,	              Destroyed); // ActionClass::DestroyTrigger called on 
	PROPERTY(bool,	              padding_31);
	PROPERTY(bool,	              padding_32);
	PROPERTY(bool,	              padding_33);
	PROPERTY(TimerStruct,	        ExistenceTimer);
	PROPERTY(int,	                EventsAlreadyFired); // bitfield like TechnoClass::Owner
	PROPERTY(bool,                Enabled);

};

#endif
