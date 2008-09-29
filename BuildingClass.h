/*
	Buildings
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <TechnoClass.h>
#include <BuildingTypeClass.h>

class BuildingLightClass;
class FactoryClass;
class InfantryClass;
class LightSourceClass;

class BuildingClass : public TechnoClass
{
public:
	//Static
	static DynamicVectorClass<BuildingClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x459E80); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x453E20); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x454190); }

	//Destructor
	virtual ~BuildingClass()
		{ THISCALL(0x43BCF0); }

	//AbstractClass
	virtual void Init()
		{ THISCALL(0x442C40); }
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x44E8F0); }
	virtual eAbstractType WhatAmI()
		{ return abs_Building; }
	virtual int Size()
		{ return sizeof(BuildingClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x454260); }
	virtual void Update()
		{ THISCALL(0x43FB20); }

	//ObjectClass
	virtual CoordStruct* GetCoords(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x447AC0); }
	virtual CoordStruct* GetCoords_(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x447E90); }
	virtual eVisualType VisualCharacter(VARIANT_BOOL flag, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR8(flag); THISCALL(0x4544A0); }
	virtual SHPStruct* GetImage()
		{ THISCALL(0x4513D0); }
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(bUnk1); PUSH_VAR32(uCell); THISCALL(0x447540); }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ PUSH_VAR8(bUnk1); PUSH_VAR32(pObj); THISCALL(0x447210); }
	virtual bool CanBeUndeployed()
		{ THISCALL(0x457620); }
	virtual ObjectTypeClass* GetType()
		{ return this->Type; }
	virtual TechnoTypeClass* GetTechnoType()
		{ return this->Type; }
	virtual wchar_t* GetUIName()
		{ THISCALL(0x459ED0); }
	virtual bool CanBeRepaired()
		{ THISCALL(0x452630); }
	virtual bool CanBeSold()
		{ THISCALL(0x4494C0); }
	virtual bool vt_entry_A0()
		{ THISCALL(0x44F5C0); }
	virtual CoordStruct* vt_entry_A4(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x4500A0); }
	virtual CoordStruct* vt_entry_A8(CoordStruct* pCrd, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCrd); THISCALL(0x447B20); }
	virtual CoordStruct* vt_entry_AC(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x459EF0); }
	virtual CoordStruct* GetFLH(CoordStruct *pDest, int idxWeapon, int nFLH_X, int nFLH_Y, int nFLH_Z)
		{ PUSH_VAR32(nFLH_Z); PUSH_VAR32(nFLH_Y); PUSH_VAR32(nFLH_X);
		  PUSH_VAR32(idxWeapon); PUSH_VAR32(pDest); THISCALL(0x453840); }
	virtual CoordStruct* GetExitCoords(CoordStruct* pCrd, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCrd); THISCALL(0x44F640); }
	virtual int vt_entry_B8()
		{ THISCALL(0x449410); }
	virtual bool Exit()
		{ THISCALL(0x445880); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL(0x440580); }
	virtual void vt_entry_DC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x44EBF0); }
	virtual void vt_entry_F0(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x453D60); }
	virtual void vt_entry_F4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x453DC0); }
	virtual int KickOutUnit(TechnoClass* pTechno, CellStruct uCell)
		{ PUSH_VAR32(uCell); PUSH_VAR32(pTechno); THISCALL(0x443C60); }
	virtual bool vt_entry_104(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x43CEA0); }
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x43D290); }
	virtual void vt_entry_118(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x5F65D0); }
	virtual bool SetLayer(eLayer value)
		{ PUSH_VAR32(value); THISCALL(0x43F180); }
	virtual RectangleStruct* vt_entry_12C(RectangleStruct* pRect)
		{ PUSH_VAR32(pRect); THISCALL(0x455C20); }
	virtual void DrawRadialIndicator(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x456750); } // nop in all except BuildingClass
	virtual bool vt_entry_13C()
		{ THISCALL(0x459C00); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4436F0); }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x443410); }
	virtual void Flash(int Duration)
		{ PUSH_VAR32(Duration); THISCALL(0x456E00); }
	virtual void IronCurtain(int nDuration, HouseClass *pSource, bool ForceShield)
		{ PUSH_VAR8(ForceShield); PUSH_VAR32(pSource); PUSH_VAR32(nDuration); THISCALL(0x457C90); }

	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH, ObjectClass* pAttacker, DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse)
		{ PUSH_VAR32(pAttackingHouse); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2);
		  PUSH_VAR32(pAttacker); PUSH_VAR32(pWH); PUSH_VAR32(dwUnk1);
		  PUSH_VAR32(pDamage); THISCALL(0x442230); }
	virtual void ReceiveCommand(TechnoClass *From, eRadioCommands rcDoThis, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(From); PUSH_VAR32(rcDoThis); THISCALL(0x43C2D0); }
	virtual bool vt_entry_198(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x44D5D0); }
	virtual void vt_entry_19C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x446FF0); }
	virtual void Sell(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x447110); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ PUSH_VAR32(dwUnk5); PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		  THISCALL(0x449440); }

	//MissionClass
	virtual bool vt_entry_200()
		{ return unknown_bool_6DD; }
	virtual int Mission_Attack()
		{ THISCALL(0x44ACF0); }
	virtual int Mission_Capture()
		{ THISCALL(0x44B760); }
	virtual int Mission_Guard()
		{ THISCALL(0x4496B0); }
	virtual int Mission_AreaGuard()
		{ THISCALL(0x449A40); }
	virtual int Mission_Harvest()
		{ THISCALL(0x44B770); }
	virtual int Mission_Unload()
		{ THISCALL(0x44D880); }
	virtual int Mission_Construction()
		{ THISCALL(0x449A50); }
	virtual int Mission_Selling()
		{ THISCALL(0x449C30); }
	virtual int Mission_Repair()
		{ THISCALL(0x44B780); }
	virtual int Mission_Missile()
		{ THISCALL(0x44C980); }
	virtual int Mission_Open()
		{ THISCALL(0x44E440); }

	//TechnoClass
	virtual bool IsUnitFactory()
		{ THISCALL(0x455DA0); }

	virtual bool ShouldBeCloaked()
		{ THISCALL(0x457770); }
	virtual bool ShouldNotBeCloaked()
		{ THISCALL(0x4578C0); }
	virtual FacingStruct* vt_entry_2A8(FacingStruct* pFacing)
		{ PUSH_VAR32(pFacing); THISCALL(0x445E50); }
	virtual bool IsArmed()
		{ THISCALL(0x458DB0); }
	virtual int GetPipFillLevel()
		{ THISCALL(0x44D700); }
	virtual DWORD vt_entry_2C8(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x43E940); }
	virtual int GetCrewCount()
		{ THISCALL(0x451330); }
	virtual int GetAntiAirValue()
		{ return Type->get_AntiAirValue(); }
	virtual int GetAntiArmorValue()
		{ return Type->get_AntiArmorValue(); }
	virtual int GetAntiInfantryValue()
		{ return Type->get_AntiInfantryValue(); }
	virtual void vt_entry_2E0()
		{ THISCALL(0x4576F0); }
	virtual DWORD vt_entry_2EC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x43E900); }
	virtual DWORD vt_entry_300(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x453A70); }
	virtual DWORD vt_entry_308(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x44D7D0); }
	virtual InfantryTypeClass* GetCrew()
		{ THISCALL(0x44EB10); }
	virtual bool vt_entry_324(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x457020); }
	virtual bool IsPowerOnline()
		{ THISCALL(0x4555D0); }
	virtual int VoiceDeploy()
		{ THISCALL(0x459C20); }
	virtual void vt_entry_3B8()
		{ THISCALL(0x44D760); }
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x447F10); }
	virtual CellClass* SelectAutoTarget(int TargetFlags, int CurrentThreat, bool OnlyTargetHouseEnemy)
		{ PUSH_VAR8(OnlyTargetHouseEnemy); PUSH_VAR32(CurrentThreat); PUSH_VAR32(TargetFlags); THISCALL(0x445F00); }
	virtual void SetTarget(AbstractClass *Target)
		{ PUSH_VAR32(Target); THISCALL(0x443B90); }
	virtual void SetOwningHouse(HouseClass* pHouse, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pHouse); THISCALL(0x448260); }
	virtual WeaponStruct* GetWeapon(int nWeaponNumber)
		{ PUSH_VAR32(nWeaponNumber); THISCALL(0x4526F0); }
	virtual bool HasTurret()
		{ THISCALL(0x4527D0); }
	virtual bool CanOccupyFire()
		{ THISCALL(0x458DD0); }
	virtual DWORD vt_entry_404()
		{ THISCALL(0x458E00); }
	virtual int GetOccupantCount()
		{ THISCALL(0x4581F0); }

	virtual void UpdateTimers()
		{ THISCALL(0x6FB740); }
	virtual DWORD vt_entry_464(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x456F80); }
	virtual void UpdateRefinerySmokeSystems()
		{ THISCALL(0x459900); }
	virtual void SetDestination(CellClass* pCell, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pCell); THISCALL(0x455D50); }
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x44D6A0); }

	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x458A80); }
	virtual void vt_entry_494()
		{ THISCALL(0x456580); }
	virtual void vt_entry_498()
		{ THISCALL(0x4565E0); }
	virtual void vt_entry_49C()
		{ THISCALL(0x456640); }

	//BuildingClass
	virtual CellStruct* vt_entry_4D4(CellStruct* pCellStruct, DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); PUSH_VAR32(pCellStruct); THISCALL(0x44EFB0); }
	virtual int vt_entry_4D8(ObjectClass* pObj)
		{ PUSH_VAR32(pObj); THISCALL(0x447E00); }
	virtual void Place(bool bUnk)
		{ PUSH_VAR8(bUnk); THISCALL(0x445F80); }
	virtual int vt_entry_4E0()
		{ THISCALL(0x4456D0); }
	virtual void vt_entry_4E4(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x43DA80); }
	virtual CellStruct* vt_entry_4E8(CellStruct* pCellStruct, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCellStruct); THISCALL(0x43ED40); }
	virtual void vt_entry_4EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x4415F0); }
	virtual bool vt_entry_4F0()
		{ THISCALL(0x448160); }
	virtual void vt_entry_4F4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x455820); }
	virtual void vt_entry_4F8(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4556D0); }
	virtual void vt_entry_4FC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x455A80); }
	virtual void vt_entry_500(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x455980); }
	virtual DWORD vt_entry_504()
		{ return 0; }

	// non-vt

	// kick out content
	void UnloadBunker()
		{ THISCALL(0x4593A0); }

	// content is dead - chronosphered away or died inside
	void ClearBunker()
		{ THISCALL(0x459470); }

	// kick out content, remove anims, etc... don't ask me what's different from kick out
	void EmptyBunker()
		{ THISCALL(0x4595C0); }

	//Constructor
	BuildingClass(BuildingTypeClass* pType, HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x43B740); }

protected:
	BuildingClass():TechnoClass(false)
		{ }
	BuildingClass(bool X):TechnoClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(BuildingTypeClass*, Type);
	PROPERTY(FactoryClass*, Factory);
	PROPERTY_STRUCT(TimerStruct, C4Timer);
	PROPERTY(int, unknown_int_534);
	PROPERTY(int, unknown_int_538);
	PROPERTY(DWORD, OwnerCountryIndex);
	PROPERTY(DWORD, unknown_540); //pointer
	PROPERTY(DWORD, unknown_544);
	PROPERTY(DWORD, unknown_548); //pointer
	PROPERTY(DWORD, unknown_54C); //pointer
	PROPERTY_STRUCT(TimerStruct, unknown_timer_550);


// see eBuildingAnims above for slot index meanings
	PROPERTY_ARRAY(AnimClass *, Anims, 0x15);
/*
	//55C = AnimClass* Anims[0x15]
			//Anims[3] = ActiveAnim
protected:
	AnimClass* StateAnims[0x15];
public:
	AnimClass* get_StateAnims(int i)
		{ return StateAnims[i]; }
*/

protected:
	DWORD align_5B0, align_5B4, align_5B8, align_5BC;
	DWORD align_5C0, align_5C4;

	PROPERTY_ARRAY(AnimClass *, DamageFireAnims, 0x8);
	//5C8 = array of ??? pointers [8]
/*
protected:
	AnimClass* DamageFireAnims[0x8];
public:
	AnimClass* get_DamageFireAnims(int i)
		{ return DamageFireAnims[i]; }
*/

	PROPERTY(bool, RequiresDamageFires); // if set, ::Update spawns damage fire anims and zeroes it
	//5E8 - 5F8 ????????
	PROPERTY_ARRAY(BuildingTypeClass *, Upgrades, 0x3);
/*
protected:
	BuildingTypeClass* Upgrades[0x3];
public:
	BuildingTypeClass* get_Upgrades(int i)
		{ return Upgrades[i]; }
*/

	PROPERTY(DWORD, FiringSWType); // type # of sw being launched
	PROPERTY(DWORD, unknown_5FC);
	PROPERTY(BuildingLightClass*, Spotlight);
	PROPERTY_STRUCT(TimerStruct, unknown_timer_604);
	PROPERTY(DWORD, unknown_610);
	PROPERTY(LightSourceClass *, LightSource); // tiled light , LightIntensity > 0
	PROPERTY(DWORD, unknown_618);
	PROPERTY(DWORD, unknown_61C);
	PROPERTY(DWORD, unknown_620);
	PROPERTY(bool, unknown_bool_624);
	PROPERTY_STRUCT(TimerStruct, LastInfantryEntry); // for hospital, armory, etc
	PROPERTY(int, unknown_int_634);
	PROPERTY(int, unknown_int_638);
	PROPERTY_STRUCT(RectangleStruct, unknown_rect_63C);
	PROPERTY_STRUCT(CoordStruct, unknown_coord_64C);
	PROPERTY(int, unknown_int_658);
	PROPERTY(DWORD, unknown_65C);
	PROPERTY(bool, HasPower);
	PROPERTY(bool, IsOverpowered);

			// each powered unit controller building gets this set on power activation and unset on power outage
	PROPERTY(bool, RegisteredAsPoweredUnitSource);

	PROPERTY(DWORD, SupportingPrisms);
	PROPERTY(bool, unknown_bool_668);
	PROPERTY(bool, ConsumesExtraPower);
	PROPERTY_STRUCT(DynamicVectorClass<InfantryClass*>, Overpowerers);
	PROPERTY_STRUCT(DynamicVectorClass<InfantryClass*>, Occupants);
	PROPERTY(DWORD, unknown_69C);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio7);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio8);

	PROPERTY(bool, unknown_bool_6C8);
	PROPERTY(bool, ShowRealName);
	PROPERTY(bool, BeingProduced);
	PROPERTY(bool, ShouldRebuild);
	PROPERTY(bool, unknown_bool_6CC);
	PROPERTY_STRUCT(TimerStruct, CashProductionTimer);
	PROPERTY(bool, unknown_bool_6DC);
	PROPERTY(bool, unknown_bool_6DD);
	PROPERTY(bool, NeedsRepairs); // AI handholder for repair logic, 
	PROPERTY(bool, C4Applied);
	PROPERTY(bool, unknown_bool_6E0);
	PROPERTY(bool, unknown_bool_6E1);
	PROPERTY(bool, unknown_bool_6E2);
	PROPERTY(bool, unknown_bool_6E3);
	PROPERTY(bool, ActuallyPlacedOnMap);
	PROPERTY(bool, unknown_bool_6E5);
	PROPERTY(bool, IsDamaged); // AI handholder for repair logic, 
	PROPERTY(bool, unknown_bool_6E7);
	PROPERTY(bool, IsBeingRepaired); // show animooted repair wrench
	PROPERTY(bool, unknown_bool_6E9);
	PROPERTY(bool, unknown_bool_6EA);
	PROPERTY(bool, HasCloakingData); // some fugly buffers
	PROPERTY(byte, CloakRadius); // from Type->CloakRadiusInCells
	PROPERTY(bool, unknown_bool_6ED);
	PROPERTY(DWORD, StorageFilledSlots); // the old "silo needed" logic

		// randomly assigned secret lab bonus, one of those three gets returned instead if NULL
	PROPERTY(DWORD, SecretProduction); /*pointer, something to do with SecretInfantry, SecretUnit, SecretBuilding */

	PROPERTY_STRUCT(ColorStruct, ColorAdd);
	PROPERTY(int, unknown_int_6FC);
	PROPERTY(short, unknown_short_700);
	PROPERTY(bool, UpgradeLevel); // as defined by Type->UpgradesToLevel=
	PROPERTY(ePrismChargeState, PrismStage);
	PROPERTY_STRUCT(CoordStruct, PrismTargetCoords);
	PROPERTY(DWORD, PrismReloadDelay);

	PROPERTY(DWORD, unknown_714);
	PROPERTY(DWORD, unknown_718);

protected:
	DWORD align_71C;

};

#endif
