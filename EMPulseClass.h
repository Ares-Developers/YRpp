/*
	EMP - no, you're NOT seeing things :P
*/

#pragma once

#include <AbstractClass.h>

class NOVTABLE EMPulseClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::EMPulse;

	//Static
	static constexpr constant_ptr<DynamicVectorClass<EMPulseClass*>, 0x8A3870u> const Array{};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~EMPulseClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	EMPulseClass(CellStruct dwCrd, int nSpread, int nDuration,
		TechnoClass* pGenerator) noexcept : EMPulseClass(noinit_t())
	{ JMP_THIS(0x4C52B0); }

protected:
	explicit __forceinline EMPulseClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CellStruct BaseCoords;
	int Spread;
	int CreationTime;	//frame in which this EMP got created
	int Duration;
};
