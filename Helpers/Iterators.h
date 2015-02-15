#pragma once

#include <GeneralStructures.h>
#include <ObjectClass.h>
#include <CellClass.h>
#include <MapClass.h>

#include <functional>

// Invokes an action on objects of a certain type in a rectangle.
/*
	The rectangle is defined by width and height. If width and/or height are
	even, center does not mark the center of the rectangle due to rounding.

	action could be invoked on an object more than once. For CellClass, action
	is invoked only once.

	\author AlexB
*/
class CellRectIterator {
	CellStruct center;
	int width;
	int height;

public:
	CellRectIterator(const CellStruct &center, int width, int height) : center(center), width(width), height(height) {}

	template <typename T>
	void apply(const std::function<bool(T*)> &action) const {
		apply<ObjectClass>([&action](ObjectClass* pObject) {
			if(T* ptr = abstract_cast<T*>(pObject)) {
				return action(ptr);
			}
			return true;
		});
	}

	template <>
	void apply<CellClass>(const std::function<bool(CellClass*)> &action) const {
		process(action);
	}

	template <>
	void apply<ObjectClass>(const std::function<bool(ObjectClass*)> &action) const {
		process(action);
	}

private:
	void process(const std::function<bool(CellClass*)> &action) const;

	void process(const std::function<bool(ObjectClass*)> &action) const;
};

// Invokes an action on objects of a certain type in a range.
/*
	The range defines a circle around the center. action is invoked on objects
	whose distance from the center is equal to or less than radius.

	action could be invoked on an object more than once. For CellClass, action
	is invoked only once.

	\author AlexB
*/
class CellRangeIterator {
	CellStruct center;
	float radius;

public:
	CellRangeIterator(const CellStruct &center, float radius) : center(center), radius(radius) {}

	template <typename T>
	void apply(const std::function<bool(T*)> &action) const {
		apply<ObjectClass>([&action](ObjectClass* pObject) {
			if(T* ptr = abstract_cast<T*>(pObject)) {
				return action(ptr);
			}
			return true;
		});
	}

	template <>
	void apply<CellClass>(const std::function<bool(CellClass*)> &action) const {
		process(action);
	}

	template <>
	void apply<ObjectClass>(const std::function<bool(ObjectClass*)> &action) const {
		process(action);
	}

private:
	void process(const std::function<bool(CellClass*)> &action) const;

	void process(const std::function<bool(ObjectClass*)> &action) const;
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
class CellSpreadIterator {
	CellStruct center;
	size_t spread;

public:
	CellSpreadIterator(const CellStruct &center, size_t spread) : center(center), spread(spread) {}

	template <typename T>
	void apply(const std::function<bool(T*)> &action) const {
		apply<ObjectClass>([&action](ObjectClass* pObject) {
			if(T* ptr = abstract_cast<T*>(pObject)) {
				return action(ptr);
			}
			return true;
		});
	}

	template <>
	void apply<CellClass>(const std::function<bool(CellClass*)> &action) const {
		process(action);
	}

	template <>
	void apply<ObjectClass>(const std::function<bool(ObjectClass*)> &action) const {
		process(action);
	}

private:
	void process(const std::function<bool(CellClass*)> &action) const;

	void process(const std::function<bool(ObjectClass*)> &action) const;
};
