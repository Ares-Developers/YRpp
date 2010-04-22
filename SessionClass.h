#ifndef SESSIONCLASS_H_
#define SESSIONCLASS_H_

#include <GeneralDefinitions.h>
#include <MPGameModeClass.h>

struct GameTypePreferencesStruct {
	PROPERTY(DWORD, idxMPMode);
	PROPERTY(DWORD, idxScenario);
	PROPERTY(int, GameSpeed);
	PROPERTY(int, Credits);
	PROPERTY(int, UnitCount);
	PROPERTY(bool, ShortGame);
	PROPERTY(bool, SuperWeapons);
	PROPERTY(bool, BuildOffAlly);
	PROPERTY(bool, MCVRepacks);
	PROPERTY(bool, CratesAppear);
	PROPERTY_ARRAY(DWORD, unknown_fields, 0x18);
};

struct AISlotsStruct {
	PROPERTY_ARRAY(int, AIDifficulties, 8);
	PROPERTY_ARRAY(void *, StartingSpots, 8);
	PROPERTY_ARRAY(int, Colours, 8);
	PROPERTY_ARRAY(int, Starts, 8);
	PROPERTY_ARRAY(int, Teams, 8);
};

struct SessionOptionsClass {
	PROPERTY(DWORD, idxMPMode);
	PROPERTY(DWORD, idxScenario);
	PROPERTY(bool, Bases);
	PROPERTY(DWORD, Money);
	PROPERTY(bool, BridgeDestruction);
	PROPERTY(bool, Crates);
	PROPERTY(bool, ShortGame);
	PROPERTY(bool, SuperWeaponsOn);
	PROPERTY(bool, BuildOffAlly);
	PROPERTY(int, GameSpeed);
	PROPERTY(bool, MultiEngineer);
	PROPERTY(int, UnitCount);
	PROPERTY(int, AIPlayers);
	PROPERTY(int, AIDifficulty);
	PROPERTY_STRUCT(AISlotsStruct, AISlots);
	PROPERTY(bool, AlliesAllowed);
	PROPERTY(bool, HarvesterTruce);
	PROPERTY(bool, CTF);
	PROPERTY(bool, FogOfWar);
	PROPERTY(bool, MCVRedeploy);
	PROPERTY_UNICODE(unnamed, 45);
};

class SessionClass {
	static SessionClass * Instance;

	eGameMode GameMode;
	PROPERTY(MPGameModeClass *, MPGameMode);
	PROPERTY(DWORD, unknown_08);
	PROPERTY(DWORD, unknown_0C);
	PROPERTY(DWORD, unknown_10);
	PROPERTY(DWORD, unknown_14);
	PROPERTY(DWORD, unknown_18);
	PROPERTY_STRUCT(SessionOptionsClass, Config);
	PROPERTY(DWORD, UniqueID);
	PROPERTY_STRING(Handle, 20);
	PROPERTY(int, PlayerColor);
	PROPERTY(DWORD, unknown_160);
	PROPERTY(DWORD, unknown_164);
	PROPERTY(DWORD, unknown_168);
	PROPERTY(DWORD, unknown_16C);
	PROPERTY(DWORD, unknown_170);
	PROPERTY(int, idxSide);
	PROPERTY(int, idxSide2);
	PROPERTY(int, Color);
	PROPERTY(int, Color2);
	PROPERTY(int, Side);
	PROPERTY(int, Side2);
	PROPERTY_STRUCT(GameTypePreferencesStruct, SkirmishPreferences);
	PROPERTY_STRUCT(GameTypePreferencesStruct, LANPreferences);
	PROPERTY_STRUCT(GameTypePreferencesStruct, WOLPreferences);
	PROPERTY_ARRAY(byte, unknown_300, 8);
	PROPERTY(bool, WOLLimitResolution);
	PROPERTY(int, LastNickSlot);

};

#endif
