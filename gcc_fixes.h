// wish sanity were here
#ifdef __GNUC__

/* gcc defines this as const IID&
 * which naturally is incompat with MSVC's IID*
 * and more to the point blows gas's brains out
 * when you try feeding it to PUSH_VAR32 -_-
 * // the following are sometimes needed
#ifdef REFIID
#undef REFIID
#define REFIID IID*
#endif
*/

#define HASHMAP <gcc_hash.h>

// oh yes, gcc's windows.h doesn't include these -_-
#ifndef FILE_ANY_ACCESS
#define FILE_ANY_ACCESS                   0x00000000
#define FILE_SPECIAL_ACCESS               FILE_ANY_ACCESS
#define FILE_READ_ACCESS                  0x00000001
#define FILE_WRITE_ACCESS                 0x00000002
#endif

#else
#ifdef _MSC_VER

#define HASHMAP <hash_map>

#endif
#endif
