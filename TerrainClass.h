/*
	Trees
*/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: VTABLE NEEDS TO BE DONE!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef TERRAIN_H
#define TERRAIN_H

#include <ObjectClass.h>
#include <TerrainTypeClass.h>

class TerrainClass : public ObjectClass
{
public:
	enum {AbsID = abs_Terrain};

	//global array
	static DynamicVectorClass<TerrainClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Constructor, Destructor
	TerrainClass(TerrainTypeClass* tt, CellStruct coords) : ObjectClass(false)
		{ JMP_THIS(0x71BB90); }

	virtual ~TerrainClass() RX;

	//identification
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

protected:
	TerrainClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_AC;
	BYTE unknown_B0;
	TimerStruct unknown_timer_B4;
	DWORD unknown_C0;
	DWORD unknown_C4;
	TerrainTypeClass* Type;
	BYTE unknown_CC;
	BYTE unknown_CD;
	DWORD unknown_D0;
	DWORD unknown_D4;
	DWORD unknown_D8;
	DWORD unknown_DC;

};

#endif
