/*
	RadSites
*/

#pragma once

#include <FileSystem.h>
#include <AbstractClass.h>

class ObjectClass;

class NOVTABLE AlphaShapeClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::AlphaShape;

	//Static
	static constexpr constant_ptr<DynamicVectorClass<AlphaShapeClass*>, 0x88A0F0u> const Array{};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~AlphaShapeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//Constructor
	AlphaShapeClass(ObjectClass* pObj, int nX, int nY) noexcept
		: AlphaShapeClass(noinit_t())
	{ JMP_THIS(0x420960); }

protected:
	explicit __forceinline AlphaShapeClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ObjectClass* AttachedTo;	//To which object is this AlphaShape attached?
	RectangleStruct Rect;
	SHPStruct* AlphaImage;
	bool IsObjectGone;	//Set if AttachedTo is NULL.
};
