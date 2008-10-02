#ifndef POWER_H
#define POWER_H

#include <RadarClass.h>

class PowerClass : public RadarClass
{
public:
	//Static
	static PowerClass* Global()
		{ return (PowerClass*)0x87F7E8; }

	//Destructor
	virtual ~PowerClass() RX;

	//RadarClass
	virtual void DisposeOfArt()
		{ THISCALL(0x63F7E0); }

	virtual void Init_For_House()
		{ THISCALL(0x63F7C0); }

	//Non-virtual

protected:
	//Constructor
	PowerClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(bool,					unknown_bool_150C);
	PROPERTY_STRUCT(TimerStruct,			unknown_timer_1510);
	PROPERTY(DWORD,					unknown_151C);
	PROPERTY_STRUCT(TimerStruct,			unknown_timer_1520);
	PROPERTY(DWORD,					unknown_152C);
	PROPERTY(DWORD,					unknown_1530);
	PROPERTY(DWORD,					unknown_1534);
	PROPERTY(bool,					unknown_bool_1538);
	PROPERTY(int,					unknown_int_153C);
	PROPERTY(int,					unknown_int_1540);
};

#endif
