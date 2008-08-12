#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <YRPP.h>
#include <YRCallbackMacros.h>

/*
	General Callback Hook Guide
	===========================
	Create - On RETN of CTOR	(-> this = EAX)
	Delete - At start of DTOR	(-> this = ECX)
	Load - On RETN of Load	(-> this = arg_0)
	Save - On RETN of Save	(-> this = arg_0)

	LoadFromINI - Positive end of LoadFromINI	(-> this = ???

	PreUpdate - At start of Update	(-> this = ECX)
	PostUpdate - At end of Update (-> this = ???)
*/

//-----------------------------------------------------------------------
//AbstractType classes
//-----------------------------------------------------------------------
class AircraftTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(AircraftTypeClass); };
class BuildingTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(BuildingTypeClass); };
class HouseTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(HouseTypeClass); };
class InfantryTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(InfantryTypeClass); };
class ObjectTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(ObjectTypeClass); };
class SideClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(SideClass); };
class SuperWeaponTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(SuperWeaponTypeClass); };
class TechnoTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(TechnoTypeClass); };
class UnitTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(UnitTypeClass); };
class WarheadTypeClassCallback
	{ public: CALLBACK_HEAD_ABSTRACTTYPE(WarheadTypeClass); };

//-----------------------------------------------------------------------
//CommandClass
//-----------------------------------------------------------------------
class CommandClassCallback
{
public:
	static void (_stdcall* Register)();	//Called when the CommandClasses get registered.
};

//-----------------------------------------------------------------------
//RulesClass
//-----------------------------------------------------------------------
class RulesClassCallback
{
public:
	//Called after a rules INI file was loaded.
	static void (_stdcall* Addition)(CCINIClass*);
	static void (_stdcall* Load)(CCINIClass *, IStream *);
	static void (_stdcall* Save)(CCINIClass *, IStream *);
};

//-----------------------------------------------------------------------
//SuperClass
//-----------------------------------------------------------------------
class SuperClassCallback
{
public:
	//Called when a Super is about to launch.
	//Return true if you handled the launch, return false to use default launching.
	static bool (_stdcall* Launch)(SuperClass*,CellStruct*);
};

//-----------------------------------------------------------------------
//YR General Callbacks
//-----------------------------------------------------------------------
class YRCallback
{
public:
	static void (_stdcall* PostRenderAll)();	//Called after everything has been drawn.
	
	static void (_stdcall* ExeRun)();			//Called when the executable was just started.
	static void (_stdcall* ExeTerminate)();		//Called when the executable gets terminated.

	//Called on any mouse event on the map.
	//See MOUSE_ definitions in GeneralDefinitions.h for flags.
	//Return eMouseEventFlags.
	static eMouseEventFlags (_stdcall* MouseEvent)(Point2D*,eMouseEventFlags);

	static void (_stdcall* CmdLineParse)(char**,int);	//Called when the command line arguments get parsed.

	static void (_stdcall* PostGameInit)();		//Called after the game has been initialized.
	static void (_stdcall* FreeMemory)();		//Called at the end of the game, when allocated objects are deleted.
};

#endif
