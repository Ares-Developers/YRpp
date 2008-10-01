/*
	Base class for units that can move (that have "feet")
*/

#ifndef FOOT_H
#define FOOT_H

#include <TechnoClass.h>

//forward declarations
class LocomotionClass;
class TeamClass;
class ParasiteClass;

class FootClass : public TechnoClass
{
public:

	//IPersistStream
	//Destructor
	virtual ~FootClass() RX;

	//AbstractClass
	//ObjectClass
	//MissionClass
	//TechnoClass
	//FootClass
	virtual void vt_entry_4D4(DWORD dwUnk) RX;
	virtual void vt_entry_4D8(DWORD dwUnk) RX;
	virtual bool vt_entry_4DC() R0;
	virtual bool vt_entry_4E0() R0;
	virtual bool vt_entry_4E4() R0;
	virtual void vt_entry_4E8(CellStruct* pCell) RX;
	virtual void vt_entry_4EC(CellStruct* pCell) RX;
	virtual CoordStruct* vt_entry_4F0(CoordStruct* pCrd) R0;
	virtual void vt_entry_4F4() RX;
	virtual bool vt_entry_4F8() R0;
	virtual bool MoveTo(CoordStruct* pCrd) R0;
	virtual bool StopMoving() R0;
	virtual bool vt_entry_504() R0;
	virtual bool vt_entry_508(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
/* ,-> */ virtual void vt_entry_50C(
/* | */ DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
/* | */ DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
/*P| */ DWORD dwUnk9, DWORD dwUnk10, DWORD dwUnk11, DWORD dwUnk12,
/*A| */ DWORD dwUnk13, DWORD dwUnk14, DWORD dwUnk15, DWORD dwUnk16) RX;
/*N| */
/*I| */ virtual void vt_entry_510(
/*C| */ DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5, 
/* | */ DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8, DWORD dwUnk9, DWORD dwUnk10) RX;
/* | */ virtual void vt_entry_514() RX;
/* `- */ virtual void Panic() RX;
	virtual void UnPanic() RX; //never
	virtual void PlayIdleAnim(int nIdleAnimNumber) RX;
	virtual DWORD vt_entry_524() R0;
	virtual DWORD vt_entry_528 ( DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3 ) R0;
	virtual DWORD vt_entry_52C(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) R0;
	virtual DWORD vt_entry_530(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual void vt_entry_534(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual int GetCurrentSpeed() R0;
	virtual DWORD vt_entry_53C(DWORD dwUnk) R0;
	virtual void vt_entry_540(DWORD dwUnk) RX;
	virtual void vt_entry_544(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void vt_entry_548() RX;
	virtual void vt_entry_54C() RX;
	virtual bool vt_entry_550(DWORD dwUnk) R0;

	//Constructor
	FootClass(HouseClass* owner):TechnoClass(false)
		{ PUSH_VAR32(owner); THISCALL(0x4D31E0); }

	// non-virtual

	// only used by squid damage routines, normal wakes are created differently it seems
	// creates 3 wake animations behind the unit
	void CreateWakes(int X, int Y, int Z)
		{ PUSH_VAR32(Z); PUSH_VAR32(Y); PUSH_VAR32(X); THISCALL(0x629E90); }

protected:
	FootClass():TechnoClass()
		{}
	FootClass(bool X):TechnoClass(X)
		{}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,             PlanningPathIdx); // which planning path am I following?
	PROPERTY(short,           unknown_short_524);
	PROPERTY(short,           unknown_short_526);
	PROPERTY(short,           unknown_short_528);
	PROPERTY(short,           unknown_short_52A);
	PROPERTY(DWORD,           unknown_52C);	//unused?
	PROPERTY(DWORD,           unknown_530);
	PROPERTY(DWORD,           unknown_534);
	PROPERTY(DWORD,           unknown_538);
	PROPERTY(bool,            unknown_bool_53C);
	PROPERTY(DWORD,           unknown_540);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio7);

	PROPERTY(short,           unknown_short_558);
	PROPERTY(short,           unknown_short_55A);
	PROPERTY_STRUCT(CellStruct,      CurrentMapCoords);
	PROPERTY(short,           unknown_short_560);
	PROPERTY(short,           unknown_short_562);
	PROPERTY(short,           unknown_short_564);
	PROPERTY(short,           unknown_short_566);
	PROPERTY(DWORD,           unknown_568);
	PROPERTY(DWORD,           unknown_56C);
	PROPERTY(DWORD,           unknown_570);
	PROPERTY(DWORD,           unknown_574);	//unused?
	PROPERTY(DWORD,           unknown_578);
	PROPERTY(DWORD,           unknown_57C);
	PROPERTY(double,          SpeedMultiplier);
	PROPERTY_STRUCT(DynamicVectorClass<AbstractClass*>,  unknown_abstract_array_588);
	PROPERTY(DWORD,           unknown_5A0);
	PROPERTY(CellClass*,      Destination); // possibly other objects as well
	PROPERTY(DWORD,           unknown_5A8);
	PROPERTY_STRUCT(DynamicVectorClass<AbstractClass*>,  unknown_abstract_array_5AC);
	PROPERTY(int,             unknown_int_5C4);
	PROPERTY(DWORD,           unknown_5C8);
	PROPERTY(DWORD,           unknown_5CC);
	PROPERTY(BYTE,            unknown_5D0);	//unused?
	PROPERTY(bool,            unknown_bool_5D1);
	PROPERTY(TeamClass*,      Team);
	PROPERTY(FootClass*,      NextTeamMember);        //next unit in team
	PROPERTY(DWORD,           unknown_5DC);
	PROPERTY(int,             unknown_int_5E0);

	PROTECTED_PROPERTY(BYTE,  unknown_5E4[0x5C]);

	PROPERTY_STRUCT(TimerStruct,     unknown_timer_640);
	PROPERTY(int,             unknown_int_64C);
	PROPERTY_STRUCT(TimerStruct,     unknown_timer_650);

	PROTECTED_PROPERTY(BYTE,  unknown_65C[0x8]);

	PROPERTY(DWORD,             unknown_664);
	PROPERTY_STRUCT(TimerStruct,       unknown_timer_668);
	PROPERTY_PTR(LocomotionClass*,  Locomotor);
	PROPERTY_STRUCT(CoordStruct,       unknown_point3d_678);
	PROPERTY(signed char,       TubeIndex);	//I'm in this tunnel
	PROPERTY(bool,              unknown_bool_685);
	PROPERTY(signed char,       WaypointIndex); // which waypoint in my planning path am I following?
	PROPERTY(bool,              unknown_bool_687);
	PROPERTY(bool,              unknown_bool_688);
	PROPERTY(bool,              IsTeamLeader);
	PROPERTY(bool,              ShouldScanForTarget);
	PROPERTY(bool,              unknown_bool_68B);
	PROPERTY(bool,              unknown_bool_68C);
	PROPERTY(bool,              unknown_bool_68D);
	PROPERTY(bool,              unknown_bool_68E);
	PROPERTY(bool,              unknown_bool_68F);
	PROPERTY(bool,              unknown_bool_690);
	PROPERTY(bool,              unknown_bool_691);
	PROPERTY(FootClass*,        ParasiteEatingMe); // the tdrone/squid that's eating me
	PROPERTY(DWORD,             unknown_698);
	PROPERTY(ParasiteClass*,    ParasiteImUsing);	// my parasitic half, nonzero for, eg, terror drone or squiddy
	PROPERTY_STRUCT(TimerStruct,       ParalysisTimer); // for squid victims
	PROPERTY(bool,              unknown_bool_6AC);
	PROPERTY(bool,              unknown_bool_6AD);
	PROPERTY(bool,              unknown_bool_6AE);
	PROPERTY(bool,              unknown_bool_6AF);
	PROPERTY(bool,              unknown_bool_6B0);
	PROPERTY(bool,              unknown_bool_6B1);
	PROPERTY(bool,              unknown_bool_6B2);
	PROPERTY(bool,              unknown_bool_6B3);
	PROPERTY(bool,              unknown_bool_6B4);
	PROPERTY(bool,              unknown_bool_6B5);
	PROPERTY(bool,              unknown_bool_6B6);
	PROPERTY(bool,              unknown_bool_6B7);
	PROPERTY(bool,              unknown_bool_6B8);
	PROTECTED_PROPERTY(DWORD,   unused_6BC);	//???
};

#endif
