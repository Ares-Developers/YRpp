#pragma once

#include <Blitters.h>

template <typename T>
class BlitTransLucent75ZReadWrite : public Blitter<T> {
	virtual void Blit
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset)
{
	T *dst = reinterpret_cast < T * >(dest);
	for (; length > 0; --length, ++dst) {
		WORD zVal = *zBuf;
		if (zVal > zMin) {
			int idx = *src++;
			if (idx) {
				word tmpval = this->Data[srcv] >> 2 & this->ExtraData;
				word dstval = *dst >> 2 & this->ExtraData;
				tmpval += 3 * dstval;
				*dst = tmpval;
				*zBuf = zMin;
			}
		}
		zBuf++;
		if (Drawing::ZBuffer->BufferEnd <= zBuf) {
			zBuf -= Drawing::ZBuffer->BufferSize;
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
