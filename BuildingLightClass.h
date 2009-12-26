#ifndef BUILDLIGHT_H
#define BUILDLIGHT_H

#include <GeneralStructures.h>
#include <ObjectClass.h>

class BuildingLightClass : public ObjectClass
{
public:
	enum {AbsID = abs_BuildingLight};

	//Static
	static DynamicVectorClass<BuildingLightClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//Destructor
	virtual ~BuildingLightClass() RX;

	//Constructor
	BuildingLightClass(ObjectClass *Owner) : ObjectClass(false)
		JMP_THIS(0x435820);

protected:
	BuildingLightClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

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
	PROPERTY(TechnoClass *, OwnerObject);
};

#endif
