/*
	Base class for buildable objects
*/

#ifndef TECHNO_H
#define TECHNO_H

#include <RadioClass.h>
#include <TechnoTypeClass.h>
#include <CaptureManagerClass.h>
#include <SlaveManagerClass.h>
#include <TemporalClass.h>
#include <Helpers/Template.h>

//forward declarations
class AirstrikeClass;
class AnimClass;
class BulletClass;
class BuildingClass;
class CellClass;
class HouseClass;
class FootClass;
class HouseClass;
class InfantryTypeClass;
class ObjectTypeClass;
class ParticleSystemClass;
class SpawnManagerClass;
class WaveClass;

#include <TransitionTimer.h>

struct VeterancyStruct
{
	float Veterancy;
	DWORD unknown_4;

	bool IsElite()
		{ JMP_THIS(0x750010); }

	bool IsVeteran()
		{ JMP_THIS(0x74FF90); }

	bool IsNegative()
		{ JMP_THIS(0x74FFF0); }

	eRank GetRemainingLevel()
		{ JMP_THIS(0x750030); }

	void Reset()
		{ JMP_THIS(0x750080); }

	void SetRookie(bool NotReally)
		{ JMP_THIS(0x750060); }

	void SetVeteran(bool YesReally)
		{ JMP_THIS(0x750090); }

	void SetElite(bool YesReally)
		{ JMP_THIS(0x7500B0); }
};

class PassengersClass
{
public:
	int NumPassengers;
	FootClass* FirstPassenger;

	void AddPassenger(FootClass* pPassenger)
		{ JMP_THIS(0x4733A0); }

	FootClass* GetFirstPassenger()
		{ return this->FirstPassenger; }

	FootClass* RemoveFirstPassenger()
		{ JMP_THIS(0x473430); }

	int GetTotalSize()
		{ JMP_THIS(0x473460); }

	int IndexOf(FootClass* candidate)
		{ JMP_THIS(0x473500); }
};

struct FlashData
{
	int DurationRemaining;
	bool FlashingNow;

	bool Update()
		{ JMP_THIS(0x4CC770); }
};

struct RecoilData
{
	int Travel;
	int CompressFrames;
	int HoldFrames;
	int RecoverFrames;
	int f_10;
	int f_14;
	int f_18;
	int f_1C;

	void Update()
		{ JMP_THIS(0x70ED10); }

	void Fire()
		{ JMP_THIS(0x70ECE0); }
};

class TechnoClass : public RadioClass
{
public:
	enum {AbsDerivateID = ABSFLAGS_ISTECHNO};

	static DynamicVectorClass<DWORD>* Array; // HAX to instantiate

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TechnoClass() RX;

	//TechnoClass
	virtual bool IsUnitFactory() R0;
	virtual bool IsCloakable() R0;
	virtual bool vt_entry_28C() R0;
	virtual bool BelongsToATeam() R0;
	virtual bool SelfHealNow() R0;
	virtual bool IsVoxel() R0;
	virtual bool vt_entry_29C() R0;
	virtual bool ShouldBeCloaked() R0;
	virtual bool ShouldNotBeCloaked() R0;
	virtual FacingStruct* GetFacing(FacingStruct* pBuffer) R0;
	virtual bool IsArmed() R0; // GetWeapon(primary) && GetWeapon(primary)->WeaponType
	virtual void vt_entry_2B0() RX;
	virtual double GetStoragePercentage() R0;
	virtual int GetPipFillLevel() R0;
	virtual int GetRefund() R0;
	virtual int GetThreatValue() R0;
	virtual bool vt_entry_2C4(DWORD dwUnk) R0;
	virtual DWORD vt_entry_2C8(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual bool vt_entry_2CC(DWORD dwUnk) R0;
	virtual int IsCrewed() R0;
	virtual int GetAntiAirValue() R0;
	virtual int GetAntiArmorValue() R0;
	virtual int GetAntiInfantryValue() R0;
	virtual void vt_entry_2E0() RX;
	virtual DWORD SelectWeapon(ObjectClass *Target) R0;
	virtual int SelectNavalTargeting(ObjectClass *Target) R0;
	virtual int GetZAdjustment() R0;
	virtual int GetZGradient() R0;
	virtual CellStruct* GetSomeCellStruct() R0;
	virtual void SetSomeCellStruct(CellStruct* Buffer) RX;
	virtual CellStruct* vt_entry_2FC(CellStruct* Buffer, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual CoordStruct * vt_entry_300(CoordStruct * Buffer, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD GetRealFacing(DWORD dwUnk) R0;
	virtual InfantryTypeClass* GetCrew() R0;
	virtual bool vt_entry_310() R0;
	virtual bool CanDeploySlashUnload() R0;
	virtual int GetROF(int nWeapon) R0;
	virtual int GetGuardRange(int dwUnk) R0;
	virtual bool vt_entry_320() R0;
	virtual bool vt_entry_324(DWORD dwUnk) R0;
	virtual bool IsSensorVisibleToPlayer() R0;
	virtual bool IsSensorVisibleToHouse(HouseClass *House) R0;
	virtual bool IsEngineer() R0;
	virtual void ProceedToNextPlanningWaypoint() RX;
	virtual DWORD ScanForTiberium(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual bool OnEnterGrinder() R0;
	virtual bool OnEnterBioReactor() R0;
	virtual bool OnEnterTankBunker() R0;
	virtual bool OnEnterBattleBunker() R0;
	virtual bool OnGarrisonStructure() R0;
	virtual bool IsPowerOnline() R0;
	virtual void QueueVoice(int idxVoc) RX;
	virtual int VoiceEnter() R0;
	virtual int VoiceHarvest() R0;
	virtual int VoiceSelect() R0;
	virtual int VoiceCapture() R0;
	virtual int VoiceMove() R0;
	virtual int VoiceDeploy() R0;
	virtual int VoiceAttack(ObjectClass *Target) R0;
	virtual bool vt_entry_374(DWORD dwUnk) R0;
	virtual bool ClickedMission(eMission Mission, DWORD dwUnk2, DWORD dwUnk3, ObjectClass *Target) R0;
	virtual bool IsUnderEMP() R0;
	virtual bool IsParalyzed() R0;
	virtual bool vt_entry_384() R0;
	virtual void vt_entry_388(DWORD dwUnk) RX;
	virtual int GetDefaultSpeed() R0;
	virtual void DecreaseAmmo() RX;
	virtual void AddPassenger(FootClass* pPassenger) RX;
	virtual bool CanDisguiseAs(ObjectClass *Target) R0;
	virtual bool TargetAndEstimateDamage(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_3A0() R0;
	virtual bool TriggersCellInset(ObjectClass *Target) R0;
	virtual bool IsCloseEnough(ObjectClass *Target, int idxWeapon) R0;
	virtual DWORD IsCloseEnoughToAttack(ObjectClass *Target) R0;
	virtual DWORD IsCloseEnoughToAttackCoords(CoordStruct *Coords) R0;
	virtual DWORD vt_entry_3B4(DWORD dwUnk) R0;
	virtual void Destroyed(ObjectClass *Killer) = 0;
	virtual FireError GetFireErrorWithoutRange(ObjectClass *Target, int nWeaponIndex) R0;
	virtual FireError GetFireError(ObjectClass *Target, int nWeaponIndex, bool ignoreRange) R0;
	virtual CellClass* SelectAutoTarget(eTargetFlags TargetFlags, int CurrentThreat, bool OnlyTargetHouseEnemy) R0;
	virtual void SetTarget(AbstractClass *Target) RX;
	virtual BulletClass* Fire(ObjectClass* pTarget, int nWeaponIndex) R0;
	virtual DWORD vt_entry_3D0() R0;
	virtual void SetOwningHouse(HouseClass* pHouse, DWORD dwUnk = 1) RX;
	virtual void vt_entry_3D8(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool Crash(ObjectClass *Killer) R0;
	virtual bool IsAreaFire() R0;
	virtual int IsNotSprayAttack() R0;
	virtual int vt_entry_3E8() R0;
	virtual int IsNotSprayAttack2() R0;
	virtual WeaponStruct* GetDeployWeapon() R0;
	virtual WeaponStruct* GetTurretWeapon() R0;
	virtual WeaponStruct* GetWeapon(int nWeaponIndex) R0;
	virtual bool HasTurret() R0;
	virtual bool CanOccupyFire() R0;
	virtual DWORD vt_entry_404() R0;
	virtual int GetOccupantCount() R0;
	virtual void OnFinishRepair() RX;
	virtual void UpdateTimers() RX;
	virtual void CreateGap() RX;
	virtual void DestroyGap() RX;
	virtual void vt_entry_41C() RX;
	virtual void Sensed() RX;
	virtual void Reload() RX;
	virtual void vt_entry_428() RX;
	virtual CoordStruct* GetTargetCoords(CoordStruct* pCrd) R0;
	virtual bool IsNotWarpingIn() R0;
	virtual bool vt_entry_434(DWORD dwUnk) R0;
	virtual void DrawActionLines(bool Force, DWORD dwUnk2) RX;
	virtual DWORD GetDisguiseFlags(DWORD existingFlags) R0;
	virtual bool IsNotDisguisedAgain(HouseClass *House) R0;

	//nooooooooooooooooooooooooooooooo (vader-style)
	//thought 666 is the number of the beast? in hex it's 444 D=
	virtual void vt_entry_444(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5,
		DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8, DWORD dwUnk9, DWORD dwUnk10) RX;
	virtual void vt_entry_448(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void DrawHealthBar(CoordStruct *Coords, RectangleStruct *Bounds, DWORD dwUnk3) RX;
	virtual void DrawPipScalePips(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual void DrawVeterancyPips(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual void DrawExtraInfo(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual void Uncloak(bool bPlaySound) RX;
	virtual void Cloak(bool bPlaySound) RX;
	virtual DWORD vt_entry_464(DWORD dwUnk) R0;
	virtual void UpdateRefinerySmokeSystems() RX;
	virtual DWORD DisguiseAs(ObjectClass *Target) R0;
	virtual void ClearDisguise() RX;
	virtual bool IsItTimeForIdleActionYet() R0;
	virtual bool UpdateIdleAction() R0;
	virtual void vt_entry_47C(DWORD dwUnk) RX;
	virtual void SetDestination(CellClass* pCell, bool bUnk) RX;
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual void UpdateSight(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5) RX;
	virtual void vt_entry_48C(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2) = 0; //pure virtual
	virtual void vt_entry_494() RX;
	virtual void vt_entry_498() RX;
	virtual void vt_entry_49C() RX;
	virtual void vt_entry_4A0(DWORD dwUnk) RX;
	virtual void vt_entry_4A4(DWORD dwUnk) RX;
	virtual void vt_entry_4A8() RX;
	virtual bool vt_entry_4AC() R0;
	virtual bool vt_entry_4B0() R0;
	virtual int vt_entry_4B4() R0;
	virtual CoordStruct* vt_entry_4B8(CoordStruct* pCrd) R0;
	virtual DWORD vt_entry_4BC() R0;
	virtual bool CanAttackOnTheMove() R0;
	virtual bool vt_entry_4C4() R0;
	virtual bool vt_entry_4C8() R0;
	virtual void vt_entry_4CC() RX;
	virtual bool vt_entry_4D0() R0;

	//non-virtual
	void ReloadNow()
		{ JMP_THIS(0x6FB080); }

	bool ShouldSuppress(CellStruct *coords)
		{ JMP_THIS(0x6F79A0); }

	// smooth operator
	const char *get_ID() {
		ObjectTypeClass *TT = this->GetType();
		return TT ? TT->get_ID() : NULL;
	}

	bool IsMindControlled()
		{ JMP_THIS(0x7105E0); }

	/*
	 *  Cell->AddThreat(this->Owner, -this->ThreatPosed);
	 *  this->ThreatPosed = 0;
	 *  int Threat = this->CalculateThreat(); // this is another gem of a function, to be revealed another time...
	 *  this->ThreatPosed = Threat;
	 *  Cell->AddThreat(this->Owner, Threat);
	 */
	void UpdateThreatInCell(CellClass *Cell)
		{ JMP_THIS(0x70F6E0); }

// CanTargetWhatAmI is a bitfield, if(!(CanTargetWhatAmI & (1 << tgt->WhatAmI())) { fail; }

// slave of the next one
	bool CanAutoTargetObject(
		eTargetFlags TargetFlags,
		int CanTargetWhatAmI,
		int WantedDistance,
		TechnoClass *Target,
		int *ThreatPosed,
		DWORD dwUnk,
		CoordStruct *SourceCoords)
			{ JMP_THIS(0x6F7CA0); }

// called by AITeam Attack Target Type and autoscan
	bool TryAutoTargetObject(
		eTargetFlags TargetFlags,
		int CanTargetWhatAmI,
		CellStruct *Coords,
		DWORD dwUnk1,
		DWORD *dwUnk2,
		int *ThreatPosed,
		DWORD dwUnk3)
			{ JMP_THIS(0x6F8960); }

	void Reactivate()
		{ JMP_THIS(0x70FBE0); }

	void Deactivate()
		{ JMP_THIS(0x70FC90); }

	//Constructor
	TechnoClass(HouseClass* pOwner) : RadioClass(false)
		{ JMP_THIS(0x6F2B40); }

protected:
	TechnoClass(bool) : RadioClass(false) { }
	TechnoClass() : RadioClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	FlashData Flashing;
	int                DeployingAnimStartFrame;
	bool               unknown_bool_FC;
	TimerStruct DeployingAnimTimer;
	DWORD              unknown_10C;
	int                unknown_int_110;
	PassengersClass Passengers;
	TechnoClass*       Transporter; // unit carrying me
	int                unknown_int_120;
	int                CurrentWeaponNumber; // for gattling
	int                unknown_int_128;
	AnimClass*         BehindAnim;
	AnimClass*         DeployAnim;
	bool               InAir;
	int                CurrentTurret;
	int                CurrentRanking; //see RANK definitons, only used for promotion detection
	DWORD              CurrentGattlingStage;
	DWORD              unknown_144;
	DWORD              unknown_148;
	HouseClass*        OwningPlayer2; // only set in ctor
	VeterancyStruct Veterancy;
	double             ArmorMultiplier;
	double             FirepowerMultiplier;
	TimerStruct IdleActionTimer; // MOO
	TimerStruct RadarFlashTimer;
	TimerStruct TargetingTimer; //Duration = 45 on init!
	TimerStruct IronCurtainTimer;
	TimerStruct IronTintTimer; // how often to alternate the effect color
	int                IronTintStage; // ^
	TimerStruct AirstrikeTimer;
	TimerStruct AirstrikeTintTimer; // tracks alternation of the effect color
	DWORD              AirstrikeTintStage; //  ^
	int                ForceShielded;	//0 or 1, NOT a bool - is this under ForceShield as opposed to IC?
	bool               Deactivated; //Robot Tanks without power for instance
	TechnoClass*       DrainTarget; // eg Disk -> PowerPlant, this points to PowerPlant
	TechnoClass*       DrainingMe;  // eg Disk -> PowerPlant, this points to Disk
	AnimClass*         DrainAnim;
	bool               Disguised;
	DWORD              DisguiseCreationFrame;
	TimerStruct InfantryBlinkTimer; // Rules->InfantryBlinkDisguiseTime , detects mirage firing per description
	TimerStruct DisguiseBlinkTimer; // disguise disruption timer
	bool               unknown_bool_1F8;
	TimerStruct ReloadTimer;
	DWORD              unknown_208;
	DWORD              unknown_20C;

	// WARNING! this is actually an index of HouseTypeClass es, but it's being changed to fix typical WW bugs.
	IndexBitfield<HouseClass *> DisplayProductionTo; // each bit corresponds to one player on the map, telling us whether that player has (1) or hasn't (0) spied this building, and the game should display what's being produced inside it to that player. The bits are arranged by player ID, i.e. bit 0 refers to house #0 in HouseClass::Array, 1 to 1, etc.; query like ((1 << somePlayer->ArrayIndex) & someFactory->DisplayProductionToHouses) != 0

	int                Group; //0-9, assigned by CTRL+Number, these kinds // also set by aimd TeamType->Group !
	TechnoClass*       FocusOnUnit; // when told to guard a unit or such
	HouseClass*        Owner;
	eCloakStates       CloakState;
	int                CloakingStage; // phase from [opaque] -> [fading] -> [transparent] , [General]CloakingStages= long
	bool               Cloaking;
	TimerStruct CloakTimer;
	int                CloakingSpeed;
	int                CloakingIncrementAmount; //defaults to 1
	TimerStruct CloakDelayTimer; // delay before cloaking again
	DWORD              unknown_24C;
	bool               unknown_bool_250;
	CoordStruct unknown_point3d_254;
	DWORD              unknown_260;
	DWORD              unknown_264;
	bool               GapSuperCharged; // GapGenerator, when SuperGapRadiusInCells != GapRadiusInCells, you can deploy the gap to boost radius
	bool               GeneratingGap; // is currently generating gap
	int                GapRadius;
	bool               BeingWarpedOut; // is being warped by CLEG
	bool               WarpingOut; // phasing in after chrono-jump
	bool               unknown_bool_272;
	BYTE               unused_273;
	TemporalClass*     TemporalImUsing; // CLEG attacking Power Plant : CLEG's this
	TemporalClass*     TemporalTargetingMe; 	// CLEG attacking Power Plant : PowerPlant's this
	bool               IsImmobilized; // by chrono aftereffects
	DWORD              unknown_280;
	int                ChronoLockRemaining; // countdown after chronosphere warps things around
	CoordStruct ChronoDestCoords; // teleport loco and chsphere set this
	AirstrikeClass*    Airstrike; //Boris
	bool               Berzerk;
	DWORD              BerzerkDurationLeft;
	DWORD              SprayOffsetIndex; // hardcoded array of xyz offsets for sprayattack, 0 - 7, see 6FE0AD
	bool               Uncrushable; // DeployedCrushable fiddles this, otherwise all 0

 // unless source is Pushy=
 // abs_Infantry source links with abs_Unit target and vice versa - can't attack others until current target flips
 // no checking whether source is Infantry, but no update for other types either
 // old Brute hack
	FootClass*         DirectRockerLinkedUnit;
	FootClass*         LocomotorTarget; // mag->LocoTarget = victim
	FootClass*         LocomotorSource; // victim->LocoSource = mag
	ObjectClass*       Target; //if attacking
	ObjectClass*       LastTarget;
	CaptureManagerClass* CaptureManager; //for Yuris
	TechnoClass*       MindControlledBy;
	bool               MindControlledByAUnit;
	AnimClass*         MindControlRingAnim;
	HouseClass*        MindControlledByHouse; //used for a TAction
	SpawnManagerClass* SpawnManager;
	TechnoClass*       SpawnOwner; // on DMISL , points to DRED and such
	SlaveManagerClass* SlaveManager;
	TechnoClass*       SlaveOwner; // on SLAV, points to YAREFN
	HouseClass*        OriginallyOwnedByHouse; //used for mind control

		//units point to the Building bunkering them, building points to Foot contained within
	TechnoClass*       BunkerLinkedItem;

	DWORD              unknown_2E8;
	TimerStruct DiskLaserTimer;
	DWORD              unknown_2F8;
	int                Ammo;
	int                Value; // set to actual cost when this gets queued in factory, updated only in building's 42C


	ParticleSystemClass* FireParticleSystem;
	ParticleSystemClass* SparkParticleSystem;
	ParticleSystemClass* NaturalParticleSystem;
	ParticleSystemClass* DamageParticleSystem;
	ParticleSystemClass* RailgunParticleSystem;
	ParticleSystemClass* unk1ParticleSystem;
	ParticleSystemClass* unk2ParticleSystem;
	ParticleSystemClass* FiringParticleSystem;

	WaveClass*         Wave; //Beams
	DWORD              unknown_328;
	DWORD              unknown_32C;
	DWORD              unknown_330;
	DWORD              unknown_334;
	int                HijackerInfantryType; // mutant hijacker

	OwnedTiberiumStruct Tiberium;
	DWORD unknown_34C;

	TransitionTimer UnloadTimer; // times the deploy, unload, etc. cycles

	FacingStruct BarrelFacing;
	FacingStruct Facing;
	FacingStruct TurretFacing;
	DWORD              unknown_3B8;
	TimerStruct TargetLaserTimer;
	short              unknown_short_3C8;
	WORD               unknown_3CA;
	bool               unknown_bool_3CC;
	bool               IsSinking;
	bool               WasSinkingAlready; // if(IsSinking && !WasSinkingAlready) { play SinkingSound; WasSinkingAlready = 1; }
	bool               unknown_bool_3CF;
	bool               unknown_bool_3D0;
	bool               HasBeenAttacked; // ReceiveDamage when not HouseClass_IsAlly
	bool               Cloakable;
	bool               IsPrimaryFactory; // doubleclicking a warfac/barracks sets it as primary
	bool               Spawned;
	bool               Produced;
	RecoilData TurretRecoil;
	RecoilData BarrelRecoil;
	bool               unknown_bool_418;
	bool               unknown_bool_419;
	bool               IsHumanControlled;
	bool               unknown_bool_41B;
	bool               unknown_bool_41C;
	bool               unknown_bool_41D;
	bool               unknown_bool_41E;
	bool               unknown_bool_41F;
	bool               unknown_bool_420;
	bool               RecruitableA; // these two are like Lenny and Carl, weird purpose and never seen separate
	bool               RecruitableB; // they're usually set on preplaced objects in maps
	bool               unknown_bool_423;
	bool               unknown_bool_424;
	bool               IsCrashing;
	bool               WasCrashingAlready;
	bool               unknown_bool_427;
	DWORD              unknown_428;
	HouseClass*        ChronoWarpedByHouse;
	bool               unknown_bool_430;
	bool               unknown_bool_431;
	bool               unknown_bool_432;
	DWORD              OldTeam; // AITeamClass * really, TODO: fix when defined
	bool               unknown_bool_438;
	bool               Absorbed; // in UnitAbsorb/InfantryAbsorb or smth, lousy memory
	bool               unknown_bool_43A;
	DWORD              unknown_43C;
	DynamicVectorClass<int> CurrentTargetThreatValues;
	DynamicVectorClass<AbstractClass*> CurrentTargets;

 // if DistributedFire=yes, this is used to determine which possible targets should be ignored in the latest threat scan
	DynamicVectorClass<AbstractClass*> AttackedTargets;

	AudioController Audio3;

	DWORD              unknown_49C;
	DWORD              unknown_4A0;

	AudioController Audio4;

	bool               unknown_bool_4B8;
	DWORD              unknown_4BC;

	AudioController Audio5;

	bool               unknown_bool_4D4;
	DWORD              unknown_4D8;

	AudioController Audio6;

	DWORD              QueuedVoiceIndex;
	DWORD              unknown_4F4;
	bool               unknown_bool_4F8;
	DWORD unknown_4FC;	//gets initialized with the current Frame, but this is NOT a TimerStruct!
	DWORD unknown_500;
	DWORD              EMPLockRemaining;
	DWORD              ThreatPosed; // calculated to include cargo etc
	DWORD              ShouldLoseTargetNow;
	DWORD              FiringRadBeam; // RadBeamClass *, TODO: fix when declared
	DWORD              PlanningToken; // PlanningTokenClass *, user waypoint voodoo, TODO: fix when declared
	ObjectTypeClass*   Disguise;
	HouseClass*        DisguisedAsHouse;
};

#endif
