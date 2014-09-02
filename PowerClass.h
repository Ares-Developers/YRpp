#ifndef POWER_H
#define POWER_H

#include <RadarClass.h>

class PowerClass : public RadarClass
{
public:
	//Static
	static PowerClass* Global()
		{ return reinterpret_cast<PowerClass*>(0x87F7E8); }

	//Destructor
	virtual ~PowerClass() RX;

	//Non-virtual

protected:
	//Constructor
	PowerClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	bool unknown_bool_150C;
	TimerStruct unknown_timer_1510;
	DWORD unknown_151C;
	TimerStruct unknown_timer_1520;
	DWORD unknown_152C;
	DWORD unknown_1530;
	DWORD unknown_1534;
	bool unknown_bool_1538;
	int unknown_int_153C;
	int unknown_int_1540;
};

#endif
