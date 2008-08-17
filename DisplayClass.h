#ifndef DISPLAY_H
#define DISPLAY_H

#include <MapClass.h>

class ObjectClass;

class LayerClass : public DynamicVectorClass<ObjectClass*>
{
	virtual bool AddObject(ObjectClass* pObject, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(pObject); THISCALL_RET(0x5519B0, bool); }

	virtual void Clear_()
		{ Clear(); }

	void Load(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x551B90);}

	void Save(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x551B20);}
};

#define		NUM_LAYERS		5

class DisplayClass : public MapClass
{
public:
	//WIP: DisplayClass::TacticalClass goes HERE

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
	virtual ~DisplayClass()
		{ THISCALL(0x5652C0); }

	//GScreenClass
	virtual void One_Time()
		{ THISCALL(0x4A8850); }

	virtual void Init_Clear()
		{ THISCALL(0x4A88C0); }

	virtual void vt_entry_20()
		{ THISCALL(0x4A8930); }

	virtual void Update(DWORD dwUnk1, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL(0x4A9700); }

	//MapClass

	//DisplayClass
	virtual void Load(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x4AE6F0);}

	virtual void Save(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x4AE720);}

	virtual void LoadFromINI(CCINIClass* pINI)	//Loads the map from a map file.
		{ PUSH_VAR32(pINI); THISCALL(0x4ACE70); }

	virtual const wchar_t* GetToolTip(UINT nDlgID)
		{ PUSH_VAR32(nDlgID); THISCALL_RET(0x4AE4F0, const wchar_t*); }

	virtual void CloseWindow()	//???
		{ THISCALL(0x4AE6B0); }

	virtual void vt_entry_8C()
		{ THISCALL(0x4AEAD0); }
	virtual bool vt_entry_90(CellStruct MapCoords, void* pUnk)
		{ PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL_RET(0x4A9890, bool); }
	virtual bool vt_entry_94(CellStruct MapCoords, void* pUnk, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL_RET(0x4A9CA0, bool); }
	virtual bool vt_entry_98(CellStruct MapCoords, void* pUnk)
		{ PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL_RET(0x4A9DD0, bool); }
	virtual bool vt_entry_9C(CellStruct MapCoords, void* pUnk)
		{ PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL_RET(0x4AA050, bool); }

	virtual void vt_entry_100() = 0;
	virtual bool vt_entry_104(DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL_RET(0x4A9840, bool); }

	virtual void Set_View_Dimensions(RectangleStruct* pRect)
		{ PUSH_VAR32(pRect); THISCALL(0x4A8960); }

	virtual void vt_entry_10C(DWORD dwUnk) { }
	virtual void vt_entry_110(DWORD dwUnk) { }

	virtual void vt_entry_114(Point2D* pPoint)
		{ PUSH_VAR32(pPoint); THISCALL(0x4AC310); }

	//Decides which mouse pointer to set and then does it.
	//Mouse is over cell pMapCoords which is bShrouded and holds pObject,
	//the Action given is eAction.
	virtual void ConvertAction(
		CellStruct* pMapCoords,
		bool bShrouded,
		ObjectClass* pObject,
		eAction nAction,
		DWORD dwUnk)
		{
			PUSH_VAR32(dwUnk);
			PUSH_VAR32(nAction);
			PUSH_VAR32(pObject);
			PUSH_VAR8(bShrouded);
			PUSH_VAR32(pMapCoords);
			THISCALL(0x4AAE90);
		}
	
	virtual void LeftMouseButtonDown(Point2D* pPoint)
		{ PUSH_VAR32(pPoint); THISCALL(0x4AC380); }

	virtual void LeftMouseButtonUp(
		DWORD dwUnk1,
		CellStruct* pMapCoords,
		ObjectClass* pObject,
		eAction nAction,
		DWORD dwUnk2)
		{
			PUSH_VAR32(dwUnk2);
			PUSH_VAR32(nAction);
			PUSH_VAR32(pObject);
			PUSH_VAR32(pMapCoords);
			PUSH_VAR32(dwUnk1);
			THISCALL(0x4AB9B0);
		}

	virtual void RightMouseButtonUp(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4AAD30); }

	//Non-virtual

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
	PROPERTY(bool,					unknown_bool_11CF);
	PROPERTY(bool,					unknown_bool_11D0);
	PROPERTY(bool,					unknown_bool_11D1);
	PROPERTY(DWORD,					unknown_11D4);
	PROPERTY(DWORD,					unknown_11D8);
	PROPERTY(DWORD,					unknown_11DC);
	PROPERTY(DWORD,					unknown_11E0);
};

#endif
