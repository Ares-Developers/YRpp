/*
	TaskForces as in the AI inis
*/

#ifndef TASKFORCE_H
#define TASKFORCE_H

#include <FileSystem.h>
#include <AbstractTypeClass.h>

//forward declarations
class TechnoTypeClass;

struct TaskForceEntryStruct
{
	TechnoTypeClass* Type;
	int Amount;
};

class TaskForceClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(TaskForceClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6E8710); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6E86A0); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6E8680); }

	//Destructor
	virtual ~TaskForceClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x6E87F0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_TaskForce; }
	virtual int Size()
		{ return sizeof(TaskForceClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6E8750); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x6E8420); }

	//Constructor
	TaskForceClass(const char* pID):AbstractTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x6E7E80); }

protected:
	TaskForceClass():AbstractTypeClass(false)
		{ }
	TaskForceClass(bool X):AbstractTypeClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,     Group);
	PROPERTY(int,     CountEntries);
	PROPERTY_STRUCT_ARRAY(TaskForceEntryStruct, Entries, 0x6);
};

#endif
