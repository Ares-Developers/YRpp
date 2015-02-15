#pragma once

#include <Blitters.h>

template <typename T>
class BlitTranslucentWriteAlpha : public Blitter<T> {
	virtual void Blit
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset)
{
	T *dst = reinterpret_cast < T * >(dest);
	for (; length > 0; --length, ++dst) {
		byte srcv = *src++;
		byte aphv = *aBuf++;
		if (srcv) {
			word deltav = 255 - aphv;
			if (aphv == 255) {
				aphv = 256;
			}
			ColorStruct clr1 = Word2Color(this->Data[srcv]);
			ColorStruct clr2 = Word2Color(*dst);
			byte _r = aphv * clr1.r + deltav * clr2.r;
			byte _g = aphv * clr1.g + deltav * clr2.g;
			byte _b = aphv * clr1.b + deltav * clr2.b;
			ColorStruct clrResult( _r, _g, _b );
			*dst = Color2Word(clrResult);
		}
		++dst;
		if (Drawing::ABuffer->BufferEnd <= aBuf) {
			aBuf -= Drawing::ABuffer->BufferSize;
		}
	}
}

	virtual void CallBlit0
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, WORD unknownArg, DWORD useless)
	{
		this->Blit(dest, src, length, zMin, zBuf, aBuf, aLvl, 0);
	}

	virtual void CallBlit1
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl)
	{
		this->Blit(dest, src, length, zMin, zBuf, aBuf, aLvl, 0);
	}

	virtual void CallBlit2
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, DWORD useless)
	{
		this->Blit(dest, src, length, zMin, zBuf, aBuf, aLvl, 0);
	}

	public:
		T *Data;
};
