/*
	OverlayTypes are initialized by INI files.
*/

#ifndef OVERLAYTYPE_H
#define OVERLAYTYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;

class OverlayTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(OverlayTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~OverlayTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest,CoordStruct* pSrc) R0;

	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//OverlayTypeClass
	virtual void Draw(Point2D* pClientCoords, RectangleStruct* pClipRect, int nFrame) RX;

	//Constructor
	OverlayTypeClass(const char* pID) : ObjectTypeClass(false)
		JMP_THIS(0x5FE250);

protected:
	OverlayTypeClass() : ObjectTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,                ArrayIndex);
	PROPERTY(eLandType,          LandType);
	PROPERTY(AnimTypeClass*,     CellAnim);
	PROPERTY(int,                DamageLevels);
	PROPERTY(int,                Strength);
	PROPERTY(bool,               Wall);
	PROPERTY(bool,               Tiberium);
	PROPERTY(bool,               Crate);
	PROPERTY(bool,               CrateTrigger);
	PROPERTY(bool,               NoUseTileLandType);
	PROPERTY(bool,               IsVeinholeMonster);
	PROPERTY(bool,               IsVeins);
	PROPERTY(bool,               ImageLoaded);	//not INI
	PROPERTY(bool,               Explodes);
	PROPERTY(bool,               ChainReaction);
	PROPERTY(bool,               Overrides);
	PROPERTY(bool,               DrawFlat);
	PROPERTY(bool,               IsRubble);
	PROPERTY(bool,               IsARock);
	PROPERTY_STRUCT(ColorStruct, RadarColor);

};

#endif
