#pragma once

#include <ASMMacros.h>

#include <exception>
#include <type_traits>

/*
 * The memory (de)allocators have to match!
 * Do not allocate memory in the DLL and hand it to the game to deallocate, or vice versa.
 * Kapiche?

 * A simple |auto foo = new IngameClass();| allocates memory from the DLL's pool.
 * But |delete foo;| deallocates memory from the game's own pool. (assuming the class you're freeing has a virtual SDDTOR)

 * So use the macros to make sure game classes go to the game's pool.
 * The custom classes like ExtMap do not need this treatment so you can use the plain old new/delete on them.

 * For the ObjectClass derivates, if you use the game's built-in allocators like | Type->CreateObject() | ,
 * you can use plain | delete |;

 */

/*
 * OK, new plan - the game's operator new/delete has been hooked to redirect to the DLL's
 * so GAME_(DE)ALLOC is now just a wrapper. Don't remove it though, just in case this fails
 * and I need to run those allocations differently.
 */

/*
 * Newer plan - previous hook screwed performance, so going back
 */

/*
* Yet a newer plan - use variadic templates
*/

// provides access to the game's operator new and operator delete.
namespace YRMemory {
	// both functions are naked, which means neither prolog nor epilog are
	// generated for them. thus, a simple jump suffices to redirect to the
	// original methods, and no more book keeping or cleanup has to be
	// performed the calling convention has to match for this trick to work.

	// naked does not support inlining. the inline modifier here means that
	// multiple definitions are allowed.

	// the game's operator new
	__declspec(naked) inline void* __cdecl Allocate(size_t sz) {
		JMP(0x7C8E17);
	}

	// the game's operator delete
	__declspec(naked) inline void __cdecl Deallocate(const void* mem) {
		JMP(0x7C8B3D);
	}

	__declspec(noinline) inline void* AllocateChecked(size_t sz) {
		if(auto const ptr = YRMemory::Allocate(sz)) {
			return ptr;
		}
		std::terminate();
	}
}

template<typename T>
struct needs_vector_delete : std::integral_constant<bool,
	!std::is_scalar<T>::value && !std::is_trivially_destructible<T>::value> {};

// this is a stateless basic allocator definition that manages memory using the
// game's operator new and operator delete methods. do not use it directly,
// though. use std::allocator_traits, which will fill in the blanks.
template <typename T>
struct GameAllocator {
	using value_type = T;

	GameAllocator() {}

	template <typename U>
	GameAllocator(const GameAllocator<U>&) {}

	bool operator == (const GameAllocator&) const { return true; }
	bool operator != (const GameAllocator&) const { return false; }

	T* allocate(const size_t count) const {
		return static_cast<T*>(YRMemory::AllocateChecked(count * sizeof(T)));
	}

	void deallocate(T* const ptr, size_t count) const {
		YRMemory::Deallocate(ptr);
	}
};

// construct or destroy objects using an allocator.
class Memory {
public:
	// construct scalars
	template <typename T, typename TAlloc, typename... TArgs>
	static inline T* Create(TAlloc& alloc, TArgs&&... args) {
		auto const ptr = std::allocator_traits<TAlloc>::allocate(alloc, 1);
		std::allocator_traits<TAlloc>::construct(alloc, ptr, std::forward<TArgs>(args)...);
		return ptr;
	};

	// destruct scalars
	template<typename T, typename TAlloc>
	static inline void Delete(TAlloc& alloc, T* ptr) {
		if(ptr) {
			std::allocator_traits<TAlloc>::destroy(alloc, ptr);
			std::allocator_traits<TAlloc>::deallocate(alloc, ptr, 1);
		}
	};

	// construct vectors
	template <typename T, typename TAlloc, typename... TArgs>
	static inline T* CreateArray(TAlloc& alloc, size_t capacity, TArgs&&... args) {
		auto const ptr = std::allocator_traits<TAlloc>::allocate(alloc, capacity);
		if(capacity && !sizeof...(args) && std::is_scalar<T>::value) {
			// set to 0
			std::memset(ptr, 0, capacity * sizeof(T));
		} else {
			for(size_t i = 0; i < capacity; ++i) {
				// use args... here. can't move args, because we need to reuse them
				std::allocator_traits<TAlloc>::construct(alloc, &ptr[i], args...);
			}
		}
		return ptr;
	}

	// destruct vectors
	template<typename T, typename TAlloc>
	static inline void DeleteArray(TAlloc& alloc, T* ptr, size_t capacity) {
		if(ptr) {
			// call the destructor if required
			if(capacity && !std::is_trivially_destructible<T>::value) {
				for(size_t i = 0; i < capacity; ++i) {
					std::allocator_traits<TAlloc>::destroy(alloc, &ptr[i]);
				}
			}

			std::allocator_traits<TAlloc>::deallocate(alloc, ptr, capacity);
		}
	};
};

// helper methods as free functions.

template <typename T, typename... TArgs>
static inline T* GameCreate(TArgs&&... args) {
	static_assert(std::is_constructible<T, TArgs...>::value, "Cannot construct T from TArgs.");

	GameAllocator<T> alloc;
	return Memory::Create<T>(alloc, std::forward<TArgs>(args)...);
}

template<typename T>
static inline void GameDelete(T* ptr) {
	GameAllocator<T> alloc;
	Memory::Delete(alloc, ptr);
}

template <typename T, typename... TArgs>
static inline T* GameCreateArray(size_t capacity, TArgs&&... args) {
	static_assert(std::is_constructible<T, TArgs...>::value, "Cannot construct T from TArgs.");

	GameAllocator<T> alloc;
	return Memory::CreateArray<T>(alloc, capacity, std::forward<TArgs>(args)...);
}

template<typename T>
static inline void GameDeleteArray(T* ptr, size_t capacity) {
	GameAllocator<T> alloc;
	Memory::DeleteArray(alloc, ptr, capacity);
}

template <typename T, typename... TArgs>
static inline T* DLLCreate(TArgs&&... args) {
	static_assert(std::is_constructible<T, TArgs...>::value, "Cannot construct T from TArgs.");

	std::allocator<T> alloc;
	return Memory::Create<T>(alloc, std::forward<TArgs>(args)...);
}

template<typename T>
static inline void DLLDelete(T* ptr) {
	std::allocator<T> alloc;
	Memory::Delete(alloc, ptr);
}

template <typename T, typename... TArgs>
static inline T* DLLCreateArray(size_t capacity, TArgs&&... args) {
	static_assert(std::is_constructible<T, TArgs...>::value, "Cannot construct T from TArgs.");

	std::allocator<T> alloc;
	return Memory::CreateArray<T>(alloc, capacity, std::forward<TArgs>(args));
}

template<typename T>
static inline void DLLDeleteArray(T* ptr, size_t capacity) {
	std::allocator<T> alloc;
	Memory::DeleteArray(alloc, ptr, capacity);
}

struct GameDeleter {
	template <typename T>
	void operator ()(T* ptr) {
		if(ptr) {
			GameDelete(ptr);
		}
	}
};

//#define GAME_ALLOC(TT, var, ...) \
//	var = GameCreate<TT>(__VA_ARGS__);
//
//#define GAME_DEALLOC(var) \
//	GameDelete(var);
//
//#define GAME_ALLOC_ARR(TT, Capacity, var) \
//	var = GameCreateArray<TT>(Capacity);
