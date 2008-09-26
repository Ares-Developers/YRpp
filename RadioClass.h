/*
	Base class for WHAT?? I DUNNO =(
*/

#ifndef RADIO_H
#define RADIO_H

#include <MissionClass.h>

//forward declarations
class TechnoClass;

class RadioClass : public MissionClass
{
public:
	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x65AB80); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x65AC40); }

	//Destructor
	virtual ~RadioClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x65AEB0); }

	//AbstractClass
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x65AAC0); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x65AB10); }

	//ObjectClass
	virtual bool Exit()
		{ THISCALL(0x65AA80); }
	virtual void ReceiveCommand(TechnoClass *From, eRadioCommands rcDoThis, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(From); PUSH_VAR32(rcDoThis); THISCALL(0x65A820); }

	//RadioClass

	// these are oogly, westwood themselves admitted it, so it's probably even more of a wtf than the rest

	virtual eRadioCommands SendToFirstLink(eRadioCommands rcDoThis)
		{ PUSH_VAR32(rcDoThis); THISCALL(0x65ACB0); }
	virtual eRadioCommands SendCommand(eRadioCommands rcDoThis, TechnoClass *Link)
		{ PUSH_VAR32(Link); PUSH_VAR32(rcDoThis); THISCALL(0x65AAA0); }
	virtual int LinkWith(eRadioCommands rcDoThis, TechnoClass *Target, TechnoClass *Link)
		{ PUSH_VAR32(Link); PUSH_VAR32(Target); PUSH_VAR32(rcDoThis); THISCALL(0x65A970); }
	virtual void SendToEachLink(eRadioCommands rcDoThis)
		{ PUSH_VAR32(rcDoThis); THISCALL(0x65ACE0); }

	TechnoClass* GetNthLink(int idx)
		{ return this->RadioLinks.GetItem(idx); }

	//Constructor
	RadioClass():MissionClass(false){THISCALL(0x65A750);}

protected:
	RadioClass(bool X):MissionClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,						unknown_D4);
	PROPERTY(DWORD,						unknown_D8);
	PROPERTY(DWORD,						unknown_DC);
	PROPERTY_STRUCT(VectorClass<TechnoClass*>,	RadioLinks);	//Docked units etc
};

#endif
