/*
	Base class for all MP gamemodes
*/

#ifndef GAMEMODE_H
#define GAMEMODE_H

//forward declarations
class MPTeam;
class HouseClass;
class CCINIClass;

// these things are fugly, feel free to rewrite if possible

#define INIT_ARGLIST wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, bool AIAllowed, int MPModeIndex
#define INIT_ARGS CSFTitle, CSFTooltip, INIFileName, mapfilter, AIAllowed, MPModeIndex

#define INIT_FUNC(addr) (void __stdcall * Allocate)(INIT_ARGLIST) = (void __stdcall *)(INIT_ARGLIST)addr;

#define UNINIT_FUNC(addr) (void __thiscall * Deallocate)(void *x, int flags) = (void __thiscall *)(void *, int)addr;

struct Initializer
{
	(void __thiscall * Deallocate)(void *x, int flags);
	(void __stdcall * Allocate)(INIT_ARGLIST);
};

#define FACTORY(addr) static Initializer *Init = (Initializer *)addr;

class MPGameModeTypeClass
{
public:
	//global arrays
	static DynamicVectorClass<MPGameModeTypeClass*>* GameModes;

	static UNINIT_FUNC(0x5D7FD0);
	static INIT_FUNC(0);

	//Destructor
	virtual ~MPGameModeTypeClass()
		{ THISCALL(0x0x5D7F20); }

	virtual bool vt_entry_04()
		{ return 0; }

	virtual bool vt_entry_08()
		{ return 0; }

	virtual bool vt_entry_0C(DWORD dwUnk)
		{ return 1; }

	virtual bool vt_entry_10()
		{ THISCALL(0x5D62C0); }

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

	virtual bool vt_entry_34(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x5D5DE0); }

	virtual void vt_entry_38(DWORD dwUnk)
		{ }

	virtual bool AIAllowed()
		{ return this->AIAllowed; }

	virtual bool vt_entry_40()
		{ return 0; }

	virtual signed int vt_entry_44()
		{ THISCALL(0x5D6370); }

	virtual void PopulateTeamDropdown(HWND hWnd, DynamicVectorClass<MPTeam*> *vecTeams, MPTeam *Team)
		{ PUSH_VAR32(Team); PUSH_VAR32(vecTeams); PUSH_VAR32(hWnd); THISCALL(0x5D6450); }

	virtual void DrawTeamDropdown(HWND hWnd, DynamicVectorClass<MPTeam*> *vecTeams, MPTeam *Team)
		{ PUSH_VAR32(Team); PUSH_VAR32(vecTeams); PUSH_VAR32(hWnd); THISCALL(0x5D64C0); }

	virtual void PopulateTeamDropdownForPlayer(HWND hWnd, int idx)
		{ PUSH_VAR32(idx); PUSH_VAR32(hWnd); THISCALL(0x5D6540); }

	//argh! source of fail
	virtual bool vt_entry_54(int a1, int a2, void *ptr, int a4, __int16 a5, int a6, int a7)
		{ if (ptr && (a5 &0xFF00)) delete(ptr); return 0; } // 0x5C0EB0

	//argh! source of fail
	virtual bool vt_entry_58(int a1, int a2, void *ptr, int a4, __int16 a5, int a6, int a7, int a8, int a9)
		{ if (ptr && (a5 &0xFF00)) delete(ptr); return 0; } // 0x5C0E90

	virtual bool vt_entry_5C(DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3)
		{ return 1; }

	virtual bool vt_entry_60()
		{ return 1; }

	virtual bool vt_entry_64()
		{ return 1; }

	virtual bool vt_entry_68()
		{ return 1; }

	virtual int vt_entry_6C()
		{ THISCALL(0x5D6430); }

	virtual int vt_entry_70()
		{ return this->vt_entry_6C(); }

	virtual void vt_entry_74(DWORD dwUnk1, DWORD dwUnk2)
		{ }

	virtual void vt_entry_78(DWORD dwUnk1)
		{ }

	virtual bool vt_entry_7C()
		{ THISCALL(0x5D6790); }

	virtual bool StartingPositionsToHouseBaseCells(char unused)
		{ PUSH_VAR8(unused); THISCALL(0x5D6BE0); }

	virtual bool StartingPositionsToHouseBaseCells2(bool arg)
		{ PUSH_VAR8(arg); THISCALL(0x5D6C70); }

	virtual bool AllyTeams()
		{ THISCALL(0x5D74A0); }

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
		{ if (ptr && (a4 &0xFF00)) delete(ptr); return 0; }

	virtual int vt_entry_B8()
		{ return 0; }

	virtual bool vt_entry_BC()
		{ return 1; }

	virtual void CreateMPTeams(DynamicVectorClass<MPTeam> *vecTeams)
		{ PUSH_VAR32(vecTeams); THISCALL(0x5D6690); }

	virtual CellStruct * AssignStartingPositionsToHouse(CellStruct *result, int idxHouse, 
		DynamicVectorClass<CellStruct> *vecCoords, byte *housesSatisfied)
		{ PUSH_VAR32(result); PUSH_VAR32(idxHouse); PUSH_VAR32(vecCoords); PUSH_VAR32(housesSatisfied); 
			THISCALL(0x5D6890); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ PUSH_VAR32(dwUnused); PUSH_VAR32(House); THISCALL(0x5D7030); }

	virtual bool GenerateStartingUnits(HouseClass *House, int &AmountToSpend)
		{ PUSH_VAR32(AmountToSpend); PUSH_VAR32(House); THISCALL(0x5D70F0); }

protected:
#define MPMODE_CTOR(clsname, addr) \
	MPBattleClass(wchar_t **CSFTitle, wchar_t **CSFTooltip, char **INIFileName, char **mapfilter, \
		bool AIAllowed, int MPModeIndex) \
		{ PUSH_VAR32(MPModeIndex); PUSH_VAR8(AIAllowed); PUSH_VAR32(mapfilter); PUSH_VAR32(INIFileName); \
			PUSH_VAR32(CSFTooltip); PUSH_VAR32(CSFTitle); THISCALL(addr); }

	//Constructor
	MPMODE_CTOR(MPGameModeTypeClass, 0x5D5B60);
	FACTORY(0x7EEE74);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(bool, unknown_4);
	PROPERTY_STRUCT(DynamicVectorClass<MPTeam *>, MPTeams);
	PROPERTY(wchar_t *, CSFTitle);
	PROPERTY(wchar_t *, CSFTooltip);
	PROPERTY(int, MPModeIndex);
	PROPERTY(char, *INIFilename);
	PROPERTY(char, *mapfilter);
	PROPERTY(bool, AIAllowed);
	PROPERTY(CCINIClass, *INI);
	PROPERTY(bool, AlliesAllowed);
	PROPERTY(bool, wolTourney);
	PROPERTY(bool, wolClanTourney);
	PROPERTY(bool, MustAlly);
};


class MPBattleClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPBattleClass()
		{ THISCALL(0x5C0FE0); }

	virtual bool vt_entry_40()
		{ return 1; }

	static (void __stdcall * Deallocate)() = (void __stdcall *)()0x5D7FF0;
	static (void __stdcall * Allocate)(INIT_ARGLIST) = (void __stdcall * Allocate)(INIT_ARGLIST)0x5D8170;

	//Constructor
	MPMODE_CTOR(MPBattleClass, 0x5C0DD0);
	FACTORY(0x7EEEBC);
};


class MPManBattleClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPManBattleClass()
		{ THISCALL(0x5C61A0); }

	static UNINIT_FUNC(0x5D8010);
	static INIT_FUNC(0x5D81B0);

	//Constructor
	MPMODE_CTOR(MPManBattleClass, 0x5C6150);
	FACTORY(0x7EEEB0);
};


class MPFreeForAllClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPFreeForAllClass()
		{ THISCALL(0x5C5E40); }

	virtual bool vt_entry_10()
		{ THISCALL(0x5C5D30); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5C5D40); }

	virtual bool vt_entry_18()
		{ THISCALL(0x5C5D90); }

	virtual bool vt_entry_40()
		{ return 1; }

	virtual void PopulateTeamDropdownForPlayer(HWND hWnd, int idx)
		{ PUSH_VAR32(idx); PUSH_VAR32(hWnd); THISCALL(0x5C5DD0); }

	static UNINIT_FUNC(0x5D8070);
	static INIT_FUNC(0x5D8270);

	//Constructor
	MPMODE_CTOR(MPFreeForAllClass, 0x5C5CE0);
	FACTORY(0x7EEE8C);
};


class MPMegawealthClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPMegawealthClass()
		{ THISCALL(0x5C9440); }

	virtual bool vt_entry_8C()
		{ THISCALL(0x5C9430); }

	//Constructor
	MPMODE_CTOR(MPMegawealthClass, 0x5C93E0);
};


class MPUnholyAllianceClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPUnholyAllianceClass()
		{ THISCALL(0x5CB540); }

	virtual bool vt_entry_10()
		{ THISCALL(0x5CB3F0); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5CB400); }

	virtual bool vt_entry_18()
		{ THISCALL(0x5CB430); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ PUSH_VAR32(dwUnused); PUSH_VAR32(House); THISCALL(0x5CB440); }

	static UNINIT_FUNC(0x5D8050);
	static INIT_FUNC(0x5D8230);

	//Constructor
	MPMODE_CTOR(MPUnholyAllianceClass, 0x5CB3A0);
	FACTORY(0x7EEE98);
};


class MPSiegeClass : public MPGameModeTypeClass 
{
	//Destructor
	virtual ~MPSiegeClass()
		{ THISCALL(0x5CABD0); }

	virtual bool vt_entry_10()
		{ THISCALL(0x5CA680); }

	virtual bool vt_entry_14(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5CA6D0); }

	virtual bool vt_entry_18()
		{ THISCALL(0x5CA7D0); }

	virtual bool AIAllowed()
		{ return 0; }

	virtual bool vt_entry_7C()
		{ return MPGameModeTypeClass::vt_entry_7C(); } // yes they did code this explicitly -_-

	virtual bool StartingPositionsToHouseBaseCells2(bool arg)
		{ PUSH_VAR8(arg); THISCALL(0x5CA800); }

	virtual void CreateMPTeams(DynamicVectorClass<MPTeam> *vecTeams)
		{ PUSH_VAR32(vecTeams); THISCALL(0x5CA9B0); }

	virtual bool SpawnBaseUnits(HouseClass *House, DWORD dwUnused)
		{ PUSH_VAR32(dwUnused); PUSH_VAR32(House); THISCALL(0x5CAA50); }

	static UNINIT_FUNC(0x5D8030);
	static INIT_FUNC(0x5D81F0);

	//Constructor
	MPMODE_CTOR(MPSiegeClass, 0x5CA630);
	FACTORY(0x7EEEA4);
};

#endif
