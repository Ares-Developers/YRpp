#ifndef THEATER_H
#define THEATER_H

#include <YRPPCore.h>

struct Theater	//US English spelling to keep it consistent with the game
{
	public:
	static Theater* TH_Temperate;
	static Theater* TH_Snow;
	static Theater* TH_Urban;
	static Theater* TH_Desert;
	static Theater* TH_NewUrban;
	static Theater* TH_Lunar;

	static int __fastcall FindIndex(char *Name)
		JMP_STD(0x48DBE0);

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

#endif
