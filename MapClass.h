#ifndef MAP_H
#define MAP_H

#include <GScreenClass.h>
#include <ArrayClasses.h>
#include <CellClass.h>

class WarheadTypeClass;

//Powerup crates
class Crate
{
public:
	//Properties
	PROPERTY_STRUCT(TimerStruct,	CrateTimer);
	PROPERTY_STRUCT(CellStruct,	Location);
};

//ZoneConnectionClass - Holding zone connection info from tubes or bridges (probably used for pathfinding)
struct ZoneConnectionClass
{
	CellStruct	FromMapCoords;
	CellStruct	ToMapCoords;
	bool		unknown_bool_08;
	CellClass*	pCell;

	//need to define a == operator so it can be used in array classes
	bool operator==(ZoneConnectionClass tZoneConnection)
		{
			return (FromMapCoords == tZoneConnection.FromMapCoords &&
					ToMapCoords == tZoneConnection.ToMapCoords &&
					unknown_bool_08 == tZoneConnection.unknown_bool_08 &&
					pCell == tZoneConnection.pCell);
		}
};

struct SubzoneTrackingStruct
{
public:
	BYTE UNKNOWN;	//need information about at least the size of this struct ASAP!

	//need to define a == operator so it can be used in array classes
	bool operator==(SubzoneTrackingStruct tSubzoneTracking)
		{ return (UNKNOWN== tSubzoneTracking.UNKNOWN); }
};

#define MAX_CELLS	0x40000

class MapClass : public GScreenClass
{
public:
	//Static
	static MapClass *Instance;

	static MapClass* Global()
		{ return (MapClass*)0x87F7E8; }

	static CellClass* InvalidCell()
		{ return (CellClass*)0xABDC50; }

	//IGameMap
	virtual long __stdcall Is_Visible(CellStruct cell) R0;

	//Destructor
	virtual ~MapClass() RX;

	//MapClass
	virtual void AllocateCells() RX;
	virtual void DestructCells() RX;
	virtual void ConstructCells() RX;
	virtual void vt_entry_64(DWORD dwUnk1, DWORD dwUnk2) RX;
	virtual bool vt_entry_68() R0;
	virtual void UpdateCrates() RX;
	virtual void CreateEmptyMap(RectangleStruct* pMapRect, bool bUnk1, char nLevel, bool bUnk2) RX;
	virtual void vt_entry_74(DWORD dwUnk) RX;

	//Non-virtual
	CellClass* GetCellAt(CoordStruct* pCrd)
		{ JMP_THIS(0x565730); }

	CellClass* GetCellAt(CellStruct* pMapCoords)
		{
			int n = (pMapCoords->Y << 9) + pMapCoords->X;

			if((n >= 0 && n < MAX_CELLS) && Cells[n]) {
				// && && && && !!
				return Cells[n];
			}

			CellClass* pCell = InvalidCell();

			pCell->set_MapCoords(pMapCoords);
			return pCell;
		}

	bool IsLocationShrouded(CoordStruct* pCrd)
		{ JMP_THIS(0x586360); }

	bool CellExists(CellStruct* pMapCoords)
		{ return (Cells[(pMapCoords->Y << 9) + pMapCoords->X] != NULL);}

	void CellIteratorReset()
		{ JMP_THIS(0x578350); }

	CellClass* CellIteratorNext()
		{ JMP_THIS(0x578290); }

// the key damage delivery
	static int __fastcall DamageArea(
		CoordStruct* Coords,
		int Damage,
		TechnoClass* SourceObject,
		WarheadTypeClass *WH,
		BYTE bUnk,
		HouseClass* SourceHouse)
			{	JMP_STD(0x489280); }

//int a2, int a3, wXY *where, int a5, int a6, int a7, int MovementZone

	int GetCellFloorHeight(CoordStruct* XYZ)
		{ JMP_THIS(0x578080); }

	CellStruct * PickCellOnEdge(CellStruct* buffer, eEdge Edge, CellStruct *CurrentLocation, CellStruct *Fallback,
		eSpeedType SpeedType, bool ValidateReachability, eMovementZone MovZone)
			{ JMP_THIS(0x4AA440); }

// Pathfinding voodoo
// do not touch them, mmkay, they trigger ZoneConnection recalc which is a MUST for firestorm to work

	void Update_Pathfinding_1()
		{ JMP_THIS(0x56C510); }

	void Update_Pathfinding_2(DynamicVectorClass<CellStruct> *where)
		{ JMP_THIS(0x586990); }

// ====================================
//        MAP REVEAL BRAINDAMAGE
// ====================================

/*
 * TechnoClass::Fire uses this for RevealOnFire on player's own units (radius = 3)
 * TechnoClass::See uses this on all (singleCampaign || !MultiplayPassive) units
 * TalkBubble uses this to display the unit to the player
 */
	static void RevealArea1(
		CoordStruct* Coords,
		int Radius,
		HouseClass* OwnerHouse,
		CellStruct arg4,
		BYTE RevealByHeight,
		BYTE arg6,
		BYTE arg7,
		BYTE arg8)
			{ JMP_STD(0x5673A0); }

/*
 * these come in pairs - first the last argument is 0 and then 1

 * AircraftClass::Fire - reveal the target area to the owner (0,0,0,1,x)
 * AircraftClass::See - reveal shroud when on the ground (arg,arg,0,1,x), and fog always (0,0,1,(height < flightlevel/2),x)
 * AnimClass::AnimClass - reveal area to player if anim->Type = [General]DropZoneAnim= (radius = Rules->DropZoneRadius /256) (0,0,0,1,x)
 * BuildingClass::Place - reveal (r = 1) to player if this is ToTile and owned by player (0,0,0,1,x)
 * BuildingClass::Put - reveal (radius = this->Type->Sight ) to owner (0,0,0,1,x)
 * PsychicReveal launch - reveal to user (0,0,0,0,x)
 * ActionClass::RevealWaypoint - reveal RevealTriggerRadius= to player (0,0,0,1,x)
 * ActionClass::RevealZoneOfWaypoint - reveal (r = 2) to player (0,0,0,1,x)
 */
	static void RevealArea2(
		CoordStruct* Coords,
		int Radius,
		HouseClass* OwnerHouse,
		DWORD /*CellStruct*/ arg4,
		BYTE RevealByHeight,
		BYTE arg6,
		BYTE arg7,
		BYTE arg8)
			{ JMP_STD(0x5678E0); }

/*
 * AircraftClass::SpyPlaneApproach
 * AircraftClass::SpyPlaneOverfly
 * AircraftClass::Carryall_Unload
 * BuildingClass::Place - RevealToAll
 * Foot/Infantry Class::Update/UpdatePosition
 * MapClass::RevealArea0 calls this to do the work
 * ParasiteClass::Infect/PointerGotInvalid
 * TechnoClass::Put
 * TechnoClass::Fire uses this (r = 4) right after using RevealArea0, wtfcock
 */
	static void RevealArea3(CoordStruct *Coords, int Height, int Radius, bool SkipReveal)
		{ JMP_STD(0x567DA0); }

// the unknown functions that are srs bsns
	int sub_578080(CoordStruct *Coords)
		{ JMP_THIS(0x578080); }

	// these two slowly reprocess the map after gapgen state changes
	void sub_657CE0()
		{ JMP_THIS(0x657CE0); }

	void sub_4F42F0(int mode)
		{ JMP_THIS(0x4F42F0); }


protected:
	//Constructor
	MapClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,					unknown_10);
	PROPERTY(void*,					unknown_pointer_14);
	PROPERTY_ARRAY(void*, unknown_pointer_array_18, 0xD);
	PROPERTY(DWORD,					unknown_4C);
	PROPERTY_STRUCT(DynamicVectorClass<ZoneConnectionClass>,		ZoneConnections);
	PROPERTY(void*,					unknown_array_68);
	PROPERTY(int,					num_items_in_68);
	PROPERTY(DWORD,					unknown_70);
	PROPERTY(DWORD,					unknown_74);
	PROPERTY(DWORD,					unknown_78);
	PROPERTY(DWORD,					unknown_7C);
	PROPERTY(DWORD,					unknown_80);
	PROPERTY(DWORD,					unknown_84);
	PROPERTY(DWORD,					unknown_88);
	PROPERTY_STRUCT(DynamicVectorClass<SubzoneTrackingStruct>,		SubzoneTracking1);
	PROPERTY_STRUCT(DynamicVectorClass<SubzoneTrackingStruct>,		SubzoneTracking2);
	PROPERTY_STRUCT(DynamicVectorClass<SubzoneTrackingStruct>,		SubzoneTracking3);
	PROPERTY_STRUCT(DynamicVectorClass<CellStruct>,				CellStructs1);
	PROPERTY_STRUCT(RectangleStruct,		MapRect);
	PROPERTY_STRUCT(RectangleStruct,		VisibleRect);
	PROPERTY(int,					CellIterator_NextX);
	PROPERTY(int,					CellIterator_NextY);
	PROPERTY(int,					CellIterator_CurrentY);
	PROPERTY(CellClass*,			CellIterator_NextCell);
	PROPERTY(DWORD,					unknown_11C);
	PROPERTY(DWORD,					unknown_120);
	PROPERTY(DWORD,					unknown_124);
	PROPERTY(DWORD,					unknown_128);
	PROPERTY(DWORD,					unknown_12C);
	PROPERTY(DWORD,					unknown_130);
	PROPERTY(DWORD,					unknown_134);
	PROPERTY_STRUCT(VectorClass<CellClass*>,					Cells);
	PROPERTY(int,					MaxWidth);
	PROPERTY(int,					MaxHeight);
	PROPERTY(int,					MaxNumCells);
	PROPERTY(DWORD, _padding_01);
	PROPERTY(DWORD, _padding_02);
	PROPERTY_STRUCT_ARRAY(Crate, Crates, 0x100);
//	PROPERTY(bool,					unknown_bool_1158);
	PROPERTY_STRUCT(DynamicVectorClass<CellStruct>,				CellStructs2);

};

#endif
