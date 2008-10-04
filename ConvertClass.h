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

	//Constructor, Destructor
	ConvertClass(
		ColorStruct* pColorData,
		ColorStruct* pUnknownColorData, //???
		DSurface* pSurface,
		int nUnknown,
		bool AllocBlitters)
		{
			PUSH_VAR8(AllocBlitters);
			PUSH_VAR32(nUnknown);
			PUSH_VAR32(pSurface);
			PUSH_VAR32(pUnknownColorData);
			PUSH_VAR32(pColorData);
			THISCALL(0x48E740);
		}

	~ConvertClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x491210); }

protected:
	ConvertClass(){ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	//That's right, I don't know anything about this class, except what it's used for...
	PROTECTED_PROPERTY(BYTE,    unknown_0[0x188]);
};

class LightConvertClass : public ConvertClass
{
public:
	//global array
	static DynamicVectorClass<LightConvertClass*>* Array;

protected:
	//Constructor, Destructor
	LightConvertClass()
		{ }

	~LightConvertClass()
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	//I have no idea...
	PROTECTED_PROPERTY(BYTE,    unknown_0[0x2C]);
};

#endif
