#ifndef GCC_HASH_H
#define GCC_HASH_H
 // gcc keeps hashmap in this NS
 // hash function for a generic pointer
 // except (const) char * which has a builtin template

#include <ext/hash_map>

// function borrowed from Saberhawk
namespace __gnu_cxx {
	template<typename T> struct hash<T *> {
		size_t operator()(T * __s) const
			{ return reinterpret_cast<unsigned long>(__s) >> 4; }
	};
};

namespace stdext = __gnu_cxx;
#endif
