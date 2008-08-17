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
	static Point2D* CoordsToClient(CoordStruct* pCrd,Point2D* pPoint)
		{
			void* pTactical;
			MEM_READ32(pTactical, TACTICAL_MAP_PTR);
			PUSH_VAR32(pPoint);
			PUSH_VAR32(pCrd);
			THISCALL_EX_RET(pTactical, 0x6D2140, Point2D*);
		}

	static Point2D CoordsToClient(CoordStruct* pCrd)
		{ Point2D P; CoordsToClient(pCrd, &P); return P; }

	
	static CoordStruct* ClientToCoords(Point2D* pPoint,CoordStruct* pCrd)
		{
			void* pTactical;
			MEM_READ32(pTactical, TACTICAL_MAP_PTR);
			PUSH_VAR32(pPoint);
			PUSH_VAR32(pCrd);
			THISCALL_EX_RET(pTactical, 0x6D2280, CoordStruct*);
		}

	static CoordStruct ClientToCoords(Point2D* pPoint)
		{ CoordStruct Crd; ClientToCoords(pPoint, &Crd); return Crd; }
};

#endif
