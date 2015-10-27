#pragma once

#include <Syringe.h>

#include <ArrayClasses.h>

// here be dragons(plenty)


// return functors

// set EAX to smth, return to smth
template<typename T>
class retfunc {
protected:
	REGISTERS *R;
	DWORD retAddr;
public:
	retfunc(REGISTERS *r, DWORD addr) : R(r), retAddr(addr) {};
	DWORD operator()(T Result) {
		R->EAX(Result);
		return retAddr;
	}
};

// set EAX to smth, return to fixed
template<typename T>
class retfunc_fixed : public retfunc<T> {
protected:
	T Result;
public:
	retfunc_fixed(REGISTERS *r, DWORD addr, T res) : retfunc<T>(r, addr), Result(res) {};
	DWORD operator()() {
		this->R->EAX(Result);
		return this->retAddr;
	}
};

// return to one of two fixed
class retfunc_bool : public retfunc<int> {
protected:
	DWORD negAddr;
public:
	retfunc_bool(REGISTERS *r, DWORD yAddr, DWORD nAddr) : retfunc<int>(r, yAddr), negAddr(nAddr) {};
	DWORD operator()(bool choose) {
		return choose ? retAddr : negAddr;
	}
};

// invalid pointers

template<typename T1>
void AnnounceInvalidPointer(T1 &elem, void *ptr) {
	if(ptr == static_cast<void*>(elem)) {
		elem = nullptr;
	}
}

template<typename T>
void AnnounceInvalidPointer(DynamicVectorClass<T> &elem, void *ptr) {
	auto idx = elem.FindItemIndex(reinterpret_cast<T*>(ptr));
	if(idx != -1) {
		elem.RemoveItem(idx);
	}
}


// vroom vroom
// Westwood uses if(((1 << HouseClass::ArrayIndex) & TechnoClass::DisplayProductionToHouses) != 0) and other bitfields like this (esp. in CellClass, omg optimized). helper wrapper just because
template <typename T>
class IndexBitfield {
public:
	IndexBitfield() = default;
	explicit IndexBitfield(DWORD const defVal) noexcept : data(defVal) {};

	bool Contains(const T obj) const {
		return (this->data & (1u << obj->ArrayIndex)) != 0u;
	}

	void Add(const T obj) {
		this->data |= (1u << obj->ArrayIndex);
	}

	void Remove(const T obj) {
		this->data &= ~(1u << obj->ArrayIndex);
	}

	void Clear() {
		this->data = 0u;
	}

	DWORD data{ 0 };
};

#include <Helpers/Cast.h>
