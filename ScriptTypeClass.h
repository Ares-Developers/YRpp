/*
	[ScriptTypes]
*/

#pragma once

#include <AbstractTypeClass.h>

struct ScriptActionNode
{
	int Action;
	int Argument;
};

//forward declarations
class TechnoTypeClass;

class NOVTABLE ScriptTypeClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::ScriptType;

	//Array
	ABSTRACTTYPE_ARRAY(ScriptTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ScriptTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//AbstractTypeClass
	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ JMP_STD(0x691970); }

	//Constructor
	ScriptTypeClass(const char* pID) noexcept
		: ScriptTypeClass(noinit_t())
	{ JMP_THIS(0x6916B0); }

protected:
	explicit __forceinline ScriptTypeClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int      ArrayIndex;
	bool     IsGlobal;
	int      ActionsCount;
	ScriptActionNode ScriptActions [50];
};
