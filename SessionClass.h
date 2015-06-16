#pragma once

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

struct PlayerData {
	byte Data[10];
	PROTECTED_PROPERTY(BYTE, align_A[2])
};

#pragma pack(push, 1)
struct NodeNameType {
	wchar_t Name[20];
	PlayerData Data;
	char Serial[23];
	int Country;
	int InitialCountry;
	int Color;
	int InitialColor;
	int StartPoint;
	int InitialStartPoint;
	int Team;
	int InitialTeam;
	DWORD unknown_int_6B;
	int HouseIndex;
	int Time;
	DWORD unknown_int_77;
	int Clan;
	DWORD unknown_int_7F;
	BYTE unknown_byte_83;
	BYTE unknown_byte_84;
};
#pragma pack(pop)

class SessionClass
{
public:
	static SessionClass* const Instance;

	GameMode GameMode;
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
	PROTECTED_PROPERTY(DWORD, unknown_310[0xE6]);
	char ScenarioFilename[0x202]; // 0x6A8
	PROTECTED_PROPERTY(BYTE, unknown_8AA[0x1F62]);
	DynamicVectorClass<NodeNameType*> unknown_vector_280C;
	DynamicVectorClass<NodeNameType*> unknown_vector_2824;
	DynamicVectorClass<NodeNameType*> StartSpots;
	PROTECTED_PROPERTY(DWORD, unknown_2854[0x221]);
	bool CurrentlyInGame; // at least used for deciding dialog backgrounds
};
