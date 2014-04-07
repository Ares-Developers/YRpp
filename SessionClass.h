#ifndef SESSIONCLASS_H_
#define SESSIONCLASS_H_

#include <GeneralDefinitions.h>
#include <MPGameModeClass.h>

struct GameTypePreferencesStruct {
	DWORD idxMPMode;
	DWORD idxScenario;
	int GameSpeed;
	int Credits;
	int UnitCount;
	bool ShortGame;
	bool SuperWeapons;
	bool BuildOffAlly;
	bool MCVRepacks;
	bool CratesAppear;
	DWORD unknown_fields [0x18];
};

struct AISlotsStruct {
	int AIDifficulties [8];
	void * StartingSpots [8];
	int Colours [8];
	int Starts [8];
	int Teams [8];
};

struct SessionOptionsClass {
	DWORD idxMPMode;
	DWORD idxScenario;
	bool Bases;
	DWORD Money;
	bool BridgeDestruction;
	bool Crates;
	bool ShortGame;
	bool SuperWeaponsOn;
	bool BuildOffAlly;
	int GameSpeed;
	bool MultiEngineer;
	int UnitCount;
	int AIPlayers;
	int AIDifficulty;
	AISlotsStruct AISlots;
	bool AlliesAllowed;
	bool HarvesterTruce;
	bool CTF;
	bool FogOfWar;
	bool MCVRedeploy;
	wchar_t unnamed [45];
};

class SessionClass {

	public:

	static SessionClass * Instance;

	GameMode::Value GameMode;
	MPGameModeClass * MPGameMode;
	DWORD unknown_08;
	DWORD unknown_0C;
	DWORD unknown_10;
	DWORD unknown_14;
	SessionOptionsClass Config;
	DWORD UniqueID;
	char Handle [20];
	int PlayerColor;
	DWORD unknown_160;
	DWORD unknown_164;
	DWORD unknown_168;
	DWORD unknown_16C;
	DWORD unknown_170;
	int idxSide;
	int idxSide2;
	int Color;
	int Color2;
	int Side;
	int Side2;
	GameTypePreferencesStruct SkirmishPreferences;
	GameTypePreferencesStruct LANPreferences;
	GameTypePreferencesStruct WOLPreferences;
	byte unknown_300 [8];
	bool WOLLimitResolution;
	int LastNickSlot;

};

#endif
