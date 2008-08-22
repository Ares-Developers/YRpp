#include <YRCallbacks.h>

#ifndef YRCALLBACKS_CPP
#define YRCALLBACKS_CPP

//-----------------------------------------------------------------------
//AbstractType classes
//-----------------------------------------------------------------------
CALLBACK_INIT_ABSTRACTTYPE(AircraftTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(AircraftTypeClass, ESI, 0x90, 00, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(BuildingTypeClass);
	CALLBACK_IMPL_XTHIS(BuildingTypeClass, Create, EAX);
	CALLBACK_IMPL_XTHIS(BuildingTypeClass, Delete, ECX);
	EXPORT _BuildingTypeClassCallback_Load(REGISTERS* R)
	{
		if(BuildingTypeClassCallback::Load)
		{
			BuildingTypeClass* pThis = (BuildingTypeClass*)R->get_ESI();
			IStream* pStm = (IStream*)R->get_EDI();
			BuildingTypeClassCallback::Load(pThis, pStm);
		}
		return 0;
	}
	CALLBACK_IMPL_LOADSAVE(BuildingTypeClass, Save, 0x0);
	CALLBACK_IMPL_LOADFROMINI(BuildingTypeClass, LoadFromINI, EBP, 0x368);
CALLBACK_INIT_ABSTRACTTYPE(HouseTypeClass);
	CALLBACK_IMPL_XTHIS(HouseTypeClass, Create, EAX);
	CALLBACK_IMPL_XTHIS(HouseTypeClass, Delete, ECX);
	CALLBACK_IMPL_LOADSAVE(HouseTypeClass, Load, 0x0);
	CALLBACK_IMPL_LOADSAVE(HouseTypeClass, Save, 0x0);
	EXPORT _HouseTypeClassCallback_LoadFromINI(REGISTERS* R)
	{
		if(HouseTypeClassCallback::LoadFromINI)
		{
			HouseTypeClass* pThis = (HouseTypeClass*)R->get_EBX();
			CCINIClass* pINI = ((CCINIClass**)R->get_EBP())[2];
			HouseTypeClassCallback::LoadFromINI(pThis, pINI);
		}
		return 0;
	}
	//CALLBACK_IMPL_LOADFROMINI(clsname,LoadFromINI,ini_reg,ini_stack);
CALLBACK_INIT_ABSTRACTTYPE(InfantryTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(InfantryTypeClass, ESI, 0xCC, 0x4, 0x8);
CALLBACK_INIT_ABSTRACTTYPE(ObjectTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(ObjectTypeClass, EBX, 0x1AC, 0x0, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(SideClass);
	CALLBACK_IMPL_ABSTRACTTYPE(SideClass, EBP, 0x368, 0x0, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(SuperWeaponTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(SuperWeaponTypeClass, EBP, 0x3F8, 0x0, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(TechnoTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(TechnoTypeClass, EBP, 0x37C, 0x0, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(UnitTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(UnitTypeClass, EDI, 0x150, 0x0, 0x0);
CALLBACK_INIT_ABSTRACTTYPE(WarheadTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(WarheadTypeClass, ESI, 0x14C, 0x0, 0x0);

CALLBACK_INIT_ABSTRACTTYPE(WeaponTypeClass);
	CALLBACK_IMPL_ABSTRACTTYPE(WeaponTypeClass, ESI, 0xE0, 0x0, 0x0);


//-----------------------------------------------------------------------
//CommandClass
//-----------------------------------------------------------------------
//Static Inits
void (_stdcall* CommandClassCallback::Register)()	=NULL;

//Implementations
//0x533058
EXPORT _CommandClassCallback_Register(REGISTERS* R)
{
	if(CommandClassCallback::Register)
		CommandClassCallback::Register();

	R->set_EAX((DWORD)(new DWORD(1)));	//Allocate SetUnitTabCommandClass
	return 0x533062;
}	

//-----------------------------------------------------------------------
//SuperClass
//-----------------------------------------------------------------------
//Static Inits
bool (_stdcall* SuperClassCallback::Launch)(SuperClass*,CellStruct*)=NULL;

//Implementations
EXPORT _SuperClassCallback_Launch(REGISTERS* R)
{
	if(SuperClassCallback::Launch)
	{
		SuperClass* pSuper=(SuperClass*)R->get_EBX();
		CellStruct* pMapCoords=(CellStruct*)R->get_StackVar32(0x1E8);

		if(SuperClassCallback::Launch(pSuper,pMapCoords))
			return 0x6CDE36;
	}
	return 0;
}

//-----------------------------------------------------------------------
//RulesClass
//-----------------------------------------------------------------------
//Static Inits
void (_stdcall* RulesClassCallback::Addition)(CCINIClass*) = NULL;
void (_stdcall* RulesClassCallback::Load)(CCINIClass*, IStream*) = NULL;
void (_stdcall* RulesClassCallback::Save)(CCINIClass*, IStream*) = NULL;

//Implementations
EXPORT _RulesClassCallback_Addition(REGISTERS* R)	//0x668F6A
{
	if(RulesClassCallback::Addition)
	{
		CCINIClass* pINI = (CCINIClass*)R->get_ESI();
		RulesClassCallback::Addition(pINI);
	}
	return 0;
}

EXPORT _RulesClassCallback_Load(REGISTERS* R)	//0x678841
{
	if(RulesClassCallback::Load)
	{
		CCINIClass* pINI = (CCINIClass*)R->get_ESI();
		IStream* pStm = (IStream*)R->get_StackVar32(0x4);
		RulesClassCallback::Load(pINI, pStm);
	}
	return 0;
}

EXPORT _RulesClassCallback_Save(REGISTERS* R)	//0x675205
{
	if(RulesClassCallback::Save)
	{
		CCINIClass* pINI = (CCINIClass*)R->get_ESI();
		IStream* pStm = (IStream*)R->get_StackVar32(0x4);
		RulesClassCallback::Save(pINI, pStm);
	}
	return 0;
}

//-----------------------------------------------------------------------
//YR General Callbacks
//-----------------------------------------------------------------------
//Static Inits
void (_stdcall* YRCallback::CmdLineParse)(char**,int)=NULL;
void (_stdcall* YRCallback::ExeRun)()=NULL;
void (_stdcall* YRCallback::ExeTerminate)()=NULL;
void (_stdcall* YRCallback::FreeMemory)()=NULL;
eMouseEventFlags (_stdcall* YRCallback::MouseEvent)(Point2D*,eMouseEventFlags)=NULL;
void (_stdcall* YRCallback::PostGameInit)()=NULL;
void (_stdcall* YRCallback::PostRenderAll)()=NULL;

//Implementations
CALLBACK_IMPL_XX(YR,ExeRun);		//0x7CD810
CALLBACK_IMPL_XX(YR,ExeTerminate);	//0x7CD8EF
CALLBACK_IMPL_XX(YR,FreeMemory);	//0x72AD0E
CALLBACK_IMPL_XX(YR,PostGameInit);	//0x52CAE9
CALLBACK_IMPL_XX(YR,PostRenderAll);	//0x4F4583

EXPORT _YRCallback_MouseEvent(REGISTERS* R)	//0x4AAC17
{
	BYTE event_flags=R->get_AL();
	if(YRCallback::MouseEvent)
	{
		void* p_wwmouse;MEM_READ32(p_wwmouse,0x887640);
		THISCALL_EX(p_wwmouse,0x7BA340);VAR32_REG(int,mx,eax);
		THISCALL_EX(p_wwmouse,0x7BA350);VAR32_REG(int,my,eax);
		Point2D p2d={mx,my};
		event_flags=YRCallback::MouseEvent(&p2d,event_flags);
	}
	R->set_AL(event_flags);
	return 0;
}

EXPORT _YRCallback_CmdLineParse(REGISTERS* R)	//0x52F639
{
	if(YRCallback::CmdLineParse)
	{
		char** ppArgs=(char**)R->get_ESI();
		int nNumArgs=(int)R->get_EDI();

		YRCallback::CmdLineParse(ppArgs,nNumArgs);
	}
	return 0;
}

#endif
