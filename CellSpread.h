#ifndef CELLSPREAD_H
#define CELLSPREAD_H

#include <GeneralStructures.h>

#include <iterator>

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
};


#endif
