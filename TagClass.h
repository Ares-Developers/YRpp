#pragma once

#include <AbstractClass.h>

//forward declarations
class TagTypeClass;
class TriggerClass;

class NOVTABLE TagClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Tag;

	//Static
	static DynamicVectorClass<TagClass*>* const Array;

	// finds an instance using the type, or creates one
	static TagClass* __fastcall GetInstance(TagTypeClass* pType)
		{ JMP_STD(0x6E52A0); }

	// deletes every tag in array
	static void __stdcall DeleteAll()
		{ JMP_STD(0x6E5570); }

	// notifies all tags in array that a global was updated
	static void __fastcall NotifyGlobalChanged(int idxGlobal)
		{ JMP_STD(0x6E57F0); }

	// notifies all tags in array that a global was updated
	static void __fastcall NotifyLocalChanged(int idxLocal)
		{ JMP_STD(0x6E5820); }

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) override R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) override R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) override R0;

	//Destructor
	virtual ~TagClass() RX;

	//AbstractClass
	virtual void PointerExpired(AbstractClass* pAbstract, bool removed) override RX;
	virtual AbstractType WhatAmI() const override RT(AbstractType);
	virtual int Size() const override R0;
	virtual void CalculateChecksum(Checksummer& checksum) const override RX;

	// contains at least one Crosses Horizontal Line event
	bool HasCrossesHorizontalLineEvent() const
		{ JMP_THIS(0x6E5320); }

	// contains at least one Crosses Vertical Line event
	bool HasCrossesVerticalLineEvent() const
		{ JMP_THIS(0x6E5300); }

	// contains at least one Zone Entry By event
	bool HasZoneEntryByEvent() const
		{ JMP_THIS(0x6E5340); }

	// contains at least one Allow Win action
	bool HasAllowWinAction() const
		{ JMP_THIS(0x6E5360); }

	// called when a global is updated
	void GlobalChanged(int idxGlobal)
		{ JMP_THIS(0x6E55A0); }

	// called when a local is updated
	void LocalChanged(int idxLocal)
		{ JMP_THIS(0x6E55B0); }

	// whether there exist no other tag having the same type
	// note: this is not the same as this->InstanceCount
	bool IsOnlyInstanceOfType() const
		{ JMP_THIS(0x6E5850); }

	bool RaiseEvent(
		TriggerEvent event, ObjectClass* pTagOwner, CellStruct location,
		bool forceAllOccured = false, TechnoClass* pSource = nullptr)
	{ JMP_THIS(0x6E53A0); }

	// whether the tag transfers when the owner is "changed",
	// like vehicle thief to tank and vice versa
	bool ShouldReplace() const
		{ JMP_THIS(0x6E57C0); }

	void Destroy()
		{ JMP_THIS(0x6E5230); }
	bool HasBeenDestroyed() const
		{ return this->Destroyed; }

	// adds a trigger to the list
	void AddTrigger(TriggerClass* pTrigger)
		{ JMP_THIS(0x6E55C0); }

	// removes a trigger from the list
	bool RemoveTrigger(TriggerClass* pTrigger)
		{ JMP_THIS(0x6E55D0); }

	// check whether the trigger is contained in the list
	bool ContainsTrigger(TriggerClass* pTrigger) const
		{ JMP_THIS(0x6E5380); }

	//Constructor
	TagClass(TagTypeClass* pType) noexcept
		: TagClass(noinit_t())
	{ JMP_THIS(0x6E4DE0); }

protected:
	explicit __forceinline TagClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	TagTypeClass* Type;
	TriggerClass* FirstTrigger;
	int InstanceCount;
	CellStruct DefaultCoords;
	bool Destroyed;
	bool IsExecuting;
	PROTECTED_PROPERTY(BYTE, padding_36[2]);
};
