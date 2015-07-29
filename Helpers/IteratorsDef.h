#pragma once

#include <Helpers/Iterators.h>
#include <Helpers/Enumerators.h>
#include <CellSpread.h>

#include <algorithm>

void CellRectIterator::process(const std::function<bool(CellClass*)> &action) const {
	// the coords mark the center of the area
	auto topleft = center;
	topleft.X -= static_cast<short>(width / 2);
	topleft.Y -= static_cast<short>(height / 2);

	auto const rect = LTRBStruct{
		topleft.X, topleft.Y, topleft.X + width, topleft.Y + height };

	// take a look at each cell in the rectangle
	for(CellRectEnumerator cell(rect); cell; ++cell) {
		// get this cell and call the action function
		if(auto const pCell = MapClass::Instance->TryGetCellAt(*cell)) {
			if(!action(pCell)) {
				return;
			}
		}
	}
}

void CellRectIterator::process(const std::function<bool(ObjectClass*)> &action) const {
	apply<CellClass>([&action](CellClass* pCell) -> bool {
		for(NextObject object(pCell->GetContent()); object; ++object) {
			if(!action(*object)) {
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
		for(NextObject object(pCell->GetContent()); object; ++object) {
			CoordStruct tmpCoords = object->GetCoords();

			// if it is near enough, do action
			if(coords.DistanceFrom(tmpCoords) <= radius * 256) {
				if(!action(*object)) {
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
		for(NextObject object(pCell->GetContent()); object; ++object) {
			if(!action(*object)) {
				return false;
			}
		}
		return true;
	});
}
