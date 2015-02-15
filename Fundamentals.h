#pragma once

/*
These globals are so important and fundamental that no other files should be
included for them to be available.
*/
namespace Unsorted
{
	static const int& CurrentFrame = *reinterpret_cast<int*>(0xA8ED84);

	// The height in the middle of a cell with a slope of 30 degrees
	const int LevelHeight = 104;
	// tan(deg2rad(90) - deg2rad(60)) * sqrt(2 * 256 ^ 2) * 0.5
	// cot(deg2rad(30)) * diagonal_leptons_per_cell * 0.5
	// sqrt(3)/3 * 362.038 * 0.5
}
