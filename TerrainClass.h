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
	//global array
	static DynamicVectorClass<TerrainClass*>* Array;

	//Constructor, Destructor
	TerrainClass(TerrainTypeClass* tt,CellStruct coords):ObjectClass(false)
													{
													CellStruct* c=&coords;
													PUSH_VAR32(c);
													PUSH_VAR32(tt);
													THISCALL(0x71BB90);
													}
	virtual ~TerrainClass()							{THISCALL(0x71B7B0);}

	//identification
	virtual eAbstractType WhatAmI(){return abs_Terrain;}

protected:
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
