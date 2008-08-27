/*
	Ground & Naval Vehicles
*/

#ifndef UNIT_H
#define UNIT_H

#include <FootClass.h>
#include <UnitTypeClass.h>

//forward declarations
class EBolt;

class UnitClass : public FootClass
{
public:
	//Static
	static DynamicVectorClass<UnitClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x746DE0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x744470); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x744600); }

	//Destructor
	virtual ~UnitClass()
		{ THISCALL(0x735780); }

	//AbstractClass
	virtual void Init()
		{ THISCALL(0x746810); }
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x7446E0); }
	virtual eAbstractType WhatAmI()
		{ return abs_Unit; }
	virtual int Size()
		{ return sizeof(UnitClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x744640); }
	virtual void Update()
		{ THISCALL(0x7360C0); }

	//ObjectClass
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL(0x7404B0); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL(0x73FD50); }
	virtual bool CanBeUndeployed()
		{ return Type->get_NonVehicle(); }
	virtual ObjectTypeClass* GetType()
		{ return Type; }
	virtual wchar_t* GetUIName()
		{ THISCALL(0x746B20); }
	virtual bool IsDisguisedAs(HouseClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x746750); }
	virtual ObjectTypeClass* GetDisguise(bool DisguisedAgainstAllies)
		{ PUSH_VAR8(DisguisedAgainstAllies); THISCALL(0x7465B0); }
	virtual HouseClass* GetDisguiseHouse(bool DisguisedAgainstAllies)
		{ PUSH_VAR8(DisguisedAgainstAllies); THISCALL(0x7465F0); }
	virtual bool vt_entry_D4()
		{ THISCALL(0x7440B0); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd);
								THISCALL(0x737BA0); }
	virtual void RegisterDestruction(TechnoClass *pDestroyer) // Raises Map Events, grants veterancy, increments house kill counters
								{ PUSH_VAR32(pDestroyer); THISCALL(0x744720); }
	virtual void vt_entry_F0(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x7441B0); }
	virtual void vt_entry_F4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x744210); }
	virtual bool vt_entry_104(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x73B0B0); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x73CEC0); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x738910); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x738890); }
	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH,
	  ObjectClass* pAttacker, DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse)
		{ PUSH_VAR32(pAttackingHouse); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(pAttacker); 
		  PUSH_VAR32(pWH); PUSH_VAR32(dwUnk1); PUSH_VAR32(pDamage); THISCALL(0x737C90); }
	virtual void FreeCaptured()
		{ THISCALL(0x746D60); }
	virtual void Scatter(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x743A50); }
	virtual void UpdatePosition(int dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x739EC0); }
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x737430); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL(0x73F0A0); }

	//MissionClass
	virtual bool vt_entry_200()
		{ THISCALL(0x744270); }

	//virtual int Mission_Attack() { THISCALL(0x4D4DC0); } //jumps to FootClass
	virtual int Mission_Guard()
		{ THISCALL(0x740810); }
	virtual int Mission_AreaGuard()
		{ THISCALL(0x744100); }
	virtual int Mission_Harvest()
		{ THISCALL(0x73E5E0); }
	virtual int Mission_Hunt()
		{ THISCALL(0x73EFC0); }
	virtual int Mission_Move()
		{ THISCALL(0x740A90); }
	virtual int Mission_Unload()
		{ THISCALL(0x73D630); }
	virtual int Mission_Repair()
		{ THISCALL(0x740EF0); }
	virtual int Mission_Patrol()
		{ THISCALL(0x7F5ECC); }

	//TechnoClass
	virtual bool vt_entry_29C()
		{ THISCALL(0x744180); }
	virtual FacingStruct* vt_entry_2A8(FacingStruct* pFacing)
		{ PUSH_VAR32(pFacing); THISCALL(0x746E30); }
	virtual double GetStoragePercentage()
		{ THISCALL(0x7414A0); }
	virtual DWORD SelectWeapon(ObjectClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x746CD0); }
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x740B60); }
	virtual DWORD vt_entry_308(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x740F80); }
	//virtual InfantryTypeClass* GetCrew() { THISCALL(0x707D20); } //jumps to TechnoClass
	virtual bool IsUnderEMP()
		{ THISCALL(0x746C90); }
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
								THISCALL(0x740FD0); }
	virtual CellClass* vt_entry_3C4(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
								THISCALL(0x743190); }
	virtual DWORD Fire(ObjectClass* pTarget, int nWeapon)
		{ PUSH_VAR32(nWeapon); PUSH_VAR32(pTarget); THISCALL(0x741340); }
	virtual void SetOwningHouse(HouseClass* pHouse, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pOwner); THISCALL(0x7463A0); }
	virtual void Reload()
		{ THISCALL(0x736CA0); }
	virtual DWORD DisguiseAs(ObjectClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x746670); }
	virtual void ClearDisguise()
		{ THISCALL(0x746720); }
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x741970); }
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x738970); }

	//FootClass
	virtual void vt_entry_4D4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x746420); }
	virtual void vt_entry_4D8(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x7464E0); }
	virtual bool vt_entry_4E4()
		{ THISCALL(0x736D50); }
	virtual void vt_entry_534(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x7416A0); }
	virtual DWORD vt_entry_53C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x7414E0); }

	//UnitClass
	virtual void DrawVXL(
	  DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
	  DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8)
		{
			PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7); PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5);
			PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
			THISCALL(0x73B470);
		}

	virtual void DrawSHP(
	  DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
	  DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8)
	{
		PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7); PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5);
		PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		THISCALL(0x73C5F0);
	}
	
	//Constructor
	UnitClass(UnitTypeClass* pType, HouseClass* pOwner):FootClass(false)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x7353C0); }

protected:
	UnitClass():FootClass()
		{ }
	UnitClass(bool X):FootClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int, unknown_int_6C0);
	PROPERTY(UnitTypeClass*, Type);
	PROPERTY(DWORD, unknown_6C8);
	PROPERTY(int, FlagHouseIndex); //Carrying the flag of this House
	PROPERTY(bool, Deployed);
	PROPERTY(bool, Unloading);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(bool, unknown_bool_6D3);
	PROPERTY(int, unknown_int_6D4);
	PROPERTY(int, unknown_int_6D8);
	PROPERTY(EBolt*, ElectricBolt); //Unit is the owner of this
	PROPERTY(bool, unknown_bool_6E0);
	PROPERTY(bool, unknown_bool_6E1);
	PROPERTY(bool, unknown_bool_6E2);
	
// isn't this what PROPERTY_UNICODE was for?
protected:
	wchar_t ToolTipText[0x100];

public:
	const wchar_t* get_ToolTipText()
		{ return ToolTipText; }
	void set_ToolTipText(const wchar_t* src)
		{ wcsncpy(ToolTipText, src, 0x100); }
};

#endif
