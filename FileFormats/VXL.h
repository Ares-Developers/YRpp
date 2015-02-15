#pragma once

class CCFileClass;
#include <GeneralStructures.h>

struct VoxelSectionHeader;
struct VoxelSectionTailer;

class VoxLib {
public:
	bool Initialized;
	DWORD CountHeaders;
	DWORD CountTailers;
	DWORD TotalSize;
	VoxelSectionHeader *HeaderData;
	VoxelSectionTailer *TailerData;
	byte * BodyData;

	VoxLib(CCFileClass *Source, bool UseContainedPalette = 0)
		{ JMP_THIS(0x755CD0); }

	~VoxLib()
		{ JMP_THIS(0x755D10); }

	// returns 0 on success, non zero on failure
	signed int ReadFile(CCFileClass *ccFile, bool UseContainedPalette)
		{ JMP_THIS(0x755DB0); }

	// return &this->HeaderData[headerIndex];
	VoxelSectionHeader * leaSectionHeader(int headerIndex)
		{ JMP_THIS(0x7564A0); }

	// return &this->TailerData[a3 + this->HeaderData[headerIndex].limb_number];
	VoxelSectionTailer * leaSectionTailer(int headerIndex, int a3)
		{ JMP_THIS(0x7564B0); }
};

struct TransformVector {
public:
	Vector3D<float> XYZ;
	float Unknown;
};

struct TransformMatrix {
public:
	TransformVector Vectors[3];
};

// file header
struct VoxFileHeader {
public:
	char filename[16];
	int PaletteCount;
	int countHeaders_OrSections1;
	int countTailers_OrSections2;
	int totalSize;
};

// internal representation of the next struct
struct VoxelSectionHeader {
	int limb_number;
	int unk1;
	char unk2;
};

// in file
struct VoxelSectionFileHeader {
public:
	char Name[16];
	VoxelSectionHeader headerData;
};

// in file
struct VoxelSectionFileTailer {
public:
	int span_start_off;
	int span_end_off;
	int span_data_off;
	float DetFloat;
	TransformMatrix TransformationMatrix;
	Vector3D<float> MinBounds;
	Vector3D<float> MaxBounds;
	char size_X;
	char size_Y;
	char size_Z;
	char NormalsMode;
};

// internal representation
struct VoxelSectionTailer {
	int span_start_off;
	int span_end_off;
	int span_data_off;
	float HVAMultiplier;
	TransformMatrix TransformationMatrix;
	Vector3D<float> MinBounds;
	int MaxBounds;
	int field_50;
	int field_54;
	int field_58;
	int field_5C;
	int field_60;
	int field_64;
	int field_68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	char size_X;
	char size_Y;
	char size_Z;
	char NormalsMode;
};
