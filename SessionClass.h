#ifndef SESSIONCLASS_H_
#define SESSIONCLASS_H_

#include <GeneralDefinitions.h>
#include <MPGameModeClass.h>
#include <GameModeOptionsClass.h>

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

class SessionClass
{
public:
	static SessionClass* Instance;

	GameMode::Value GameMode;
	MPGameModeClass* MPGameMode;
	DWORD unknown_08;
	DWORD unknown_0C;
	DWORD unknown_10;
	DWORD unknown_14;
	GameModeOptionsClass Config;
	DWORD UniqueID;
	char Handle[20];
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
	BOOL MuteSWLaunches;
	byte unknown_304[4];
	bool WOLLimitResolution;
	int LastNickSlot;
	byte unknown_310[0x2DC8];
};

#endif
