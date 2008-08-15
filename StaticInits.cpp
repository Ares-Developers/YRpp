//This file initilializes static constant values.

#include <YRPP.h>

#include <AbstractTypeClass.h>
DynamicVectorClass<AbstractTypeClass*>* AbstractTypeClass::Array =
								(DynamicVectorClass<AbstractTypeClass*>*)0xA8E968;

#include <AircraftClass.h>
DynamicVectorClass<AircraftClass*>* AircraftClass::Array =
								(DynamicVectorClass<AircraftClass*>*)0xA8E390;

#include <AircraftTypeClass.h>
DynamicVectorClass<AircraftTypeClass*>* AircraftTypeClass::Array =
								(DynamicVectorClass<AircraftTypeClass*>*)0xA8B218;

#include <AlphaShapeClass.h>
DynamicVectorClass<AlphaShapeClass*>* AlphaShapeClass::Array =
								(DynamicVectorClass<AlphaShapeClass*>*)0x88A0F0;

#include <AnimClass.h>
DynamicVectorClass<AnimClass*>* AnimClass::Array =
								(DynamicVectorClass<AnimClass*>*)0xA8E9A8;

#include <AnimTypeClass.h>
DynamicVectorClass<AnimTypeClass*>* AnimTypeClass::Array =
								(DynamicVectorClass<AnimTypeClass*>*)0x8B4150;

#include <BuildingClass.h>
DynamicVectorClass<BuildingClass*>* BuildingClass::Array =
								(DynamicVectorClass<BuildingClass*>*)0xA8EB40;

#include <BuildingTypeClass.h>
DynamicVectorClass<BuildingTypeClass*>* BuildingTypeClass::Array =
								(DynamicVectorClass<BuildingTypeClass*>*)0xA83C68;

#include <CCINIClass.h>
CCINIClass* CCINIClass::INI_AI			= (CCINIClass*)0x887128;
CCINIClass* CCINIClass::INI_Art			= (CCINIClass*)0x887180;
CCINIClass* CCINIClass::INI_Rules		= (CCINIClass*)0x887048;

#include <ColorScheme.h>
DynamicVectorClass<ColorScheme*>* ColorScheme::Array =
								(DynamicVectorClass<ColorScheme*>*)0xB054D0;

#include <CommandClass.h>
DynamicVectorClass<CommandClass*>* CommandClass::Array =
								(DynamicVectorClass<CommandClass*>*)0x87F658;

#include <ConvertClass.h>
DynamicVectorClass<ConvertClass*>* ConvertClass::Array =
								(DynamicVectorClass<ConvertClass*>*)0x89ECF8;

#include <EMPulseClass.h>
DynamicVectorClass<EMPulseClass*>* EMPulseClass::Array =
								(DynamicVectorClass<EMPulseClass*>*)0x8A3870;

#include <HouseClass.h>
DynamicVectorClass<HouseClass*>* HouseClass::Array =
								(DynamicVectorClass<HouseClass*>*)0xA80228;

#include <HouseTypeClass.h>
DynamicVectorClass<HouseTypeClass*>* HouseTypeClass::Array =
								(DynamicVectorClass<HouseTypeClass*>*)0xA83C98;

#include <InfantryClass.h>
DynamicVectorClass<InfantryClass*>* InfantryClass::Array =
								(DynamicVectorClass<InfantryClass*>*)0xA83DE8;

#include <InfantryTypeClass.h>
DynamicVectorClass<InfantryTypeClass*>* InfantryTypeClass::Array =
								(DynamicVectorClass<InfantryTypeClass*>*)0xA8E348;

#include <ConvertClass.h>
DynamicVectorClass<LightConvertClass*>* LightConvertClass::Array =
								(DynamicVectorClass<LightConvertClass*>*)0x87F698;

#include <ObjectClass.h>
DynamicVectorClass<ObjectClass*>* ObjectClass::CurrentObjects =
								(DynamicVectorClass<ObjectClass*>*)0xA8ECB8;

#include <OverlayClass.h>
DynamicVectorClass<OverlayClass*>* OverlayClass::Array =
								(DynamicVectorClass<OverlayClass*>*)0xA8EC50;

#include <OverlayTypeClass.h>
DynamicVectorClass<OverlayTypeClass*>* OverlayTypeClass::Array =
								(DynamicVectorClass<OverlayTypeClass*>*)0xA83D80;

#include <ParticleClass.h>
DynamicVectorClass<ParticleClass*>* ParticleClass::Array =
								(DynamicVectorClass<ParticleClass*>*)0xA83DC8;

#include <ParticleSystemClass.h>
DynamicVectorClass<ParticleSystemClass*>* ParticleSystemClass::Array =
								(DynamicVectorClass<ParticleSystemClass*>*)0xA80208;

#include <ParticleSystemTypeClass.h>
DynamicVectorClass<ParticleSystemTypeClass*>* ParticleSystemTypeClass::Array =
								(DynamicVectorClass<ParticleSystemTypeClass*>*)0xA83D68;

#include <ParticleTypeClass.h>
DynamicVectorClass<ParticleTypeClass*>* ParticleTypeClass::Array =
								(DynamicVectorClass<ParticleTypeClass*>*)0xA83D98;

#include <RadSiteClass.h>
DynamicVectorClass<RadSiteClass*>* RadSiteClass::Array =
								(DynamicVectorClass<RadSiteClass*>*)0xB04BD0;

#include <SideClass.h>
DynamicVectorClass<SideClass*>* SideClass::Array =
								(DynamicVectorClass<SideClass*>*)0x8B4120;

#include <SmudgeClass.h>
DynamicVectorClass<SmudgeClass*>* SmudgeClass::Array =
								(DynamicVectorClass<SmudgeClass*>*)0xA8B1E0;

#include <SmudgeTypeClass.h>
DynamicVectorClass<SmudgeTypeClass*>* SmudgeTypeClass::Array =
								(DynamicVectorClass<SmudgeTypeClass*>*)0xA8EC18;

#include <SuperWeaponTypeClass.h>
DynamicVectorClass<SuperWeaponTypeClass*>* SuperWeaponTypeClass::Array =
								(DynamicVectorClass<SuperWeaponTypeClass*>*)0xA8E330;

#include <TemporalClass.h>
DynamicVectorClass<TemporalClass*>* TemporalClass::Array =
								(DynamicVectorClass<TemporalClass*>*)0xB0EC60;

//Tree classes don't have their VTables done yet
/*#include <TerrainClass.h>
DynamicVectorClass<TerrainClass*>* TerrainClass::Array =
								(DynamicVectorClass<TerrainClass*>*)0xA8E988;

#include <TerrainTypeClass.h>
DynamicVectorClass<TerrainTypeClass*>* TerrainTypeClass::Array =
								(DynamicVectorClass<TerrainTypeClass*>*)0xA8E318;*/

#include <UnitClass.h>
DynamicVectorClass<UnitClass*>* UnitClass::Array =
								(DynamicVectorClass<UnitClass*>*)0x8B4108;

#include <UnitTypeClass.h>
DynamicVectorClass<UnitTypeClass*>* UnitTypeClass::Array =
								(DynamicVectorClass<UnitTypeClass*>*)0xA83CE0;

#include <VocClass.h>
DynamicVectorClass<VocClass*>* VocClass::Array =
								(DynamicVectorClass<VocClass*>*)0xB1D378;

#include <VoxClass.h>
DynamicVectorClass<VoxClass*>* VoxClass::Array =
								(DynamicVectorClass<VoxClass*>*)0xB1D4A0;

#include <WarheadTypeClass.h>
DynamicVectorClass<WarheadTypeClass*>* WarheadTypeClass::Array =
								(DynamicVectorClass<WarheadTypeClass*>*)0x8874C0;

#include <WeaponTypeClass.h>
DynamicVectorClass<WeaponTypeClass*>* WeaponTypeClass::Array =
								(DynamicVectorClass<WeaponTypeClass*>*)0x887568;
