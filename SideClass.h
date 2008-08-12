/*
	Sides
*/

#ifndef SIDE_H
#define SIDE_H

#include <AbstractTypeClass.h>

class SideClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(SideClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x6A4740);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6A4780);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6A48A0);}

	//Destructor
	virtual ~SideClass()		{THISCALL(0x6A4610);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_Side;}
	virtual int					Size(){return sizeof(SideClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x6A4710);}

	//Constructor
	SideClass(const char* id):AbstractTypeClass(false)
								{PUSH_VAR32(id);THISCALL(0x6A4550);}

protected:
	SideClass():AbstractTypeClass(false){};
	SideClass(bool X):AbstractTypeClass(X){};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(TypeList<int>,		HouseTypes);	//indices!

};

#endif
