#ifndef BUILDLIGHT_H
#define BUILDLIGHT_H

#include <GeneralStructures.h>
#include <ObjectClass.h>

class BuildingLightClass : public ObjectClass
{
public:
	//Static
	static DynamicVectorClass<BuildingLightClass*>* Array;

	//Destructor
	virtual ~BuildingLightClass() RX;

	//Constructor
	BuildingLightClass(BuildingClass *Owner) : ObjectClass(false)
		{ JMP_THIS(0x435820); }

protected:
	BuildingLightClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(DWORD, field_A8);
	PROPERTY(DWORD, field_AC);
	PROPERTY(DWORD, field_B0);
	PROPERTY(DWORD, field_B4);
	PROPERTY_STRUCT(CoordStruct, field_B8);
	PROPERTY_STRUCT(CoordStruct, field_C4);
	PROPERTY(DWORD, field_D0);
	PROPERTY(DWORD, field_D4);
	PROPERTY(bool, field_D8);
	PROPERTY(eSpotlightBehaviour, BehaviourMode);
	PROPERTY(ObjectClass *, FollowingObject);
	PROPERTY(BuildingClass *, OwnerBuilding);
};

#endif
