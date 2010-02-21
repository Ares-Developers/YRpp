#ifndef GAMEMODEOPTIONSCLASS_H_
#define GAMEMODEOPTIONSCLASS_H_

#include <wchar.h>

class StartingSlotClass;

struct StartAISlots
{
	int AIDifficulties[8];
	StartingSlotClass *StartingSpots[8];
	int Colours[8];
	int Starts[8];
	int Teams[8];
};


class GameModeOptionsClass
{
public:
	static GameModeOptionsClass *Instance;

	int MPModeIndex;
	int ScenarioIndex;
	char Bases;
	int Money;
	char BridgeDestruction;
	char Crates;
	char ShortGame;
	char SWAllowed;
	char BuildOffAlly;
	int GameSpeed;
	char MultiEngineer;
	int UnitCount;
	int AIPlayers;
	int AIDifficulty;
	StartAISlots AISlots;
	char AlliesAllowed;
	char HarvesterTruce;
	char CTF;
	char FogOfWar;
	char MCVRedeploy;
	wchar_t wchars[45];
};

#endif
