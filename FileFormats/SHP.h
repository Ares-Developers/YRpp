#ifndef SHP_H_
#define SHP_H_

#include <BasicStructures.h>

//SHP file stuff
struct SHPStruct
{
	SHPStruct() : Type(0), Width(0), Height(0), Frames(0)
		{}

	~SHPStruct()
		{ JMP_THIS(0x69E500); }

	RectangleStruct* GetFrameBounds(RectangleStruct &buffer, int idxFrame) const
		{ JMP_THIS(0x69E7E0); }

	RectangleStruct GetFrameBounds(int idxFrame) const {
		RectangleStruct buffer;
		return *GetFrameBounds(buffer, idxFrame);
	}

	bool HasCompression(int idxFrame) const
		{ JMP_THIS(0x69E900); }

	WORD	Type;
	short	Width;
	short	Height;
	short	Frames;
};

//=== GLOBAL LINKED LIST OF ALL LOADED SHP FILES
// defined but not used
// static SHPStruct* SHPStruct_first=(SHPStruct*)0xB077B0;
//==============================================

#endif
