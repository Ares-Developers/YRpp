/*
	Buildings
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <TechnoClass.h>
#include <BuildingTypeClass.h>
#include <BuildingLightClass.h>
class FactoryClass;
class InfantryClass;
class LightSourceClass;

class BuildingClass : public TechnoClass
{
public:
	enum {AbsID = abs_Building};

	//Static
	static DynamicVectorClass<BuildingClass*>* Array;

	static CellStruct &DefaultCellCoords;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	//Destructor
	virtual ~BuildingClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//ObjectClass
	//MissionClass
	//TechnoClass
	virtual void Destroyed(ObjectClass* Killer) RX;
	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2) RX;

	//BuildingClass
	virtual CellStruct* vt_entry_4D4(CellStruct* pCellStruct, DWORD dwUnk, DWORD dwUnk2) R0;
	virtual int vt_entry_4D8(ObjectClass* pObj) R0;
	virtual void Place(bool bUnk) RX;
	virtual int vt_entry_4E0() R0;
	virtual void vt_entry_4E4(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual CellStruct* vt_entry_4E8(CellStruct* pCellStruct, DWORD dwUnk) R0;
	virtual void vt_entry_4EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual bool vt_entry_4F0() R0;
	virtual void vt_entry_4F4(DWORD dwUnk) RX;
	virtual void vt_entry_4F8(DWORD dwUnk) RX;
	virtual void vt_entry_4FC(DWORD dwUnk) RX;
	virtual void vt_entry_500(DWORD dwUnk) RX;
	virtual DWORD vt_entry_504() R0;

	// non-vt

	// power up
	void GoOnline()
		{ JMP_THIS(0x452260); }
	void GoOffline()
		{ JMP_THIS(0x452360); }

	// Firewall aka FirestormWall
	// depending on what facings of this building
	// are connected to another FWall,
	// returns the index of the image file
	// to draw.
	DWORD GetFWFlags()
		{ JMP_THIS(0x455B90); }

	void CreateEndPost(bool arg)
		{ JMP_THIS(0x4533A0); }

	// kick out content
	void UnloadBunker()
		{ JMP_THIS(0x4593A0); }

	// content is dead - chronosphered away or died inside
	void ClearBunker()
		{ JMP_THIS(0x459470); }

	// kick out content, remove anims, etc... don't ask me what's different from kick out
	void EmptyBunker()
		{ JMP_THIS(0x4595C0); }

	// called after destruction - CrateBeneath, resetting foundation'ed cells
	void AfterDestruction()
		{ JMP_THIS(0x441F60); }

	// destroys the specific animation (active, turret, special, etc)
	void DestroyNthAnim(BuildingAnimSlot Slot)
		{ JMP_THIS(0x451E40); }

	//Constructor
	BuildingClass(BuildingTypeClass* pType, HouseClass* pOwner) : TechnoClass(false)
		{ JMP_THIS(0x43B740); }

protected:
	BuildingClass() : TechnoClass(false) { }

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
	PROPERTY(AnimClass*, FirestormAnim); //pointer
	PROPERTY(DWORD, PsiWarnAnim); //pointer
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
	PROPERTY(DWORD, LaserFenceFrame); // 0-7 for active directionals, 8/12 for offline ones, check ntfnce.shp or whatever
	PROPERTY(DWORD, FirestormWallFrame); // anim data for firestorm active animations
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
	PROPERTY(int, FiringOccupantIndex); // which occupant should get XP, which weapon should be fired (see 6FF074)

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
	PROPERTY(bool, IsFogged);
	PROPERTY(bool, IsBeingRepaired); // show animooted repair wrench
	PROPERTY(bool, unknown_bool_6E9);
	PROPERTY(bool, unknown_bool_6EA);
	PROPERTY(bool, HasCloakingData); // some fugly buffers
	PROPERTY(byte, CloakRadius); // from Type->CloakRadiusInCells
	PROPERTY(bool, unknown_bool_6ED);
	PROPERTY(DWORD, StorageFilledSlots); // the old "silo needed" logic

		// randomly assigned secret lab bonus, one of those three gets returned instead if NULL
	PROPERTY(TechnoTypeClass *, SecretProduction); /*pointer, something to do with SecretInfantry, SecretUnit, SecretBuilding */

	PROPERTY_STRUCT(ColorStruct, ColorAdd);
	PROPERTY(int, unknown_int_6FC);
	PROPERTY(short, unknown_short_700);
	PROPERTY(bool, UpgradeLevel); // as defined by Type->UpgradesToLevel=
	PROPERTY(ePrismChargeState, PrismStage);
	PROPERTY_STRUCT(CoordStruct, PrismTargetCoords);
	PROPERTY(DWORD, PrismReloadDelay);

	PROPERTY(DWORD, unknown_714);
	PROPERTY(DWORD, unknown_718); // "healing unit" sound, old hospital mode

protected:
	DWORD align_71C;

};

#endif
