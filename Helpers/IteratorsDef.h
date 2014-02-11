#ifndef HELPER_ITERATORS_DEF_H
#define HELPER_ITERATORS_DEF_H

#include <Helpers/Iterators.h>
#include <Helpers/Enumerators.h>
#include <CellSpread.h>

#include <algorithm>

void CellRectIterator::process(const std::function<bool(CellClass*)> &action) const {
	// the coords mark the center of the area
	CellStruct offset = center;
	offset.X -= static_cast<short>(width / 2);
	offset.Y -= static_cast<short>(height / 2);

	// take a look at each cell in the rectangle
	for(short i = 0; i<height; ++i) {
		for(short j = 0; j<width; ++j) {
			// get the specific cell coordinates
			CellStruct cell = {j, i};
			cell += offset;

			// get this cell and call the action function
			if(CellClass* pCell = MapClass::Instance->TryGetCellAt(cell)) {
				if(!action(pCell)) {
					return;
				}
			}
		}
	}
}

void CellRectIterator::process(const std::function<bool(ObjectClass*)> &action) const {
	apply<CellClass>([&action](CellClass* pCell) -> bool {
		for(auto pObject = pCell->GetContent(); pObject; pObject = pObject->NextObject) {
			if(!action(pObject)) {
				return false;
			}
		}
		return true;
	});
}

void CellRangeIterator::process(const std::function<bool(CellClass*)> &action) const {
	// get all cells in a square around the target.
	int range = static_cast<int>(std::floor(radius + 0.99f)) * 2 + 1;
	CellRectIterator inner(center, range, range);
	inner.apply<CellClass>([this, &action](CellClass* pCell) -> bool {
		if(center.DistanceFrom(pCell->MapCoords) <= radius) {
			return action(pCell);
		}

		// continue
		return true;
	});
}

void CellRangeIterator::process(const std::function<bool(ObjectClass*)> &action) const {
	// get target cell coords
	CoordStruct coords = CellClass::Cell2Coord(center);

	apply<CellClass>([this, &action, &coords](CellClass* pCell) -> bool {
		for(auto pObject = pCell->GetContent(); pObject; pObject = pObject->NextObject) {
			CoordStruct tmpCoords = pObject->GetCoords();

			// if it is near enough, do action
			if(coords.DistanceFrom(tmpCoords) <= radius * 256) {
				if(!action(pObject)) {
					return false;
				}
			}
		}
		return true;
	});
}

void CellSpreadIterator::process(const std::function<bool(CellClass*)> &action) const {
	auto legacy = std::min(spread, 10u);
	auto count = CellSpread::NumCells(legacy);
	for(auto i = 0u; i < count; ++i) {
		if(CellClass* pCell = MapClass::Instance->TryGetCellAt(center + CellSpread::GetCell(i))) {
			if(!action(pCell)) {
				return;
			}
		}
	}
	
	for(CellSpreadEnumerator i(spread, 11); i; ++i) {
		if(CellClass* pCell = MapClass::Instance->TryGetCellAt(center + *i)) {
			if(!action(pCell)) {
				break;
			}
		}
	}
}

void CellSpreadIterator::process(const std::function<bool(ObjectClass*)> &action) const {
	apply<CellClass>([&action](CellClass* pCell) -> bool {
		for(auto pObject = pCell->GetContent(); pObject; pObject = pObject->NextObject) {
			if(!action(pObject)) {
				return false;
			}
		}
		return true;
	});
}

#endif
