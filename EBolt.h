/*
	Electric Bolts
*/

#ifndef EBOLT_H
#define EBOLT_H

#include <GeneralDefinitions.h>

class EBolt
{
public:
	//Constructor, Destructor
	EBolt(CoordStruct P1,CoordStruct P2,bool bAlternateColor)
	{
		THISCALL(0x4C1E10);

		int X=P2.X;int Y=P2.Y;int Z=P2.Z;
		PUSH_IMM(0);
		PUSH_VAR32(Z);
		PUSH_VAR32(Y);
		PUSH_VAR32(X);
		X=P1.X;Y=P1.Y;Z=P1.Z;
		PUSH_VAR32(Z);
		PUSH_VAR32(Y);
		PUSH_VAR32(X);
		THISCALL(0x4C2A60);
	}

	~EBolt()		{/*???*/}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY_STRUCT(CoordStruct,			Point1);
	PROPERTY_STRUCT(CoordStruct,			Point2);
	PROPERTY(DWORD,					unknown_18);	//Duration?
	PROPERTY(int,					Random);	//Random number between 0 and 256
	PROPERTY(TechnoClass*,			Owner);
	PROPERTY(DWORD,					unknown_24);
	PROPERTY(int,					unknown_int_28);
	PROPERTY(bool,					AlternateColor);

};

#endif
