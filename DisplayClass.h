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
		{ return (DisplayClass*)0x87F7E8; }

	static LayerClass* GetLayer(eLayer lyr)
	{
		if(lyr >= lyr_Underground && lyr <= lyr_Top)
			return ((LayerClass**)0x8A0360)[lyr];
		else
			return NULL;
	}

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
	//Mouse is over cell pMapCoords which is bShrouded and holds pObject,
	//the Action given is eAction.
	virtual void ConvertAction(
		CellStruct* pMapCoords,
		bool bShrouded,
		ObjectClass* pObject,
		eAction nAction,
		DWORD dwUnk) RX;
	virtual void LeftMouseButtonDown(Point2D* pPoint) RX;
	virtual void LeftMouseButtonUp(
		DWORD dwUnk1,
		CellStruct* pMapCoords,
		ObjectClass* pObject,
		eAction nAction,
		DWORD dwUnk2) RX;
	virtual void RightMouseButtonUp(DWORD dwUnk) RX;

	//Non-virtual

	void LMBUp(CoordStruct *XYZ, CellStruct* pMapCoords, ObjectClass* pObject, eAction nAction, DWORD dwUnk2)
		{ JMP_THIS(0x4AB9B0); }
	void RMBUp(DWORD dwUnk)
		{ JMP_THIS(0x4AAD30); }

	eAction DecideAction(CellStruct* pMapCoords, ObjectClass* pObject, DWORD dwUnk)
		{ JMP_THIS(0x692610); }

protected:
	//Constructor
	DisplayClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRUCT(CellStruct,			CurrentPlacingMapCoords);	//Currently placing the building here
	PROPERTY_STRUCT(CellStruct,			unknown_cell_1178);		//related to the placing foundation
	PROPERTY(CellStruct*,			CurrentFoundationData);	//Foundation data of the building we're currently placing
	PROPERTY(bool,					unknown_1180);
	PROPERTY(bool,					unknown_1181);
	PROPERTY_STRUCT(CellStruct,			unknown_cell_1182);
	PROPERTY_STRUCT(CellStruct,			unknown_cell_1186);
	PROPERTY(DWORD,					unknown_118C);
	PROPERTY(DWORD,					unknown_1190);
	PROPERTY(DWORD,					unknown_1194);
	PROPERTY(DWORD,					unknown_1198);
	PROPERTY(bool,					FollowObject);
	PROPERTY(ObjectClass*,			ObjectToFollow);
	PROPERTY(ObjectClass*,			CurrentBuilding);		//Building we're currently placing
	PROPERTY(ObjectTypeClass*,		CurrentBuildingType);	//Type of that building
	PROPERTY(DWORD,					unknown_11AC);
	PROPERTY(bool,					RepairMode);
	PROPERTY(bool,					SellMode);
	PROPERTY(bool,					PowerToggleMode);
	PROPERTY(bool,					PlanningMode);
	PROPERTY(bool,					PlaceBeaconMode);
	PROPERTY(int,					CurrentSWTypeIndex);	//Index of the SuperWeaponType we have currently selected
	PROPERTY(DWORD,					unknown_11BC);
	PROPERTY(DWORD,					unknown_11C0);
	PROPERTY(DWORD,					unknown_11C4);
	PROPERTY(DWORD,					unknown_11C8);
	PROPERTY(bool,					unknown_bool_11CC);
	PROPERTY(bool,					unknown_bool_11CD);
	PROPERTY(bool,					unknown_bool_11CE);
	PROPERTY(bool,					DraggingRectangle);
	PROPERTY(bool,					unknown_bool_11D0);
	PROPERTY(bool,					unknown_bool_11D1);
	PROPERTY(DWORD,					unknown_11D4);
	PROPERTY(DWORD,					unknown_11D8);
	PROPERTY(DWORD,					unknown_11DC);
	PROPERTY(DWORD,					unknown_11E0);
};

#endif
