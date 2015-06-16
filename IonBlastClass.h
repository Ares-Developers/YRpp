/*
	Ion Cannons
	If DisableIonBeam is set, no Ion Beam will be shown but just the impact effect.
	Used by the Psychic Dominator
*/

#pragma once

#include <GeneralDefinitions.h>

class IonBlastClass
{
public:
	static DynamicVectorClass<IonBlastClass *>* const Array;

	static void UpdateAll()
		{ JMP_STD(0x53D310); }

	void Update()
		{ JMP_THIS(0x53CBE0); }

	//Constructor, Destructor
	IonBlastClass(CoordStruct Crd)
		{ JMP_THIS(0x53CB10); }

	~IonBlastClass()
		{ JMP_THIS(0x53CB90); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CoordStruct Location;
	int Lifetime;
	BOOL DisableIonBeam;	//0 = no, 1 = yes

};
