#pragma once

#include <Blitters.h>

template <typename T>
class BlitTransLucent50Alpha : public Blitter<T> {
	virtual void Blit
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset)
{
	T *dst = reinterpret_cast < T * >(dest);
	int alphaLevel = min((261 * max(aLvl, 0)) >> 11, 254);
	word *extra = this->ExtraData[alphaLevel << 9];
	word *buf = *(word *) this->Data;
	for (; length > 0; --length, ++dst) {
		byte srcv = *src++;
		byte aphv = *aBuf++;
		if (srcv) {
			word tmpval = this->Data[srcv | extra[aphv]] >> 1 & this->ExtraData;
			word dstval = *dst >> 1 & this->ExtraData;
			tmpval += dstval;
			*dst = tmpval;
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
