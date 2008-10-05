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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~AlphaShapeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//Constructor
	AlphaShapeClass(ObjectClass* pObj,int nX,int nY) : AbstractClass(false)
		JMP_THIS(0x420960);

protected:
	AlphaShapeClass() : AbstractClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(ObjectClass*, AttachedTo);	//To which object is this AlphaShape attached?
	PROPERTY_STRUCT(RectangleStruct, Rect);
	PROPERTY(SHPStruct*, AlphaImage);
	PROPERTY(bool, IsObjectGone);	//Set if AttachedTo is NULL.
};

#endif
