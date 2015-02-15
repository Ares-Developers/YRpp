#pragma once

#include <GeneralDefinitions.h>

class Checksummer {
	static const size_t Size = 4;
public:
	Checksummer() : Value(0), ByteIndex(0) {
		for(int i = 0; i < Size; ++i) {
			this->Bytes[i] = 0;
		}
	}

	DWORD GetValue() const {
		return this->GetValueInline();
	}

	DWORD Intermediate() const {
		return this->Value;
	}

	void Commit() {
		this->CommitInline();
	}

	void Add(const void* data, size_t c_bytes) {
		if(data && c_bytes) {
			auto bytes = reinterpret_cast<const BYTE*>(data);

			// fill the current block
			while(this->ByteIndex != 0 && this->ByteIndex < Size && c_bytes) {
				this->AddInline(*bytes++);
				--c_bytes;
			}

			// take the full blocks
			const auto blocks = c_bytes / Size;
			for(auto i = 0u; i < blocks; ++i) {
				this->Value = Process(bytes, Size, this->Value);
				bytes += Size;
			}
			c_bytes -= blocks * Size;

			// fill in the remainder
			while(c_bytes--) {
				this->AddInline(*bytes++);
			}
		}
	}

	void Add(BYTE value) {
		this->AddInline(value);
	}

	void Add(bool value) {
		this->Add(static_cast<BYTE>(value != 0));
	}

	void Add(char value) {
		this->Add(static_cast<BYTE>(value));
	}

	void Add(signed char value) {
		this->Add(static_cast<BYTE>(value));
	}

	void Add(const char* string) {
		if(string) {
			this->Add(string, strlen(string));
		}
	}

	template <typename T>
	void Add(const T& value) {
		this->Add(&value, sizeof(T));
	}

	static DWORD Process(const void* data, size_t size, DWORD initial) {
		auto bytes = reinterpret_cast<const BYTE*>(data);
		auto ret = ~initial;

		static const DWORD* CRC_Table = reinterpret_cast<DWORD*>(0x81F7B4);

		for(auto i = 0u; i < size; ++i) {
			ret = CRC_Table[*bytes++ ^ static_cast<BYTE>(ret)] ^ (ret >> 8);
		}

		return ~ret;
	}

	static DWORD Process(const char* string, DWORD initial) {
		auto bytes = reinterpret_cast<const BYTE*>(string);
		auto ret = ~initial;

		static auto CRC_Table = reinterpret_cast<const DWORD*>(0x81F7B4);

		while(*bytes) {
			ret = CRC_Table[*bytes++ ^ static_cast<BYTE>(ret)] ^ (ret >> 8);
		}

		return ~ret;
	}

protected:
	void Fill() const {
		// this check is missing in the original, which makes it
		// write beyond the array, ie. outside the class' memory.
		if(this->ByteIndex < Size) {
			this->Bytes[this->ByteIndex] = static_cast<BYTE>(this->ByteIndex);
			for(auto i = this->ByteIndex + 1; i < Size; ++i) {
				this->Bytes[i] = this->Bytes[0];
			}
		}
	}

	__forceinline void AddInline(BYTE value) {
		// clear old data
		if(this->ByteIndex == 0) {
			for(int i = 0; i < Size; ++i) {
				this->Bytes[i] = 0;
			}
		}

		this->Bytes[this->ByteIndex++] = value;

		if(this->ByteIndex == Size) {
			this->CommitInline();
		}
	}

	__forceinline DWORD GetValueInline() const {
		// nothing to check
		if(!this->ByteIndex) {
			return this->Value;
		}

		// fill the remaining bytes
		this->Fill();

		// project the value without changing internal state
		return Process(this->Bytes, Size, this->Value);
	}

	__forceinline void CommitInline() {
		this->Value = this->GetValueInline();
		this->ByteIndex = 0;
	}

	DWORD Value;
	size_t ByteIndex;
	mutable BYTE Bytes[Size];
};

// when using the original game implementation, use this to allocate space on
// the stack. this class has a byte of padding to prevent out of bounds writes.
class SafeChecksummer : public Checksummer {
public:
	SafeChecksummer() : Checksummer() { }

protected:
	/*
	* this is not entirely correct
	* the original class doesn't have this member and as such its sizeof == 0xC,
	* but the code writes to the 0xC'th byte anyway... when the class is
	* allocated through the heap, it works because windows apparently aligns
	* memory blocks to 8 byte boundaries but when it's allocated on the stack,
	* all hell breaks loose
	*/
	BYTE  Padding;
};
