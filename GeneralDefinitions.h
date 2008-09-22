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
#define	abs_LightSource		0x13
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


typedef int eAbilities;

#define	ability_FASTER		0x0
#define	ability_STRONGER		0x1
#define	ability_FIREPOWER		0x2
#define	ability_SCATTER		0x3
#define	ability_ROF		0x4
#define	ability_SIGHT		0x5
#define	ability_CLOAK		0x6
#define	ability_TIBERIUM_PROOF		0x7
#define	ability_VEIN_PROOF		0x8
#define	ability_SELF_HEAL		0x9
#define	ability_EXPLODES		0xA
#define	ability_RADAR_INVISIBLE		0xB
#define	ability_SENSORS		0xC
#define	ability_FEARLESS		0xD
#define	ability_C4		0xE
#define	ability_TIBERIUM_HEAL		0xF
#define	ability_GUARD_AREA		0x10
#define	ability_CRUSHER		0x11


typedef int eAIModes;

#define		aim_General		0x00
#define		aim_LowOnCash 0x01 // if HouseClass::AvailableMoney < 25 ! stupidly low value
#define		aim_BuildBase		0x03
#define		aim_SellAll		0x04

typedef int eArmor;

#define	armor_None		0x0
#define	armor_Flak		0x1
#define	armor_Plate		0x2
#define	armor_Light		0x3
#define	armor_Medium		0x4
#define	armor_Heavy		0x5
#define	armor_Wood		0x6
#define	armor_Steel		0x7
#define	armor_Concrete		0x8
#define	armor_Special_1		0x9
#define	armor_Special_2		0xA


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


typedef int eBuildingAnims;

#define	ba_Upgrade1		0x0
#define	ba_Upgrade2		0x1
#define	ba_Upgrade3		0x2
#define	ba_Active		0x3
#define	ba_ActiveTwo		0x4
#define	ba_ActiveThree		0x5
#define	ba_ActiveFour		0x6
#define	ba_Production		0x7
#define	ba_PreProduction		0x8
#define	ba_Turret		0x9
#define	ba_Special		0xA
#define	ba_SpecialTwo		0xB
#define	ba_SpecialThree		0xC
#define	ba_SpecialFour		0xD
#define	ba_Super		0xE
#define	ba_SuperTwo		0xF
#define	ba_SuperThree		0x10
#define	ba_SuperFour		0x11
#define	ba_Idle		0x12
#define	ba_LowPower		0x13
#define	ba_SuperLowPower		0x14


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

#define	cf2_NoShadow			0x08 //else tooltip is TXT_SHADOW


typedef int eCloakStates;

#define	cs_Uncloaked		0x0
#define	cs_Cloaking		0x1
#define	cs_Cloaked		0x2
#define	cs_Uncloaking		0x3


typedef int eDamageState;

#define	ds_Unaffected		0x0
#define	ds_Unchanged		0x1
#define	ds_NowYellow		0x2
#define	ds_NowRed		0x3
#define	ds_NowDead		0x4
#define	ds_PostMortem		0x5


typedef int eDirection;

#define	dir_N		0x0
#define	dir_NE		0x1
#define	dir_E		0x2
#define	dir_SE		0x3
#define	dir_S		0x4
#define	dir_SW		0x5
#define	dir_W		0x6
#define	dir_NW		0x7


typedef int eFiringState;

#define	fs_ReadyToFire		0x0
#define	fs_NoAmmo		0x1
#define	fs_2		0x2
#define	fs_WaitForIt		0x3
#define	fs_4		0x4
#define	fs_CantAffect		0x5
#define	fs_CantCommand		0x6
#define	fs_CantInterrupt		0x7
#define	fs_OutOfRange		0x8
#define	fs_DecloakFirst		0x9
#define	fs_SpawnsReady		0xA


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


typedef int eGameMode;

#define	gm_Campaign		0x0
#define	gm_LAN		0x3
#define	gm_Internet		0x4
#define	gm_Skirmish		0x5


typedef int eInfDeath;

#define	id_Die1		0x1
#define	id_Die2		0x2
#define	id_Explode		0x3
#define	id_Flames		0x4
#define	id_Electro		0x5
#define	id_HeadPop		0x6
#define	id_Nuked		0x7
#define	id_Virus		0x8
#define	id_Mutate		0x9
#define	id_Brute		0xA


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


typedef int eLayer;

#define	lyr_None		-0x1
#define	lyr_Underground		0x0
#define	lyr_Surface		0x1
#define	lyr_Ground		0x2
#define	lyr_Air		0x3
#define	lyr_Top		0x4

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
#define	mz_InfantryDestroyer		0x8
#define	mz_Fly		0x9
#define	mz_WaterBeach		0xB
#define	mz_CrusherAll		0xC


typedef int ePip;

#define	pip_green		0x1
#define	pip_yellow		0x2
#define	pip_white		0x3
#define	pip_red		0x4
#define	pip_blue		0x5
#define	pip_wtf		0x6
#define	pip_persongreen		0x7
#define	pip_personyellow		0x8
#define	pip_personwhite		0x9
#define	pip_personred		0xA
#define	pip_personblue		0xB
#define	pip_personpurple		0xC


typedef int ePipScale;

#define	ps_Ammo		0x1
#define	ps_Tiberium		0x2
#define	ps_Passengers		0x3
#define	ps_Storage		0x4
#define	ps_MindControl		0x5


typedef int ePowerup;

#define	pow_Money		0x0
#define	pow_Unit		0x1
#define	pow_HealBase		0x2
#define	pow_Cloak		0x3
#define	pow_Explosion		0x4
#define	pow_Napalm		0x5
#define	pow_Squad		0x6
#define	pow_Darkness		0x7
#define	pow_Reveal		0x8
#define	pow_Armor		0x9
#define	pow_Speed		0xA
#define	pow_Firepower		0xB
#define	pow_ICBM		0xC
#define	pow_Invulnerability		0xD
#define	pow_Veteran		0xE
#define	pow_IonStorm		0xF
#define	pow_Gas		0x10
#define	pow_Tiberium		0x11
#define	pow_Pod		0x12


typedef int ePrerequisite;

#define	prereq_PROC		-0x6
#define	prereq_TECH		-0x5
#define	prereq_RADAR		-0x4
#define	prereq_BARRACKS		-0x3
#define	prereq_FACTORY		-0x2
#define	prereq_POWER		-0x1


typedef int ePrismChargeState;

#define		pcs_Idle		0
#define		pcs_Charging		1
#define		pcs_Firing		2


typedef int RadarEventType;

#define		RADAREVENT_0		0x00
#define		RADAREVENT_1		0x01
#define		RADAREVENT_2		0x02
#define		RADAREVENT_BASEUNDERATTACK		0x03
#define		RADAREVENT_OREMINERUNDERATTACK		0x04
#define		RADAREVENT_5		0x05
#define		RADAREVENT_UNITREADY		0x06
#define		RADAREVENT_UNITLOST			0x07
#define		RADAREVENT_UNITREPAIRED		0x08
#define		RADAREVENT_RADARSABOTAGED		0x09
#define		RADAREVENT_BUILDINGCAPTURED		0x0A
#define		RADAREVENT_BEACONDETECTED		0x0B
#define		RADAREVENT_SUPERWEAPONDETECTED		0x0C
#define		RADAREVENT_SUPERWEAPONLAUNCHED		0x0D
#define		RADAREVENT_BRIDGEREPAIRED		0x0E
#define		RADAREVENT_STRUCTUREABANDONED		0x0F
#define		RADAREVENT_ALLYUNDERATTACK		0x10


typedef int eRank;

#define	rank_Invalid		-0x1
#define	rank_Elite		0x0
#define	rank_Veteran		0x1
#define	rank_Rookie		0x2


typedef int eSequence;

#define	seq_Ready		0x0
#define	seq_Prone		0x2
#define	seq_Walk		0x3
#define	seq_FireUp		0x4
#define	seq_Down		0x5
#define	seq_Crawl		0x6
#define	seq_Up		0x7
#define	seq_FireProne		0x8
#define	seq_Idle1		0x9
#define	seq_Idle2		0xA
#define	seq_Die1		0xB
#define	seq_Die2		0xC
#define	seq_Die3		0xD
#define	seq_Die4		0xE
#define	seq_Die5		0xF
#define	seq_Tread		0x10
#define	seq_Swim		0x11
#define	seq_WetIdle1		0x12
#define	seq_WetIdle2		0x13
#define	seq_WetAttack		0x14
#define	seq_Hover		0x15
#define	seq_Tumble		0x17
#define	seq_FireFly		0x18
#define	seq_Deploy		0x19
#define	seq_Deployed		0x1A
#define	seq_DeployedFire		0x1B
#define	seq_DeployedIdle		0x1C
#define	seq_Undeploy		0x1D
#define	seq_Cheer		0x1E
#define	seq_Paradrop		0x1F
#define	seq_AirDeathStart		0x20
#define	seq_AirDeathFalling		0x21
#define	seq_AirDeathFinish		0x22
#define	seq_Panic		0x23
#define	seq_Shovel		0x24
#define	seq_Carry		0x25
#define	seq_SecondaryFire		0x26
#define	seq_SecondaryProne		0x27


typedef int eSpeedType;

#define	st_Foot		0x0
#define	st_Track		0x1
#define	st_Wheel		0x2
#define	st_Hover		0x3
#define	st_Winged		0x4
#define	st_Float		0x5
#define	st_Amphibious		0x6
#define	st_FloatBeach		0x7


typedef int eTheater;

#define	th_Temperate		0x0
#define	th_Snow		0x1
#define	th_Urban		0x2
#define	th_Desert		0x3
#define	th_NewUrban		0x4
#define	th_Lunar		0x5


typedef int eVisualType;

#define	vt_Normal		0x00
#define	vt_Indistinct		0x01
#define	vt_Darken		0x02
#define	vt_Shadowy		0x03
#define	vt_Ripple		0x04
#define	vt_Hidden		0x05


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
typedef int eSoundPriority;

#define	sp_LOWEST		0x1
#define	sp_LOW		0x2
#define	sp_NORMAL		0x3
#define	sp_HIGH		0x4
#define	sp_CRITICAL		0x5

typedef int eWaveType;

#define wave_Sonic 0x0
#define wave_Laser 0x1
#define wave_BigLaser 0x2
#define wave_Magnetron 0x3

typedef int eSoundType;

#define	sndtype_STANDARD		0x0
#define	sndtype_QUEUE		0x1
#define	sndtype_INTERRUPT		0x2
#define	sndtype_QUEUED_INTERRUPT		0x3


typedef int eSoundControl;

#define	sndc_LOOP		0x1
#define	sndc_RANDOM		0x2
#define	sndc_ALL		0x4
#define	sndc_PREDELAY		0x8
#define	sndc_INTERRUPT		0x10
#define	sndc_ATTACK		0x20
#define	sndc_DECAY		0x40
#define	sndc_AMBIENT		0x80


// UI
typedef BYTE eMouseEventFlags;

#define	mevf_LBUTTONDOWN		0x01
#define	mevf_LBUTTONHELD		0x02
#define	mevf_LBUTTONUP		0x04
#define	mevf_MOVE		0x08
#define	mevf_RBUTTONDOWN		0x10
#define	mevf_RBUTTONHELD		0x20
#define	mevf_RBUTTONUP		0x40


typedef int eEdge;

#define	edge_NORTH		0x00
#define	edge_EAST		0x01
#define	edge_SOUTH		0x02
#define	edge_WEST		0x03
#define	edge_AIR		0x04


typedef int eMove;

#define	move_OK		0
#define	move_Cloak		1
#define	move_Moving_Block		2
#define	move_Closed_Gate		3
#define	move_Friendly_Destroyable		4
#define	move_Destroyable		5
#define	move_Temp		6
#define	move_No		7
#define	move_Count		8


typedef int eZGradient;

#define	zgrad_None		-1
#define	zgrad_Ground		0
#define	zgrad_45Deg		1
#define	zgrad_90Deg		2
#define	zgrad_135Deg		3
#define	zgrad_Count		4


typedef int eFireError;

#define	fire_OK		0
#define	fire_Ammo		1
#define	fire_Facing		2
#define	fire_Rearm		3
#define	fire_Rotating		4
#define	fire_Illegal		5
#define	fire_Cant		6
#define	fire_Moving		7
#define	fire_Range		8
#define	fire_Cloaked		9
#define	fire_Busy		10
#define	fire_Must_Deploy		11

//Westwood custom messages (e.g. for SendMessage)
#define	WW_SLIDER_GETVALUE			0x400

#define	WW_SLIDER_SETVALUE			0x405
#define	WW_SLIDER_SETRANGE			0x406

#define	WW_INITDIALOG				0x497
#define	WW_SETCOLOR					0x498

#define WW_BLITDDS					0x4A8	//lParam is some structure

#define	WW_STATIC_SETTEXT			0x4B2

#define	WW_CB_ADDITEM				0x4C2

#define	WW_LB_ADDITEM				0x4CD

#endif
