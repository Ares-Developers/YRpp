#ifndef TACTICAL_H
#define TACTICAL_H

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: Just a few static functions for now
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <GeneralDefinitions.h>

#define		TACTICAL_MAP_PTR		0x887324

class TacticalClass
{
public:
	static TacticalClass* Global()
		{ return *((TacticalClass**)0x887324); }

	Point2D* CoordsToClient(CoordStruct* pCoords, Point2D* pDest)
		JMP_THIS(0x6D2140);
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
			JMP_THIS(0x6D2280);
	/*
	static CoordStruct* ClientToCoords(Point2D* pPoint, CoordStruct* pCrd)
	{
		void* pTactical;
		MEM_READ32(pTactical, TACTICAL_MAP_PTR);
		PUSH_VAR32(pPoint);
		PUSH_VAR32(pCrd);
		THISCALL_EX(pTactical, 0x6D2280);
	}*/
};

#endif
