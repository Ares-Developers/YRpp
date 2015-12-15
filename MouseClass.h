#pragma once

#include <SidebarClass.h>

class MouseCursor {
public:
	static const size_t CursorCount = 86;
	static MouseCursor* const First;

	static MouseCursor& GetCursor(MouseCursorType cursor) {
		return First[static_cast<int>(cursor)];
	}

	MouseCursor() = default;

	MouseCursor(
		int frame, int count, int interval, int miniFrame, int miniCount,
		MouseHotSpotX hotX, MouseHotSpotY hotY)
		: Frame(frame), Count(count), Interval(interval), MiniFrame(miniFrame),
		MiniCount(miniCount), HotX(hotX), HotY(hotY)
	{ }

	int Frame{ 0 };
	int Count{ 1 };
	int Interval{ 1 };
	int MiniFrame{ -1 };
	int MiniCount{ 0 };
	MouseHotSpotX HotX{ MouseHotSpotX::Center };
	MouseHotSpotY HotY{ MouseHotSpotY::Middle };
};

struct TabDataClass
{
	int TargetValue;
	int LastValue;
	bool NeedsRedraw;
	bool ValueIncreased;
	bool ValueChanged;
	PROTECTED_PROPERTY(BYTE, align_B);
	int ValueDelta;
};

class TabClass : public SidebarClass, public INoticeSink
{
public:
	TabDataClass TabData;
	TimerStruct unknown_timer_552C;
	TimerStruct InsufficientFundsBlinkTimer;
	BYTE unknown_byte_5544;
	bool MissionTimerPinged;
	BYTE unknown_byte_5546;
	PROTECTED_PROPERTY(BYTE, padding_5547);
};

class ScrollClass : public TabClass
{
public:
	DWORD unknown_int_5548;
	BYTE unknown_byte_554C;
	PROTECTED_PROPERTY(BYTE, align_554D[3]);
	DWORD unknown_int_5550;
	DWORD unknown_int_5554;
	BYTE unknown_byte_5548;
	BYTE unknown_byte_5549;
	BYTE unknown_byte_554A;
	PROTECTED_PROPERTY(BYTE, padding_554B);
};

class NOVTABLE MouseClass : public ScrollClass
{
public:
	//Static
	static MouseClass * const Instance;

	//Destructor
	virtual ~MouseClass() RX;

	//GScreenClass
	virtual bool SetCursor(MouseCursorType idxCursor, bool miniMap) override R0;
	virtual bool UpdateCursor(MouseCursorType idxCursor, bool miniMap) override R0;
	virtual bool RestoreCursor() override R0;
	virtual void UpdateCursorMinimapState(bool miniMap) override RX;

	//DisplayClass
	virtual MouseCursorType GetLastMouseCursor() override RT(MouseCursorType);

	bool MouseCursorIsMini;
	PROTECTED_PROPERTY(BYTE, unknown_byte_5559[3]);
	MouseCursorType MouseCursorIndex;
	MouseCursorType MouseCursorLastIndex;
	int MouseCursorCurrentFrame;
};
