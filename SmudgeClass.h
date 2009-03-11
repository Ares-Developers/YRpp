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
	//Static
	static DynamicVectorClass<SmudgeClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SmudgeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	SmudgeClass(SmudgeTypeClass* pType) : ObjectClass(false)
		JMP_THIS(0x6B4A50);

protected:
	SmudgeClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(SmudgeTypeClass*,	Type);

};

#endif
