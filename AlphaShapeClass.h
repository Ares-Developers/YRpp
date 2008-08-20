/*
	RadSites
*/

#ifndef ALPHASHAPE_H
#define ALPHASHAPE_H

#include <FileSystem.h>
#include <AbstractClass.h>

class ObjectClass;

class AlphaShapeClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<AlphaShapeClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x420D40);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x420DE0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x420E40);}

	//Destructor
	virtual ~AlphaShapeClass()	{THISCALL(0x420C80);}

	//AbstractClass
	virtual void				PointerExpired(void* p,bool bUnknown)
								{PUSH_VAR8(bUnknown);PUSH_VAR32(p);THISCALL(0x420E70);}
	virtual eAbstractType		WhatAmI(){return abs_AlphaShape;}
	virtual int					Size(){return sizeof(AlphaShapeClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x420DA0);}

	//Constructor
	AlphaShapeClass(ObjectClass* pObj,int nX,int nY):AbstractClass(false)
								{PUSH_VAR32(nY);PUSH_VAR32(nX);PUSH_VAR32(pObj);THISCALL(0x65B1E0);}

protected:
	AlphaShapeClass():AbstractClass(false){};
	AlphaShapeClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ObjectClass*,		AttachedTo);	//To which object is this AlphaShape attached?
	PROPERTY_STRUCT(RectangleStruct,	Rect);
	PROPERTY(SHPStruct*,		AlphaImage);
	PROPERTY(bool,				IsObjectGone);	//Set if AttachedTo is NULL.
};

#endif
