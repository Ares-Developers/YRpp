#ifndef HELPER_TEMPLATE_H
#define HELPER_TEMPLATE_H

#include <Syringe.h>

#include <functional>
#include <xcompile.h>
#include <Helpers/Type.h>

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
	int operator()( T Result ) {
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
	int operator()() {
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
	int operator()(bool choose) {
		return choose ? retAddr : negAddr;
	}
};

// invalid pointers

template<typename T1, typename T2>
void AnnounceInvalidPointerMap(hash_map<T1, T2> &map, void *ptr) {
	typename hash_map<T1, T2>::iterator ix;
	ix = map.find(reinterpret_cast<T1>(ptr));
	if(ix != map.end()) {
		map.erase(ix);
	}

	for(ix = map.begin(); ix != map.end(); ++ix) {
		if(ptr == ((void *)(ix->second))) {
			map.erase(ix->first);
		}
	}
}

template<typename T1>
void AnnounceInvalidPointer(T1 &elem, void *ptr) {
	if(ptr == (void *)elem) {
		elem = NULL;
	}
}


// vroom vroom
// Westwood uses if(((1 << HouseClass::ArrayIndex) & TechnoClass::DisplayProductionToHouses) != 0) and other bitfields like this (esp. in CellClass, omg optimized). helper wrapper just because
template <typename T>
class IndexBitfield {
	public:
	DWORD data;
	IndexBitfield(const DWORD defVal = 0) : data(defVal) {};

	bool Contains(const T obj) const {
		return (this->data & (1 << obj->ArrayIndex)) != 0;
	}
	void Add(const T obj) {
		this->data |= (1 << obj->ArrayIndex);
	}
	void Remove(const T obj) {
		this->data &= ~(1 << obj->ArrayIndex);
	}
	void Clear() {
		this->data = 0;
	}
};

#include <AbstractClass.h>
template <typename T>
inline T specific_cast(AbstractClass * Object) {
	if(Object->WhatAmI() == CompoundT<T>::BaseT::AbsID) {
		return reinterpret_cast<T>(Object);
	}
	return NULL;
};

template <typename T>
inline T generic_cast(AbstractClass * Object) {
	if((Object->AbstractFlags & CompoundT<T>::BaseT::AbsDerivateID) != 0) {
		return reinterpret_cast<T>(Object);
	}
	return NULL;
};
#endif
