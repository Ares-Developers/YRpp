#ifndef HELPER_CAST_H
#define HELPER_CAST_H

#include <AbstractClass.h>

class ObjectClass;
class MissionClass;
class RadioClass;
class TechnoClass;
class FootClass;

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

template <typename T>
inline T abstract_cast(AbstractClass* pAbstract) {
	return specific_cast<T>(pAbstract);
};

template <>
inline AbstractClass* abstract_cast<AbstractClass*>(AbstractClass* pAbstract) {
	return pAbstract;
};

template <>
inline ObjectClass* abstract_cast<ObjectClass*>(AbstractClass* pAbstract) {
	return generic_cast<ObjectClass*>(pAbstract);
};

template <>
inline MissionClass* abstract_cast<MissionClass*>(AbstractClass* pAbstract) {
	return reinterpret_cast<MissionClass*>(generic_cast<TechnoClass*>(pAbstract));
};

template <>
inline RadioClass* abstract_cast<RadioClass*>(AbstractClass* pAbstract) {
	return reinterpret_cast<RadioClass*>(generic_cast<TechnoClass*>(pAbstract));
};

template <>
inline TechnoClass* abstract_cast<TechnoClass*>(AbstractClass* pAbstract) {
	return generic_cast<TechnoClass*>(pAbstract);
};

template <>
inline FootClass* abstract_cast<FootClass*>(AbstractClass* pAbstract) {
	return generic_cast<FootClass*>(pAbstract);
};

#endif
