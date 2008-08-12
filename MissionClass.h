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
	virtual ~MissionClass()		{/* ~ObjectClass() */}

	//AbstractClass
	virtual void			CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x5B3970);}
	virtual void			Update(){THISCALL(0x5B3060);}

	//ObjectClass
	virtual eMission		GetCurrentMission(){return (CurrentMission==mission_None) ? 
												QueuedMission : CurrentMission;}

	//MissionClass
	virtual bool			QueueMission(eMission mission, bool start_mission)
	{PUSH_VAR8(start_mission);PUSH_VAR32(mission);THISCALL(0x5B35E0);}
	virtual bool			NextMission(){THISCALL(0x5B3570);}
	virtual void			ForceMission(eMission mission){PUSH_VAR32(mission);THISCALL(0x5B2FD0);}

	virtual void			vt_entry_1F4(eMission mission){PUSH_VAR32(mission);THISCALL(0x5B3650);}
	virtual bool			vt_entry_1F8(){THISCALL(0x5B36B0);}
	virtual bool			vt_entry_1FC(){THISCALL(0x5B3A10);}
	virtual bool			vt_entry_200(){return true;}

	virtual int				Mission_Sleep(){return 450;}
	virtual int				Mission_Harmless(){return 450;}
	virtual int				Mission_Ambush(){return 450;}
	virtual int				Mission_Attack(){return 450;}
	virtual int				Mission_Capture(){return 450;}
	virtual int				Mission_Eaten(){return 450;}
	virtual int				Mission_Guard(){return 450;}
	virtual int				Mission_AreaGuard(){return 450;}
	virtual int				Mission_Harvest(){return 450;}
	virtual int				Mission_Hunt(){return 450;}
	virtual int				Mission_Move(){return 450;}
	virtual int				Mission_Retreat(){return 450;}
	virtual int				Mission_Return(){return 450;}
	virtual int				Mission_Stop(){return 450;}
	virtual int				Mission_Unload(){return 450;}
	virtual int				Mission_Enter(){return 450;}
	virtual int				Mission_Construction(){return 450;}
	virtual int				Mission_Selling(){return 450;}
	virtual int				Mission_Repair(){return 450;}
	virtual int				Mission_Missile(){return 450;}
	virtual int				Mission_Open(){return 450;}
	virtual int				Mission_Rescue(){return 450;}
	virtual int				Mission_Patrol(){return 450;}
	virtual int				Mission_ParaDropApproach(){return 450;}
	virtual int				Mission_ParaDropOverfly(){return 450;}
	virtual int				Mission_Wait(){return 450;}
	virtual int				Mission_SpyPlaneApproach(){return 450;}
	virtual int				Mission_SpyPlaneAOverfly(){return 450;}

	//Constructor
	MissionClass():ObjectClass(false){THISCALL(0x5B2DA0);}

protected:
	MissionClass(bool X):ObjectClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(eMission,				CurrentMission);	//see MISSION definitions
	PROPERTY(eMission,				unknown_mission_B0);	//see MISSION definitions
	PROPERTY(eMission,				QueuedMission);	//see MISSION definitions
	PROPERTY(bool,					unknown_bool_B8);
	PROPERTY(int,					MissionStatus);
	PROPERTY(int,					CurrentMissionStartTime);	//in frames
	PROPERTY(DWORD,					unknown_C4);
	PROPERTY(TimerStruct,			UpdateTimer);
};

#endif
