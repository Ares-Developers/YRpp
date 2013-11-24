#ifndef HELPER_ITERATORS_DEF_H
#define HELPER_ITERATORS_DEF_H

#include <Helpers/Iterators.h>
#include <CellSpread.h>

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
	apply<CellClass>([&action](CellClass* pCell) {
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
	inner.apply<CellClass>([this, &action](CellClass* pCell) {
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

	apply<CellClass>([this, &action, &coords](CellClass* pCell) {
		for(auto pObject = pCell->GetContent(); pObject; pObject = pObject->NextObject) {
			CoordStruct tmpCoords;
			pObject->GetCoords(&tmpCoords);

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
	// get all cells in a square around the target.
	size_t range = spread * 2 + 1;
	CellRectIterator inner(center, range, range);
	inner.apply<CellClass>([this, &action](CellClass* pCell) {
		CellStruct delta = pCell->MapCoords - center;
		auto distance = CellSpread::GetDistance(delta);

		// invoke action if in spread
		if(distance <= spread) {
			return action(pCell);
		}

		// continue
		return true;
	});
}

void CellSpreadIterator::process(const std::function<bool(ObjectClass*)> &action) const {
	apply<CellClass>([&action](CellClass* pCell) {
		for(auto pObject = pCell->GetContent(); pObject; pObject = pObject->NextObject) {
			if(!action(pObject)) {
				return false;
			}
		}
		return true;
	});
}

#endif
