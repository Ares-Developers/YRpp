//This file initilializes static constant values.

#include <YRPP.h>

#define DECL(cls, adr) \
	DynamicVectorClass<cls*>* cls::Array = \
		(DynamicVectorClass<cls*>*)adr;


#include <AbstractTypeClass.h>
DECL(AbstractTypeClass, 0xA8E968);

#include <AircraftClass.h>
DECL(AircraftClass, 0xA8E390);

#include <AircraftTypeClass.h>
DECL(AircraftTypeClass, 0xA8B218);

#include <AlphaShapeClass.h>
DECL(AlphaShapeClass, 0x88A0F0);

#include <AnimClass.h>
DECL(AnimClass, 0xA8E9A8);

#include <AnimTypeClass.h>
DECL(AnimTypeClass, 0x8B4150);

#include <BulletClass.h>
DECL(BulletClass, 0xA8ED40);

#include <BulletTypeClass.h>
DECL(BulletTypeClass, 0xA83C80);

#include <BuildingClass.h>
DECL(BuildingClass, 0xA8EB40);

#include <BuildingTypeClass.h>
DECL(BuildingTypeClass, 0xA83C68);

#include <CCINIClass.h>
CCINIClass* CCINIClass::INI_AI			= (CCINIClass*)0x887128;
CCINIClass* CCINIClass::INI_Art			= (CCINIClass*)0x887180;
CCINIClass* CCINIClass::INI_Rules		= (CCINIClass*)0x887048;

#include <ColorScheme.h>
DECL(ColorScheme, 0xB054D0);

#include <CommandClass.h>
DECL(CommandClass, 0x87F658);

#include <ConvertClass.h>
DECL(ConvertClass, 0x89ECF8);

#include <EMPulseClass.h>
DECL(EMPulseClass, 0x8A3870);

#include <HouseClass.h>
DECL(HouseClass, 0xA80228);

#include <HouseTypeClass.h>
DECL(HouseTypeClass, 0xA83C98);

#include <InfantryClass.h>
DECL(InfantryClass, 0xA83DE8);

#include <InfantryTypeClass.h>
DECL(InfantryTypeClass, 0xA8E348);

#include <ConvertClass.h>
DECL(LightConvertClass, 0x87F698);

#include <ObjectClass.h>
DynamicVectorClass<ObjectClass*>* ObjectClass::CurrentObjects =
								(DynamicVectorClass<ObjectClass*>*)0xA8ECB8;

#include <OverlayClass.h>
DECL(OverlayClass, 0xA8EC50);

#include <OverlayTypeClass.h>
DECL(OverlayTypeClass, 0xA83D80);

#include <ParticleClass.h>
DECL(ParticleClass, 0xA83DC8);

#include <ParticleSystemClass.h>
DECL(ParticleSystemClass, 0xA80208);

#include <ParticleSystemTypeClass.h>
DECL(ParticleSystemTypeClass, 0xA83D68);

#include <ParticleTypeClass.h>
DECL(ParticleTypeClass, 0xA83D98);

#include <RadSiteClass.h>
DECL(RadSiteClass, 0xB04BD0);

#include <SideClass.h>
DECL(SideClass, 0x8B4120);

#include <SmudgeClass.h>
DECL(SmudgeClass, 0xA8B1E0);

#include <SmudgeTypeClass.h>
DECL(SmudgeTypeClass, 0xA8EC18);

#include <SuperWeaponTypeClass.h>
DECL(SuperWeaponTypeClass, 0xA8E330);

#include <TemporalClass.h>
DECL(TemporalClass, 0xB0EC60);

//Tree classes don't have their VTables done yet
/*#include <TerrainClass.h>
DECL(TerrainClass, 0xA8E988);

#include <TerrainTypeClass.h>
DECL(TerrainTypeClass, 0xA8E318);*/

#include <UnitClass.h>
DECL(UnitClass, 0x8B4108);

#include <UnitTypeClass.h>
DECL(UnitTypeClass, 0xA83CE0);

#include <VocClass.h>
DECL(VocClass, 0xB1D378);

#include <VoxClass.h>
DECL(VoxClass, 0xB1D4A0);

#include <WarheadTypeClass.h>
DECL(WarheadTypeClass, 0x8874C0);

#include <WeaponTypeClass.h>
DECL(WeaponTypeClass, 0x887568);
