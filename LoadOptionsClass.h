#ifndef LOADOPTIONSCLASS_H
#define LOADOPTIONSCLASS_H

#include <GeneralDefinitions.h>
#include <ArrayClasses.h>
#include <Helpers/String.h>

class FileEntryClass {
public:

	// constructor / destructors
	FileEntryClass() :
		TechLevel(0),
		HouseIndex(-1),
		CampaignIndex(-1),
		IsValid(true),
		IsWrongVersion(false),
		GameMode(GameMode::Campaign),
		LastWriteTime({0, 0})
	{ }

	static int Compare(const FileEntryClass& lhs, const FileEntryClass& rhs) {
		return -CompareFileTime(&lhs.LastWriteTime, &rhs.LastWriteTime);
	}

	bool operator < (const FileEntryClass& rhs) const {
		return Compare(*this, rhs) < 0;
	}

	FixedWString<0x80> Name;
	FixedString<0x20> Filename;
	int TechLevel;
	int HouseIndex;
	FixedWString<0x40> HouseName;
	int CampaignIndex;
	FILETIME LastWriteTime;
	bool IsValid;
	bool IsWrongVersion;
	PROTECTED_PROPERTY(BYTE, align_1B6[2]);
	GameMode GameMode;
};

enum class LoadOptionsMode : unsigned int {
	None = 0,
	Load = 1,
	Save = 2,
	Delete = 3
};

class LoadOptionsClass
{
protected:
	// constructor
	LoadOptionsClass()
		{ JMP_THIS(0x558740); }

public:
	virtual ~LoadOptionsClass()
		{ JMP_THIS(0x55A0D0); }

	virtual bool LoadMission(const char* pFilename) const
		{ JMP_THIS(0x559D60); }

	virtual bool SaveMission(const char* pFilename, const wchar_t* pDescription) const
		{ JMP_THIS(0x559E7B); }

	virtual bool DeleteMission(const char* pFilename) const
		{ JMP_THIS(0x559EB0); }

	virtual bool GetFileEntry(FileEntryClass& FileEntry, const WIN32_FIND_DATAA& pFindData) const
		{ JMP_THIS(0x559ED0); }

	virtual const wchar_t* GetUIString_Load() const
		{ JMP_THIS(0x55A050); }

	virtual const wchar_t* GetUIString_Save() const
		{ JMP_THIS(0x55A070); }

	virtual const wchar_t* GetUIString_Delete() const 
		{ JMP_THIS(0x55A090); }

	virtual const wchar_t* GetUIString_GameSaved() const
		{ JMP_THIS(0x55A0B0); }

	//Properties
	LoadOptionsMode Mode;
	const char* Extension; //"SAV", "SED" for MapSeedClass
	const wchar_t* Description;
	unsigned int SpaceRequirement; //default is 0x800 = 2048
	DWORD unknown_14;
	DWORD unknown_18;
	DWORD unknown_1C;
	DynamicVectorClass<FileEntryClass*> FileEntries;
};

#endif
