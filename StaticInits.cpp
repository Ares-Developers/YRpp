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
ALIAS(AudioStream *, AudioStream::Instance, 0xB1D4D8);
ALIAS(DWORD *, AudioController::Audio_IDX_Container, 0x87E294);

#include <BombListClass.h>
ALIAS_O(BombListClass *, BombListClass::Instance, 0x87F5D8);

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

#include <CaptureManagerClass.h>
DECL(CaptureManagerClass, 0x89E0F0);

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
ALIAS(RectangleStruct, Drawing::SurfaceDimensions_Hidden, 0x886FA0);
ALIAS(ColorStruct, Drawing::TooltipColor, 0xB0FA1C);

#include <YRDDraw.h>
ALIAS(DirectDrawWrap *, DirectDrawWrap::lpDD, 0x8A0094);
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

#include <IsometricTileTypeClass.h>
DECL(IsometricTileTypeClass, 0xA8ED28);

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

#include <PCX.h>
ALIAS_O(PCX *, PCX::Instance, 0xAC4848);

#include <RadBeam.h>
DECL(RadBeam, 0xB04A60);

#include <RadSiteClass.h>
DECL(RadSiteClass, 0xB04BD0);

#include <RulesClass.h>
ALIAS(RulesClass*, RulesClass::Instance, 0x8871E0);
//bool RulesClass::Initialized = false;

#include <ScenarioClass.h>
ALIAS(ScenarioClass*, ScenarioClass::Instance, 0xA8B230);

#include <SessionClass.h>
ALIAS_O(SessionClass*, SessionClass::Instance, 0xA8B238);

#include <SideClass.h>
DECL(SideClass, 0x8B4120);

#include <SmudgeClass.h>
DECL(SmudgeClass, 0xA8B1E0);

#include <SmudgeTypeClass.h>
DECL(SmudgeTypeClass, 0xA8EC18);

#include <SpawnManagerClass.h>
DECL(SpawnManagerClass, 0xB0B880);

#include <SlaveManagerClass.h>
DECL(SlaveManagerClass, 0xB0B5F0);

#include <SpotlightClass.h>
DECL(SpotlightClass, 0xAC1678);

#include <StringTable.h>
ALIAS(CSFString *, StringTable::LastLoadedString, 0xB1CF88);

#include <SuperWeaponTypeClass.h>
DECL(SuperWeaponTypeClass, 0xA8E330);

#include <TacticalClass.h>
ALIAS(TacticalClass *, TacticalClass::Instance, 0x887324);

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

DynamicVectorClass<TechnoClass *>* TechnoClass::Array = (DynamicVectorClass<TechnoClass *>*)0xA8EC78;
DynamicVectorClass<TechnoTypeClass *>* TechnoTypeClass::Array = (DynamicVectorClass<TechnoTypeClass *>*)0xA8EB00;

#include <Theater.h>
Theater* Theater::Array        = (Theater *)0x7E1B78;
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

ALIAS(Imports::FP_DefWindowProcA, Imports::DefWindowProcA, 0x7E1394);
ALIAS(Imports::FP_MoveWindow, Imports::MoveWindow, 0x7E1398);
ALIAS(Imports::FP_GetUpdateRect, Imports::GetUpdateRect, 0x7E139C);
ALIAS(Imports::FP_GetFocus, Imports::GetFocus, 0x7E13A0);
ALIAS(Imports::FP_GetDC, Imports::GetDC, 0x7E13A4);
ALIAS(Imports::FP_GetKeyState, Imports::GetKeyState, 0x7E13A8);
ALIAS(Imports::FP_GetActiveWindow, Imports::GetActiveWindow, 0x7E13AC);
ALIAS(Imports::FP_GetCapture, Imports::GetCapture, 0x7E13B0);
ALIAS(Imports::FP_GetDlgCtrlID, Imports::GetDlgCtrlID, 0x7E13B4);
ALIAS(Imports::FP_ChildWindowFromPointEx, Imports::ChildWindowFromPointEx, 0x7E13B8);
ALIAS(Imports::FP_GetWindowRect, Imports::GetWindowRect, 0x7E13BC);
ALIAS(Imports::FP_GetCursorPos, Imports::GetCursorPos, 0x7E13C0);
ALIAS(Imports::FP_CloseWindow, Imports::CloseWindow, 0x7E13C4);
ALIAS(Imports::FP_EndDialog, Imports::EndDialog, 0x7E13C8);
ALIAS(Imports::FP_SetFocus, Imports::SetFocus, 0x7E13CC);
ALIAS(Imports::FP_SetDlgItemTextA, Imports::SetDlgItemTextA, 0x7E13D0);
ALIAS(Imports::FP_DialogBoxParamA, Imports::DialogBoxParamA, 0x7E13D4);
#ifdef _MSVC
ALIAS(Imports::FP_DialogBoxIndirectParamA, Imports::DialogBoxIndirectParamA, 0x7E13D8);
#endif
ALIAS(Imports::FP_ShowCursor, Imports::ShowCursor, 0x7E13DC);
ALIAS(Imports::FP_GetAsyncKeyState, Imports::GetAsyncKeyState, 0x7E13E0);
ALIAS(Imports::FP_ToAscii, Imports::ToAscii, 0x7E13E4);
ALIAS(Imports::FP_MapVirtualKeyA, Imports::MapVirtualKeyA, 0x7E13E8);
ALIAS(Imports::FP_GetSystemMetrics, Imports::GetSystemMetrics, 0x7E13EC);
ALIAS(Imports::FP_SetWindowPos, Imports::SetWindowPos, 0x7E13F0);
ALIAS(Imports::FP_DestroyWindow, Imports::DestroyWindow, 0x7E13F4);
ALIAS(Imports::FP_ReleaseCapture, Imports::ReleaseCapture, 0x7E13F8);
ALIAS(Imports::FP_SetCapture, Imports::SetCapture, 0x7E13FC);
ALIAS(Imports::FP_AdjustWindowRectEx, Imports::AdjustWindowRectEx, 0x7E1400);
ALIAS(Imports::FP_GetMenu, Imports::GetMenu, 0x7E1404);
ALIAS(Imports::FP_AdjustWindowRect, Imports::AdjustWindowRect, 0x7E1408);
ALIAS(Imports::FP_GetSysColor, Imports::GetSysColor, 0x7E140C);
ALIAS(Imports::FP_IsDlgButtonChecked, Imports::IsDlgButtonChecked, 0x7E1410);
ALIAS(Imports::FP_CheckDlgButton, Imports::CheckDlgButton, 0x7E1414);
ALIAS(Imports::FP_WaitForInputIdle, Imports::WaitForInputIdle, 0x7E1418);
ALIAS(Imports::FP_GetTopWindow, Imports::GetTopWindow, 0x7E141C);
ALIAS(Imports::FP_GetForegroundWindow, Imports::GetForegroundWindow, 0x7E1420);
ALIAS(Imports::FP_LoadIconA, Imports::LoadIconA, 0x7E1424);
ALIAS(Imports::FP_SetActiveWindow, Imports::SetActiveWindow, 0x7E1428);
ALIAS(Imports::FP_RedrawWindow, Imports::RedrawWindow, 0x7E142C);
ALIAS(Imports::FP_GetWindowContextHelpId, Imports::GetWindowContextHelpId, 0x7E1430);
ALIAS(Imports::FP_WinHelpA, Imports::WinHelpA, 0x7E1434);
ALIAS(Imports::FP_ChildWindowFromPoint, Imports::ChildWindowFromPoint, 0x7E1438);
ALIAS(Imports::FP_LoadCursorA, Imports::LoadCursorA, 0x7E143C);
ALIAS(Imports::FP_SetCursor, Imports::SetCursor, 0x7E1440);
ALIAS(Imports::FP_PostQuitMessage, Imports::PostQuitMessage, 0x7E1444);
ALIAS(Imports::FP_FindWindowA, Imports::FindWindowA, 0x7E1448);
ALIAS(Imports::FP_SetCursorPos, Imports::SetCursorPos, 0x7E144C);
#ifdef _MSVC
ALIAS(Imports::FP_CreateDialogIndirectParamA, Imports::CreateDialogIndirectParamA, 0x7E1450);
#endif
ALIAS(Imports::FP_GetKeyNameTextA, Imports::GetKeyNameTextA, 0x7E1454);
ALIAS(Imports::FP_ScreenToClient, Imports::ScreenToClient, 0x7E1458);
ALIAS(Imports::FP_LockWindowUpdate, Imports::LockWindowUpdate, 0x7E145C);
ALIAS(Imports::FP_MessageBoxA, Imports::MessageBoxA, 0x7E1460);
ALIAS(Imports::FP_ReleaseDC, Imports::ReleaseDC, 0x7E1464);
ALIAS(Imports::FP_WindowFromPoint, Imports::WindowFromPoint, 0x7E1468);
ALIAS(Imports::FP_UpdateWindow, Imports::UpdateWindow, 0x7E146C);
ALIAS(Imports::FP_SetWindowLongA, Imports::SetWindowLongA, 0x7E1470);
ALIAS(Imports::FP_GetWindowLongA, Imports::GetWindowLongA, 0x7E1474);
ALIAS(Imports::FP_ValidateRect, Imports::ValidateRect, 0x7E1478);
ALIAS(Imports::FP_IntersectRect, Imports::IntersectRect, 0x7E147C);
ALIAS(Imports::FP_MessageBoxIndirectA, Imports::MessageBoxIndirectA, 0x7E1480);
ALIAS(Imports::FP_PeekMessageA, Imports::PeekMessageA, 0x7E1484);
ALIAS(Imports::FP_CallWindowProcA, Imports::CallWindowProcA, 0x7E1488);
ALIAS(Imports::FP_KillTimer, Imports::KillTimer, 0x7E148C);
ALIAS(Imports::FP_SendDlgItemMessageA, Imports::SendDlgItemMessageA, 0x7E1490);
ALIAS(Imports::FP_SetTimer, Imports::SetTimer, 0x7E1494);
ALIAS(Imports::FP_ShowWindow, Imports::ShowWindow, 0x7E1498);
ALIAS(Imports::FP_InvalidateRect, Imports::InvalidateRect, 0x7E149C);
ALIAS(Imports::FP_EnableWindow, Imports::EnableWindow, 0x7E14A0);
ALIAS(Imports::FP_SendMessageA, Imports::SendMessageA, 0x7E14A4);
ALIAS(Imports::FP_GetDlgItem, Imports::GetDlgItem, 0x7E14A8);
ALIAS(Imports::FP_PostMessageA, Imports::PostMessageA, 0x7E14AC);
ALIAS(Imports::FP_wsprintfA, Imports::wsprintfA, 0x7E14B0);
ALIAS(Imports::FP_SetRect, Imports::SetRect, 0x7E14B4);
ALIAS(Imports::FP_ClientToScreen, Imports::ClientToScreen, 0x7E14B8);
ALIAS(Imports::FP_TranslateMessage, Imports::TranslateMessage, 0x7E14BC);
ALIAS(Imports::FP_DispatchMessageA, Imports::DispatchMessageA, 0x7E14C0);
ALIAS(Imports::FP_GetClientRect, Imports::GetClientRect, 0x7E14C4);
ALIAS(Imports::FP_GetWindow, Imports::GetWindow, 0x7E14C8);
ALIAS(Imports::FP_BringWindowToTop, Imports::BringWindowToTop, 0x7E14CC);
ALIAS(Imports::FP_SetForegroundWindow, Imports::SetForegroundWindow, 0x7E14D0);
ALIAS(Imports::FP_CreateWindowExA, Imports::CreateWindowExA, 0x7E14D4);
ALIAS(Imports::FP_RegisterClassA, Imports::RegisterClassA, 0x7E14D8);
ALIAS(Imports::FP_GetClassNameA, Imports::GetClassNameA, 0x7E14DC);
ALIAS(Imports::FP_IsWindowVisible, Imports::IsWindowVisible, 0x7E14E0);
ALIAS(Imports::FP_EnumChildWindows, Imports::EnumChildWindows, 0x7E14E4);
ALIAS(Imports::FP_IsWindowEnabled, Imports::IsWindowEnabled, 0x7E14E8);
ALIAS(Imports::FP_GetParent, Imports::GetParent, 0x7E14EC);
ALIAS(Imports::FP_GetNextDlgTabItem, Imports::GetNextDlgTabItem, 0x7E14F0);
ALIAS(Imports::FP_IsDialogMessageA, Imports::IsDialogMessageA, 0x7E14F4);
ALIAS(Imports::FP_TranslateAcceleratorA, Imports::TranslateAcceleratorA, 0x7E14F8);
ALIAS(Imports::FP_CharToOemBuffA, Imports::CharToOemBuffA, 0x7E14FC);
ALIAS(Imports::FP_BeginPaint, Imports::BeginPaint, 0x7E1500);
ALIAS(Imports::FP_EndPaint, Imports::EndPaint, 0x7E1504);
ALIAS(Imports::FP_CreateDialogParamA, Imports::CreateDialogParamA, 0x7E1508);
ALIAS(Imports::FP_GetWindowTextA, Imports::GetWindowTextA, 0x7E150C);
ALIAS(Imports::FP_RegisterHotKey, Imports::RegisterHotKey, 0x7E1510);

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

void SlaveManagerClass::ZeroOutSlaves() {
	for(int i = this->SlaveNodes.Count - 1; i >= 0; --i) {
		SlaveManagerClass::SlaveControl *SlaveNode = this->SlaveNodes[i];
		if(InfantryClass *Slave = SlaveNode->Slave) {
			Slave->SlaveOwner = NULL;
		}
		SlaveNode->Slave = NULL;
		SlaveNode->State = SlaveManagerClass::SlaveControl::state_Dead;
		SlaveNode->RespawnTimer.Start(this->RegenRate);
	}
}
