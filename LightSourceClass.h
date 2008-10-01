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
	LightSourceClass(CoordStruct Crd,int nVisibility,int nIntensity,TintStruct Tint):AbstractClass(false)
										{
										int X=Crd.X;
										int Y=Crd.Y;
										int Z=Crd.Z;
										int RedTint=Tint.Red;
										int GreenTint=Tint.Green;
										int BlueTint=Tint.Blue;
										PUSH_VAR32(BlueTint);
										PUSH_VAR32(GreenTint);
										PUSH_VAR32(RedTint);
										PUSH_VAR32(nIntensity);
										PUSH_VAR32(nVisibility);
										PUSH_VAR32(Z);
										PUSH_VAR32(Y);
										PUSH_VAR32(X);
										THISCALL(0x554760);
										}

	//non-virtual
	void Activate(){PUSH_IMM(0);THISCALL(0x554A60);}	//Start lighting

protected:
	LightSourceClass():AbstractClass(false){}
	LightSourceClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(int,				LightIntensity);
	PROPERTY_STRUCT(TintStruct,		LightTint);
	PROPERTY(int,				unknown_int_30);
	PROPERTY_STRUCT(CoordStruct,		Location);
	PROPERTY(int,				LightVisibility);
	PROPERTY(bool,				Activated);
};

#endif
