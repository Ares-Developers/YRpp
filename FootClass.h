/*
	Base class for units that can move (that have "feet")
*/

#ifndef FOOT_H
#define FOOT_H

#include <TechnoClass.h>

//forward declarations
class LocomotionClass;
class ParasiteClass;

class FootClass : public TechnoClass
{
public:

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x4DB3C0, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x4DB690, HRESULT); }

	//Destructor
	virtual ~FootClass()
		{ THISCALL(0x4D3590); }

	//AbstractClass
	virtual void PointerExpired(void* p,bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x4D9960); }
	virtual CoordStruct* GetCoords_(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x4DBDF0, CoordStruct*); }

	//ObjectClass
	virtual eVisualType VisualCharacter(VARIANT_BOOL flag, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR8(flag); THISCALL_RET(0x4DA4E0, eVisualType); }
	virtual SHPStruct* GetImage()
		{ THISCALL_RET(0x4DED70, SHPStruct*); }
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL_RET(0x4DDDE0, eAction); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL_RET(0x4DDED0, eAction); }
	virtual eLayer InWhichLayer()
		{ THISCALL_RET(0x4DB7E0, eLayer); }
	virtual bool CanBeSold()
		{ THISCALL_RET(0x4D9E70, bool); }
	virtual bool vt_entry_BC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x4DDC40, bool); }
	virtual bool vt_entry_C0()
		{ return unknown_bool_6B6; }
	virtual bool vt_entry_D4()
		{ THISCALL_RET(0x4DB260, bool); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL_RET(0x4D7170, bool); }
	virtual void vt_entry_DC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4D9720); }
	virtual void UnInit()
		{ THISCALL(0x4DE5D0); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ }
	virtual bool SetLayer(eLayer value)
		{ PUSH_VAR32(value); THISCALL_RET(0x4D3780, bool); }
	virtual bool vt_entry_138()
		{ THISCALL_RET(0x4DFA50, bool); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4D7D50, bool); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4D74E0, bool); }
	virtual void IronCurtain(int nDuration, DWORD dwUnused, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(dwUnused); PUSH_VAR32(nDuration); THISCALL(0x4DEAE0); }
	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH, ObjectClass* pAttacker, 
	                          DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse)
		{ PUSH_VAR32(pAttackingHouse); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(pAttacker); 
		  PUSH_VAR32(pWH); PUSH_VAR32(dwUnk1); PUSH_VAR32(pDamage); THISCALL_RET(0x4D7330, eDamageState); }
	virtual void UpdatePosition(int dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4D85D0); }
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4D8FB0); }
	virtual void Sell(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4D9F70); }
	virtual void AssignPlanningPath(signed int idxPath, signed char idxWP)
		{ PUSH_VAR8(idxWP); PUSH_VAR32(idxPath); THISCALL(0x4DC810); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x4D9C10, DWORD); }
	virtual DWORD vt_entry_1B0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x4D9C60, DWORD); }
	virtual void SetLocation(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x4DB810); }

	//MissionClass
	virtual void vt_entry_1F4(eMission mission)
		{ PUSH_VAR32(mission); THISCALL(0x4D8F40); }
	virtual bool vt_entry_1F8()
		{ THISCALL_RET(0x4D8F80, bool); }
	virtual int Mission_Attack()
		{ THISCALL_RET(0x4D4DC0, int); }
	virtual int Mission_Capture()
		{ THISCALL_RET(0x4D4B20, int); }
	virtual int Mission_Eaten()
		{ THISCALL_RET(0x4D4CB0, int); }
	virtual int Mission_Guard()
		{ THISCALL_RET(0x4D5070, int); }
	virtual int Mission_AreaGuard()
		{ THISCALL_RET(0x4D6AA0, int); }
	virtual int Mission_Hunt()
		{ THISCALL_RET(0x4D5350, int); }
	virtual int Mission_Move()
		{ THISCALL_RET(0x4D4200, int); }
	virtual int Mission_Retreat()
		{ THISCALL_RET(0x4DA2C0, int); }
	virtual int Mission_Enter()
		{ THISCALL_RET(0x4D9290, int); }
	virtual int Mission_Rescue()
		{ THISCALL_RET(0x4DDF90, int); }
	virtual int Mission_Patrol()
		{ THISCALL_RET(0x4D4280, int); }

	//TechnoClass
	virtual bool IsCloakable()
		{THISCALL_RET(0x4DBDA0, bool); }
	virtual bool vt_entry_290()
		{THISCALL_RET(0x41C050, bool); }
	virtual bool vt_entry_2C4(DWORD dwUnk)
		{PUSH_VAR32(dwUnk);THISCALL_RET(0x4DBA50, bool); }
	virtual bool vt_entry_2CC(DWORD dwUnk)
		{PUSH_VAR32(dwUnk);THISCALL_RET(0x4D3810, bool); }
	virtual DWORD vt_entry_2EC(DWORD dwUnk)
		{PUSH_VAR32(dwUnk);THISCALL_RET(0x704350, DWORD); }
	virtual int vt_entry_2F0()
		{return 2;}
	virtual CellStruct* vt_entry_2F4()
		{THISCALL_RET(0x459DB0, CellStruct*); }
	virtual void vt_entry_2F8(DWORD dwUnk)
		{}
	virtual bool vt_entry_320()
		{THISCALL_RET(0x4DA1D0, bool); }
	virtual void vt_entry_334()
		{THISCALL(0x4DE580);}
	virtual DWORD vt_entry_338(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4DD0A0, DWORD); }
	virtual bool OnEnterGrinder()
		{ THISCALL_RET(0x4DFA70, bool); }
	virtual bool OnEnterBioReactor()
		{ THISCALL_RET(0x4DFB70, bool); }
	virtual bool OnEnterTankBunker()
		{ THISCALL_RET(0x4DFF40, bool); }
	virtual bool OnEnterBattleBunker()
		{ THISCALL_RET(0x4DFCB0, bool); }
	virtual bool OnGarrisonStructure()
		{ THISCALL_RET(0x4DFE00, bool); }
	virtual bool vt_entry_380()
		{ THISCALL_RET(0x4DE770, bool); }
	virtual void AddPassenger(FootClass* pPassenger)
		{ PUSH_VAR32(pPassenger); THISCALL(0x4DE630); }
	virtual DWORD vt_entry_3A0()
		{ THISCALL_RET(0x4D5660, DWORD); }
	virtual void vt_entry_3B8()
		{ THISCALL(0x4D98C0); }
	virtual CellClass* vt_entry_3C4(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4D9920, CellClass*); }
	virtual void SetOwningCountry(HouseTypeClass* pCountry)
		{ PUSH_VAR32(pCountry); THISCALL(0x4DBED0); }
	virtual bool vt_entry_3DC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x4DEBB0, bool); }
	virtual CoordStruct* GetTargetCoords(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x4D8560, CoordStruct*); }
	virtual void vt_entry_438(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4DC060); }
	virtual void vt_entry_47C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4D94A0); }
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x4D94B0); }
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4D82B0, bool); }
	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4DF510); }
	virtual void vt_entry_4A4(DWORD dwUnk)
		{PUSH_VAR32(dwUnk);THISCALL(0x4DF0E0);}
	virtual void vt_entry_4A8()
		{ THISCALL(0x4DF1A0); }
	virtual bool vt_entry_4AC()
		{ THISCALL_RET(0x4DF1C0, bool); }
	virtual bool vt_entry_4B0()
		{ THISCALL_RET(0x4DF1D0, bool); }
	virtual int vt_entry_4B4()
		{ THISCALL_RET(0x4DF1E0, int); }
	virtual CoordStruct* vt_entry_4B8(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x4DF1F0, CoordStruct*); }
	virtual bool vt_entry_4C4()
		{ THISCALL_RET(0x4DF310, bool); }
	virtual bool vt_entry_4C8()
		{ THISCALL_RET(0x4DF320, bool); }
	virtual void vt_entry_4CC()
		{ THISCALL(0x4DF3A0); }
	virtual bool vt_entry_4D0()
		{ THISCALL_RET(0x4DF4B0, bool); }

	//FootClass
	virtual void vt_entry_4D4(DWORD dwUnk)
		{}
	virtual void vt_entry_4D8(DWORD dwUnk)
		{}
	virtual bool vt_entry_4DC()
		{ THISCALL_RET(0x4DC790, bool); }
	virtual bool vt_entry_4E0()
		{ THISCALL_RET(0x4DBFD0, bool); }
	virtual bool vt_entry_4E4()
		{ return false; }
	virtual void vt_entry_4E8(CellStruct* pCell)
		{ PUSH_VAR32(pCell); THISCALL(0x4DE7B0); }
	virtual void vt_entry_4EC(CellStruct* pCell)
		{ PUSH_VAR32(pCell); THISCALL(0x4DE940); }
	virtual CoordStruct* vt_entry_4F0(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x4D9FF0, CoordStruct*); }
	virtual void vt_entry_4F4()
		{ THISCALL(0x4DC030); }
	virtual bool vt_entry_4F8()
		{ return false; }
	virtual bool MoveTo(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x4D55F0, bool); }
	virtual bool StopMoving()
		{ THISCALL_RET(0x4D55C0, bool); }
	virtual bool vt_entry_504()
		{ THISCALL_RET(0x4DB9B0, bool); }
	virtual bool vt_entry_508(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4DF7F0, bool); }

/*pd sagt:
41C090 D=
NOOOOOOOOOOOOOOOOOOOOOOOOOOoooooooooooooooooooooooooo*/
	virtual void vt_entry_50C(
		DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
		DWORD dwUnk9, DWORD dwUnk10, DWORD dwUnk11, DWORD dwUnk12,
		DWORD dwUnk13, DWORD dwUnk14, DWORD dwUnk15, DWORD dwUnk16)
		{
		PUSH_VAR32(dwUnk16); PUSH_VAR32(dwUnk15); PUSH_VAR32(dwUnk14); PUSH_VAR32(dwUnk13);
		PUSH_VAR32(dwUnk12); PUSH_VAR32(dwUnk11); PUSH_VAR32(dwUnk10); PUSH_VAR32(dwUnk9);
		PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7); PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5);
		PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		THISCALL(0x41C090);
	}
	virtual void vt_entry_510(
		DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5, 
		DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8, DWORD dwUnk9, DWORD dwUnk10)
		{
		PUSH_VAR32(dwUnk10); PUSH_VAR32(dwUnk9); PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7);
		PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3);
		PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4DAF10);
	}

	virtual void vt_entry_514()
		{ }
	virtual void Panic()
		{ }
	virtual void UnPanic()
		{ }
	virtual void PlayIdleAnim(int nIdleAnimNumber)
		{ }
	virtual DWORD vt_entry_524()
		{ return 0; }
	virtual DWORD vt_entry_528( DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3 )
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4DF040, DWORD); }
	virtual DWORD vt_entry_52C(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4DEE80, DWORD); }
	virtual DWORD vt_entry_530(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4DEE50, DWORD); }
	virtual void vt_entry_534(DWORD dwUnk, DWORD dwUnk2)
		{ }
	virtual int GetCurrentSpeed()
		{ THISCALL_RET(0x4DB1A0, int); }
	virtual DWORD vt_entry_53C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x4D5690, DWORD); }
	virtual void vt_entry_540(DWORD dwUnk)
		{ }
	virtual void vt_entry_544(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4D3710); }
	virtual void				vt_entry_548()
		{ }
	virtual void				vt_entry_54C()
		{ }
	virtual bool vt_entry_550(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x4DDC60, bool); }

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
	PROTECTED_PROPERTY(BYTE,  unknown_structure3_544[0x14]);
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
	PROPERTY(DWORD,           MemberOfTeam);  //AITeamClass *
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
	PROPERTY(LocomotionClass*,  Locomotor);
	PROPERTY_STRUCT(CoordStruct,       unknown_point3d_678);
	PROPERTY(signed char,       TubeIndex);	//I'm in this tunnel
	PROPERTY(bool,              unknown_bool_685);
	PROPERTY(signed char,       WaypointIndex); // which waypoint in my planning path am I following?
	PROPERTY(bool,              unknown_bool_687);
	PROPERTY(bool,              unknown_bool_688);
	PROPERTY(bool,              IsTeamLeader);
	PROPERTY(bool,              unknown_bool_68A);
	PROPERTY(bool,              unknown_bool_68B);
	PROPERTY(bool,              unknown_bool_68C);
	PROPERTY(bool,              unknown_bool_68D);
	PROPERTY(bool,              unknown_bool_68E);
	PROPERTY(bool,              unknown_bool_68F);
	PROPERTY(bool,              unknown_bool_690);
	PROPERTY(bool,              unknown_bool_691);
	PROPERTY(ParasiteClass*,    ParasiteEatingMe);
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
