/*
	Radar notifications
*/

#ifndef RADAREVENT_H
#define RADAREVENT_H

#include <GeneralDefinitions.h>

typedef int RadarEventType;

#define		RADAREVENT_0							0x00
#define		RADAREVENT_1							0x01
#define		RADAREVENT_2							0x02
#define		RADAREVENT_BASEUNDERATTACK				0x03
#define		RADAREVENT_OREMINERUNDERATTACK			0x04
#define		RADAREVENT_5							0x05
#define		RADAREVENT_UNITREADY					0x06
#define		RADAREVENT_UNITLOST						0x07
#define		RADAREVENT_UNITREPAIRED					0x08
#define		RADAREVENT_RADARSABOTAGED				0x09
#define		RADAREVENT_BUILDINGCAPTURED				0x0A
#define		RADAREVENT_BEACONDETECTED				0x0B
#define		RADAREVENT_SUPERWEAPONDETECTED			0x0C
#define		RADAREVENT_SUPERWEAPONLAUNCHED			0x0D
#define		RADAREVENT_BRIDGEREPAIRED				0x0E
#define		RADAREVENT_STRUCTUREABANDONED			0x0F
#define		RADAREVENT_ALLYUNDERATTACK				0x10

class RadarEventClass
{
public:
	static bool Create(int nType,CellStruct nMapCoords)
		{
		PUSH_VAR32(nMapCoords);
		SET_REG32(ecx,nType);
		CALL_RET(0x65FA70, bool); }

private:
	//Constructor, Destructor
	RadarEventClass(int nType,CellStruct nMapCoords)
	{
		PUSH_VAR32(nMapCoords);
		PUSH_VAR32(nType);
		THISCALL(0x65FB80);
	}

	~RadarEventClass()		{/*???*/}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,				Type);
	PROPERTY(int,				RadarX);	//not sure
	PROPERTY(int,				RadarY);	//not sure
	PROPERTY(float,				unknown_float_0C);
	PROPERTY(DWORD,				unknown_10);
	PROPERTY(float,				RotationSpeed);
	PROPERTY(DWORD,				unknown_18);
	PROPERTY(float,				ColorSpeed);
	PROPERTY_STRUCT(CellStruct,		MapCoords);
	PROPERTY_STRUCT(TimerStruct,		unknown_timer_24);	//Rotation timer?
	PROPERTY_STRUCT(TimerStruct,		unknown_timer_30);	//Color timer?
	PROPERTY(bool,				unknown_bool_3C);
	PROPERTY(bool,				unknown_bool_3D);
};

#endif
