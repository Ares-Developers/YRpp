#pragma once

// This file contains strong language, excessive amounts of copy pasting and is known to make grown men cry.
// Proceed at your own risk.
// Don't forget to email ex-Westwood coders and tell them just how much you love their awesome code.

class BlitterCore {
	public:
		BlitterCore() = default;
		virtual ~BlitterCore() = default;

		// depending on the blitter, these have different intepretations and usage
		// zBuf - pointer to Z-buffer data
		// zMin - minimum Z value (context)
		// aBuf - pointer to Alpha buffer data
		// aLvl - Alpha threshold (context)
		// warpOffset - offset for warping the data (context)
	virtual void Blit
		(void *dst, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit0
		(void *dst, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, 
			WORD unknownArg, DWORD useless) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit1
		(void *dst, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit2
		(void *dst, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, 
			DWORD useless) = 0;

};

template<typename T>
class Blitter : public BlitterCore {
	public:
		Blitter() = default;
		virtual ~Blitter() = default;

		// depending on the blitter, these have different intepretations and usage
		// zBuf - pointer to Z-buffer data
		// zMin - minimum Z value (context)
		// aBuf - pointer to Alpha buffer data
		// aLvl - Alpha threshold (context)
		// warpOffset - offset for warping the data (context)
	virtual void Blit
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit0
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, 
			WORD unknownArg, DWORD useless) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit1
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl) = 0;

	// actual body: this->Blit(dst, src, length, zMin, zBuf, aBuf, aLvl, 0);
	virtual void CallBlit2
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, 
			DWORD useless) = 0;

	byte *Data; // LightConvertClass's byte buffer
};

class RLEBlitterCore {
	public:
		RLEBlitterCore() = default;
		virtual ~RLEBlitterCore() = default;

		// depending on the blitter, these have different intepretations and usage
		// zBuf - pointer to Z-buffer data
		// zMin - minimum Z value (context)
		// aBuf - pointer to Alpha buffer data
		// aLvl - Alpha threshold (context)
		// warpOffset - offset for warping the data (context)
	virtual void Blit
		(void *dst, byte *src, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11) = 0;

	// actual body: this->Blit(dst, src, Length, EncodedLen, a6, a7, a8, a9, a10, a11);
	virtual void CallBlit0
		(void *dst, byte *src, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11,
			DWORD useless) = 0;

	byte *Data; // LightConvertClass's byte buffer
};

template<typename T>
class RLEBlitter : public RLEBlitterCore {
	public:
		RLEBlitter() = default;
		virtual ~RLEBlitter() = default;

/*
		// depending on the blitter, these have different intepretations and usage
		// zBuf - pointer to Z-buffer data
		// zMin - minimum Z value (context)
		// aBuf - pointer to Alpha buffer data
		// aLvl - Alpha threshold (context)
		// warpOffset - offset for warping the data (context)
	virtual void Blit
		(T *dst, byte *src, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11) = 0;

	// actual body: this->Blit(dst, src, Length, EncodedLen, a6, a7, a8, a9, a10, a11);
	virtual void CallBlit0
		(T *dst, byte *src, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11,
			DWORD useless) = 0;

	byte *Data; // LightConvertClass's byte buffer
*/
};
