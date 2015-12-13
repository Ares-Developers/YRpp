/*
	TechnoTypes are initialized by INI files.
*/

#pragma once

#include <ObjectTypeClass.h>
#include <RulesClass.h>
#include <WeaponTypeClass.h>

//forward declarations
class AircraftTypeClass;
class AnimTypeClass;
class BuildingTypeClass;
class InfantryTypeClass;
class ParticleSystemTypeClass;
class VoxelAnimTypeClass;
class UnitTypeClass;

struct AbilitiesStruct
{
	bool FASTER; //0x00
	bool STRONGER; //0x01
	bool FIREPOWER; //0x02
	bool SCATTER; //0x03
	bool ROF; //0x04
	bool SIGHT; //0x05
	bool CLOAK; //0x06
	bool TIBERIUM_PROOF; //0x07
	bool VEIN_PROOF; //0x08
	bool SELF_HEAL; //0x09
	bool EXPLODES; //0x0A
	bool RADAR_INVISIBLE; //0x0B
	bool SENSORS; //0x0C
	bool FEARLESS; //0x0D
	bool C4; //0x0E
	bool TIBERIUM_HEAL; //0x0F
	bool GUARD_AREA; //0x10
	bool CRUSHER; //0x11
};

struct TurretControl
{
	int Travel;
	int CompressFrames;
	int RecoverFrames;
	int HoldFrames;
};

struct WeaponStruct
{
	WeaponTypeClass*  WeaponType;
	CoordStruct       FLH;
	int               BarrelLength;
	int               BarrelThickness;
	bool              TurretLocked;

	WeaponStruct() : WeaponType(nullptr),
		FLH(CoordStruct::Empty),
		BarrelLength(0),
		BarrelThickness(0),
		TurretLocked(false)
	{ }

	bool operator == (const WeaponStruct& pWeap) const
		{ return false; }
};

class NOVTABLE TechnoTypeClass : public ObjectTypeClass
{
public:

	static DynamicVectorClass<TechnoTypeClass *>* const Array; // HAX to instantiate

	static TechnoTypeClass* Find(const char* pID)
	{
		for(auto pItem : *Array) {
			if(!_strcmpi(pItem->get_ID(), pID)) {
				return pItem;
			}
		}
		return nullptr;
	}

	static int FindIndex(const char* pID)
	{
		for(int i = 0; i < Array->Count; ++i) {
			if(!_strcmpi(Array->Items[i]->get_ID(), pID)) {
				return i;
			}
		}
		return -1;
	}

	static auto const MaxWeapons = 18;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;
	virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//Destructor
	virtual ~TechnoTypeClass() RX;

	//ObjectTypeClass

	//TechnoTypeClass
	virtual bool vt_entry_A0() R0;
	virtual bool CanAttackMove() const R0;
	virtual bool CanCreateHere(const CellStruct& mapCoords, HouseClass* pOwner) const R0;
	virtual int GetCost() const R0;
	virtual int GetRepairStepCost() const R0;
	virtual int GetRepairStep() const R0;
	virtual int GetRefund(HouseClass* pHouse, bool bUnk) const R0;
	virtual int GetFlightLevel() const R0;

	// non-virtual
	bool HasMultipleTurrets() const
	{
		return this->TurretCount > 0;
	}

	CoordStruct* GetParticleSysOffset(CoordStruct* pBuffer) const
		{ JMP_THIS(0x7178C0); }

	CoordStruct GetParticleSysOffset() const
	{
		CoordStruct buffer;
		GetParticleSysOffset(&buffer);
		return buffer;
	}

	bool InOwners(DWORD const bitHouseType) const {
		return 0u != (this->GetOwners() & bitHouseType);
	}

	bool InRequiredHouses(DWORD const bitHouseType) const {
		auto const test = this->RequiredHouses;
		if(static_cast<int>(test) == -1) {
			return true;
		}
		return 0u != (test & bitHouseType);
	}

	bool InForbiddenHouses(DWORD const bitHouseType) const {
		auto const test = this->ForbiddenHouses;
		if(static_cast<int>(test) == -1) {
			return false;
		}
		return 0u != (test & bitHouseType);
	}

	// weapon related
	WeaponStruct& GetWeapon(size_t const index, bool const elite) {
		return elite ? this->EliteWeapon[index] : this->Weapon[index];
	}

	WeaponStruct const& GetWeapon(size_t const index, bool const elite) const {
		return elite ? this->EliteWeapon[index] : this->Weapon[index];
	}

	//Constructor
	TechnoTypeClass(const char* id, SpeedType speedtype) noexcept
		: TechnoTypeClass(noinit_t())
	{ JMP_THIS(0x710AF0); }

protected:
	explicit __forceinline TechnoTypeClass(noinit_t) noexcept
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int             WalkRate;
	int             IdleRate;
	AbilitiesStruct VeteranAbilities;
	AbilitiesStruct EliteAbilities;
	double          SpecialThreatValue;
	double          MyEffectivenessCoefficient;
	double          TargetEffectivenessCoefficient;
	double          TargetSpecialThreatCoefficient;
	double          TargetStrengthCoefficient;
	double          TargetDistanceCoefficient;
	double          ThreatAvoidanceCoefficient;
	int             SlowdownDistance;
	DWORD align_2FC;
	double          unknown_double_300;
	double          AccelerationFactor;
	int             CloakingSpeed;
	TypeList<VoxelAnimTypeClass*> DebrisTypes;
	TypeList<int> DebrisMaximums;
	_GUID           Locomotor;
	DWORD align_35C;
	double          unknown_double_360;
	double          unknown_double_368;
	double          Weight;
	double          PhysicalSize;
	double          Size;
	double          SizeLimit;
	bool            HoverAttack;
	int             VHPScan;
	int             unknown_int_398;
	DWORD align_39C;
	double          RollAngle;
	double          PitchSpeed;
	double          PitchAngle;
	int             BuildLimit;
	Category        Category;
	DWORD           unknown_3C0;
	DWORD align_3C4;
	double          DeployTime;
	int             FireAngle;
	PipScale        PipScale;
	bool            PipsDrawForAll;
	int             LeptonMindControlOffset;
	int             PixelSelectionBracketDelta;
	int             PipWrap;
	TypeList<BuildingTypeClass*> Dock;
	BuildingTypeClass* DeploysInto;
	UnitTypeClass*  UndeploysInto;
	UnitTypeClass*  PowersUnit;
	bool            PoweredUnit;
	TypeList<int> VoiceSelect;
	TypeList<int> VoiceSelectEnslaved;
	TypeList<int> VoiceSelectDeactivated;
	TypeList<int> VoiceMove;
	TypeList<int> VoiceAttack;
	TypeList<int> VoiceSpecialAttack;
	TypeList<int> VoiceDie;
	TypeList<int> VoiceFeedback;
	TypeList<int> MoveSound;
	TypeList<int> DieSound;
	int             AuxSound1;
	int             AuxSound2;
	int             CreateSound;
	int             DamageSound;
	int             ImpactWaterSound;
	int             ImpactLandSound;
	int             CrashingSound;
	int             SinkingSound;
	int             VoiceFalling;
	int             VoiceCrashing;
	int             VoiceSinking;
	int             VoiceEnter;
	int             VoiceCapture;
	int             TurretRotateSound;
	int             EnterTransportSound;
	int             LeaveTransportSound;
	int             DeploySound;
	int             UndeploySound;
	int             ChronoInSound;
	int             ChronoOutSound;
	int             VoiceHarvest;
	int             VoicePrimaryWeaponAttack;
	int             VoicePrimaryEliteWeaponAttack;
	int             VoiceSecondaryWeaponAttack;
	int             VoiceSecondaryEliteWeaponAttack;
	int             VoiceDeploy;
	int             VoiceUndeploy;
	int             EnterGrinderSound;
	int             LeaveGrinderSound;
	int             EnterBioReactorSound;
	int             LeaveBioReactorSound;
	int             ActivateSound;
	int             DeactivateSound;
	int             MindClearedSound;
	MovementZone    MovementZone;
	int             GuardRange;
	int             MinDebris;
	int             MaxDebris;
	TypeList<AnimTypeClass*> DebrisAnims;
	int             Passengers;
	bool            OpenTopped;
	int             Sight;
	bool            ResourceGatherer;
	bool            ResourceDestination;
	bool            RevealToAll;
	bool            Drainable;
	int             SensorsSight;
	int             DetectDisguiseRange;
	int             BombSight;
	int             LeadershipRating;
	int             NavalTargeting;
	int             LandTargeting;
	float           BuildTimeMultiplier;
	int             MindControlRingOffset;
	int             Cost;
	int             Soylent;
	int             FlightLevel;
	int             AirstrikeTeam;
	int             EliteAirstrikeTeam;
	AircraftTypeClass* AirstrikeTeamType;
	AircraftTypeClass* EliteAirstrikeTeamType;
	int             AirstrikeRechargeTime;
	int             EliteAirstrikeRechargeTime;
	int             TechLevel;
	TypeList<int> Prerequisite;
	TypeList<int> PrerequisiteOverride;
	int             ThreatPosed;
	int             Points;
	int             Speed;
	SpeedType       SpeedType;
	int             InitialAmmo;
	int             Ammo;
	int             IFVMode;
	int             AirRangeBonus;
	bool            BerserkFriendly;
	bool            SprayAttack;
	bool            Pushy;
	bool            Natural;
	bool            Unnatural;
	bool            CloseRange;
	int             Reload;
	int             EmptyReload;
	int             ReloadIncrement;
	int             RadialFireSegments;
	int             DeployFireWeapon;
	bool            DeployFire;
	bool            DeployToLand;
	bool            MobileFire;
	bool            OpportunityFire;
	bool            DistributedFire;
	bool            DamageReducesReadiness;
	int             ReadinessReductionMultiplier;
	UnitTypeClass*  UnloadingClass;
	AnimTypeClass*  DeployingAnim;
	bool            AttackFriendlies;
	bool            AttackCursorOnFriendlies;
	int             UndeployDelay;
	bool            PreventAttackMove;
	DWORD           OwnerFlags;
	int             AIBasePlanningSide;
	bool            StupidHunt;
	bool            AllowedToStartInMultiplayer;
	char            CameoFile[0x19];
	PROTECTED_PROPERTY(BYTE,  align_6EF);
	SHPStruct*      Cameo;
	bool            CameoAllocated;
	char            AltCameoFile[0x19];
	PROTECTED_PROPERTY(BYTE,  align_70E[2]);
	SHPStruct*      AltCameo;
	bool            AltCameoAllocated;
	int             RotCount;
	int             ROT;
	int             TurretOffset;
	bool            CanBeHidden;
	int             Points2; //twice
	TypeList<AnimTypeClass*> Explosion;
	TypeList<AnimTypeClass*> DestroyAnim;
	ParticleSystemTypeClass* NaturalParticleSystem;
	CoordStruct NaturalParticleSystemLocation;
	ParticleSystemTypeClass* RefinerySmokeParticleSystem;
	TypeList<ParticleSystemTypeClass*> DamageParticleSystems;
	TypeList<ParticleSystemTypeClass*> DestroyParticleSystems;
	CoordStruct DamageSmokeOffset;
	bool            DamSmkOffScrnRel;
	CoordStruct DestroySmokeOffset;
	CoordStruct RefinerySmokeOffsetOne;
	CoordStruct RefinerySmokeOffsetTwo;
	CoordStruct RefinerySmokeOffsetThree;
	CoordStruct RefinerySmokeOffsetFour;
	int             ShadowIndex;
	int             Storage;
	bool            TurretNotExportedOnGround;
	bool            Gunner;
	bool            HasTurretTooltips;
	int             TurretCount;
	int             WeaponCount;
	bool            IsChargeTurret;
	int             TurretWeapon[0x21];
	WeaponStruct	Weapon[MaxWeapons];
	bool            ClearAllWeapons;
	WeaponStruct	EliteWeapon[MaxWeapons];
	bool            TypeImmune;
	bool            MoveToShroud;
	bool            Trainable;
	bool            DamageSparks; //enabled for Cyborg InfantryTypes
	bool            TargetLaser;
	bool            ImmuneToVeins;
	bool            TiberiumHeal;
	bool            CloakStop;
	bool            IsTrain;
	bool            IsDropship;
	bool            ToProtect;
	bool            Disableable;
	bool            Unbuildable; //always false, if true it cannot be built from sidebar
	bool            DoubleOwned;
	bool            Invisible;
	bool            RadarVisible;
	bool            HasPrimary; //not loaded from the INIs
	bool            Sensors;
	bool            Nominal;
	bool            DontScore;
	bool            DamageSelf;
	bool            Turret;
	bool            TurretRecoil;
	TurretControl   TurretAnimData;
	bool            unknown_bool_CB4; //always false?
	TurretControl   BarrelAnimData;
	bool            unknown_bool_CC8; //always false?

protected:
	BYTE align_CC9, align_CCA, align_CCB;

public:
	bool            Repairable;
	bool            Crewed;
	bool            Naval;
	bool            Remapable;
	bool            Cloakable;
	bool            GapGenerator;
	char            GapRadiusInCells;
	char            SuperGapRadiusInCells;
	bool            Teleporter;
	bool            IsGattling;
	int             WeaponStages;
	int WeaponStage [6];
	int EliteStage [6];
	int             RateUp;
	int             RateDown;
	bool            SelfHealing;
	bool            Explodes;
	WeaponTypeClass* DeathWeapon;
	float           DeathWeaponDamageModifier;
	bool            NoAutoFire;
	bool            TurretSpins;
	bool            TiltCrashJumpjet;
	bool            Normalized;
	bool            ManualReload;
	bool            VisibleLoad;
	bool            LightningRod;
	bool            HunterSeeker;
	bool            Crusher;
	bool            OmniCrusher;
	bool            OmniCrushResistant;
	bool            TiltsWhenCrushes;
	bool            IsSubterranean;
	bool            AutoCrush;
	bool            Bunkerable;
	bool            CanDisguise;
	bool            PermaDisguise;
	bool            DetectDisguise;
	bool            DisguiseWhenStill;
	bool            CanApproachTarget;
	bool            CanRecalcApproachTarget;
	bool            ImmuneToPsionics;
	bool            ImmuneToPsionicWeapons;
	bool            ImmuneToRadiation;
	bool            Parasiteable;
	bool            DefaultToGuardArea;
	bool            Warpable;
	bool            ImmuneToPoison;
	bool            ReselectIfLimboed;
	bool            RejoinTeamIfLimboed;
	bool            Slaved;
	InfantryTypeClass* Enslaves;
	int             SlavesNumber;
	int             SlaveRegenRate;
	int             SlaveReloadRate;
	int             OpenTransportWeapon;
	bool            Spawned;
	AircraftTypeClass* Spawns;
	int             SpawnsNumber;
	int             SpawnRegenRate;
	int             SpawnReloadRate;
	bool            MissileSpawn;
	bool            Underwater;
	bool            BalloonHover;
	int             SuppressionThreshold;
	int             JumpjetTurnRate;
	int             JumpjetSpeed;
	float           JumpjetClimb;
	float           JumpjetCrash;
	int             JumpjetHeight;
	float           JumpjetAccel;
	float           JumpjetWobbles;
	bool            JumpjetNoWobbles;
	int             JumpjetDeviation;
	bool            JumpJet;
	bool            Crashable;
	bool            ConsideredAircraft;
	bool            Organic;
	bool            NoShadow;
	bool            CanPassiveAquire;
	bool            CanRetaliate;
	bool            RequiresStolenThirdTech;
	bool            RequiresStolenSovietTech;
	bool            RequiresStolenAlliedTech;
	DWORD           RequiredHouses;
	DWORD           ForbiddenHouses;
	DWORD           SecretHouses;
	bool            UseBuffer;
	CoordStruct SecondSpawnOffset;
	bool            IsSelectableCombatant;
	bool            Accelerates;
	bool            DisableVoxelCache;
	bool            DisableShadowCache;
	int             ZFudgeCliff;
	int             ZFudgeColumn;
	int             ZFudgeTunnel;
	int             ZFudgeBridge;
	char            PaletteFile[0x20];
	void*           Palette; //no... idea....
	DWORD           align_DF4;
};
