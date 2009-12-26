/*
	Overlays (mainly Ore and Gems)
*/

#ifndef OVERLAY_H
#define OVERLAY_H

/*

;GEF in case it wasn't intuitively obvious from the above, this list mirrors an object enumeration
;in overlay.hh. If you want to add something to this list, make sure you add to the enumeration
;or get a programmer to do it for you

 * Ironically, the list they had in overlay.hh doesn't seem to have been updated that much since TS.

 */

#define OVERLAY_VEINS 0x7E
#define OVERLAY_VEINHOLE 0xA7
#define OVERLAY_VEINHOLEDUMMY 0xB2

#define OVERLAY_BRIDGEHEAD11 0x18
#define OVERLAY_BRIDGEHEAD12 0x19

#define OVERLAY_BRIDGEHEAD21 0xED
#define OVERLAY_BRIDGEHEAD22 0xEE

#define OVERLAY_LOBRIDGE1 0x7A
#define OVERLAY_LOBRIDGE2 0x7B
#define OVERLAY_LOBRIDGE3 0x7C
#define OVERLAY_LOBRIDGE4 0x7D

#include <ObjectClass.h>
#include <OverlayTypeClass.h>

class OverlayClass : public ObjectClass
{
public:
	enum {AbsID = abs_Overlay};

	//Static
	static DynamicVectorClass<OverlayClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~OverlayClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	OverlayClass(OverlayTypeClass* pType) : ObjectClass(false)
		JMP_THIS(0x5FC380);

protected:
	OverlayClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(OverlayTypeClass*, Type);
};

#endif

