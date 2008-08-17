#ifndef AIRSTRIKE_H
#define AIRSTRIKE_H

#include <AbstractClass.h>

//forward declarations
class AircraftTypeClass;
class ObjectClass;
class TechnoClass;

//The AirstrikeClass handles the airstrikes Boris calls in.
class AirstrikeClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL_RET(0x41D7A0, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x41D6F0, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x41D780, HRESULT); }

	//Destructor
	
	virtual ~AirstrikeClass()	{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x41DD50);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_Airstrike;}
	virtual int					Size(){return sizeof(AirstrikeClass);}

	//Constructor
	AirstrikeClass(ObjectClass* pOwner):AbstractClass(false)
								{PUSH_VAR32(pOwner);THISCALL(0x41D380);}

	//non-virtual
	void	StartMission(ObjectClass* pTarget){PUSH_VAR32(pTarget);THISCALL(0x41D830);}

protected:
	AirstrikeClass():AbstractClass(false){}
	AirstrikeClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,					AirstrikeTeam);			//As in the INI files.
	PROPERTY(int,					EliteAirstrikeTeam);	//As in the INI files.
	PROPERTY(int,					AirstrikeTeamTypeIndex);	//As in the INI files.
	PROPERTY(int,					EliteAirstrikeTeamTypeIndex);	//As in the INI files.
	PROPERTY(DWORD,					unknown_34);
	PROPERTY(DWORD,					unknown_38);	//unused?
	PROPERTY(bool,					IsOnMission);	//Is the Aircraft on its way?
	PROPERTY(bool,					unknown_bool_3D);
	PROPERTY(DWORD,					TeamDissolveFrame);	//when was the last time this team was invoked and subsequently dissolved
	PROPERTY(int,					AirstrikeRechargeTime);	//As in the INI files.
	PROPERTY(int,					EliteAirstrikeRechargeTime);	//As in the INI files.
	PROPERTY(TechnoClass*,			Owner);		//The unit that called the Airstrike (usually Boris).
	PROPERTY(ObjectClass*,			Target);	//The Airstrike's target.
	PROPERTY(AircraftTypeClass*,	AirstrikeTeamType);	//As in the INI files.
	PROPERTY(AircraftTypeClass*,	EliteAirstrikeTeamType);	//As in the INI files.
	PROPERTY(FootClass*,					FirstObject);
};

#endif
