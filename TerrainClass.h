/*
	Trees
*/

#pragma once

#include <ObjectClass.h>
#include <TerrainTypeClass.h>
#include <ProgressTimer.h>

class NOVTABLE TerrainClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::Terrain;

	//global array
	static DynamicVectorClass<TerrainClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TerrainClass() RX;

	//identification
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor, Destructor
	TerrainClass(TerrainTypeClass* tt, CellStruct coords) noexcept
		: TerrainClass(noinit_t())
	{ JMP_THIS(0x71BB90); }

protected:
	explicit __forceinline TerrainClass(noinit_t) noexcept
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ProgressTimer Animation;
	TerrainTypeClass* Type;
	bool IsBurning; // this terrain object has been ignited
	bool TimeToDie; // finish the animation and uninit
	RectangleStruct unknown_rect_D0;

};
