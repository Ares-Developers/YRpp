#ifndef HELPER_CAST_H
#define HELPER_CAST_H

#include <AbstractClass.h>

template <typename T>
inline T specific_cast(AbstractClass* pAbstract) {
	if(pAbstract && pAbstract->WhatAmI() == CompoundT<T>::BaseT::AbsID) {
		return reinterpret_cast<T>(pAbstract);
	}
	return nullptr;
};

template <typename T>
inline T generic_cast(AbstractClass* pAbstract) {
	if(pAbstract && (pAbstract->AbstractFlags & CompoundT<T>::BaseT::AbsDerivateID) != 0) {
		return reinterpret_cast<T>(pAbstract);
	}
	return nullptr;
};

#endif
