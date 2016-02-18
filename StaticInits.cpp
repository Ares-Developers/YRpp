//This file initializes static constant values.

#include <YRPP.h>

//include <VTables.h>

#define DECL(cls, adr) \
	DynamicVectorClass<cls*>* const cls::Array = \
		reinterpret_cast<DynamicVectorClass<cls*>*>(adr);

#define ALIAS(Type, Obj, Addr) \
	Type &Obj = *reinterpret_cast<Type*>(Addr);

#define ALIAS_O(Type, Obj, Addr) \
	Type Obj = reinterpret_cast<Type>(Addr);

#include <Audio.h>
ALIAS(AudioIDXData*, AudioIDXData::Instance, 0x87E294);
ALIAS(AudioStream *, AudioStream::Instance, 0xB1D4D8);

#include <BombListClass.h>
ALIAS_O(BombListClass* const, BombListClass::Instance, 0x87F5D8);

#include <BulletClass.h>
ALIAS(DynamicVectorClass<BulletClass*>, BulletClass::ScalableBullets, 0x89DE18);

#include <BuildingTypeClass.h>
ALIAS(int, BuildingTypeClass::HeightInLeptons, 0x89DDB8);

#include <CCINIClass.h>
ALIAS(DWORD, CCINIClass::RulesHash, 0xB77E00);
ALIAS(DWORD, CCINIClass::ArtHash, 0xB77E04);
ALIAS(DWORD, CCINIClass::AIHash, 0xB77E08);

ALIAS(CCINIClass*, CCINIClass::INI_Rules, 0x887048);

ALIAS_O(CCINIClass* const, CCINIClass::INI_AI, 0x887128);
ALIAS_O(CCINIClass* const, CCINIClass::INI_Art, 0x887180);
ALIAS_O(CCINIClass* const, CCINIClass::INI_RA2MD, 0x8870C0);

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
ALIAS(RectangleStruct const, DSurface::SidebarBounds, 0x886F90);
ALIAS(RectangleStruct const, DSurface::ViewBounds, 0x886FA0);
ALIAS(RectangleStruct const, DSurface::WindowBounds, 0x886FB0);

#include <LoadProgressManager.h>
ALIAS(LoadProgressManager *, LoadProgressManager::LPMgr, 0xABC9BC);

#include <FileSystem.h>
ALIAS(SHPStruct *, FileSystem::PIPBRD_SHP, 0xAC1478);
ALIAS(SHPStruct *, FileSystem::PIPS_SHP, 0xAC147C);
ALIAS(SHPStruct *, FileSystem::PIPS2_SHP, 0xAC1480);
ALIAS(SHPStruct *, FileSystem::TALKBUBL_SHP, 0xAC1484);
ALIAS(SHPStruct *, FileSystem::WRENCH_SHP, 0x89DDC8);
ALIAS(SHPStruct *, FileSystem::POWEROFF_SHP, 0x89DDC4);
ALIAS(SHPStruct *, FileSystem::GRFXTXT_SHP, 0xA8F794);
ALIAS(BytePalette *, FileSystem::TEMPERAT_PAL, 0x885780);
ALIAS(BytePalette *, FileSystem::GRFXTXT_PAL, 0xA8F790);
ALIAS(ConvertClass *, FileSystem::CAMEO_PAL, 0x87F6B0);
ALIAS(ConvertClass *, FileSystem::UNITx_PAL, 0x87F6B4);
ALIAS(ConvertClass *, FileSystem::x_PAL, 0x87F6B8);
ALIAS(ConvertClass *, FileSystem::GRFTXT_TIBERIUM_PAL, 0x87F6BC);
ALIAS(ConvertClass *, FileSystem::ANIM_PAL, 0x87F6C0);
ALIAS(ConvertClass *, FileSystem::THEATER_PAL, 0x87F6C4);
ALIAS(ConvertClass *, FileSystem::MOUSE_PAL, 0x87F6C8);
ALIAS(ConvertClass *, FileSystem::GRFXTXT_Convert, 0xA8F798);

#include <FPSCounter.h>
ALIAS(unsigned int, FPSCounter::CurrentFrameRate, 0xABCD44);
ALIAS(unsigned int, FPSCounter::TotalFramesElapsed, 0xABCD48);
ALIAS(unsigned int, FPSCounter::TotalTimeElapsed, 0xABCD4C);
ALIAS(bool, FPSCounter::ReducedEffects, 0xABCD50);
ALIAS(unsigned int, Detail::MinFrameRate, 0x829FF4);
ALIAS(unsigned int, Detail::BufferZoneWidth, 0x829FF8);

#include <GameModeOptionsClass.h>
ALIAS_O(GameModeOptionsClass * const, GameModeOptionsClass::Instance, 0xA8B250);

#include <GameOptionsClass.h>
ALIAS_O(GameOptionsClass * const, GameOptionsClass::Instance, 0xA8EB60);

#include <GetCDClass.h>
ALIAS_O(GetCDClass* const, GetCDClass::Instance, 0xA8E8E8);

#include <HouseClass.h>
ALIAS(HouseClass *, HouseClass::Player, 0xA83D4C);
ALIAS(HouseClass *, HouseClass::Observer, 0xAC1198);

#include <InputManagerClass.h>
ALIAS(InputManagerClass *, InputManagerClass::Instance, 0x87F770);

#include <Kamikaze.h>
ALIAS_O(Kamikaze* const, Kamikaze::Instance, 0xABC5F8);

#include <LocomotionClass.h>
ALIAS(const CLSID, LocomotionClass::CLSIDs::Drive, 0x7E9A30);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Jumpjet, 0x7E9AC0);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Hover, 0x7E9A40);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Rocket, 0x7E9AD0);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Tunnel, 0x7E9A50);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Walk, 0x7E9A60);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Droppod, 0x7E9A70);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Fly, 0x7E9A80);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Teleport, 0x7E9A90);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Mech, 0x7E9AA0);
ALIAS(const CLSID, LocomotionClass::CLSIDs::Ship, 0x7E9AB0);

#include <MessageListClass.h>
ALIAS_O(MessageListClass * const, MessageListClass::Instance, 0xA8BC60);

#include <MixFileClass.h>
List<MixFileClass*>* const MixFileClass::MIXes = (List<MixFileClass*>* )0xABEFD8;
DECL(MixFileClass, 0x884D90);
DynamicVectorClass<MixFileClass*>* const MixFileClass::Array_Alt = reinterpret_cast<DynamicVectorClass<MixFileClass*>*>(0x884DC0);
DynamicVectorClass<MixFileClass*>* const MixFileClass::Maps = reinterpret_cast<DynamicVectorClass<MixFileClass*>*>(0x884DA8);
DynamicVectorClass<MixFileClass*>* const MixFileClass::Movies = reinterpret_cast<DynamicVectorClass<MixFileClass*>*>(0x884DE0);

MixFileClass* const MixFileClass::MULTIMD = reinterpret_cast<MixFileClass*>(0x884DD8);
MixFileClass* const MixFileClass::MULTI   = reinterpret_cast<MixFileClass*>(0x884DDC);

MixFileClass::GenericMixFiles* const MixFileClass::Generics = reinterpret_cast<MixFileClass::GenericMixFiles*>(0x884DF8);

#include <MapClass.h>
ALIAS_O(MapClass * const, MapClass::Instance, 0x87F7E8);

#include <DisplayClass.h>
ALIAS_O(LogicClass* const, LogicClass::Instance, 0x87F778);

#include <MouseClass.h>
ALIAS_O(MouseClass * const, MouseClass::Instance, 0x87F7E8);
MouseCursor* const MouseCursor::First = reinterpret_cast<MouseCursor*>(0x82D028);

#include <Networking.h>
ALIAS(DWORD, Networking::CurrentFrameCRC, 0xAC51FC);
ALIAS_O(DWORD * const, Networking::LatestFramesCRC, 0xB04474);
ALIAS(int, Networking::LastEventIndex, 0xA802C8);
ALIAS(int, Networking::NextPacketIndex, 0xA802D0);
ALIAS_O(NetworkEvent * const, Networking::QueuedEvents, 0xA802D4);
ALIAS_O(int * const, Networking::QueuedEventTimestamps, 0xA83A54);

#include <Notifications.h>
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidAnim, 0xB0F5B8);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidTeam, 0xB0F5D8);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidWaypoint, 0xB0F5F0);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidTag, 0xB0F618);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidFactory, 0xB0F640);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidActionOrEvent, 0xB0F658);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidType, 0xB0F670);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidHouse, 0xB0F6C8);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidNeuron, 0xB0F6F0);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidTrigger, 0xB0F708);
ALIAS(PointerExpiredNotification, PointerExpiredNotification::NotifyInvalidObject, 0xB0F720);

#include <ObjectClass.h>
DynamicVectorClass<ObjectClass*>* const ObjectClass::CurrentObjects =
	reinterpret_cast<DynamicVectorClass<ObjectClass*>*>(0xA8ECB8);

DynamicVectorClass<ObjectClass*>* const ObjectClass::Logics =
	reinterpret_cast<DynamicVectorClass<ObjectClass*>*>(0x87F778);

DynamicVectorClass<ObjectClass*>* const ObjectClass::ObjectsInLayers =
	reinterpret_cast<DynamicVectorClass<ObjectClass*>*>(0x8A0360);


#include <PCX.h>
ALIAS_O(PCX * const, PCX::Instance, 0xAC4848);
WORD PCX::DefaultTransparentColor = COLOR_PURPLE;

#include <Powerups.h>
ALIAS(int *, Powerups::Weights, 0x81DA8C);
ALIAS(double *, Powerups::Arguments, 0x89EC28);
ALIAS(bool *, Powerups::Naval, 0x89ECC0);
ALIAS(int *, Powerups::Anims, 0x81DAD8);
ALIAS(char **, Powerups::Effects, 0x7E523C);

#include <ProgressScreenClass.h>
ALIAS_O(ProgressScreenClass * const, ProgressScreenClass::Instance, 0xAC4F58);

#include <RulesClass.h>
ALIAS(RulesClass*, RulesClass::Instance, 0x8871E0);
//bool RulesClass::Initialized = false;

#include <ScenarioClass.h>
ALIAS(ScenarioClass*, ScenarioClass::Instance, 0xA8B230);

#include <SessionClass.h>
ALIAS_O(SessionClass* const, SessionClass::Instance, 0xA8B238);

#include <SidebarClass.h>
ALIAS_O(wchar_t * const, SidebarClass::TooltipBuffer, 0xB07BC4);

#include <StringTable.h>
ALIAS(CSFString *, StringTable::LastLoadedString, 0xB1CF88);
ALIAS(int, StringTable::MaxLabelLen, 0xB1CF58);
ALIAS(int, StringTable::LabelCount, 0xB1CF6C);
ALIAS(int, StringTable::ValueCount, 0xB1CF70);
ALIAS(CSFLanguages, StringTable::Language, 0x845728);
ALIAS(bool, StringTable::IsLoaded, 0xB1CF80);
ALIAS(char*, StringTable::FileName, 0xB1CF68);
ALIAS(CSFLabel*, StringTable::Labels, 0xB1CF74);
ALIAS(wchar_t**, StringTable::Values, 0xB1CF78);
ALIAS(char**, StringTable::ExtraValues, 0xB1CF7C);

#include <SuperClass.h>
ALIAS_O(DynamicVectorClass<SuperClass*>* const, SuperClass::ShowTimers, 0xA83D50);
ALIAS(double, LightningStorm::CloudHeightFactor, 0xB0CDD8);
ALIAS(CellStruct, LightningStorm::Coords, 0xA9F9CC);
ALIAS(HouseClass*, LightningStorm::Owner, 0xA9FACC);
ALIAS(int, LightningStorm::Deferment, 0xA9FAB8);
ALIAS(int, LightningStorm::Duration, 0x827FC4);
ALIAS(int, LightningStorm::StartTime, 0x827FC0);
ALIAS(bool, LightningStorm::Active, 0xA9FAB4);
ALIAS(bool, LightningStorm::TimeToEnd, 0xA9FAD0);
ALIAS_O(DynamicVectorClass<AnimClass*>* const, LightningStorm::CloudsPresent, 0xA9F9D0);
ALIAS_O(DynamicVectorClass<AnimClass*>* const, LightningStorm::CloudsManifesting, 0xA9FA60);
ALIAS_O(DynamicVectorClass<AnimClass*>* const, LightningStorm::BoltsPresent, 0xA9FA18);
ALIAS(PsychicDominatorStatus, PsyDom::Status, 0xA9FAC0);
ALIAS(CellStruct, PsyDom::Coords, 0xA9FA48);
ALIAS(HouseClass*, PsyDom::Owner, 0xA9FAC8);
ALIAS(AnimClass*, PsyDom::Anim, 0xA9FAC4);
ALIAS(int, ChronoScreenEffect::Status, 0xA9FAB0);
ALIAS(int, ChronoScreenEffect::Duration, 0xA9FA98);
ALIAS(NukeFlashStatus, NukeFlash::Status, 0xA9FABC);
ALIAS(int, NukeFlash::StartTime, 0x827FC8);
ALIAS(int, NukeFlash::Duration, 0x827FCC);

#include <TacticalClass.h>
ALIAS(TacticalClass *, TacticalClass::Instance, 0x887324);

#include <SwizzleManagerClass.h>
SwizzleManagerClass& SwizzleManagerClass::Instance = *reinterpret_cast<SwizzleManagerClass*>(0xB0C110);

#include <Theater.h>
Theater* const Theater::Array        = reinterpret_cast<Theater*>(0x7E1B78);
Theater* const Theater::TH_Temperate = reinterpret_cast<Theater*>(0x7E1B78);
Theater* const Theater::TH_Snow      = reinterpret_cast<Theater*>(0x7E1BE8);
Theater* const Theater::TH_Urban     = reinterpret_cast<Theater*>(0x7E1C58);
Theater* const Theater::TH_Desert    = reinterpret_cast<Theater*>(0x7E1CC8);
Theater* const Theater::TH_NewUrban  = reinterpret_cast<Theater*>(0x7E1D38);
Theater* const Theater::TH_Lunar     = reinterpret_cast<Theater*>(0x7E1DA8);

#include <Unsorted.h>
ALIAS(DWORD, Game::Savegame_Magic, 0x83D560);
ALIAS(int, Game::CurrentFrameRate, 0xABCD44);
ALIAS(HWND, Game::hWnd, 0xB73550);
ALIAS(HINSTANCE, Game::hInstance, 0xB732F0);

ALIAS(bool, Game::bVideoBackBuffer, 0x840A6C);
ALIAS(bool, Game::bAllowVRAMSidebar, 0xA8EB96);

ALIAS(const IID, IIDs::IUnknown, 0x7F7C90);
ALIAS(const IID, IIDs::IPersistStream, 0x7F7C80);
ALIAS(const IID, IIDs::IPersist, 0x7F7C70);
ALIAS(const IID, IIDs::IRTTITypeInfo, 0x7E9AE0);
ALIAS(const IID, IIDs::IHouse, 0x7EA768);
ALIAS(const IID, IIDs::IPublicHouse, 0x7E9B00);
ALIAS(const IID, IIDs::IEnumConnections, 0x7F7CB0);
ALIAS(const IID, IIDs::IConnectionPoint, 0x7F7CC0);
ALIAS(const IID, IIDs::IConnectionPointContainer, 0x7F7CD0);
ALIAS(const IID, IIDs::IEnumConnectionPoints, 0x7F7CE0);
ALIAS(const IID, IIDs::IApplication, 0x7E36C0);
ALIAS(const IID, IIDs::IGameMap, 0x7EA6E8);
ALIAS(const IID, IIDs::ILocomotion, 0x7ED358);
ALIAS(const IID, IIDs::IPiggyback, 0x7E9B10);
ALIAS(const IID, IIDs::IFlyControl, 0x7E9B40);
ALIAS(const IID, IIDs::ISwizzle, 0x7E9B20);

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

ALIAS_O(DynamicVectorClass<MovieInfo>* const, MovieInfo::Array, 0xABF390);

ALIAS_O(MovieUnlockableInfo const* const, MovieUnlockableInfo::CommonUnlockables, 0x00832C20);
ALIAS_O(MovieUnlockableInfo const* const, MovieUnlockableInfo::AlliedUnlockables, 0x00832C30);
ALIAS_O(MovieUnlockableInfo const* const, MovieUnlockableInfo::SovietUnlockables, 0x00832CA0);

#include <VocClass.h>
ALIAS(bool, VocClass::VoicesEnabled, 0x8464AC);

#include <VoxClass.h>
ALIAS(int, VoxClass::EVAIndex, 0xB1D4C8);

#include <WWMouseClass.h>
ALIAS(WWMouseClass *, WWMouseClass::Instance, 0x887640);

#undef ALIAS
#undef DECL

void SlaveManagerClass::ZeroOutSlaves() {
	for(const auto& pNode : this->SlaveNodes) {
		if(auto pSlave = pNode->Slave) {
			pSlave->SlaveOwner = nullptr;
		}
		pNode->Slave = nullptr;
		pNode->State = SlaveControlStatus::Dead;
		pNode->RespawnTimer.Start(this->RegenRate);
	}
}

int HouseClass::CountOwnedNow(const TechnoTypeClass* const pItem) const {
	switch(pItem->WhatAmI()) {
	case AbstractType::BuildingType:
		return this->CountOwnedNow(
			static_cast<BuildingTypeClass const*>(pItem));

	case AbstractType::UnitType:
		return this->CountOwnedNow(
			static_cast<UnitTypeClass const*>(pItem));

	case AbstractType::InfantryType:
		return this->CountOwnedNow(
			static_cast<InfantryTypeClass const*>(pItem));

	case AbstractType::AircraftType:
		return this->CountOwnedNow(
			static_cast<AircraftTypeClass const*>(pItem));

	default:
		__assume(0);
	}
}

int HouseClass::CountOwnedAndPresent(const TechnoTypeClass* const pItem) const {
	switch(pItem->WhatAmI()) {
	case AbstractType::BuildingType:
		return this->CountOwnedAndPresent(
			static_cast<BuildingTypeClass const*>(pItem));

	case AbstractType::UnitType:
		return this->CountOwnedAndPresent(
			static_cast<UnitTypeClass const*>(pItem));

	case AbstractType::InfantryType:
		return this->CountOwnedAndPresent(
			static_cast<InfantryTypeClass const*>(pItem));

	case AbstractType::AircraftType:
		return this->CountOwnedAndPresent(
			static_cast<AircraftTypeClass const*>(pItem));

	default:
		__assume(0);
	}
}

int HouseClass::CountOwnedEver(TechnoTypeClass const* const pItem) const {
	switch(pItem->WhatAmI()) {
	case AbstractType::BuildingType:
		return this->CountOwnedEver(
			static_cast<BuildingTypeClass const*>(pItem));

	case AbstractType::UnitType:
		return this->CountOwnedEver(
			static_cast<UnitTypeClass const*>(pItem));

	case AbstractType::InfantryType:
		return this->CountOwnedEver(
			static_cast<InfantryTypeClass const*>(pItem));

	case AbstractType::AircraftType:
		return this->CountOwnedEver(
			static_cast<AircraftTypeClass const*>(pItem));

	default:
		__assume(0);
	}
}

bool HouseClass::CanExpectToBuild(const TechnoTypeClass* const pItem) const {
	auto const parentOwnerMask = this->Type->FindParentCountryIndex();
	return this->CanExpectToBuild(pItem, parentOwnerMask);
}

bool HouseClass::CanExpectToBuild(const TechnoTypeClass* const pItem, int const idxParent) const {
	auto const parentOwnerMask = 1u << idxParent;
	if(pItem->InOwners(parentOwnerMask)) {
		if(this->InRequiredHouses(pItem)) {
			if(!this->InForbiddenHouses(pItem)) {
				auto const BaseSide = pItem->AIBasePlanningSide;
				if(BaseSide == -1 || BaseSide == this->Type->SideIndex) {
					return true;
				}
			}
		}
	}
	return false;
}

int HouseClass::FindSuperWeaponIndex(SuperWeaponType const type) const {
	for(int i = 0; i < this->Supers.Count; ++i) {
		if(this->Supers.Items[i]->Type->Type == type) {
			return i;
		}
	}
	return -1;
}

SuperClass* HouseClass::FindSuperWeapon(SuperWeaponType const type) const {
	auto index = this->FindSuperWeaponIndex(type);
	return this->Supers.GetItemOrDefault(index);
}

bool HouseClass::IsIonCannonEligibleTarget(const TechnoClass* const pTechno) const {
	if(pTechno->InWhichLayer() == Layer::Ground && pTechno->IsAlive && !pTechno->InLimbo) {
		return true;
	}

	// hard difficulty shoots the tank in the factory
	if(this->AIDifficulty == AIDifficulty::Hard) {
		for(const auto* pFactory : *FactoryClass::Array) {
			if(pFactory->Object == pTechno
				&& pFactory->Production.Timer.Duration
				&& !pFactory->IsSuspended)
			{
				return true;
			}
		}
	}

	return false;
}

int TechnoClass::GetIonCannonValue(AIDifficulty const difficulty) const {
	const auto& rules = *RulesClass::Instance;

	const TypeList<int>* pValues = nullptr;
	int value = 1;

	if(auto pUnit = abstract_cast<const UnitClass*>(this)) {
		auto pType = pUnit->Type;

		if(pType->Harvester) {
			pValues = &rules.AIIonCannonHarvesterValue;

		} else if(rules.BuildConst.FindItemIndex(pType->DeploysInto) != -1) {
			pValues = &rules.AIIonCannonMCVValue;

		} else if(pType->Passengers > 0) {
			pValues = &rules.AIIonCannonAPCValue;

		} else {
			value = 2;
		}

	} else if(auto pBuilding = abstract_cast<const BuildingClass*>(this)) {
		auto pType = pBuilding->Type;

		if(pType->Factory == AbstractType::BuildingType) {
			pValues = &rules.AIIonCannonConYardValue;

		} else if(pType->Factory == AbstractType::UnitType && !pType->Naval) {
			pValues = &rules.AIIonCannonWarFactoryValue;

		} else if(pType->PowerBonus > pType->PowerDrain) {
			pValues = &rules.AIIonCannonPowerValue;

		} else if(pType->IsBaseDefense) {
			pValues = &rules.AIIonCannonBaseDefenseValue;

		} else if(pType->IsPlug) {
			pValues = &rules.AIIonCannonPlugValue;

		} else if(pType->IsTemple) {
			pValues = &rules.AIIonCannonTempleValue;

		} else if(pType->HoverPad) {
			pValues = &rules.AIIonCannonHelipadValue;

		} else if(rules.BuildConst.FindItemIndex(pType) != -1) {
			pValues = &rules.AIIonCannonTechCenterValue;

		} else {
			value = 4;
		}

	} else if(auto pInfantry = abstract_cast<const InfantryClass*>(this)) {
		auto pType = pInfantry->Type;

		if(pType->Engineer) {
			pValues = &rules.AIIonCannonEngineerValue;

		} else if(pType->VehicleThief) {
			pValues = &rules.AIIonCannonThiefValue;

		} else {
			value = 2;
		}
	}

	if(pValues) {
		value = pValues->GetItemOrDefault(static_cast<int>(difficulty), value);
	}

	return value;
}

TechnoTypeClass* BuildingClass::GetSecretProduction() const {
	auto const pType = this->Type;

	if(pType->SecretInfantry) {
		return pType->SecretInfantry;
	}
	if(pType->SecretUnit) {
		return pType->SecretUnit;
	}
	if(pType->SecretBuilding) {
		return pType->SecretBuilding;
	}
	return this->SecretProduction;
}
