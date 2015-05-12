#pragma once

#include <GeneralDefinitions.h>
#include <Randomizer.h>
#include <ArrayClasses.h>
#include <TechnoTypeClass.h>

struct Variable
{
	char Name[40];
	char Value;
};

struct ScenarioFlags
{
	bool bit00 : 1;
	bool bit01 : 1;
	bool bit02 : 1;
	bool bit03 : 1;
	bool CTFMode : 1; // the base for it does exist...
	bool Inert : 1;
	bool TiberiumGrows : 1;
	bool TiberiumSpreads : 1;

	bool MCVDeploy : 1;
	bool InitialVeteran : 1;
	bool FixedAlliance : 1;
	bool HarvesterImmune : 1;
	bool FogOfWar : 1;
	bool bit13 : 1;
	bool TiberiumExplosive : 1;
	bool DestroyableBridges : 1;

	bool Meteorites : 1;
	bool IonStorms : 1;
	bool Visceroids : 1;
	bool bit19 : 1;
	bool bit20 : 1;
	bool bit21 : 1;
	bool bit22 : 1;
	bool bit23 : 1;

	bool bit24 : 1;
	bool bit25 : 1;
	bool bit26 : 1;
	bool bit27 : 1;
	bool bit28 : 1;
	bool bit29 : 1;
	bool bit30 : 1;
	bool bit31 : 1;
};

class ScenarioClass
{
public:
	//Static
	static ScenarioClass *&Instance;

	static ScenarioClass* Global()
		{ return *((ScenarioClass**)0xA8B230); }

	static void __fastcall UpdateCellLighting()
		{ JMP_STD(0x4AE4C0); }

	static void __fastcall UpdateLighting()
		{ JMP_STD(0x53C280); }

	// this calls UpdateCellLighting() from above and does other good stuff
	// initializers call it with -1, -1, -1, 0 , map retint actions use current tint * 10, 0
	static void __fastcall RecalcLighting(int R, int G, int B, DWORD dwUnk)
		{ JMP_STD(0x53AD00); }

	// valid range [0..701]
	bool IsDefinedWaypoint(int idx)
		{ JMP_THIS(0x68BD80); }

	CellStruct * GetWaypointCoords(CellStruct *dest, int idx)
		{ JMP_THIS(0x68BCC0); }

	CellStruct GetWaypointCoords(int idx) {
		CellStruct dest;
		GetWaypointCoords(&dest, idx);
		return dest;
	}

	//CTOR / DTOR
protected:
	ScenarioClass() { THISCALL(0x6832C0); }
	~ScenarioClass() { THISCALL(0x667A30); }

public:
	//Properties
	ScenarioFlags SpecialFlags;
	char NextScenario [0x104];
	char AltNextScenario [0x104];
	int HomeCell; //CellStruct?
	int AltHomeCell; //CellStruct?
	int UniqueID; //defaults to 1,000,000 - random salt for this game's communications
	Randomizer Random; //218
	DWORD Difficulty1;
	DWORD Difficulty2; // 2 - Difficulty1
	TimerStruct ElapsedTimer;
	TimerStruct PauseTimer;
	DWORD unknown_62C;
	WORD unknown_630;
	CellStruct Waypoints [702];

	//Map Header
	int StartX;
	int StartY;
	int Width;
	int Height;
	int NumberStartingPoints;
	Point2D StartingPoints [0x8];
	int HouseIndices [0x10]; // starting position => HouseClass::Array->GetItem(#)
	CellStruct HouseHomeCells [0x8];
	bool TeamsPresent;
	int NumCoopHumanStartSpots;
	TimerStruct MissionTimer;
	wchar_t * MissionTimerTextCSF;
	char MissionTimerText [32];
	TimerStruct ShroudRegrowTimer;
	TimerStruct FogTimer;
	TimerStruct IceTimer;
	TimerStruct unknown_timer_123c;
	TimerStruct AmbientTimer;
	int TechLevel;
	TheaterType Theater;
	char FileName [0x104];
	wchar_t Name [0x2D];
	char UIName [0x20];
	wchar_t UINameLoaded [0x2D];

	//Movies
	const char* Intro; //Movie name
	const char* Brief;
	const char* Win;
	const char* Lose;
	const char* Action;
	const char* PostScore;
	const char* PreMapSelect;

	wchar_t Briefing [0x400];
	char BriefingCSF [0x20];
	int ThemeIndex;
	int HumanPlayerHouseTypeIndex;
	double CarryOverMoney;
	int CarryOverCap;
	int Percent;

	Variable GlobalVariables [50];
	Variable LocalVariables [100];

	CellStruct View1;
	CellStruct View2;
	CellStruct View3;
	CellStruct View4;
	DWORD unknown_34A0;
	bool FreeRadar; //34A4
	bool TrainCrate;
	bool TiberiumGrowthEnabled;
	bool VeinGrowthEnabled;
	bool IceGrowthEnabled; //34A8
	bool BridgeDestroyed; // RA1 leftover, no logic attached
	bool VariablesChanged; // global or local has been updated 34AA
	bool AmbientChanged; // ambient has been changed 34AB
	bool EndOfGame; //34AC
	bool TimerInherit;
	bool SkipScore;
	bool OneTimeOnly;
	bool SkipMapSelect;  //34B0
	bool TruckCrate;
	bool FillSilos;
	bool TiberiumDeathToVisceroid;
	bool IgnoreGlobalAITriggers; //34B4
	bool unknown_bool_34B5;
	bool unknown_bool_34B6;
	bool unknown_bool_34B7;
	int PlayerSideIndex; //34B8
	bool MultiplayerOnly; //34BC
	bool IsRandom;
	bool PickedUpAnyCrate;
	TimerStruct unknown_timer_34C0;
	int CampaignIndex;
	int StartingDropships;
	TypeList<TechnoTypeClass*> AllowableUnits;
	TypeList<int> AllowableUnitMaximums;
	TypeList<int> DropshipUnitCounts;

	//General Lighting
	int AmbientOriginal; // set at map creation
	int AmbientCurrent; // current ambient
	int AmbientTarget; // target ambient (while changing)
	int Red;
	int Green;
	int Blue;
	int Ground; // all these are stored as ini value * 100 + 0.01
	int Level; // this one is stored as ini value * 1000 + 0.01

	//Ion lighting
	int IonAmbient;
	int IonRed;
	int IonGreen;
	int IonBlue;
	int IonGround;
	int IonLevel;

	//Nuke flash lighting
	int NukeAmbient;
	int NukeRed;
	int NukeGreen;
	int NukeBlue;
	int NukeGround;
	int NukeLevel;
	int NukeAmbientChangeRate;

	//Dominator lighting
	int DominatorAmbient;
	int DominatorRed;
	int DominatorGreen;
	int DominatorBlue;
	int DominatorGround;
	int DominatorLevel;
	int DominatorAmbientChangeRate;

	DWORD unknown_3598;
	int InitTime;
	short Stage;
	bool unknown_35A2;
	BYTE unknown_35A3;
	int ParTimeEasy;
	int ParTimeMedium;
	int ParTimeDifficult;
	char UnderParTitle [0x1F]; //35B0
	char UnderParMessage [0x1F]; //35CF
	char OverParTitle [0x1F]; //35EE
	char OverParMessage [0x1F]; //360D
	char LSLoadMessage [0x1F]; //362C
	char LSBrief [0x1F]; //364B
	int LS640BriefLocX;
	int LS640BriefLocY;
	int LS800BriefLocX;
	int LS800BriefLocY;
	char LS640BkgdName [0x40];
	char LS800BkgdName [0x40];
	char LS800BkgdPal [0x40];
};
