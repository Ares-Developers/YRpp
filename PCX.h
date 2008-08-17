//This can be used to load PCX files into BSurfaces!

#ifndef PCX_H
#define PCX_H

#include <Surface.h>

class PCX
{
public:
	//Load a PCX file
	static bool LoadFile(const char* pFileName)
	{
		PUSH_IMM(0);
		PUSH_IMM(2);
		PUSH_VAR32(pFileName);
		THISCALL_EX_RET(0xAC4848, 0x6B9D00, bool);
	}
	
	//Get a BSurface for a PCX file. File needs to be loaded some time first!
	static BSurface* GetSurface(const char* pFileName)
	{
		PUSH_IMM(0);
		PUSH_VAR32(pFileName);
		THISCALL_EX_RET(0xAC4848, 0x6BA140, BSurface*);
	}
};

#endif
