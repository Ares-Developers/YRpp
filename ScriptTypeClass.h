/*
	[ScriptTypes]
*/

#ifndef SCRIPTTYPE_H
#define SCRIPTTYPE_H

#include <AbstractTypeClass.h>

struct ScriptActionNode
{
	int Action;
	int Argument;
};

//forward declarations
class TechnoTypeClass;

class ScriptTypeClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(ScriptTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x691D50); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x691D90); }
	virtual HRESULT _stdcall Save(IStream* pStm,     BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x691DE0); }

	//Destructor
	virtual ~ScriptTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x691FA0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_ScriptType; }
	virtual int Size()
		{ return sizeof(ScriptTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x691E00); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x6918A0); }

	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ PUSH_VAR8(IsGlobal); SET_REG32(ECX, pINI); CALL(0x691970); }

	//Constructor
	ScriptTypeClass(const char* pID):AbstractTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x6916B0); }

protected:
	ScriptTypeClass():AbstractTypeClass(false)
		{ }
	ScriptTypeClass(bool X):AbstractTypeClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(int,      ArrayIndex);
	PROPERTY(bool,     IsGlobal);
	PROPERTY(int,      ActionsCount);
//	PROPERTY_STRUCT_ARRAY(TaskForceEntryStruct, Entries, 0x6);
	PROPERTY_STRUCT_ARRAY(ScriptActionNode, ScriptActions, 50);
};

#endif
