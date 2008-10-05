/*
	Lasers
*/

#ifndef LASERDRAW_H
#define LASERDRAW_H

#include <GeneralDefinitions.h>

class LaserDrawClass
{
public:
	//Constructor, Destructor
	LaserDrawClass( CoordStruct P1,
					CoordStruct P2,
					ColorStruct InnerColor,
					ColorStruct OuterColor,
					ColorStruct OuterSpread,
					int nDuration)
	{
		PUSH_IMM(0); //???
		PUSH_IMM(0x3FF00000); //???
		PUSH_IMM(1); //???
		PUSH_IMM(0); //???
		PUSH_VAR32(nDuration);
		PUSH_VAR32(OuterSpread);
		PUSH_VAR32(OuterColor);
		PUSH_VAR32(InnerColor);
		PUSH_VAR32(1); //??? bool
		PUSH_VAR32(0); //cutoff
		int X,Y,Z;
		X = P2.X; Y = P2.Y; Z = P2.Z;
		PUSH_VAR32(Z); PUSH_VAR32(Y); PUSH_VAR32(X);
		X = P1.X; Y = P1.Y; Z = P1.Z;
		PUSH_VAR32(Z); PUSH_VAR32(Y); PUSH_VAR32(X);
		THISCALL(0x54FE60);
	}


	~LaserDrawClass() {/*???*/}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROTECTED_PROPERTY(BYTE,  unknown[0x5C]);
};

#endif
