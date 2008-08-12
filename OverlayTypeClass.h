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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x5FEC30);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x5FEAF0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x5FEC10);}

	//Destructor
	virtual ~OverlayTypeClass()	{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x5FEF30);};

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_OverlayType;}
	virtual int					Size(){return sizeof(OverlayTypeClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x5FEA50);}
	virtual int					GetArrayIndex(){return ArrayIndex;}

	//AbstractTypeClass
	virtual bool				LoadFromINI(CCINIClass* pINI){PUSH_VAR32(pINI);THISCALL(0x5FE770);}

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest,CoordStruct* pSrc)
		{ PUSH_VAR32(pSrc); PUSH_VAR32(pDest); THISCALL(0x5FEA30);}

	virtual bool				SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner)
								{PUSH_VAR32(pOwner);PUSH_VAR32(pMapCoords);THISCALL(0x5FE530);}
	virtual ObjectClass*		CreateObject(HouseClass* pOwner){PUSH_VAR32(pOwner);THISCALL(0x5FE570);}
	virtual void				vt_entry_90(DWORD dwUnk){PUSH_VAR32(dwUnk);THISCALL(0x5FE4C0);}
	virtual SHPStruct*			GetImage(){THISCALL(0x5FEDE0);}

	//OverlayTypeClass
	virtual void				Draw(Point2D* pClientCoords,RectangleStruct* pClipRect,int nFrame)
								{PUSH_VAR32(nFrame);PUSH_VAR32(pClipRect);PUSH_VAR32(pClientCoords);
								THISCALL(0x5FE5A0);}

	//Constructor
	OverlayTypeClass(const char* pID):ObjectTypeClass(false)
										{PUSH_VAR32(pID);THISCALL(0x5FE250);}

protected:
	OverlayTypeClass(bool X):ObjectTypeClass(X){};
	OverlayTypeClass():ObjectTypeClass(false){};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,					ArrayIndex);
	PROPERTY(eLandType,				LandType);
	PROPERTY(AnimTypeClass*,		CellAnim);
	PROPERTY(int,					DamageLevels);
	PROPERTY(int,					Strength);
	PROPERTY(bool,					Wall);
	PROPERTY(bool,					Tiberium);
	PROPERTY(bool,					Crate);
	PROPERTY(bool,					CrateTrigger);
	PROPERTY(bool,					NoUseTileLandType);
	PROPERTY(bool,					IsVeinholeMonster);
	PROPERTY(bool,					IsVeins);
	PROPERTY(bool,					ImageLoaded);	//not INI
	PROPERTY(bool,					Explodes);
	PROPERTY(bool,					ChainReaction);
	PROPERTY(bool,					Overrides);
	PROPERTY(bool,					DrawFlat);
	PROPERTY(bool,					IsRubble);
	PROPERTY(bool,					IsARock);
	PROPERTY_STRUCT(ColorStruct,			RadarColor);

};

#endif
