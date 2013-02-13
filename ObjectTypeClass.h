/*
	ObjectTypes are initialized by INI files.
*/

#ifndef OBJTYPE_H
#define OBJTYPE_H

#include <AbstractTypeClass.h>
#include <FileSystem.h>

//forward declarations
class TechnoTypeClass;
class HouseTypeClass;
class ObjectClass;
class BuildingClass;

class ObjectTypeClass : public AbstractTypeClass
{
public:
	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;
	virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//Destructor
	virtual ~ObjectTypeClass() RX;

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest, CoordStruct* pSrc) const R0;
	virtual DWORD GetOwners() const R0;
	virtual int GetPipMax() const R0;
	virtual void vt_entry_78(DWORD dwUnk) const RX;
	virtual void vt_entry_7C(DWORD dwUnk) RX;
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) = 0;
	virtual int GetActualCost(HouseClass* pHouse) const R0;
	virtual int GetBuildSpeed() const R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) = 0;
	virtual CellStruct * GetFoundationData(bool IncludeBib) const R0;
	virtual BuildingClass* FindFactory(bool CheckPrereqs, bool CheckPower, bool CheckBuildLimit,
		HouseClass *House) const R0;
	virtual SHPStruct* GetCameo() const R0;
	virtual SHPStruct* GetImage() const R0;

	static bool __fastcall IsBuildCat5(eAbstractType abstractID, int idx)
		{ JMP_STD(0x5004E0); }

	static TechnoTypeClass * __fastcall GetTechnoType(eAbstractType abstractID, int idx)
		{ JMP_STD(0x48DCD0); }


	//Constructor
	ObjectTypeClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x5F7090); }

protected:
	ObjectTypeClass() : AbstractTypeClass(false) { }
	ObjectTypeClass(bool) : AbstractTypeClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ColorStruct RadialColor;
	BYTE          unused_9B;
	int           Armor;
	int           Strength;
	SHPStruct*    Image;
	bool          ImageIsOutdated;
	bool          unused_A9;
	bool          unused_AA;
	bool          unused_AB;
	SHPStruct*    AlphaImage;
	VoxelStruct MainVoxel;
	VoxelStruct TurretVoxel; //also used for WO voxels
	VoxelStruct BarrelVoxel;

	VoxelStruct ChargerTurrets [0x12];
	VoxelStruct ChargerBarrels [0x12];

	bool          NoSpawnAlt;
	BYTE          unused_1E9;
	BYTE          unused_1EA;
	BYTE          unused_1EB;
	int           MaxDimension;
	int           CrushSound; //index
	int           AmbientSound; //index

	char ImageFile [0x19];

	bool           AlternateArcticArt;
	bool           ArcticArtInUse; //not read from ini

	char AlphaImageFile [0x19];

	bool           Theater;
	bool           Crushable;
	bool           Bombable;
	bool           RadarInvisible;
	bool           Selectable;
	bool           LegalTarget;
	bool           Insignificant;
	bool           Immune;
	bool           IsLogic; // add objects to the logic vector
	BYTE           unused_235;
	bool           Voxel;
	bool           NewTheater;
	bool           HasRadialIndicator;
	bool           IgnoresFirestorm;
	bool           UseLineTrail;
	ColorStruct LineTrailColor;
	BYTE           unused_23E;
	BYTE           unused_23F;
	int            LineTrailColorDecrement;

	SomeVoxelCache VoxelCaches [4]; //These don't even seem to be of any use...
};

#endif
