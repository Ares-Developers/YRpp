#ifndef PLANNING_TOKEN_H
#define PLANNING_TOKEN_H

#include <AbstractClass.h>

class TechnoClass;

class PlanningTokenClass
{
public:

	void Clear()
		{ JMP_THIS(0x636310); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	TechnoClass * OwnerUnit;
	// more fields should be here
};

#endif
