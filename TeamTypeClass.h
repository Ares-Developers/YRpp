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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x6F1C40); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6F1BB0); }
	virtual HRESULT _stdcall Save(IStream* pStm,     BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x6F1B90); }

	//Destructor
	virtual ~TeamTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x6F20D0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_TeamType; }
	virtual int Size()
		{ return sizeof(TeamTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x6F1C80); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x6F1090); }

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
