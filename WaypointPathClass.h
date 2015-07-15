#pragma once

#include <AbstractClass.h>

// this refers to the "planning mode" waypoints you place with your mouse, not mapping waypoints
class WaypointClass
{
public:
	//need to define a == operator so it can be used in array classes
	bool operator == (const WaypointClass& tWaypoint) const
	{
		return (Coords == tWaypoint.Coords && unknown == tWaypoint.unknown);
	}

	//Properties
	CellStruct Coords;
	DWORD       unknown;
};

class NOVTABLE WaypointPathClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Waypoint;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~WaypointPathClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	WaypointClass * GetWaypoint(int idx) const
		{ JMP_THIS(0x763980); }
	WaypointClass * GetWaypointAfter(int idx) const
		{ JMP_THIS(0x763BA0); }
	bool WaypointExistsAt(WaypointClass *wpt) const
		{ JMP_THIS(0x763A50); }

	// Constructor
	WaypointPathClass(int idx)
		: WaypointPathClass(noinit_t())
	{ JMP_THIS(0x763810); }

protected:
	explicit __forceinline WaypointPathClass(noinit_t)
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int  CurrentWaypointIndex; //seems that way
	DynamicVectorClass<WaypointClass> Waypoints; // actual path waypoints, no *
};
