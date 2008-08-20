/*
	Aircraft
*/

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <FootClass.h>
#include <AircraftTypeClass.h>

//forward declarations

//What are these?
class StageClass : public IFlyControl{ };
class FlasherClass : public StageClass{ };

//AircraftClass
class AircraftClass : public FootClass, public FlasherClass
{
public:
	//Static
	static DynamicVectorClass<AircraftClass*>* Array;

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL(0x414290); }

	virtual ULONG _stdcall AddRef()
		{ return 1; }
	virtual ULONG _stdcall Release()
		{ return 1; }

	//IFlyControl
	virtual int _stdcall Landing_Altitude()
		{ PUSH_VAR32(this); CALL(0x41B6A0); }
	virtual int _stdcall Landing_Direction()
		{ PUSH_VAR32(this); CALL(0x41B760); }
	virtual long _stdcall Is_Loaded()
		{ PUSH_VAR32(this); CALL(0x41B7D0); }
	virtual long _stdcall Is_Strafe()
		{ PUSH_VAR32(this); CALL(0x41B7F0); }
	virtual long _stdcall Is_Fighter()
		{ PUSH_VAR32(this); CALL(0x41B840); }
	virtual long _stdcall Is_Locked()
		{ PUSH_VAR32(this); CALL(0x41B860); }

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x41C190); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x41B430); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x41B5C0); }

	//Destructor
	virtual ~AircraftClass()
		{ THISCALL(0x414080); }

	//AbstractClass
	virtual void Init()
		{ THISCALL(0x413F80); }
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x41B660); }
	virtual eAbstractType WhatAmI()
		{ return abs_Aircraft; }
	virtual int Size()
		{ return sizeof(AircraftClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x41B610); }
	virtual bool IsOnFloor()
		{ THISCALL(0x41B980); }
	virtual bool IsInAir()
		{ THISCALL(0x41B920); }
	virtual void Update()
		{ THISCALL(0x414BB0); }

	//ObjectClass
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL(0x417F80); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL(0x417CC0); }
	virtual bool CanBeUndeployed()
		{ return IsOnFloor(); }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual wchar_t* GetUIName()
		{ THISCALL(0x41C1D0); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL(0x414310); }
	virtual int KickOutUnit(TechnoClass* pTechno, CellStruct uCell)
		{ PUSH_VAR32(uCell); PUSH_VAR32(pTechno); THISCALL(0x415B10); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x4144B0); }
	virtual void See(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x41ADF0); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL(0x417C80); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL(0x417BD0); }
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4190B0); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL(0x4196B0); }

	//MissionClass
	virtual bool QueueMission(eMission mission, bool start_mission)
		{ PUSH_VAR8(start_mission); PUSH_VAR32(mission); THISCALL(0x41BA90); }
	virtual bool NextMission()
		{ THISCALL(0x41B870); }
	virtual void ForceMission(eMission mission)
		{ PUSH_VAR32(mission); THISCALL(0x41B9F0); }

	virtual void vt_entry_1F4(eMission mission)
		{ PUSH_VAR32(mission); THISCALL(0x41BB30); }
	virtual bool vt_entry_200()
		{ THISCALL(0x41B5E0); }

	virtual int Mission_Attack()
		{ THISCALL(0x417FE0); }
	virtual int Mission_Guard()
		{ THISCALL(0x41A5C0); }
	virtual int Mission_AreaGuard()
		{ THISCALL(0x41A940); }
	virtual int Mission_Hunt()
		{ THISCALL(0x414A80); }
	virtual int Mission_Move()
		{ THISCALL(0x4166C0); }
	virtual int Mission_Retreat()
		{ THISCALL(0x415A50); }
	virtual int Mission_Unload()
		{ THISCALL(0x4151E0); }
	virtual int Mission_Enter()
		{ THISCALL(0x419C80); }
	virtual int Mission_Patrol()
		{ THISCALL(0x417300); }
	virtual int Mission_ParaDropApproach()
		{ THISCALL(0x4158E0); }
	virtual int Mission_ParaDropOverfly()
		{ THISCALL(0x415960); }
	virtual int Mission_SpyPlaneApproach()
		{ THISCALL(0x4155F0); }
	virtual int Mission_SpyPlaneOverfly()
		{ THISCALL(0x4157C0); }

	//TechnoClass
	virtual FacingStruct* vt_entry_2A8(FacingStruct* pFacing)
		{ PUSH_VAR32(pFacing); THISCALL(0x41C1E0); }
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4195A0); }
	virtual DWORD vt_entry_308(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x41A570); }
	virtual bool vt_entry_378(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x417CA0); }
	virtual void DecreaseAmmo()
		{ }
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x41A9E0); }
	virtual DWORD Fire(ObjectClass* pTarget, int nWeapon)
		{ PUSH_VAR32(nWeapon); PUSH_VAR32(pTarget); THISCALL(0x415EE0); }
	virtual bool IsNotWarpingIn()
		{ return unknown_bool_6D5; } // not chronoshifting in
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x41AA80); }
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4176F0); }

	//FootClass
	virtual bool vt_entry_4DC()
		{ THISCALL(0x41B890); }
	virtual DWORD vt_entry_528(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x41BBD0); }

	//Constructor
	AircraftClass(AircraftTypeClass* pType, HouseClass* pOwner):FootClass(false)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x413D20); }

protected:
	AircraftClass():FootClass()
		{ }
	AircraftClass(bool X):FootClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(AircraftTypeClass*, Type);
	PROPERTY(bool, unknown_bool_6C8);
	PROPERTY(bool, HasPassengers);	//parachutes
	PROPERTY(bool, unknown_bool_6CA);
	PROPERTY(DWORD, unknown_6CC);
	PROPERTY(bool, unknown_bool_6D0);
	PROPERTY(bool, unknown_bool_6D1);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(char, unknown_char_6D3);
	PROPERTY(bool, unknown_bool_6D4);
	PROPERTY(bool, unknown_bool_6D5);
};

#endif
