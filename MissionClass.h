/*
	Base class for all game objects with missions (yeah... not many).
*/

#ifndef MISSION_H
#define MISSION_H

#include <ObjectClass.h>

class MissionClass : public ObjectClass
{
public:
	//Destructor
	virtual ~MissionClass() { /* ~ObjectClass() */ }

	static eMission FindIndex(const char *name)
		{ SET_REG32(ECX, name); CALL(0x5B3910); }

	static const char * FindName(int const *index)
		{ SET_REG32(ECX, index); CALL(0x5B3740); }

	//MissionClass
	virtual bool QueueMission(eMission mission, bool start_mission) R0;
	virtual bool NextMission() R0;
	virtual void ForceMission(eMission mission) RX;

	virtual void vt_entry_1F4(eMission mission) RX;
	virtual bool Mission_Revert() R0;
	virtual bool vt_entry_1FC() R0;
	virtual bool vt_entry_200() R0;

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
	virtual int Mission_SpyPlaneAOverfly() R0;

	//Constructor
	MissionClass():ObjectClass(false) { THISCALL(0x5B2DA0); }

protected:
	MissionClass(bool X):ObjectClass(X) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(eMission, CurrentMission);	//see MISSION definitions
	PROPERTY(eMission, unknown_mission_B0);	//see MISSION definitions
	PROPERTY(eMission, QueuedMission);	//see MISSION definitions
	PROPERTY(bool,     unknown_bool_B8);
	PROPERTY(int,      MissionStatus);
	PROPERTY(int,      CurrentMissionStartTime);	//in frames
	PROPERTY(DWORD,    unknown_C4);
	PROPERTY(TimerStruct, UpdateTimer);
};

#endif
