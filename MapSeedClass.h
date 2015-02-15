#pragma once

#include <LoadOptionsClass.h>

//Random map generator
class MapSeedClass : public LoadOptionsClass
{
protected:
	MapSeedClass()
		{ JMP_THIS(0x595680); }

public:
	virtual ~MapSeedClass()
		{ JMP_THIS(0x5AC270); }
	
	//Loads an SED file
	virtual bool LoadMission(const char* pFilename) const
		{ JMP_THIS(0x597A30); }
	
	//Saves an SED file
	virtual bool SaveMission(const char* pFilename, const wchar_t* pDescription) const
		{ JMP_THIS(0x597760); }
		
	virtual bool DeleteMission(const char* pFilename) const
		{ JMP_THIS(0x597D50); }
		
	virtual bool GetFileEntry(FileEntryClass& FileEntry, const WIN32_FIND_DATAA& pFindData) const
		{ JMP_THIS(0x597D60); }
	
	virtual const wchar_t* GetUIString_Load() const
		{ JMP_THIS(0x597F80); }
		
	virtual const wchar_t* GetUIString_Save() const
		{ JMP_THIS(0x597FA0); }
		
	virtual const wchar_t* GetUIString_Delete() const
		{ JMP_THIS(0x597FC0); }
		
	virtual const wchar_t* GetUIString_GameSaved() const
		{ JMP_THIS(0x597FE0); }

	static MapSeedClass* Global()
		{ return reinterpret_cast<MapSeedClass*>(0xABDFD8); }
	
	//Properties
public:
	int Theater;
	int MapType; //Archipelago, Continent, etc... default 1
	int Resources; //little, moderate, many, etc... default 1
	int Ruggedness;
	int Time; //Morning, Afternoon, Night, etc... default 1
	int WaterAmount;
	int NumPlayers; //default 2
	int Tiberium;
	int TiberiumLayout; //back from TS RMG, now randomized
	int Vegetation;
	int UrbanPresence;
	int Width;
	int Height;
	int Accessibility;
	int RegionSize;
	int Seed; //default -1
	FixedWString<0x80> DescriptionBuffer;
	
	/*
		This is confusing the hell out of me...
		At some points (e.g. 0x5961D2), the MapSeedClass constructor is invoked after allocating 0x178 bytes.
		According to that information, this class would have to end here.
		
		However, 0x595740 fist calls the MapSeedClass constructor and then initializes further fields.
		It looks a lot like the constructor of another class extending MapSeedClass, however there seems to be no type information for it.
		According to 0xABDFD8, that class must be 0x318 bytes long.
		
		I'll simply add the following to this MapSeedClass, if I ever figure out what's behind all this I'll fix this.
		~pd
	*/
	
	DWORD unknown178;
	DWORD unknown17C;
	DWORD unknown180;
	DWORD unknown184;

	TypeList<int> RMGLevelLightSettings; //0x188
	TypeList<int> TemperateAmbientLight; //0x1A4
	TypeList<int> SnowAmbientLight; //0x1C0
	TypeList<int> TemperateAmbientRed; //0x1DC
	TypeList<int> TemperateAmbientGreen; //0x1F8
	TypeList<int> TemperateAmbientBlue; //0x214
	TypeList<int> SnowAmbientRed; //0x230
	TypeList<int> SnowAmbientGreen; //0x24C
	TypeList<int> SnowAmbientBlue; //0x268
	TypeList<int> RMGVegetationMinimums; //0x284
	TypeList<int> RMGVegetationMaximums; //0x2A0

	int RMGMinimumTiberium; //default 2500
	int RMGMaximumTiberium; //default 5500
	TypeList<BuildingTypeClass*> TemperateOrePatchLamps; //0x2C4
	TypeList<BuildingTypeClass*> SnowOrePatchLamps; //0x2E0
	int MaxTrees; //default 500
	bool unknown300; //default true
	DWORD unknown304;
	DWORD unknown308; //UNUSED?
	int Level; //default 4
	bool unknown310;

private:
	DWORD align_314;
};
