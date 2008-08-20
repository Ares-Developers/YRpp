#ifndef WAYPOINTPATH_H
#define WAYPOINTPATH_H

#include <AbstractClass.h>

// this refers to the "planning mode" waypoints you place with your mouse, not mapping waypoints
class WaypointClass
{
public:
	//need to define a == operator so it can be used in array classes
	bool operator == (WaypointClass tWaypoint)
	{
		return (Coords == tWaypoint.get_Coords() &&
				unknown == tWaypoint.get_unknown());
	}

	//Properties
	PROPERTY(CellStruct,  Coords);
	PROPERTY(DWORD,       unknown);
};

class WaypointPathClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x763C30); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x763C70); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x763D90); }
	
	//Destructor
	virtual ~WaypointPathClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x763E20); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_Waypoint; } // not waypointpath -_-
	virtual int Size()
		{ return sizeof(WaypointPathClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x763C00); }

	WaypointClass * GetWaypoint(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x763980); }
	WaypointClass * GetWaypointAfter(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x763BA0); }
	bool WaypointExistsAt(WaypointClass *wpt)
		{ PUSH_VAR32(wpt); THISCALL(0x763A50); }

	// Constructor
	WaypointPathClass(int idx)
		{ PUSH_VAR32(idx); THISCALL(0x763810); }

protected:
	//Constructor
	WaypointPathClass():AbstractClass(false)
		{ }
	WaypointPathClass(bool X):AbstractClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,  CurrentWaypointIndex); //seems that way
	PROPERTY_STRUCT(DynamicVectorClass<WaypointClass>,  Waypoints); // actual path waypoints, no *
};

#endif
