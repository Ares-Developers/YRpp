#ifndef MOUSE_H
#define MOUSE_H

#include <SidebarClass.h>

class MouseCursor {
public:
	static MouseCursor* First;

	int Frame;
	int Count;
	int Interval;
	int MiniFrame;
	int MiniCount;
	eMouseHotSpotX HotX;
	eMouseHotSpotY HotY;

	MouseCursor() :
		Frame(0),
		Count(1),
		Interval(1),
		MiniFrame(-1),
		MiniCount(0),
		HotX(hotspx_center),
		HotY(hotspy_middle)
		{ };

	MouseCursor (int _F, int _C, int _I, int _MF, int _MC, eMouseHotSpotX _X, eMouseHotSpotY _Y) :
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

	void SetPointer(int Index, bool Minimap) {
		JMP_THIS(0x5BDC80);
	}
};

#endif
