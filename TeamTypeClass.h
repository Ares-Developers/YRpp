/*
	[TeamTypes]
*/

#ifndef TEAMTYPE_H
#define TEAMTYPE_H

#include <AbstractTypeClass.h>

//forward declarations
class TechnoTypeClass;
class TeamClass;

class TeamTypeClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(TeamTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	static bool LoadFromINIList(CCINIClass *pINI, bool IsGlobal)
		{ PUSH_VAR8(IsGlobal); SET_REG32(ECX, pINI); CALL(0x6F19B0); }

	//Constructor
	TeamTypeClass(const char* pID):AbstractTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x6F06E0); }

	TeamClass * CreateTeam(HouseClass *pHouse)
		{ PUSH_VAR32(pHouse); THISCALL(0x6F09C0); }

	void DestroyAllInstances()
		{ THISCALL(0x6F0A70); }

	int GetGroup()
		{ THISCALL(0x6F1870); }

	CellStruct* GetWaypoint(CellStruct *buffer)
		{ PUSH_VAR32(buffer); THISCALL(0x6F18A0); }

	CellStruct* GetTransportWaypoint(CellStruct *buffer)
		{ PUSH_VAR32(buffer); THISCALL(0x6F18E0); }

	bool CanRecruitUnit(FootClass *Unit, HouseClass *Owner)
		{ PUSH_VAR32(Owner); PUSH_VAR32(Unit); THISCALL(0x6F1320); }

	void FlashAllInstances(int Duration)
		{ PUSH_VAR32(Duration); THISCALL(0x6F1F30); }

	TeamClass * FindFirstInstance()
		{ THISCALL(0x6F1F70); }

	void ProcessTaskforce()
		{ THISCALL(0x6F1FA0); }

	static void ProcessAllTaskforces()
		{ CALL(0x6F2040); }

	HouseClass* GetHouse()
		{ THISCALL(0x6F2070); }

protected:
	TeamTypeClass():AbstractTypeClass(false)
		{ }
	TeamTypeClass(bool X):AbstractTypeClass(X)
		{ }

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
