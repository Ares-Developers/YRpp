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
class BuildingTypeClass;

class ObjectTypeClass : public AbstractTypeClass
{
public:
	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;
	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//Destructor
	virtual ~ObjectTypeClass() RX;

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest, CoordStruct* pSrc) R0;
	virtual DWORD GetOwners() R0;
	virtual int GetPipMax() R0;
	virtual void vt_entry_78(DWORD dwUnk) RX;
	virtual void vt_entry_7C(DWORD dwUnk) RX;
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) = 0;
	virtual int GetActualCost(HouseClass* pHouse) R0;
	virtual int GetBuildSpeed() R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) = 0;
	virtual void vt_entry_90(DWORD dwUnk) RX;
	virtual BuildingTypeClass* GetFactoryType(bool OverridePrereqs, bool OverridePower, bool OverrideBuildLimit, 
		HouseClass *House) R0;
	virtual SHPStruct* GetCameo() R0;
	virtual SHPStruct* GetImage() R0;

	//Constructor
	ObjectTypeClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x5F7090);

protected:
	ObjectTypeClass() : AbstractTypeClass(false) { }
	ObjectTypeClass(bool) : AbstractTypeClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRUCT(ColorStruct,   RadialColor);
	PROPERTY(BYTE,          unused_9B);
	PROPERTY(int,           Armor);
	PROPERTY(int,           Strength);
	PROPERTY(SHPStruct*,    Image);
	PROPERTY(bool,          IsImageAllocated);
	PROPERTY(bool,          unused_A9);
	PROPERTY(bool,          unused_AA);
	PROPERTY(bool,          unused_AB);
	PROPERTY(SHPStruct*,    AlphaImage);
	PROPERTY_STRUCT(VoxelStruct,   MainVoxel);
	PROPERTY_STRUCT(VoxelStruct,   TurretVoxel); //also used for WO voxels
	PROPERTY_STRUCT(VoxelStruct,   BarrelVoxel);

	PROPERTY_STRUCT_ARRAY(VoxelStruct, ChargerTurrets, 0x12);
	PROPERTY_STRUCT_ARRAY(VoxelStruct, ChargerBarrels, 0x12);

	PROPERTY(bool,          NoSpawnAlt);
	PROPERTY(BYTE,          unused_1E9);
	PROPERTY(BYTE,          unused_1EA);
	PROPERTY(BYTE,          unused_1EB);
	PROPERTY(int,           MaxDimension);
	PROPERTY(int,           CrushSound); //index
	PROPERTY(int,           AmbientSound); //index

	PROPERTY_STRING(ImageFile, 0x19);

	PROPERTY(bool,           AlternateActicArt);
	PROPERTY(bool,           ArcticArtInUse); //not read from ini

	PROPERTY_STRING(AlphaImageFile, 0x19);

	PROPERTY(bool,           Theater);
	PROPERTY(bool,           Crushable);
	PROPERTY(bool,           Bombable);
	PROPERTY(bool,           RadarInvisible);
	PROPERTY(bool,           Selectable);
	PROPERTY(bool,           LegalTarget);
	PROPERTY(bool,           Insignificant);
	PROPERTY(bool,           Immune);
	PROPERTY(bool,           Voxel);
	PROPERTY(bool,           NewTheater);
	PROPERTY(bool,           HasRadialIndicator);
	PROPERTY(bool,           IgnoresFirestorm);
	PROPERTY(bool,           UseLineTrail);
	PROPERTY_STRUCT(ColorStruct,    LineTrailColor);
	PROPERTY(BYTE,           unused_23E);
	PROPERTY(BYTE,           unused_23F);
	PROPERTY(int,            LineTrailColorDecrement);

	PROTECTED_PROPERTY(BYTE, unknown_244[0x50]); //These don't even seem to be of any use...
};

#endif
