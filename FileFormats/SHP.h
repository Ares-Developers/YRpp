#pragma once

#include <BasicStructures.h>

/*
*	SHP structs come in different forms: the plain file data, and a kind of
*	reference used for caching. Usually, it is not needed to know what type a
*	SHPStruct is of, because the the member functions work with both.
*/

struct SHPReference;
struct SHPFile;

//SHP file stuff
struct SHPStruct
{
	SHPStruct() : Type(0), Width(0), Height(0), Frames(0)
		{}

	~SHPStruct()
		{ JMP_THIS(0x69E500); }

	// loads the file, if this is a referece
	void Load()
		{ JMP_THIS(0x69E090); }

	// unloads the data, if this is a reference
	void Unload()
		{ JMP_THIS(0x69E100); }

	// resolves to the actual file data, and loads it if necessary
	SHPFile* GetData()
		{ JMP_THIS(0x69E580); }

	RectangleStruct* GetFrameBounds(RectangleStruct &buffer, int idxFrame) const
		{ JMP_THIS(0x69E7E0); }

	RectangleStruct GetFrameBounds(int idxFrame) const {
		RectangleStruct buffer;
		return *GetFrameBounds(buffer, idxFrame);
	}

	ColorStruct* GetColor(ColorStruct &buffer, int idxFrame) const
		{ JMP_THIS(0x69E860); }

	ColorStruct GetColor(int idxFrame) const {
		ColorStruct buffer;
		return *GetColor(buffer, idxFrame);
	}

	byte* GetPixels(int idxFrame)
		{ JMP_THIS(0x69E740); }

	// Flags & 2
	bool HasCompression(int idxFrame) const
		{ JMP_THIS(0x69E900); }

	bool IsReference() const {
		return Type == 0xFFFF;
	}

	SHPReference* AsReference();

	const SHPReference* AsReference() const;

	SHPFile* AsFile();

	const SHPFile* AsFile() const;

	WORD	Type;
	short	Width;
	short	Height;
	short	Frames;
};

struct SHPReference : public SHPStruct
{
	SHPReference(const char* filename)
		{ JMP_THIS(0x69E430); }

	char*			Filename;
	SHPStruct*		Data;
	bool			Loaded;
	int				Index;
	//linked list of all SHPReferences
	SHPReference*	Next;
	SHPReference*	Prev;
	DWORD			unknown_20;
};

struct SHPFrame
{
	short		Left;
	short		Top;
	short		Width;
	short		Height;
	DWORD		Flags;
	ColorStruct	Color;
	DWORD		unknown_10;
	int			Offset;
};

struct SHPFile : public SHPStruct
{
	const SHPFrame& GetFrameHeader(int idxFrame) const {
		return (&FirstFrame)[idxFrame];
	}

	SHPFrame	FirstFrame;
};

inline SHPReference* SHPStruct::AsReference() {
	return IsReference() ? static_cast<SHPReference*>(this) : nullptr;
}

inline const SHPReference* SHPStruct::AsReference() const {
	return IsReference() ? static_cast<const SHPReference*>(this) : nullptr;
}

inline SHPFile* SHPStruct::AsFile() {
	return !IsReference() ? static_cast<SHPFile*>(this) : nullptr;
}

inline const SHPFile* SHPStruct::AsFile() const {
	return !IsReference() ? static_cast<const SHPFile*>(this) : nullptr;
}

//=== GLOBAL LINKED LIST OF ALL LOADED SHP FILES
// defined but not used
// static SHPStruct* SHPStruct_first=(SHPStruct*)0xB077B0;
//==============================================
