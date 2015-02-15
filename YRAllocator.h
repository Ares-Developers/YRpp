// Memory allocation handler

#pragma once

#include <YRPPCore.h>
#include <Memory.h>

class MemoryBuffer
{
public:
	MemoryBuffer()
		: MemoryBuffer(nullptr, 0)
	{ }

	MemoryBuffer(int size)
		: MemoryBuffer(nullptr, size)
	{ }

	MemoryBuffer(void* pBuffer, int size)
		: Buffer(pBuffer), Size(size), Allocated(false)
	{
		if(!this->Buffer && this->Size > 0) {
			this->Buffer = YRMemory::Allocate(static_cast<size_t>(size));
			this->Allocated = true;
		}
	}

	MemoryBuffer(const MemoryBuffer& other)
		: MemoryBuffer(other.Buffer, other.Size)
	{ }

	MemoryBuffer(MemoryBuffer&& other)
		: MemoryBuffer(other.Buffer, other.Size)
	{
		this->Allocated = other.Allocated;
		other.Allocated = false;
	}

	~MemoryBuffer()
	{
		this->Deallocate();
	}

	MemoryBuffer& operator = (const MemoryBuffer& other)
	{
		if(this != &other) {
			this->Deallocate();
			this->Buffer = other.Buffer;
			this->Size = other.Size;
		}

		return *this;
	}

	MemoryBuffer& operator = (MemoryBuffer&& other)
	{
		*this = other;
		this->Allocated = other.Allocated;
		other.Allocated = false;
		return *this;
	}

	void Clear()
	{
		this->Deallocate();
		this->Buffer = nullptr;
		this->Size = 0;
	}

private:
	void Deallocate()
	{
		if(this->Allocated) {
			YRMemory::Deallocate(this->Buffer);
			this->Allocated = false;
		}
	}

public:
	void* Buffer;
	int Size;
	bool Allocated;
};

