#ifndef YRPP_CHECKSUM_H
#define YRPP_CHECKSUM_H

#include <GeneralDefinitions.h>

class Checksummer {
public:
	void Add(BYTE Value)
		{ JMP_THIS(0x4A1C10); };

	void Add(bool Value)
		{ JMP_THIS(0x4A1CA0); };

	void Add(WORD Value)
		{ JMP_THIS(0x4A1D30); };

	void Add(DWORD Value)
		{ JMP_THIS(0x4A1D50); };

	void Add(float Value)
		{ JMP_THIS(0x4A1D70); };

	void Add(double Value)
		{ JMP_THIS(0x4A1D90); };

	void Add(const char * Value)
		{ JMP_THIS(0x4A1DB0); };

	void Add(const BYTE * Buffer, int Length)
		{ JMP_THIS(0x4A1DE0); };

protected:
	DWORD AddBuffer(const BYTE * Buffer, int Length, DWORD InitialValue)
		{ JMP_THIS(0x4A1C10); };

public:
	void Reset() {
		CurrentValue = 0;
		CurrentByteIndex = 0;
		CurrentBytes[0] = 0;
		CurrentBytes[1] = 0;
		CurrentBytes[2] = 0;
		CurrentBytes[3] = 0;
		LastByteIndex = 0;
	};

	Checksummer() : CurrentValue(0), CurrentByteIndex(0), LastByteIndex(0) {
		CurrentBytes[0] = 0;
		CurrentBytes[1] = 0;
		CurrentBytes[2] = 0;
		CurrentBytes[3] = 0;
	};

	DWORD CurrentValue;
	int   CurrentByteIndex;
	BYTE  CurrentBytes[4];

	/*
	 * this is not entirely correct
	 * the original class doesn't have this member and as such its sizeof == 0xC, but the code writes to the 0xC'th byte anyway...
	 * when the class is allocated through the heap, it works because windows apparently aligns memory blocks to 8 byte boundaries
	 * but when it's allocated on the stack, all hell breaks loose
	 */
	BYTE  LastByteIndex;
};

#endif
