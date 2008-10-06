/*
	Base class for buildable objects
*/

#ifndef TECHNO_H
#define TECHNO_H

#include <RadioClass.h>
#include <TechnoTypeClass.h>

//forward declarations
class AirstrikeClass;
class AnimClass;
class BuildingClass;
class CaptureManagerClass;
class CellClass;
class HouseClass;
class FootClass;
class InfantryTypeClass;
class ObjectTypeClass;
class ParticleSystemClass;
class SlaveManagerClass;
class SpawnManagerClass;
class TemporalClass;
class WaveClass;

#include <TransitionTimer.h>

//also see FACING definitions
struct FacingStruct
{
	WORD Facing1; //current facing?
	WORD unused_2;
	WORD Facing2; //??
	WORD unused_6;
	TimerStruct Timer; //rotation?
	WORD ROT; //Rate of Turn. INI Value * 256
	WORD unused_16;
};

struct VeterancyStruct
{
	float Veterancy;
	DWORD unknown_4;
};

class PassengersClass
{
public:
	int NumPassengers;
	FootClass* FirstPassenger;

	void AddPassenger(FootClass* pPassenger)
		JMP_THIS(0x4733A0);

	FootClass* GetFirstPassenger()
		{ return this->FirstPassenger; }

	FootClass* RemoveFirstPassenger()
		JMP_THIS(0x473430);

	int GetTotalSize()
		JMP_THIS(0x473460);

	int IndexOf(FootClass* candidate)
		JMP_THIS(0x473500);
};

struct FlashData
{
	int DurationRemaining;
	bool FlashingNow;

	bool Update()
		JMP_THIS(0x4CC770);
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
		JMP_THIS(0x70ED10);

	void Fire()
		JMP_THIS(0x70ECE0);
};

class TechnoClass : public RadioClass
{
public:
	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TechnoClass() RX;

	//TechnoClass
	virtual bool IsUnitFactory() R0;
	virtual bool IsCloakable() R0;
	virtual bool vt_entry_28C() R0;
	virtual bool vt_entry_290() R0;
	virtual bool SelfHealNow() R0;
	virtual bool IsVoxel() R0;
	virtual bool vt_entry_29C() R0;
	virtual bool ShouldBeCloaked() R0;
	virtual bool ShouldNotBeCloaked() R0;
	virtual FacingStruct* vt_entry_2A8(FacingStruct* pFacing) R0;
	virtual bool IsArmed() R0; // GetWeapon(primary) && GetWeapon(primary)->WeaponType
	virtual void vt_entry_2B0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5) RX;
	virtual double GetStoragePercentage() R0;
	virtual int GetPipFillLevel() R0;
	virtual int GetRefund() R0;
	virtual int GetThreatValue() R0;
	virtual bool vt_entry_2C4(DWORD dwUnk) R0;
	virtual DWORD vt_entry_2C8(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual bool vt_entry_2CC(DWORD dwUnk) R0;
	virtual int GetCrewCount() R0;
	virtual int GetAntiAirValue() R0;
	virtual int GetAntiArmorValue() R0;
	virtual int GetAntiInfantryValue() R0;
	virtual void vt_entry_2E0() RX;
	virtual DWORD SelectWeapon(ObjectClass *Target) R0;
	virtual int SelectNavalTargeting(ObjectClass *Target) R0;
	virtual DWORD vt_entry_2EC(DWORD dwUnk) R0;
	virtual int vt_entry_2F0() R0;
	virtual CellStruct* vt_entry_2F4() R0;
	virtual void vt_entry_2F8(DWORD dwUnk) RX;
	virtual DWORD vt_entry_2FC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual DWORD vt_entry_300(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_308(DWORD dwUnk) R0;
	virtual InfantryTypeClass* GetCrew() R0;
	virtual bool vt_entry_310() R0;
	virtual bool CanDeploySlashUnload() R0;
	virtual int GetROF(int nWeapon) R0;
	virtual int vt_entry_31C(int dwUnk) R0;
	virtual bool vt_entry_320() R0;
	virtual bool vt_entry_324(DWORD dwUnk) R0;
	virtual bool vt_entry_328() R0;
	virtual bool vt_entry_32C(DWORD dwUnk) R0;
	virtual bool IsEngineer() R0;
	virtual void vt_entry_334() RX;
	virtual DWORD vt_entry_338(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
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
	virtual bool vt_entry_378(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) R0;
	virtual bool IsUnderEMP() R0;
	virtual bool vt_entry_380() R0;
	virtual bool vt_entry_384() R0;
	virtual void vt_entry_388(DWORD dwUnk) RX;
	virtual int GetDefaultSpeed() R0;
	virtual void DecreaseAmmo() RX;
	virtual void AddPassenger(FootClass* pPassenger) RX;
	virtual bool CanDisguiseAs(ObjectClass *Target) R0;
	virtual bool TargetAndEstimateDamage(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_3A0() R0;
	virtual bool TriggersCellInset(ObjectClass *Target) R0;
	virtual bool vt_entry_3A8(DWORD dwUnk) R0;
	virtual DWORD vt_entry_3AC(DWORD dwUnk) R0;
	virtual DWORD vt_entry_3B0(DWORD dwUnk) R0;
	virtual DWORD vt_entry_3B4(DWORD dwUnk) R0;
	virtual void Destroyed(ObjectClass *Killer) = 0;
	virtual DWORD vt_entry_3BC(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual int vt_entry_3C0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) R0;
	virtual CellClass* SelectAutoTarget(eTargetFlags TargetFlags, int CurrentThreat, bool OnlyTargetHouseEnemy) R0;
	virtual void SetTarget(AbstractClass *Target) RX;
	virtual DWORD Fire(ObjectClass* pTarget, int nWeapon) R0;
	virtual DWORD vt_entry_3D0() R0;
	virtual void SetOwningHouse(HouseClass* pHouse, DWORD dwUnk) RX;
	virtual void vt_entry_3D8(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool Crash(DWORD dwUnk) R0;
	virtual bool IsAreaFire() R0;
	virtual int IsNotSprayAttack() R0;
	virtual int vt_entry_3E8() R0;
	virtual int IsNotSprayAttack2() R0;
	virtual WeaponStruct* GetDeployWeapon() R0;
	virtual WeaponStruct* GetTurretWeapon() R0;
	virtual WeaponStruct* GetWeapon(int nWeaponNumber) R0;
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
	virtual void vt_entry_438(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual DWORD vt_entry_43C(DWORD dwUnk) R0;
	virtual bool vt_entry_440(DWORD dwUnk) R0;

	//nooooooooooooooooooooooooooooooo (vader-style)
	//thought 666 is the number of the beast? in hex it's 444 D=
	virtual void vt_entry_444(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5,
		DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8, DWORD dwUnk9, DWORD dwUnk10) RX;
	virtual void vt_entry_448(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void DrawHealthBar(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
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
	virtual bool CanAttack() R0;
	virtual bool vt_entry_4C4() R0;
	virtual bool vt_entry_4C8() R0;
	virtual void vt_entry_4CC() RX;
	virtual bool vt_entry_4D0() R0;

	//non-virtual
	void ReloadNow()
		JMP_THIS(0x6FB080);

	bool ShouldSuppress(CellStruct *coords)
		JMP_THIS(0x6F79A0);

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
			JMP_THIS(0x6F7CA0);

// called by AITeam Attack Target Type and autoscan
	bool TryAutoTargetObject(
		eTargetFlags TargetFlags,
		int CanTargetWhatAmI,
		CellStruct *Coords,
		DWORD dwUnk1,
		DWORD *dwUnk2,
		int *ThreatPosed,
		DWORD dwUnk3)
			JMP_THIS(0x6F8960);

	//Constructor
	TechnoClass(HouseClass* pOwner = NULL) : RadioClass(false)
		JMP_THIS(0x6F2B40);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
public:
	PROPERTY_STRUCT(FlashData,   Flashing);
	PROPERTY(int,                DeployingAnimStartFrame);
	PROPERTY(bool,               unknown_bool_FC);
	PROPERTY_STRUCT(TimerStruct,        DeployingAnimTimer);
	PROPERTY(DWORD,              unknown_10C);
	PROPERTY(int,                unknown_int_110);
	PROPERTY_STRUCT(PassengersClass,		Passengers);
	PROPERTY(TechnoClass*,       Transporter); // unit carrying me
	PROPERTY(int,                unknown_int_120);
	PROPERTY(int,                CurrentWeaponNumber); // for gattling
	PROPERTY(int,                unknown_int_128);
	PROPERTY(AnimClass*,         BehindAnim);
	PROPERTY(AnimClass*,         DeployAnim);
	PROPERTY(bool,               InAir);
	PROPERTY(int,                CurrentTurret);
	PROPERTY(int,                CurrentRanking); //see RANK definitons, only used for promotion detection
	PROPERTY(DWORD,              CurrentGattlingStage);
	PROPERTY(DWORD,              unknown_144);
	PROPERTY(DWORD,              unknown_148);
	PROPERTY(HouseClass*,        OwningPlayer2); // only set in ctor
	PROPERTY_STRUCT(VeterancyStruct,    Veterancy);
	PROPERTY(double,             ArmorMultiplier);
	PROPERTY(double,             FirepowerMultiplier);
	PROPERTY_STRUCT(TimerStruct, IdleActionTimer); // MOO
	PROPERTY_STRUCT(TimerStruct, RadarFlashTimer);
	PROPERTY_STRUCT(TimerStruct, TargetingTimer); //Duration = 45 on init!
	PROPERTY_STRUCT(TimerStruct, IronCurtainTimer);
	PROPERTY_STRUCT(TimerStruct, IronTintTimer); // how often to alternate the effect color
	PROPERTY(int,                IronTintStage); // ^
	PROPERTY_STRUCT(TimerStruct, AirstrikeTimer);
	PROPERTY_STRUCT(TimerStruct, AirstrikeTintTimer); // tracks alternation of the effect color
	PROPERTY(DWORD,              AirstrikeTintStage); //  ^
	PROPERTY(int,                IronCurtainActive);	//0 or 1, NOT a bool
	PROPERTY(bool,               Deactivated); //Robot Tanks without power for instance
	PROPERTY(TechnoClass*,       DrainTarget); // eg Disk -> PowerPlant, this points to PowerPlant
	PROPERTY(TechnoClass*,       DrainingMe);  // eg Disk -> PowerPlant, this points to Disk
	PROPERTY(AnimClass*,         DrainAnim);
	PROPERTY(bool,               Disguised);
	PROPERTY(DWORD,              DisguiseCreationFrame);
	PROPERTY_STRUCT(TimerStruct, InfantryBlinkTimer); // Rules->InfantryBlinkDisguiseTime , detects mirage firing per description
	PROPERTY_STRUCT(TimerStruct, DisguiseBlinkTimer); // disguise disruption timer
	PROPERTY(bool,               unknown_bool_1F8);
	PROPERTY_STRUCT(TimerStruct, ReloadTimer);
	PROPERTY(DWORD,              unknown_208);
	PROPERTY(DWORD,              unknown_20C);
	PROPERTY(DWORD,              unknown_210);
	PROPERTY(int,                Group); //0-9, assigned by CTRL+Number, these kinds // also set by aimd TeamType->Group !
	PROPERTY(TechnoClass*,       FocusOnUnit); // when told to guard a unit or such
	PROPERTY(HouseClass*,        Owner);
	PROPERTY(eCloakStates,       CloakState);
	PROPERTY(int,                CloakingStage); // phase from [opaque] -> [fading] -> [transparent] , [General]CloakingStages= long
	PROPERTY(bool,               Cloaking);
	PROPERTY_STRUCT(TimerStruct, CloakTimer);
	PROPERTY(int,                CloakingSpeed);
	PROPERTY(int,                CloakingIncrementAmount); //defaults to 1
	PROPERTY_STRUCT(TimerStruct, CloakDelayTimer); // delay before cloaking again
	PROPERTY(DWORD,              unknown_24C);
	PROPERTY(bool,               unknown_bool_250);
	PROPERTY_STRUCT(CoordStruct, unknown_point3d_254);
	PROPERTY(DWORD,              unknown_260);
	PROPERTY(DWORD,              unknown_264);
	PROPERTY(bool,               GapSuperCharged); // GapGenerator, when SuperGapRadiusInCells != GapRadiusInCells, you can deploy the gap to boost radius
	PROPERTY(bool,               GeneratingGap); // is currently generating gap
	PROPERTY(int,                GapRadius);
	PROPERTY(bool,               BeingWarpedOut); // is being warped by CLEG
	PROPERTY(bool,               WarpingOut); // phasing in after chrono-jump
	PROPERTY(bool,               unknown_bool_272);
	PROPERTY(BYTE,               unused_273);
	PROPERTY(TemporalClass*,     TemporalImUsing); // CLEG attacking Power Plant : CLEG's this 
	PROPERTY(TemporalClass*,     TemporalTargetingMe); 	// CLEG attacking Power Plant : PowerPlant's this 
	PROPERTY(bool,               IsImmobilized); // by chrono aftereffects
	PROPERTY(DWORD,              unknown_280);
	PROPERTY(int,                ChronoLockRemaining); // countdown after chronosphere warps things around
	PROPERTY_STRUCT(CoordStruct, unknown_point3d_288);
	PROPERTY(AirstrikeClass*,    Airstrike); //Boris
	PROPERTY(bool,               Berzerk);
	PROPERTY(DWORD,              BerzerkDurationLeft);
	PROPERTY(DWORD,              unknown_2A0);
	PROPERTY(DWORD,              unknown_2A4);
	PROPERTY(DWORD,              unknown_2A8);
	PROPERTY(FootClass*,         LocomotorTarget); // mag->LocoTarget = victim
	PROPERTY(FootClass*,         LocomotorSource); // victim->LocoSource = mag
	PROPERTY(ObjectClass*,       Target); //if attacking
	PROPERTY(ObjectClass*,       LastTarget);
	PROPERTY(CaptureManagerClass*, CaptureManager); //for Yuris
	PROPERTY(TechnoClass*,       MindControlledBy);
	PROPERTY(bool,               MindControlledByAUnit);
	PROPERTY(AnimClass*,         MindControlRingAnim);
	PROPERTY(HouseClass*,        MindControlledByHouse); //used for a TAction
	PROPERTY(SpawnManagerClass*, SpawnManager);
	PROPERTY(TechnoClass*,       SpawnOwner); // on DMISL , points to DRED and such
	PROPERTY(SlaveManagerClass*, SlaveManager);
	PROPERTY(TechnoClass*,       SlaveOwner); // on SLAV, points to YAREFN
	PROPERTY(HouseClass*,        OriginallyOwnedByHouse); //used for mind control

		//units point to the Building bunkering them, building points to Foot contained within
	PROPERTY(TechnoClass*,       BunkerLinkedItem);

	PROPERTY(DWORD,              unknown_2E8);
	PROPERTY_STRUCT(TimerStruct, DiskLaserTimer);
	PROPERTY(DWORD,              unknown_2F8);
	PROPERTY(int,                Ammo);
	PROPERTY(int,                Value); // set to actual cost when this gets queued in factory, updated only in building's 42C

	
	PROPERTY(ParticleSystemClass*, FireParticleSystem);
	PROPERTY(ParticleSystemClass*, SparkParticleSystem);
	PROPERTY(ParticleSystemClass*, NaturalParticleSystem);
	PROPERTY(ParticleSystemClass*, DamageParticleSystem);
	PROPERTY(ParticleSystemClass*, RailgunParticleSystem);
	PROPERTY(ParticleSystemClass*, unk1ParticleSystem);
	PROPERTY(ParticleSystemClass*, unk2ParticleSystem);
	PROPERTY(ParticleSystemClass*, FiringParticleSystem);

	PROPERTY(WaveClass*,         Wave); //Beams
	PROPERTY(DWORD,              unknown_328);
	PROPERTY(DWORD,              unknown_32C);
	PROPERTY(DWORD,              unknown_330);
	PROPERTY(DWORD,              unknown_334);
	PROPERTY(InfantryTypeClass *, HijackedByInfantry); // mutant hijacker

	PROPERTY_STRUCT(OwnedTiberiumStruct, Tiberium);
	PROPERTY(DWORD,					unknown_34C);

	PROPERTY_STRUCT(TransitionTimer, UnloadTimer); // times the deploy, unload, etc. cycles

public:
	PROPERTY_STRUCT(FacingStruct,       BarrelFacing);
	PROPERTY_STRUCT(FacingStruct,       Facing);
	PROPERTY_STRUCT(FacingStruct,       TurretFacing);
	PROPERTY(DWORD,              unknown_3B8);
	PROPERTY_STRUCT(TimerStruct,        TargetLaserTimer);
	PROPERTY(short,              unknown_short_3C8);
	PROPERTY(WORD,               unknown_3CA);
	PROPERTY(bool,               unknown_bool_3CC);
	PROPERTY(bool,               unknown_bool_3CD);
	PROPERTY(bool,               unknown_bool_3CE);
	PROPERTY(bool,               unknown_bool_3CF);
	PROPERTY(bool,               unknown_bool_3D0);
	PROPERTY(bool,               HasBeenAttacked); // ReceiveDamage when not HouseClass_IsAlly
	PROPERTY(bool,               Cloakable);
	PROPERTY(bool,               IsPrimaryFactory); // doubleclicking a warfac/barracks sets it as primary
	PROPERTY(bool,               Spawned);
	PROPERTY(bool,               Produced);
	PROPERTY_STRUCT(RecoilData,  TurretRecoil);
	PROPERTY_STRUCT(RecoilData,  BarrelRecoil);
	PROPERTY(bool,               unknown_bool_418);
	PROPERTY(bool,               unknown_bool_419);
	PROPERTY(bool,               IsHumanControlled);
	PROPERTY(bool,               unknown_bool_41B);
	PROPERTY(bool,               unknown_bool_41C);
	PROPERTY(bool,               unknown_bool_41D);
	PROPERTY(bool,               unknown_bool_41E);
	PROPERTY(bool,               unknown_bool_41F);
	PROPERTY(bool,               unknown_bool_420);
	PROPERTY(bool,               RecruitableA); // these two are like Lenny and Carl, weird purpose and never seen separate
	PROPERTY(bool,               RecruitableB); // they're usually set on preplaced objects in maps
	PROPERTY(bool,               unknown_bool_423);
	PROPERTY(bool,               unknown_bool_424);
	PROPERTY(bool,               unknown_bool_425);
	PROPERTY(bool,               unknown_bool_426);
	PROPERTY(bool,               unknown_bool_427);
	PROPERTY(DWORD,              unknown_428);
	PROPERTY(HouseClass*,        ChronoWarpedByHouse);
	PROPERTY(bool,               unknown_bool_430);
	PROPERTY(bool,               unknown_bool_431);
	PROPERTY(bool,               unknown_bool_432);
	PROPERTY(DWORD,              OldTeam); // AITeamClass * really, TODO: fix when defined
	PROPERTY(bool,               unknown_bool_438);
	PROPERTY(bool,               Absorbed); // in UnitAbsorb/InfantryAbsorb or smth, lousy memory
	PROPERTY(bool,               unknown_bool_43A);
	PROPERTY(DWORD,              unknown_43C);
	PROPERTY_STRUCT(DynamicVectorClass<int>, CurrentTargetThreatValues);
	PROPERTY_STRUCT(DynamicVectorClass<AbstractClass*>, CurrentTargets);

 // if DistributedFire=yes, this is used to determine which possible targets should be ignored in the latest threat scan
	PROPERTY_STRUCT(DynamicVectorClass<AbstractClass*>, AttackedTargets);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio3);

	PROPERTY(DWORD,              unknown_49C);
	PROPERTY(DWORD,              unknown_4A0);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio4);

	PROPERTY(bool,               unknown_bool_4B8);
	PROPERTY(DWORD,              unknown_4BC);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio5);

	PROPERTY(bool,               unknown_bool_4D4);
	PROPERTY(DWORD,              unknown_4D8);

	PROPERTY_STRUCT(Unsorted::AudioController, Audio6);

	PROPERTY(DWORD,              QueuedVoiceIndex);
	PROPERTY(DWORD,              unknown_4F4);
	PROPERTY(bool,               unknown_bool_4F8);
	PROPERTY(DWORD,				unknown_4FC);	//gets initialized with the current Frame, but this is NOT a TimerStruct!
	PROPERTY(DWORD,				unknown_500);
	PROPERTY(DWORD,              EMPLockRemaining);
	PROPERTY(DWORD,              ThreatPosed); // calculated to include cargo etc
	PROPERTY(DWORD,              ShouldLoseTargetNow);
	PROPERTY(DWORD,              FiringRadBeam); // RadBeamClass *, TODO: fix when declared
	PROPERTY(DWORD,              PlanningToken); // PlanningTokenClass *, user waypoint voodoo, TODO: fix when declared
	PROPERTY(ObjectTypeClass*,   Disguise);
	PROPERTY(HouseClass*,        DisguisedAsHouse);
};

#endif
