#pragma once

#include <YRPPCore.h>
#include <Interfaces.h>

class NOVTABLE GScreenClass : public IGameMap
{
public:
	//Static
	static GScreenClass* Global()
		{ return reinterpret_cast<GScreenClass*>(0x87F7E8); }

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IGameMap

	//Destructor
	virtual ~GScreenClass() RX;

	//GScreenClass
	virtual void One_Time() RX;
	virtual void vt_entry_18() RX;
	virtual void Init_Clear() RX;
	virtual void vt_entry_20() RX;
	virtual void GetInputAndUpdate(DWORD* outKeyCode, int* outMouseX, int* outMouseY) RX;
	virtual void Update(const int& keyCode, const Point2D& mouseCoords) RX;
	virtual bool vt_entry_2C(DWORD dwUnk) R0;
	virtual bool vt_entry_30(DWORD dwUnk) R0;
	virtual bool vt_entry_34(DWORD dwUnk) R0;
	virtual void MarkNeedsRedraw(int dwUnk) RX;
	virtual void DrawOnTop() RX;
	virtual void Draw(DWORD dwUnk) RX;
	virtual void vt_entry_44() RX;
	virtual bool SetCursor(MouseCursorType idxCursor, bool miniMap) = 0;
	virtual bool UpdateCursor(MouseCursorType idxCursor, bool miniMap) = 0;
	virtual bool RestoreCursor() = 0;
	virtual void UpdateCursorMinimapState(bool miniMap) = 0;

protected:
	//Constuctor
	GScreenClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	int ScreenShakeX;
	int ScreenShakeY;
	int unknown_int_0C;	//default is 2
};
