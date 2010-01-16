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
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

protected:
	TerrainClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,				unknown_AC);
	PROPERTY(BYTE,				unknown_B0);
	PROPERTY_STRUCT(TimerStruct,		unknown_timer_B4);
	PROPERTY(DWORD,				unknown_C0);
	PROPERTY(DWORD,				unknown_C4);
	PROPERTY(TerrainTypeClass*, Type);
	PROPERTY(BYTE,				unknown_CC);
	PROPERTY(BYTE,				unknown_CD);
	PROPERTY(DWORD,				unknown_D0);
	PROPERTY(DWORD,				unknown_D4);
	PROPERTY(DWORD,				unknown_D8);
	PROPERTY(DWORD,				unknown_DC);

};

#endif
