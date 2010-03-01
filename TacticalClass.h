#ifndef TACTICAL_H
#define TACTICAL_H

#include <GeneralDefinitions.h>
#include <GeneralStructures.h>
#include <AbstractClass.h>
#include <ColorScheme.h>

class TacticalClass : public AbstractClass
{
public:
	static TacticalClass* Global()
		{ return *((TacticalClass**)0x887324); }

	static TacticalClass * &Instance;

	Point2D* CoordsToClient(CoordStruct* pCoords, Point2D* pDest)
		{ JMP_THIS(0x6D2140); }
	/*
	static Point2D* CoordsToClient(CoordStruct* pCrd, Point2D* pPoint)
	{
		void* pTactical;
		MEM_READ32(pTactical, TACTICAL_MAP_PTR);
		PUSH_VAR32(pPoint);
		PUSH_VAR32(pCrd);
		THISCALL_EX(pTactical, 0x6D2140);
	}*/

	CoordStruct* ClientToCoords(Point2D* pClient, CoordStruct* pDest)
			{ JMP_THIS(0x6D2280); }
	/*
	static CoordStruct* ClientToCoords(Point2D* pPoint, CoordStruct* pCrd)
	{
		void* pTactical;
		MEM_READ32(pTactical, TACTICAL_MAP_PTR);
		PUSH_VAR32(pPoint);
		PUSH_VAR32(pCrd);
		THISCALL_EX(pTactical, 0x6D2280);
	}*/

	Point2D * AdjustForZShapeMove(Point2D* pDest, Point2D* pClient)
		{ JMP_THIS(0x6D1FE0); }

	// convert xyz height to xy height?
	static int AdjustForZ(int Height)
		{ JMP_THIS(0x6D20E0); }

	void FocusOn(CoordStruct* pDest, int Velocity)
		{ JMP_THIS(0x6D2420); }


	// called when area needs to be marked for redrawing due to external factors
	// - alpha lights, terrain changes like cliff destruction, etc
	void RegisterDirtyArea(RectangleStruct Area, bool bUnk)
		{ JMP_THIS(0x6D2790); }

	static int DrawTimer(int index, ColorScheme *Scheme, int Time, wchar_t *Text, Point2D *someXY1, Point2D *someXY2)
		{ JMP_STD(0x64DB50); }

	PROPERTY(DWORD, field_24);
	PROPERTY(DWORD, field_28);
	PROPERTY(DWORD, field_2C);
	PROPERTY(DWORD, field_30);
	PROPERTY(DWORD, field_34);
	PROPERTY(DWORD, field_38);
	PROPERTY(DWORD, field_3C);
	PROPERTY(DWORD, field_40);
	PROPERTY(DWORD, field_44);
	PROPERTY(DWORD, field_48);
	PROPERTY(DWORD, field_4C);
	PROPERTY(DWORD, field_50);
	PROPERTY(DWORD, field_54);
	PROPERTY(DWORD, field_58);
	PROPERTY(DWORD, field_5C);
	PROPERTY(DWORD, field_60);
	PROPERTY(DWORD, field_64);
	PROPERTY(DWORD, field_68);
	PROPERTY(DWORD, field_6C);
	PROPERTY(DWORD, field_70);
	PROPERTY(DWORD, field_74);
	PROPERTY(DWORD, field_78);
	PROPERTY(DWORD, field_7C);
	PROPERTY(DWORD, field_80);
	PROPERTY(DWORD, field_84);
	PROPERTY(DWORD, field_88);
	PROPERTY(DWORD, field_8C);
	PROPERTY(DWORD, field_90);
	PROPERTY(DWORD, field_94);
	PROPERTY(DWORD, field_98);
	PROPERTY(DWORD, field_9C);
	PROPERTY(DWORD, field_A0);
	PROPERTY(DWORD, field_A4);
	PROPERTY(DWORD, field_A8);
	PROPERTY(bool, field_AC);
	PROPERTY(bool, field_AD);
	PROPERTY_STRUCT(RectangleStruct, VisibleArea);
	PROPERTY(double, ZoomInFactor);
	PROPERTY(DWORD, field_C8);
	PROPERTY(DWORD, field_CC);
	PROPERTY(DWORD, field_D0);
	PROPERTY(DWORD, field_D4);
	PROPERTY(DWORD, field_D8);
	PROPERTY(DWORD, field_DC);
	PROPERTY(DWORD, VisibleCellCount);
	PROPERTY_ARRAY(CellClass *, VisibleCells, 800);
	PROPERTY(DWORD, field_D64);
	PROPERTY(DWORD, field_D68);
	PROPERTY(DWORD, field_D6C);
	PROPERTY(DWORD, field_D70);
	PROPERTY(DWORD, field_D74);
	PROPERTY(DWORD, field_D78);
	PROPERTY(bool, field_D7C);
	PROPERTY(bool, Redrawing); // set while redrawing - cheap mutex
	PROPERTY(DWORD, field_D80);
	PROPERTY(DWORD, field_D84);
	PROPERTY(DWORD, field_D88);
	PROPERTY(DWORD, field_D8C);
	PROPERTY(DWORD, field_D90);
	PROPERTY(DWORD, field_D94);
	PROPERTY(DWORD, field_D98);
	PROPERTY(DWORD, field_D9C);
	PROPERTY(DWORD, MouseFrameIndex);
	PROPERTY(DWORD, StartTime);
	PROPERTY(DWORD, field_DA8);
	PROPERTY(DWORD, field_DAC);
	PROPERTY_ARRAY(float, Floats, 12);
	PROPERTY_STRUCT(RectangleStruct, field_DE4);
	PROPERTY(DWORD, field_DF4);
	PROPERTY(double, field_DF8);
	PROPERTY(DWORD, field_E00);
	PROPERTY(DWORD, field_E04);
	PROPERTY(double, field_E08);
	PROPERTY(DWORD, field_E10);
	PROPERTY(DWORD, field_E14);

};

#endif
