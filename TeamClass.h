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

	void GetTaskForceMembers(DynamicVectorClass<TechnoTypeClass *>*dest)
		JMP_THIS(0x6EF4D0);

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	TeamClass(TeamTypeClass* pType) : AbstractClass(false)
		JMP_THIS(0x6E8A90);

protected:
	TeamClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TeamTypeClass*, Type);
	PROPERTY(ScriptClass*,   CurrentScript);
	PROPERTY(HouseClass*,    Owner);
	PROPERTY(HouseClass*,    Target);
	PROPERTY(CellClass*,     SpawnCell);
	PROPERTY(DWORD,          unknown_38);
	PROPERTY(DWORD,          unknown_3C);
	PROPERTY(DWORD,          unknown_40);
	PROPERTY(int,            unknown_44);
	PROPERTY(int,            TotalObjects);
	PROPERTY(int,            TotalThreatValue);
	PROPERTY(int,            CreationFrame);
	PROPERTY(FootClass *,    FirstUnit);
	PROPERTY_STRUCT(TimerStruct, GuardAreaTimer);
	PROPERTY_STRUCT(TimerStruct, SuspendTimer);
	PROPERTY(DWORD,          Tag); // TagClass *
	PROPERTY(bool,           unknown_74);
	PROPERTY(bool,           unknown_75);
	PROPERTY(bool,           unknown_76);
	PROPERTY(bool,           unknown_77);

	PROPERTY(bool,           unknown_78);
	PROPERTY(bool,           unknown_79);
	PROPERTY(bool,           unknown_7A);
	PROPERTY(bool,           unknown_7B);

	PROPERTY(bool,           unknown_7C);
	PROPERTY(bool,           NeedsToDisappear);
	PROPERTY(bool,           unknown_7E);
	PROPERTY(bool,           unknown_7F);

	PROPERTY(bool,           StepCompleted); // can proceed to the next step of the script
	PROPERTY(bool,           unknown_81);
	PROPERTY(bool,           unknown_82);
	PROPERTY(bool,           IsSuspended);

	PROPERTY(bool,           AchievedGreatSuccess); // executed script action 49, 0
	PROPERTY(bool,           unknown_85);
	PROPERTY(bool,           unknown_86);
	PROPERTY(bool,           unknown_87);

	PROPERTY_ARRAY(int,      CountObjects, 6); // counts of each object specified in the Type
};

#endif
