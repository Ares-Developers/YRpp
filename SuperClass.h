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
	static CellStruct &DefaultCoords; //0xB0C000

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Destructor
	virtual ~SuperClass() RX;

	// non virtual
	void CreateChronoAnim(CoordStruct Coords)
		{ JMP_THIS(0x6CB3A0); }

	void Reset()
		{ JMP_THIS(0x6CE0B0); }

	// was the setting successful? (did we have to change the state (true) or was it already in the same hold state(false))
	bool SetOnHold(bool status)
		{ JMP_THIS(0x6CB4D0); }

	// true if this was ->Granted
	bool Lose()
		{ JMP_THIS(0x6CB7B0); }

	bool IsPowered()
		{ return this->Type->IsPowered; }

	void Launch(CellStruct *Cell, bool IsPlayer)
		{ JMP_THIS(0x6CC390); }

	char CanFire()
		{ JMP_THIS(0x6CC360); }

	void SetReadiness(bool Ready) // this->IsCharged = Ready
		{ JMP_THIS(0x6CB820); }

	char StopPreclickAnim(bool /*IsPlayer*/) // if this is a PostClick SW, firing it does this
		{ JMP_THIS(0x6CB830); }

	char ClickFire(bool IsPlayer, CellStruct *Coords) // calls Launch after printing Lightning Storm warning and other fluff
		{ JMP_THIS(0x6CB920); }

	bool HasChargeProgressed(bool IsPlayer) // true if the charge has changed (charge overlay on the cameo)
		{ JMP_THIS(0x6CBCA0); }               // triggers the EVA Announcement if it's ready

	signed int GetCameoChargeState() // which cameo charge overlay frame to show
		{ JMP_THIS(0x6CBEE0); }

	void SetCharge(int Percentage)
		{ JMP_THIS(0x6CC1E0); }

	int GetRechargeTime() // the time it takes this SW to recharge fully
		{ JMP_THIS(0x6CC260); }

	void SetRechargeTime(int time) // makes this SW rechange in this many frames, as opposed to [Type]RechargeTime
		{ JMP_THIS(0x6CC280); }

	void ResetRechargeTime() // nullifies the previous call
		{ JMP_THIS(0x6CC290); }

	wchar_t *NameReadiness() // the string to be displayed over the SW in the sidebar - "Ready" or ChargeDrain state
		{ JMP_THIS(0x6CC2B0); }

	bool ShouldDrawProgress() // sidebar
		{ JMP_THIS(0x6CDE90); }

	bool ShouldFlashTab() // sidebar
		{ JMP_THIS(0x6CE1A0); }


	//Constructor
	SuperClass(SuperWeaponTypeClass* pSWType, HouseClass* pOwner) : AbstractClass(false)
		{ JMP_THIS(0x6CAF90); }

protected:
	SuperClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_24;
	SuperWeaponTypeClass* Type;
	HouseClass* Owner;
	TimerStruct RechargeTimer;
	DWORD unknown_3C;		//unused?
	bool unknown_bool_40;
	DWORD unknown_44;		//unused?
	DWORD unknown_48;
	DWORD unknown_4C;
	int SpecialSoundDuration; // see 0x6CD14F
	CoordStruct SpecialSoundLocation;		//unused?
	bool unknown_bool_60;          // 0x60
	CellStruct ChronoMapCoords;  // 0x62
	AnimClass * Animation;                // 0x68
	bool unknown_bool_6C;
	bool Granted;
	bool Quantity; // Stupidity - 0 means unlimited, 1 means one-shot
	bool IsCharged;
	bool IsOnHold;
	int ReadinessFrame; // when did it become ready?
	DWORD unknown_78;
	DWORD ChargeDrainState;
};

class LightningStorm
{
public:
	static CoordStruct &EmptyCoords;
	static double &CloudHeightFactor;

	static DynamicVectorClass<AnimClass*>* CloudsPresent;
	static DynamicVectorClass<AnimClass*>* CloudsManifesting;
	static DynamicVectorClass<AnimClass*>* BoltsPresent;

	static CellStruct Coords()
		{ CellStruct retval; MEM_READ32(retval, 0xA9F9CC); return retval; }
	static void Coords(CellStruct value)
		{ MEM_WRITE32(0xA9F9CC, value); }

	static HouseClass *Owner()
		{ HouseClass *retval; MEM_READ32(retval, 0xA9FACC); return retval; }
	static void Owner(HouseClass *value)
		{ MEM_WRITE32(0xA9FACC, value); }

	static int Deferment()
		{ int retval; MEM_READ32(retval, 0xA9FAB8); return retval; }
	static void Deferment(int value)
		{ MEM_WRITE32(0xA9FAB8, value); }

	static int Duration()
		{ int retval; MEM_READ32(retval, 0x827FC4); return retval; }
	static void Duration(int value)
		{ MEM_WRITE32(0x827FC4, value); }

	static int Status()
		{ int retval; MEM_READ32(retval, 0xA9FABC); return retval; }
	static void Status(int value)
		{ MEM_WRITE32(0xA9FABC, value); }

	static int StartTime()
		{ int retval; MEM_READ32(retval, 0x827FC0); return retval; }
	static void StartTime(int value)
		{ MEM_WRITE32(0x827FC0, value); }

	static byte Active()
		{ byte retval; MEM_READ8(retval, 0xA9FAB4); return retval; }
	static void Active(byte value)
		{ MEM_WRITE8(0xA9FAB4, value); }

	static byte TimeToEnd()
		{ byte retval; MEM_READ8(retval, 0xA9FAD0); return retval; }
	static void TimeToEnd(byte value)
		{ MEM_WRITE8(0xA9FAD0, value); }

	static void Start(int Duration, int Deferment, CellStruct Coords, HouseClass *pOwner)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(Coords); SET_REG32(EDX, Deferment); SET_REG32(ECX, Duration);
			CALL(0x539EB0); }

	static void RequestStop()
		{ CALL(0x53A090); }

	static bool HasDeferment()
		{ return Active() && Deferment() > 0; }

	static void Strike(CellStruct Coords)
		{ PUSH_VAR32(Coords); CALL(0x53A140); }

	static void Strike2(CoordStruct Coords)
		{ JMP_STD(0x53A300); }

	static void PrintMessage()
		{ CALL(0x53AE00); }
};

class PsyDom
{
public:
	static CellStruct Coords()
		{ CellStruct retval; MEM_READ32(retval, 0xA9FA48); return retval; }
	static void Coords(CellStruct value)
		{ MEM_WRITE32(0xA9FA48, value); }

	static HouseClass *Owner()
		{ HouseClass *retval; MEM_READ32(retval, 0xA9FAC8); return retval; }
	static void Owner(HouseClass* value)
		{ MEM_WRITE32(0xA9FAC8, value); }

	static AnimClass *Anim()
		{ AnimClass *retval; MEM_READ32(retval, 0xA9FAC4); return retval; }
	static void Anim(AnimClass* value)
		{ MEM_WRITE32(0xA9FAC4, value); }

	static int Status()
		{ int retval; MEM_READ32(retval, 0xA9FAC0); return retval; }
	static void Status(int value)
		{ MEM_WRITE32(0xA9FAC0, value); }

	static void Start(HouseClass *pOwner, CellStruct Coords)
		{ PUSH_VAR32(Coords); SET_REG32(ECX, pOwner);
			CALL(0x53AE50); }

	static void Update()
		{ CALL(0x53AF40); }

	static void Fire()
		{ CALL(0x53B080); }

	static void PrintMessage()
		{ CALL(0x53B410); }

	static bool Active()
		{ CALL(0x53B400); }
};

class ChronoScreenEffect
{
public:
	static int Status()
		{ int retval; MEM_READ32(retval, 0xA9FAB0); return retval; }
	static void Status(int value)
		{ MEM_WRITE32(0xA9FAB0, value); }

	static int Duration()
		{ int retval; MEM_READ32(retval, 0xA9FA98); return retval; }
	static void Duration(int value)
		{ MEM_WRITE32(0xA9FA98, value); }

	static void Start(int duration)
		{ SET_REG32(ECX, duration);
			CALL(0x53B460); }

	static void Update()
		{ CALL(0x53B560); }

	static bool Active()
		{ CALL(0x53BAD0); }
};

class NukeFlash
{
public:
	static int StartTime()
		{ int retval; MEM_READ32(retval, 0x827FC8); return retval; }
	static void StartTime(int value)
		{ MEM_WRITE32(0x827FC8, value); }

	static int Duration()
		{ int retval; MEM_READ32(retval, 0x827FCC); return retval; }
	static void Duration(int value)
		{ MEM_WRITE32(0x827FCC, value); }
};

#endif
