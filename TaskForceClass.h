/*
	TaskForces as in the AI inis
*/

#ifndef TASKFORCE_H
#define TASKFORCE_H

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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TaskForceClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	TaskForceClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x6E7E80);

protected:
	TaskForceClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,     Group);
	PROPERTY(int,     CountEntries);
	PROPERTY_STRUCT_ARRAY(TaskForceEntryStruct, Entries, 0x6);
};

#endif
