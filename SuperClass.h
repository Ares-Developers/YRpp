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
	bool HasPower;
	int ReadinessFrame; // when did it become ready?
	DWORD unknown_78;
	DWORD ChargeDrainState;
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
