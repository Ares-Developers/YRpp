/*
	RadSites
*/

#ifndef RADSITE_H
#define RADSITE_H

#include <AbstractClass.h>

class LightSourceClass;
class WeaponTypeClass;

class RadSiteClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<RadSiteClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~RadSiteClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//CUSTOM Constructor (to make things easier)
	RadSiteClass(CellStruct nBaseCoords, int nSpread, int nRadLevel):AbstractClass(false)
	{
		THISCALL(0x65B1E0);
		BaseCell = nBaseCoords;
		Spread = nSpread;
		Spread_Leptons = (nSpread << 8) + 0x80;

		PUSH_VAR32(nRadLevel);
		THISCALL(0x65B4F0);
	}

	//non-virtual
public:
	//Start irradiating an area. Be sure to set the BaseCell, Spread and RadLevel first!
	void Activate()
		{ JMP_THIS(0x65B580); }

	//Add this RadLevel to the current radiation.
	void Add(int nRadLevel)
		{ JMP_THIS(0x65B530); }

protected:
	RadSiteClass() : AbstractClass(false) JMP_THIS(0x65B1E0);
	RadSiteClass(bool) : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(LightSourceClass*,    LightSource);
	PROPERTY_STRUCT(TimerStruct,   RadLevelTimer);
	PROPERTY_STRUCT(TimerStruct,   RadLightTimer);
	PROPERTY_STRUCT(CellStruct,    BaseCell);
	PROPERTY(int,       Spread);	//CellSpread in cells.
	PROPERTY(int,       Spread_Leptons);	//CellSpread in leptons.
	PROPERTY(int,       RadLevel);
	PROPERTY(DWORD,     unknown_50);
	PROPERTY(DWORD,     unknown_54);
	PROPERTY(DWORD,     unknown_58);	//unused?
	PROPERTY(DWORD,     unknown_5C);	//unused?
	PROPERTY(DWORD,     unknown_60);	//unused?
	PROPERTY(DWORD,     unknown_64);
	PROPERTY(DWORD,     unknown_68);
	PROPERTY(DWORD,     RadLevel_Start);
	PROPERTY(DWORD,     RadLevel_Current);
};

#endif
