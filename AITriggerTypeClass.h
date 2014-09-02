/*
	[AITriggerTypes]
*/

#ifndef AITRIGTYPE_H
#define AITRIGTYPE_H

#include <YRPP.h>
#include <HouseTypeClass.h>
#include <TeamTypeClass.h>
#include <AbstractTypeClass.h>

//forward declarations
class TechnoTypeClass;
class TeamTypeClass;

struct AITriggerConditionComparator
{
	int ComparatorType;
	int ComparatorOperand;
};

class AITriggerTypeClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_AITriggerType};

	//Array
	ABSTRACTTYPE_ARRAY(AITriggerTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~AITriggerTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	static bool LoadFromINIList(CCINIClass *pINI)
		{ JMP_STD(0x41F2E0); }

	// Global == saving into AI.ini as opposed to map?
	// if !Global, [AITriggerTypesEnable] gets saved as well
	static bool SaveToINIList(CCINIClass *pINI, bool Global)
		{ JMP_STD(0x41F490); }

	// non-virtual

	// teams finished script, and
	void RegisterSuccess()
		{ JMP_THIS(0x41FD60); }

	void RegisterFailure()
		{ JMP_THIS(0x41FE20); }

	// the main condition
	bool ConditionMet(HouseClass *CallingHouse, HouseClass *TargetHouse, bool EnoughBaseDefense) const
		{ JMP_THIS(0x41E720); }

	// slaves
	bool OwnerHouseOwns(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41EE90); }

	bool CivilianHouseOwns(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41EC90); }

	bool EnemyHouseOwns(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41EAF0); }

	bool IronCurtainCharged(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41F0D0); }

	bool ChronoSphereCharged(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41F180); }

	bool HouseCredits(HouseClass *CallingHouse, HouseClass *TargetHouse) const
		{ JMP_THIS(0x41F230); }

	void FormatForSaving(char * buffer, size_t size) const {
		const char *Team1Name = "<none>";
		const char *Team2Name = "<none>";
		const char *HouseName = "<none>";
		const char *ConditionName = "<none>";

		TeamTypeClass *T = this->Team1;
		if(T) {
			Team1Name = T->get_ID();
		}
		T = this->Team2;
		if(T) {
			Team2Name = T->get_ID();
		}

		if(this->OwnerHouseType == th_Single) {
			int HouseIndex = this->HouseIndex;
			if(HouseIndex != -1) {
				HouseName = HouseTypeClass::Array->GetItem(HouseIndex)->get_ID();
			}
		} else if(this->OwnerHouseType == th_Any) {
			HouseName = "<all>";
		}

		TechnoTypeClass *O = this->ConditionObject;
		if(O) {
			ConditionName = O->get_ID();
		}

		char ConditionString[68];
		int idx = 0;
		char * condStr = ConditionString;
		auto buf = reinterpret_cast<const byte*>(&this->Conditions);
		do {
			sprintf_s(condStr, 4, "%02x", *buf);
			++buf;
			++idx;
			condStr += 2;
		} while(idx < 0x20 );
		*condStr = '\0';

		sprintf_s(buffer, size, "%s = %s,%s,%s,%d,%d,%s,%s,%lf,%lf,%lf,%d,%d,%d,%d,%s,%d,%d,%d\n",
			this->ID,
			this->Name,
			Team1Name,
			HouseName,
			this->TechLevel,
			this->ConditionType,
			ConditionName,
			ConditionString,
			this->Weight_Current,
			this->Weight_Minimum,
			this->Weight_Maximum,
			this->IsForSkirmish != 0,
			0,
			this->SideIndex,
			this->IsForBaseDefense != 0,
			Team2Name,
			this->Enabled_Easy != 0,
			this->Enabled_Normal != 0,
			this->Enabled_Hard != 0
		);

	}

	//Constructor
	AITriggerTypeClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x41E350); }

protected:
	AITriggerTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	eAITrigCondition ConditionType;
	int              IsGlobal;
	eAITrigHouseType OwnerHouseType;
	bool             IsEnabled;
	int              HouseIndex;
	int              SideIndex;
	int              TechLevel;
	int              unknown_B4;
	double           Weight_Current;
	double           Weight_Minimum;
	double           Weight_Maximum;
	bool             IsForSkirmish;
	bool             IsForBaseDefense;
	bool             Enabled_Easy;
	bool             Enabled_Normal;
	bool             Enabled_Hard;
	TechnoTypeClass* ConditionObject;
	TeamTypeClass*   Team1;
	TeamTypeClass*   Team2;
	AITriggerConditionComparator Conditions [4]; // don't ask
	int              TimesExecuted;
	int              TimesCompleted;
	int              unknown_10C;

};

#endif
