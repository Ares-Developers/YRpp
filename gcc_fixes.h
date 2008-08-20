// wish sanity were here
#ifdef __GNUC__

#error GCC is not supported. This is because it produces a different binary class layout     \
	which is utterly incompatible with data layout of objects in the game, therefore it cannot \
	be used to interact with it without converting the YRPP headers to plain C, which is a massive \
	undertaking for dubious gain, as GCC even optimises code worse than MSVC.

#else
#ifdef _MSC_VER

#define HASHMAP <hash_map>

#endif
#endif
