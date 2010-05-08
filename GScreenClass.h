#ifndef GSCREEN_H
#define GSCREEN_H

#include <YRPPCore.h>
#include <Interfaces.h>

class GScreenClass : public IGameMap
{
public:
	//Static
	static GScreenClass* Global()
		{ return (GScreenClass*)0x87F7E8; }

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid,void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//Destructor
	virtual ~GScreenClass() RX;

	//GScreenClass
	virtual void One_Time() RX;
	virtual void vt_entry_18() RX;
	virtual void Init_Clear() RX;
	virtual void vt_entry_20() RX;
	virtual void vt_entry_24(int* out_Unknown, int* out_MouseX, int* out_MouseY) RX;
	virtual void Update(DWORD dwUnk1, DWORD dwUnk2) RX;
	virtual bool vt_entry_2C(DWORD dwUnk) R0;
	virtual bool vt_entry_30(DWORD dwUnk) R0;
	virtual bool vt_entry_34(DWORD dwUnk) R0;
	virtual void vt_entry_38(DWORD dwUnk) RX;
	virtual void DrawOnTop() RX;
	virtual void Draw(DWORD dwUnk) RX;
	virtual void vt_entry_44() RX;
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

public:

	DWORD unknown_04;
	DWORD unknown_08;
	int unknown_int_0C;	//default is 2


};

#endif
