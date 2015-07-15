/*
	Base class for all MP gamemodes
*/

/*
NOTE:
	The game modes should NOT become victims of Operation: The Cleansing,
	since we will possibly want to derive classes from them!

	-pd
*/

#pragma once

#include <GeneralDefinitions.h>
#include <MPTeams.h>

//forward declarations
class HouseClass;
class CCINIClass;

// these things are fugly, feel free to rewrite if possible

/*
#define INIT_ARGLIST wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex
#define INIT_ARGS CSFTitle, CSFTooltip, INIFileName, mapfilter, AIAllowed, MPModeIndex

#define INIT_FUNC(addr) void (__stdcall * Allocate)(INIT_ARGLIST) = void (__stdcall *)(INIT_ARGLIST)addr;

#define UNINIT_FUNC(addr) void (__thiscall * Deallocate)(void *x, int flags) = void(__thiscall *)(void *, int)addr;


struct Initializer
{
	void (__thiscall * Deallocate)(void *x, int flags);
	void (__stdcall * Allocate)(INIT_ARGLIST);
};

#define FACTORY(addr) static Initializer *Init = (Initializer *)addr;

#define MPMODE_CTOR(clsname, addr) \
	clsname( \
		wchar_t **CSFTitle, \
		wchar_t **CSFTooltip, \
		char **INIFileName, \
		char **mapfilter, \
		bool AIAllowed, \
		int MPModeIndex) \
			JMP_THIS(addr);
*/

//BAAAAH THIS FILE IS HELL - rewrite requested :P -pd
//WAAAAH - rewrite in progress :D

class MPGameModeClass
{
public:
	//global arrays
	static DynamicVectorClass<MPGameModeClass*>* GameModes;

	/*
	static UNINIT_FUNC(0x5D7FD0);
	static INIT_FUNC(0);
	*/

	//Destructor
	virtual ~MPGameModeClass()
		{ JMP_THIS(0x5D7F20); }

	virtual bool vt_entry_04()
		{ return 0; }

	virtual bool vt_entry_08()
		{ return 0; }

	virtual bool vt_entry_0C(DWORD dwUnk)
		{ return 1; }

	virtual bool vt_entry_10()
		{ JMP_THIS(0x5D62C0); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ return 1; }

	virtual bool vt_entry_18()
		{ return 1; }

	virtual bool vt_entry_1C(DWORD dwUnk)
		{ return 1; }

	virtual void vt_entry_20()
		{ }

	virtual void vt_entry_24()
		{ }

	virtual signed int vt_entry_28()
		{ return -2; }

	virtual signed int vt_entry_2C()
		{ return this->MustAlly ? 0 : -2; } // (-(this->MustAlly != 0) & 2) - 2;

	virtual signed int vt_entry_30()
		{ return this->AlliesAllowed ? 3 : -2 ; } // (-(this->AlliesAllowed != 0) & 5) - 2

	virtual bool CanAllyWith(int idx)
		{ JMP_THIS(0x5D5DE0); }

	virtual void vt_entry_38(DWORD dwUnk)
		{ }

	virtual bool IsAIAllowed()
		{ return AIAllowed; }

	virtual bool vt_entry_40()
		{ return 0; }

	virtual signed int FirstValidMapIndex()
		{ JMP_THIS(0x5D6370); }

	virtual void PopulateTeamDropdown(HWND hWnd, DynamicVectorClass<MPTeam*> *vecTeams, MPTeam *Team)
		{ JMP_THIS(0x5D6450); }

	virtual void DrawTeamDropdown(HWND hWnd, DynamicVectorClass<MPTeam*> *vecTeams, MPTeam *Team)
		{ JMP_THIS(0x5D64C0); }

	virtual void PopulateTeamDropdownForPlayer(HWND hWnd, int idx)
		{ JMP_THIS(0x5D6540); }

	//argh! source of fail
	virtual bool vt_entry_54(int a1, int a2, void *ptr, int a4, __int16 a5, int a6, int a7)
		{ JMP_THIS(0x5C0EB0); } // 0x5C0EB0

	//argh! source of fail
	virtual bool vt_entry_58(int a1, int a2, void *ptr, int a4, __int16 a5, int a6, int a7, int a8, int a9)
		{ JMP_THIS(0x5C0E90); } // 0x5C0E90

	virtual bool vt_entry_5C(DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3)
		{ return 1; }

	virtual bool vt_entry_60()
		{ return 1; }

	virtual bool vt_entry_64()
		{ return 1; }

	virtual bool vt_entry_68()
		{ return 1; }

	virtual int RandomHumanCountryIndex()
		{ JMP_THIS(0x5D6430); }

	virtual int RandomAICountryIndex()
		{ return this->RandomHumanCountryIndex(); }

	virtual void vt_entry_74(DWORD dwUnk1, DWORD dwUnk2)
		{ }

	virtual void vt_entry_78(DWORD dwUnk1)
		{ }

	virtual bool UnfixAlliances()
		{ JMP_THIS(0x5D6790); }

	virtual bool StartingPositionsToHouseBaseCells(char unused)
		{ JMP_THIS(0x5D6BE0); }

	virtual bool StartingPositionsToHouseBaseCells2(bool arg)
		{ JMP_THIS(0x5D6C70); }

	virtual bool AllyTeams()
		{ JMP_THIS(0x5D74A0); }

	virtual bool vt_entry_8C()
		{ return 1; }

	virtual void vt_entry_90()
		{ }

	virtual void vt_entry_94()
		{ }

	virtual signed int vt_entry_98()
		{ return -1; }

	virtual void vt_entry_9C()
		{ }

	virtual void vt_entry_A0(DWORD dwUnk)
		{ }

	virtual void vt_entry_A4(DWORD dwUnk)
		{ }

	virtual bool vt_entry_A8()
		{ return 0; }

	virtual void vt_entry_AC()
		{ }

	virtual void vt_entry_B0()
		{ }

	virtual bool vt_entry_B4(int a1, void *ptr, int a3, __int16 a4, int a5, int a6, int a7)
		{ JMP_THIS(0); }

	virtual int vt_entry_B8()
		{ return 0; }

	virtual bool vt_entry_BC()
		{ return 1; }

	virtual void CreateMPTeams(DynamicVectorClass<MPTeam> *vecTeams)
		{ JMP_THIS(0x5D6690); }

	virtual CellStruct * AssignStartingPositionsToHouse(CellStruct *result, int idxHouse,
		DynamicVectorClass<CellStruct> *vecCoords, byte *housesSatisfied)
		{ JMP_THIS(0x5D6890); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ JMP_THIS(0x5D7030); }

	virtual bool GenerateStartingUnits(HouseClass *House, int &AmountToSpend)
		{ JMP_THIS(0x5D70F0); }

protected:
	//Constructor
	MPGameModeClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		{ JMP_THIS(0x5D5B60); }

	explicit __forceinline MPGameModeClass(noinit_t)
	{ }
	//FACTORY(0x7EEE74);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	bool unknown_4;
	DynamicVectorClass<MPTeam *> MPTeams;
	wchar_t * CSFTitle;
	wchar_t * CSFTooltip;
	int MPModeIndex;
	char* INIFilename;
	char* MapFilter;
	bool AIAllowed;
	CCINIClass* INI;
	bool AlliesAllowed;
	bool wolTourney;
	bool wolClanTourney;
	bool MustAlly;
};


class MPBattleClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPBattleClass()
		{ JMP_THIS(0x5C0FE0); }

	virtual bool vt_entry_40()
		{ return 1; }

	/*
	static (void __stdcall * Deallocate)() = (void __stdcall *)()0x5D7FF0;
	static (void __stdcall * Allocate)(INIT_ARGLIST) = (void __stdcall * Allocate)(INIT_ARGLIST)0x5D8170;
	*/

	MPBattleClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPBattleClass(noinit_t())
	{ JMP_THIS(0x5D8170); }

protected:
	explicit __forceinline MPBattleClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
	//FACTORY(0x7EEEBC);
};


class MPManBattleClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPManBattleClass()
		{ THISCALL(0x5C61A0); }

	/*
	static UNINIT_FUNC(0x5D8010);
	static INIT_FUNC(0x5D81B0);
	*/

	//Constructor
	MPManBattleClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPManBattleClass(noinit_t())
	{ JMP_THIS(0x5C6150); }

protected:
	explicit __forceinline MPManBattleClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
	//FACTORY(0x7EEEB0);
};


class MPFreeForAllClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPFreeForAllClass()
		{ THISCALL(0x5C5E40); }

	virtual bool vt_entry_10()
		{ JMP_THIS(0x5C5D30); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ JMP_THIS(0x5C5D40); }

	virtual bool vt_entry_18()
		{ JMP_THIS(0x5C5D90); }

	virtual bool vt_entry_40()
		{ return 1; }

	virtual void PopulateTeamDropdownForPlayer(HWND hWnd, int idx)
		{ JMP_THIS(0x5C5DD0); }

	/*
	static UNINIT_FUNC(0x5D8070);
	static INIT_FUNC(0x5D8270);
	*/

	//Constructor
	MPFreeForAllClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPFreeForAllClass(noinit_t())
	{ JMP_THIS(0x5C5CE0); }

protected:
	explicit __forceinline MPFreeForAllClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
	//FACTORY(0x7EEE8C);
};


class MPMegawealthClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPMegawealthClass()
		{ JMP_THIS(0x5C9440); }

	virtual bool vt_entry_8C()
		{ JMP_THIS(0x5C9430); }

	//Constructor
	MPMegawealthClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPMegawealthClass(noinit_t())
	{ JMP_THIS(0x5C93E0); }

protected:
	explicit __forceinline MPMegawealthClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
};


class MPUnholyAllianceClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPUnholyAllianceClass()
		{ JMP_THIS(0x5CB540); }

	virtual bool vt_entry_10()
		{ JMP_THIS(0x5CB3F0); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ JMP_THIS(0x5CB400); }

	virtual bool vt_entry_18()
		{ JMP_THIS(0x5CB430); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ JMP_THIS(0x5CB440); }

	/*
	static UNINIT_FUNC(0x5D8050);
	static INIT_FUNC(0x5D8230);
	*/

	//Constructor
	MPUnholyAllianceClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPUnholyAllianceClass(noinit_t())
	{ JMP_THIS(0x5CB3A0); }

protected:
	explicit __forceinline MPUnholyAllianceClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
	//FACTORY(0x7EEE98);
};


class MPSiegeClass : public MPGameModeClass
{
	//Destructor
	virtual ~MPSiegeClass()
		{ JMP_THIS(0x5CABD0); }

	virtual bool vt_entry_10()
		{ JMP_THIS(0x5CA680); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ JMP_THIS(0x5CA6D0); }

	virtual bool vt_entry_18()
		{ JMP_THIS(0x5CA7D0); }

	virtual bool AIAllowed()
		{ return 0; }

	virtual bool UnfixAlliances()
		{ return MPGameModeClass::UnfixAlliances(); } // yes they did code this explicitly -_-

	virtual bool StartingPositionsToHouseBaseCells2(bool arg)
		{ JMP_THIS(0x5CA800); }

	virtual void CreateMPTeams(DynamicVectorClass<MPTeam> *vecTeams)
		{ JMP_THIS(0x5CA9B0); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ JMP_THIS(0x5CAA50); }

	/*
	static UNINIT_FUNC(0x5D8030);
	static INIT_FUNC(0x5D81F0);
	*/

	//Constructor
	MPSiegeClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex)
		: MPSiegeClass(noinit_t())
	{ JMP_THIS(0x5CA630); }

protected:
	explicit __forceinline MPSiegeClass(noinit_t)
		: MPGameModeClass(noinit_t())
	{ }
	//FACTORY(0x7EEEA4);
};
