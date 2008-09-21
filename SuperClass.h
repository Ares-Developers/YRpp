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
	PROPERTY(int,					SpecialSoundDuration); // see 0x6CD14F
	PROPERTY_STRUCT(CoordStruct,	SpecialSoundLocation);		//unused?
	PROPERTY(bool,					unknown_bool_60);
	PROPERTY_STRUCT(CellStruct,			ChronoMapCoords);
	PROPERTY(bool,					unknown_bool_6C);
	PROPERTY(bool,					unknown_bool_6D);
	PROPERTY(bool,					Quantity);
	PROPERTY(bool,					IsCharged);
	PROPERTY(bool,					HasPower);
	PROPERTY(int,					ReadinessFrame); // when did it become ready?
	PROPERTY(DWORD,					unknown_78);
	PROPERTY(DWORD,					ChargeDrainState);
};

class LightningStorm
{
	static CellStruct Coords()
		{ CellStruct ret; MEM_READ32(ret, 0xA9F9CC); return ret; }
	static HouseClass *Owner()
		{ HouseClass *ret; MEM_READ32(ret, 0xA9FACC); return ret; }
	static int Deferment()
		{ int ret; MEM_READ32(ret, 0xA9FAB8); return ret; }
	static int Status()
		{ int ret; MEM_READ32(ret, 0xA9FABC); return ret; }
	static byte Active()
		{ byte ret; MEM_READ8(ret, 0xA9FAB4); return ret; }
	static byte TimeToEnd()
		{ byte ret; MEM_READ8(ret, 0xA9FAD0); return ret; }
	static void Start(int Duration, int Deferment, CellStruct Coords, HouseClass *pOwner)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(Coords); SET_REG32(EDX, Deferment); SET_REG32(ECX, Duration);
			CALL(0x539EB0); }

	static void RequestStop()
		{ CALL(0x53A090); }

	static bool HasDeferment()
		{ return Active() && Deferment() > 0; }

	static void Strike(CellStruct Coords)
		{ PUSH_VAR32(Coords); CALL(0x53A140); }

	static void PrintMessage()
		{ CALL(0x53AE00); }
};

class PsyDom
{
	static CellStruct Coords()
		{ CellStruct ret; MEM_READ32(ret, 0xA9FA48); return ret; }
	static HouseClass *Owner()
		{ HouseClass *ret; MEM_READ32(ret, 0xA9FAC8); return ret; }
	static AnimClass *Anim()
		{ AnimClass *ret; MEM_READ32(ret, 0xA9FAC4); return ret; }
	static int Status()
		{ int ret; MEM_READ32(ret, 0xA9FAC0); return ret; }
	static void Start(HouseClass *pOwner, CellStruct Coords)
		{ PUSH_VAR32(Coords); SET_REG32(ECX, pOwner);
			CALL(0x53AE50); }

	static void Update()
		{ CALL(0x53AF40); }

	static void Fire()
		{ CALL(0x53B080); }

	static void PrintMessage()
		{ CALL(0x53B410); }
};

#endif
