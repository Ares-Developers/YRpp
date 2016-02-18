#pragma once

#include <GeneralDefinitions.h>

#include <Helpers/CompileTime.h>

class TechnoClass;

class RadBeam
{
public:
	static constexpr constant_ptr<DynamicVectorClass<RadBeam*>, 0xB04A60u> const Array{};

	// Constructor removed - do not use it, use Allocate instead

	~RadBeam() = default;

	static RadBeam* __fastcall Allocate(RadBeamType mode)
		{ JMP_STD(0x659110); }

	void SetColor(const ColorStruct &color)
		{ this->Color = color; }

	void SetCoordsSource(const CoordStruct &loc)
		{ this->SourceLocation = loc; }

	void SetCoordsTarget(const CoordStruct &loc)
		{ this->TargetLocation = loc; }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_0;
	TechnoClass* Owner;
	byte unknown_8;

	/**
	 * if there's difference in the Y coord of SourceLocation and TargetLocation,
	 * they're both converted to screen coords (2D)
	 * and the difference of those Y coords is taken as this field
	 */
	DWORD unknown_C;


	RadBeamType Type;
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
