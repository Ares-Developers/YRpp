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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ScriptTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass
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
	PROPERTY_STRUCT_ARRAY(ScriptActionNode, ScriptActions, 50);
};

#endif
