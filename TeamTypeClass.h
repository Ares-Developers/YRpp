/*
	[TeamTypes]
*/

#pragma once

#include <AbstractTypeClass.h>
#include <ScriptTypeClass.h>
#include <TaskForceClass.h>

//forward declarations
class FootClass;
class TagClass;
class TeamClass;
class TechnoTypeClass;

class NOVTABLE TeamTypeClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::TeamType;

	//Array
	ABSTRACTTYPE_ARRAY(TeamTypeClass, 0xA8ECA0u);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ PUSH_VAR8(IsGlobal); SET_REG32(ECX, pINI); CALL(0x6F19B0); }

	TeamClass * CreateTeam(HouseClass *pHouse)
		{ JMP_THIS(0x6F09C0); }

	void DestroyAllInstances()
		{ JMP_THIS(0x6F0A70); }

	int GetGroup() const
		{ JMP_THIS(0x6F1870); }

	CellStruct* GetWaypoint(CellStruct *buffer) const
		{ JMP_THIS(0x6F18A0); }

	CellStruct* GetTransportWaypoint(CellStruct *buffer) const
		{ JMP_THIS(0x6F18E0); }

	bool CanRecruitUnit(FootClass* pUnit, HouseClass* pOwner) const
		{ JMP_THIS(0x6F1320); }

	void FlashAllInstances(int Duration)
		{ JMP_THIS(0x6F1F30); }

	TeamClass * FindFirstInstance() const
		{ JMP_THIS(0x6F1F70); }

	void ProcessTaskForce()
		{ JMP_THIS(0x6F1FA0); }

	static void ProcessAllTaskforces()
		{ JMP_STD(0x6F2040); }

	HouseClass* GetHouse() const
		{ JMP_THIS(0x6F2070); }

	//Constructor
	TeamTypeClass(const char* pID) noexcept
		: TeamTypeClass(noinit_t())
	{ JMP_THIS(0x6F06E0); }

protected:
	explicit __forceinline TeamTypeClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int      ArrayIndex;
	int      Group;
	int      VeteranLevel;
	bool     Loadable;
	bool     Full;
	bool     Annoyance;
	bool     GuardSlower;
	bool     Recruiter;
	bool     Autocreate;
	bool     Prebuild;
	bool     Reinforce;
	bool     Whiner;
	bool     Aggressive;
	bool     LooseRecruit;
	bool     Suicide;
	bool     Droppod;
	bool     UseTransportOrigin;
	bool     DropshipLoadout;
	bool     OnTransOnly;
	int      Priority;
	int      Max;
	int      field_BC;
	int      MindControlDecision;
	HouseClass *     Owner;
	int      idxHouse; // idx for MP
	int      TechLevel;
	TagClass* Tag;
	int      Waypoint;
	int      TransportWaypoint;
	int      cntInstances;
	ScriptTypeClass*  ScriptType;
	TaskForceClass*   TaskForce;
	int      IsGlobal;
	int      field_EC;
	bool     field_F0;
	bool     field_F1;
	bool     AvoidThreats;
	bool     IonImmune;
	bool     TransportsReturnOnUnload;
	bool     AreTeamMembersRecruitable;
	bool     IsBaseDefense;
	bool     OnlyTargetHouseEnemy;

};
