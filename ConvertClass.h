/*
	Converts are palettes... AFAIK
*/

#pragma once

#include <AbstractClass.h>
#include <ArrayClasses.h>
#include <Surface.h>

#include <Blitters.h>

#include <FileFormats/SHP.h>
#include <Helpers/CompileTime.h>

struct ColorStruct;
class DSurface;

// struct Blitter;

class ConvertClass
{
public:
	//global array
	static constexpr constant_ptr<DynamicVectorClass<ConvertClass*>, 0x89ECF8u> const Array{};

	static ConvertClass* FindOrAllocate(const char* pFilename);

	static void __fastcall CreateFromFile(const char* pFilename, BytePalette* &pPalette, ConvertClass* &pDestination)
		{ JMP_STD(0x72ADE0); }

	// if you're drawing a SHP, call SHPStruct::HasCompression and choose one of these two based on that
	BlitterCore* SelectPlainBlitter(BlitterFlags flags) const
		{ JMP_THIS(0x490B90); }

	RLEBlitterCore* SelectRLEBlitter(BlitterFlags flags) const
		{ JMP_THIS(0x490E50); }

	virtual ~ConvertClass() RX;

	ConvertClass(
		BytePalette const& palette,
		BytePalette const& palette2, //???
		DSurface* pSurface,
		size_t shadeCount,
		bool skipBlitters) : ConvertClass(noinit_t())
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
	// actually this is just the result of pSurface->GetBytesPerPixel()
	// but this name sounds better
	int BytesPerPixel;
	BlitterCore* Blitters[50];
	RLEBlitterCore* RLEBlitters[39];
	size_t ShadeCount;
	void* BufferA; // new(ShadeCount * 8 * BytesPerPixel) - gets filled with palette values on CTOR
	void* Midpoint; // points to the middle of BufferA above, ??
	void* BufferB; // if(BytesPerPixel == 1) { BufferB = new byte[0x100]; }
	DWORD CurrentZRemap; // set right before drawing
	DWORD HalfColorMask; // for masking colors right-shifted by 1
	DWORD QuarterColorMask; // for masking colors right-shifted by 2
};

class LightConvertClass : public ConvertClass
{
public:
	//global array
	static constexpr constant_ptr<DynamicVectorClass<LightConvertClass*>, 0x87F698u> const Array{};

	//Destructor
	virtual ~LightConvertClass() RX;

	virtual void UpdateColors(int red, int green, int blue, bool tinted) final
		{ JMP_THIS(0x556090); }

	//Constructor
	LightConvertClass(
		BytePalette const& palette1,
		BytePalette const& palette2,
		Surface* pSurface,
		int color_R,
		int color_G,
		int color_B,
		bool skipBlitters,
		BYTE* pBuffer, // allowed to be null
		size_t shadeCount) : LightConvertClass(noinit_t())
	{ JMP_THIS(0x555DA0); }

protected:
	explicit __forceinline LightConvertClass(noinit_t)
		: ConvertClass(noinit_t())
	{ }

public:

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	BytePalette const* UsedPalette1;
	BytePalette const* UsedPalette2;
	BYTE* unknown_buffer_190;
	int UsageCount;
	TintStruct Color1;
	TintStruct Color2;
	bool Tinted;
	PROTECTED_PROPERTY(BYTE, align_1B1[3]);
};
