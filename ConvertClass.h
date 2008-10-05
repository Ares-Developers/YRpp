/*
	Converts are palettes... AFAIK
*/

#ifndef CONVERT_H
#define CONVERT_H

#include <ArrayClasses.h>

class DSurface;

class ConvertClass
{
public:
	//global array
	static DynamicVectorClass<ConvertClass*>* Array;

	ConvertClass(
		ColorStruct* pColorData,
		ColorStruct* pUnknownColorData, //???
		DSurface* pSurface,
		int nUnknown,
		bool AllocBlitters)
			JMP_THIS(0x48E740);

	virtual ~ConvertClass() RX;

protected:
	ConvertClass() { }
	ConvertClass(bool) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	//That's right, I don't know anything about this class, except what it's used for...
	PROTECTED_PROPERTY(BYTE, unknown_0[0x188]);
};

class LightConvertClass : public ConvertClass
{
public:
	//global array
	static DynamicVectorClass<LightConvertClass*>* Array;

	//Constructor, Destructor
	LightConvertClass(
		DWORD arg0,
		DWORD arg4,
		DWORD arg8,
		DWORD argC,
		DWORD arg10,
		DWORD arg14,
		DWORD arg18,
		DWORD arg1C,
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
