/*
	Infantry
*/

#ifndef INFANTRY_H
#define INFANTRY_H

#include <FootClass.h>
#include <InfantryTypeClass.h>

class InfantryClass : public FootClass
{
public:
	//Static
	static DynamicVectorClass<InfantryClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x523300, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x521960, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x521B00, HRESULT); }

	//Destructor
	virtual ~InfantryClass()
		{ THISCALL(0x523350); }

	//AbstractClass
	virtual void Init()
		{ THISCALL(0x517CC0); }
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x51AA10); }
	virtual eAbstractType WhatAmI()
		{ return abs_Infantry; }
	virtual int Size()
		{ return sizeof(InfantryClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x521C90); }
	virtual void Update()
		{ THISCALL(0x51BAB0); }

	//ObjectClass
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL_RET(0x51F800, eAction); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL_RET(0x51E3B0, eAction); }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual wchar_t* GetUIName()
		{ THISCALL_RET(0x51F2C0, wchar_t*); }
	virtual CoordStruct* GetFLH(CoordStruct *pDest, int idxWeapon, int nFLH_X, int nFLH_Y, int nFLH_Z)
		{ PUSH_VAR32(nFLH_Z); PUSH_VAR32(nFLH_Y); PUSH_VAR32(nFLH_X);
		  PUSH_VAR32(idxWeapon); PUSH_VAR32(pDest); THISCALL_RET(0x523250, CoordStruct*); }
	virtual bool IsDisguisedAs(HouseClass *Target)
		{ PUSH_VAR32(Target); THISCALL_RET(0x5227F0, bool); }
	virtual ObjectTypeClass* GetDisguise(bool DisguisedAgainstAllies)
		{ PUSH_VAR8(DisguisedAgainstAllies); THISCALL_RET(0x522640, ObjectTypeClass*); }
	virtual HouseClass* GetDisguiseHouse(bool DisguisedAgainstAllies)
		{ PUSH_VAR8(DisguisedAgainstAllies); THISCALL_RET(0x5226C0, HouseClass*); }
	virtual bool vt_entry_D4()
		{ THISCALL_RET(0x51DF10, bool); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL_RET(0x51DFF0, bool); }
	virtual bool vt_entry_E8(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x521760, bool); }
	virtual void vt_entry_F0(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5217C0); }
	virtual void vt_entry_F4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x521850); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x518F90); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x51F250, bool); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x51F190, bool); }
	virtual void IronCurtain(int nDuration, DWORD dwUnused, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(nDuration); THISCALL(0x522600); }
	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH,
	  ObjectClass* pAttacker, DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse)
		{ PUSH_VAR32(pAttackingHouse); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(pAttacker);
		  PUSH_VAR32(pWH); PUSH_VAR32(dwUnk1); PUSH_VAR32(pDamage); THISCALL_RET(0x517FA0, eDamageState); }
	virtual void Scatter(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x51D0D0); }
	virtual void UpdatePosition(int dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x519630); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL_RET(0x51BF90, DWORD); }

	//MissionClass
	virtual bool vt_entry_200()
		{ THISCALL_RET(0x521B60, bool); }
	virtual int Mission_Attack()
		{ THISCALL_RET(0x51F3E0, int); }
	virtual int Mission_Guard()
		{ THISCALL_RET(0x51F620, int); }
	virtual int Mission_AreaGuard()
		{ THISCALL_RET(0x51F640, int); }
	virtual int Mission_Harvest()
		{ THISCALL_RET(0x522E70, int); }
	virtual int Mission_Hunt()
		{ THISCALL_RET(0x51F540, int); }
	virtual int Mission_Move()
		{ THISCALL_RET(0x51F660, int); }
	virtual int Mission_Unload()
		{ THISCALL_RET(0x51F6E0, int); }

	//TechnoClass
	virtual DWORD SelectWeapon(ObjectClass *Target)
		{ PUSH_VAR32(Target); THISCALL_RET(0x5218E0, DWORD); }
	virtual DWORD vt_entry_300(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x521D30, DWORD); }
	virtual bool IsEngineer()
		{ return Type->get_Engineer(); }
	virtual bool vt_entry_384()
		{ THISCALL_RET(0x522BC0, bool); }
	virtual void vt_entry_388(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x522C00); }
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x51C8B0, int); }
	virtual CellClass* vt_entry_3C4(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x51E140, CellClass*); }
	virtual void SetTarget(AbstractClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x51B1F0); }
	virtual DWORD Fire(ObjectClass* pTarget, int nWeapon)
		{ PUSH_VAR32(nWeapon); PUSH_VAR32(pTarget); THISCALL_RET(0x51DF60, DWORD); }
	virtual void vt_entry_428()
		{ THISCALL(0x51F330); }
	virtual DWORD DisguiseAs(ObjectClass *Target)
		{ PUSH_VAR32(Target); THISCALL_RET(0x522700, DWORD); }
	virtual void ClearDisguise()
		{ THISCALL(0x522780); }
	virtual bool vt_entry_474()
		{ THISCALL_RET(0x5216D0, bool); }
	virtual bool vt_entry_478()
		{ THISCALL_RET(0x51CDB0, bool); }
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x51CBA0); }

	//FootClass
	virtual void vt_entry_4F4()
		{ THISCALL(0x521DD0); }
	virtual bool vt_entry_4F8()
		{ THISCALL_RET(0x521EB0, bool); }
	virtual bool MoveTo(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x51DBD0, bool); }
	virtual bool StopMoving()
		{ THISCALL_RET(0x51DAF0, bool); }
	virtual bool vt_entry_508(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
								THISCALL_RET(0x522FE0, bool); }
	virtual void vt_entry_514()
		{ THISCALL(0x5220F0); }
	virtual void Panic()
		{ THISCALL(0x5220F0); }
	virtual void UnPanic()
		{ THISCALL(0x5220F0); }
	virtual void PlayIdleAnim(int nIdleAnimNumber)
		{ PUSH_VAR32(nIdleAnimNumber); THISCALL(0x5220F0); }
	virtual int GetCurrentSpeed()
		{ THISCALL_RET(0x521D80, int); }
	virtual DWORD vt_entry_53C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x522340, DWORD); }
	virtual void vt_entry_548()
		{ THISCALL(0x521B20); }
	virtual void vt_entry_54C()
		{ THISCALL(0x521B40); }

	//InfantryClass
	virtual bool IsDeployed()
		{ THISCALL_RET(0x5228D0, bool); }
	virtual bool PlayAnim(int nAnimNumber, bool bUnk, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR8(bUnk); PUSH_VAR32(nAnimNumber); THISCALL_RET(0x51D6F0, bool); }
	
	//Constructor
	InfantryClass(InfantryTypeClass* pType, HouseClass* pOwner):FootClass(false)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x7353C0); }

protected:
	InfantryClass():FootClass()
		{ }
	InfantryClass(bool X):FootClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(InfantryTypeClass*, Type);
	PROPERTY(int,            SequenceAnim); //which is currently playing
	PROPERTY_STRUCT(TimerStruct,    unknown_Timer_6C8);
	PROPERTY(DWORD,          unknown_6D4);
	PROPERTY(bool,           unknown_bool_6D8);
	PROPERTY(bool,           Technician);
	PROPERTY(bool,           unknown_bool_6DA);
	PROPERTY(bool,           Crawling);
	PROPERTY(bool,           unknown_bool_6DC);
	PROPERTY(bool,           unknown_bool_6DD);
	PROPERTY(DWORD,          unknown_6E0);
	PROPERTY(bool,           unknown_bool_6E4);
	PROPERTY(int,            unknown_int_6E8);
	PROTECTED_PROPERTY(DWORD, unused_6EC); //??
};

#endif
