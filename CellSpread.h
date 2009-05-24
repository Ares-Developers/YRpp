#ifndef CELLSPREAD_H
#define CELLSPREAD_H

#include <GeneralStructures.h>

class CellSpread
{
public:
	static int NumCells(unsigned int nSpread)
	{
		return ((unsigned int*)0x7ED3D0)[nSpread];
	}

	static CellStruct GetCell(unsigned int n)
	{
		return ((CellStruct*)0xABD490)[n];
	}

	static CellStruct GetNeighbourOffset(unsigned int direction) {
		if(direction > 7) { CellStruct dummy = {0, 0}; return dummy; }
		return ((CellStruct*)0x89F688)[direction];
	}
};

#endif
