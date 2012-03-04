#ifndef TEAM_H
#define TEAM_H

#include <TeamTypeClass.h>

class HouseClass;
class FootClass;
class CellClass;
class ScriptClass;

class TeamClass : public AbstractClass
{
public:
	enum {AbsID = abs_Team};

	//Static
	static DynamicVectorClass<TeamClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamClass() RX;

	void GetTaskForceMembers(DynamicVectorClass<TechnoTypeClass *>*dest) const
		{ JMP_THIS(0x6EF4D0); }

	void LiberateMember(FootClass* pFoot, int idx=-1, byte count=0)
		{ JMP_THIS(0x6EA870); }

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//Constructor
	TeamClass(TeamTypeClass* pType) : AbstractClass(false)
		{ JMP_THIS(0x6E8A90); }

protected:
	TeamClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TeamTypeClass* Type;
	ScriptClass*   CurrentScript;
	HouseClass*    Owner;
	HouseClass*    Target;
	CellClass*     SpawnCell;
	DWORD          unknown_38;
	DWORD          unknown_3C;
	DWORD          unknown_40;
	int            unknown_44;
	int            TotalObjects;
	int            TotalThreatValue;
	int            CreationFrame;
	FootClass *    FirstUnit;
	TimerStruct GuardAreaTimer;
	TimerStruct SuspendTimer;
	DWORD          Tag; // TagClass *
	bool           unknown_74;
	bool           unknown_75;
	bool           unknown_76;
	bool           unknown_77;

	bool           unknown_78;
	bool           unknown_79;
	bool           unknown_7A;
	bool           unknown_7B;

	bool           unknown_7C;
	bool           NeedsToDisappear;
	bool           unknown_7E;
	bool           unknown_7F;

	bool           StepCompleted; // can proceed to the next step of the script
	bool           unknown_81;
	bool           unknown_82;
	bool           IsSuspended;

	bool           AchievedGreatSuccess; // executed script action 49, 0
	bool           unknown_85;
	bool           unknown_86;
	bool           unknown_87;

	int CountObjects [6]; // counts of each object specified in the Type
};

#endif
