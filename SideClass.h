/*
	Sides
*/

#pragma once

#include <AbstractTypeClass.h>

class NOVTABLE SideClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::Side;

	//Array
	ABSTRACTTYPE_ARRAY(SideClass, 0x8B4120u);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~SideClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	SideClass(const char* pID) noexcept
		: SideClass(noinit_t())
	{ JMP_THIS(0x6A4550); }

protected:
	explicit __forceinline SideClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TypeList<int> HouseTypes;	//indices!

};
