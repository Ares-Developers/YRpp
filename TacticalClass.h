#pragma once

#include <GeneralDefinitions.h>
#include <GeneralStructures.h>
#include <AbstractClass.h>
#include <ColorScheme.h>

class NOVTABLE TacticalClass : public AbstractClass
{
public:
	static TacticalClass* Global()
		{ return *reinterpret_cast<TacticalClass**>(0x887324); }

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

	int GetOcclusion(const CellStruct& cell, bool fog) const
		{ JMP_THIS(0x6D8700); }

	Point2D * AdjustForZShapeMove(Point2D* pDest, Point2D* pClient)
		{ JMP_THIS(0x6D1FE0); }

	// convert xyz height to xy height?
	static int __fastcall AdjustForZ(int Height)
		{ JMP_STD(0x6D20E0); }

	void FocusOn(CoordStruct* pDest, int Velocity)
		{ JMP_THIS(0x6D2420); }


	// called when area needs to be marked for redrawing due to external factors
	// - alpha lights, terrain changes like cliff destruction, etc
	void RegisterDirtyArea(RectangleStruct Area, bool bUnk)
		{ JMP_THIS(0x6D2790); }

	void RegisterCellAsVisible(CellClass* pCell)
		{ JMP_THIS(0x6DA7D0) };

	static int DrawTimer(int index, ColorScheme *Scheme, int Time, wchar_t *Text, Point2D *someXY1, Point2D *someXY2)
		{ JMP_STD(0x64DB50); }

public:

	DWORD field_24;
	DWORD field_28;
	DWORD field_2C;
	DWORD field_30;
	DWORD field_34;
	DWORD field_38;
	DWORD field_3C;
	DWORD field_40;
	DWORD field_44;
	DWORD field_48;
	DWORD field_4C;
	DWORD field_50;
	DWORD field_54;
	DWORD field_58;
	DWORD field_5C;
	DWORD field_60;
	DWORD field_64;
	DWORD field_68;
	DWORD field_6C;
	DWORD field_70;
	DWORD field_74;
	DWORD field_78;
	DWORD field_7C;
	DWORD field_80;
	DWORD field_84;
	DWORD field_88;
	DWORD field_8C;
	DWORD field_90;
	DWORD field_94;
	DWORD field_98;
	DWORD field_9C;
	DWORD field_A0;
	DWORD field_A4;
	DWORD field_A8;
	bool field_AC;
	bool field_AD;
	RectangleStruct VisibleArea;
	double ZoomInFactor;
	DWORD field_C8;
	DWORD field_CC;
	DWORD field_D0;
	DWORD field_D4;
	DWORD field_D8;
	DWORD field_DC;
	DWORD VisibleCellCount;
	CellClass * VisibleCells [800];
	DWORD field_D64;
	DWORD field_D68;
	DWORD field_D6C;
	DWORD field_D70;
	DWORD field_D74;
	DWORD field_D78;
	bool field_D7C;
	bool Redrawing; // set while redrawing - cheap mutex
	DWORD field_D80;
	DWORD field_D84;
	DWORD field_D88;
	DWORD field_D8C;
	DWORD field_D90;
	DWORD field_D94;
	DWORD field_D98;
	DWORD field_D9C;
	DWORD MouseFrameIndex;
	DWORD StartTime;
	DWORD field_DA8;
	DWORD field_DAC;
	float Floats [12];
	RectangleStruct field_DE4;
	DWORD field_DF4;
	double field_DF8;
	DWORD field_E00;
	DWORD field_E04;
	double field_E08;
	DWORD field_E10;
	DWORD field_E14;

};
