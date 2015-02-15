/*
	File related stuff
*/

#pragma once

#include <ConvertClass.h>
#include <GeneralStructures.h>
#include <CCFileClass.h>
#include <Memory.h>

#include <FileFormats/_Loader.h>

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
	static SHPStruct *&GRFXTXT_SHP;

	static BytePalette *&TEMPERAT_PAL;
	static BytePalette *&GRFXTXT_PAL;

	static ConvertClass *&CAMEO_PAL;
	static ConvertClass *&UNITx_PAL;
	static ConvertClass *&x_PAL;
	static ConvertClass *&GRFTXT_TIBERIUM_PAL;
	static ConvertClass *&ANIM_PAL;
	static ConvertClass *&THEATER_PAL;
	static ConvertClass *&MOUSE_PAL;
	static ConvertClass *&GRFXTXT_Convert;

	static void* LoadFile(const char* pFileName)
		{ return LoadFile(pFileName, false); }

	static SHPStruct* LoadSHPFile(const char* pFileName)
		{ return static_cast<SHPStruct*>(LoadFile(pFileName, true)); }

	//I'm just making this up for easy palette loading
	static ConvertClass* LoadPALFile(const char* pFileName, DSurface* pSurface)
	{
		auto pRawData = reinterpret_cast<const ColorStruct*>(LoadFile(pFileName, false));

		BytePalette ColorData;
		for(int i = 0; i < 0x100; i++)
		{
			ColorData[i].R = static_cast<BYTE>(pRawData[i].R << 2);
			ColorData[i].G = static_cast<BYTE>(pRawData[i].G << 2);
			ColorData[i].B = static_cast<BYTE>(pRawData[i].B << 2);
		}

		return GameCreate<ConvertClass>(&ColorData, TEMPERAT_PAL, pSurface, 0x35, false);
	}

	template <typename T>
	static T* LoadWholeFileEx(const char* pFilename, bool &outAllocated) {
		return static_cast<T*>(LoadWholeFileEx(pFilename, outAllocated));
	}

	// returns a pointer to a new block of bytes. caller takes ownership and has
	// to free it from the game's pool.
	template <typename T = void>
	static T* AllocateFile(const char* pFilename) {
		CCFileClass file(pFilename);
		return static_cast<T*>(file.ReadWholeFile());
	}

	// allocates a new palette with the 6 bit colors converted to 8 bit
	// (not the proper way. how the game does it.) caller takes ownership and
	// has to free it from the game's pool.
	static BytePalette* AllocatePalette(const char* pFilename) {
		auto ret = AllocateFile<BytePalette>(pFilename);

		if(ret) {
			for(auto& color : ret->Entries) {
				color.R <<= 2;
				color.G <<= 2;
				color.B <<= 2;
			}
		}

		return ret;
	}
};
