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
	static DynamicVectorClass<IonBlastClass *>* Array;

	//Constructor, Destructor
	IonBlastClass(CoordStruct Crd)
		{ JMP_THIS(0x53CB10); }

	~IonBlastClass()		{/*???*/}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(CoordStruct, Location);
	PROPERTY(int, Lifetime);
	PROPERTY(int, DisableIonBeam);	//0 = no, 1 = yes

};

#endif
