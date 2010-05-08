/*
	LightSource - used for light posts and radiation
*/

#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <AbstractClass.h>

class LightSourceClass : public AbstractClass
{
public:
	enum {AbsID = abs_LightSource};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~LightSourceClass() RX;

	//AbstractClass
	virtual eAbstractType		WhatAmI() R0;
	virtual int					Size() R0;

	//Constructor
	LightSourceClass(
		CoordStruct Crd,
		int nVisibility,
		int nIntensity,
		TintStruct Tint) : AbstractClass(false)
			{ JMP_THIS(0x554760); }

	//non-virtual
	void Activate(DWORD dwZero = 0)	//Start lighting
		{ JMP_THIS(0x554A60); }

protected:
	LightSourceClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int LightIntensity;
	TintStruct LightTint;
	int unknown_int_30;
	CoordStruct Location;
	int LightVisibility;
	bool Activated;
};

#endif
