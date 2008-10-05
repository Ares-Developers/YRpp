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
	static TriggerTypeClass * __fastcall Find(TriggerTypeClass *pType)
		JMP_STD(0x726630);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TriggerClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	// events include 25 (Cross_Horizontal_Line) ?
	bool InvolvesCrossingHorizontal() JMP_THIS(0x726250);

	// events include 26 (Cross_Vertical_Line) ?
	bool InvolvesCrossingVertical() JMP_THIS(0x726290);

	// events include 24 (Entered_Zone) ? // fuck knows what "Zone" is
	bool InvolvesZoneEntry() JMP_THIS(0x7262D0);

	// events include 14 (Allow_Win) ? // god awful logic, creator should curl up and die
	bool InvolvesAllowWin() JMP_THIS(0x726310);

	// events include 27/28 (Global_Set/Cleared) ? 
	bool InvolvesGlobalChecking(int idx) JMP_THIS(0x726350);

	void GlobalUpdated(int idx) JMP_THIS(0x7263A0);
	void LocalUpdated(int idx) JMP_THIS(0x7263D0);

	void ResetTimers() JMP_THIS(0x726400);

	void MarkEventAsOccured(int idx) { this->EventsAlreadyFired |= (1 << idx); }
	void MarkEventAsNotOccured(int idx) { this->EventsAlreadyFired &= ~(1 << idx); }
	bool HasEventOccured(int idx) { return (this->EventsAlreadyFired & (1 << idx)) != 0; }
	
	bool HasBeenDestroyed() { return this->Destroyed; }

	void SetHouse(HouseClass *House) { this->House = House; }
	HouseClass * GetHouse() { return this->House; }

	// called whenever an event bubbles up , returns true if all of this trigger's events are up
	bool UpdateEvents(int eventKind, ObjectClass *Object, char a4, bool isRepeating, int a6)
		JMP_THIS(0x7246C0);

	bool FireActions(ObjectClass *Obj, CellStruct Pos)
		JMP_THIS(0x7265C0);

	//Constructor
	TriggerClass(TriggerTypeClass *pType = NULL) : AbstractClass(false)
		JMP_THIS(0x725FA0);

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
	PROPERTY_STRUCT(TimerStruct,	        ExistenceTimer);
	PROPERTY(int,	                EventsAlreadyFired); // bitfield like TechnoClass::Owner
	PROPERTY(bool,                Enabled);

};

#endif
