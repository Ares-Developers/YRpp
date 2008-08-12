/*
	File related stuff
*/

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <GeneralStructures.h>
#include <CCFileClass.h>
#include <CCINIClass.h>
#include <ConvertClass.h>

class DSurface;

//Voxel file stuff
class VoxLib;	//VXL
class MotLib;	//HVA

struct VoxelStruct
{
	VoxLib*	VXL;
	MotLib* HVA;
};

//SHP file stuff
struct SHPStruct
{
	WORD		unknown_0;
	short		Width;
	short		Height;
	short		Frames;
	DWORD		unknown_8;
	DWORD		unknown_C;
	//linked list of all SHPStructs
	SHPStruct*	Next;
	SHPStruct*	Prev;
};

//=== GLOBAL LINKED LIST OF ALL LOADED SHP FILES
// defined but not used
// static SHPStruct* SHPStruct_first=(SHPStruct*)0xB077B0;
//==============================================

class FileSystem
{
public:
	static void* LoadFile(const char* pFileName, bool bLoadAsSHP)
		{
			void* pReturn;

			SET_REG8(dl, bLoadAsSHP);
			SET_REG32(ecx,pFileName);
			CALL(0x5B40B0);
			GET_REG32(pReturn,eax);

			return pReturn;
		}

	static void* LoadFile(const char* pFileName)
		{ return LoadFile(pFileName, false); }

	static SHPStruct* LoadSHPFile(const char* pFileName)
		{ return (SHPStruct*)LoadFile(pFileName, true); }

	//I'm just making this up for easy palette loading
	static ConvertClass* LoadPALFile(const char* pFileName, DSurface* pSurface)
	{
		ColorStruct* pRawData = (ColorStruct*)LoadFile(pFileName, false);
		ColorStruct ColorData[0x100];

		for(int i = 0; i < 0x100; i++)
		{
			ColorData[i].R = pRawData[i].R << 2;
			ColorData[i].G = pRawData[i].G << 2;
			ColorData[i].B = pRawData[i].B << 2;
		}

		return new ConvertClass(
			ColorData,
			(ColorStruct*)0x885780,
			pSurface,
			0x35,
			0);
	}
};

#endif
