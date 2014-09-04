#ifndef MOUSE_H
#define MOUSE_H

#include <SidebarClass.h>

class MouseCursor {
public:
	static const size_t CursorCount = 86;
	static MouseCursor* const First;

	int Frame;
	int Count;
	int Interval;
	int MiniFrame;
	int MiniCount;
	MouseHotSpotX HotX;
	MouseHotSpotY HotY;

	MouseCursor() :
		Frame(0),
		Count(1),
		Interval(1),
		MiniFrame(-1),
		MiniCount(0),
		HotX(MouseHotSpotX::Center),
		HotY(MouseHotSpotY::Middle)
		{ };

	MouseCursor (int _F, int _C, int _I, int _MF, int _MC, MouseHotSpotX _X, MouseHotSpotY _Y) :
		Frame(_F),
		Count(_C),
		Interval(_I),
		MiniFrame(_MF),
		MiniCount(_MC),
		HotX(_X),
		HotY(_Y)
		{ };

};

class MouseClass : public SidebarClass
{
public:
	//Static
	static MouseClass *Instance;

	void SetPointer(int Index, bool Minimap)
		{ JMP_THIS(0x5BDC80); }
};

#endif
