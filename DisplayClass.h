#ifndef DISPLAY_H
#define DISPLAY_H

#include <MapClass.h>

class CCINIClass;
class ObjectClass;
class ObjectTypeClass;

class LayerClass : public DynamicVectorClass<ObjectClass*>
{
	virtual bool AddObject(ObjectClass* pObject, bool bUnknown)
		{ JMP_THIS(0x5519B0); }

	virtual void Clear_()
		{ Clear(); }

	void Load(IStream* pStm)
		{ JMP_THIS(0x551B90); }

	void Save(IStream* pStm)
		{ JMP_THIS(0x551B20); }
};

#define		NUM_LAYERS		5

class DisplayClass : public MapClass
{
public:
	//WIP: DisplayClass::TacticalClass goes HERE

	bool ProcessClickCoords(Point2D *src, CellStruct *XYdst, CoordStruct *XYZdst, ObjectClass **Target, BYTE *a5, BYTE *a6)
		{ JMP_THIS(0x692300); }

	//Static
	static DisplayClass* Global()
		{ return reinterpret_cast<DisplayClass*>(0x87F7E8); }

	static LayerClass* GetLayer(Layer::Value lyr)
	{
		if(lyr >= Layer::Underground && lyr <= Layer::Top)
			return reinterpret_cast<LayerClass**>(0x8A0360)[lyr];
		else
			return nullptr;
	}

	// the foundation for placement with green/red
	void  SetActiveFoundation(CellStruct *Coords)
		{ JMP_THIS(0x4A8BF0); }

	//Destructor
	virtual ~DisplayClass() RX;

	//GScreenClass
	//MapClass
	//DisplayClass
	virtual void Load(IStream* pStm) RX;
	virtual void Save(IStream* pStm) RX;
	virtual void LoadFromINI(CCINIClass* pINI) RX; //Loads the map from a map file.
	virtual const wchar_t* GetToolTip(UINT nDlgID) R0;
	virtual void CloseWindow() RX; //prolly wrong naming
	virtual void vt_entry_8C() RX;
	virtual bool vt_entry_90(CellStruct MapCoords, void* pUnk) R0;
	virtual bool vt_entry_94(CellStruct MapCoords, void* pUnk, bool bUnk) R0;
	virtual bool vt_entry_98(CellStruct MapCoords, void* pUnk) R0;
	virtual bool vt_entry_9C(CellStruct MapCoords, void* pUnk) R0;
	virtual void vt_entry_100() = 0;
	virtual bool vt_entry_104(DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual void Set_View_Dimensions(RectangleStruct* pRect) RX;
	virtual void vt_entry_10C(DWORD dwUnk) RX;
	virtual void vt_entry_110(DWORD dwUnk) RX;
	virtual void vt_entry_114(Point2D* pPoint) RX;

	//Decides which mouse pointer to set and then does it.
	//Mouse is over cell pMapCoords which is bShrouded and holds pObject.
	virtual void ConvertAction(
		CellStruct* pMapCoords,
		bool bShrouded,
		ObjectClass* pObject,
		Action action,
		DWORD dwUnk) RX;
	virtual void LeftMouseButtonDown(Point2D* pPoint) RX;
	virtual void LeftMouseButtonUp(
		DWORD dwUnk1,
		CellStruct* pMapCoords,
		ObjectClass* pObject,
		Action action,
		DWORD dwUnk2) RX;
	virtual void RightMouseButtonUp(DWORD dwUnk) RX;

	//Non-virtual

	void LMBUp(CoordStruct *XYZ, CellStruct* pMapCoords, ObjectClass* pObject, Action action, DWORD dwUnk2)
		{ JMP_THIS(0x4AB9B0); }
	void RMBUp(DWORD dwUnk)
		{ JMP_THIS(0x4AAD30); }

	Action DecideAction(CellStruct* pMapCoords, ObjectClass* pObject, DWORD dwUnk)
		{ JMP_THIS(0x692610); }


	/* pass in CurrentFoundationData and receive the width/height of a bounding rectangle in cells */
	CellStruct * FoundationBoundsSize(CellStruct *buffer, CellStruct *FoundationData)
		{ JMP_THIS(0x4A94F0); }

	/* marks or unmarks the cells pointed to by CurrentFoundationData as containing a building */
	void MarkFoundation(CellStruct * BaseCell, bool Mark)
		{ JMP_THIS(0x4A95A0); }

protected:
	//Constructor
	DisplayClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	CellStruct CurrentFoundation_CenterCell;	//Currently placing the building here
	CellStruct CurrentFoundation_TopLeftOffset;		// offset from center cell of the current foundation (under the mouse) to the top left cell
	CellStruct* CurrentFoundation_Data;	//Foundation data of the building we're currently placing (note: limited to 120 cells)
	bool unknown_1180;
	bool unknown_1181;
	CellStruct CurrentFoundationCopy_CenterCell; // this is a copy of the CurrentFoundation data above..
	CellStruct CurrentFoundationCopy_TopLeftOffset;
	CellStruct * CurrentFoundationCopy_Data; // (note: limited to 50 [!] cells)
	DWORD unknown_1190;
	DWORD unknown_1194;
	DWORD unknown_1198;
	bool FollowObject;
	ObjectClass* ObjectToFollow;
	ObjectClass* CurrentBuilding;		//Building we're currently placing
	ObjectTypeClass* CurrentBuildingType;	//Type of that building
	DWORD unknown_11AC;
	bool RepairMode;
	bool SellMode;
	bool PowerToggleMode;
	bool PlanningMode;
	bool PlaceBeaconMode;
	int CurrentSWTypeIndex;	//Index of the SuperWeaponType we have currently selected
	DWORD unknown_11BC;
	DWORD unknown_11C0;
	DWORD unknown_11C4;
	DWORD unknown_11C8;
	bool unknown_bool_11CC;
	bool unknown_bool_11CD;
	bool unknown_bool_11CE;
	bool DraggingRectangle;
	bool unknown_bool_11D0;
	bool unknown_bool_11D1;
	DWORD unknown_11D4;
	DWORD unknown_11D8;
	DWORD unknown_11DC;
	DWORD unknown_11E0;
};

#endif
