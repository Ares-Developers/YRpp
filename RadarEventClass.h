/*
	Radar notifications
*/

#ifndef RADAREVENT_H
#define RADAREVENT_H

#include <GeneralDefinitions.h>

class RadarEventClass
{
public:
	static bool Create(int nType, CellStruct nMapCoords)
		{ PUSH_VAR32(nMapCoords); SET_REG32(ecx, nType); CALL(0x65FA70); }

private:
	//Constructor, Destructor
	RadarEventClass(int nType, CellStruct nMapCoords)
		{ JMP_THIS(0x65FB80); }

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
