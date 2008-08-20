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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x5FDF10);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x5FD8F0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x5FD950);}

	//Destructor
	virtual ~OverlayClass()		{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x5FDF70);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_Overlay;}
	virtual int					Size(){return sizeof(OverlayClass);}

	//ObjectClass
	virtual ObjectTypeClass*	GetType(){return Type;}

	virtual bool				Put(CoordStruct* pCrd,eDirection dFaceDir){PUSH_VAR32(dFaceDir);PUSH_VAR32(pCrd);
								THISCALL(0x5FD270);}
	virtual void				Draw(Point2D* pCoords,DWORD dwUnk){}
	virtual void				vt_entry_118(DWORD dwUnk,DWORD dwUnk2)
								{PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);THISCALL(0x5FD970);}
	virtual bool				SetLayer(eLayer value){PUSH_VAR32(value);THISCALL(0x5FC570);}

	//Constructor
	//Constructor
	OverlayClass(OverlayTypeClass* pType):ObjectClass(false)
			{PUSH_VAR32(pType);THISCALL(0x5FC380);}

protected:
	OverlayClass():ObjectClass(false){}
	OverlayClass(bool X):ObjectClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(OverlayTypeClass*,		Type);
};

#endif

