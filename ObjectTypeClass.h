/*
	ObjectTypes are initialized by INI files.
*/

#pragma once

#include <AbstractTypeClass.h>
#include <FileSystem.h>

//forward declarations
class TechnoTypeClass;
class HouseTypeClass;
class ObjectClass;
class BuildingClass;

class NOVTABLE ObjectTypeClass : public AbstractTypeClass
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
	virtual BuildingClass* FindFactory(bool allowOccupied, bool requirePower, bool requireCanBuild, HouseClass const* pHouse) const R0;
	virtual SHPStruct* GetCameo() const R0;
	virtual SHPStruct* GetImage() const R0;

	static bool __fastcall IsBuildCat5(AbstractType abstractID, int idx)
		{ JMP_STD(0x5004E0); }

	static TechnoTypeClass * __fastcall GetTechnoType(AbstractType abstractID, int idx)
		{ JMP_STD(0x48DCD0); }


	//Constructor
	ObjectTypeClass(const char* pID) noexcept
		: ObjectTypeClass(noinit_t())
	{ JMP_THIS(0x5F7090); }

protected:
	explicit __forceinline ObjectTypeClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ColorStruct RadialColor;
	BYTE          unused_9B;
	Armor         Armor;
	int           Strength;
	SHPStruct*    Image;
	bool          ImageAllocated;
	PROTECTED_PROPERTY(BYTE, align_A9[3]);
	SHPStruct*    AlphaImage;
	VoxelStruct MainVoxel;
	VoxelStruct TurretVoxel; //also used for WO voxels
	VoxelStruct BarrelVoxel;

	VoxelStruct ChargerTurrets [0x12];
	VoxelStruct ChargerBarrels [0x12];

	bool          NoSpawnAlt;
	PROTECTED_PROPERTY(BYTE, align_1E9[3]);
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
	bool           AllowCellContent;
	bool           Voxel;
	bool           NewTheater;
	bool           HasRadialIndicator;
	bool           IgnoresFirestorm;
	bool           UseLineTrail;
	ColorStruct    LineTrailColor;
	PROTECTED_PROPERTY(BYTE, align_23E[2]);
	int            LineTrailColorDecrement;

	SomeVoxelCache VoxelCaches [4]; //These don't even seem to be of any use...
};
