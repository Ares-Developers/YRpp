/*
	Base class for all game objects with missions (yeah... not many).
*/

#ifndef MISSION_H
#define MISSION_H

#include <ObjectClass.h>

class CCINIClass;

class MissionControlClass
{
	public:
		static MissionControlClass* Array()
			{ return reinterpret_cast<MissionControlClass*>(0xA8E3A8); }

		static const char** Names()
			{ return reinterpret_cast<const char**>(0x816CAC); }

		static MissionControlClass* __fastcall Find(const char* pName)
			{ JMP_STD(0x5B3910); }

		MissionControlClass()
			{ JMP_THIS(0x5B3700); }

		const char* GetName()
			{ JMP_THIS(0x5B3740); }

		void LoadFromINI(CCINIClass* pINI)
			{ JMP_THIS(0x5B3760); }

		//Properties
		int ArrayIndex;
		bool NoThreat;
		bool Zombie;
		bool Recruitable;
		bool Paralyzed;
		bool Retaliate;
		bool Scatter;
		double Rate; //default 0.016
		double AARate; //default 0.016
};

class MissionClass : public ObjectClass
{
public:
	//Destructor
	virtual ~MissionClass() { /* ~ObjectClass() */ }

	static eMission __fastcall FindIndex(const char *name)
		{ JMP_STD(0x5B3910); }

	static const char * __fastcall FindName(int const *index)
		{ JMP_STD(0x5B3740); }

	//MissionClass
	virtual bool QueueMission(eMission mission, bool start_mission) R0;
	virtual bool NextMission() R0;
	virtual void ForceMission(eMission mission) RX;

	virtual void vt_entry_1F4(eMission mission) RX;
	virtual bool Mission_Revert() R0;
	virtual bool vt_entry_1FC() const R0;
	virtual bool vt_entry_200() const R0;

	virtual int Mission_Sleep() R0;
	virtual int Mission_Harmless() R0;
	virtual int Mission_Ambush() R0;
	virtual int Mission_Attack() R0;
	virtual int Mission_Capture() R0;
	virtual int Mission_Eaten() R0;
	virtual int Mission_Guard() R0;
	virtual int Mission_AreaGuard() R0;
	virtual int Mission_Harvest() R0;
	virtual int Mission_Hunt() R0;
	virtual int Mission_Move() R0;
	virtual int Mission_Retreat() R0;
	virtual int Mission_Return() R0;
	virtual int Mission_Stop() R0;
	virtual int Mission_Unload() R0;
	virtual int Mission_Enter() R0;
	virtual int Mission_Construction() R0;
	virtual int Mission_Selling() R0;
	virtual int Mission_Repair() R0;
	virtual int Mission_Missile() R0;
	virtual int Mission_Open() R0;
	virtual int Mission_Rescue() R0;
	virtual int Mission_Patrol() R0;
	virtual int Mission_ParaDropApproach() R0;
	virtual int Mission_ParaDropOverfly() R0;
	virtual int Mission_Wait() R0;
	virtual int Mission_SpyPlaneApproach() R0;
	virtual int Mission_SpyPlaneOverfly() R0;

	//Constructor
	MissionClass():ObjectClass(false) { THISCALL(0x5B2DA0); }

protected:
	MissionClass(bool):ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	eMission CurrentMission;	//see MISSION definitions
	eMission unknown_mission_B0;	//see MISSION definitions
	eMission QueuedMission;	//see MISSION definitions
	bool     unknown_bool_B8;
	int      MissionStatus;
	int      CurrentMissionStartTime;	//in frames
	DWORD    unknown_C4;
	TimerStruct UpdateTimer;
};

#endif
