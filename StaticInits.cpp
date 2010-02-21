//This file initializes static constant values.

#include <YRPP.h>

//include <VTables.h>

#define DECL(cls, adr) \
	DynamicVectorClass<cls*>* cls::Array = \
		(DynamicVectorClass<cls*>*)adr;

#define ALIAS(Type, Obj, Addr) \
	Type &Obj = *(Type *)(Addr);

#define ALIAS_O(Type, Obj, Addr) \
	Type Obj = (Type )(Addr);

#include <AbstractTypeClass.h>
DECL(AbstractTypeClass, 0xA8E968);

#include <AITriggerTypeClass.h>
DECL(AITriggerTypeClass, 0xA8B200);

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

#include <Audio.h>
ALIAS(AudioIDXData *, AudioIDXData::IDX, 0x87E294);

#include <BulletClass.h>
DECL(BulletClass, 0xA8ED40);

#include <BulletTypeClass.h>
DECL(BulletTypeClass, 0xA83C80);

#include <BuildingClass.h>
DECL(BuildingClass, 0xA8EB40);
ALIAS(CellStruct, BuildingClass::DefaultCellCoords, 0x89C818);

#include <BuildingTypeClass.h>
DECL(BuildingTypeClass, 0xA83C68);
ALIAS(int, BuildingTypeClass::HeightInLeptons, 0x89DDB8);

#include <BuildingLightClass.h>
DECL(BuildingLightClass, 0x8B4190);

#include <CCINIClass.h>
ALIAS(CCINIClass*, CCINIClass::INI_Rules, 0x887048);

ALIAS_O(CCINIClass*, CCINIClass::INI_AI, 0x887128);
ALIAS_O(CCINIClass*, CCINIClass::INI_Art, 0x887180);
ALIAS_O(CCINIClass*, CCINIClass::INI_RA2MD, 0x8870C0);

#include <ColorScheme.h>
DECL(ColorScheme, 0xB054D0);

#include <CommandClass.h>
DECL(CommandClass, 0x87F658);

#include <ConvertClass.h>
DECL(ConvertClass, 0x89ECF8);
DECL(LightConvertClass, 0x87F698);

#include <Drawing.h>
ALIAS(ABufferClass *, ABufferClass::ABuffer, 0x87E8A4);
ALIAS(ZBufferClass *, ZBufferClass::ZBuffer, 0x887644);

#include <YRDDraw.h>
ALIAS(void *, DirectDrawWrap::lpDD, 0x8A0094);
ALIAS(byte, DirectDrawWrap::DoSmth, 0x8A0DEF);

#include <Surface.h>
ALIAS(DSurface *, DSurface::Tile, 0x8872FC);
ALIAS(DSurface *, DSurface::Sidebar, 0x887300);
ALIAS(DSurface *, DSurface::Primary, 0x887308);
ALIAS(DSurface *, DSurface::Hidden, 0x88730C);
ALIAS(DSurface *, DSurface::Alternate, 0x887310);
ALIAS(DSurface *, DSurface::Hidden_2, 0x887314);
ALIAS(DSurface *, DSurface::Composite, 0x88731C);

#include <LoadProgressManager.h>
ALIAS(LoadProgressManager *, LoadProgressManager::LPMgr, 0xABC9BC);

#include <EMPulseClass.h>
DECL(EMPulseClass, 0x8A3870);

#include <FactoryClass.h>
DECL(FactoryClass, 0xA83E30);

#include <FileSystem.h>
ALIAS(SHPStruct *, FileSystem::PIPS_SHP, 0xAC147C);
ALIAS(ConvertClass *, FileSystem::CAMEO_PAL, 0x87F6B0);
ALIAS(ConvertClass *, FileSystem::UNITx_PAL, 0x87F6B4);
ALIAS(ConvertClass *, FileSystem::x_PAL, 0x87F6B8);
ALIAS(ConvertClass *, FileSystem::GRFTXT_TIBERIUM_PAL, 0x87F6BC);
ALIAS(ConvertClass *, FileSystem::ANIM_PAL, 0x87F6C0);
ALIAS(ConvertClass *, FileSystem::THEATER_PAL, 0x87F6C4);
ALIAS(ConvertClass *, FileSystem::MOUSE_PAL, 0x87F6C8);

#include <GameModeOptionsClass.h>
ALIAS_O(GameModeOptionsClass *, GameModeOptionsClass::Instance, 0xA8B250);

#include <HouseClass.h>
DECL(HouseClass, 0xA80228);
ALIAS(HouseClass *, HouseClass::Player, 0xA83D4C);

#include <HouseTypeClass.h>
DECL(HouseTypeClass, 0xA83C98);

#include <InfantryClass.h>
DECL(InfantryClass, 0xA83DE8);

#include <IonBlastClass.h>
DECL(IonBlastClass, 0xAA0118);

#include <InfantryTypeClass.h>
DECL(InfantryTypeClass, 0xA8E348);

#include <MixFileClass.h>
List<MixFileClass*>* MixFileClass::MIXes = (List<MixFileClass*>* )0xABEFD8;
DECL(MixFileClass, 0x884D90);
DynamicVectorClass<MixFileClass*>* MixFileClass::Array_Alt = (DynamicVectorClass<MixFileClass*>*)0x884DC0;
DynamicVectorClass<MixFileClass*>* MixFileClass::Maps = (DynamicVectorClass<MixFileClass*>*)0x884DA8;
DynamicVectorClass<MixFileClass*>* MixFileClass::Movies = (DynamicVectorClass<MixFileClass*>*)0x884DE0;

MixFileClass* MixFileClass::MULTIMD = (MixFileClass*)0x884DD8;
MixFileClass* MixFileClass::MULTI   = (MixFileClass*)0x884DDC;

MixFileClass::GenericMixFiles* MixFileClass::Generics = (MixFileClass::GenericMixFiles*)0x884DF8;

#include <MapClass.h>
ALIAS_O(MapClass *, MapClass::Instance, 0x87F7E8);

#include <MouseClass.h>
ALIAS_O(MouseClass *, MouseClass::Instance, 0x87F7E8);
MouseCursor* MouseCursor::First = (MouseCursor*)0x82D028;

#include <NetworkEvents.h>
ALIAS(int, Networking::LastEventIndex, 0xA802C8);
ALIAS(int, Networking::NextPacketIndex, 0xA802D0);
ALIAS_O(NetworkEvent *, Networking::QueuedEvents, 0xA802D4);
ALIAS_O(int *, Networking::QueuedEventTimestamps, 0xA83A54);


#include <ObjectClass.h>
DynamicVectorClass<ObjectClass*>* ObjectClass::CurrentObjects =
	(DynamicVectorClass<ObjectClass*>*)0xA8ECB8;

#include <OverlayClass.h>
DECL(OverlayClass, 0xA8EC50);

#include <OverlayTypeClass.h>
DECL(OverlayTypeClass, 0xA83D80);

#include <ParasiteClass.h>
DECL(ParasiteClass, 0xAC4910);

#include <ParticleClass.h>
DECL(ParticleClass, 0xA83DC8);

#include <ParticleSystemClass.h>
DECL(ParticleSystemClass, 0xA80208);

#include <ParticleSystemTypeClass.h>
DECL(ParticleSystemTypeClass, 0xA83D68);

#include <ParticleTypeClass.h>
DECL(ParticleTypeClass, 0xA83D98);

#include <RadBeam.h>
DECL(RadBeam, 0xB04A60);

#include <RadSiteClass.h>
DECL(RadSiteClass, 0xB04BD0);

#include <RulesClass.h>
ALIAS(RulesClass*, RulesClass::Instance, 0x8871E0);
//bool RulesClass::Initialized = false;

#include <ScenarioClass.h>
ALIAS(ScenarioClass*, ScenarioClass::Instance, 0xA8B230);

#include <SideClass.h>
DECL(SideClass, 0x8B4120);

#include <SmudgeClass.h>
DECL(SmudgeClass, 0xA8B1E0);

#include <SmudgeTypeClass.h>
DECL(SmudgeTypeClass, 0xA8EC18);

#include <SpotlightClass.h>
DECL(SpotlightClass, 0xAC1678);

#include <StringTable.h>
ALIAS(CSFString *, StringTable::LastLoadedString, 0xB1CF88);

#include <SuperWeaponTypeClass.h>
DECL(SuperWeaponTypeClass, 0xA8E330);

#include <TaskForceClass.h>
DECL(TaskForceClass, 0xA8E8D0);

#include <ScriptTypeClass.h>
DECL(ScriptTypeClass, 0x8B41C8);

#include <SwizzleManagerClass.h>
SwizzleManagerClass& SwizzleManagerClass::Instance = *(SwizzleManagerClass*)0xB0C110;

#include <TeamClass.h>
DECL(TeamClass, 0x8B40E8);

#include <TeamTypeClass.h>
DECL(TeamTypeClass, 0xA8ECA0);

#include <TemporalClass.h>
DECL(TemporalClass, 0xB0EC60);

#include <TechnoClass.h>

DynamicVectorClass<DWORD>* TechnoClass::Array = (DynamicVectorClass<DWORD>*)0xA8EC78;
DynamicVectorClass<DWORD>* TechnoTypeClass::Array = (DynamicVectorClass<DWORD>*)0xA8EB00;

#include <Theater.h>
Theater* Theater::TH_Temperate = (Theater *)0x7E1B78;
Theater* Theater::TH_Snow      = (Theater *)0x7E1BE8;
Theater* Theater::TH_Urban     = (Theater *)0x7E1C58;
Theater* Theater::TH_Desert    = (Theater *)0x7E1CC8;
Theater* Theater::TH_NewUrban  = (Theater *)0x7E1D38;
Theater* Theater::TH_Lunar     = (Theater *)0x7E1DA8;

//Tree classes don't have their VTables done yet
/*#include <TerrainClass.h>
DECL(TerrainClass, 0xA8E988);
*/

#include <TerrainTypeClass.h>
DECL(TerrainTypeClass, 0xA8E318);

#include <UnitClass.h>
DECL(UnitClass, 0x8B4108);

#include <UnitTypeClass.h>
DECL(UnitTypeClass, 0xA83CE0);

#include <Unsorted.h>
ALIAS(DWORD, Game::Savegame_Magic, 0x83D560);
ALIAS(int, Game::CurrentFrameRate, 0xABCD44);
ALIAS(HWND, Game::hWnd, 0xB73550);
ALIAS(HINSTANCE, Game::hInstance, 0xB732F0);

ALIAS(bool, Game::bVideoBackBuffer, 0x840A6C);
ALIAS(bool, Game::bAllowVRAMSidebar, 0xA8EB96);

ALIAS(IID, IIDs::AbstractClass_0, 0x7F7C90);
ALIAS(IID, IIDs::AbstractClass_1, 0x7F7C80);
ALIAS(IID, IIDs::AbstractClass_2, 0x7F7C70);
ALIAS(IID, IIDs::AbstractClass_3, 0x7E9AE0);

ALIAS(Imports::FP_OleLoadFromStream, Imports::OleLoadFromStream, 0x7E15F8);
ALIAS(Imports::FP_TimeGetTime, Imports::TimeGetTime, 0x7E1530);

DynamicVectorClass<MovieInfo> *MovieInfo::Array = (DynamicVectorClass<MovieInfo>*)0xABF390;

MovieUnlockableInfo* MovieUnlockableInfo::AlliedUnlockables = (MovieUnlockableInfo *)0x00832C30;
MovieUnlockableInfo* MovieUnlockableInfo::SovietUnlockables = (MovieUnlockableInfo *)0x00832CA0;

#include <VocClass.h>
DECL(VocClass, 0xB1D378);

#include <EBolt.h>
DECL(EBolt, 0x8A0E88);

#include <LineTrail.h>
DECL(LineTrail, 0xABCB78);

#include <VoxClass.h>
DECL(VoxClass, 0xB1D4A0);

#include <WarheadTypeClass.h>
DECL(WarheadTypeClass, 0x8874C0);

#include <WaveClass.h>
DECL(WaveClass, 0xA8EC38);

#include <WeaponTypeClass.h>
DECL(WeaponTypeClass, 0x887568);

#include <WWMouseClass.h>
ALIAS(WWMouseClass *, WWMouseClass::Instance, 0x887640);

#undef ALIAS
#undef DECL
