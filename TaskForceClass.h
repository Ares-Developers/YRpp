/*
	TaskForces as in the AI inis
*/

#pragma once

#include <AbstractTypeClass.h>

//forward declarations
class TechnoTypeClass;

struct TaskForceEntryStruct
{
	int Amount;
	TechnoTypeClass* Type;
};

class NOVTABLE TaskForceClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::TaskForce;

	//Array
	ABSTRACTTYPE_ARRAY(TaskForceClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TaskForceClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	TaskForceClass(const char* pID) noexcept
		: TaskForceClass(noinit_t())
	{ JMP_THIS(0x6E7E80); }

protected:
	explicit __forceinline TaskForceClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int     Group;
	int     CountEntries;
	bool    isGlobal;
	TaskForceEntryStruct Entries [0x6];
};
