#pragma once

#include <AbstractTypeClass.h>

//forward declarations
class CCINIClass;
class TriggerTypeClass;

class NOVTABLE TagTypeClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::TagType;

	//Array
	ABSTRACTTYPE_ARRAY(TagTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) override R0;

	virtual HRESULT __stdcall Load(IStream* pStm) override R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) override R0;

	//Destructor
	virtual ~TagTypeClass() RX;

	//AbstractClass
	virtual void PointerExpired(AbstractClass* pAbstract, bool removed) override RX;
	virtual AbstractType WhatAmI() const override RT(AbstractType);
	virtual int Size() const override R0;
	virtual void CalculateChecksum(Checksummer& checksum) const override RX;

	//AbstractTypeClass
	virtual int GetArrayIndex() const override R0;
	virtual bool LoadFromINI(CCINIClass* pINI) override R0;
	virtual bool SaveToINI(CCINIClass* pINI) override R0;

	//static
	static void __fastcall LoadFromINIList(CCINIClass* pINI)
		{ JMP_STD(0x6E5ED0); }

	static void __fastcall SaveToINIList(CCINIClass* pINI)
		{ JMP_STD(0x6E5FE0); }

	TagTypeClass* __fastcall FindByNameOrID(char const* pName)
		{ JMP_STD(0x6E5E70); }

	//non-virtual
	using Flags = BYTE; // same as trigger and event flags?
	Flags GetFlags() const
		{ JMP_THIS(0x6E61F0); }

	// contains at least one Allow Win action
	bool HasAllowWinAction() const
		{ JMP_THIS(0x6E6220); }

	// contains at least one Crosses Horizontal Line event
	bool HasCrossesHorizontalLineEvent() const
		{ JMP_THIS(0x6E6250); }

	// contains at least one Crosses Vertical Line event
	bool HasCrossesVerticalLineEvent() const
		{ JMP_THIS(0x6E6280); }

	// contains at least one Zone Entry By event
	bool HasZoneEntryByEvent() const
		{ JMP_THIS(0x6E62B0); }

	// adds a trigger to the list
	bool AddTrigger(TriggerTypeClass* pTrigger)
		{ JMP_THIS(0x6E5DD0); }

	// removes a trigger from the list
	bool RemoveTrigger(TriggerTypeClass* pTrigger)
		{ JMP_THIS(0x6E5E00); }

	// check whether the trigger is contained in the list
	bool ContainsTrigger(TriggerTypeClass* pTrigger) const
		{ JMP_THIS(0x6E62E0); }

	//Constructor
	TagTypeClass(char const* pName) noexcept
		: TagTypeClass(noinit_t())
	{ JMP_THIS(0x5447C0); }

protected:
	explicit __forceinline TagTypeClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	int ArrayIndex;
	TriggerPersistence Persistence;
	TriggerTypeClass* FirstTrigger;
};
