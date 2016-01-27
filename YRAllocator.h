// Memory allocation handler

#pragma once

#include <YRPPCore.h>
#include <Memory.h>

class MemoryBuffer
{
public:
	constexpr MemoryBuffer() noexcept = default;

	explicit MemoryBuffer(int size) noexcept
		: MemoryBuffer(nullptr, size)
	{ }

	MemoryBuffer(void* pBuffer, int size) noexcept
		: Buffer(pBuffer), Size(size)
	{
		if(!this->Buffer && this->Size > 0) {
			this->Buffer = YRMemory::Allocate(static_cast<size_t>(size));
			this->Allocated = true;
		}
	}

	constexpr MemoryBuffer(MemoryBuffer const& other) noexcept
		: Buffer(other.Buffer), Size(other.Size)
	{ }

	MemoryBuffer(MemoryBuffer&& other) noexcept
		: Buffer(other.Buffer), Size(other.Size), Allocated(other.Allocated)
	{
		other.Allocated = false;
	}

	~MemoryBuffer() noexcept
	{
		if(this->Allocated) {
			YRMemory::Deallocate(this->Buffer);
		}
	}

	MemoryBuffer& operator = (MemoryBuffer const& other) noexcept
	{
		if(this != &other) {
			MemoryBuffer tmp(static_cast<MemoryBuffer&&>(*this));
			this->Buffer = other.Buffer;
			this->Size = other.Size;
		}

		return *this;
	}

	MemoryBuffer& operator = (MemoryBuffer&& other) noexcept
	{
		*this = other;
		auto const allocated = other.Allocated;
		other.Allocated = false;
		this->Allocated = allocated;
		return *this;
	}

	void Clear() noexcept
	{
		MemoryBuffer tmp(static_cast<MemoryBuffer&&>(*this));
		this->Buffer = nullptr;
		this->Size = 0;
	}

public:
	void* Buffer{ nullptr };
	int Size{ 0 };
	bool Allocated{ false };
};
