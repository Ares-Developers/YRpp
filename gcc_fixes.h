// wish sanity were here
#ifdef __GNUC__

/* gcc defines this as const IID&
 * which naturally is incompat with MSVC's IID*
 * and more to the point blows gas's brains out
 * when you try feeding it to PUSH_VAR32 -_-
 */
#ifdef REFIID
#undef REFIID
#define REFIID IID*
#endif

#define HASHMAP <gcc_hash.h>

#else
#ifdef _MSC_VER

#define HASHMAP <hash_map>

#endif
#endif
