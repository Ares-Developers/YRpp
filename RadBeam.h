#ifndef RADBEAM_H
#define RADBEAM_H

#include <GeneralDefinitions.h>

class TechnoClass;

class RadBeam
{
public:
	static DynamicVectorClass<RadBeam*>* Array;

	//Constructor, Destructor
	RadBeam(int mode) // anything else = rad, 1 = chrono, 2 = magnetron??
	                  //(2 is invoked by RadEruption, but it uses MagnaBeamColor from rules... )
		{ JMP_THIS(0x6593F0); }

	~RadBeam()
		{ }

	static RadBeam* Allocate(int mode)
		{ JMP_STD(0x659110); }

	void SetColor(ColorStruct *color)
		{ this->Color = *color; }

	void SetCoordsSource(CoordStruct *loc)
		{ this->SourceLocation = *loc; }

	void SetCoordsTarget(CoordStruct *loc)
		{ this->TargetLocation = *loc; }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_0;
	TechnoClass* Owner;
	byte unknown_8;
	DWORD unknown_C;
	DWORD unknown_10;
	DWORD unknown_14;
	double unknown_18;
	ColorStruct Color;
	CoordStruct SourceLocation; //FLH
	CoordStruct TargetLocation;
	DWORD Period;
	double Amplitude;
	double unknown_48;
	DWORD unknown_50;
	DWORD unknown_54;
	byte unknown_58;
	DWORD unknown_5C;
	DWORD unknown_60;
	DWORD unknown_64;
	double unknown_68;
	CoordStruct AnotherLocation;
	DWORD unknown_7C;
	double unknown_80;
	DWORD unknown_88;
	DWORD unknown_8C;
	CoordStruct AndAnotherLocation;
	DWORD unknown_9C;
	DWORD unknown_A0;
	DWORD unknown_A4;
	DWORD unknown_A8;
	DWORD unknown_AC;
	DWORD unknown_B0;
	DWORD unknown_B4;
	double unknown_B8;
	byte unknown_C0;
	DWORD unknown_C4;
};

#endif
