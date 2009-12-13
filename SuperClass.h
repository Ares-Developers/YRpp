/*
	Supers
*/

#ifndef SUPER_H
#define SUPER_H

#include <SuperWeaponTypeClass.h>

//Forward declarations
class AnimClass;
class HouseClass;

class SuperClass : public AbstractClass
{
public:
	enum {AbsID = abs_Super};

	//Static
	//static DynamicVectorClass<SuperClass*>* Array; //- per player

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Destructor
	virtual ~SuperClass() RX;

	// non virtual
	void CreateChronoAnim(CoordStruct Coords)
		JMP_THIS(0x6CB3A0);

	//Constructor
	SuperClass(SuperWeaponTypeClass* pSWType, HouseClass* pOwner) : AbstractClass(false)
		JMP_THIS(0x6CAF90);

protected:
	SuperClass() : AbstractClass(false) { }

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
	PROPERTY(bool,					unknown_bool_60);          // 0x60 
	PROPERTY_STRUCT(CellStruct,			ChronoMapCoords);  // 0x62
	PROPERTY(AnimClass *,		Animation);                // 0x68
	PROPERTY(bool,					unknown_bool_6C);
	PROPERTY(bool,					unknown_bool_6D);
	PROPERTY(bool,					Quantity); // Stupidity - 0 means unlimited, 1 means one-shot
	PROPERTY(bool,					IsCharged);
	PROPERTY(bool,					HasPower);
	PROPERTY(int,					ReadinessFrame); // when did it become ready?
	PROPERTY(DWORD,					unknown_78);
	PROPERTY(DWORD,					ChargeDrainState);
};

class LightningStorm
{
public:
	static CellStruct Coords()
		{ CellStruct retval; MEM_READ32(retval, 0xA9F9CC); return retval; }
	static HouseClass *Owner()
		{ HouseClass *retval; MEM_READ32(retval, 0xA9FACC); return retval; }
	static int Deferment()
		{ int retval; MEM_READ32(retval, 0xA9FAB8); return retval; }
	static int Status()
		{ int retval; MEM_READ32(retval, 0xA9FABC); return retval; }
	static byte Active()
		{ byte retval; MEM_READ8(retval, 0xA9FAB4); return retval; }
	static byte TimeToEnd()
		{ byte retval; MEM_READ8(retval, 0xA9FAD0); return retval; }
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
public:
	static CellStruct Coords()
		{ CellStruct retval; MEM_READ32(retval, 0xA9FA48); return retval; }
	static HouseClass *Owner()
		{ HouseClass *retval; MEM_READ32(retval, 0xA9FAC8); return retval; }
	static AnimClass *Anim()
		{ AnimClass *retval; MEM_READ32(retval, 0xA9FAC4); return retval; }
	static int Status()
		{ int retval; MEM_READ32(retval, 0xA9FAC0); return retval; }
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
