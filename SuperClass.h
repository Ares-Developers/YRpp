/*
	Supers
*/

#pragma once

#include <SuperWeaponTypeClass.h>

//Forward declarations
class AnimClass;
class HouseClass;

class NOVTABLE SuperClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Super;

	//Static
	static DynamicVectorClass<SuperClass*>* const Array;

	static DynamicVectorClass<SuperClass*>* const ShowTimers;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Destructor
	virtual ~SuperClass() RX;

	// non virtual
	void CreateChronoAnim(CoordStruct coords)
		{ JMP_THIS(0x6CB3A0); }

	void Reset()
		{ JMP_THIS(0x6CE0B0); }

	// was the setting successful? (did we have to change the state (true) or was it already in the same hold state(false))
	bool SetOnHold(bool onHold)
		{ JMP_THIS(0x6CB4D0); }

	bool Grant(bool oneTime, bool announce, bool onHold)
		{ JMP_THIS(0x6CB560); }

	// true if this was ->Granted
	bool Lose()
		{ JMP_THIS(0x6CB7B0); }

	bool IsPowered() const
		{ return this->Type->IsPowered; }

	void Launch(const CellStruct& cell, bool isPlayer)
		{ JMP_THIS(0x6CC390); }

	char CanFire() const
		{ JMP_THIS(0x6CC360); }

	void SetReadiness(bool ready) // this->IsCharged = Ready
		{ JMP_THIS(0x6CB820); }

	char StopPreclickAnim(bool isPlayer) // if this is a PostClick SW, firing it does this
		{ JMP_THIS(0x6CB830); }

	char ClickFire(bool isPlayer, const CellStruct& cell) // calls Launch after printing Lightning Storm warning and other fluff
		{ JMP_THIS(0x6CB920); }

	bool HasChargeProgressed(bool isPlayer) // true if the charge has changed (charge overlay on the cameo)
		{ JMP_THIS(0x6CBCA0); }               // triggers the EVA Announcement if it's ready

	signed int GetCameoChargeState() const // which cameo charge overlay frame to show
		{ JMP_THIS(0x6CBEE0); }

	void SetCharge(int percentage)
		{ JMP_THIS(0x6CC1E0); }

	int GetRechargeTime() const // the time it takes this SW to recharge fully
		{ JMP_THIS(0x6CC260); }

	void SetRechargeTime(int time) // makes this SW rechange in this many frames, as opposed to [Type]RechargeTime
		{ JMP_THIS(0x6CC280); }

	void ResetRechargeTime() // nullifies the previous call
		{ JMP_THIS(0x6CC290); }

	const wchar_t* NameReadiness() const // the string to be displayed over the SW in the sidebar - "Ready" or ChargeDrain state
		{ JMP_THIS(0x6CC2B0); }

	bool ShouldDrawProgress() const // sidebar
		{ JMP_THIS(0x6CDE90); }

	bool ShouldFlashTab() const // sidebar
		{ JMP_THIS(0x6CE1A0); }

	//Constructor
	SuperClass(SuperWeaponTypeClass* pSWType, HouseClass* pOwner) noexcept
		: SuperClass(noinit_t())
	{ JMP_THIS(0x6CAF90); }

protected:
	explicit __forceinline SuperClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int CustomChargeTime;
	SuperWeaponTypeClass* Type;
	HouseClass* Owner;
	TimerStruct RechargeTimer;
	PROTECTED_PROPERTY(DWORD, unused_3C);
	bool BlinkState;
	PROTECTED_PROPERTY(BYTE, unused_41[7]);
	LARGE_INTEGER BlinkTimer;
	int SpecialSoundDuration; // see 0x6CD14F
	CoordStruct SpecialSoundLocation;
	bool CanHold;          // 0x60
	PROTECTED_PROPERTY(BYTE, unused_61);
	CellStruct ChronoMapCoords;  // 0x62
	PROTECTED_PROPERTY(BYTE, unused_66[2]);
	AnimClass* Animation;                // 0x68
	bool AnimationGotInvalid;
	bool Granted;
	bool OneTime; // remove this SW when it has been fired once
	bool IsCharged;
	bool IsOnHold;
	PROTECTED_PROPERTY(BYTE, unused_71[3]);
	int ReadinessFrame; // when did it become ready?
	int CameoChargeState;
	ChargeDrainState ChargeDrainState;
};

class LightningStorm
{
public:
	static double &CloudHeightFactor;

	static CellStruct &Coords;
	static HouseClass* &Owner;
	static int &Deferment;
	static int &Duration;
	static int &StartTime;
	static bool &Active;
	static bool &TimeToEnd;

	static DynamicVectorClass<AnimClass*>* const CloudsPresent;
	static DynamicVectorClass<AnimClass*>* const CloudsManifesting;
	static DynamicVectorClass<AnimClass*>* const BoltsPresent;

	static void Start(int duration, int deferment, CellStruct cell, HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(cell); SET_REG32(EDX, deferment); SET_REG32(ECX, duration);
			CALL(0x539EB0); }

	static void RequestStop()
		{ CALL(0x53A090); }

	static bool HasDeferment()
		{ CALL(0x53A0E0); }

	static void Strike(CellStruct cell)
		{ PUSH_VAR32(cell); CALL(0x53A140); }

	static void Strike2(CoordStruct coords)
		{ JMP_STD(0x53A300); }

	static void PrintMessage()
		{ CALL(0x53AE00); }
};

class PsyDom
{
public:
	static PsychicDominatorStatus &Status;
	static CellStruct &Coords;
	static HouseClass* &Owner;
	static AnimClass* &Anim;

	static void Start(HouseClass* pOwner, CellStruct coords)
		{ PUSH_VAR32(coords); SET_REG32(ECX, pOwner);
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
	static int &Status;
	static int &Duration;

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
	static NukeFlashStatus &Status;
	static int &StartTime;
	static int &Duration;

	static void FadeIn()
		{ CALL(0x53AB70); }

	static void FadeOut()
		{ CALL(0x53AC50); }

	static bool IsFadingIn()
		{ CALL(0x53A110); }

	static bool IsFadingOut()
		{ CALL(0x53A120); }
};
