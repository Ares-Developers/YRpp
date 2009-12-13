#ifndef BUILDINGTYPE_H
#define BUILDINGTYPE_H

#include <TechnoTypeClass.h>

struct BuildingAnimStruct
{
	char Anim[0x10];
	char Damaged[0x10];
	char Garrisoned[0x10];
	Point2D Position;
	int ZAdjust;
	int YSort;
	bool Powered;
	bool PoweredLight;
	bool PoweredEffect;
	bool PoweredSpecial;
};

struct BuildingAnimFrameStruct
{
	DWORD dwUnknown;
	int FrameCount;
	int FrameDuration;
};

class BuildingTypeClass : public TechnoTypeClass
{
public:
	enum {AbsID = abs_BuildingType};

	//Array
	ABSTRACTTYPE_ARRAY(BuildingTypeClass);

	static int &HeightInLeptons;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	//Destructor
	virtual ~BuildingTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass
	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//TechnoTypeClass
	//BuildingTypeClass
	virtual SHPStruct* LoadBuildup() R0;

	//Constructor
	BuildingTypeClass(const char* pID) : TechnoTypeClass(false)
		JMP_THIS(0x45DD90);

	//non-virtual
	short GetFoundationWidth()
		JMP_THIS(0x45EC90);
	short GetFoundationHeight(bool bIncludeBib)
		JMP_THIS(0x45ECA0);

protected:
	BuildingTypeClass() : TechnoTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(CellStruct*, FoundationData);
	PROPERTY(SHPStruct*, Buildup);
	PROPERTY(bool, BuildupLoaded);
	PROPERTY(eBuildCat, BuildCat);
	PROPERTY_STRUCT(CoordStruct, HalfDamageSmokeLocation1);
	PROPERTY_STRUCT(CoordStruct, HalfDamageSmokeLocation2);
private: DWORD align_E24;
	PROPERTY(double, GateCloseDelay);
	PROPERTY(int, LightVisibility);
	PROPERTY(int, LightIntensity);
	PROPERTY(int, LightRedTint);
	PROPERTY(int, LightGreenTint);
	PROPERTY(int, LightBlueTint);
	PROPERTY_STRUCT(Point2D, PrimaryFirePixelOffset);
	PROPERTY_STRUCT(Point2D, SecondaryFirePixelOffset);
	PROPERTY(int, ToOverlay);
	PROPERTY(int, ToTile);
	PROPERTY_STRING(BuildupFile, 0x10);
	PROPERTY(int, BuildupSound);
	PROPERTY(int, PackupSound);
	PROPERTY(int, CreateUnitSound);
	PROPERTY(int, UnitEnterSound);
	PROPERTY(int, UnitExitSound);
	PROPERTY(int, WorkingSound);
	PROPERTY(int, NotWorkingSound);
	PROPERTY_STRING(PowersUpBuilding, 0x18);
	PROPERTY(UnitTypeClass*, FreeUnit);
	PROPERTY(InfantryTypeClass*, SecretInfantry);
	PROPERTY(UnitTypeClass*, SecretUnit);
	PROPERTY(BuildingTypeClass*, SecretBuilding);
	PROPERTY(int, field_EB0);
	PROPERTY(int, Adjacent);
	PROPERTY(eAbstractType, Factory);
	PROPERTY_STRUCT(CoordStruct, TargetCoordOffset);
	PROPERTY_STRUCT(CoordStruct, ExitCoord);
	PROPERTY(CellStruct*, FoundationOutside);
	PROPERTY(int, field_ED8);
	PROPERTY(int, DeployFacing);
	PROPERTY(int, PowerBonus);
	PROPERTY(int, PowerDrain);
	PROPERTY(int, ExtraPowerBonus);
	PROPERTY(int, ExtraPowerDrain);
	PROPERTY(eFoundation, Foundation);
	PROPERTY(int, Height);
	PROPERTY(int, OccupyHeight);
	PROPERTY(int, MidPoint);
	PROPERTY(int, DoorStages);

protected:
	BuildingAnimFrameStruct BuildingAnimFrame[6];
public:
	BuildingAnimFrameStruct* get_BuildingAnimFrame(int i)
		{ return &BuildingAnimFrame[i]; }

protected:
	BuildingAnimStruct BuildingAnim[0x15];
public:
	BuildingAnimStruct* get_BuildingAnim(int i)
		{ return &BuildingAnim[i]; }

	PROPERTY(int, Upgrades);
	PROPERTY(SHPStruct*, DeployingAnim);
	PROPERTY(bool, DeployingAnimLoaded);
	PROPERTY(SHPStruct*, UnderDoorAnim);
	PROPERTY(bool, UnderDoorAnimLoaded);
	PROPERTY(SHPStruct*, Rubble);
	PROPERTY(bool, RubbleLoaded);
	PROPERTY(SHPStruct*, RoofDeployingAnim);
	PROPERTY(bool, RoofDeployingAnimLoaded);
	PROPERTY(SHPStruct*, UnderRoofDoorAnim);
	PROPERTY(bool, UnderRoofDoorAnimLoaded);
	PROPERTY(SHPStruct*, DoorAnim);
	PROPERTY(SHPStruct*, SpecialZOverlay);
	PROPERTY(int, SpecialZOverlayZAdjust);
	PROPERTY(SHPStruct*, BibShape);
	PROPERTY(bool, BibShapeLoaded);
	PROPERTY(int, NormalZAdjust);
	PROPERTY(int, AntiAirValue);
	PROPERTY(int, AntiArmorValue);
	PROPERTY(int, AntiInfantryValue);
	PROPERTY_STRUCT(Point2D, ZShapePointMove);
	PROPERTY(int, unknown_1538);
	PROPERTY(int, unknown_153C);
	PROPERTY(int, unknown_1540);
	PROPERTY(int, unknown_1544);
	PROPERTY(WORD, ExtraLight);
	PROPERTY(bool, TogglePower);
	PROPERTY(bool, HasSpotlight);
	PROPERTY(bool, IsTemple);
	PROPERTY(bool, IsPlug);
	PROPERTY(bool, HoverPad);
	PROPERTY(bool, BaseNormal);
	PROPERTY(bool, EligibileForAllyBuilding);
	PROPERTY(bool, EligibleForDelayKill);
	PROPERTY(bool, NeedsEngineer);
	PROPERTY(int, CaptureEvaEvent);
	PROPERTY(int, ProduceCashStartup);
	PROPERTY(int, ProduceCashAmount);
	PROPERTY(int, ProduceCashDelay);
	PROPERTY(int, InfantryGainSelfHeal);
	PROPERTY(int, UnitsGainSelfHeal);
	PROPERTY(int, RefinerySmokeFrames);
	PROPERTY(bool, Bib);
	PROPERTY(bool, Wall);
	PROPERTY(bool, Capturable);
	PROPERTY(bool, Powered);
	PROPERTY(bool, PoweredSpecial);
	PROPERTY(bool, Overpowerable);
	PROPERTY(bool, Spyable);
	PROPERTY(bool, CanC4);
	PROPERTY(bool, WantsExtraSpace);
	PROPERTY(bool, Unsellable);
	PROPERTY(bool, ClickRepairable);
	PROPERTY(bool, CanBeOccupied);
	PROPERTY(bool, CanOccupyFire);
	PROPERTY(int, MaxNumberOccupants);
	PROPERTY(bool, ShowOccupantPips);

protected:
	Point2D MuzzleFlash[0xA];
public:
	Point2D* get_MuzzleFlash(int i)
		{ return &MuzzleFlash[i]; }


protected:
	Point2D DamageFireOffset[8];
public:
	Point2D* get_DamageFireOffset(int i)
		{ return &DamageFireOffset[i]; }

	PROPERTY_STRUCT(Point2D, QueueingCell);
	PROPERTY(int, NumberImpassableRows);

protected:
	Point2D RemoveOccupy[8];
public:
	Point2D* get_RemoveOccupy(int i)
		{ return &RemoveOccupy[i]; }

protected:
	Point2D AddOccupy[8];
public:
	Point2D* get_AddOccupy(int i)
		{ return &AddOccupy[i]; }

	PROPERTY(bool, Radar);
	PROPERTY(bool, SpySat);
	PROPERTY(bool, ChargeAnim);
	PROPERTY(bool, IsAnimDelayedFire);
	PROPERTY(bool, SiloDamage);
	PROPERTY(bool, UnitRepair);
	PROPERTY(bool, UnitReload);
	PROPERTY(bool, Bunker);
	PROPERTY(bool, Cloning);
	PROPERTY(bool, Grinding);
	PROPERTY(bool, UnitAbsorb);
	PROPERTY(bool, InfantryAbsorb);
	PROPERTY(bool, SecretLab);
	PROPERTY(bool, DoubleThick);
	PROPERTY(bool, Flat);
	PROPERTY(bool, DockUnload);
	PROPERTY(bool, Recoilless);
	PROPERTY(bool, HasStupidGuardMode);
	PROPERTY(bool, BridgeRepairHut);
	PROPERTY(bool, Gate);
	PROPERTY(bool, SAM);
	PROPERTY(bool, ConstructionYard);
	PROPERTY(bool, NukeSilo);
	PROPERTY(bool, Refinery);
	PROPERTY(bool, Weeder);
	PROPERTY(bool, WeaponsFactory);
	PROPERTY(bool, LaserFencePost);
	PROPERTY(bool, LaserFence);
	PROPERTY(bool, FirestormWall);
	PROPERTY(bool, Hospital);
	PROPERTY(bool, Armory);
	PROPERTY(bool, EMPulseCannon);
	PROPERTY(bool, TickTank);
	PROPERTY(bool, TurretAnimIsVoxel);
	PROPERTY(bool, BarrelAnimIsVoxel);
	PROPERTY(bool, CloakGenerator);
	PROPERTY(bool, SensorArray);
	PROPERTY(bool, ICBMLauncher);
	PROPERTY(bool, Artillary);
	PROPERTY(bool, Helipad);
	PROPERTY(bool, OrePurifier);
	PROPERTY(bool, FactoryPlant);
	PROPERTY(float, InfantryCostBonus);
	PROPERTY(float, UnitsCostBonus);
	PROPERTY(float, AircraftCostBonus);
	PROPERTY(float, BuildingsCostBonus);
	PROPERTY(float, DefensesCostBonus);
	PROPERTY(bool, GDIBarracks);
	PROPERTY(bool, NODBarracks);
	PROPERTY(bool, YuriBarracks);
	PROPERTY(float, ChargedAnimTime);
	PROPERTY(int, DelayedFireDelay);
	PROPERTY(int, SuperWeapon);
	PROPERTY(int, SuperWeapon2);
	PROPERTY(int, GateStages);
	PROPERTY(int, PowersUpToLevel);
	PROPERTY(bool, DamagedDoor);
	PROPERTY(bool, InvisibleInGame);
	PROPERTY(bool, TerrainPalette);
	PROPERTY(bool, PlaceAnywhere);
	PROPERTY(bool, ExtraDamageStage);
	PROPERTY(bool, AIBuildThis);
	PROPERTY(bool, IsBaseDefense);
	PROPERTY(BYTE, CloakRadiusInCells);
	PROPERTY(bool, ConcentricRadialIndicator);
	PROPERTY(int, PsychicDetectionRadius);
	PROPERTY(int, BarrelStartPitch);
	PROPERTY_STRING(VoxelBarrelFile, 0x1C);
	PROPERTY_STRUCT(CoordStruct, VoxelBarrelOffsetToPitchPivotPoint);
	PROPERTY_STRUCT(CoordStruct, VoxelBarrelOffsetToRotatePivotPoint);
	PROPERTY_STRUCT(CoordStruct, VoxelBarrelOffsetToBuildingPivotPoint);
	PROPERTY_STRUCT(CoordStruct, VoxelBarrelOffsetToBarrelEnd);
	PROPERTY(bool, DemandLoad);
	PROPERTY(bool, DemandLoadBuildup);
	PROPERTY(bool, FreeBuildup);
	PROPERTY(bool, IsThreatRatingNode);
	PROPERTY(bool, PrimaryFireDualOffset);
	PROPERTY(bool, ProtectWithWall);
	PROPERTY(bool, CanHideThings);
	PROPERTY(bool, CrateBeneath);
	PROPERTY(bool, LeaveRubble);
	PROPERTY(bool, CrateBeneathIsMoney);
	PROPERTY_STRING(TheaterSpecificID, 0x13);
	PROPERTY(int, NumberOfDocks);
	PROPERTY_STRUCT(VectorClass<CoordStruct>, DockingOffsets);
private: DWORD align_1794;
};

#endif
