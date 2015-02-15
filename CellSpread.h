#pragma once

#include <GeneralStructures.h>

class CellSpread
{
public:
	static size_t NumCells(unsigned int nSpread) {
		return reinterpret_cast<size_t*>(0x7ED3D0)[nSpread];
	}

	static const CellStruct& GetCell(size_t n) {
		return reinterpret_cast<const CellStruct*>(0xABD490)[n];
	}

	static const CellStruct& GetNeighbourOffset(size_t direction) {
		if(direction > 7) {
			return CellStruct::Empty;
		}
		return reinterpret_cast<const CellStruct*>(0x89F688)[direction];
	}

	static size_t GetDistance(int dx, int dy) {
		auto x = static_cast<size_t>(std::abs(dx));
		auto y = static_cast<size_t>(std::abs(dy));

		// distance is longer component plus
		// half the shorter component
		if(x > y) {
			return x + y / 2;
		} else {
			return y + x / 2;
		}
	};

	static size_t GetDistance(const CellStruct &offset) {
		return GetDistance(offset.X, offset.Y);
	};
};
