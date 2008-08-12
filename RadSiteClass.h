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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x65B470);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x65B3D0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x65B450);}

	//Destructor
	virtual ~RadSiteClass()		{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x65BED0);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_RadSite;}
	virtual int					Size(){return sizeof(RadSiteClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x65B3B0);}
	virtual void				Update(){THISCALL(0x65B800);}

	//CUSTOM Constructor (to make things easier)
	RadSiteClass(CellStruct nBaseCoords,int nSpread,int nRadLevel):AbstractClass(false){
		THISCALL(0x65B1E0);
		BaseCell=nBaseCoords;
		Spread=nSpread;
		Spread_Leptons=(nSpread<<8)+0x80;
		PUSH_VAR32(nRadLevel);THISCALL(0x65B4F0);
	}

	//non-virtual
public:
	void	Activate(){THISCALL(0x65B580);}	//Start irradiating an area. Be sure to set the BaseCell, Spread and RadLevel first!
	void	Add(int nRadLevel){PUSH_VAR32(nRadLevel);THISCALL(0x65B530);}	//Add this RadLevel to the current radiation.

protected:
	RadSiteClass():AbstractClass(false){THISCALL(0x65B1E0);}
	RadSiteClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(LightSourceClass*,			LightSource);
	PROPERTY_STRUCT(TimerStruct,				RadLevelTimer);
	PROPERTY_STRUCT(TimerStruct,				RadLightTimer);
	PROPERTY_STRUCT(CellStruct,				BaseCell);
	PROPERTY(int,						Spread);	//CellSpread in cells.
	PROPERTY(int,						Spread_Leptons);	//CellSpread in leptons.
	PROPERTY(int,						RadLevel);
	PROPERTY(DWORD,						unknown_50);
	PROPERTY(DWORD,						unknown_54);
	PROPERTY(DWORD,						unknown_58);	//unused?
	PROPERTY(DWORD,						unknown_5C);	//unused?
	PROPERTY(DWORD,						unknown_60);	//unused?
	PROPERTY(DWORD,						unknown_64);
	PROPERTY(DWORD,						unknown_68);
	PROPERTY(DWORD,						RadLevel_Start);
	PROPERTY(DWORD,						RadLevel_Current);
};

#endif
