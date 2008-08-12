/*
	Ion Cannons
	If DisableIonBeam is set, no Ion Beam will be shown but just the impact effect.
	Used by the Psychic Dominator
*/

#ifndef IONBLAST_H
#define IONBLAST_H

#include <GeneralDefinitions.h>

class IonBlastClass
{
public:
	//Constructor, Destructor
	IonBlastClass(CoordStruct Crd)
	{
		int X = Crd.X;
		int Y = Crd.Y;
		int Z = Crd.Z;

		PUSH_VAR32(Z);
		PUSH_VAR32(Y);
		PUSH_VAR32(X);
		THISCALL(0x53CB10);
	}

	~IonBlastClass()		{/*???*/}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY_STRUCT(CoordStruct,		Location);
	PROPERTY(int,				Lifetime);
	PROPERTY(int,				DisableIonBeam);	//0 = no, 1 = yes

};

#endif
