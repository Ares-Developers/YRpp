//Memory allocation handler

#ifndef ALLOC_H
#define ALLOC_H

#include <YRPPCore.h>

class Allocator
{
public:
	Allocator() { Pointer = NULL; Size = 0; Allocated = false; };
	~Allocator() { Free(); };

	Allocator* Allocate(void* p, int nSize)
		JMP_THIS(0x43AD00);

	void Free()
		JMP_THIS(0x43AE50);

	//Properties
	PROPERTY(void*, Pointer);
	PROPERTY(int, Size);
	PROPERTY(bool, Allocated);
};

#endif
