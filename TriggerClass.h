#pragma once

#include <AbstractClass.h>

//forward declarations
class ObjectClass;
class TechnoClass;
class TriggerTypeClass;

class NOVTABLE TriggerClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Trigger;

	//Static
	static DynamicVectorClass<TriggerClass*>* const Array;

	// finds an instance using the type, or creates one
	static TriggerClass* __fastcall GetInstance(TriggerTypeClass* pType)
		{ JMP_STD(0x726630); }

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) override R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) override R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) override R0;

	//Destructor
	virtual ~TriggerClass() RX;

	//AbstractClass
	virtual void PointerExpired(AbstractClass* pAbstract, bool removed) override RX;
	virtual AbstractType WhatAmI() const override RT(AbstractType);
	virtual int Size() const override R0;
	virtual void CalculateChecksum(Checksummer& checksum) const override RX;

	// contains at least one Crosses Horizontal Line event
	bool HasCrossesHorizontalLineEvent() const
		{ JMP_THIS(0x726250); }

	// contains at least one Crosses Vertical Line event
	bool HasCrossesVerticalLineEvent() const
		{ JMP_THIS(0x726290); }

	// contains at least one Zone Entry By event
	bool HasZoneEntryByEvent() const
		{ JMP_THIS(0x7262D0); }

	// contains at least one Allow Win action
	bool HasAllowWinAction() const
		{ JMP_THIS(0x726310); }

	// contains at least one Global Set or Global Cleared event
	bool HasGlobalSetOrClearedEvent(int idxGlobal) const
		{ JMP_THIS(0x726350); }

	// called when a global is updated. resets timers
	void NotifyGlobalChanged(int idxGlobal)
		{ JMP_THIS(0x7263A0); }

	// called when a local is updated. resets timers
	void NotifyLocalChanged(int idxLocal)
		{ JMP_THIS(0x7263D0); }

	// resets the timers for all Elapsed Time and Random Delay events
	void ResetTimers()
		{ JMP_THIS(0x726400); }

	void MarkEventAsOccured(int idx)
		{ this->OccuredEvents |= (1u << idx); }
	void MarkEventAsNotOccured(int idx)
		{ this->OccuredEvents &= ~(1u << idx); }
	bool HasEventOccured(int idx) const
		{ return (this->OccuredEvents & (1u << idx)) != 0u; }

	void Destroy()
		{ JMP_THIS(0x726720); }
	bool HasBeenDestroyed() const
		{ return this->Destroyed; }

	void SetHouse(HouseClass* pHouse)
		{ this->House = pHouse; }
	HouseClass* GetHouse() const
		{ return this->House; }

	// enables the trigger and resets the timers
	void Enable()
		{ this->Enabled = true; this->ResetTimers(); }
	void Disable()
		{ this->Enabled = false; }

	// called whenever an event bubbles up, returns true if all of this
	// trigger's events occured. persistent events are remembered
	bool RegisterEvent(
		TriggerEvent event, ObjectClass* pObject, bool forceFire,
		bool persistent, TechnoClass* pSource)
	{ JMP_THIS(0x7264C0); }

	// returns whether any action was executed
	bool FireActions(ObjectClass* pObj, CellStruct location)
		{ JMP_THIS(0x7265C0); }

	//Constructor
	TriggerClass(TriggerTypeClass* pType)
		: TriggerClass(noinit_t())
	{ JMP_THIS(0x725FA0); }

protected:
	explicit __forceinline TriggerClass(noinit_t)
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	TriggerTypeClass*	Type;
	TriggerClass*		NextTrigger;
	HouseClass*			House;
	bool				Destroyed; // ActionClass::DestroyTrigger called on
	PROTECTED_PROPERTY(BYTE, align_31[3]);
	TimerStruct			Timer;
	DWORD				OccuredEvents; // bitfield for 32 events max
	bool				Enabled;
	PROTECTED_PROPERTY(BYTE, padding_45[3]);
};
