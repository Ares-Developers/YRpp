#ifndef CELLSPREAD_H
#define CELLSPREAD_H

#include <GeneralStructures.h>

class CellSpread
{
public:
	static int NumCells(int nSpread)
	{
		return ((int*)0x7ED3D0)[nSpread];
	}

	static CellStruct GetCell(int n)
	{
		return ((CellStruct*)0xABD490)[n];
	}
};

#endif
