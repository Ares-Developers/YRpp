#ifndef RADAR_H
#define RADAR_H

#include <DisplayClass.h>

class RadarClass : public DisplayClass
{
public:
	//WIP: RadarClass::RTacticalClass goes HERE

	//Static
	static RadarClass* Global()
		{ return (RadarClass*)0x87F7E8; }

	//Destructor
	virtual ~RadarClass()
		{ THISCALL(0x652C00); }

	//GScreenClass
	virtual void One_Time()
		{ THISCALL(0x652CF0); }

	virtual void Init_Clear()
		{ THISCALL(0x652DE0); }

	virtual void vt_entry_20()
		{ THISCALL(0x653010); }

	virtual void Update(DWORD dwUnk1, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL(0x653850); }

	virtual void Draw(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x653100); }

	//MapClass
	virtual void CreateEmptyMap(RectangleStruct* pMapRect, bool bUnk1, char nLevel, bool bUnk2)
		{ 
			PUSH_VAR8(bUnk2);
			PUSH_VAR8(nLevel);
			PUSH_VAR8(bUnk1);
			PUSH_VAR32(pMapRect);
			THISCALL(0x653F50);
		}

	virtual void vt_entry_74(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x654490); }

	//DisplayClass
	virtual void Load(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x6568A0);}

	virtual void Save(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x656AC0);}

	virtual const wchar_t* GetToolTip(UINT nDlgID)
		{ PUSH_VAR32(nDlgID); THISCALL(0x658770); }

	virtual void CloseWindow()	//???
		{ THISCALL(0x654320); }

	virtual bool vt_entry_90(CellStruct MapCoords, void* pUnk)
		{ PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL(0x653810); }

	virtual bool vt_entry_94(CellStruct MapCoords, void* pUnk, bool bUnk)
		{ PUSH_VAR8(bUnk); PUSH_VAR32(pUnk); PUSH_VAR32(MapCoords); THISCALL(0x653830); }

	//RadarClass
	virtual void DisposeOfArt()
		{ THISCALL(0x652D90); }

	virtual void* vt_entry_12C(void* out_pUnk, Point2D* pPoint)
		{ PUSH_VAR32(pPoint); PUSH_VAR32(out_pUnk); THISCALL(0x653760); }

	virtual void vt_entry_130(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x653F70); }

	virtual void Init_For_House()
		{ THISCALL(0x652E90); }

	//Non-virtual

protected:
	//Constructor
	RadarClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,					unknown_11E4);
	PROPERTY(DWORD,					unknown_11E8);
	PROPERTY(DWORD,					unknown_11EC);
	PROPERTY(DWORD,					unknown_11F0);
	PROPERTY(DWORD,					unknown_11F4);
	PROPERTY(DWORD,					unknown_11F8);
	PROPERTY(DWORD,					unknown_11FC);
	PROPERTY(DWORD,					unknown_1200);
	PROPERTY(DWORD,					unknown_1204);
	PROPERTY(DWORD,					unknown_1208);
	PROPERTY_STRUCT(RectangleStruct,		unknown_rect_120C);
	PROPERTY(DWORD,					unknown_121C);
	PROPERTY(DWORD,					unknown_1220);
	PROPERTY_STRUCT(DynamicVectorClass<CellStruct>,	unknown_cells_1124);
	PROPERTY(DWORD,					unknown_123C);
	PROPERTY(DWORD,					unknown_1240);
	PROPERTY(DWORD,					unknown_1244);
	PROPERTY(DWORD,					unknown_1248);
	PROPERTY(DWORD,					unknown_124C);
	PROPERTY(DWORD,					unknown_1250);
	PROPERTY(DWORD,					unknown_1254);
	PROPERTY(DWORD,					unknown_1258);
	PROPERTY_STRUCT(DynamicVectorClass<Point2D>,		unknown_points_125C);
	PROPERTY_STRUCT_ARRAY(DynamicVectorClass<Point2D>, unknown_points_array_1278, 0x16);
	PROPERTY(DWORD,					unknown_1488);
	PROPERTY(int,					unknown_int_148C);
	PROPERTY(DWORD,					unknown_1490);
	PROPERTY(DWORD,					unknown_1494);
	PROPERTY(DWORD,					unknown_1498);
	PROPERTY_STRUCT(RectangleStruct,		unknown_rect_149C);
	PROPERTY(DWORD,					unknown_14AC);
	PROPERTY(DWORD,					unknown_14B0);
	PROPERTY(DWORD,					unknown_14B4);
	PROPERTY(DWORD,					unknown_14B8);
	PROPERTY(bool,					unknown_bool_14BC);
	PROPERTY(bool,					unknown_bool_14BD);
	PROPERTY(DWORD,					unknown_14C0);
	PROPERTY(DWORD,					unknown_14C4);
	PROPERTY(DWORD,					unknown_14C8);
	PROPERTY(DWORD,					unknown_14CC);
	PROPERTY(DWORD,					unknown_14D0);
	PROPERTY(int,					unknown_int_14D4);
	PROPERTY(bool,					IsAvailableNow);
	PROPERTY(bool,					unknown_bool_14D9);
	PROPERTY(bool,					unknown_bool_14DA);
	PROPERTY_STRUCT(RectangleStruct,		unknown_rect_14DC);
	PROPERTY(DWORD,					unknown_14E0);
	PROPERTY(DWORD,					unknown_14E4);
	PROPERTY(DWORD,					unknown_14E8);
	PROPERTY(DWORD,					unknown_14EC);
	PROPERTY(DWORD,					unknown_14F0);
	PROPERTY(DWORD,					unknown_14F4);
	PROPERTY(DWORD,					unknown_14F8);
	PROPERTY(DWORD,					unknown_14FC);
	PROPERTY_STRUCT(TimerStruct,			unknown_timer_1500);
};

#endif
