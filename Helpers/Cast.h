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
	typedef CompoundT<T>::BaseT Base;

	static_assert(std::is_base_of<AbstractClass, Base>::value,
		"specific_cast: T is required to be a type derived from AbstractClass.");

	static_assert(!std::is_abstract<Base>::value,
		"specific_cast: Abstract types (not fully implemented classes) are not suppored.");

	if(pAbstract && pAbstract->WhatAmI() == Base::AbsID) {
		return reinterpret_cast<T>(pAbstract);
	}
	return nullptr;
};

template <typename T>
inline T generic_cast(AbstractClass* pAbstract) {
	typedef CompoundT<T>::BaseT Base;

	static_assert(std::is_base_of<ObjectClass, Base>::value
		&& std::is_abstract<Base>::value,
		"generic_cast: T is required to be an abstract type derived from ObjectClass.");

	if(pAbstract && (pAbstract->AbstractFlags & Base::AbsDerivateID) != 0) {
		return reinterpret_cast<T>(pAbstract);
	}
	return nullptr;
};

template <typename T>
inline T abstract_cast(AbstractClass* pAbstract) {
	typedef typename std::remove_pointer<T>::type Base;

	static_assert(std::is_base_of<AbstractClass, Base>::value,
		"abstract_cast: T is required to be a type derived from AbstractClass.");

	static_assert(!std::is_base_of<AbstractTypeClass, Base>::value
		|| !std::is_abstract<Base>::value,
		"abstract_cast: Abstract types (not fully implemented classes) derived from AbstractTypeClass are not suppored.");

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
