#ifndef MAP_H
#define MAP_H

#include <GScreenClass.h>
#include <ArrayClasses.h>
#include <CellClass.h>

//Powerup crates
class Crate
{
public:
	//Properties
	PROPERTY(TimerStruct,	CrateTimer);
	PROPERTY(CellStruct,	Location);
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
	static MapClass* Global()
		{ return (MapClass*)0x87F7E8; }

	static CellClass* InvalidCell()
		{ return (CellClass*)0xABDC50; }

	//IGameMap
	virtual long _stdcall Is_Visible(CellStruct cell)
		{ PUSH_VAR32(cell); PUSH_VAR32(this); CALL(0x5656D0); }

	//Destructor
	virtual ~MapClass()
		{ THISCALL(0x5652C0); }

	//GScreenClass
	virtual void One_Time()
		{ THISCALL(0x565800); }

	virtual void Init_Clear()
		{ THISCALL(0x5659F0); }

	//MapClass
	virtual void AllocateCells()
		{ THISCALL(0x565AA0); }

	virtual void DestructCells()
		{ THISCALL(0x565B00); }

	virtual void ConstructCells()
		{ THISCALL(0x565BC0); }

	virtual void vt_entry_64(DWORD dwUnk1, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL(0x4F4BB0); }

	virtual bool vt_entry_68()
		{ return false; }

	virtual void UpdateCrates()
		{ THISCALL(0x56BBE0); }

	virtual void CreateEmptyMap(RectangleStruct* pMapRect, bool bUnk1, char nLevel, bool bUnk2)
		{ 
			PUSH_VAR8(bUnk2);
			PUSH_VAR8(nLevel);
			PUSH_VAR8(bUnk1);
			PUSH_VAR32(pMapRect);
			THISCALL(0x565C10);
		}

	virtual void vt_entry_74(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x567230); }

	//Non-virtual
	CellClass* GetCellAt(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x565730); }

	CellClass* GetCellAt(CellStruct* pMapCoords)
		{
			int n = (pMapCoords->Y << 9) + pMapCoords->X;

			if((n >= 0 || n < MAX_CELLS) && Cells[n])
				return Cells[n];

			CellClass* pCell = InvalidCell();

			pCell->set_MapCoords(*pMapCoords);
			return pCell;
		}

	bool IsLocationShrouded(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x586360); }

	bool CellExists(CellStruct* pMapCoords)
		{ return (Cells[(pMapCoords->Y << 9) + pMapCoords->X] != NULL);}

	void CellIteratorReset()
		{ THISCALL(0x578350); }

	CellClass* CellIteratorNext()
		{ THISCALL(0x578290); }

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
	PROPERTY_STRUCT_ARRAY(Crate, Crates, 0x100);
	PROPERTY(bool,					unknown_bool_1158);
	PROPERTY_STRUCT(DynamicVectorClass<CellStruct>,				CellStructs2);

};

class CellSpread
{
public:
	static int NumCells(int nSpread)
		{
			int* CSNTable=(int*)0x7ED3D0;
			return CSNTable[nSpread];
		}

	static CellStruct GetCell(int n)
		{
			CellStruct* CSTable=(CellStruct*)0xABD490;
			return CSTable[n];
		}
};


#endif
