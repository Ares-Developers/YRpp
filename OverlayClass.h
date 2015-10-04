/*
	Overlays (mainly Ore and Gems)
*/

#pragma once

/*

;GEF in case it wasn't intuitively obvious from the above, this list mirrors an object enumeration
;in overlay.hh. If you want to add something to this list, make sure you add to the enumeration
;or get a programmer to do it for you

 * Ironically, the list they had in overlay.hh doesn't seem to have been updated that much since TS.

 */

#define OVERLAY_GASAND 0x00
#define OVERLAY_GAWALL 0x02
#define OVERLAY_NAWALL 0x1A

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

class NOVTABLE OverlayClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::Overlay;

	//Static
	static DynamicVectorClass<OverlayClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~OverlayClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	OverlayClass(OverlayTypeClass* pType) noexcept
		: OverlayClass(noinit_t())
	{ JMP_THIS(0x5FC380); }

protected:
	explicit __forceinline OverlayClass(noinit_t) noexcept
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	OverlayTypeClass* Type;
};
