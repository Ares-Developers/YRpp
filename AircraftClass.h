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
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL_RET(0x414290, HRESULT); }

	virtual ULONG _stdcall AddRef()
		{ return 1; }
	virtual ULONG _stdcall Release()
		{ return 1; }

	//IFlyControl
	virtual int _stdcall Landing_Altitude()
		{ PUSH_VAR32(this); CALL_RET(0x41B6A0, int); }
	virtual int _stdcall Landing_Direction()
		{ PUSH_VAR32(this); CALL_RET(0x41B760, int); }
	virtual long _stdcall Is_Loaded()
		{ PUSH_VAR32(this); CALL_RET(0x41B7D0, long); }
	virtual long _stdcall Is_Strafe()
		{ PUSH_VAR32(this); CALL_RET(0x41B7F0, long); }
	virtual long _stdcall Is_Fighter()
		{ PUSH_VAR32(this); CALL_RET(0x41B840, long); }
	virtual long _stdcall Is_Locked()
		{ PUSH_VAR32(this); CALL_RET(0x41B860, long); }

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x41C190, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x41B430, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x41B5C0, HRESULT); }

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
		{ THISCALL_RET(0x41B980, bool); }
	virtual bool IsInAir()
		{ THISCALL_RET(0x41B920, bool); }
	virtual void Update()
		{ THISCALL(0x414BB0); }

	//ObjectClass
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL_RET(0x417F80, eAction); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL_RET(0x417CC0, eAction); }
	virtual bool CanBeUndeployed()
		{ return IsOnFloor(); }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual wchar_t* GetUIName()
		{ THISCALL_RET(0x41C1D0, wchar_t*); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL_RET(0x414310, bool); }
	virtual int KickOutUnit(TechnoClass* pTechno, CellStruct uCell)
		{ PUSH_VAR32(uCell); PUSH_VAR32(pTechno); THISCALL_RET(0x415B10, int); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x4144B0); }
	virtual void See(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x41ADF0); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x417C80, bool); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x417BD0, bool); }
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4190B0); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x4196B0, DWORD); }

	//MissionClass
	virtual bool QueueMission(eMission mission, bool start_mission)
		{ PUSH_VAR8(start_mission); PUSH_VAR32(mission); THISCALL_RET(0x41BA90, bool); }
	virtual bool NextMission()
		{ THISCALL_RET(0x41B870, bool); }
	virtual void ForceMission(eMission mission)
		{ PUSH_VAR32(mission); THISCALL(0x41B9F0); }

	virtual void vt_entry_1F4(eMission mission)
		{ PUSH_VAR32(mission); THISCALL(0x41BB30); }
	virtual bool vt_entry_200()
		{ THISCALL_RET(0x41B5E0, bool); }
	virtual int Mission_Attack()
		{ THISCALL_RET(0x417FE0, int); }
	virtual int Mission_Guard()
		{ THISCALL_RET(0x41A5C0, int); }
	virtual int Mission_AreaGuard()
		{ THISCALL_RET(0x41A940, int); }
	virtual int Mission_Hunt()
		{ THISCALL_RET(0x414A80, int); }
	virtual int Mission_Move()
		{ THISCALL_RET(0x4166C0, int); }
	virtual int Mission_Retreat()
		{ THISCALL_RET(0x415A50, int); }
	virtual int Mission_Unload()
		{ THISCALL_RET(0x4151E0, int); }
	virtual int Mission_Enter()
		{ THISCALL_RET(0x419C80, int); }
	virtual int Mission_Patrol()
		{ THISCALL_RET(0x417300, int); }
	virtual int Mission_ParaDropApproach()
		{ THISCALL_RET(0x4158E0, int); }
	virtual int Mission_ParaDropOverfly()
		{ THISCALL_RET(0x415960, int); }
	virtual int Mission_SpyPlaneApproach()
		{ THISCALL_RET(0x4155F0, int); }
	virtual int Mission_SpyPlaneOverfly()
		{ THISCALL_RET(0x4157C0, int); }

	//TechnoClass
	virtual FacingStruct* vt_entry_2A8(FacingStruct* pFacing)
		{ PUSH_VAR32(pFacing); THISCALL_RET(0x41C1E0, FacingStruct*); }
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4195A0, DWORD); }
	virtual DWORD vt_entry_308(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x41A570, DWORD); }
	virtual bool vt_entry_378(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x417CA0, bool); }
	virtual void DecreaseAmmo()
		{ }
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x41A9E0, int); }
	virtual DWORD Fire(ObjectClass* pTarget, int nWeapon)
		{ PUSH_VAR32(nWeapon); PUSH_VAR32(pTarget); THISCALL_RET(0x415EE0, DWORD); }
	virtual bool IsNotWarpingIn()
		{ return unknown_bool_6D5; } // not chronoshifting in
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x41AA80); }
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x4176F0, bool); }

	//FootClass
	virtual bool vt_entry_4DC()
		{ THISCALL_RET(0x41B890, bool); }
	virtual DWORD vt_entry_528(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x41BBD0, DWORD); }

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
