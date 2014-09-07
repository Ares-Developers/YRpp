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
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//Destructor
	virtual ~BuildingLightClass() RX;

	//Constructor
	BuildingLightClass(ObjectClass *Owner) : ObjectClass(false)
		{ JMP_THIS(0x435820); }

	// non-virtual
	void SetBehaviour(SpotlightBehaviour mode)
		{ JMP_THIS(0x436BE0); }

protected:
	BuildingLightClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	double Speed;
	CoordStruct field_B8;
	CoordStruct field_C4;
	double Acceleration;
	bool Direction;
	SpotlightBehaviour BehaviourMode;
	ObjectClass * FollowingObject;
	TechnoClass * OwnerObject;
};

#endif
