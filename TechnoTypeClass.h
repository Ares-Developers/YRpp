/*
	TechnoTypes are initialized by INI files.
*/

#ifndef TECHNOTYPE_H
#define TECHNOTYPE_H

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
	int HoldFrames;
	int RecoverFrames;
};

struct WeaponStruct
{
	WeaponTypeClass*  WeaponType;
	CoordStruct       FLH;
	int               BarrelLength;
	int               BarrelThickness;
	bool              TurretLocked;

	WeaponStruct()
	{
		this->WeaponType = NULL;
		this->FLH.X = this->FLH.Y = this->FLH.Z = this->BarrelLength = this->BarrelThickness = 0;
		this->TurretLocked = false;
	}

	bool operator == (WeaponStruct pWeap)
		{ return true; }
};

#pragma pack(push, 8)

#pragma pack(4)

class TechnoTypeClass : public ObjectTypeClass
{
public:

	static DynamicVectorClass<TechnoTypeClass *>* Array; // HAX to instantiate

	static TechnoTypeClass* Find(const char* pID)
	{
		for(int i = 0; i < Array->Count; ++i) {
			if(!_strcmpi(((TechnoTypeClass*)Array->Items[i])->get_ID(), pID)) {
				return ((TechnoTypeClass*)Array->Items[i]);
			}
		}
		return NULL;
	}

	static int FindIndex(const char* pID)
	{
		for(int i = 0; i < Array->Count; ++i) {
			if(!_strcmpi(((TechnoTypeClass*)Array->Items[i])->get_ID(), pID)) {
				return i;
			}
		}
		return -1;
	}

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
	virtual bool CanCreateHere(CellStruct* pMapCoords, DWORD dwUnk) const R0;
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

	//Constructor
	TechnoTypeClass(const char* id, eSpeedType speedtype) : ObjectTypeClass(false)
		{ JMP_THIS(0x710AF0); }

protected:
	//default contructor, only used by polymorphism
	TechnoTypeClass() : ObjectTypeClass(false)
		{ }
	TechnoTypeClass(bool) : ObjectTypeClass(false)
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
	int             Category;
	DWORD           unknown_3C0;
	DWORD align_3C4;
	double          DeployTime;
	int             FireAngle;
	PipScale::Value PipScale;
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
	eMovementZone   MovementZone;
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
	eSpeedType      SpeedType;
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
	char CameoFile [0x19];
	PROTECTED_PROPERTY(BYTE,  unused_6EF);
	SHPStruct*      Cameo;
	PROTECTED_PROPERTY(BYTE,  unused_6F4);
	char AltCameoFile [0x19];
	PROTECTED_PROPERTY(BYTE,  unused_70E);
	PROTECTED_PROPERTY(BYTE,  unused_70F);
	SHPStruct*      AltCameo;
	PROTECTED_PROPERTY(BYTE,  unused_714);
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

	int TurretWeapon [0x21];

/*
	//Turret - Weapon assignments
	protected: int TurretWeapon[0x21];
	public: int get_TurretWeapon(int turret)
		{ return TurretWeapon[turret]; }
				void set_TurretWeapon(int turret, int value)
		{ TurretWeapon[turret]=value; }
*/

	//Weapon
	protected:
		WeaponStruct            Weapon[0x12];
	public:
		WeaponTypeClass* get_Primary()
			{ return Weapon[0].WeaponType; }
		WeaponTypeClass* get_Secondary()
			{ return Weapon[1].WeaponType; }

		WeaponTypeClass* get_Weapon(int i)
			{ return Weapon[i].WeaponType; }
		void set_Weapon(int i, WeaponTypeClass* value)
			{ Weapon[i].WeaponType = value; }

		CoordStruct get_WeaponFLH(int i)
			{ return Weapon[i].FLH;}
		void set_WeaponFLH(int i, CoordStruct value)
			{ Weapon[i].FLH = value;}

	bool            ClearAllWeapons;

	//EliteWeapon
	protected:
		WeaponStruct            EliteWeapon[0x12];
	public:
		WeaponTypeClass* get_ElitePrimary()
			{ return EliteWeapon[0].WeaponType; }
		WeaponTypeClass* get_EliteSecondary()
			{ return EliteWeapon[1].WeaponType; }

		WeaponTypeClass* get_EliteWeapon(int i)
			{ return EliteWeapon[i].WeaponType; }
		void set_EliteWeapon(int i, WeaponTypeClass* value)
			{ EliteWeapon[i].WeaponType = value; }

		CoordStruct get_EliteWeaponFLH(int i)
			{ return EliteWeapon[i].FLH;}
		void set_EliteWeaponFLH(int i, CoordStruct value)
			{ EliteWeapon[i].FLH = value;}

	bool            TypeImmune;
	bool            MoveToShroud;
	bool            Trainable;
	bool            Cyborg_; //!Copied from the InfantryTypeClass!
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
	char PaletteFile [0x20];
	void*           Palette; //no... idea....
	DWORD           unknown_DF4;
	int             ArrayIndex; //in the respective class type's array!!
};

#pragma pack(pop)

#endif
