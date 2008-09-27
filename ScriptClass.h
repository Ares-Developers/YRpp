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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6915F0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x691630); }
	virtual HRESULT _stdcall Save(IStream* pStm,     BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x691690); }

	//Destructor
	virtual ~ScriptClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x691EE0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_ScriptType; }
	virtual int Size()
		{ return sizeof(ScriptTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6914E0); }

	ScriptActionNode* GetCurrentAction(ScriptActionNode *buffer)
		{ PUSH_VAR32(buffer); THISCALL(0x691500); }

	ScriptActionNode* GetNextAction(ScriptActionNode *buffer)
		{ PUSH_VAR32(buffer); THISCALL(0x691540); }

	bool Reset()
		{ this->idxCurrentLine = -1; return true; } 

	bool SetCurrentLine(int idx)
		{ this->idxCurrentLine = idx; return true; } 

	bool NextAction()
		{ ++this->idxCurrentLine; return this->HasNextAction(); } 

	bool HasNextAction()
		{ return this->idxCurrentLine < this->Type->get_ActionsCount(); } 

	//Constructor
	ScriptClass(ScriptTypeClass *pType):AbstractClass(false)
		{ PUSH_VAR32(pType); THISCALL(0x6913C0); }

protected:
	ScriptClass():AbstractClass(false)
		{ }
	ScriptClass(bool X):AbstractClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ScriptTypeClass *, Type);
	PROPERTY(int,      field_28);
	PROPERTY(int,      idxCurrentLine);

};

#endif
