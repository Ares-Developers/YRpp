#pragma once

#include <AbstractClass.h>

//forward declarations
class SuperClass;
class TechnoClass;
class TagTypeClass;
class TriggerTypeClass;
class TriggerClass;

class NOVTABLE TActionClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Action;

	//Static
	static DynamicVectorClass<TActionClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TActionClass() RX;

	//AbstractClass
	virtual void PointerExpired(AbstractClass* pAbstract, bool removed) override RX;
	virtual AbstractType WhatAmI() const override RT(AbstractType);
	virtual int Size() const override R0;
	virtual void CalculateChecksum(Checksummer& checksum) const override RX;
	virtual int GetArrayIndex() const override R0;

	// you are responsible for doing INI::ReadString and strtok'ing it before calling
	// this func only calls strtok again, doesn't know anything about buffers
	void LoadFromINI()
		{ JMP_THIS(0x6DD5B0); }

	// you allocate the buffer for this, and save it to ini yourself after this returns
	// this func only sprintf's the stuff it needs into buffer
	void PrepareSaveToINI(char *buffer) const
		{ JMP_THIS(0x6DD300); }

	// fuck if I know what's the purpose of this, returns a bitfield of flags for trigger logic
	static int GetFlags(int actionKind)
		{ JMP_STD(0x6E3EE0); }

	// transforms actionKind to a number saying what to parse arguments as (team/tag/trigger id, waypoint, integer, etc)
	static int GetMode(int actionKind)
		{ JMP_STD(0x6E3B60); }

	// main brain, returns whether succeeded (mostly, no consistency in results what so ever)
	// trigger fires all actions regardless of result of this
	bool Execute(HouseClass* pHouse, ObjectClass* pObject, TriggerClass* pTrigger, CellStruct const& location)
		{ JMP_THIS(0x6DD8B0); }

	// BIG LIST OF EXECUTE'S SLAVE FUNCTIONS - feel free to use

	// NOTE: most of these are defined as separate functions AS WELL AS inlined in Execute() above.
	// Ergo, hooking into them by their address will not always override builtin handling.
	// If you need to know which are inlined, poke me.
#pragma push_macro("ACTION_FUNC")

#define ACTION_FUNC(name, addr) \
	bool name(HouseClass* pTargetHouse, ObjectClass* pSourceObject, TriggerClass* pTrigger, CellStruct const& location) \
		{ JMP_THIS(addr); }

	ACTION_FUNC(LightningStrikeAt, 0x6E0050);
	ACTION_FUNC(RemoveParticleSystemsAt, 0x6E0080);
	ACTION_FUNC(WakeupAttachedObjects, 0x6E01C0);

	ACTION_FUNC(SetVeinGrowth, 0x6E0250);
	ACTION_FUNC(SetTiberiumGrowth, 0x6E0270);
	ACTION_FUNC(SetIceGrowth, 0x6E0290);

	ACTION_FUNC(WakeupAllIdle, 0x6E02B0);
	ACTION_FUNC(WakeupAllHarmless, 0x6E0330);
	ACTION_FUNC(WakeupGroup, 0x6E03B0);

	ACTION_FUNC(PlayerWin, 0x6E0440);
	ACTION_FUNC(PlayerLose, 0x6E0460);
	ACTION_FUNC(EndScenario, 0x6E0480);

	ACTION_FUNC(Apply100DamageAt, 0x6E0490);
	ACTION_FUNC(SmallLightFlashAt, 0x6E0790);
	ACTION_FUNC(MediumLightFlashAt, 0x6E07F0);
	ACTION_FUNC(LargeLightFlashAt, 0x6E0850);

	ACTION_FUNC(SellAttachedBuildings, 0x6E08B0);
	ACTION_FUNC(BerserkAttachedInfantry, 0x6E0930);
	ACTION_FUNC(SendAttachedBuildingsOffline, 0x6E09A0);
	ACTION_FUNC(SendAttachedBuildingsOnline, 0x6E0A20);

	ACTION_FUNC(SwitchAttachedObjectsToHouse, 0x6E0AA0);
	ACTION_FUNC(SwitchAllObjectsToHouse, 0x6E0B60);
	ACTION_FUNC(MindControlBuildingsOfHouse, 0x6E0CA0);
	ACTION_FUNC(RelinquishMindControlOfBuildingsOfHouse, 0x6E0D00);

	ACTION_FUNC(PrintMessage, 0x6E0D60);
	ACTION_FUNC(MakeTwoHousesAlly, 0x6E0DF0);
	ACTION_FUNC(MakeTwoHousesEnemy, 0x6E0E60);

	ACTION_FUNC(SetTargetCell, 0x6E0ED0);

	ACTION_FUNC(GrowShroud, 0x6E0F90);

	ACTION_FUNC(GlobalSet, 0x6E0FA0);
	ACTION_FUNC(GlobalClear, 0x6E0FC0);

	ACTION_FUNC(RevealAroundWaypoint, 0x6E0FE0);
	ACTION_FUNC(ReduceTiberiumAt, 0x6E1180);
	ACTION_FUNC(RevealZoneOfWaypoint, 0x6E11C0);

	ACTION_FUNC(MissionTimerStart, 0x6E13A0);
	ACTION_FUNC(MissionTimerStop, 0x6E13E0);
	ACTION_FUNC(MissionTimerExtend, 0x6E1440);
	ACTION_FUNC(MissionTimerShorten, 0x6E14A0);
	ACTION_FUNC(MissionTimerStartWithText, 0x6E1530);
	ACTION_FUNC(MissionTimerSetText, 0x6E15F0);

	ACTION_FUNC(PlayMovie, 0x6E16D0);
	ACTION_FUNC(PlayMovieInSidebar, 0x6E1720);
	ACTION_FUNC(PlayMovieInSidebarPauseGame, 0x6E1740);

	ACTION_FUNC(PlayAudio, 0x6E1760);
	ACTION_FUNC(PlayAudioAtRandomWP, 0x6E1780);
	ACTION_FUNC(PlayAudioAtSpecificWP, 0x6E18B0);
	ACTION_FUNC(StopAudioAtSpecificWP, 0x6E1980);

	ACTION_FUNC(TeleportAllHouseObjectTo, 0x6E1A40);

	ACTION_FUNC(ReshroudMapAroundWaypoint, 0x6E1A70);

	ACTION_FUNC(PlayTheme, 0x6E1B90);
	ACTION_FUNC(PlayEVA, 0x6E1BB0);

	ACTION_FUNC(Grant1ShotSW, 0x6E1BD0);
	ACTION_FUNC(GrantPermanentSW, 0x6E1C40);

	ACTION_FUNC(DiplayDropFlare, 0x6E1CC0);

	ACTION_FUNC(WinnerIs, 0x6E1DC0);
	ACTION_FUNC(LoserIs, 0x6E1E00);

	ACTION_FUNC(EnableProductionForHouse, 0x6E1E40);
	ACTION_FUNC(FireSale, 0x6E1EA0);
	ACTION_FUNC(EnableAutocreateForHouse, 0x6E1F00);

	ACTION_FUNC(CreateTeam, 0x6E1F60);
	ACTION_FUNC(DestroyAllInstancesOfTeam, 0x6E1F90);

	ACTION_FUNC(SpawnTeam, 0x6E1FB0);
	ACTION_FUNC(SpawnTeamAtWP, 0x6E1FD0);

	ACTION_FUNC(DestroyAttached, 0x6E2050);

	ACTION_FUNC(ResizePlayerView, 0x6E21E0);

	ACTION_FUNC(PlayAnimAtWP, 0x6E2290);
	ACTION_FUNC(FireWeaponAtWP, 0x6E2390);
	ACTION_FUNC(PlayVoxelAnimAtWP, 0x6E2520);

	ACTION_FUNC(LightningStormStart, 0x6E2600);
	ACTION_FUNC(LightningStormStop, 0x6E2640);

	ACTION_FUNC(JumpCameraHome, 0x6E2850);

	ACTION_FUNC(ZoomIn, 0x6E2860);
	ACTION_FUNC(ZoomOut, 0x6E28DC);

	ACTION_FUNC(SetAttachedSpotlightBehaviour, 0x6E2970);

	ACTION_FUNC(DeleteTrigger, 0x6E2A10);
	ACTION_FUNC(DeleteTag, 0x6E2A50);
	ACTION_FUNC(ForceTrigger, 0x6E2AA0);
	ACTION_FUNC(EnableTrigger, 0x6E2AF0);
	ACTION_FUNC(RadarEventAdd, 0x6E2BB0);

	ACTION_FUNC(LocalSet, 0x6E2BE0);
	ACTION_FUNC(LocalClear, 0x6E2C00);

	ACTION_FUNC(ClearSmudges, 0x6E2C20);

	ACTION_FUNC(StartMeteorShower, 0x6E2C40);

	ACTION_FUNC(SetAmbientChangeStep, 0x6E2E20);
	ACTION_FUNC(SetAmbientChangeRate, 0x6E2E40);

	ACTION_FUNC(SetTintRed, 0x6E2E60);
	ACTION_FUNC(SetTintGreen, 0x6E2EB0);
	ACTION_FUNC(SetTintBlue, 0x6E2F00);

	ACTION_FUNC(SetAmbientLevel, 0x6E2F4F);

	ACTION_FUNC(SetChronoScreenEffectState, 0x6E2F90);

	ACTION_FUNC(EnableAITriggers, 0x6E2FA0);
	ACTION_FUNC(DisableAITriggers, 0x6E3000);

	ACTION_FUNC(Cheer, 0x6E3060);

	ACTION_FUNC(RestoreStartingUnitsOf, 0x6E30C0);
	ACTION_FUNC(RestoreStartingBuildingsOf, 0x6E3120);

	ACTION_FUNC(DestroyAllObjectsOf, 0x6E3180);
	ACTION_FUNC(DestroyAllBuildingsOf, 0x6E31E0);
	ACTION_FUNC(DestroyAllNonNavalUnitsOf, 0x6E3240);
	ACTION_FUNC(DestroyAllNavalUnitsOf, 0x6E32A0);

	ACTION_FUNC(SetRatioAITeam, 0x6E3300);
	ACTION_FUNC(SetRatioAITeamAircraft, 0x6E3320);
	ACTION_FUNC(SetRatioAITeamInfantry, 0x6E3340);
	ACTION_FUNC(SetRatioAITeamUnits, 0x6E3360);

	ACTION_FUNC(IonBlastAtWP, 0x6E3380);
	ACTION_FUNC(NukeAtWP, 0x6E3410);
	ACTION_FUNC(LightningStormAtWP, 0x6E35F0);
	ACTION_FUNC(IronCurtainAtWP, 0x6E36E0);

	ACTION_FUNC(SetTechLevelOfTechnoType, 0x6E37F0);

	ACTION_FUNC(ChronoInTeam, 0x6E3890);

	ACTION_FUNC(CrateAtWP, 0x6E38B0);

	ACTION_FUNC(ChemLauncherAtWP, 0x6E38F0);

	ACTION_FUNC(ToggleTrainCrate, 0x6E3B20);

	ACTION_FUNC(RadarBlackout, 0x6E3B40);

	ACTION_FUNC(FlashTeamFor, 0x6E4020);
	ACTION_FUNC(TalkBubble, 0x6E4040);

	ACTION_FUNC(PauseScenarioFor, 0x6E4080);

	ACTION_FUNC(EjectOccupantsOfFirstAttachedBuilding, 0x6E4090);

	ACTION_FUNC(SwitchToTab, 0x6E4100);
	ACTION_FUNC(FlashCameo, 0x6E4150);

	ACTION_FUNC(SpawnBuilding, 0x6E4200);

	ACTION_FUNC(SetSWChargeLevel, 0x6E42D0);
	ACTION_FUNC(SetSWRechargeTime, 0x6E4320);
	ACTION_FUNC(ResetSWRechargeTime, 0x6E4360);
	ACTION_FUNC(ResetSW, 0x6E43A0);

	ACTION_FUNC(SetPreferredTargetCell, 0x6E43E0);
	ACTION_FUNC(ResetTargetCell, 0x6E4440);

	ACTION_FUNC(SetDefenseCell, 0x6E4460);
	ACTION_FUNC(ResetDefenseCell, 0x6E44C0);

	ACTION_FUNC(SetBaseCenter, 0x6E44E0);
	ACTION_FUNC(ResetBaseCenter, 0x6E4540);

	ACTION_FUNC(FlashBuildingsOfType, 0x6E4560);

#undef ACTION_FUNC
#pragma pop_macro("ACTION_FUNC")
	// WHEEEEEW. End of slave functions.

	HouseClass* FindHouseByIndex(TriggerClass* pTrigger, int idxHouse) const
		{ JMP_THIS(0x6E45E0); }

	//Constructor
	TActionClass() noexcept
		: TActionClass(noinit_t())
	{ JMP_THIS(0x71E6A0); }

protected:
	explicit __forceinline TActionClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	int                ArrayIndex;
	TActionClass*      NextAction;
	TriggerAction      ActionKind;
	TeamTypeClass*     TeamType;
	RectangleStruct    Bounds; // map bounds for use with action 40
	int                Waypoint;
	int                Value2; // multipurpose
	TagTypeClass*      TagType;
	TriggerTypeClass*  TriggerType;
	char               TechnoID[0x19];
	char               Text[0x20];
	PROTECTED_PROPERTY(BYTE, align_8D[3]);
	int                Value; // multipurpose
};
