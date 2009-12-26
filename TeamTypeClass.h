/*
	[TeamTypes]
*/

#ifndef TEAMTYPE_H
#define TEAMTYPE_H

#include <AbstractTypeClass.h>
#include <ScriptTypeClass.h>
#include <TaskForceClass.h>

//forward declarations
class TechnoTypeClass;
class TeamClass;

class TeamTypeClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_TeamType};

	//Array
	ABSTRACTTYPE_ARRAY(TeamTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ PUSH_VAR8(IsGlobal); SET_REG32(ECX, pINI); CALL(0x6F19B0); }

	TeamClass * CreateTeam(HouseClass *pHouse)
		JMP_THIS(0x6F09C0);

	void DestroyAllInstances()
		JMP_THIS(0x6F0A70); 

	int GetGroup()
		JMP_THIS(0x6F1870);

	CellStruct* GetWaypoint(CellStruct *buffer)
		JMP_THIS(0x6F18A0);

	CellStruct* GetTransportWaypoint(CellStruct *buffer)
		JMP_THIS(0x6F18E0);

	bool CanRecruitUnit(FootClass *Unit, HouseClass *Owner)
		JMP_THIS(0x6F1320);

	void FlashAllInstances(int Duration)
		JMP_THIS(0x6F1F30);

	TeamClass * FindFirstInstance()
		JMP_THIS(0x6F1F70);

	void ProcessTaskForce()
		JMP_THIS(0x6F1FA0);

	static void ProcessAllTaskforces()
		JMP_STD(0x6F2040);

	HouseClass* GetHouse()
		JMP_THIS(0x6F2070);

	//Constructor
	TeamTypeClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x6F06E0);

protected:
	TeamTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,      ArrayIndex);
	PROPERTY(int,      Group);
	PROPERTY(int,      VeteranLevel);
	PROPERTY(bool,     Loadable);
	PROPERTY(bool,     Full);
	PROPERTY(bool,     Annoyance);
	PROPERTY(bool,     GuardSlower);
	PROPERTY(bool,     Recruiter);
	PROPERTY(bool,     Autocreate);
	PROPERTY(bool,     Prebuild);
	PROPERTY(bool,     Reinforce);
	PROPERTY(bool,     Whiner);
	PROPERTY(bool,     Aggressive);
	PROPERTY(bool,     LooseRecruit);
	PROPERTY(bool,     Suicide);
	PROPERTY(bool,     Droppod);
	PROPERTY(bool,     UseTransportOrigin);
	PROPERTY(bool,     field_B2);
	PROPERTY(bool,     OnTransOnly);
	PROPERTY(int,      Priority);
	PROPERTY(int,      Max);
	PROPERTY(int,      field_BC);
	PROPERTY(int,      MindControlDecision);
	PROPERTY(HouseClass *,     Owner);
	PROPERTY(int,      idxHouse); // idx for MP
	PROPERTY(int,      TechLevel);
	PROPERTY(DWORD,    Tag); // TagClass *
	PROPERTY(int,      Waypoint);
	PROPERTY(int,      TransportWaypoint);
	PROPERTY(int,      cntInstances);
	PROPERTY(ScriptTypeClass*,  ScriptType);
	PROPERTY(TaskForceClass*,   TaskForce);
	PROPERTY(int,      IsGlobal);
	PROPERTY(int,      field_EC);
	PROPERTY(bool,     field_F0);
	PROPERTY(bool,     field_F1);
	PROPERTY(bool,     AvoidThreats);
	PROPERTY(bool,     IonImmune);
	PROPERTY(bool,     TransportsReturnOnUnload);
	PROPERTY(bool,     AreTeamMembersRecruitable);
	PROPERTY(bool,     IsBaseDefense);
	PROPERTY(bool,     OnlyTargetHouseEnemy);

};

#endif
