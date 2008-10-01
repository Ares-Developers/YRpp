/*
	Cells
*/

#ifndef CELL_H
#define CELL_H

#include <AbstractClass.h>

//forward declarations
class ObjectClass;
class TechnoClass;
class BuildingClass;
class UnitClass;
class InfantryClass;
class AircraftClass;
class TerrainClass;
class LightConvertClass;
class RadSiteClass;
class FootClass;

class CellClass : public AbstractClass
{
public:

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~CellClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	// non-virtual

	// get content objects
	ObjectClass *FindObjectNearestTo(CoordStruct *where, bool alt, ObjectClass *ExcludeThis)
		{ PUSH_VAR32(ExcludeThis); PUSH_VAR8(alt); PUSH_VAR32(where); THISCALL(0x47C3D0); }

	ObjectClass *FindObjectOfType(int AbstractID, bool alt)
		{ PUSH_VAR8(alt); PUSH_VAR32(AbstractID); THISCALL(0x47C4D0); }

	BuildingClass *GetBuilding()
		{ THISCALL(0x47C520); }

	UnitClass *GetUnit(bool alt)
		{ PUSH_VAR8(alt); THISCALL(0x47EBA0); }

	InfantryClass *GetInfantry(bool alt)
		{ PUSH_VAR8(alt); THISCALL(0x47EC40); }

	AircraftClass *GetAircraft(bool alt)
		{ PUSH_VAR8(alt); THISCALL(0x47EBF0); }

	TerrainClass *GetTerrain(bool alt)
		{ PUSH_VAR8(alt); THISCALL(0x47C550); }

	/* craziest thing... first iterates Content looking to Aircraft,
	 * failing that, calls FindObjectNearestTo,
	 * if that fails too, reiterates Content looking for Terrain
	 */
	ObjectClass *GetSomeObject(CoordStruct *where, bool alt)
		{ PUSH_VAR32(where); PUSH_VAR8(alt); THISCALL(0x47C5A0); }


	// misc
	void SetWallOwner()
		{ THISCALL(0x47D210); }

	// adjusts LAT
	void SetupLAT()
		{ THISCALL(0x47CA80); }

	// checks for nearby cliff impassability, calls SetupLAT(), sets up TubeClass if tunnel, cell anim if attached, etc
	void Setup()
		{ THISCALL(0x47D2B0); }

	void BlowUpBridge()
		{ THISCALL(0x47DD70); }

	// those unks are passed to TechnoClass::Scatter in that same order
	void ScatterContent(DWORD unk2, DWORD unk3, DWORD unk4, bool alt)
		{ PUSH_VAR8(alt); PUSH_VAR32(unk4); PUSH_VAR32(unk3); PUSH_VAR32(unk2); THISCALL(0x481670); }

	void GetNeighbourCell(unsigned int direction)
		{ PUSH_VAR32(direction); THISCALL(0x481810); }

	// called whenever anything moves, first to remove threat from source cell, second time to add threat to dest cell
	void UpdateThreat(unsigned int SourceHouse, signed int ThreatLevel)
		{ PUSH_VAR32(ThreatLevel); PUSH_VAR32(SourceHouse); THISCALL(0x481870); }

	void CollectCrate(FootClass *Collector)
		{ THISCALL(0x481A00); }

	void ProcessColourComponents(int *arg0, int *Intensity, signed int *Ambient, int *a5, int *a6, int *tintR, int *tintG, int *tintB)
		{ PUSH_VAR32(tintB);
		  PUSH_VAR32(tintG);
		  PUSH_VAR32(tintR);
		  PUSH_VAR32(a6);
		  PUSH_VAR32(a5);
		  PUSH_VAR32(Ambient);
		  PUSH_VAR32(Intensity);
		  PUSH_VAR32(arg0);
			THISCALL(0x484180); }

	/*TubeClass*/void GetTunnel()
		{ THISCALL(0x484F20); }

	// don't laugh, it returns the uiname of contained tiberium... which nobody ever sets
	wchar_t *GetUIName()
		{ THISCALL(0x484FF0); }

	// returns the tiberium's index in OverlayTypes
	int GetContainedTiberiumIndex()
		{ THISCALL(0x485010); }

	int GetContainedTiberiumValue()
		{ THISCALL(0x485020); }

	int SetMapCoords(CoordStruct *coords)
		{ PUSH_VAR32(coords); THISCALL(0x485240); }

	// in leptons
	CoordStruct *Get3DCoords(CoordStruct *result)
		{ PUSH_VAR32(result); THISCALL(0x486840); }

	// depends on one of the cell flags being set
	CoordStruct *Get3DCoords2(CoordStruct *result)
		{ PUSH_VAR32(result); THISCALL(0x486890); }

	// used by ambient waves and stuff
	CoordStruct *Get3DCoords3(CoordStruct *result)
		{ PUSH_VAR32(result); THISCALL(0x480A30); }

	void ActivateVeins()
		{ THISCALL(0x486920); }


	// cloak generators
	bool CloakGen_InclHouse(unsigned int idx)
		{ return ((1 << idx) & this->CloakedByHouses) != 0; }

	void CloakGen_AddHouse(unsigned int idx)
		{ this->CloakedByHouses |= 1 << idx; }

	void CloakGen_RemHouse(unsigned int idx)
		{ this->CloakedByHouses &= ~(1 << idx); }

	// unused, returns 0 if that house doesn't have cloakgens covering this cell or Player has sensors over this cell
	bool DrawObjectsCloaked(int OwnerHouseIdx)
		{ PUSH_VAR32(OwnerHouseIdx); THISCALL(0x486800); }


	// sensors
	bool Sensors_InclHouse(unsigned int idx)
		{ return this->SensorsOfHouses[idx] > 0; }

	void Sensors_AddOfHouse(unsigned int idx)
		{ ++this->SensorsOfHouses[idx]; }

	void Sensors_RemOfHouse(unsigned int idx)
		{ --this->SensorsOfHouses[idx]; }


	// disguise sensors
	bool DisguiseSensors_InclHouse(unsigned int idx)
		{ return this->DisguiseSensorsOfHouses[idx] > 0; }

	void DisguiseSensors_AddOfHouse(unsigned int idx)
		{ ++this->DisguiseSensorsOfHouses[idx]; }

	void DisguiseSensors_RemOfHouse(unsigned int idx)
		{ --this->DisguiseSensorsOfHouses[idx]; }


	// Rad Sites
	void SetRadSite(RadSiteClass *Rad)
		{ this->RadSite = Rad; }

	RadSiteClass* GetRadSite()
		{ return this->RadSite; }

	bool IsRadiated()
		{ THISCALL(0x487C90); }

	int GetRadLevel()
		{ THISCALL(0x487CB0); }

	void RadLevel_Increase(double amount)
		{ double *arg = &amount;
		  PUSH_VAR64(arg);
		  THISCALL(0x487CE0); }

	void RadLevel_Decrease(double amount)
		{ double *arg = &amount;
		  PUSH_VAR64(arg);
		  THISCALL(0x487D00); }

	// helper mimicking game's behaviour
	ObjectClass* GetContent()
		{ return this->Flags & cf_Bridge ? this->AltObject : this->FirstObject; }

	// tilesets
#define ISTILE(tileset, addr) \
	bool Tile_Is_ ## tileset() \
		{ THISCALL(addr); }

ISTILE(Tunnel, 0x484AB0);
ISTILE(Water, 0x485060);
ISTILE(Blank, 0x486380);
ISTILE(Ramp, 0x4863A0);
ISTILE(Cliff, 0x4863D0);
ISTILE(Shore, 0x4865B0);
ISTILE(Wet, 0x4865D0);
ISTILE(MiscPave, 0x486650);
ISTILE(Pave, 0x486670);
ISTILE(DirtRoad, 0x486690);
ISTILE(PavedRoad, 0x4866D0);
ISTILE(PavedRoadEnd, 0x4866F0);
ISTILE(PavedRoadSlope, 0x486710);
ISTILE(Median, 0x486730);
ISTILE(Bridge, 0x486750);
ISTILE(WoodBridge, 0x486770);
ISTILE(ClearToSandLAT, 0x486790);
ISTILE(Green, 0x4867B0);
ISTILE(NotWater, 0x4867E0);
ISTILE(DestroyableCliff, 0x486900);

	// HACK EVIL HACK
	static int BridgeHeight()
		{ return *(int *)0xB0C07C; }

	static CoordStruct * Cell2Coord(CellStruct* cell, CoordStruct *crd)
		{
			crd->X = cell->X * 256 + 128;
			crd->Y = cell->Y * 256 + 128;
			crd->Z = 0;
			return crd;
		}

	CoordStruct * FixHeight(CoordStruct *crd)
		{
			crd->Z += (this->Flags & cf_Bridge) * BridgeHeight();
			return crd;
		}

protected:
	//Constructor
	CellClass():AbstractClass(false)
		{ THISCALL(0x47BBF0); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(CellStruct,         MapCoords);	//Where on the map does this Cell lie?

	PROTECTED_PROPERTY(BYTE,     unknown_28[0xC]);

	PROPERTY(LightConvertClass*, LightConvert);
	PROPERTY(int,                IsoTileTypeIndex);	//What tile is this Cell?

	PROTECTED_PROPERTY(BYTE,     unknown_3C[8]);

	PROPERTY(int,                OverlayTypeIndex);	//What Overlay lies on this Cell?
	PROPERTY(int,                SmudgeTypeIndex);	//What Smudge lies on this Cell?

	PROPERTY(DWORD,              unknown_4C);
	PROPERTY(int,                WallOwnerIndex); // Which House owns the wall placed in this Cell?
	                                              // Determined by finding the nearest BuildingType and taking its owner
	PROPERTY(DWORD,              unknown_54);
	PROPERTY(DWORD,              unknown_58);
	PROPERTY(DWORD,              unknown_5C);
	PROPERTY(DWORD,              unknown_60);
	PROPERTY(DWORD,              unknown_64);
	PROPERTY(DWORD,              unknown_68);
	PROPERTY(DWORD,              unknown_6C);
	PROPERTY(DWORD,              unknown_70);
	PROPERTY(DWORD,              unknown_74);
	PROPERTY(DWORD,              CloakedByHouses);	//Is this cell in a cloak generator's radius? One bit per House.

	// Is this cell in range of some SensorsSight= equipment? One Word(!) per House, ++ and -- per unit.
protected:
	unsigned short               SensorsOfHouses[0x18]; // ! 24 houses instead of 32 like cloakgen
/*
	// use Sensors_ funcs above
public:
	unsigned short               get_SensorsOfHouses(int idx)
		{ return SensorsOfHouses[i]; }
	void                         set_SensorsOfHouses(int idx, unsigned short val)
		{ SensorsOfHouses[i] = val; }
*/

	// Is this cell in range of some DetectDisguise= equipment? One Word(!) per House, ++ and -- per unit.
protected:
	unsigned short               DisguiseSensorsOfHouses[0x18]; // ! 24 houses instead of 32 like cloakgen
/*
public:
	// use DisguiseSensors_ funcs above
	unsigned short               get_DisguiseSensorsOfHouses(int idx)
		{ return DisguiseSensorsOfHouses[i]; }
	void                         set_DisguiseSensorsOfHouses(int idx, unsigned short val)
		{ DisguiseSensorsOfHouses[i] = val; }
*/

	PROPERTY(DWORD,              unknown_DC);
	PROPERTY(DWORD,              unknown_E0);

	PROPERTY(ObjectClass*,       FirstObject);	//The first Object on this Cell. NextObject functions as a linked list.

	//Some other Object on this cell, for functions above that use "bool alt":
	// ObjectClass *iterationItem = alt ? this->AltContent) : this->Content;
	PROPERTY(ObjectClass*,       AltObject);

//	PROTECTED_PROPERTY(BYTE,	unknown_E8[4]);

	PROPERTY(eLandType,          LandType);	//What type of floor is this Cell?
	PROPERTY(double,             RadLevel);	//The level of radiation on this Cell.
	PROPERTY(RadSiteClass*,      RadSite);	//A pointer to the responsible RadSite.

	PROPERTY(DWORD,              unknown_FC);
	PROPERTY(DWORD,              unknown_100);
	PROPERTY(DWORD,              unknown_104);
	PROPERTY(WORD,               unknown_108);
	PROPERTY(WORD,               unknown_10A);
	PROPERTY(WORD,               unknown_10C);
	PROPERTY(WORD,               unknown_10E);
	PROPERTY(WORD,               unknown_110);
	PROPERTY(WORD,               unknown_112);
	PROPERTY(WORD,               unknown_114);
	PROPERTY(signed short,       TubeIndex); // !@#% Westwood braindamage, can't use > 127! (movsx eax, al)

	PROPERTY(char,               unknown_118);
	PROPERTY(char,               unknown_119);
	PROPERTY(char,               Height);
	PROPERTY(char,               Level);

	PROTECTED_PROPERTY(BYTE,     unknown_11C);
	PROTECTED_PROPERTY(BYTE,     unknown_11D);

	PROPERTY(char,               Powerup);	//The crate type on this cell.

	PROTECTED_PROPERTY(BYTE,     unknown_11F);
	PROPERTY(BYTE,               Shroudedness); // trust me, you don't wanna know... if you do, see 0x7F4194 and cry
	PROTECTED_PROPERTY(BYTE,     unknown_121[0xB]);

	PROPERTY(eCellFlags_12C,     CopyFlags);	// related to Flags below
	PROTECTED_PROPERTY(BYTE,     unknown_130[0x10]);

	PROPERTY(eCellFlags,         Flags);	//Various settings.
	PROTECTED_PROPERTY(BYTE,     unknown_144[4]);
};

#endif
