/*
	File related stuff
*/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <ConvertClass.h>
#include <GeneralStructures.h>

#include <FileFormats/_Loader.h>

class CCFileClass;
class DSurface;

struct VoxelStruct
{
	VoxLib* VXL;
	MotLib* HVA;
};

class FileSystem
{
public:
	static void* __fastcall LoadFile(const char* pFileName, bool bLoadAsSHP)
		JMP_STD(0x5B40B0);

	static SHPStruct *&PIPS_SHP;

	static ConvertClass *&CAMEO_PAL;
	static ConvertClass *&UNITx_PAL;
	static ConvertClass *&x_PAL;
	static ConvertClass *&GRFTXT_TIBERIUM_PAL;
	static ConvertClass *&ANIM_PAL;
	static ConvertClass *&THEATER_PAL;
	static ConvertClass *&MOUSE_PAL;

	static void* LoadFile(const char* pFileName)
		{ return LoadFile(pFileName, false); }

	static SHPStruct* LoadSHPFile(const char* pFileName)
		{ return (SHPStruct*)LoadFile(pFileName, true); }

	//I'm just making this up for easy palette loading
	static ConvertClass* LoadPALFile(const char* pFileName, DSurface* pSurface)
	{
		ColorStruct* pRawData = (ColorStruct*)LoadFile(pFileName, false);
		BytePalette ColorData;

		for(int i = 0; i < 0x100; i++)
		{
			ColorData[i].R = pRawData[i].R << 2;
			ColorData[i].G = pRawData[i].G << 2;
			ColorData[i].B = pRawData[i].B << 2;
		}

		return new ConvertClass(
			&ColorData,
			(BytePalette*)0x885780,
			pSurface,
			0x35,
			0);
	}
};

#endif
