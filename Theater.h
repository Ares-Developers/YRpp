#pragma once

#include <GeneralDefinitions.h>
#include <YRPPCore.h>

struct Theater	//US English spelling to keep it consistent with the game
{
public:
	static Theater* const Array;
	static Theater* const TH_Temperate;
	static Theater* const TH_Snow;
	static Theater* const TH_Urban;
	static Theater* const TH_Desert;
	static Theater* const TH_NewUrban;
	static Theater* const TH_Lunar;

	static Theater& GetTheater(TheaterType theater) {
		return Array[static_cast<int>(theater)];
	}

	static int __fastcall FindIndex(const char* pName)
		{ JMP_STD(0x48DBE0); }

	char	Identifier[0x10];		//e.g. "TEMPERATE"
	char	UIName[0x20];			//e.g. "Name:Temperate"
	char	ControlFileName[0xA];	//e.g. "TEMPERAT" -> INI and MIX
	char	ArtFileName[0xA];		//e.g. "ISOTEMP" -> MIX
	char	PaletteFileName[0xA];	//e.g. "ISOTEM" -> PAL
	char	Extension[0x4];			//e.g. "TEM" -> Iso tile file extension
	char	MMExtension[0x4];		//e.g. "MMT" -> Marble Madness tile file extension
	char	Letter[0x2];			//e.g. "T" -> Theater specific IDs (GTCNST, NTWEAP, YTBARRACKS)

	//unused, was probably lighting stuff once
	float	RadarTerrainBrightness;		//0.0 to 1.0
	float	unknown_float_5C;
	float	unknown_float_60;
	float	unknown_float_64;
	int		unknown_int_68;
	int		unknown_int_6C;
};
