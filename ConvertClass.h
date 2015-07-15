/*
	Converts are palettes... AFAIK
*/

#pragma once

#include <AbstractClass.h>
#include <ArrayClasses.h>
#include <Surface.h>

#include <Blitters.h>

#include <FileFormats/SHP.h>

struct ColorStruct;
class DSurface;

// struct Blitter;

class ConvertClass
{
public:
	//global array
	static DynamicVectorClass<ConvertClass*>* const Array;

	static ConvertClass* FindOrAllocate(const char * FileName);

	static void __fastcall CreateFromFile(const char* Filename, BytePalette* &pPalette, ConvertClass* &pDestination)
		{ JMP_STD(0x72ADE0); }

	// if you're drawing a SHP, call SHPStruct::HasCompression and choose one of these two based on that
	BlitterCore * SelectPlainBlitter(BlitterFlags flags)
		{ JMP_THIS(0x490B90); }

	RLEBlitterCore * SelectRLEBlitter(BlitterFlags flags)
		{ JMP_THIS(0x490E50); }

	void* SelectProperBlitter(SHPStruct * SHP, int FrameIndex, BlitterFlags flags) {
		return (SHP->HasCompression(FrameIndex))
			? static_cast<void*>(this->SelectRLEBlitter(flags))
			: static_cast<void*>(this->SelectPlainBlitter(flags))
		;
	}

	virtual ~ConvertClass() RX;

	ConvertClass(
		BytePalette* pColorData,
		BytePalette* pUnknownColorData, //???
		DSurface* pSurface,
		size_t Count,
		bool SkipBlitters) : ConvertClass(noinit_t())
	{ JMP_THIS(0x48E740); }

protected:
	explicit __forceinline ConvertClass(noinit_t)
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	//That's right, I don't know anything about this class, except what it's used for...

	// == 1 ? alloc_a_few_blitters_for_uchar : alloc_a_fuckton_of_blitters_for_ushort
	// actually this is just the result of Surface->GetBytesPerPixel()
	// but this name sounds better
	DWORD LeanAndMean;
	BlitterCore * Blitters  [89];
	size_t Count;
	byte * BufferA; // new(Count * 8 * LeanAndMean) - gets filled with pColorData values on CTOR
	byte * Midpoint; // points to the middle of BufferA above, ??
	byte * BufferB; // if(LeanAndMean == 1) { BufferB = new byte[0x100]; }
	DWORD f_17C;
	DWORD f_180;
	DWORD f_184;

//	PROTECTED_PROPERTY(BYTE, unknown_0[0x188]);
};

class LightConvertClass : public ConvertClass
{
public:
	//global array
	static DynamicVectorClass<LightConvertClass*>* const Array;

	//Destructor
	virtual ~LightConvertClass() RX;

	void UpdateColors(int Red, int Green, int Blue, bool bUnknown)
		{ JMP_THIS(0x556090); }

	//Constructor
	LightConvertClass(
		BytePalette *Pal1,
		BytePalette *Pal2,
		Surface *Surface,
		int Color_R,
		int Color_G,
		int Color_B,
		bool SkipBlitters,
		size_t Count,
		DWORD arg20) : LightConvertClass(noinit_t())
	{ JMP_THIS(0x555DA0); }

protected:
	explicit __forceinline LightConvertClass(noinit_t)
		: ConvertClass(noinit_t())
	{ }

public:

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	BytePalette* UsedPalette1;
	BytePalette* UsedPalette2;
	void* unknown_190;
	int UsageCount;
	TintStruct Color1;
	TintStruct Color2;
	BYTE unknown_1B0;
	PROTECTED_PROPERTY(BYTE, align_1B1[3]);
};
