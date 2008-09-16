#ifndef MOUSE_H
#define MOUSE_H

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

class MouseClass : public GScreenClass
{

};

#endif
