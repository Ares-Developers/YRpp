/*
	Sides
*/

#ifndef SIDE_H
#define SIDE_H

#include <AbstractTypeClass.h>

class SideClass : public AbstractTypeClass
{
public:

	//Array
	ABSTRACTTYPE_ARRAY(SideClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~SideClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	SideClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x6A4550);

protected:
	SideClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(TypeList<int>, HouseTypes);	//indices!

};

#endif
