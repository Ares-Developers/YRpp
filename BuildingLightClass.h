#pragma once

#include <GeneralStructures.h>
#include <ObjectClass.h>

class NOVTABLE BuildingLightClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::BuildingLight;

	//Static
	static constexpr constant_ptr<DynamicVectorClass<BuildingLightClass*>, 0x8B4190u> const Array{};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//Destructor
	virtual ~BuildingLightClass() RX;

	// non-virtual
	void SetBehaviour(SpotlightBehaviour mode)
		{ JMP_THIS(0x436BE0); }

	//Constructor
	BuildingLightClass(ObjectClass* pOwner) noexcept
		: BuildingLightClass(noinit_t())
	{ JMP_THIS(0x435820); }

protected:
	explicit __forceinline BuildingLightClass(noinit_t) noexcept
		: ObjectClass(noinit_t())
	{ }

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
