/*
	TechnoTypes are initialized by INI files.
*/

#ifndef TECHNOTYPE_H
#define TECHNOTYPE_H

#include <ObjectTypeClass.h>
#include <RulesClass.h>

//forward declarations
class AircraftTypeClass;
class AnimTypeClass;
class BuildingTypeClass;
class InfantryTypeClass;
class ParticleSystemTypeClass;
class VoxelAnimTypeClass;
class WeaponTypeClass;
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

struct WeaponStruct
{
	WeaponTypeClass*  WeaponType;
	CoordStruct       FLH;
	int               BarrelLength;
	int               BarrelThickness;
	bool              TurretLocked;
};

#pragma pack(push, technotype)

#pragma pack(4)

class TechnoTypeClass : public ObjectTypeClass
{
public:
	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x7162F0); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x716DC0); }
	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize)
		{ PUSH_VAR32(pcbSize); PUSH_VAR32(this); CALL(0x7170A0); }

	//Destructor
	virtual ~TechnoTypeClass()
		{ THISCALL(0x711AE0); }

	//AbstractClass
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x7171A0); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x712170); }

	//ObjectTypeClass
	virtual DWORD GetOwners()
		{ THISCALL(0x711EC0); }
	virtual int GetPipMax()
		{ THISCALL(0x716290); }
	virtual int GetActualCost(HouseTypeClass* pCountry)
		{ PUSH_VAR32(pCountry); THISCALL(0x711F00); }
	virtual int GetBuildSpeed()
		{ THISCALL(0x711EE0); }
	virtual SHPStruct* GetCameo()
		{ THISCALL(0x712040); }

	//TechnoTypeClass
	virtual bool vt_entry_A0()
		{ return true; }
	virtual bool CanAttackMove()
		{ THISCALL(0x711E90); }
	virtual bool vt_entry_A8(CellStruct* pMapCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pMapCoords); THISCALL(0x716150); }
	virtual int GetCost()
		{ return Cost; }
	virtual int vt_entry_B4()
		{ THISCALL(0x7120D0); }
	virtual int GetRepairStep()
		{ return RulesClass::Global()->get_RepairStep(); }
	virtual int GetRefund(HouseClass* pHouse, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pHouse); THISCALL(0x711F60); }
	virtual int GetFlightLevel()
		{ return FlightLevel != -1
		  ? FlightLevel
		  : RulesClass::Global()->get_FlightLevel(); }

	//Constructor
	TechnoTypeClass(const char* id, eSpeedType speedtype):ObjectTypeClass(false)
		{ PUSH_VAR32(speedtype); PUSH_VAR32(id); THISCALL(0x710AF0); }

protected:
	//default contructor, only used by polymorphism
	TechnoTypeClass():ObjectTypeClass(false)
		{ }
	TechnoTypeClass(bool X):ObjectTypeClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,             WalkRate);
	PROPERTY(int,             IdleRate);
	PROPERTY_STRUCT(AbilitiesStruct, VeteranAbilities);
	PROPERTY_STRUCT(AbilitiesStruct, EliteAbilities);
	PROPERTY(double,          SpecialThreatValue);
	PROPERTY(double,          MyEffectivenessCoefficient);
	PROPERTY(double,          TargetEffectivenessCoefficient);
	PROPERTY(double,          TargetSpecialThreatCoefficient);
	PROPERTY(double,          TargetStrengthCoefficient);
	PROPERTY(double,          TargetDistanceCoefficient);
	PROPERTY(double,          ThreatAvoidanceCoefficient);
	PROPERTY(int,             SlowdownDistance);
private: DWORD align_2FC;
	PROPERTY(double,          unknown_double_300);
	PROPERTY(double,          AccelerationFactor);
	PROPERTY(int,             CloakingSpeed);
	PROPERTY_STRUCT(TypeList<VoxelAnimTypeClass*>,  DebrisTypes);
	PROPERTY_STRUCT(TypeList<int>,   DebrisMaximums);
	PROPERTY(_GUID,           Locomotor);
private: DWORD align_35C;
	PROPERTY(double,          unknown_double_360);
	PROPERTY(double,          unknown_double_368);
	PROPERTY(double,          Weight);
	PROPERTY(double,          PhysicalSize);
	PROPERTY(double,          Size);
	PROPERTY(double,          SizeLimit);
	PROPERTY(bool,            HoverAttack);
	PROPERTY(int,             VHPScan);
	PROPERTY(int,             unknown_int_398);
private: DWORD align_39C;
	PROPERTY(double,          RollAngle);
	PROPERTY(double,          PitchSpeed);
	PROPERTY(double,          PitchAngle);
	PROPERTY(int,             BuildLimit);
	PROPERTY(int,             Category);
	PROPERTY(DWORD,           unknown_3C0);
private: DWORD align_3C4;
	PROPERTY(double,          DeployTime);
	PROPERTY(int,             FireAngle);
	PROPERTY(int,             PipScale);
	PROPERTY(bool,            PipsDrawForAll);
	PROPERTY(int,             LeptonMindControlOffset);
	PROPERTY(int,             PixelSelectionBracketDelta);
	PROPERTY(int,             PipWrap);
	PROPERTY_STRUCT(TypeList<BuildingTypeClass*>, Dock);
	PROPERTY(BuildingTypeClass*, DeploysInto);
	PROPERTY(UnitTypeClass*,  UndeploysInto);
	PROPERTY(UnitTypeClass*,  PowersUnit);
	PROPERTY(bool,            PoweredUnit);
	PROPERTY_STRUCT(TypeList<int>,   VoiceSelect);
	PROPERTY_STRUCT(TypeList<int>,   VoiceSelectEnslaved);
	PROPERTY_STRUCT(TypeList<int>,   VoiceSelectDeactivated);
	PROPERTY_STRUCT(TypeList<int>,   VoiceMove);
	PROPERTY_STRUCT(TypeList<int>,   VoiceAttack);
	PROPERTY_STRUCT(TypeList<int>,   VoiceSpecialAttack);
	PROPERTY_STRUCT(TypeList<int>,   VoiceDie);
	PROPERTY_STRUCT(TypeList<int>,   VoiceFeedback);
	PROPERTY_STRUCT(TypeList<int>,   MoveSound);
	PROPERTY_STRUCT(TypeList<int>,   DieSound);
	PROPERTY(int,             AuxSound1);
	PROPERTY(int,             AuxSound2);
	PROPERTY(int,             CreateSound);
	PROPERTY(int,             DamageSound);
	PROPERTY(int,             ImpactWaterSound);
	PROPERTY(int,             ImpactLandSound);
	PROPERTY(int,             CrashingSound);
	PROPERTY(int,             SinkingSound);
	PROPERTY(int,             VoiceFalling);
	PROPERTY(int,             VoiceCrashing);
	PROPERTY(int,             VoiceSinking);
	PROPERTY(int,             VoiceEnter);
	PROPERTY(int,             VoiceCapture);
	PROPERTY(int,             TurretRotateSound);
	PROPERTY(int,             EnterTransportSound);
	PROPERTY(int,             LeaveTransportSound);
	PROPERTY(int,             DeploySound);
	PROPERTY(int,             UndeploySound);
	PROPERTY(int,             ChronoInSound);
	PROPERTY(int,             ChronoOutSound);
	PROPERTY(int,             VoiceHarvest);
	PROPERTY(int,             VoicePrimaryWeaponAttack);
	PROPERTY(int,             VoicePrimaryEliteWeaponAttack);
	PROPERTY(int,             VoiceSecondaryWeaponAttack);
	PROPERTY(int,             VoiceSecondaryEliteWeaponAttack);
	PROPERTY(int,             VoiceDeploy);
	PROPERTY(int,             VoiceUndeploy);
	PROPERTY(int,             EnterGrinderSound);
	PROPERTY(int,             LeaveGrinderSound);
	PROPERTY(int,             EnterBioReactorSound);
	PROPERTY(int,             LeaveBioReactorSound);
	PROPERTY(int,             ActivateSound);
	PROPERTY(int,             DeactivateSound);
	PROPERTY(int,             MindClearedSound);
	PROPERTY(eMovementZone,   MovementZone);
	PROPERTY(int,             GuardRange);
	PROPERTY(int,             MinDebris);
	PROPERTY(int,             MaxDebris);
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, DebrisAnims);
	PROPERTY(int,             Passengers);
	PROPERTY(bool,            OpenTopped);
	PROPERTY(int,             Sight);
	PROPERTY(bool,            ResourceGatherer);
	PROPERTY(bool,            ResourceDestination);
	PROPERTY(bool,            RevealToAll);
	PROPERTY(bool,            Drainable);
	PROPERTY(int,             SensorsSight);
	PROPERTY(int,             DetectDisguiseRange);
	PROPERTY(int,             BombSight);
	PROPERTY(int,             LeadershipRating);
	PROPERTY(int,             NavalTargeting);
	PROPERTY(int,             LandTargeting);
	PROPERTY(float,           BuildTimeMultiplier);
	PROPERTY(int,             MindControlRingOffset);
	PROPERTY(int,             Cost);
	PROPERTY(int,             Soylent);
	PROPERTY(int,             FlightLevel);
	PROPERTY(int,             AirstrikeTeam);
	PROPERTY(int,             EliteAirstrikeTeam);
	PROPERTY(AircraftTypeClass*, AirstrikeTeamType);
	PROPERTY(AircraftTypeClass*, EliteAirstrikeTeamType);
	PROPERTY(int,             AirstrikeRechargeTime);
	PROPERTY(int,             EliteAirstrikeRechargeTime);
	PROPERTY(int,             TechLevel);
	PROPERTY_STRUCT(TypeList<int>,   Prerequisite);
	PROPERTY_STRUCT(TypeList<int>,   PrerequisiteOverride);
	PROPERTY(int,             ThreatPosed);
	PROPERTY(int,             Points);
	PROPERTY(int,             Speed);
	PROPERTY(eSpeedType,      SpeedType);
	PROPERTY(int,             InitialAmmo);
	PROPERTY(int,             Ammo);
	PROPERTY(int,             IFVMode);
	PROPERTY(int,             AirRangeBonus);
	PROPERTY(bool,            BerserkFriendly);
	PROPERTY(bool,            SprayAttack);
	PROPERTY(bool,            Pushy);
	PROPERTY(bool,            Natural);
	PROPERTY(bool,            Unnatural);
	PROPERTY(bool,            CloseRange);
	PROPERTY(int,             Reload);
	PROPERTY(int,             EmptyReload);
	PROPERTY(int,             ReloadIncrement);
	PROPERTY(int,             RadialFireSegments);
	PROPERTY(int,             DeployFireWeapon);
	PROPERTY(bool,            DeployFire);
	PROPERTY(bool,            DeployToLand);
	PROPERTY(bool,            MobileFire);
	PROPERTY(bool,            OpportunityFire);
	PROPERTY(bool,            DistributedFire);
	PROPERTY(bool,            DamageReducesReadiness);
	PROPERTY(int,             ReadinessReductionMultiplier);
	PROPERTY(UnitTypeClass*,  UnloadingClass);
	PROPERTY(AnimTypeClass*,  DeployingAnim);
	PROPERTY(bool,            AttackFriendlies);
	PROPERTY(bool,            AttackCursorOnFriendlies);
	PROPERTY(int,             UndeployDelay);
	PROPERTY(bool,            PreventAttackMove);
	PROPERTY(DWORD,           OwnerFlags);
	PROPERTY(int,             AIBasePlanningSide);
	PROPERTY(bool,            StupidHunt);
	PROPERTY(bool,            AllowedToStartInMultiplayer);
	PROPERTY_STRING(CameoFile, 0x19);
	PROTECTED_PROPERTY(BYTE,  unused_6EF);
	PROPERTY(SHPStruct*,      Cameo);
	PROTECTED_PROPERTY(BYTE,  unused_6F4);
	PROPERTY_STRING(AltCameoFile, 0x19);
	PROTECTED_PROPERTY(BYTE,  unused_70E);
	PROTECTED_PROPERTY(BYTE,  unused_70F);
	PROPERTY(SHPStruct*,      AltCameo);
	PROTECTED_PROPERTY(BYTE,  unused_714);
	PROPERTY(int,             RotCount);
	PROPERTY(int,             ROT);
	PROPERTY(int,             TurretOffset);
	PROPERTY(bool,            CanBeHidden);
	PROPERTY(int,             Points2); //twice
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, Explosion);
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, DestroyAnim);
	PROPERTY(ParticleSystemTypeClass*, NaturalParticleSystem);
	PROPERTY_STRUCT(CoordStruct,     NaturalParticleSystemLocation);
	PROPERTY(ParticleSystemTypeClass*, RefinerySmokeParticleSystem);
	PROPERTY_STRUCT(TypeList<ParticleSystemTypeClass*>, DamageParticleSystems);
	PROPERTY_STRUCT(TypeList<ParticleSystemTypeClass*>, DestroyParticleSystems);
	PROPERTY_STRUCT(CoordStruct,     DamageSmokeOffset);
	PROPERTY(bool,            DamSmkOffScrnRel);
	PROPERTY_STRUCT(CoordStruct,     DestroySmokeOffset);
	PROPERTY_STRUCT(CoordStruct,     RefinerySmokeOffsetOne);
	PROPERTY_STRUCT(CoordStruct,     RefinerySmokeOffsetTwo);
	PROPERTY_STRUCT(CoordStruct,     RefinerySmokeOffsetThree);
	PROPERTY_STRUCT(CoordStruct,     RefinerySmokeOffsetFour);
	PROPERTY(int,             ShadowIndex);
	PROPERTY(int,             Storage);
	PROPERTY(bool,            TurretNotExportedOnGround);
	PROPERTY(bool,            Gunner);
	PROPERTY(bool,            HasTurretTooltips);
	PROPERTY(int,             TurretCount);
	PROPERTY(int,             WeaponCount);
	PROPERTY(bool,            IsChargeTurret);

	PROPERTY_ARRAY(int, TurretWeapon, 0x21);

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

	PROPERTY(bool,            ClearAllWeapons);

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

	PROPERTY(bool,            TypeImmune);
	PROPERTY(bool,            MoveToShroud);
	PROPERTY(bool,            Trainable);
	PROPERTY(bool,            Cyborg_); //!Copied from the InfantryTypeClass!
	PROPERTY(bool,            TargetLaser);
	PROPERTY(bool,            ImmuneToVeins);
	PROPERTY(bool,            TiberiumHeal);
	PROPERTY(bool,            CloakStop);
	PROPERTY(bool,            IsTrain);
	PROPERTY(bool,            IsDropship);
	PROPERTY(bool,            ToProtect);
	PROPERTY(bool,            Disableable);
	PROPERTY(bool,            unknown_bool_C98); //always false
	PROPERTY(bool,            DoubleOwned);
	PROPERTY(bool,            Invisible);
	PROPERTY(bool,            RadarVisible);
	PROPERTY(bool,            HasPrimary); //not loaded from the INIs
	PROPERTY(bool,            Sensors);
	PROPERTY(bool,            Nominal);
	PROPERTY(bool,            DontScore);
	PROPERTY(bool,            DamageSelf);
	PROPERTY(bool,            Turret);
	PROPERTY(bool,            TurretRecoil);
	PROPERTY(int,             TurretTravel);
	PROPERTY(int,             TurretCompressFrames);
	PROPERTY(int,             TurretHoldFrames);
	PROPERTY(int,             TurretRecoverFrames);
	PROPERTY(bool,            unknown_bool_CB4); //always false?
	PROPERTY(int,             BarrelTravel);
	PROPERTY(int,             BarrelCompressFrames);
	PROPERTY(int,             BarrelHoldFrames);
	PROPERTY(int,             BarrelRecoverFrames);
	PROPERTY(bool,            unknown_bool_CC8); //always false?

protected:
	BYTE align_CC9, align_CCA, align_CCB;

public:
	PROPERTY(bool,            Repairable);
	PROPERTY(bool,            Crewed);
	PROPERTY(bool,            Naval);
	PROPERTY(bool,            Remapable);
	PROPERTY(bool,            Cloakable);
	PROPERTY(bool,            GapGenerator);
	PROPERTY(char,            GapRadiusInCells);
	PROPERTY(char,            SuperGapRadiusInCells);
	PROPERTY(bool,            Teleporter);
	PROPERTY(bool,            IsGattling);
	PROPERTY(int,             WeaponStages);
	PROPERTY_ARRAY(int, WeaponStage, 6);
	PROPERTY_ARRAY(int, EliteStage, 6);
	PROPERTY(int,             RateUp);
	PROPERTY(int,             RateDown);
	PROPERTY(bool,            SelfHealing);
	PROPERTY(bool,            Explodes);
	PROPERTY(WeaponTypeClass*, DeathWeapon);
	PROPERTY(float,           DeathWeaponDamageModifier);
	PROPERTY(bool,            NoAutoFire);
	PROPERTY(bool,            TurretSpins);
	PROPERTY(bool,            TiltCrashJumpjet);
	PROPERTY(bool,            Normalized);
	PROPERTY(bool,            ManualReload);
	PROPERTY(bool,            VisibleLoad);
	PROPERTY(bool,            LightningRod);
	PROPERTY(bool,            HunterSeeker);
	PROPERTY(bool,            Crusher);
	PROPERTY(bool,            OmniCrusher);
	PROPERTY(bool,            OmniCrushResistant);
	PROPERTY(bool,            TiltsWhenCrushes);
	PROPERTY(bool,            IsSubterranean);
	PROPERTY(bool,            AutoCrush);
	PROPERTY(bool,            Bunkerable);
	PROPERTY(bool,            CanDisguise);
	PROPERTY(bool,            PermaDisguise);
	PROPERTY(bool,            DetectDisguise);
	PROPERTY(bool,            DisguiseWhenStill);
	PROPERTY(bool,            CanApproachTarget);
	PROPERTY(bool,            CanRecalcApproachTarget);
	PROPERTY(bool,            ImmuneToPsionics);
	PROPERTY(bool,            ImmuneToPsionicWeapons);
	PROPERTY(bool,            ImmuneToRadiation);
	PROPERTY(bool,            Parasiteable);
	PROPERTY(bool,            DefaultToGuardArea);
	PROPERTY(bool,            Warpable);
	PROPERTY(bool,            ImmuneToPoison);
	PROPERTY(bool,            ReselectIfLimboed);
	PROPERTY(bool,            RejoinTeamIfLimboed);
	PROPERTY(bool,            Slaved);
	PROPERTY(InfantryTypeClass*, Enslaves);
	PROPERTY(int,             SlavesNumber);
	PROPERTY(int,             SlaveRegenRate);
	PROPERTY(int,             SlaveReloadRate);
	PROPERTY(int,             OpenTransportWeapon);
	PROPERTY(bool,            Spawned);
	PROPERTY(AircraftTypeClass*, Spawns);
	PROPERTY(int,             SpawnsNumber);
	PROPERTY(int,             SpawnRegenRate);
	PROPERTY(int,             SpawnReloadRate);
	PROPERTY(bool,            MissileSpawn);
	PROPERTY(bool,            Underwater);
	PROPERTY(bool,            BalloonHover);
	PROPERTY(int,             SuppressionThreshold);
	PROPERTY(int,             JumpjetTurnRate);
	PROPERTY(int,             JumpjetSpeed);
	PROPERTY(float,           JumpjetClimb);
	PROPERTY(float,           JumpjetCrash);
	PROPERTY(int,             JumpjetHeight);
	PROPERTY(float,           JumpjetAccel);
	PROPERTY(float,           JumpjetWobbles);
	PROPERTY(bool,            JumpjetNoWobbles);
	PROPERTY(int,             JumpjetDeviation);
	PROPERTY(bool,            JumpJet);
	PROPERTY(bool,            Crashable);
	PROPERTY(bool,            ConsideredAircraft);
	PROPERTY(bool,            Organic);
	PROPERTY(bool,            NoShadow);
	PROPERTY(bool,            CanPassiveAquire);
	PROPERTY(bool,            CanRetaliate);
	PROPERTY(bool,            RequiresStolenThirdTech);
	PROPERTY(bool,            RequiresStolenSovietTech);
	PROPERTY(bool,            RequiresStolenAlliedTech);
	PROPERTY(DWORD,           RequiredHouses);
	PROPERTY(DWORD,           ForbiddenHouses);
	PROPERTY(DWORD,           SecretHouses);
	PROPERTY(bool,            UseBuffer);
	PROPERTY_STRUCT(CoordStruct,     SecondSpawnOffset);
	PROPERTY(bool,            IsSelectableCombatant);
	PROPERTY(bool,            Accelerates);
	PROPERTY(bool,            DisableVoxelCache);
	PROPERTY(bool,            DisableShadowCache);
	PROPERTY(int,             ZFudgeCliff);
	PROPERTY(int,             ZFudgeColumn);
	PROPERTY(int,             ZFudgeTunnel);
	PROPERTY(int,             ZFudgeBridge);
	PROPERTY_STRING(PaletteFile, 0x20);
	PROPERTY(void*,           Palette); //no... idea....
	PROPERTY(DWORD,           unknown_DF4);
	PROPERTY(int,             ArrayIndex); //in the respective class type's array!!
};

#pragma pack(pop, technotype)

#endif
