#ifndef GENEREALDEFINITIONS_H
#define GENEREALDEFINITIONS_H

#include <GeneralStructures.h>

//Scalar Deleting Destructor Flags
#define SDDTOR_NODELETE				0x00
#define SDDTOR_DELETE				0x01

typedef int eAbstractFlags;
#define ABSFLAGS_ISTECHNO			0x01
#define ABSFLAGS_ISOBJECT			0x02
#define ABSFLAGS_ISFOOT				0x04


typedef int eAbstractType;

#define	abs_None		0x0
#define	abs_Unit		0x1
#define	abs_Aircraft		0x2
#define	abs_AircraftType		0x3
#define	abs_Anim		0x4
#define	abs_AnimType		0x5
#define	abs_Building		0x6
#define	abs_BuildingType		0x7
#define	abs_Bullet		0x8
#define	abs_BulletType		0x9
#define	abs_Campaign		0xA
#define	abs_Cell		0xB
#define	abs_Factory		0xC
#define	abs_House		0xD
#define	abs_HouseType		0xE
#define	abs_Infantry		0xF
#define	abs_InfantryType		0x10
#define	abs_Isotile		0x11
#define	abs_IsotileType		0x12
#define	abs_BuildingLight		0x13
#define	abs_Overlay		0x14
#define	abs_OverlayType		0x15
#define	abs_Particle		0x16
#define	abs_ParticleType		0x17
#define	abs_ParticleSystem		0x18
#define	abs_ParticleSystemType		0x19
#define	abs_Script		0x1A
#define	abs_ScriptType		0x1B
#define	abs_Side		0x1C
#define	abs_Smudge		0x1D
#define	abs_SmudgeType		0x1E
#define	abs_Special		0x1F
#define	abs_SuperWeaponType		0x20
#define	abs_TaskForce		0x21
#define	abs_Team		0x22
#define	abs_TeamType		0x23
#define	abs_Terrain		0x24
#define	abs_TerrainType		0x25
#define	abs_Trigger		0x26
#define	abs_TriggerType		0x27
#define	abs_UnitType		0x28
#define	abs_VoxelAnim		0x29
#define	abs_VoxelAnimType		0x2A
#define	abs_Wave		0x2B
#define	abs_Tag		0x2C
#define	abs_TagType		0x2D
#define	abs_Tiberium		0x2E
#define	abs_Action		0x2F
#define	abs_Event		0x30
#define	abs_WeaponType		0x31
#define	abs_WarheadType		0x32
#define	abs_Waypoint		0x33
#define	abs_Abstract		0x34
#define	abs_Tube		0x35
#define	abs_LightSource		0x36
#define	abs_EMPulse		0x37
#define	abs_TacticalMap		0x38
#define	abs_Super		0x39
#define	abs_AITrigger		0x3A
#define	abs_AITriggerType		0x3B
#define	abs_Neuron		0x3C
#define	abs_FoggedObject		0x3D
#define	abs_AlphaShape		0x3E
#define	abs_VeinholeMonster		0x3F
#define	abs_NavyType		0x40
#define	abs_SpawnManager		0x41
#define	abs_CaptureManager		0x42
#define	abs_Parasite		0x43
#define	abs_Bomb		0x44
#define	abs_RadSite		0x45
#define	abs_Temporal		0x46
#define	abs_Airstrike		0x47
#define	abs_SlaveManager		0x48
#define	abs_DiskLaser		0x49


typedef int eAction;

#define	act_None		0x0
#define	act_Move		0x1
#define	act_NoMove		0x2
#define	act_Enter		0x3
#define	act_Self_Deploy		0x4
#define	act_Attack		0x5
#define	act_Harvest		0x6
#define	act_Select		0x7
#define	act_ToggleSelect		0x8
#define	act_Capture		0x9
#define	act_Eaten		0xA
#define	act_Repair		0xB
#define	act_Sell		0xC
#define	act_SellUnit		0xD
#define	act_NoSell		0xE
#define	act_NoRepair		0xF
#define	act_Sabotage		0x10
#define	act_Tote		0x11
#define	act_DontUse2		0x12
#define	act_DontUse3		0x13
#define	act_Nuke		0x14
#define	act_DontUse4		0x15
#define	act_DontUse5		0x16
#define	act_DontUse6		0x17
#define	act_DontUse7		0x18
#define	act_DontUse8		0x19
#define	act_GuardArea		0x1A
#define	act_Heal		0x1B
#define	act_Damage		0x1C
#define	act_GRepair		0x1D
#define	act_NoDeploy		0x1E
#define	act_NoEnter		0x1F
#define	act_NoGRepair		0x20
#define	act_TogglePower		0x21
#define	act_NoTogglePower		0x22
#define	act_EnterTunnel		0x23
#define	act_NoEnterTunnel		0x24
#define	act_IronCurtain		0x25
#define	act_LightningStorm		0x26
#define	act_ChronoSphere		0x27
#define	act_ChronoWarp		0x28
#define	act_ParaDrop		0x29
#define	act_PlaceWaypoint		0x2A
#define	act_TibSunBug		0x2B
#define	act_EnterWaypointMode		0x2C
#define	act_FollowWaypoint		0x2D
#define	act_SelectWaypoint		0x2E
#define	act_LoopWaypointPath		0x2F
#define	act_DragWaypoint		0x30
#define	act_AttackWaypoint		0x31
#define	act_EnterWaypoint		0x32
#define	act_PatrolWaypoint		0x33
#define	act_AreaAttack		0x34
#define	act_IvanBomb		0x35
#define	act_NoIvanBomb		0x36
#define	act_Detonate		0x37
#define	act_DetonateAll		0x38
#define	act_DisarmBomb		0x39
#define	act_SelectNode		0x3A
#define	act_AttackSupport		0x3B
#define	act_PlaceBeacon		0x3C
#define	act_SelectBeacon		0x3D
#define	act_AttackMoveNav		0x3E
#define	act_AttackMoveTar		0x3F
#define	act_Demolish		0x40
#define	act_AmerParaDrop		0x41
#define	act_PsychicDominator		0x42
#define	act_SpyPlane		0x43
#define	act_GeneticConverter		0x44
#define	act_ForceShield		0x45
#define	act_NoForceShield		0x46
#define	act_Airstrike		0x47
#define	act_PsychicReveal		0x48


class Abilities {
public:
	typedef int Value;
	enum {
		FASTER = 0x0,
		STRONGER = 0x1,
		FIREPOWER = 0x2,
		SCATTER = 0x3,
		ROF = 0x4,
		SIGHT = 0x5,
		CLOAK = 0x6,
		TIBERIUM_PROOF = 0x7,
		VEIN_PROOF = 0x8,
		SELF_HEAL = 0x9,
		EXPLODES = 0xA,
		RADAR_INVISIBLE = 0xB,
		SENSORS = 0xC,
		FEARLESS = 0xD,
		C4 = 0xE,
		TIBERIUM_HEAL = 0xF,
		GUARD_AREA = 0x10,
		CRUSHER = 0x11
	};
};


class AIDifficulty {
public:
	typedef unsigned int Value;
	enum {
		Hard = 0,
		Normal = 1,
		Easy = 2
	};
};

class TriggerEvent {
public:
	typedef unsigned int Value;
	enum {
		None = 0x0,
		EnteredBy = 0x1,
		SpiedBy = 0x2,
		ThievedBy = 0x3,
		DiscoveredByPlayer  = 0x4,
		HouseDiscovered = 0x5,
		AttackedByAnybody = 0x6,
		DestroyedByAnybody = 0x7,
		AnyEvent = 0x8,
		DestroyedUnitsAll = 0x9,
		DestroyedBuildingsAll = 0xA,
		DestroyedAll = 0xB,
		CreditsExceed = 0xC,
		ElapsedTime = 0xD,
		MissionTimerExpired = 0xE,
		DestroyedBuildingsNum  = 0xF,
		DestroyedUnitsNum = 0x10,
		NoFactoriesLeft = 0x11,
		CiviliansEvacuated = 0x12,
		BuildBuildingType = 0x13,
		BuildUnitType = 0x14,
		BuildInfantryType = 0x15,
		BuildAircraftType = 0x16,
		TeamLeavesMap = 0x17,
		ZoneEntryBy = 0x18,
		CrossesHorizontalLine = 0x19,
		CrossesVerticalLine = 0x1A,
		GlobalSet = 0x1B,
		GlobalCleared = 0x1C,
		DestroyedFakesAll = 0x1D,
		LowPower = 0x1E,
		AllBridgesDestroyed = 0x1F,
		BuildingExists = 0x20,
		SelectedByPlayer = 0x21,
		ComesNearWaypoint = 0x22,
		EnemyInSpotlight = 0x23,
		LocalSet = 0x24,
		LocalCleared = 0x25,
		FirstDamaged_combatonly = 0x26,
		HalfHealth_combatonly = 0x27,
		QuarterHealth_combatonly = 0x28,
		FirstDamaged_anysource = 0x29,
		HalfHealth_anysource = 0x2A,
		QuarterHealth_anysource = 0x2B,
		AttackedByHouse = 0x2C,
		AmbientLightBelow = 0x2D,
		AmbientLightAbove = 0x2E,
		ElapsedScenarioTime = 0x2F,
		DestroyedByAnything = 0x30,
		PickupCrate = 0x31,
		PickupCrate_any = 0x32,
		RandomDelay = 0x33,
		CreditsBelow = 0x34,
		SpyAsHouse = 0x35,
		SpyAsInfantry = 0x36,
		DestroyedUnitsNaval = 0x37,
		DestroyedUnitsLand = 0x38,
		BuildingDoesNotExist = 0x39,
		PowerFull = 0x3A,
		EnteredOrOverflownBy = 0x3B,
		TechTypeExists = 0x3C,
		TechTypeDoesntExist = 0x3D
	};
};

class TriggerAction {
public:
	typedef unsigned int Value;
	enum {
		None = 0x0,
		Win = 0x1,
		Lose = 0x2,
		ProductionBegins = 0x3,
		CreateTeam = 0x4,
		DestroyTeam = 0x5,
		AllToHunt = 0x6,
		Reinforcement = 0x7,
		DropZoneFlare = 0x8,
		FireSale = 0x9,
		PlayMovie = 0xA,
		TextTrigger = 0xB,
		DestroyTrigger = 0xC,
		AutocreateBegins = 0xD,
		ChangeHouse = 0xE,
		AllowWin = 0xF,
		RevealAllMap = 0x10,
		RevealAroundWaypoint = 0x11,
		RevealWaypointZone = 0x12,
		PlaySoundEffect = 0x13,
		PlayMusicTheme = 0x14,
		PlaySpeech = 0x15,
		ForceTrigger = 0x16,
		TimerStart = 0x17,
		TimerStop = 0x18,
		TimerExtend = 0x19,
		TimerShorten = 0x1A,
		TimerSet = 0x1B,
		GlobalSet = 0x1C,
		GlobalClear = 0x1D,
		AutoBaseBuilding = 0x1E,
		GrowShroud = 0x1F,
		DestroyAttachedObject = 0x20,
		AddOneTimeSuperWeapon = 0x21,
		AddRepeatingSuperWeapon = 0x22,
		PreferredTarget = 0x23,
		AllChangeHouse = 0x24,
		MakeAlly = 0x25,
		MakeEnemy = 0x26,
		ChangeZoomLevel = 0x27,
		ResizePlayerView = 0x28,
		PlayAnimAt = 0x29,
		DoExplosionAt = 0x2A,
		CreateVoxelAnim = 0x2B,
		IonStormStart = 0x2C,
		IonStormStop = 0x2D,
		LockInput = 0x2E,
		UnlockInput = 0x2F,
		MoveCameraToWaypoint = 0x30,
		ZoomIn = 0x31,
		ZoomOut = 0x32,
		ReshroudMap = 0x33,
		ChangeLightBehavior = 0x34,
		EnableTrigger = 0x35,
		DisableTrigger = 0x36,
		CreateRadarEvent = 0x37,
		LocalSet = 0x38,
		LocalClear = 0x39,
		MeteorShower = 0x3A,
		ReduceTiberium = 0x3B,
		SellBuilding = 0x3C,
		TurnOffBuilding = 0x3D,
		TurnOnBuilding = 0x3E,
		Apply100Damage = 0x3F,
		SmallLightFlash = 0x40,
		MediumLightFlash = 0x41,
		LargeLightFlash = 0x42,
		AnnounceWin = 0x43,
		AnnounceLose = 0x44,
		ForceEnd = 0x45,
		DestroyTag = 0x46,
		SetAmbientStep = 0x47,
		SetAmbientRate = 0x48,
		SetAmbientLight = 0x49,
		AITriggersBegin = 0x4A,
		AITriggersStop = 0x4B,
		RatioOfAITriggerTeams = 0x4C,
		RatioOfTeamAircraft = 0x4D,
		RatioOfTeamInfantry = 0x4E,
		RatioOfTeamUnits = 0x4F,
		ReinforcementAt = 0x50,
		WakeupSelf = 0x51,
		WakeupAllSleepers = 0x52,
		WakeupAllHarmless = 0x53,
		WakeupGroup = 0x54,
		VeinGrowth = 0x55,
		TiberiumGrowth = 0x56,
		IceGrowth = 0x57,
		ParticleAnim = 0x58,
		RemoveParticleAnim = 0x59,
		LightningStrike = 0x5A,
		GoBerzerk = 0x5B,
		ActivateFirestorm = 0x5C,
		DeactivateFirestorm = 0x5D,
		IonCannonStrike = 0x5E,
		NukeStrike = 0x5F,
		ChemMissileStrike = 0x60,
		ToggleTrainCargo = 0x61,
		PlaySoundEffectRandom = 0x62,
		PlaySoundEffectAtWaypoint = 0x63,
		PlayIngameMovie = 0x64,
		ReshroudMapAtWaypoint = 0x65,
		LightningStormStrike = 0x66,
		TimerText = 0x67,
		FlashTeam = 0x68,
		TalkBubble = 0x69,
		SetObjectTechLevel = 0x6A,
		ReinforcementByChrono = 0x6B,
		CreateCrate = 0x6C,
		IronCurtain = 0x6D,
		PauseGame = 0x6E,
		EvictOccupiers = 0x6F,
		CenterCameraAtWaypoint = 0x70,
		MakeHouseCheer = 0x71,
		SetTabTo = 0x72,
		FlashCameo = 0x73,
		StopSounds = 0x74,
		PlayIngameMovieAndPause = 0x75,
		ClearAllSmudges = 0x76,
		DestroyAll = 0x77,
		DestroyAllBuildings = 0x78,
		DestroyAllLandUnits = 0x79,
		DestroyAllNavalUnits = 0x7A,
		MindControlBase = 0x7B,
		RestoreMindControlledBase = 0x7C,
		CreateBuilding = 0x7D,
		RestoreStartingUnits = 0x7E,
		StartChronoScreenEffect = 0x7F,
		TeleportAll = 0x80,
		SetSuperWeaponCharge = 0x81,
		RestoreStartingBuildings = 0x82,
		FlashBuildingsOfType = 0x83,
		SuperWeaponSetRechargeTime = 0x84,
		SuperWeaponResetRechargeTime = 0x85,
		SuperWeaponReset = 0x86,
		SetPreferredTargetCell = 0x87,
		ClearPreferredTargetCell = 0x88,
		SetBaseCenterCell = 0x89,
		ClearBaseCenterCell = 0x8A,
		BlackoutRadar = 0x8B,
		SetDefensiveTargetCell = 0x8C,
		ClearDefensiveTargetCell = 0x8D,
		RetintRed = 0x8E,
		RetintGreen = 0x8F,
		RetintBlue = 0x90,
		JumpCameraHome = 0x91
	};
};

class AIMode {
public:
	typedef int Value;
	enum {
		General = 0,
		LowOnCash = 1, // if HouseClass::AvailableMoney < 25 ! stupidly low value
		BuildBase = 3,
		SellAll = 4,
	};
};


typedef int eAITrigCondition;

#define		tc_AIOwns		0x0
#define		tc_EnemyOwns		0x1
#define		tc_EnemyYellowPower		0x2
#define		tc_EnemyRedPower		0x3
#define		tc_EnemyCashExceeds		0x4
#define		tc_IronCharged		0x5
#define		tc_ChronoCharged		0x6
#define		tc_NeutralOwns		0x7
#define		tc_Pool		0xFFFFFFFF


typedef int eAITrigHouseType;

#define		th_None		0x0
#define		th_Single		0x1
#define		th_Any		0x2


class Armor {
public:
	typedef int Value;
	enum {
		None = 0,
		Flak = 1,
		Plate = 2,
		Light = 3,
		Medium = 4,
		Heavy = 5,
		Wood = 6,
		Steel = 7,
		Concrete = 8,
		Special_1 = 9,
		Special_2 = 10
	};
};

//spotlight behaviour
class SpotlightBehaviour {
public:
	typedef unsigned int Value;
	enum {
		None = 0x0,
		Sweep = 0x1,
		Circle = 0x2,
		Follow = 0x3,
	};
};

typedef int eSpotlightFlags;

#define sf_NoColor 0x1
#define sf_NoRed 0x2
#define sf_NoGreen 0x4
#define sf_NoBlue 0x8

//ParticleTypeClass->BehavesLike
typedef int eBehavesLike;

#define	bl_Smoke		0x0
#define	bl_Gas		0x1
#define	bl_Fire		0x2
#define	bl_Spark		0x3
#define	bl_Railgun		0x4


//ParticleSystemTypeClass->HoldsWhat, almost, but not entirely, unlike eBehavesLike above
typedef int eHoldsWhat;

#define	hw_Gas		0x0
#define	hw_Smoke		0x1
#define	hw_Fire		0x2
#define	hw_Spark		0x3
#define	hw_Railgun		0x4


typedef int eBuildCat;

#define	bcat_DontCare		0x0
#define	bcat_Tech		0x1
#define	bcat_Resource		0x2
#define	bcat_Power		0x3
#define	bcat_Infrastructure		0x4
#define	bcat_Combat		0x5


//typedef int eBuildingAnims;

class BuildingAnimSlot {
public:
	typedef int Value;
	enum {
		Upgrade1 = 0x0,
		Upgrade2 = 0x1,
		Upgrade3 = 0x2,
		Active = 0x3,
		ActiveTwo = 0x4,
		ActiveThree = 0x5,
		ActiveFour = 0x6,
		Production = 0x7,
		PreProduction = 0x8,
		Turret = 0x9,
		Special = 0xA,
		SpecialTwo = 0xB,
		SpecialThree = 0xC,
		SpecialFour = 0xD,
		Super = 0xE,
		SuperTwo = 0xF,
		SuperThree = 0x10,
		SuperFour = 0x11,
		Idle = 0x12,
		LowPower = 0x13,
		SuperLowPower = 0x14,
		All = 0xFFFFFFFE, // -2
	};
};


typedef int eCategory;

#define	cat_Soldier		0x0
#define	cat_Civilian		0x1
#define	cat_VIP		0x2
#define	cat_Recon		0x3
#define	cat_AFV		0x4
#define	cat_IFV		0x5
#define	cat_LRFS		0x6
#define	cat_Support		0x7
#define	cat_Transport		0x8
#define	cat_AirPower		0x9
#define	cat_AirLift		0xA


typedef int eCellFlags;

#define	cf_IsWaypoint		0x04
#define	cf_Explored			0x08 //this means no shroud
#define	cf_FlagPresent		0x10
#define cf_Bridge			0x100
#define	cf_VeinsPresent		0x20000
#define	cf_EMPPresent		0x80000
#define	cf_Fogged		0x400000


typedef int eCellFlags_12C;

#define cf2_ContainsBuilding	0x02
#define	cf2_NoShadow			0x08 //else tooltip is TXT_SHADOW


class CloakState {
public:
	typedef int Value;
	enum {
		Uncloaked = 0,
		Cloaking = 1,
		Cloaked = 2,
		Uncloaking = 3
	};
};

class DamageState {
public:
	typedef int Value;
	enum {
		Unaffected = 0,
		Unchanged = 1,
		NowYellow = 2,
		NowRed = 3,
		NowDead = 4,
		PostMortem = 5
	};
};

class Direction {
public:
	typedef unsigned int Value;
	enum {
		N = 0x0,
		North = 0x0,
		NE = 0x1,
		NorthEast = 0x1,
		E = 0x2,
		East = 0x2,
		SE = 0x3,
		SouthEast = 0x3,
		S = 0x4,
		South = 0x4,
		SW = 0x5,
		SouthWest = 0x5,
		W = 0x6,
		West = 0x6,
		NW = 0x7,
		NorthWest = 0x7,
	};
};

// this is how game's enums are to be defined from now on
class FireError {
public:
	typedef unsigned int Value;
	enum {
		NotAValue = 0xFF,
		OK = 0, // no problem, can fire
		AMMO = 1, // no ammo
		FACING = 2, // bad facing
		REARM = 3, // still reloading
		ROTATING = 4, // busy rotating
		ILLEGAL = 5, // can't fire
		CANT = 6, // I'm sorry Dave, I can't do that
		MOVING = 7, // moving, can't fire
		RANGE = 8, // out of range
		CLOAKED = 9, // need to decloak
		BUSY = 10, // busy, please hold
		MUST_DEPLOY = 11 // deploy first!
	};
};


class HealthState {
public:
	typedef unsigned int Value;
	enum {
		Red = 0,
		Yellow = 1,
		Green = 2
	};
};


typedef int eFoundation;

#define	fnd_1x1		0x0
#define	fnd_2x1		0x1
#define	fnd_1x2		0x2
#define	fnd_2x2		0x3
#define	fnd_2x3		0x4
#define	fnd_3x2		0x5
#define	fnd_3x3		0x6
#define	fnd_3x5		0x7
#define	fnd_4x2		0x8
#define	fnd_3x3Refinery		0x9
#define	fnd_1x3		0xA
#define	fnd_3x1		0xB
#define	fnd_4x3		0xC
#define	fnd_1x4		0xD
#define	fnd_1x5		0xE
#define	fnd_2x6		0xF
#define	fnd_2x5		0x10
#define	fnd_5x3		0x11
#define	fnd_4x4		0x12
#define	fnd_3x4		0x13
#define	fnd_6x4		0x14
#define	fnd_0x0		0x15


class GameMode {
public:
	typedef unsigned int Value;
	enum {
		Campaign = 0x0,
		LAN = 0x3,
		Internet = 0x4,
		Skirmish = 0x5,
	};
};

class InfDeath {
public:
	typedef int Value;
	enum {
		None = 0,
		Die1 = 1,
		Die2 = 2,
		Explode = 3,
		Flames = 4,
		Electro = 5,
		HeadPop = 6,
		Nuked = 7,
		Virus = 8,
		Mutate = 9,
		Brute = 10,
	};
};


typedef int eLandType;

#define	lt_Clear		0x0
#define	lt_Road		0x1
#define	lt_Water		0x2
#define	lt_Rock		0x3
#define	lt_Wall		0x4
#define	lt_Tiberium		0x5
#define	lt_Beach		0x6
#define	lt_Rough		0x7
#define	lt_Ice		0x8
#define	lt_Railroad		0x9
#define	lt_Tunnel		0xA
#define	lt_Weeds		0xB


/*
 *
 * Some helpers
 *  let W = a result of creepy maths = 104 (leptons)
 *  let GH = this->GetHeight()
 *
 *  ObjectClass::InWhichLayer, used by practically all ObjectClass derivates except Foot, returns
 *   Ground if GH < 2*W leptons
 *   Air if it returns < Rules->CruiseHeight leptons
 *   Top otherwise
 *
 * FootClass::InWhichLayer, used by Infantry, Unit and Aircraft, returns results depending on the locomotor
 *  Drive         : Ground
 *  DropPod       : Air
 *  Fly           : Ground if GH <= 0, Top otherwise
 *  Hover         : Ground
 *  Jumpjet       : Ground if GH <= 2*W, Air if it's not at the height of its flight (rising/landing), Top otherwise
 *  Mech          : Ground
 *  Rocket        : Air
 *  Ship          : Ground
 *  Subterrannean : Underground if really underground, Ground if on ground, diving or elevating
 *  Walk          : Ground
 *
 */
class Layer {
public:
	typedef unsigned int Value;
	enum {
		None = -0x1,
		Underground = 0x0,
		Surface = 0x1,
		Ground = 0x2,
		Air = 0x3,
		Top = 0x4,
	};
};

class PlacementType {
public:
	typedef int Value;
	enum {
		Remove = 0,
		Put = 1,
		Redraw = 2,
		AddContent = 3
	};
};

typedef int eMouseHotSpotX;
typedef int eMouseHotSpotY;

#define hotspx_left		0
#define hotspx_center		0x3039
#define hotspx_right	0xD431

#define hotspy_top		0
#define hotspy_middle		0x3039
#define hotspy_bottom	0xD431

typedef int eMission;

#define	mission_None		-0x1
#define	mission_Sleep		0x0
#define	mission_Attack		0x1
#define	mission_Move		0x2
#define	mission_QMove		0x3
#define	mission_Retreat		0x4
#define	mission_Guard		0x5
#define	mission_Sticky		0x6
#define	mission_Enter		0x7
#define	mission_Capture		0x8
#define	mission_Eaten		0x9
#define	mission_Harvest		0xA
#define	mission_Area_Guard		0xB
#define	mission_Return		0xC
#define	mission_Stop		0xD
#define	mission_Ambush		0xE
#define	mission_Hunt		0xF
#define	mission_Unload		0x10
#define	mission_Sabotage		0x11
#define	mission_Construction		0x12
#define	mission_Selling		0x13
#define	mission_Repair		0x14
#define	mission_Rescue		0x15
#define	mission_Missile		0x16
#define	mission_Harmless		0x17
#define	mission_Open		0x18
#define	mission_Patrol		0x19
#define	mission_ParadropApproach		0x1A
#define	mission_ParadropOverfly		0x1B
#define	mission_Wait		0x1C
#define	mission_ChronoMove		0x1D
#define	mission_AttackAgain		0x1E
#define	mission_SpyplaneApproach		0x1F
#define	mission_SpyplaneOverfly		0x20


typedef int eMovementZone;

#define	mz_Normal		0x0
#define	mz_Crusher		0x1
#define	mz_Destroyer		0x2
#define	mz_AmphibiousDestroyer		0x3
#define	mz_AmphibiousCrusher		0x4
#define	mz_Amphibious		0x5
#define	mz_Subterrannean		0x6
#define	mz_Infantry		0x7
#define	mz_InfantryDestroyer		0x8
#define	mz_Fly		0x9
#define	mz_WaterBeach		0xB
#define	mz_CrusherAll		0xC


class Pip {
public:
	typedef int Value;
	enum {
		Empty = 0,
		Green = 1,
		Yellow = 2,
		White = 3,
		Red = 4,
		Blue = 5,
		PersonEmpty = 6,
		PersonGreen = 7,
		PersonYellow = 8,
		PersonWhite = 9,
		PersonRed = 10,
		PersonBlue = 11,
		PersonPurple = 12
	};
};

class PipScale {
public:
	typedef int Value;
	enum {
		None = 0,
		Ammo = 1,
		Tiberium = 2,
		Passengers = 3,
		Storage = 4,
		MindControl = 5
	};
};

class Powerup {
public:
	typedef int Value;
	enum {
		Money = 0,
		Unit = 1,
		HealBase = 2,
		Cloak = 3,
		Explosion = 4,
		Napalm = 5,
		Squad = 6,
		Darkness = 7,
		Reveal = 8,
		Armor = 9,
		Speed = 10,
		Firepower = 11,
		ICBM = 12,
		Invulnerability = 13,
		Veteran = 14,
		IonStorm = 15,
		Gas = 16,
		Tiberium = 17,
		Pod = 18
	};
};


typedef int ePrerequisite;

#define	prereq_PROC		-0x6
#define	prereq_TECH		-0x5
#define	prereq_RADAR		-0x4
#define	prereq_BARRACKS		-0x3
#define	prereq_FACTORY		-0x2
#define	prereq_POWER		-0x1


typedef int ePrismChargeState;

#define		pcs_Idle		0
#define		pcs_Master		1
#define		pcs_Slave		2


class RadarEventType {
public:
	typedef int Value;
	enum {
		Combat = 0,
		Noncombat = 1,
		DropZone = 2,
		BaseAttacked = 3,
		HarvesterAttacked = 4,
		EnemySensed = 5,
		UnitProduced = 6,
		UnitLost = 7,
		UnitRepaired = 8,
		BuildingInfiltrated = 9,
		BuildingCaptured = 10,
		BeaconPlaced = 11,
		SuperweaponDetected = 12,
		SuperweaponActivated = 13,
		BridgeRepaired = 14,
		GarrisonAbandoned = 15,
		AllyBaseAttacked = 16
	};
};

class PsychicDominatorStatus {
public:
	typedef unsigned int Value;
	enum {
		Inactive = 0,
		FirstAnim = 1,
		Fire = 2,
		SecondAnim = 3,
		Reset = 4,
		Over = 5
	};
};

class NukeFlashStatus {
public:
	typedef unsigned int Value;
	enum {
		Inactive = 0,
		FadeIn = 1,
		FadeOut = 2
	};
};

class ChargeDrainState {
public:
	typedef int Value;
	enum {
		None = -1,
		Charging = 0,
		Ready = 1,
		Draining = 2
	};
};

class SuperWeaponType {
public:
	typedef unsigned char Value;
	enum {
		Nuke = 0x0,
		IronCurtain = 0x1,
		LightningStorm = 0x2,
		ChronoSphere = 0x3,
		ChronoWarp = 0x4,
		ParaDrop = 0x5,
		AmerParaDrop = 0x6,
		PsychicDominator = 0x7,
		SpyPlane = 0x8,
		GeneticMutator = 0x9,
		ForceShield = 0xA,
		PsychicReveal = 0xB
	};
};


class MouseCursorType {
public:
	typedef unsigned char Value;
	enum {
		Default = 0x0,
		Move_N = 0x1,
		Move_NE = 0x2,
		Move_E = 0x3,
		Move_SE = 0x4,
		Move_S = 0x5,
		Move_SW = 0x6,
		Move_W = 0x7,
		Move_NW = 0x8,
		NoMove_N = 0x9,
		NoMove_NE = 0xA,
		NoMove_E = 0xB,
		NoMove_SE = 0xC,
		NoMove_S = 0xD,
		NoMove_SW = 0xE,
		NoMove_W = 0xF,
		NoMove_NW = 0x10,
		Select = 0x11,
		Move = 0x12,
		NoMove = 0x13,
		Attack = 0x14,
		AttackOutOfRange = 0x15,
		Protect = 0x16,
		DesolatorDeploy = 0x17,
		Cursor_18 = 0x18,
		Enter = 0x19,
		NoEnter = 0x1A,
		Deploy = 0x1B,
		NoDeploy = 0x1C,
		Cursor_1D = 0x1D,
		Sell = 0x1E,
		SellUnit = 0x1F,
		NoSell = 0x20,
		Repair = 0x21,
		EngineerRepair = 0x22,
		NoRepair = 0x23,
		Waypoint = 0x24,
		Disguise = 0x25,
		IvanBomb = 0x26,
		MindControl = 0x27,
		RemoveSquid = 0x28,
		Crush = 0x29,
		SpyTech = 0x2A,
		SpyPower = 0x2B,
		Cursor_2C = 0x2C,
		GIDeploy = 0x2D,
		Cursor_2E = 0x2E,
		ParaDrop = 0x2F,
		Cursor_30 = 0x30, // RallyPoint
		CloseWaypoint = 0x31, // ???
		LightningStorm = 0x32,
		Detonate = 0x33,
		Demolish = 0x34,
		Nuke = 0x35,
		Cursor_36 = 0x36, // BlueMove
		Power = 0x37,
		Cursor_38 = 0x38, // NoBlueMove
		IronCurtain = 0x39,
		Chronosphere = 0x3A,
		Disarm = 0x3B,
		Disallowed = 0x3C,
		Scroll = 0x3D,
		Scroll_ESW = 0x3E,
		Scroll_SW = 0x3F,
		Scroll_NSW = 0x40,
		Scroll_NW = 0x41,
		Scroll_NEW = 0x42,
		Scroll_NE = 0x43,
		Scroll_NES = 0x44,
		Scroll_ES = 0x45,
		Protect2 = 0x46,
		AttackOutOfRange2 = 0x47,
		Cursor_48 = 0x48, // LeaveBuilding
		InfantryAbsorb = 0x49,
		NoMindControl = 0x4A,
		Cursor_4B = 0x4B, // NoRallyPoint
		Cursor_4C = 0x4C,
		Cursor_4D = 0x4D,
		Beacon = 0x4E,
		ForceShield = 0x4F,
		NoForceShield = 0x50,
		GeneticMutator = 0x51,
		AirStrike = 0x52,
		PsychicDominator = 0x53,
		PsychicReveal = 0x54,
		SpyPlane = 0x55
	};
};

class RadBeamType {
public:
	typedef unsigned int Value;
	enum {
		Temporal = 0x0,
		RadBeam = 0x1,
		Eruption = 0x2, // this sets the beam color to MagnaBeamColor! There probably was no reason for that whatsoever.
	};
};

typedef int eRank;

#define	rank_Invalid		-0x1
#define	rank_Elite		0x0
#define	rank_Veteran		0x1
#define	rank_Rookie		0x2


class Sequence {
public:
	typedef int Value;
	enum {
		Ready = 0,
		Guard = 1,
		Prone = 2,
		Walk = 3,
		FireUp = 4,
		Down = 5,
		Crawl = 6,
		Up = 7,
		FireProne = 8,
		Idle1 = 9,
		Idle2 = 10,
		Die1 = 11,
		Die2 = 12,
		Die3 = 13,
		Die4 = 14,
		Die5 = 15,
		Tread = 16,
		Swim = 17,
		WetIdle1 = 18,
		WetIdle2 = 19,
		WetDie1 = 20,
		WetDie2 = 21,
		WetAttack = 22,
		Hover = 23,
		Fly = 24,
		Tumble = 25,
		FireFly = 26,
		Deploy = 27,
		Deployed = 28,
		DeployedFire = 29,
		DeployedIdle = 30,
		Undeploy = 31,
		Cheer = 32,
		Paradrop = 33,
		AirDeathStart = 34,
		AirDeathFalling = 35,
		AirDeathFinish = 36,
		Panic = 37,
		Shovel = 38,
		Carry = 39,
		SecondaryFire = 40,
		SecondaryProne = 41
	};
};


typedef int eSequenceFacing;

#define	st_N		0x0
#define	st_NE		0x1
#define	st_E		0x2
#define	st_SE		0x3
#define	st_S		0x4
#define	st_SW		0x5
#define	st_W		0x6
#define	st_NW		0x7


typedef int eSpeedType;

#define	st_Foot		0x0
#define	st_Track		0x1
#define	st_Wheel		0x2
#define	st_Hover		0x3
#define	st_Winged		0x4
#define	st_Float		0x5
#define	st_Amphibious		0x6
#define	st_FloatBeach		0x7


class TheaterType {
public:
	typedef int Value;
	enum {
		Temperate = 0,
		Snow = 1,
		Urban = 2,
		Desert = 3,
		NewUrban = 4,
		Lunar = 5,
	};
};

//typedef int eVisualType;
class VisualType {
public:
	typedef unsigned int Value;
	enum {
		Normal = 0x00,
		Indistinct = 0x01,
		Darken = 0x02,
		Shadowy = 0x03,
		Ripple = 0x04,
		Hidden = 0x05,
	};
};

typedef int eRadioCommands;

#define	rc_00		0
#define	rc_01		1
#define	rc_Hello		2
#define	rc_Exit		3
#define	rc_04		4
#define	rc_05		5
#define	rc_06		6
#define	rc_07		7
#define	rc_08		8
#define	rc_09		9
#define	rc_CannotEnter		10
#define	rc_0B		11
#define	rc_0C		12
#define	rc_0D		13
#define	rc_0E		14
#define	rc_CanEnter		15
#define	rc_10		16
#define	rc_11		17
#define	rc_12		18
#define	rc_NeedToMove		19
#define	rc_14		20
#define	rc_15		21
#define	rc_16		22
#define	rc_17		23
#define	rc_TryAcceptDocker		24
#define	rc_19		25
#define	rc_1A		26
#define	rc_1B		27
#define	rc_1C		28
#define	rc_1D		29
#define	rc_1E		30
#define	rc_1F		31
#define	rc_20		32
#define	rc_21		33
#define	rc_22		34
#define	rc_23		35
#define	rc_RadioWantRide		36


// networking
typedef int eNetworkEvents;

#define	netev_EMPTY		0x0
#define	netev_POWERON		0x1
#define	netev_POWEROFF		0x2
#define	netev_ALLY		0x3
#define	netev_MEGAMISSION		0x4
#define	netev_MEGAMISSION_F		0x5
#define	netev_IDLE		0x6
#define	netev_SCATTER		0x7
#define	netev_DESTRUCT		0x8
#define	netev_DEPLOY		0x9
#define	netev_DETONATE		0xA
#define	netev_PLACE		0xB
#define	netev_OPTIONS		0xC
#define	netev_GAMESPEED		0xD
#define	netev_PRODUCE		0xE
#define	netev_SUSPEND		0xF
#define	netev_ABANDON		0x10
#define	netev_PRIMARY		0x11
#define	netev_SPECIAL_PLACE		0x12
#define	netev_EXIT		0x13
#define	netev_ANIMATION		0x14
#define	netev_REPAIR		0x15
#define	netev_SELL		0x16
#define	netev_SELLCELL		0x17
#define	netev_SPECIAL		0x18
#define	netev_FRAMESYNC		0x19
#define	netev_MESSAGE		0x1A
#define	netev_RESPONSE_TIME		0x1B
#define	netev_FRAMEINFO		0x1C
#define	netev_SAVEGAME		0x1D
#define	netev_ARCHIVE		0x1E
#define	netev_ADDPLAYER		0x1F
#define	netev_TIMING		0x20
#define	netev_PROCESS_TIME		0x21
#define	netev_PAGEUSER		0x22
#define	netev_REMOVEPLAYER		0x23
#define	netev_LATENCYFUDGE		0x24
#define	netev_MEGAFRAMEINFO		0x25
#define	netev_PACKETTIMING		0x26
#define	netev_ABOUTTOEXIT		0x27
#define	netev_FALLBACKHOST		0x28
#define	netev_ADDRESSCHANGE		0x29
#define	netev_PLANCONNECT		0x2A
#define	netev_PLANCOMMIT		0x2B
#define	netev_PLANNODEDELETE		0x2C
#define	netev_ALLCHEER		0x2D
#define	netev_ABANDON_ALL		0x2E


// Sound specific
class SoundPriority {
public:
	typedef int Value;
	enum {
		Lowest = 0,
		Low = 1,
		Normal = 2,
		High = 3,
		Critical = 4
	};
};

class SoundType {
public:
	typedef unsigned int Value;
	enum {
		Normal = 0x0,
		Violent = 0x1,
		Movement = 0x2,
		Quiet = 0x4,
		Loud = 0x8,
		Global = 0x10,
		Screen = 0x20,
		Local = 0x40,
		Player = 0x80,
		NoiseShy = 0x100,
		GunShy = 0x200,
		Unshroud = 0x400,
		Shroud = 0x800,
		Ambient = 0x1000
	};
};

class SoundControl {
public:
	typedef unsigned int Value;
	enum {
		None = 0x0,
		Loop = 0x1,
		Random = 0x2,
		All = 0x4,
		Predelay = 0x8,
		Interrupt = 0x10,
		Attack = 0x20,
		Decay = 0x40,
		Ambient = 0x80
	};
};

class VoxType {
public:
	typedef int Value;
	enum {
		Standard = 0,
		Queue = 1,
		Interrupt = 2,
		QueuedInterrupt = 3
	};
};

class VoxPriority {
public:
	typedef int Value;
	enum {
		Low = 0,
		Normal = 1,
		Important = 2,
		Critical = 3
	};
};

typedef int eWaveType;

#define wave_Sonic 0x0
#define wave_Laser 0x1
#define wave_BigLaser 0x2
#define wave_Magnetron 0x3


class TargetType {
public:
	typedef unsigned int Value;
	enum {
		None = 0,
		Anything = 1,
		Buildings = 2,
		Harvesters = 3,
		Infantry = 4,
		Vehicles = 5,
		Factories = 6,
		BaseDefenses = 7,
		// unknown = 8,
		Power = 9,
		Occupiable = 10,
		TechBuildings = 11
	};
};


typedef int eTargetFlags;

#define	ttf_0x1		0x1
#define	ttf_0x2		0x2
#define	ttf_Air		0x4
#define	ttf_Infantry		0x8
#define	ttf_Vehicles		0x10
#define	ttf_Buildings		0x20
#define	ttf_Economy		0x40
#define	ttf_Ships		0x80 // from RA1
#define	ttf_Neutral		0x100 // from RA1
#define	ttf_Capture		0x200
#define	ttf_Fakes		0x400 // from RA1
#define	ttf_Power		0x800
#define	ttf_Factories		0x1000
#define	ttf_BaseDefense		0x2000
#define	ttf_Friendlies		0x4000
#define	ttf_Occupiable		0x8000
#define	ttf_TechCapture		0x10000

typedef int eBlitterFlags;

#define	bf_001		0x1
#define	bf_Alpha25		0x2
#define	bf_Alpha50		0x4
#define	bf_Warp		0x8
#define	bf_010		0x10
#define	bf_020		0x20
#define	bf_040		0x40
#define	bf_080		0x80
#define	bf_MultiPass		0x100
#define	bf_200		0x200
#define	bf_400		0x400
#define	bf_Alpha		0x800
#define	bf_1000		0x1000
#define	bf_2000		0x2000
#define	bf_4000		0x4000

// UI
class MouseEvent {
public:
	typedef unsigned char Value;
	enum {
		LeftDown = 0x1,
		LeftHeld = 0x2,
		LeftUp = 0x4,
		Move = 0x8,
		RightDown = 0x10,
		RightHeld = 0x20,
		RightUp = 0x40
	};
};

// typedef BYTE eMouseEventFlags;

//control key flags
typedef DWORD eControlKeyFlags;

#define ckf_SHIFT 0x01
#define ckf_CTRL 0x02
#define ckf_ALT 0x04


typedef int eEdge;

#define	edge_NORTH		0x00
#define	edge_EAST		0x01
#define	edge_SOUTH		0x02
#define	edge_WEST		0x03
#define	edge_AIR		0x04


class Move {
public:
	typedef int Value;
	enum {
		OK = 0,
		Cloak = 1,
		MovingBlock = 2,
		ClosedGate = 3,
		FriendlyDestroyable = 4,
		Destroyable = 5,
		Temp = 6,
		No = 7
	};
};

class ZGradient {
public:
	typedef int Value;
	enum {
		None = -1,
		Ground = 0,
		Deg45 = 1,
		Deg90 = 2,
		Deg135 = 3
	};
};

class ParasiteState {
public:
	typedef int Value;
	enum {
		Start = 0, // creates grab animation
		Grab = 1, // wait for the grab anim
		PushLeft = 2, // push the victim, variant A
		PushRight = 3, // push the victim, variant B
		Damage = 4 // wait until rocking stops; deliver damage
	};
};

//Westwood custom messages (e.g. for SendMessage)
#define	WW_SLIDER_GETVALUE			0x400

#define	WW_SLIDER_SETVALUE			0x405
#define	WW_SLIDER_SETRANGE			0x406

#define	WW_INITDIALOG				0x497
#define	WW_SETCOLOR					0x498

#define WW_BLITDDS					0x4A8 //lParam is some structure

#define	WW_STATIC_SETTEXT			0x4B2

#define WW_CB_GETITEMINDEX			0x4BE //wParam = 0; lParam = wchar_t* text;

#define	WW_CB_ADDITEM				0x4C2 //wParam = int index; lParam = 0

#define	WW_LB_ADDITEM				0x4CD

#endif
