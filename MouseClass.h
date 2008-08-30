#ifndef MOUSE_H
#define MOUSE_H

struct MousePointer
{
	int Frame;
	int Count;
	int Interval;
	int MiniFrame;
	int MiniCount;
	eMouseHotSpotX HotX;
	eMouseHotSpotY HotY;
};

#endif
