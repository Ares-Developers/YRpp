/*
	Actual AI Team Scripts
*/

#ifndef SCRIPT_H
#define SCRIPT_H

#include <AbstractClass.h>

//forward declarations
#include <ScriptTypeClass.h>

class ScriptClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~ScriptClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	ScriptActionNode* GetCurrentAction(ScriptActionNode *buffer)
		JMP_THIS(0x691500);

	ScriptActionNode* GetNextAction(ScriptActionNode *buffer)
		JMP_THIS(0x691540);

	bool Reset()
		{ this->idxCurrentLine = -1; return true; } 

	bool SetCurrentLine(int idx)
		{ this->idxCurrentLine = idx; return true; } 

	bool NextAction()
		{ ++this->idxCurrentLine; return this->HasNextAction(); } 

	bool HasNextAction()
		{ return this->idxCurrentLine < this->Type->get_ActionsCount(); } 

	//Constructor
	ScriptClass(ScriptTypeClass *pType = NULL) : AbstractClass(false)
		JMP_THIS(0x6913C0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ScriptTypeClass *, Type);
	PROPERTY(int, field_28);
	PROPERTY(int, idxCurrentLine);

};

#endif
