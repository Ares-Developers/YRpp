/*
	Supers
*/

#ifndef SUPER_H
#define SUPER_H

#include <SuperWeaponTypeClass.h>

//Forward declarations
class HouseClass;

class SuperClass : public AbstractClass
{
public:
	//Static
	//static DynamicVectorClass<SuperClass*>* Array; //- per player

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x6CDEB0);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6CDEF0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6CDFD0);}

	//AbstractClass
	virtual void				PointerExpired(void* p,bool bUnknown)
								{PUSH_VAR8(bUnknown);PUSH_VAR32(p);THISCALL(0x6CDFF0);}
	virtual eAbstractType		WhatAmI(){return abs_Super;}
	virtual int					Size(){return sizeof(SuperClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x6CE020);}

	//Destructor
	virtual ~SuperClass()							{THISCALL(0x6CB120);}

	//Constructor
	SuperClass(SuperWeaponTypeClass* pSWType,HouseClass* pOwner):AbstractClass(false)
													{
													PUSH_VAR32(pOwner);
													PUSH_VAR32(pSWType);
													THISCALL(0x6CAF90);
													}

protected:
	SuperClass():AbstractClass(false){}
	SuperClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(DWORD,					unknown_24);
	PROPERTY(SuperWeaponTypeClass*,	Type);
	PROPERTY(HouseClass*,			Owner);
	PROPERTY_STRUCT(TimerStruct,			RechargeTimer);
	PROPERTY(DWORD,					unknown_3C);		//unused?
	PROPERTY(bool,					unknown_bool_40);
	PROPERTY(DWORD,					unknown_44);		//unused?
	PROPERTY(DWORD,					unknown_48);
	PROPERTY(DWORD,					unknown_4C);
	PROPERTY(int,					unknown_int_50);
	PROPERTY(DWORD,					unknown_54);		//unused?
	PROPERTY(DWORD,					unknown_58);		//unused?
	PROPERTY(DWORD,					unknown_5C);		//unused?
	PROPERTY(bool,					unknown_bool_60);
	PROPERTY_STRUCT(CellStruct,			ChronoMapCoords);
	PROPERTY(bool,					unknown_bool_6C);
	PROPERTY(bool,					unknown_bool_6D);
	PROPERTY(bool,					unknown_bool_6E);
	PROPERTY(bool,					IsCharged);
	PROPERTY(bool,					HasPower);
	PROPERTY(int,					unknown_int_74);
	PROPERTY(DWORD,					unknown_78);
	PROPERTY(DWORD,					unknown_7C);
};

#endif
