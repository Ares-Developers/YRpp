/*
	Converts are palettes... AFAIK
*/

#ifndef CONVERT_H
#define CONVERT_H

#include <AbstractClass.h>
#include <ArrayClasses.h>
#include <Surface.h>

struct ColorStruct;
class DSurface;

struct Blitter;

class ConvertClass
{
public:
	//global array
	static DynamicVectorClass<ConvertClass*>* Array;

	ConvertClass(
		BytePalette* pColorData,
		BytePalette* pUnknownColorData, //???
		DSurface* pSurface,
		size_t Count,
		bool SkipBlitters)
			JMP_THIS(0x48E740);

	Blitter * SelectBlitterA(eBlitterFlags flags)
			JMP_THIS(0x490B90);

	Blitter * SelectBlitterB(eBlitterFlags flags)
			JMP_THIS(0x490E50);

	virtual ~ConvertClass() RX;

protected:
	ConvertClass() { }
	ConvertClass(bool) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	//That's right, I don't know anything about this class, except what it's used for...

	// == 1 ? alloc_a_few_blitters_for_uchar : alloc_a_fuckton_of_blitters_for_ushort
	// actually this is just the result of Surface->GetBytesPerPixel()
	// but this name sounds better
	PROPERTY(DWORD, LeanAndMean);
	PROPERTY_ARRAY(Blitter *, Blitters , 89);
	PROPERTY(size_t, Count);
	PROPERTY(byte *, BufferA); // new(Count * 8 * LeanAndMean) - gets filled with pColorData values on CTOR
	PROPERTY(byte *, Midpoint); // points to the middle of BufferA above, ??
	PROPERTY(byte *, BufferB); // if(LeanAndMean == 1) { BufferB = new(0x100); }
	PROPERTY(DWORD, f_17C);
	PROPERTY(DWORD, f_180);
	PROPERTY(DWORD, f_184);

//	PROTECTED_PROPERTY(BYTE, unknown_0[0x188]);
};

class LightConvertClass : public ConvertClass
{
public:
	//global array
	static DynamicVectorClass<LightConvertClass*>* Array;

	//Constructor, Destructor

	LightConvertClass(
		BytePalette *Pal1,
		BytePalette *Pal2,
		Surface *Surface,
		int Color_R,
		int Color_G,
		int Color_B,
		bool SkipBlitters,
		size_t Count,
		DWORD arg20) : ConvertClass(false)
			JMP_THIS(0x555DA0);

	virtual ~LightConvertClass() RX;

protected:
	LightConvertClass() : ConvertClass(false) {}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	//I have no idea...
	PROTECTED_PROPERTY(BYTE, unknown_0[0x2C]);
};

#endif
