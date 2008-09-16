#ifndef GSCREEN_H
#define GSCREEN_H

#include <YRPPCore.h>

class GScreenClass : public IGameMap
{
public:
	//Static
	static GScreenClass* Global()
		{ return (GScreenClass*)0x87F7E8; }

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid,void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL(0x4F4240); }

	virtual ULONG _stdcall AddRef()
		{ return 1; }

	virtual ULONG _stdcall Release()
		{ return 1; }

	//IGameMap

	//Destructor
	virtual ~GScreenClass() { }

	//GScreenClass
	virtual void One_Time()
		{ *((DWORD*)0xA8EF54) = 0; }	//DisplayClass::TacticalClass* Radar_TacticalMap

	virtual void vt_entry_18()
		{ Init_Clear(); vt_entry_20(); }

	virtual void Init_Clear()
		{ unknown_int_0C = 2; }

	virtual void vt_entry_20()
		{ *((DWORD*)0xA8EF54) = 0; }	//DisplayClass::TacticalClass* Radar_TacticalMap

	virtual void vt_entry_24(int* out_Unknown, int* out_MouseX, int* out_MouseY)
		{
			PUSH_VAR32(out_MouseY);
			PUSH_VAR32(out_MouseX);
			PUSH_VAR32(out_Unknown);
			THISCALL(0x4F4320);
		}

	virtual void Update(DWORD dwUnk1, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL(0x4F4BB0); }

	virtual bool vt_entry_2C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4F43F0); }

	virtual bool vt_entry_30(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4F4410); }

	virtual bool vt_entry_34(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4F4450); }

	virtual void vt_entry_38(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x4F42F0); }

	virtual void DrawOnTop()
		{ THISCALL(0x4F4480); }

	virtual void Draw(DWORD dwUnk) { }

	virtual void vt_entry_44()
		{ THISCALL(0x4F45B0); }

	virtual void QueryCursor(int CursorIndex, DWORD dwUnk) = 0;
	virtual void SetCursor(int CursorIndex, DWORD dwUnk) = 0;
	virtual void vt_entry_50() = 0;
	virtual void vt_entry_54() = 0;

protected:
	//Constuctor
	GScreenClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,		unknown_04);
	PROPERTY(DWORD,		unknown_08);
	PROPERTY(int,		unknown_int_0C);	//default is 2


};

#endif
