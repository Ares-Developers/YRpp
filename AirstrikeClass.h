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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~AirstrikeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//Constructor
	AirstrikeClass(TechnoClass* pOwner) : AbstractClass(false)
		JMP_THIS(0x41D380);

	//non-virtual
	void StartMission(ObjectClass* pTarget)
		JMP_THIS(0x41D830);

protected:
	AirstrikeClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int, AirstrikeTeam);			//As in the INI files.
	PROPERTY(int, EliteAirstrikeTeam);	//As in the INI files.
	PROPERTY(int, AirstrikeTeamTypeIndex);	//As in the INI files.
	PROPERTY(int, EliteAirstrikeTeamTypeIndex);	//As in the INI files.
	PROPERTY(DWORD, unknown_34);
	PROPERTY(DWORD, unknown_38);	//unused?
	PROPERTY(bool, IsOnMission);	//Is the Aircraft on its way?
	PROPERTY(bool, unknown_bool_3D);
	PROPERTY(DWORD, TeamDissolveFrame);	//when was the last time this team was invoked and subsequently dissolved
	PROPERTY(int, AirstrikeRechargeTime);	//As in the INI files.
	PROPERTY(int, EliteAirstrikeRechargeTime);	//As in the INI files.
	PROPERTY(TechnoClass*, Owner);		//The unit that called the Airstrike (usually Boris).
	PROPERTY(ObjectClass*, Target);	//The Airstrike's target.
	PROPERTY(AircraftTypeClass*, AirstrikeTeamType);	//As in the INI files.
	PROPERTY(AircraftTypeClass*, EliteAirstrikeTeamType);	//As in the INI files.
	PROPERTY(FootClass*, FirstObject);
};

#endif
