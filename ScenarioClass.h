#ifndef SCENARIO_H
#define SCENARIO_H

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
	bool bit04 : 1;
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

	// this calls UpdateCellLighting() from above and does other good stuff
	// initializers call it with -1, -1, -1, 0 , map retint actions use current tint * 10, 0
	static void __fastcall RecalcLighting(int R, int G, int B, DWORD dwUnk)
		{ JMP_STD(0x53AD00); }

	//CTOR / DTOR
protected:
	ScenarioClass() { THISCALL(0x6832C0); }
	~ScenarioClass() { THISCALL(0x667A30); }

public:
	//Properties
	PROPERTY(ScenarioFlags, SpecialFlags);
	PROPERTY_STRING(NextScenario, 0x104);
	PROPERTY_STRING(AltNextScenario, 0x104);
	PROPERTY(int, HomeCell); //CellStruct?
	PROPERTY(int, AltHomeCell); //CellStruct?
	PROPERTY(int, UniqueID); //defaults to 1,000,000 - random salt for this game's communications
	PROPERTY_STRUCT(Randomizer, Random); //218
	PROPERTY(DWORD, Difficulty1);
	PROPERTY(DWORD, Difficulty2); // 2 - Difficulty1
	PROPERTY_STRUCT(TimerStruct, ElapsedTime);
	PROPERTY_STRUCT(TimerStruct, Pause);
	PROPERTY(DWORD, unknown_62C);
	PROPERTY(WORD, unknown_630);
	PROPERTY_ARRAY(CellStruct, Waypoints, 702);

	//Map Header
	PROPERTY(int, StartX);
	PROPERTY(int, StartY);
	PROPERTY(int, Width);
	PROPERTY(int, Height);
	PROPERTY(int, NumberStartingPoints);
	PROPERTY_ARRAY(Point2D, StartingPoints, 0x8);
	PROPERTY_ARRAY(int, HouseIndices, 0x10); // starting position => HouseClass::Array->GetItem(#)
	PROPERTY_ARRAY(CellStruct, HouseHomeCells, 0x8);
	PROPERTY(bool, TeamsPresent);
	PROPERTY(int, NumCoopHumanStartSpots);
	PROPERTY_STRUCT(TimerStruct, MissionTimer);
	PROPERTY(wchar_t *, MissionTimerTextCSF);
	PROPERTY_ARRAY(char, MissionTimerText, 32);
	PROPERTY_STRUCT(TimerStruct, ShroudRegrow);
	PROPERTY_STRUCT(TimerStruct, Timer1);
	PROPERTY_STRUCT(TimerStruct, Timer2);
	PROPERTY_STRUCT(TimerStruct, Timer3);
	PROPERTY_STRUCT(TimerStruct, Timer4);
	PROPERTY(int, TechLevel);
	PROPERTY(int, Theater);
	PROPERTY_STRING(FileName, 0x104);
	PROPERTY_UNICODE(Name, 0x2D);
	PROPERTY_STRING(UIName, 0x20);
	PROPERTY_UNICODE(UINameLoaded, 0x2D);

	//Movies
	PROPERTY(const char*, Intro); //Movie name
	PROPERTY(const char*, Brief);
	PROPERTY(const char*, Win);
	PROPERTY(const char*, Lose);
	PROPERTY(const char*, Action);
	PROPERTY(const char*, PostScore);
	PROPERTY(const char*, PreMapSelect);

	PROPERTY_UNICODE(Briefing, 0x400);
	PROPERTY_STRING(BriefingCSF, 0x20);
	PROPERTY(int, ThemeIndex);
	PROPERTY(int, HumanPlayerHouseTypeIndex);
	PROPERTY(double, CarryOverMoney);
	PROPERTY(int, CarryOverCap);
	PROPERTY(int, Percent);

	PROPERTY_ARRAY(Variable, GlobalVariables, 50);
	PROPERTY_ARRAY(Variable, LocalVariables, 100);

	PROPERTY_STRUCT(CellStruct, View1);
	PROPERTY_STRUCT(CellStruct, View2);
	PROPERTY_STRUCT(CellStruct, View3);
	PROPERTY_STRUCT(CellStruct, View4);
	PROPERTY(DWORD, unknown_34A0);
	PROPERTY(bool, FreeRadar); //34A4
	PROPERTY(bool, TrainCrate);
	PROPERTY(bool, TiberiumGrowthEnabled);
	PROPERTY(bool, VeinGrowthEnabled);
	PROPERTY(bool, IceGrowthEnabled); //34A8
	PROPERTY(bool, unknown_bool_34A9);
	PROPERTY(bool, unknown_bool_34AA);
	PROPERTY(bool, unknown_bool_34AB);
	PROPERTY(bool, EndOfGame); //34AC
	PROPERTY(bool, TimerInherit);
	PROPERTY(bool, SkipScore);
	PROPERTY(bool, OneTimeOnly);
	PROPERTY(bool, SkipMapSelect);  //34B0
	PROPERTY(bool, TruckCrate);
	PROPERTY(bool, FillSilos);
	PROPERTY(bool, TiberiumDeathToVisceroid);
	PROPERTY(bool, IgnoreGlobalAITriggers); //34B4
	PROPERTY(bool, unknown_bool_34B5);
	PROPERTY(bool, unknown_bool_34B6);
	PROPERTY(bool, unknown_bool_34B7);
	PROPERTY(int, PlayerSideIndex); //34B8
	PROPERTY(bool, MultiplayerOnly); //34BC
	PROPERTY(bool, IsRandom);
	PROPERTY(DWORD, unknown_34C0);
	PROPERTY(DWORD, unknown_34C4);
	PROPERTY(DWORD, unknown_34C8);
	PROPERTY(int, CampaignIndex);
	PROPERTY(int, StartingDropshipsCount);
	PROPERTY(TypeList<TechnoTypeClass*>, StartingDropships);
	PROPERTY(TypeList<int>, AllowableUnits);
	PROPERTY(TypeList<int>, AllowableUnitMaximums);

	//General Lighting
	PROPERTY(int, AmbientOriginal); // set at map creation
	PROPERTY(int, AmbientCurrent); // current ambient
	PROPERTY(int, AmbientTarget); // target ambient (while changing)
	PROPERTY(int, Red);
	PROPERTY(int, Green);
	PROPERTY(int, Blue);
	PROPERTY(int, Ground); // all these are stored as ini value * 100 + 0.01
	PROPERTY(int, Level); // this one is stored as ini value * 1000 + 0.01

	//Ion lighting
	PROPERTY(int, IonAmbient);
	PROPERTY(int, IonRed);
	PROPERTY(int, IonGreen);
	PROPERTY(int, IonBlue);
	PROPERTY(int, IonGround);
	PROPERTY(int, IonLevel);

	//Nuke flash lighting
	PROPERTY(int, NukeAmbient);
	PROPERTY(int, NukeRed);
	PROPERTY(int, NukeGreen);
	PROPERTY(int, NukeBlue);
	PROPERTY(int, NukeGround);
	PROPERTY(int, NukeLevel);
	PROPERTY(int, NukeAmbientChangeRate);

	//Dominator lighting
	PROPERTY(int, DominatorAmbient);
	PROPERTY(int, DominatorRed);
	PROPERTY(int, DominatorGreen);
	PROPERTY(int, DominatorBlue);
	PROPERTY(int, DominatorGround);
	PROPERTY(int, DominatorLevel);
	PROPERTY(int, DominatorAmbientChangeRate);

	PROPERTY(DWORD, unknown_3598);
	PROPERTY(int, InitTime);
	PROPERTY(DWORD, unknown_35A0);
	PROPERTY(int, ParTimeEasy);
	PROPERTY(int, ParTimeMedium);
	PROPERTY(int, ParTimeDifficult);
	PROPERTY_STRING(UnderParTitle, 0x1F); //35B0
	PROPERTY_STRING(UnderParMessage, 0x1F); //35CF
	PROPERTY_STRING(OverParTitle, 0x1F); //35EE
	PROPERTY_STRING(OverParMessage, 0x1F); //360D
	PROPERTY_STRING(LSLoadMessage, 0x1F); //362C
	PROPERTY_STRING(LSBrief, 0x1F); //364B
	PROPERTY(int, LS640BriefLocX);
	PROPERTY(int, LS640BriefLocY);
	PROPERTY(int, LS800BriefLocX);
	PROPERTY(int, LS800BriefLocY);
	PROPERTY_STRING(LS640BkgdName, 0x40);
	PROPERTY_STRING(LS800BkgdName, 0x40);
	PROPERTY_STRING(LS800BkgdPal, 0x40);
};

#endif
