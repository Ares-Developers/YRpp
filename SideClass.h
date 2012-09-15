/*
	Sides
*/

#ifndef SIDE_H
#define SIDE_H

#include <AbstractTypeClass.h>

class SideClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_Side};

	//Array
	ABSTRACTTYPE_ARRAY(SideClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~SideClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//Constructor
	SideClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x6A4550); }

protected:
	SideClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TypeList<int> HouseTypes;	//indices!

};

#endif
