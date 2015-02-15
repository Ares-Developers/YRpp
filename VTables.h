#pragma once

#include <GeneralDefinitions.h>

// magic!
// constructs a VTable lookup that can be used in templates like DVC, i.e. like this:
/*
if(VT<T>::Set()) {
	*(DWORD *)this = VT<T>::Get();
}
 */

template<typename T>
class VT {
	static const DWORD Address = 0;
public:
	static bool Set() {
		return Address != 0;
	}
	static DWORD Get() {
		return Address;
	}
};

#define VT_C(cls, addr) \
template<> class VT< cls > { \
	static const DWORD Address = addr; \
};

VT_C(SideClass, 0x7F2EC0);
VT_C(VectorClass<SideClass*>, 0x7EA044);
VT_C(DynamicVectorClass<SideClass*>, 0x7EA024);
