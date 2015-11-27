/*
	Base class for buildable objects
*/

#pragma once

#include <RadioClass.h>
#include <RadBeam.h>
#include <TechnoTypeClass.h>
#include <CaptureManagerClass.h>
#include <SlaveManagerClass.h>
#include <TeamClass.h>
#include <TemporalClass.h>
#include <LaserDrawClass.h>
#include <Helpers/Template.h>
#include <ProgressTimer.h>
#include <PlanningTokenClass.h>

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

struct NetworkEvent;

#include <TransitionTimer.h>

struct VeterancyStruct
{
	VeterancyStruct() = default;

	explicit VeterancyStruct(double value) noexcept {
		this->Add(value);
	}

	void Add(int ownerCost, int victimCost) noexcept {
		this->Add(static_cast<double>(victimCost)
			/ (ownerCost * RulesClass::Instance->VeteranRatio));
	}

	void Add(double value) noexcept {
		auto val = this->Veterancy + value;

		if(val > RulesClass::Instance->VeteranCap) {
			val = RulesClass::Instance->VeteranCap;
		}

		this->Veterancy = static_cast<float>(val);
	}

	Rank GetRemainingLevel() const noexcept {
		if(this->Veterancy >= 2.0f) {
			return Rank::Elite;
		}

		if(this->Veterancy >= 1.0f) {
			return Rank::Veteran;
		}

		return Rank::Rookie;
	}

	bool IsNegative() const noexcept {
		return this->Veterancy < 0.0f;
	}

	bool IsRookie() const noexcept {
		return this->Veterancy >= 0.0f && this->Veterancy < 1.0f;
	}

	bool IsVeteran() const noexcept {
		return this->Veterancy >= 1.0f && this->Veterancy < 2.0f;
	}

	bool IsElite() const noexcept {
		return this->Veterancy >= 2.0f;
	}

	void Reset() noexcept {
		this->Veterancy = 0.0f;
	}

	void SetRookie(bool notReally = true) noexcept {
		this->Veterancy = notReally ? -0.25f : 0.0f;
	}

	void SetVeteran(bool yesReally = true) noexcept {
		this->Veterancy = yesReally ? 1.0f : 0.0f;
	}

	void SetElite(bool yesReally = true) noexcept {
		this->Veterancy = yesReally ? 2.0f : 0.0f;
	}

	float Veterancy{ 0.0f };
};

class PassengersClass
{
public:
	int NumPassengers;
	FootClass* FirstPassenger;

	void AddPassenger(FootClass* pPassenger)
		{ JMP_THIS(0x4733A0); }

	FootClass* GetFirstPassenger() const
		{ return this->FirstPassenger; }

	FootClass* RemoveFirstPassenger()
		{ JMP_THIS(0x473430); }

	int GetTotalSize() const
		{ JMP_THIS(0x473460); }

	int IndexOf(FootClass* candidate) const
		{ JMP_THIS(0x473500); }

	PassengersClass() : NumPassengers(0), FirstPassenger(nullptr) {};

	~PassengersClass() { };
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
	enum class RecoilState : unsigned int {
		Inactive = 0,
		Compressing = 1,
		Holding = 2,
		Recovering = 3,
	};

	TurretControl Turret;
	float TravelPerFrame;
	float TravelSoFar;
	RecoilState State;
	int TravelFramesLeft;

	void Update()
		{ JMP_THIS(0x70ED10); }

	void Fire()
		{ JMP_THIS(0x70ECE0); }
};

class NOVTABLE TechnoClass : public RadioClass
{
public:
	static const auto AbsDerivateID = AbstractFlags::Techno;

	static DynamicVectorClass<TechnoClass *>* const Array; // HAX to instantiate

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TechnoClass() RX;

	//TechnoClass
	virtual bool IsUnitFactory() const R0;
	virtual bool IsCloakable() const R0;
	virtual bool CanScatter() const R0;
	virtual bool BelongsToATeam() const R0;
	virtual bool ShouldSelfHealOneStep() const R0;
	virtual bool IsVoxel() const R0;
	virtual bool vt_entry_29C() R0;
	virtual bool ShouldBeCloaked() const R0;
	virtual bool ShouldNotBeCloaked() const R0;
	virtual DirStruct* GetFacing(DirStruct* pBuffer) const R0;
	virtual bool IsArmed() const R0; // GetWeapon(primary) && GetWeapon(primary)->WeaponType
	virtual void vt_entry_2B0() const RX;
	virtual double GetStoragePercentage() const R0;
	virtual int GetPipFillLevel() const R0;
	virtual int GetRefund() const R0;
	virtual int GetThreatValue() const R0;
	virtual bool vt_entry_2C4(DWORD dwUnk) R0;
	virtual DWORD vt_entry_2C8(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual bool vt_entry_2CC(DWORD dwUnk) R0;
	virtual int GetCrewCount() const R0;
	virtual int GetAntiAirValue() const R0;
	virtual int GetAntiArmorValue() const R0;
	virtual int GetAntiInfantryValue() const R0;
	virtual void GotHijacked() RX;
	virtual int SelectWeapon(AbstractClass *pTarget) const R0;
	virtual int SelectNavalTargeting(AbstractClass *pTarget) const R0;
	virtual int GetZAdjustment() const R0;
	virtual ZGradient GetZGradient() const RT(ZGradient);
	virtual CellStruct* GetSomeCellStruct() const R0;
	virtual void SetSomeCellStruct(CellStruct* Buffer) RX;
	virtual CellStruct* vt_entry_2FC(CellStruct* Buffer, DWORD dwUnk2, DWORD dwUnk3) const R0;
	virtual CoordStruct * vt_entry_300(CoordStruct * Buffer, DWORD dwUnk2) const R0;
	virtual DWORD vt_entry_304(DWORD dwUnk, DWORD dwUnk2) const R0;
	virtual DirStruct* GetRealFacing(DirStruct* pBuffer) const R0;
	virtual InfantryTypeClass* GetCrew() const R0;
	virtual bool vt_entry_310() const R0;
	virtual bool CanDeploySlashUnload() const R0;
	virtual int GetROF(int nWeapon) const R0;
	virtual int GetGuardRange(int dwUnk) const R0;
	virtual bool vt_entry_320() const R0;
	virtual bool IsRadarVisible(int* pOutDetection) const R0; // out value will be set to 1 if unit is cloaked and 2 if it is subterranean, otherwise it's unchanged
	virtual bool IsSensorVisibleToPlayer() const R0;
	virtual bool IsSensorVisibleToHouse(HouseClass *House) const R0;
	virtual bool IsEngineer() const R0;
	virtual void ProceedToNextPlanningWaypoint() RX;
	virtual DWORD ScanForTiberium(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) const R0;
	virtual bool EnterGrinder() R0;
	virtual bool EnterBioReactor() R0;
	virtual bool EnterTankBunker() R0;
	virtual bool EnterBattleBunker() R0;
	virtual bool GarrisonStructure() R0;
	virtual bool IsPowerOnline() const R0;
	virtual void QueueVoice(int idxVoc) RX;
	virtual int VoiceEnter() R0;
	virtual int VoiceHarvest() R0;
	virtual int VoiceSelect() R0;
	virtual int VoiceCapture() R0;
	virtual int VoiceMove() R0;
	virtual int VoiceDeploy() R0;
	virtual int VoiceAttack(ObjectClass *pTarget) R0;
	virtual bool ClickedEvent(NetworkEvents event) R0;

	// depending on the mission you click, cells/Target are not always needed
	virtual bool ClickedMission(Mission Mission, ObjectClass *pTarget, CellClass * TargetCell, CellClass *NearestTargetCellICanEnter) R0;
	virtual bool IsUnderEMP() const R0;
	virtual bool IsParalyzed() const R0;
	virtual bool CanCheer() const R0;
	virtual void Cheer(bool Force) RX;
	virtual int GetDefaultSpeed() const R0;
	virtual void DecreaseAmmo() RX;
	virtual void AddPassenger(FootClass* pPassenger) RX;
	virtual bool CanDisguiseAs(AbstractClass*pTarget) const R0;
	virtual bool TargetAndEstimateDamage(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual DWORD vt_entry_3A0() R0;
	virtual bool TriggersCellInset(AbstractClass *pTarget) R0;
	virtual bool IsCloseEnough(AbstractClass *pTarget, int idxWeapon) const R0;
	virtual bool IsCloseEnoughToAttack(AbstractClass *pTarget) const R0;
	virtual bool IsCloseEnoughToAttackCoords(const CoordStruct& Coords) const R0;
	virtual DWORD vt_entry_3B4(DWORD dwUnk) const R0;
	virtual void Destroyed(ObjectClass *Killer) = 0;
	virtual FireError GetFireErrorWithoutRange(AbstractClass *pTarget, int nWeaponIndex) const RT(FireError);
	virtual FireError GetFireError(AbstractClass *pTarget, int nWeaponIndex, bool ignoreRange) const RT(FireError);
	virtual CellClass* SelectAutoTarget(TargetFlags TargetFlags, int CurrentThreat, bool OnlyTargetHouseEnemy) R0;
	virtual void SetTarget(AbstractClass *pTarget) RX;
	virtual BulletClass* Fire(AbstractClass* pTarget, int nWeaponIndex) R0;
	virtual void Guard() RX; // clears target and destination and puts in guard mission
	virtual bool SetOwningHouse(HouseClass* pHouse, bool announce = true) R0;
	virtual void vt_entry_3D8(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool Crash(ObjectClass *Killer) R0;
	virtual bool IsAreaFire() const R0;
	virtual int IsNotSprayAttack() const R0;
	virtual int vt_entry_3E8() R0;
	virtual int IsNotSprayAttack2() const R0;
	virtual WeaponStruct* GetDeployWeapon() const R0;
	virtual WeaponStruct* GetTurretWeapon() const R0;
	virtual WeaponStruct* GetWeapon(int nWeaponIndex) const R0;
	virtual bool HasTurret() const R0;
	virtual bool CanOccupyFire() const R0;
	virtual int GetOccupyRangeBonus() const R0;
	virtual int GetOccupantCount() const R0;
	virtual void OnFinishRepair() RX;
	virtual void UpdateCloak(bool bUnk = 1) RX;
	virtual void CreateGap() RX;
	virtual void DestroyGap() RX;
	virtual void vt_entry_41C() RX;
	virtual void Sensed() RX;
	virtual void Reload() RX;
	virtual void vt_entry_428() RX;
	virtual CoordStruct* GetTargetCoords(CoordStruct* pCrd) const R0;
	virtual bool IsNotWarpingIn() const R0;
	virtual bool vt_entry_434(DWORD dwUnk) const R0;
	virtual void DrawActionLines(bool Force, DWORD dwUnk2) RX;
	virtual DWORD GetDisguiseFlags(DWORD existingFlags) const R0;
	virtual bool IsClearlyVisibleTo(HouseClass *House) const R0; // can House see right through my disguise?

	//nooooooooooooooooooooooooooooooo (vader-style)
	//thought 666 is the number of the beast? in hex it's 444 D=
	virtual void vt_entry_444(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5,
		DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8, DWORD dwUnk9, DWORD dwUnk10) RX;
	virtual void vt_entry_448(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void DrawHealthBar(Point2D *pLocation, RectangleStruct *pBounds, bool bUnk3) const RX;
	virtual void DrawPipScalePips(Point2D *pLocation, Point2D *pOriginalLocation, RectangleStruct *pBounds) const RX;
	virtual void DrawVeterancyPips(Point2D *pLocation, RectangleStruct *pBounds) const RX;
	virtual void DrawExtraInfo(Point2D *pLocation, Point2D *pOriginalLocation, RectangleStruct *pBounds) const RX;
	virtual void Uncloak(bool bPlaySound) RX;
	virtual void Cloak(bool bPlaySound) RX;
	virtual DWORD vt_entry_464(DWORD dwUnk) const R0;
	virtual void UpdateRefinerySmokeSystems() RX;
	virtual DWORD DisguiseAs(AbstractClass* pTarget) R0;
	virtual void ClearDisguise() RX;
	virtual bool IsItTimeForIdleActionYet() const R0;
	virtual bool UpdateIdleAction() R0;
	virtual void vt_entry_47C(DWORD dwUnk) RX;
	virtual void SetDestination(AbstractClass* pDest, bool bUnk) RX;
	virtual bool vt_entry_484(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual void UpdateSight(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5) RX;
	virtual void vt_entry_48C(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual void vt_entry_490(DWORD dwUnk, DWORD dwUnk2) = 0; //pure virtual
	virtual void RadarTrackingStart() RX;
	virtual void RadarTrackingStop() RX;
	virtual void RadarTrackingFlash() RX;
	virtual void RadarTrackingUpdate(bool bUnk) RX;
	virtual void vt_entry_4A4(DWORD dwUnk) RX;
	virtual void vt_entry_4A8() RX;
	virtual bool vt_entry_4AC() const R0;
	virtual bool vt_entry_4B0() const R0;
	virtual int vt_entry_4B4() const R0;
	virtual CoordStruct* vt_entry_4B8(CoordStruct* pCrd) R0;
	virtual DWORD vt_entry_4BC() R0;
	virtual bool CanAttackOnTheMove() const R0;
	virtual bool vt_entry_4C4() const R0;
	virtual bool vt_entry_4C8() R0;
	virtual void vt_entry_4CC() RX;
	virtual bool vt_entry_4D0() R0;

	//non-virtual

	// (re-)starts the reload timer
	void StartReloading()
		{ JMP_THIS(0x6FB080); }

	bool ShouldSuppress(CellStruct *coords) const
		{ JMP_THIS(0x6F79A0); }

	// smooth operator
	const char* get_ID() const {
		auto const pType = this->GetType();
		return pType ? pType->get_ID() : nullptr;
	}

	bool IsMindControlled() const
		{ JMP_THIS(0x7105E0); }

	bool CanBePermaMindControlled() const
		{ JMP_THIS(0x53C450); }

	LaserDrawClass* CreateLaser(ObjectClass *pTarget, int idxWeapon, WeaponTypeClass *pWeapon, const CoordStruct &Coords)
		{ JMP_THIS(0x6FD210); }

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
		TargetFlags targetFlags,
		int canTargetWhatAmI,
		int wantedDistance,
		TechnoClass* pTarget,
		int* pThreatPosed,
		DWORD dwUnk,
		CoordStruct* pSourceCoords) const
			{ JMP_THIS(0x6F7CA0); }

// called by AITeam Attack Target Type and autoscan
	bool TryAutoTargetObject(
		TargetFlags targetFlags,
		int canTargetWhatAmI,
		CellStruct* pCoords,
		DWORD dwUnk1,
		DWORD* dwUnk2,
		int* pThreatPosed,
		DWORD dwUnk3)
			{ JMP_THIS(0x6F8960); }

	void Reactivate()
		{ JMP_THIS(0x70FBE0); }

	void Deactivate()
		{ JMP_THIS(0x70FC90); }


	// this should be the transport, but it's unused
	// marks passenger as "InOpenTopped" for targeting, range scanning and other purposes
	void EnteredOpenTopped(TechnoClass* pWho)
		{ JMP_THIS(0x710470); }

	// this should be the transport, but it's unused
	// reverses the above
	void ExitedOpenTopped(TechnoClass* pWho)
		{ JMP_THIS(0x7104A0); }

	// called when the source unit dies - passengers are about to get kicked out, this basically calls ->ExitedOpenTransport on each passenger
	void MarkPassengersAsExited()
		{ JMP_THIS(0x7104C0); }

	// for gattlings
	void SetCurrentWeaponStage(int idx)
		{ JMP_THIS(0x70DDD0); }

	void SetFocus(AbstractClass* pFocus)
		{ JMP_THIS(0x70C610); }

	int sub_70DE00(int State)
		{ JMP_THIS(0x70DE00); }

	int __fastcall ClearPlanningTokens(NetworkEvent* pEvent)
		{ JMP_STD(0x6386E0); }

	void SetTargetForPassengers(AbstractClass* pTarget)
		{ JMP_THIS(0x710550); }

	// returns the house that created this object (factoring in Mind Control)
	HouseClass * GetOriginalOwner()
		{ JMP_THIS(0x70F820); }

	void FireDeathWeapon(int additionalDamage)
		{ JMP_THIS(0x70D690); }

	bool HasAbility(Ability ability) const
		{ JMP_THIS(0x70D0D0); }

	int GetIonCannonValue(AIDifficulty difficulty) const;

	int GetIonCannonValue(AIDifficulty difficulty, int maxHealth) const {
		// what TS does
		if(maxHealth > 0 && this->Health > maxHealth) {
			return (this->WhatAmI() == AbstractType::Building) ? 3 : 1;
		}

		return this->GetIonCannonValue(difficulty);
	}

	DirStruct GetFacing() const {
		DirStruct ret;
		this->GetFacing(&ret);
		return ret;
	}

	DirStruct GetRealFacing() const {
		DirStruct ret;
		this->GetRealFacing(&ret);
		return ret;
	}

	//Constructor
	TechnoClass(HouseClass* pOwner) noexcept
		: TechnoClass(noinit_t())
	{ JMP_THIS(0x6F2B40); }

protected:
	explicit __forceinline TechnoClass(noinit_t) noexcept
		: RadioClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	FlashData        Flashing;
	ProgressTimer    Animation; // how the unit animates
	PassengersClass  Passengers;
	TechnoClass*     Transporter; // unit carrying me
	int              unknown_int_120;
	int              CurrentTurretNumber; // for IFV/gattling/charge turrets
	int              unknown_int_128;
	AnimClass*       BehindAnim;
	AnimClass*       DeployAnim;
	bool             InAir;
	int              CurrentWeaponNumber; // for IFV/gattling
	Rank             CurrentRanking; // only used for promotion detection
	int              CurrentGattlingStage;
	int              GattlingValue; // sum of RateUps and RateDowns
	DWORD            unknown_148;
	HouseClass*      InitialOwner; // only set in ctor
	VeterancyStruct  Veterancy;
	PROTECTED_PROPERTY(DWORD, align_154);
	double           ArmorMultiplier;
	double           FirepowerMultiplier;
	TimerStruct      IdleActionTimer; // MOO
	TimerStruct      RadarFlashTimer;
	TimerStruct      TargetingTimer; //Duration = 45 on init!
	TimerStruct      IronCurtainTimer;
	TimerStruct      IronTintTimer; // how often to alternate the effect color
	int              IronTintStage; // ^
	TimerStruct      AirstrikeTimer;
	TimerStruct      AirstrikeTintTimer; // tracks alternation of the effect color
	DWORD            AirstrikeTintStage; //  ^
	int              ForceShielded;	//0 or 1, NOT a bool - is this under ForceShield as opposed to IC?
	bool             Deactivated; //Robot Tanks without power for instance
	TechnoClass*     DrainTarget; // eg Disk -> PowerPlant, this points to PowerPlant
	TechnoClass*     DrainingMe;  // eg Disk -> PowerPlant, this points to Disk
	AnimClass*       DrainAnim;
	bool             Disguised;
	DWORD            DisguiseCreationFrame;
	TimerStruct      InfantryBlinkTimer; // Rules->InfantryBlinkDisguiseTime , detects mirage firing per description
	TimerStruct      DisguiseBlinkTimer; // disguise disruption timer
	bool             unknown_bool_1F8;
	TimerStruct      ReloadTimer;
	DWORD            unknown_208;
	DWORD            unknown_20C;

	// WARNING! this is actually an index of HouseTypeClass es, but it's being changed to fix typical WW bugs.
	IndexBitfield<HouseClass *> DisplayProductionTo; // each bit corresponds to one player on the map, telling us whether that player has (1) or hasn't (0) spied this building, and the game should display what's being produced inside it to that player. The bits are arranged by player ID, i.e. bit 0 refers to house #0 in HouseClass::Array, 1 to 1, etc.; query like ((1 << somePlayer->ArrayIndex) & someFactory->DisplayProductionToHouses) != 0

	int              Group; //0-9, assigned by CTRL+Number, these kinds // also set by aimd TeamType->Group !
	AbstractClass*   Focus; // when told to guard a unit or such; distinguish undeploy and selling
	HouseClass*      Owner;
	CloakState       CloakState;
	ProgressTimer    CloakProgress; // phase from [opaque] -> [fading] -> [transparent] , [General]CloakingStages= long
	TimerStruct      CloakDelayTimer; // delay before cloaking again
	float            WarpFactor; // don't ask! set to 0 in CTOR, never modified, only used as ((this->Fetch_ID) + this->WarpFactor) % 400 for something in cloak ripple
	bool             unknown_bool_250;
	CoordStruct      LastSightCoords;
	int              LastSightRange;
	int              LastSightHeight;
	bool             GapSuperCharged; // GapGenerator, when SuperGapRadiusInCells != GapRadiusInCells, you can deploy the gap to boost radius
	bool             GeneratingGap; // is currently generating gap
	int              GapRadius;
	bool             BeingWarpedOut; // is being warped by CLEG
	bool             WarpingOut; // phasing in after chrono-jump
	bool             unknown_bool_272;
	BYTE             unused_273;
	TemporalClass*   TemporalImUsing; // CLEG attacking Power Plant : CLEG's this
	TemporalClass*   TemporalTargetingMe; 	// CLEG attacking Power Plant : PowerPlant's this
	bool             IsImmobilized; // by chrono aftereffects
	DWORD            unknown_280;
	int              ChronoLockRemaining; // countdown after chronosphere warps things around
	CoordStruct      ChronoDestCoords; // teleport loco and chsphere set this
	AirstrikeClass*  Airstrike; //Boris
	bool             Berzerk;
	DWORD            BerzerkDurationLeft;
	DWORD            SprayOffsetIndex; // hardcoded array of xyz offsets for sprayattack, 0 - 7, see 6FE0AD
	bool             Uncrushable; // DeployedCrushable fiddles this, otherwise all 0

 // unless source is Pushy=
 // abs_Infantry source links with abs_Unit target and vice versa - can't attack others until current target flips
 // no checking whether source is Infantry, but no update for other types either
 // old Brute hack
	FootClass*       DirectRockerLinkedUnit;
	FootClass*       LocomotorTarget; // mag->LocoTarget = victim
	FootClass*       LocomotorSource; // victim->LocoSource = mag
	AbstractClass*   Target; //if attacking
	AbstractClass*   LastTarget;
	CaptureManagerClass* CaptureManager; //for Yuris
	TechnoClass*     MindControlledBy;
	bool             MindControlledByAUnit;
	AnimClass*       MindControlRingAnim;
	HouseClass*      MindControlledByHouse; //used for a TAction
	SpawnManagerClass* SpawnManager;
	TechnoClass*     SpawnOwner; // on DMISL , points to DRED and such
	SlaveManagerClass* SlaveManager;
	TechnoClass*     SlaveOwner; // on SLAV, points to YAREFN
	HouseClass*      OriginallyOwnedByHouse; //used for mind control

		//units point to the Building bunkering them, building points to Foot contained within
	TechnoClass*     BunkerLinkedItem;

	float            PitchAngle; // not exactly, and it doesn't affect the drawing, only internal state of a dropship
	TimerStruct      DiskLaserTimer;
	DWORD            unknown_2F8;
	int              Ammo;
	int              Value; // set to actual cost when this gets queued in factory, updated only in building's 42C


	ParticleSystemClass* FireParticleSystem;
	ParticleSystemClass* SparkParticleSystem;
	ParticleSystemClass* NaturalParticleSystem;
	ParticleSystemClass* DamageParticleSystem;
	ParticleSystemClass* RailgunParticleSystem;
	ParticleSystemClass* unk1ParticleSystem;
	ParticleSystemClass* unk2ParticleSystem;
	ParticleSystemClass* FiringParticleSystem;

	WaveClass*       Wave; //Beams


	// rocking effect
	float            AngleRotatedSideways; // in this frame, in radians - if abs() exceeds pi/2, it dies
	float            AngleRotatedForwards; // same

	// set these and leave the previous two alone!
	// if these are set, the unit will roll up to pi/4, by this step each frame, and balance back
	float            RockingSidewaysPerFrame; // left to right - positive pushes left side up
	float            RockingForwardsPerFrame; // back to front - positive pushes ass up

	int              HijackerInfantryType; // mutant hijacker

	OwnedTiberiumStruct Tiberium;
	DWORD            unknown_34C;

	TransitionTimer  UnloadTimer; // times the deploy, unload, etc. cycles

	FacingStruct     BarrelFacing;
	FacingStruct     Facing;
	FacingStruct     TurretFacing;
	int              CurrentBurstIndex;
	TimerStruct      TargetLaserTimer;
	short            unknown_short_3C8;
	WORD             unknown_3CA;
	bool             CountedAsOwned; // is this techno contained in OwningPlayer->Owned... counts?
	bool             IsSinking;
	bool             WasSinkingAlready; // if(IsSinking && !WasSinkingAlready) { play SinkingSound; WasSinkingAlready = 1; }
	bool             unknown_bool_3CF;
	bool             unknown_bool_3D0;
	bool             HasBeenAttacked; // ReceiveDamage when not HouseClass_IsAlly
	bool             Cloakable;
	bool             IsPrimaryFactory; // doubleclicking a warfac/barracks sets it as primary
	bool             Spawned;
	bool             IsInPlayfield;
	RecoilData       TurretRecoil;
	RecoilData       BarrelRecoil;
	bool             unknown_bool_418;
	bool             unknown_bool_419;
	bool             IsHumanControlled;
	bool             DiscoveredByPlayer;
	bool             DiscoveredByComputer;
	bool             unknown_bool_41D;
	bool             unknown_bool_41E;
	bool             unknown_bool_41F;
	char             SightIncrease; // used for LeptonsPerSightIncrease
	bool             RecruitableA; // these two are like Lenny and Carl, weird purpose and never seen separate
	bool             RecruitableB; // they're usually set on preplaced objects in maps
	bool             IsRadarTracked;
	bool             IsOnCarryall;
	bool             IsCrashing;
	bool             WasCrashingAlready;
	bool             IsBeingManipulated;
	TechnoClass*     BeingManipulatedBy; // set when something is being molested by a locomotor such as magnetron
	                                       // the pointee will be marked as the killer of whatever the victim falls onto
	HouseClass*      ChronoWarpedByHouse;
	bool             unknown_bool_430;
	bool             unknown_bool_431;
	bool             unknown_bool_432;
	TeamClass*       OldTeam;
	bool             CountedAsOwnedSpecial; // for absorbers, infantry uses this to manually control OwnedInfantry count
	bool             Absorbed; // in UnitAbsorb/InfantryAbsorb or smth, lousy memory
	bool             unknown_bool_43A;
	DWORD            unknown_43C;
	DynamicVectorClass<int> CurrentTargetThreatValues;
	DynamicVectorClass<AbstractClass*> CurrentTargets;

 // if DistributedFire=yes, this is used to determine which possible targets should be ignored in the latest threat scan
	DynamicVectorClass<AbstractClass*> AttackedTargets;

	AudioController  Audio3;

	DWORD            unknown_49C;
	DWORD            unknown_4A0;

	AudioController  Audio4;

	bool             unknown_bool_4B8;
	DWORD            unknown_4BC;

	AudioController  Audio5;

	bool             unknown_bool_4D4;
	DWORD            unknown_4D8;

	AudioController  Audio6;

	DWORD            QueuedVoiceIndex;
	DWORD            unknown_4F4;
	bool             unknown_bool_4F8;
	DWORD            unknown_4FC;	//gets initialized with the current Frame, but this is NOT a TimerStruct!
	DWORD            unknown_500;
	DWORD            EMPLockRemaining;
	DWORD            ThreatPosed; // calculated to include cargo etc
	DWORD            ShouldLoseTargetNow;
	RadBeam*         FiringRadBeam;
	PlanningTokenClass* PlanningToken;
	ObjectTypeClass* Disguise;
	HouseClass*      DisguisedAsHouse;
};
