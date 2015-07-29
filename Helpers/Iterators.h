#pragma once

#include <GeneralStructures.h>
#include <ObjectClass.h>
#include <CellClass.h>
#include <CellSpread.h>
#include <MapClass.h>

#include <Helpers/Enumerators.h>

// Invokes an action on objects of a certain type in a rectangle.
/*
	The rectangle is defined by width and height. If width and/or height are
	even, center does not mark the center of the rectangle due to rounding.

	action could be invoked on an object more than once. For CellClass, action
	is invoked only once.

	\author AlexB
*/
template <typename T>
struct CellRectIterator
{
	template <typename Func>
	void operator () (LTRBStruct bounds, Func&& action) const {
		CellRectIterator<ObjectClass>{}(bounds, [&action](ObjectClass* const pObject)
		{
			if(auto const pItem = abstract_cast<T*>(pObject)) {
				if(!action(pItem)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellRectIterator<ObjectClass>
{
	template <typename Func>
	void operator () (LTRBStruct bounds, Func&& action) const {
		CellRectIterator<CellClass>{}(bounds, [&action](CellClass* const pCell)
		{
			for(NextObject object(pCell->GetContent()); object; ++object) {
				if(!action(*object)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellRectIterator<CellClass> {
	template <typename Func>
	void operator () (LTRBStruct bounds, Func&& action) const {
		for(CellRectEnumerator cell(bounds); cell; ++cell) {
			if(auto const pCell = MapClass::Instance->TryGetCellAt(*cell)) {
				if(!action(pCell)) {
					return;
				}
			}
		}
	}
};

// Invokes an action on objects of a certain type in a range.
/*
	The range defines a circle around the center. action is invoked on objects
	whose distance from the center is equal to or less than radius.

	action could be invoked on an object more than once. For CellClass, action
	is invoked only once.

	\author AlexB
*/
template <typename T>
struct CellRangeIterator
{
	template <typename Func>
	void operator () (CellStruct const center, double radius, Func&& action) const {
		CellRangeIterator<ObjectClass>{}(center, radius, [&action](ObjectClass* const pObject)
		{
			if(auto const pItem = abstract_cast<T*>(pObject)) {
				if(!action(pItem)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellRangeIterator<ObjectClass>
{
	template <typename Func>
	void operator () (CellStruct const center, double radius, Func&& action) const {
		CellRangeIterator<CellClass>{}(center, radius, [&action](CellClass* const pCell)
		{
			for(NextObject object(pCell->GetContent()); object; ++object) {
				if(!action(*object)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellRangeIterator<CellClass> {
	template <typename Func>
	void operator () (CellStruct const center, double radius, Func&& action) const {
		for(CellRangeEnumerator cell(center, radius); cell; ++cell) {
			if(auto const pCell = MapClass::Instance->TryGetCellAt(*cell)) {
				if(!action(pCell)) {
					return;
				}
			}
		}
	}
};

// Invokes an action on objects of a certain type in CellSpread range.
/*
	The affected area is defined by a CellSpread range. action is invoked on
	cells whose CellSpread distance from the center is equal to or less than
	this spread range, or on objects residing on such cells.

	action could be invoked on an object more than once. For CellClass, action
	is invoked only once.

	\author AlexB
*/
template <typename T>
struct CellSpreadIterator
{
	template <typename Func>
	void operator () (CellStruct const center, size_t const spread, Func&& action) const {
		CellSpreadIterator<ObjectClass>{}(center, spread, [&action](ObjectClass* const pObject)
		{
			if(auto const pItem = abstract_cast<T*>(pObject)) {
				if(!action(pItem)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellSpreadIterator<ObjectClass>
{
	template <typename Func>
	void operator () (CellStruct const center, size_t const spread, Func&& action) const {
		CellSpreadIterator<CellClass>{}(center, spread, [&action](CellClass* const pCell)
		{
			for(NextObject object(pCell->GetContent()); object; ++object) {
				if(!action(*object)) {
					return false;
				}
			}
			return true;
		});
	}
};

template <>
struct CellSpreadIterator<CellClass> {
	template <typename Func>
	void operator () (CellStruct const center, size_t const spread, Func&& action) const {
		auto const legacy = std::min(spread, 10u);
		auto const count = CellSpread::NumCells(legacy);
		for(auto i = 0u; i < count; ++i) {
			if(auto const pCell = MapClass::Instance->TryGetCellAt(center + CellSpread::GetCell(i))) {
				if(!action(pCell)) {
					return;
				}
			}
		}

		for(CellSpreadEnumerator i(spread, 11u); i; ++i) {
			if(auto const pCell = MapClass::Instance->TryGetCellAt(center + *i)) {
				if(!action(pCell)) {
					return;
				}
			}
		}
	}
};
