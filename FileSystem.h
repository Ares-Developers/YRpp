/*
	File related stuff
*/

#pragma once

#include <ConvertClass.h>
#include <GeneralStructures.h>
#include <CCFileClass.h>
#include <Memory.h>

#include <FileFormats/_Loader.h>
#include <Helpers/CompileTime.h>

class DSurface;

struct VoxelStruct
{
	VoxLib* VXL;
	MotLib* HVA;
};

class FileSystem
{
public:
	static constexpr reference<SHPStruct*, 0xAC1478u> PIPBRD_SHP{};
	static constexpr reference<SHPStruct*, 0xAC147Cu> PIPS_SHP{};
	static constexpr reference<SHPStruct*, 0xAC1480u> PIPS2_SHP{};
	static constexpr reference<SHPStruct*, 0xAC1484u> TALKBUBL_SHP{};
	static constexpr reference<SHPStruct*, 0x89DDC8u> WRENCH_SHP{};
	static constexpr reference<SHPStruct*, 0x89DDC4u> POWEROFF_SHP{};
	static constexpr reference<SHPStruct*, 0xA8F794u> GRFXTXT_SHP{};

	static constexpr reference<BytePalette, 0x885780u> TEMPERAT_PAL{};
	static constexpr reference<BytePalette*, 0xA8F790u> GRFXTXT_PAL{};

	static constexpr reference<ConvertClass*, 0x87F6B0u> CAMEO_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6B4u> UNITx_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6B8u> x_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6BCu> GRFTXT_TIBERIUM_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6C0u> ANIM_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6C4u> THEATER_PAL{};
	static constexpr reference<ConvertClass*, 0x87F6C8u> MOUSE_PAL{};
	static constexpr reference<ConvertClass*, 0xA8F798u> GRFXTXT_Convert{};

	static void* __fastcall LoadFile(const char* pFileName, bool bLoadAsSHP)
		{ JMP_STD(0x5B40B0); }

	static void* __fastcall LoadWholeFileEx(const char* pFilename, bool &outAllocated)
		{ JMP_STD(0x4A38D0); }

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

		return GameCreate<ConvertClass>(ColorData, TEMPERAT_PAL, pSurface, 0x35, false);
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
