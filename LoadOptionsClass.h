#ifndef LOADOPTIONSCLASS_H
#define LOADOPTIONSCLASS_H

#include <GeneralDefinitions.h>
#include <ArrayClasses.h>

class FileEntryClass; //unknown

class LoadOptionsClass
{
protected:
	LoadOptionsClass() RX;

public:
	virtual ~LoadOptionsClass()
		{ JMP_THIS(0x55A0D0); }
		
	virtual bool LoadMission(const char* lpMultiByteName)
		{ JMP_THIS(0x559D60); }
		
	virtual bool SaveMission(const char* lpMultiByteName, const wchar_t* unknown)
		{ JMP_THIS(0x559E7B); }
		
	virtual bool DeleteMission(const char* fileName)
		{ JMP_THIS(0x559EB0); }
		
	virtual bool unknown_method10(const wchar_t* unknown1, void* unknown2)
		{ JMP_THIS(0x559ED0); }
	
	virtual const wchar_t* GetUIString_Load()
		{ JMP_THIS(0x55A050); }
		
	virtual const wchar_t* GetUIString_Save()
		{ JMP_THIS(0x55A070); }
		
	virtual const wchar_t* GetUIString_Delete()
		{ JMP_THIS(0x55A090); }
		
	virtual const wchar_t* GetUIString_GameSaved()
		{ JMP_THIS(0x55A0B0); }
	
	//Properties
	DWORD unknown04;
	const char* FileExtension; //"SAV", "SED" for MapSeedClass
	DWORD unknown0C;
	int unknown10; //default is 0x800 = 2048
	DWORD unknown14;
	DWORD unknown18;
	DWORD unknown1C;
	DynamicVectorClass<FileEntryClass*> FileEntries;
};

#endif
