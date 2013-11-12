/*
	Buildings
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <TechnoClass.h>
#include <BuildingTypeClass.h>
#include <BuildingLightClass.h>
#include <ProgressTimer.h>
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
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//ObjectClass
	//MissionClass
	//TechnoClass
	virtual void Destroyed(ObjectClass* Killer) RX;
	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2) RX;

	//BuildingClass
	virtual CellStruct* vt_entry_4D4(CellStruct* pCellStruct, DWORD dwUnk, DWORD dwUnk2) const R0;
	virtual int vt_entry_4D8(ObjectClass* pObj) const R0;
	virtual void Place(bool bUnk) RX;
	virtual void UpdateConstructionOptions() RX;
	virtual void vt_entry_4E4(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual CellStruct* vt_entry_4E8(CellStruct* pCellStruct, DWORD dwUnk) const R0;
	virtual void vt_entry_4EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual bool TogglePrimaryFactory() R0;
	virtual void SensorArrayActivate(CellStruct cell=CellStruct::Empty) RX;
	virtual void SensorArrayDeactivate(CellStruct cell=CellStruct::Empty) RX;
	virtual void DisguiseDetectorActivate(CellStruct cell=CellStruct::Empty) RX;
	virtual void DisguiseDetectorDeactivate(CellStruct cell=CellStruct::Empty) RX;
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
	DWORD GetFWFlags() const
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
	void DestroyNthAnim(BuildingAnimSlot::Value Slot)
		{ JMP_THIS(0x451E40); }

	void PlayNthAnim(BuildingAnimSlot::Value Slot, int dwUnk = 0) {
		bool Damaged = !this->IsGreenHP();
		bool Garrisoned = this->GetOccupantCount() > 0;

		BuildingAnimStruct *AnimData = &this->Type->BuildingAnim[Slot];
		char *AnimName = nullptr;
		if(Damaged) {
			AnimName = AnimData->Damaged;
		} else if(Garrisoned) {
			AnimName = AnimData->Garrisoned;
		} else {
			AnimName = AnimData->Anim;
		}
		if(AnimName && *AnimName) {
			this->PlayAnim(AnimName, Slot, Damaged, Garrisoned, dwUnk);
		}
	}

	int PlayAnim(char *animName, BuildingAnimSlot::Value Slot, bool Damaged, bool Garrisoned, int dwUnk = 0)
		{ JMP_THIS(0x451890); }

	// when the building is switched off
	void DisableStuff()
		{ JMP_THIS(0x452480); }

	// when the building is switched on
	void EnableStuff()
		{ JMP_THIS(0x452410); }

	// when the building is warped
	void DisableTemporal()
		{ JMP_THIS(0x4521C0); }

	// when the building warped back in
	void EnableTemporal()
		{ JMP_THIS(0x452210); }

	// returns Type->SuperWeapon, if its AuxBuilding is satisfied
	int FirstActiveSWIdx() const
		{ JMP_THIS(0x457630); }

	// returns Type->SuperWeapon2, if its AuxBuilding is satisfied
	int SecondActiveSWIdx() const
		{ JMP_THIS(0x457690); }

	void FireLaser(CoordStruct Coords)
		{ JMP_THIS(0x44ABD0); }

	bool IsBeingDrained() const
		{ JMP_THIS(0x70FEC0); }

	bool UpdateBunker()
		{ JMP_THIS(0x458E50); }

	//Constructor
	BuildingClass(BuildingTypeClass* pType, HouseClass* pOwner) : TechnoClass(false)
		{ JMP_THIS(0x43B740); }

	// helpers
	bool HasSuperWeapon(int Type) const {
		if(this->Type->HasSuperWeapon(Type)) {
			return true;
		}
		for(int i = 0; i < 3; ++i) {
			if(BuildingTypeClass * BType = this->Upgrades[i]) {
				if(BType->HasSuperWeapon(Type)) {
					return true;
				}
			}
		}
		return false;
	}

protected:
	BuildingClass() : TechnoClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	BuildingTypeClass* Type;
	FactoryClass* Factory;
	TimerStruct C4Timer;
	int unknown_int_534;
	int unknown_int_538;
	DWORD OwnerCountryIndex;
	InfantryClass* C4AppliedBy;
	DWORD unknown_544;
	AnimClass* FirestormAnim; //pointer
	AnimClass* PsiWarnAnim; //pointer
	TimerStruct unknown_timer_550;

// see eBuildingAnims above for slot index meanings
	AnimClass * Anims [0x15];
	bool AnimStates [0x15]; // one flag for each of the above anims (whether the anim was enabled when power went offline?)

protected:
	char align_5C5[3];
public:

	AnimClass * DamageFireAnims [0x8];

	bool RequiresDamageFires; // if set, ::Update spawns damage fire anims and zeroes it
	//5E8 - 5F8 ????????
	BuildingTypeClass * Upgrades [0x3];

	int FiringSWType; // type # of sw being launched
	DWORD unknown_5FC;
	BuildingLightClass* Spotlight;
	RepeatableTimerStruct GateTimer;
	LightSourceClass * LightSource; // tiled light , LightIntensity > 0
	DWORD LaserFenceFrame; // 0-7 for active directionals, 8/12 for offline ones, check ntfnce.shp or whatever
	DWORD FirestormWallFrame; // anim data for firestorm active animations
	ProgressTimer RepairProgress; // for hospital, armory, unitrepair etc
	RectangleStruct unknown_rect_63C;
	CoordStruct unknown_coord_64C;
	int unknown_int_658;
	DWORD unknown_65C;
	bool HasPower;
	bool IsOverpowered;

	// each powered unit controller building gets this set on power activation and unset on power outage
	bool RegisteredAsPoweredUnitSource;

	DWORD SupportingPrisms;
	bool HasExtraPowerBonus;
	bool HasExtraPowerDrain;
	DynamicVectorClass<InfantryClass*> Overpowerers;
	DynamicVectorClass<InfantryClass*> Occupants;
	int FiringOccupantIndex; // which occupant should get XP, which weapon should be fired (see 6FF074)

	AudioController Audio7;
	AudioController Audio8;

	bool WasOnline; // the the last state when Update()ing. if this changed since the last Update(), UpdatePowered is called.
	bool ShowRealName;
	bool BeingProduced;
	bool ShouldRebuild;
	bool HasEngineer; // used to pass the NeedsEngineer check
	TimerStruct CashProductionTimer;
	bool unknown_bool_6DC;
	bool unknown_bool_6DD;
	bool NeedsRepairs; // AI handholder for repair logic,
	bool C4Applied;
	bool NoCrew;
	bool unknown_bool_6E1;
	bool unknown_bool_6E2;
	bool HasBeenCaptured; // has this building changed ownership at least once? affects crew and repair.
	bool ActuallyPlacedOnMap;
	bool unknown_bool_6E5;
	bool IsDamaged; // AI handholder for repair logic,
	bool IsFogged;
	bool IsBeingRepaired; // show animooted repair wrench
	bool unknown_bool_6E9;
	bool unknown_bool_6EA;
	char HasCloakingData; // some fugly buffers
	byte CloakRadius; // from Type->CloakRadiusInCells
	bool unknown_bool_6ED;
	DWORD StorageFilledSlots; // the old "silo needed" logic

		// randomly assigned secret lab bonus, one of those three gets returned instead if NULL
	TechnoTypeClass * SecretProduction; /*pointer, something to do with SecretInfantry, SecretUnit, SecretBuilding */

	ColorStruct ColorAdd;
	int unknown_int_6FC;
	short unknown_short_700;
	bool UpgradeLevel; // as defined by Type->UpgradesToLevel=
	char GateStage;
	ePrismChargeState PrismStage;
	CoordStruct PrismTargetCoords;
	DWORD DelayBeforeFiring;

	int BunkerState; // used in UpdateBunker and friends
};

#endif
