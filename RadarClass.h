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
	virtual ~RadarClass() RX;

	//MapClass
	virtual void CreateEmptyMap(RectangleStruct* pMapRect, bool bUnk1, char nLevel, bool bUnk2)
		{ PUSH_VAR8(bUnk2); PUSH_VAR8(nLevel); PUSH_VAR8(bUnk1); PUSH_VAR32(pMapRect); THISCALL(0x653F50); }

	virtual void vt_entry_74(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x654490); }

	//DisplayClass

	//RadarClass
	virtual void DisposeOfArt() RX;
	virtual void* vt_entry_12C(void* out_pUnk, Point2D* pPoint) R0;
	virtual void vt_entry_130(DWORD dwUnk) RX;
	virtual void Init_For_House() RX;

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
