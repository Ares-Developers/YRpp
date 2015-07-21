#pragma once

#include <GeneralDefinitions.h>
#include <GeneralStructures.h>
#include <Drawing.h>

struct SHPStruct;

class WWMouseClass
{
public:
	static WWMouseClass *&Instance;

	virtual ~WWMouseClass()
		{ JMP_THIS(0x0); }

	virtual void Draw(CellStruct const& coords, SHPStruct const* pImage, int idxFrame)
		{ JMP_THIS(0x7B8A00); }

	virtual bool IsRefCountNegative()
		{ JMP_THIS(0x7BA320); }

	virtual void HideCursor()
		{ JMP_THIS(0x7B9930); }

	virtual void ShowCursor()
		{ JMP_THIS(0x7B9750); }

	virtual void ReleaseMouse()
		{ JMP_THIS(0x7B9C30); }

	virtual void CaptureMouse()
		{ JMP_THIS(0x7B9A60); }

	virtual byte GetField10()
		{ JMP_THIS(0x7BA330); }

	virtual void func_20(RectangleStruct Useless)
		{ JMP_THIS(0x7B9D70); }

	virtual void CallFunc10()
		{ JMP_THIS(0x7B9D80); }

	virtual DWORD GetRefCount()
		{ JMP_THIS(0x7B89F0); }

	virtual int GetX()
		{ JMP_THIS(0x7BA340); }

	virtual int GetY()
		{ JMP_THIS(0x7BA350); }

	virtual Point2D* GetCoords(Point2D *buffer)
		{ JMP_THIS(0x7BA360); }

	virtual void SetCoords(Point2D buffer)
		{ JMP_THIS(0x7BA380); }

	virtual void func_3C(DSurface* pSurface, bool bUnk)
		{ JMP_THIS(0x7B90C0); }

	virtual void func_40(DSurface* pSurface, bool bUnk)
		{ JMP_THIS(0x7B92D0); }

	virtual void func_44(int *arg1, int *arg2)
		{ JMP_THIS(0x7B9D90); }

public:

	SHPStruct * Image;
	int         ImageFrameIndex;
	DWORD       RefCount;
	byte        field_10;
	byte        field_11;
	byte        field_12;
	byte        field_13;
	DWORD       field_14;
	DWORD       field_18;
	Point2D     XY1;
	DSurface *  Surface;
	HWND        hWnd;
	RectangleStruct Rect0;
	Point2D     XY2;
	DWORD       field_44;
	RectangleStruct Rect1;
	DWORD       field_58;
	RectangleStruct Rect2;
	DWORD       field_6C;
	RectangleStruct Rect3;
	RectangleStruct Rect4;
	DWORD       field_90;
	DWORD       field_94;

};
