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

public:

	int Type;
	int RadarX;	//not sure
	int RadarY;	//not sure
	float unknown_float_0C;
	DWORD unknown_10;
	float RotationSpeed;
	DWORD unknown_18;
	float ColorSpeed;
	CellStruct MapCoords;
	TimerStruct unknown_timer_24;	//Rotation timer?
	TimerStruct unknown_timer_30;	//Color timer?
	bool unknown_bool_3C;
	bool unknown_bool_3D;
};

#endif
