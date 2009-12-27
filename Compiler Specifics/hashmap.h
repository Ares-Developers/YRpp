#ifndef HASHMAP_H_
#define HASHMAP_H_

#ifdef _MSC_VER
#include <hash_map>
using stdext::hash_map;
#else

#ifdef __GNUC__
#include <ext/hash_map>

using __gnu_cxx::hash_map;
#endif

#endif

#endif /* HASHMAP_H_ */
