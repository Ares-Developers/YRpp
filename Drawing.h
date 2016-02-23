/*
	Drawing related static class.
	This provides access to the game's Surfaces, color value conversion
	and text aligning helpers.
*/

#pragma once

#include <ColorScheme.h>
#include <GeneralDefinitions.h>
#include <Helpers/CompileTime.h>
#include <Surface.h>

class Drawing
{
public:
	static constexpr reference<ColorStruct, 0xB0FA1Cu> const TooltipColor{};

	//TextBox dimensions for tooltip-style boxes
	static RectangleStruct* __fastcall GetTextDimensions(
		RectangleStruct* pOutBuffer, wchar_t const* pText, Point2D location,
		WORD flags, int marginX = 0, int marginY = 0)
			{ JMP_STD(0x4A59E0); }

	static RectangleStruct __fastcall GetTextDimensions(
		wchar_t const* pText, Point2D location, WORD flags, int marginX = 0,
		int marginY = 0)
	{
		RectangleStruct buffer;
		GetTextDimensions(&buffer, pText, location, flags, marginX, marginY);
		return buffer;
	}

	// Rectangles
	static RectangleStruct* __fastcall Intersect(
		RectangleStruct* pOutBuffer, RectangleStruct const& rect1,
		RectangleStruct const& rect2, int* delta_left = nullptr,
		int* delta_top = nullptr)
			{ JMP_STD(0x421B60); }

	static RectangleStruct __fastcall Intersect(
		RectangleStruct const& rect1, RectangleStruct const& rect2,
		int* delta_left = nullptr, int* delta_top = nullptr)
	{
		RectangleStruct buffer;
		Intersect(&buffer, rect1, rect2, delta_left, delta_top);
		return buffer;
	}

	//Stuff

	/** Message is a vswprintf format specifier, ... is for any arguments needed */
	static Point2D * __cdecl PrintUnicode(Point2D *Position1, wchar_t *Message, Surface *a3, RectangleStruct *Rect, Point2D *Position2,
			ColorScheme *a6, int a7, int a8, ...)
		{ JMP_STD(0x4A61C0); };
};

//A few preset 16bit colors.
#define		COLOR_BLACK  0x0000
#define		COLOR_WHITE  0xFFFF

#define		COLOR_RED    0xF800
#define		COLOR_GREEN  0x07E0
#define		COLOR_BLUE   0x001F

#define		COLOR_PURPLE (COLOR_RED | COLOR_BLUE)

class ABufferClass {
public:
	static constexpr reference<ABufferClass*, 0x87E8A4u> const ABuffer{};

	ABufferClass(RectangleStruct rect)
		{ JMP_THIS(0x410CE0); }

	RectangleStruct Bounds;
	int field_10;
	BSurface* Surface;
	WORD* BufferStart;
	WORD* BufferEnd;
	int BufferSizeInBytes;
	int field_24;
	int Width;
	int Height;
};

class ZBufferClass {
public:
	static constexpr reference<ZBufferClass*, 0x887644u> const ZBuffer{};

	ZBufferClass(RectangleStruct rect)
		{ JMP_THIS(0x7BC970); }

	RectangleStruct Bounds;
	int field_10;
	BSurface* Surface;
	WORD* BufferStart;
	WORD* BufferEnd;
	int BufferSizeInBytes;
	int field_24;
	int Width;
	int Height;
};
