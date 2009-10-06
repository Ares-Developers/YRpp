#ifndef MOUSE_H
#define MOUSE_H

#include <SidebarClass.h>

class MouseCursor
{
public:
	static MouseCursor* First;

	int Frame;
	int Count;
	int Interval;
	int MiniFrame;
	int MiniCount;
	eMouseHotSpotX HotX;
	eMouseHotSpotY HotY;
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
