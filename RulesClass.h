#pragma once

#include <ArrayClasses.h>
#include <GeneralDefinitions.h>

//forward declarations
class AbstractClass;
class AircraftTypeClass;
class AnimTypeClass;
class BuildingTypeClass;
class BulletTypeClass;
class CCINIClass;
class InfantryTypeClass;
class OverlayTypeClass;
class ParticleSystemTypeClass;
class SmudgeTypeClass;
class TerrainTypeClass;
class UnitTypeClass;
class VoxelAnimTypeClass;
class WarheadTypeClass;
class WeaponTypeClass;

struct SHPStruct;

//Difficulty
struct DifficultyStruct
{
	double Firepower;
	double GroundSpeed;
	double AirSpeed;
	double Armor;
	double ROF;
	double Cost;
	double BuildTime;
	double RepairDelay;
	double BuildDelay;
	bool BuildSlowdown;
	bool DestroyWalls;
	bool ContentScan;
	PROTECTED_PROPERTY(BYTE, unused_4B[0x5]);
};

//Rockets
struct RocketStruct
{
	int PauseFrames;
	int TiltFrames;
	float PitchInitial;
	float PitchFinal;
	float TurnRate;
	int RaiseRate; //shouldn't this be a float? prolly a mistake by WW...
	float Acceleration;
	int Altitude;
	int Damage;
	int EliteDamage;
	int BodyLength;
	bool LazyCurve;
	AircraftTypeClass* Type;

	RocketStruct() noexcept :
		PauseFrames(0),
		TiltFrames(0),
		PitchInitial(0.0f),
		PitchFinal(0.0f),
		TurnRate(0.0f),
		RaiseRate(0),
		Acceleration(0.0f),
		Altitude(0),
		Damage(0),
		EliteDamage(0),
		BodyLength(0),
		LazyCurve(false),
		Type(nullptr)
	{ }

	explicit RocketStruct(noinit_t) noexcept
	{ }
};

class RulesClass
{
public:
	//Static
	static RulesClass *&Instance;

	static RulesClass* Global()
		{ return *reinterpret_cast<RulesClass**>(0x8871E0); }

//	static bool Initialized;

	// call this for the first INI file only
	void Init(CCINIClass *pINI)
		{ JMP_THIS(0x6686C0); }

	// call this instead of Init for the later files (gamemode, map)
	// reads the generic/list sections like [VehicleTypes] from pINI
	// doesn't actually load [MTNK] or other list contents' sections
	void Read_File(CCINIClass *pINI)
		{ JMP_THIS(0x668BF0); }

	void Read_SpecialWeapons(CCINIClass *pINI)
		{ JMP_THIS(0x668FB0); }

	void Read_AudioVisual(CCINIClass *pINI)
		{ JMP_THIS(0x6691E0); }

	void Read_CrateRules(CCINIClass *pINI)
		{ JMP_THIS(0x66B900); }

	void Read_CombatDamage(CCINIClass *pINI)
		{ JMP_THIS(0x66BBB0); }

	void Read_Radiation(CCINIClass *pINI)
		{ JMP_THIS(0x66CF70); }

	void Read_ElevationModel(CCINIClass *pINI)
		{ JMP_THIS(0x66D150); }

	void Read_WallModel(CCINIClass *pINI)
		{ JMP_THIS(0x66D1F0); }

	void Read_Difficulty(CCINIClass *pINI)
		{ JMP_THIS(0x66D270); }

	void Read_Colors(CCINIClass *pINI)
		{ JMP_THIS(0x66D3A0); }

	void Read_ColorAdd(CCINIClass *pINI)
		{ JMP_THIS(0x66D480); }

	void Read_General(CCINIClass *pINI)
		{ JMP_THIS(0x66D530); }

	void Read_MultiplayerDialogSettings(CCINIClass *pINI)
		{ JMP_THIS(0x671EA0); }

	void Read_Maximums(CCINIClass *pINI)
		{ JMP_THIS(0x672230); }

	void Read_InfantryTypes(CCINIClass *pINI)
		{ JMP_THIS(0x672280); }

	void Read_Countries(CCINIClass *pINI)
		{ JMP_THIS(0x6722F0); }

	void Read_VehicleTypes(CCINIClass *pINI)
		{ JMP_THIS(0x672360); }

	void Read_AircraftTypes(CCINIClass *pINI)
		{ JMP_THIS(0x6723D0); }

	void Read_Sides(CCINIClass *pINI)
		{ JMP_THIS(0x672440); }

	void Read_SuperWeaponTypes(CCINIClass *pINI)
		{ JMP_THIS(0x6725F0); }

	void Read_BuildingTypes(CCINIClass *pINI)
		{ JMP_THIS(0x672660); }

	void Read_TerrainTypes(CCINIClass *pINI)
		{ JMP_THIS(0x6726D0); }

	void Read_Teams_obsolete(CCINIClass *pINI)
		{ JMP_THIS(0x672740); }

	void Read_SmudgeTypes(CCINIClass *pINI)
		{ JMP_THIS(0x6727D0); }

	void Read_OverlayTypes(CCINIClass *pINI)
		{ JMP_THIS(0x672840); }

	void Read_Animations(CCINIClass *pINI)
		{ JMP_THIS(0x6728B0); }

	void Read_VoxelAnims(CCINIClass *pINI)
		{ JMP_THIS(0x672920); }

	void Read_Warheads(CCINIClass *pINI)
		{ JMP_THIS(0x672990); }

	void Read_Particles(CCINIClass *pINI)
		{ JMP_THIS(0x672A00); }

	void Read_ParticleSystems(CCINIClass *pINI)
		{ JMP_THIS(0x672A70); }

	void Read_AI(CCINIClass *pINI)
		{ JMP_THIS(0x672AE0); }

	void Read_Powerups(CCINIClass *pINI)
		{ JMP_THIS(0x673E80); }

	void Read_LandCharacteristics(CCINIClass *pINI)
		{ JMP_THIS(0x674000); }

	void Read_IQ(CCINIClass *pINI)
		{ JMP_THIS(0x674240); }

	void Read_JumpjetControls(CCINIClass *pINI)
		{ JMP_THIS(0x6743D0); }

	void Read_Difficulties(CCINIClass *pINI)
		{ JMP_THIS(0x674500); }

	void Read_Movies(CCINIClass *pINI)
		{ JMP_THIS(0x674550); }

	void Read_AdvancedCommandBar(CCINIClass *pINI)
		{ JMP_THIS(0x674650); }

	void PointerGotInvalid(AbstractClass* pInvalid, bool removed)
		{ JMP_THIS(0x678850); }


	//CTOR / DTOR
protected:
	RulesClass() JMP_THIS(0x665650);
	~RulesClass() JMP_THIS(0x667A30);

	//Properties

public:

	int				 DetailMinFrameRateNormal;
	int				 DetailMinFrameRateMovie;
	int				 DetailBufferZoneWidth;
	int				 AmmoCrateDamage;
	UnitTypeClass*			 LargeVisceroid;
	UnitTypeClass*			 SmallVisceroid;
	int				 AttackingAircraftSightRange;
	DWORD align_1C;
	double			 TunnelSpeed;
	double			 TiberiumHeal;
	int				 SelfHealInfantryFrames;
	int				 SelfHealInfantryAmount;
	int				 SelfHealUnitFrames;
	int				 SelfHealUnitAmount;
	bool				 FreeMCV;
	bool				 BerzerkAllowed;
	int				 PoseDir;
	int				 DeployDir;
	AnimTypeClass*			 DropPodPuff;
	int				 WaypointAnimationSpeed;
	AnimTypeClass*			 BarrelExplode;
	TypeList<VoxelAnimTypeClass*>	 BarrelDebris;
	ParticleSystemTypeClass*		 BarrelParticle;
	float				 RadarEventColorSpeed;
	int				 RadarEventMinRadius;
	float				 RadarEventSpeed;
	float				 RadarEventRotationSpeed;
	int				 FlashFrameTime;
	int				 RadarCombatFlashTime;
	int				 MaxWaypointPathLength;
	AnimTypeClass*			 Wake;
	AnimTypeClass*			 NukeTakeOff;
	AnimTypeClass*			 InfantryExplode;
	AnimTypeClass*			 FlamingInfantry;
	AnimTypeClass*			 InfantryHeadPop;
	AnimTypeClass*			 InfantryNuked;
	AnimTypeClass*			 InfantryVirus;
	AnimTypeClass*			 InfantryBrute;
	AnimTypeClass*			 InfantryMutate;
	AnimTypeClass*			 Behind;
	DWORD align_BC;
	double			 AITriggerSuccessWeightDelta;
	double			 AITriggerFailureWeightDelta;
	double			 AITriggerTrackRecordCoefficient;
	int				 VeinholeMonsterStrength;
	int				 MaxVeinholeGrowth;
	int				 VeinholeGrowthRate;
	int				 VeinholeShrinkRate;
	AnimTypeClass*			 VeinAttack;
	int				 VeinDamage;
	int				 MaximumQueuedObjects;
	int				 AircraftFogReveal;
	OverlayTypeClass*			 WoodCrateImg;
	OverlayTypeClass*			 CrateImg;
	OverlayTypeClass*			 WaterCrateImg;
	TypeList<AnimTypeClass*>		 DropPod;
	TypeList<AnimTypeClass*>		 DeadBodies;
	TypeList<AnimTypeClass*>		 MetallicDebris;
	TypeList<AnimTypeClass*>		 BridgeExplosions;
	int				 DigSound;
	int				 CreateUnitSound;
	int				 CreateInfantrySound;
	int				 CreateAircraftSound;
	int				 BaseUnderAttackSound;
	int				 GUIMainButtonSound;
	int				 GUIBuildSound;
	int				 GUITabSound;
	int				 GUIOpenSound;
	int				 GUICloseSound;
	int				 GUIMoveOutSound;
	int				 GUIMoveInSound;
	int				 GUIComboOpenSound;
	int				 GUIComboCloseSound;
	int				 GUICheckboxSound;
	int				 ScoreAnimSound;
	int				 IFVTransformSound;
	int				 PsychicSensorDetectSound;
	int				 BuildingGarrisonedSound;
	int				 BuildingAbandonedSound;
	int				 BuildingRepairedSound;
	int				 CheerSound;
	int				 PlaceBeaconSound;
	int				 DefaultChronoSound;
	int				 StartPlanningModeSound;
	int				 AddPlanningModeCommandSound;
	int				 ExecutePlanSound;
	int				 EndPlanningModeSound;
	int				 CrateMoneySound;
	int				 CrateRevealSound;
	int				 CrateFireSound;
	int				 CrateArmourSound;
	int				 CrateSpeedSound;
	int				 CrateUnitSound;
	int				 CratePromoteSound;
	int				 ImpactWaterSound;
	int				 ImpactLandSound;
	int				 SinkingSound;
	int				 BombTickingSound;
	int				 BombAttachSound;
	int				 YuriMindControlSound;
	int				 ChronoInSound;
	int				 ChronoOutSound;
	int				 SpySatActivationSound;
	int				 SpySatDeactivationSound;
	int				 UpgradeVeteranSound;
	int				 UpgradeEliteSound;
	int				 VoiceIFVRepair;
	int				 SlavesFreeSound;
	int				 SlaveMinerDeploySound;
	int				 SlaveMinerUndeploySound;
	int				 BunkerWallsUpSound;
	int				 BunkerWallsDownSound;
	int				 RepairBridgeSound;
	int				 PsychicDominatorActivateSound;
	int				 GeneticMutatorActivateSound;
	int				 PsychicRevealActivateSound;
	int				 MasterMindOverloadDeathSound;
	int				 AirstrikeAbortSound;
	int				 AirstrikeAttackVoice;
	int				 MindClearedSound;
	int				 EnterGrinderSound;
	int				 LeaveGrinderSound;
	int				 EnterBioReactorSound;
	int				 LeaveBioReactorSound;
	int				 ActivateSound;
	int				 DeactivateSound;
	int				 SpyPlaneCamera;
	int				 LetsDoTheTimeWarpOutAgain;
	int				 LetsDoTheTimeWarpInAgain;
	int				 DiskLaserChargeUp;
	int				 SpyPlaneCameraFrames;
	AnimTypeClass*			 Dig;
	AnimTypeClass*			 IonBlast;
	AnimTypeClass*			 IonBeam;
	TypeList<AnimTypeClass*>		 DamageFireTypes;
	TypeList<AnimTypeClass*>		 WeatherConClouds;
	TypeList<AnimTypeClass*>		 WeatherConBolts;
	AnimTypeClass*			 WeatherConBoltExplosion;
	WarheadTypeClass*			 DominatorWarhead;
	AnimTypeClass*			 DominatorFirstAnim;
	AnimTypeClass*			 DominatorSecondAnim;
	int				 DominatorFireAtPercentage;
	int				 DominatorCaptureRange;
	int				 DominatorDamage;
	int				 MindControlAttackLineFrames;
	int				 DrainMoneyFrameDelay;
	int				 DrainMoneyAmount;
	AnimTypeClass*			 DrainAnimationType;
	AnimTypeClass*			 ControlledAnimationType;
	AnimTypeClass*			 PermaControlledAnimationType;
	AnimTypeClass*			 ChronoBlast;
	AnimTypeClass*			 ChronoBlastDest;
	AnimTypeClass*			 ChronoPlacement;
	AnimTypeClass*			 ChronoBeam;
	AnimTypeClass*			 WarpIn;
	AnimTypeClass*			 WarpOut;
	AnimTypeClass*			 WarpAway;
	AnimTypeClass*			 ChronoSparkle1;
	AnimTypeClass*			 IronCurtainInvokeAnim;
	AnimTypeClass*			 ForceShieldInvokeAnim;
	AnimTypeClass*			 WeaponNullifyAnim;
	AnimTypeClass*			 AtmosphereEntry;
	TypeList<int >		 PrerequisitePower;
	TypeList<int >		 PrerequisiteFactory;
	TypeList<int >		 PrerequisiteBarracks;
	TypeList<int >		 PrerequisiteRadar;
	TypeList<int >		 PrerequisiteTech;
	TypeList<int >		 PrerequisiteProc;
	UnitTypeClass*	 PrerequisiteProcAlternate;
	int				 GateUp;
	int				 GateDown;
	int				 TurnRate;
	int				 Speed;
	DWORD align_414;
	double			 Climb;
	int				 CruiseHeight;
	DWORD align_424;
	double			 Acceleration;
	double			 WobblesPerSecond;
	int				 WobbleDeviation;
	TypeList<int >		 RadarEventSuppressionDistances;
	TypeList<int >		 RadarEventVisibilityDurations;
	TypeList<int >		 RadarEventDurations;
	int				 IonCannonDamage;
	int				 RailgunDamageRadius;
	BuildingTypeClass*		 PrismType;
	int		PrismSupportModifier; // this is int(100 * ini value)
	int				 PrismSupportMax;
	int				 PrismSupportDelay;
	int				 PrismSupportDuration;
	int				 PrismSupportHeight;
	/*
	int				 V3RocketPauseFrames;
	int				 V3RocketTiltFrames;
	float				 V3RocketPitchInitial;
	float				 V3RocketPitchFinal;
	float				 V3RocketTurnRate;
	float				 V3RocketRaiseRate;
	float				 V3RocketAcceleration;
	int				 V3RocketAltitude;
	int				 V3RocketDamage;
	int				 V3RocketEliteDamage;
	int				 V3RocketBodyLength;
	bool				 V3RocketLazyCurve;
	AircraftTypeClass*		 V3RocketType;
	int				 DMislPauseFrames;
	int				 DMislTiltFrames;
	float				 DMislPitchInitial;
	float				 DMislPitchFinal;
	float				 DMislTurnRate;
	float				 DMislRaiseRate;
	float				 DMislAcceleration;
	int				 DMislAltitude;
	int				 DMislDamage;
	int				 DMislEliteDamage;
	int				 DMislBodyLength;
	bool				 DMislLazyCurve;
	AircraftTypeClass*		 DMislType;
	int				 CMislPauseFrames;
	int				 CMislTiltFrames;
	float				 CMislPitchInitial;
	float				 CMislPitchFinal;
	float				 CMislTurnRate;
	float				 CMislRaiseRate;
	float				 CMislAcceleration;
	int				 CMislAltitude;
	int				 CMislDamage;
	int				 CMislEliteDamage;
	int				 CMislBodyLength;
	bool				 CMislLazyCurve;
	AircraftTypeClass*		 CMislType;
	*/
	RocketStruct V3Rocket;
	RocketStruct DMisl;
	RocketStruct CMisl;
	int				 ParadropRadius;
	double			 ZoomInFactor;
	double			 ConditionRedSparkingProbability;
	double			 ConditionYellowSparkingProbability;
	int				 TiberiumExplosionDamage;
	int				 TiberiumStrength;
	float				 MinLowPowerProductionSpeed;
	float				 MaxLowPowerProductionSpeed;
	float				 LowPowerPenaltyModifier;
	float				 MultipleFactory;
	int				 MaximumCheerRate;
	DWORD align_584;
	double			 TreeFlammability;
	double			 MissileSpeedVar;
	double			 MissileROTVar;
	int				 MissileSafetyAltitude;
	WeaponTypeClass*			 DropPodWeapon;
	int				 DropPodHeight;
	int				 DropPodSpeed;
	double			 DropPodAngle;
	double			 ScrollMultiplier;
	double			 CrewEscape;
	int				 ShakeScreen;
	int				 HoverHeight;
	double			 HoverBob;
	double			 HoverBoost;
	double			 HoverAcceleration;
	double			 HoverBrake;
	double			 HoverDampen;
	double			 PlacementDelay;
	TypeList<VoxelAnimTypeClass*>	 ExplosiveVoxelDebris;
	VoxelAnimTypeClass*		 TireVoxelDebris;
	VoxelAnimTypeClass*		 ScrapVoxelDebris;
	int				 BridgeVoxelMax;
	int				 CloakingStages;
	int				 RevealTriggerRadius;
	double			 ShipSinkingWeight;
	double			 IceCrackingWeight;
	double			 IceBreakingWeight;
	TypeList<int >		 IceCrackSounds;
	byte				 CliffBackImpassability;
	double			 VeteranRatio;
	double			 VeteranCombat;
	double			 VeteranSpeed;
	double			 VeteranSight;
	double			 VeteranArmor;
	double			 VeteranROF;
	double			 VeteranCap;
	int				 CloakSound;
	int				 SellSound;
	int				 GameClosed;
	int				 IncomingMessage;
	int				 SystemError;
	int				 OptionsChanged;
	int				 GameForming;
	int				 PlayerLeft;
	int				 PlayerJoined;
	int				 MessageCharTyped;
	int				 Construction;
	TypeList<int >		 CreditTicks;
	int				 BuildingDieSound;
	int				 BuildingSlam;
	int				 RadarOn;
	int				 RadarOff;
	int				 MovieOn;
	int				 MovieOff;
	int				 ScoldSound;
	int				 TeslaCharge;
	int				 TeslaZap;
	int				 GenericClick;
	int				 GenericBeep;
	int				 BuildingDamageSound;
	int				 HealCrateSound; // also "healing unit" sound, old hospital mode
	int				 ChuteSound;
	int				 StopSound;
	int				 GuardSound;
	int				 ScatterSound;
	int				 DeploySound;		//TS leftover! Never read from the INI.
	int				 StormSound;
	TypeList<int >		 LightningSounds;
	int				 ShellButtonSlideSound;
	DWORD align_754;
	double			 WallBuildSpeedCoefficient;
	double			 ChargeToDrainRatio;
	double			 TrackedUphill;
	double			 TrackedDownhill;
	double			 WheeledUphill;
	double			 WheeledDownhill;
	int				 SpotlightMovementRadius;
	int				 SpotlightLocationRadius;
	double			 SpotlightSpeed;
	double			 SpotlightAcceleration;
	double			 SpotlightAngle;
	int				 SpotlightRadius;
	int				 WindDirection;
	int				 CameraRange;
	int				 FlightLevel;
	int				 ParachuteMaxFallRate;
	int				 NoParachuteMaxFallRate;
	int				 BuildingDrop;
	TypeList<SmudgeTypeClass*>	 Scorches;
	TypeList<SmudgeTypeClass*>	 Scorches1;
	TypeList<SmudgeTypeClass*>	 Scorches2;
	TypeList<SmudgeTypeClass*>	 Scorches3;
	TypeList<SmudgeTypeClass*>	 Scorches4;
	TypeList<BuildingTypeClass*>	 RepairBay;
	BuildingTypeClass*		 GDIGateOne;
	BuildingTypeClass*		 GDIGateTwo;
	BuildingTypeClass*		 NodGateOne;
	BuildingTypeClass*		 NodGateTwo;
	BuildingTypeClass*		 WallTower;
	TypeList<BuildingTypeClass*>	 Shipyard;
	BuildingTypeClass*		 GDIPowerPlant;
	BuildingTypeClass*		 NodRegularPower;
	BuildingTypeClass*		 NodAdvancedPower;
	BuildingTypeClass*		 ThirdPowerPlant;
	TypeList<BuildingTypeClass*>	 BuildConst;
	TypeList<BuildingTypeClass*>	 BuildPower;
	TypeList<BuildingTypeClass*>	 BuildRefinery;
	TypeList<BuildingTypeClass*>	 BuildBarracks;
	TypeList<BuildingTypeClass*>	 BuildTech;
	TypeList<BuildingTypeClass*>	 BuildWeapons;
	TypeList<BuildingTypeClass*>	 AlliedBaseDefenses;
	TypeList<BuildingTypeClass*>	 SovietBaseDefenses;
	TypeList<BuildingTypeClass*>	 ThirdBaseDefenses;
	TypeList<int >		 AIForcePredictionFudge;
	TypeList<BuildingTypeClass*>	 BuildDefense;
	TypeList<BuildingTypeClass*>	 BuildPDefense;
	TypeList<BuildingTypeClass*>	 BuildAA;
	TypeList<BuildingTypeClass*>	 BuildHelipad;
	TypeList<BuildingTypeClass*>	 BuildRadar;
	TypeList<BuildingTypeClass*>	 ConcreteWalls;
	TypeList<BuildingTypeClass*>	 NSGates;
	TypeList<BuildingTypeClass*>	 EWGates;
	TypeList<BuildingTypeClass*>	 BuildNavalYard;
	TypeList<BuildingTypeClass*>	 BuildDummy;
	TypeList<BuildingTypeClass*>	 NeutralTechBuildings;
	double			 GDIWallDefense;
	double			 GDIWallDefenseCoefficient;
	double			 NodBaseDefenseCoefficient;
	double			 GDIBaseDefenseCoefficient;
	int				 ComputerBaseDefenseResponse;
	int				 MaximumBaseDefenseValue;
	TypeList<UnitTypeClass*>		 BaseUnit;
	TypeList<UnitTypeClass*>		 HarvesterUnit;
	TypeList<AircraftTypeClass*>	 PadAircraft;
	TypeList<AnimTypeClass*>		 OnFire;
	TypeList<AnimTypeClass*>		 TreeFire;
	AnimTypeClass*			 Smoke;
	AnimTypeClass*			 Smoke_;	//exists twice
	AnimTypeClass*			 MoveFlash;
	AnimTypeClass*			 BombParachute;
	AnimTypeClass*			 Parachute;
	TypeList<AnimTypeClass*>		 SplashList;
	AnimTypeClass*			 SmallFire;
	AnimTypeClass*			 LargeFire;
	InfantryTypeClass*		 Paratrooper;
	int				 EliteFlashTimer;
	int				 ChronoDelay;
	int				 ChronoReinfDelay;
	int				 ChronoDistanceFactor;
	bool				 ChronoTrigger;
	int				 ChronoMinimumDelay;
	int				 ChronoRangeMinimum;
	TypeList<InfantryTypeClass*>	 AmerParaDropInf;
	TypeList<int >		 AmerParaDropNum;
	TypeList<InfantryTypeClass*>	 AllyParaDropInf;
	TypeList<int >		 AllyParaDropNum;
	TypeList<InfantryTypeClass*>	 SovParaDropInf;
	TypeList<int >		 SovParaDropNum;
	TypeList<InfantryTypeClass*>	 YuriParaDropInf;
	TypeList<int >		 YuriParaDropNum;
	TypeList<InfantryTypeClass*>	 AnimToInfantry;
	TypeList<InfantryTypeClass*>	 SecretInfantry;
	TypeList<UnitTypeClass*>		 SecretUnits;
	TypeList<BuildingTypeClass*>	 SecretBuildings;
	int				 SecretSum;
	InfantryTypeClass*		 AlliedDisguise;
	InfantryTypeClass*		 SovietDisguise;
	InfantryTypeClass*		 ThirdDisguise;
	int				 SpyPowerBlackout;
	float				 SpyMoneyStealPercent;
	bool				 AttackCursorOnDisguise;
	float				 AIMinorSuperReadyPercent;
	int				 AISafeDistance;
	int				 HarvesterTooFarDistance;
	int				 ChronoHarvTooFarDistance;
	TypeList<int >		 AlliedBaseDefenseCounts;
	TypeList<int >		 SovietBaseDefenseCounts;
	TypeList<int >		 ThirdBaseDefenseCounts;
	TypeList<int >		 AIPickWallDefensePercent;
	int				 AIRestrictReplaceTime;
	int				 ThreatPerOccupant;
	int				 ApproachTargetResetMultiplier;
	int				 CampaignMoneyDeltaEasy;
	int				 CampaignMoneyDeltaHard;
	int				 GuardAreaTargetingDelay;
	int				 NormalTargetingDelay;
	int				 AINavalYardAdjacency;
	TypeList<int >		 DisabledDisguiseDetectionPercent;
	TypeList<int >		 AIAutoDeployFrameDelay;
	int				 MaximumBuildingPlacementFailures;
	TypeList<int >		 AICaptureNormal;
	TypeList<int >		 AICaptureWounded;
	TypeList<int >		 AICaptureLowPower;
	TypeList<int >		 AICaptureLowMoney;
	int				 AICaptureLowMoneyMark;
	int				 AICaptureWoundedMark;
	TypeList<int >		 AISuperDefenseProbability;
	int				 AISuperDefenseFrames;
	float				 AISuperDefenseDistance;
	TypeList<int >		 OverloadCount;
	TypeList<int >		 OverloadDamage;
	TypeList<int >		 OverloadFrames;
	float				 PurifierBonus;
	float				 OccupyDamageMultiplier;
	float				 OccupyROFMultiplier;
	int				 OccupyWeaponRange;
	int				 BunkerDamageMultiplier;
	float				 BunkerROFMultiplier;
	int				 BunkerWeaponRangeBonus;
	float				 OpenToppedDamageMultiplier;
	int				 OpenToppedRangeBonus;
	int				 OpenToppedWarpDistance;
	float				 FallingDamageMultiplier;
	bool				 CurrentStrengthDamage;
	InfantryTypeClass*		 Technician;
	InfantryTypeClass*		 Engineer;
	InfantryTypeClass*		 Pilot;
	InfantryTypeClass*		 AlliedCrew;
	InfantryTypeClass*		 SovietCrew;
	InfantryTypeClass*		 ThirdCrew;
	WarheadTypeClass*			 FlameDamage;
	WarheadTypeClass*			 FlameDamage2;
	WarheadTypeClass*			 NukeWarhead;
	BulletTypeClass*			 NukeProjectile;
	BulletTypeClass*			 NukeDown;
	WarheadTypeClass*			 MutateWarhead;
	WarheadTypeClass*			 MutateExplosionWarhead;
	WarheadTypeClass*			 EMPulseWarhead;
	WarheadTypeClass*			 EMPulseProjectile;
	WarheadTypeClass*			 C4Warhead;
	WarheadTypeClass*			 CrushWarhead;
	WarheadTypeClass*			 V3Warhead;
	WarheadTypeClass*			 DMislWarhead;
	WarheadTypeClass*			 V3EliteWarhead;
	WarheadTypeClass*			 DMislEliteWarhead;
	WarheadTypeClass*			 CMislWarhead;
	WarheadTypeClass*			 CMislEliteWarhead;
	WarheadTypeClass*			 IvanWarhead;
	int				 IvanDamage;
	int				 IvanTimedDelay;
	bool				 CanDetonateTimeBomb;
	bool				 CanDetonateDeathBomb;
	int				 IvanIconFlickerRate;
	WeaponTypeClass*			 DeathWeapon;
	SHPStruct*				 BOMBCURS_SHP;
	SHPStruct*				 CHRONOSK_SHP;
	int				 IronCurtainDuration;
	int				 PsychicRevealRadius;
	WarheadTypeClass*			 IonCannonWarhead;
	TerrainTypeClass*			 VeinholeTypeClass;
	TypeList<TerrainTypeClass*>	 DefaultMirageDisguises;
	int				 InfantryBlinkDisguiseTime;
	ParticleSystemTypeClass*		 DefaultLargeGreySmokeSystem;
	ParticleSystemTypeClass*		 DefaultSmallGreySmokeSystem;
	ParticleSystemTypeClass*		 DefaultSparkSystem;
	ParticleSystemTypeClass*		 DefaultLargeRedSmokeSystem;
	ParticleSystemTypeClass*		 DefaultSmallRedSmokeSystem;
	ParticleSystemTypeClass*		 DefaultDebrisSmokeSystem;
	ParticleSystemTypeClass*		 DefaultFireStreamSystem;
	ParticleSystemTypeClass*		 DefaultTestParticleSystem;
	ParticleSystemTypeClass*		 DefaultRepairParticleSystem;
	DWORD align_103C;
	double			 MyEffectivenessCoefficientDefault;
	double			 TargetEffectivenessCoefficientDefault;
	double			 TargetSpecialThreatCoefficientDefault;
	double			 TargetStrengthCoefficientDefault;
	double			 TargetDistanceCoefficientDefault;
	double			 DumbMyEffectivenessCoefficient;
	double			 DumbTargetEffectivenessCoefficient;
	double			 DumbTargetSpecialThreatCoefficient;
	double			 DumbTargetStrengthCoefficient;
	double			 DumbTargetDistanceCoefficient;
	double			 EnemyHouseThreatBonus;
	double			 TurboBoost;
	double			 AttackInterval;
	double			 AttackDelay;
	double			 PowerEmergency;
	double			 AirstripRatio;
	int				 AirstripLimit;
	DWORD align_10C4;
	double			 HelipadRatio;
	int				 HelipadLimit;
	DWORD align_10D4;
	double			 TeslaRatio;
	int				 TeslaLimit;
	DWORD align_10E4;
	double			 AARatio;
	int				 AALimit;
	DWORD align_10F4;
	double			 DefenseRatio;
	int				 DefenseLimit;
	DWORD align_1104;
	double			 WarRatio;
	int				 WarLimit;
	DWORD align_1114;
	double			 BarracksRatio;
	int				 BarracksLimit;
	int				 RefineryLimit;
	double			 RefineryRatio;
	int				 BaseSizeAdd;
	int				 PowerSurplus;
	int				 InfantryReserve;
	int				 InfantryBaseMult;
	int				 SoloCrateMoney;
	int				 TreeStrength;
	UnitTypeClass*			 UnitCrateType;
	DWORD align_114C;
	double			 PatrolScan;
	TypeList<int >		 TeamDelays;
	TypeList<int >		 AIHateDelays;
	int				 DissolveUnfilledTeamDelay;
	TypeList<int >		 AIIonCannonConYardValue;
	TypeList<int >		 AIIonCannonWarFactoryValue;
	TypeList<int >		 AIIonCannonPowerValue;
	TypeList<int >		 AIIonCannonTechCenterValue;
	TypeList<int >		 AIIonCannonEngineerValue;
	TypeList<int >		 AIIonCannonThiefValue;
	TypeList<int >		 AIIonCannonHarvesterValue;
	TypeList<int >		 AIIonCannonMCVValue;
	TypeList<int >		 AIIonCannonAPCValue;
	TypeList<int >		 AIIonCannonBaseDefenseValue;
	TypeList<int >		 AIIonCannonPlugValue;
	TypeList<int >		 AIIonCannonHelipadValue;
	TypeList<int >		 AIIonCannonTempleValue;
	int				 AIAlternateProductionCreditCutoff;
	TypeList<int >		 MultiplayerAICM;
	TypeList<int >		 AIVirtualPurifiers;
	TypeList<int >		 AISlaveMinerNumber;
	TypeList<int >		 HarvestersPerRefinery;
	TypeList<int >		 AIExtraRefineries;
	TypeList<int >		 MinimumAIDefensiveTeams;
	TypeList<int >		 MaximumAIDefensiveTeams;
	TypeList<int >		 TotalAITeamCap;
	DWORD align_13E4;
	double			 AIUseTurbineUpgradeProbability;
	TypeList<int >		 FillEarliestTeamProbability;
	DWORD align_140C;
	double			 CloakDelay;
	double			 GameSpeedBias;
	double			 BaseBias;
	double			 ExpSpread;
	int				 FireSupress;
	int				 MaxIQLevels;
	int				 SuperWeapons;
	int				 Production;
	int				 GuardArea;
	int				 RepairSell;
	int				 AutoCrush;
	int				 Scatter;
	int				 ContentScan;
	int				 Aircraft;
	int				 Harvester;
	int				 SellBack;
	int				 AIBaseSpacing;
	Powerup			 SilverCrate;
	Powerup			 WoodCrate;
	Powerup			 WaterCrate;
	int				 CrateMinimum;
	int				 CrateMaximum;
	int				 unknown_int_1478;	//defaults to 0x2000
	AnimTypeClass*			 DropZoneAnim;
	int				 MinMoney;
	int				 Money;
	int				 MaxMoney;
	int				 MoneyIncrement;
	int				 MinUnitCount;
	int				 UnitCount;
	int				 MaxUnitCount;
	int				 TechLevel;
	int				 GameSpeed;
	int				 AIDifficultyStruct;
	int				 AIPlayers;
	bool				 BridgeDestruction;
	bool				 ShadowGrow;
	bool				 Shroud;
	bool				 Bases;
	bool				 TiberiumGrows;
	bool				 Crates;
	bool				 CaptureTheFlag;
	bool				 HarvesterTruce;
	bool				 MultiEngineer;
	bool				 AlliesAllowed;
	bool				 ShortGame;
	bool				 FogOfWar;
	bool				 MCVRedeploys;
	bool				 SuperWeaponsAllowed;
	bool				 BuildOffAlly;
	bool				 AllyChangeAllowed;
	int				 DropZoneRadius;
	double			 MessageDelay;
	double			 SavourDelay;
	int				 Players;
	DWORD align_14D4;
	double			 BaseDefenseDelay;
	int				 SuspendPriority;
	DWORD align_14E4;
	double			 SuspendDelay;
	double			 SurvivorRate;
	int				 AlliedSurvivorDivisor;
	int				 SovietSurvivorDivisor;
	int				 ThirdSurvivorDivisor;
	DWORD align_1504;
	double			 ReloadRate;
	double			 AutocreateTime;
	double			 BuildupTime;
	int				 HarvesterLoadRate;
	DWORD align_1524;
	double			 HarvesterDumpRate;
	int				 AtomDamage;
	DWORD align_1534;
	DifficultyStruct			 Easy;
	DifficultyStruct			 Normal;
	DifficultyStruct			 Difficult;
	DWORD align_1628[4];
	double			 GrowthRate;
	double			 ShroudRate;
	double			 FogRate;
	double			 IceGrowthRate;
	double			 VeinGrowthRate;
	int				 IceSolidifyFrameTime;
	DWORD align_1664;
	double			 AmbientChangeRate;
	double			 AmbientChangeStep;
	double			 CrateRegen;
	double			 TimerWarning;
	int				 TiberiumTransmogrify;
	DWORD align_168C;
	double			 unknown_double_1690;	//2.6875
	double			 unknown_double_1698;	//2.3125
	double			 unknown_double_16A0;	//2.5625
	double			 SpeakDelay;
	double			 DamageDelay;
	int				 Gravity;
	int				 LeptonsPerSightIncrease;
	int				 Incoming;
	int				 MinDamage;
	int				 MaxDamage;
	int				 RepairStep;
	double			 RepairPercent;
	int				 IRepairStep;
	DWORD align_16DC;
	double			 RepairRate;
	double			 URepairRate;
	double			 IRepairRate;
	double			 unknown_double_16F8;	//1.875
	double			 ConditionYellow;
	double			 ConditionRed;
	double			 IdleActionFrequency;
	int				 CloseEnough;
	int				 Stray;
	int				 RelaxedStray;
	int				 GuardModeStray;
	int				 Crush;
	int				 CrateRadius;
	int				 HomingScatter;
	int				 BallisticScatter;
	double			 RefundPercent;
	int				 BridgeStrength;
	DWORD align_1744;
	double			 BuildSpeed;
	double			 C4Delay;
	int				 CreditReserve;
	DWORD align_175C;
	double			 PathDelay;
	int				 BlockagePathDelay;
	DWORD align_176C;
	double			 MovieTime;
	int				 TiberiumShortScan;
	int				 TiberiumLongScan;
	int				 SlaveMinerShortScan;
	int				 SlaveMinerSlaveScan;
	int				 SlaveMinerLongScan;
	int				 SlaveMinerScanCorrection;
	int				 SlaveMinerKickFrameDelay;
	int				 LightningDeferment;
	int				 LightningDamage;
	int				 LightningStormDuration;
	int				 LightningHitDelay;
	int				 LightningScatterDelay;
	int				 LightningCellSpread;
	int				 LightningSeparation;
	bool				 LightningPrintText;
	WarheadTypeClass*			 LightningWarhead;
	int				 ForceShieldRadius;
	int				 ForceShieldDuration;
	int				 ForceShieldBlackoutDuration;
	int				 ForceShieldPlayFadeSoundTime;
	bool				 MutateExplosion;
	int				 CollapseChance;
	int				 WeedCapacity;
	float				 ExtraUnitLight;
	float				 ExtraInfantryLight;
	float				 ExtraAircraftLight;
	bool				 Paranoid;
	bool				 CurleyShuffle;
	bool				 BlendedFog;
	bool				 CompEasyBonus;
	bool				 FineDiffControl;
	bool				 TiberiumExplosive;
	bool				 EnemyHealth;
	bool				 AllyReveal;
	bool				 SeparateAircraft;
	bool				 TreeTargeting;
	bool				 NamedCivilians;
	bool				 PlayerAutoCrush;
	bool				 PlayerReturnFire;
	bool				 PlayerScatter;
	bool				 RevealByHeight;
	bool				 AllowShroudedSubteranneanMoves;
	bool				 ShroudGrow;
	bool				 NodAIBuildsWalls;
	bool				 AIBuildsWalls;
	bool				 UseMinDefenseRule;
	AnimTypeClass*			 EMPulseSparkles;
	float				 EngineerCaptureLevel;
	float				 EngineerCaptureLevel_;
	float				 TalkBubbleTime;
	int				 RadDurationMultiple;
	int				 RadApplicationDelay;
	int				 RadLevelMax;
	int				 RadLevelDelay;
	int				 RadLightDelay;
	double			 RadLevelFactor;
	double			 RadLightFactor;
	double			 RadTintFactor;
	ColorStruct				 RadColor;
	WarheadTypeClass*			 RadSiteWarhead;
	int				 ElevationIncrement;
	DWORD align_183C;
	double			 ElevationIncrementBonus;
	double			 ElevationBonusCap;
	bool				 AlliedWallTransparency;
	DWORD align_1854;
	double			 WallPenetratorThreshold;
	ColorStruct				 LocalRadarColor;
	ColorStruct				 LineTrailColorOverride;
	ColorStruct				 ChronoBeamColor;
	ColorStruct				 MagnaBeamColor;
	int				 OreTwinkleChance;
	AnimTypeClass*			 OreTwinkle;

	ColorStruct ColorAdd [0x10];

	int				 LaserTargetColor;
	int				 IronCurtainColor;
	int				 BerserkColor;
	int				 ForceShieldColor;
	float				 DirectRockingCoefficient;
	float				 FallBackCoefficient;
};
