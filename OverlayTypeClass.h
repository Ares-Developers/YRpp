/*
	OverlayTypes are initialized by INI files.
*/

#pragma once

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;

class NOVTABLE OverlayTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::OverlayType;

	//Array
	ABSTRACTTYPE_ARRAY(OverlayTypeClass, 0xA83D80u);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~OverlayTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest,CoordStruct* pSrc) const R0;

	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//OverlayTypeClass
	virtual void Draw(Point2D* pClientCoords, RectangleStruct* pClipRect, int nFrame) RX;

	//Constructor
	OverlayTypeClass(const char* pID) noexcept
		: OverlayTypeClass(noinit_t())
	{ JMP_THIS(0x5FE250); }

protected:
	explicit __forceinline OverlayTypeClass(noinit_t) noexcept
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int                ArrayIndex;
	LandType           LandType;
	AnimTypeClass*     CellAnim;
	int                DamageLevels;
	int                Strength;
	bool               Wall;
	bool               Tiberium;
	bool               Crate;
	bool               CrateTrigger;
	bool               NoUseTileLandType;
	bool               IsVeinholeMonster;
	bool               IsVeins;
	bool               ImageLoaded;	//not INI
	bool               Explodes;
	bool               ChainReaction;
	bool               Overrides;
	bool               DrawFlat;
	bool               IsRubble;
	bool               IsARock;
	ColorStruct RadarColor;

};
