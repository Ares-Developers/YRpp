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
		{ PUSH_VAR32(mode); THISCALL(0x6593F0); }

	~RadBeam()
		{ }

	static RadBeam* Allocate(int mode)
		{ PUSH_VAR32(mode); CALL(0x659110); }

	void SetColor(ColorStruct *color)
		{ this->Color = *color; }

	void SetCoordsSource(CoordStruct *loc)
		{ this->SourceLocation = *loc; }

	void SetCoordsTarget(CoordStruct *loc)
		{ this->TargetLocation = *loc; }

	static void DrawAll()
		{ CALL(0x6591B0); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(DWORD, unknown_0);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(byte, unknown_8);
	PROPERTY(DWORD, unknown_C);
	PROPERTY(DWORD, unknown_10);
	PROPERTY(DWORD, unknown_14);
	PROPERTY(double, unknown_18);
	PROPERTY_STRUCT(ColorStruct, Color);
	PROPERTY_STRUCT(CoordStruct, SourceLocation); //FLH
	PROPERTY_STRUCT(CoordStruct, TargetLocation);
	PROPERTY(DWORD, unknown_3C);
	PROPERTY(double, unknown_40);
	PROPERTY(double, unknown_48);
	PROPERTY(DWORD, unknown_50);
	PROPERTY(DWORD, unknown_54);
	PROPERTY(byte, unknown_58);
	PROPERTY(DWORD, unknown_5C);
	PROPERTY(DWORD, unknown_60);
	PROPERTY(DWORD, unknown_64);
	PROPERTY(double, unknown_68);
	PROPERTY(CoordStruct, AnotherLocation);
	PROPERTY(DWORD, unknown_7C);
	PROPERTY(double, unknown_80);
	PROPERTY(DWORD, unknown_88);
	PROPERTY(DWORD, unknown_8C);
	PROPERTY(CoordStruct, AndAnotherLocation);
	PROPERTY(DWORD, unknown_9C);
	PROPERTY(DWORD, unknown_A0);
	PROPERTY(DWORD, unknown_A4);
	PROPERTY(DWORD, unknown_A8);
	PROPERTY(DWORD, unknown_AC);
	PROPERTY(DWORD, unknown_B0);
	PROPERTY(DWORD, unknown_B4);
	PROPERTY(double, unknown_B8);
	PROPERTY(byte, unknown_C0);
	PROPERTY(DWORD, unknown_C4);
};

#endif