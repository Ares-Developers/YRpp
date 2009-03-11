/*
	LightSource - used for light posts and radiation
*/

#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H

#include <AbstractClass.h>

class LightSourceClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

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
			JMP_THIS(0x554760);

	//non-virtual
	void Activate(DWORD dwZero = 0)	//Start lighting
		JMP_THIS(0x554A60);

protected:
	LightSourceClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(int, LightIntensity);
	PROPERTY_STRUCT(TintStruct, LightTint);
	PROPERTY(int, unknown_int_30);
	PROPERTY_STRUCT(CoordStruct, Location);
	PROPERTY(int, LightVisibility);
	PROPERTY(bool, Activated);
};

#endif
