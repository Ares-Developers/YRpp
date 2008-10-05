/*
	Overlays (mainly Ore and Gems)
*/

#ifndef OVERLAY_H
#define OVERLAY_H

#include <ObjectClass.h>
#include <OverlayTypeClass.h>

class OverlayClass : public ObjectClass
{
public:
	//Static
	static DynamicVectorClass<OverlayClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~OverlayClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	OverlayClass(OverlayTypeClass* pType = NULL) : ObjectClass(false)
		JMP_THIS(0x5FC380);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(OverlayTypeClass*, Type);
};

#endif

