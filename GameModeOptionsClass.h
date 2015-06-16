#pragma once

#include <wchar.h>

class StartingSlotClass;

struct AISlotsStruct
{
	int AIDifficulties[8];
	StartingSlotClass* StartingSpots[8];
	int Colours[8];
	int Starts[8];
	int Teams[8];
};

class GameModeOptionsClass
{
public:
	// this is the same as SessionClass::Instance->Config
	static GameModeOptionsClass* const Instance;

	int MPModeIndex;
	int ScenarioIndex;
	bool Bases;
	int Money;
	bool BridgeDestruction;
	bool Crates;
	bool ShortGame;
	bool SWAllowed;
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
	wchar_t MapDescription[45];
};
