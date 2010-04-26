#ifndef WWMOUSE_H
#define WWMOUSE_H

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

	virtual void Draw(CellStruct *Coords, SHPStruct *Image, int Unk)
		{ JMP_THIS(0x7B8A00); }

	virtual bool IsField0CNegative()
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

	virtual DWORD GetField0C()
		{ JMP_THIS(0x7B89F0); }

	virtual int GetX()
		{ JMP_THIS(0x7BA340); }

	virtual int GetY()
		{ JMP_THIS(0x7BA350); }

	virtual Point2D* GetCoords(Point2D *buffer)
		{ JMP_THIS(0x7BA360); }

	virtual void SetCoords(Point2D buffer)
		{ JMP_THIS(0x7BA380); }

	virtual void func_3C(DSurface *Surface, bool bUnk)
		{ JMP_THIS(0x7B90C0); }

	virtual void func_40(DSurface *Surface, bool bUnk)
		{ JMP_THIS(0x7B92D0); }

	virtual void func_44(int *arg1, int *arg2)
		{ JMP_THIS(0x7B9D90); }

	PROPERTY(SHPStruct *, Image);
	PROPERTY(int        , ImageFrameIndex);
	PROPERTY(DWORD      , field_C);
	PROPERTY(byte       , field_10);
	PROPERTY(byte       , field_11);
	PROPERTY(byte       , field_12);
	PROPERTY(byte       , field_13);
	PROPERTY(DWORD      , field_14);
	PROPERTY(DWORD      , field_18);
	PROPERTY(Point2D    , XY1);
	PROPERTY(DSurface * , Surface);
	PROPERTY(HWND       , hWnd);
	PROPERTY(RectangleStruct, Rect0);
	PROPERTY(Point2D    , XY2);
	PROPERTY(DWORD      , field_44);
	PROPERTY(RectangleStruct, Rect1);
	PROPERTY(DWORD      , field_58);
	PROPERTY(RectangleStruct, Rect2);
	PROPERTY(DWORD      , field_6C);
	PROPERTY(RectangleStruct, Rect3);
	PROPERTY(RectangleStruct, Rect4);
	PROPERTY(DWORD      , field_90);
	PROPERTY(DWORD      , field_94);

};
#endif
