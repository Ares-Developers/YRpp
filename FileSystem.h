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
		{ JMP_STD(0x5B40B0); }

	static void* __fastcall LoadWholeFileEx(const char* pFilename, bool &outAllocated)
		{ JMP_STD(0x4A38D0); }

	static SHPStruct *&PIPBRD_SHP;
	static SHPStruct *&PIPS_SHP;
	static SHPStruct *&PIPS2_SHP;
	static SHPStruct *&TALKBUBL_SHP;
	static SHPStruct *&WRENCH_SHP;
	static SHPStruct *&POWEROFF_SHP;

	static BytePalette *&TEMPERAT_PAL;

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
			TEMPERAT_PAL,
			pSurface,
			0x35,
			0);
	}

	template <typename T>
	static T* LoadWholeFileEx(const char* pFilename, bool &outAllocated) {
		return static_cast<T*>(LoadWholeFileEx(pFilename, outAllocated));
	}
};

#endif
