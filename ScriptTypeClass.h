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
	enum {AbsID = abs_ScriptType};

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
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass
	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ JMP_STD(0x691970); }

	//Constructor
	ScriptTypeClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x6916B0); }

protected:
	ScriptTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,      ArrayIndex);
	PROPERTY(bool,     IsGlobal);
	PROPERTY(int,      ActionsCount);
	PROPERTY_STRUCT_ARRAY(ScriptActionNode, ScriptActions, 50);
};

#endif
