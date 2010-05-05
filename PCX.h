//This can be used to load PCX files into BSurfaces!

#ifndef PCX_H
#define PCX_H

#include <Surface.h>
#include <GeneralDefinitions.h>

class PCX
{
protected:
		//Load a PCX file
		bool ForceLoadFile(const char* pFileName, int flag1, int flag2)
			{ JMP_THIS(0x6B9D00); }

	public:

	static PCX *Instance;

	//Load a PCX file
	bool LoadFile(const char* pFileName, int flag1 = 2, int flag2 = 0)
	{
		if(Instance->GetSurface(pFileName, NULL)) {
			return true;
		}
		return Instance->ForceLoadFile(pFileName, flag1, flag2);
	}

	//Get a BSurface for a PCX file. File needs to be loaded some time first!
	BSurface* GetSurface(const char* pFileName, BytePalette * pPalette = NULL)
		{ JMP_THIS(0x6BA140); }

	void *Buffer;
};

#endif
