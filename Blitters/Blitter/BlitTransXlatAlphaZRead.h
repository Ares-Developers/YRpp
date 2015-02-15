#pragma once

#include <Blitters.h>

template <typename T>
class BlitTransXlatAlphaZRead : public Blitter<T> {
	virtual void Blit
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, int warpOffset)
{
	T *dst = reinterpret_cast < T * >(dest);
	int alphaLevel = min((261 * max(aLvl, 0)) >> 11, 254);
	word *extra = this->ExtraData[alphaLevel << 9];
	for (; length > 0; --length, ++dst) {
		if (*zBuf++ > zMin) {
			byte srcv = *src++;
			if (srcv) {
				*dst = this->Data[srcv | extra[*aBuf++]];
			}
		}
		++dst;
		if (Drawing::ZBuffer->BufferEnd <= zBuf) {
			zBuf -= Drawing::ZBuffer->BufferSize;
		}
		if (Drawing::ABuffer->BufferEnd <= aBuf) {
			aBuf -= Drawing::ABuffer->BufferSize;
		}
	}
}

	virtual void CallBlit0
		(void *dest, byte *src, unsigned int length, WORD zMin, WORD *zBuf, WORD *aBuf, WORD aLvl, WORD unknownArg, DWORD extraArg)
{
	T *dst = reinterpret_cast < T * >(dest);
	int alphaLevel = min((261 * max(aLvl, 0)) >> 11, 254);
	word *extra = this->ExtraData[alphaLevel << 9];
	for (; length > 0; --length, ++dst) {
		if (*zBuf++ > zMin) {
			byte srcv = *src++;
			if (srcv) {
				*dst = extraArg | this->Data[srcv | extra[*aBuf++]];
			}
		}
		++dst;
		if (Drawing::ZBuffer->BufferEnd <= zBuf) {
			zBuf -= Drawing::ZBuffer->BufferSize;
		}
		if (Drawing::ABuffer->BufferEnd <= aBuf) {
			aBuf -= Drawing::ABuffer->BufferSize;
		}
	}
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

