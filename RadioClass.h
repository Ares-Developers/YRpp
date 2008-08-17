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
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x65AB80, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x65AC40, HRESULT); }

	//Destructor
	virtual ~RadioClass()		{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x65AEB0);}

	//AbstractClass
	virtual void				PointerExpired(void* p,bool bUnknown)
								{PUSH_VAR8(bUnknown);PUSH_VAR32(p);THISCALL(0x65AAC0);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x65AB10);}

	//ObjectClass
	virtual bool vt_entry_D4()
		{THISCALL_RET(0x65AA80, bool); }
	virtual void				vt_entry_194(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3)
								{PUSH_VAR32(dwUnk3);PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);THISCALL(0x65A820);}

	//RadioClass
	virtual int vt_entry_274(DWORD dwUnk)
		{PUSH_VAR32(dwUnk);THISCALL_RET(0x65ACB0, int); }
	virtual int vt_entry_278(DWORD dwUnk,DWORD dwUnk2)
		{PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);THISCALL_RET(0x65AAA0, int); }
	virtual int vt_entry_27C(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3)
		{PUSH_VAR32(dwUnk3);PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);THISCALL_RET(0x65A970, int); }
	virtual void				vt_entry_280(DWORD dwUnk){PUSH_VAR32(dwUnk);THISCALL(0x65ACE0);}

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
	PROPERTY_STRUCT(VectorClass<TechnoClass*>,	unknown_techno_array_E0);	//Docked units etc
};

#endif
