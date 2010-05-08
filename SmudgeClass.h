/*
	Smudges
*/

#ifndef SMUDGE_H
#define SMUDGE_H

#include <ObjectClass.h>
#include <SmudgeTypeClass.h>

class SmudgeClass : public ObjectClass
{
public:
	enum {AbsID = abs_Smudge};

	//Static
	static DynamicVectorClass<SmudgeClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SmudgeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	SmudgeClass(SmudgeTypeClass* pType) : ObjectClass(false)
		{ JMP_THIS(0x6B4A50); }

protected:
	SmudgeClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	SmudgeTypeClass* Type;

};

#endif
