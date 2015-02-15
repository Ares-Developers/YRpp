/*
	Drawing related static class.
	This provides access to the game's Surfaces, color value conversion
	and text aligning helpers.
*/

#pragma once

#include <GeneralDefinitions.h>
#include "ColorScheme.h"
#include <Surface.h>

class Drawing
{
public:

	static RectangleStruct &SurfaceDimensions_Hidden;

	static ColorStruct &TooltipColor;

	//TextBox dimensions for tooltip-style boxes
	static RectangleStruct GetTextBox(const wchar_t* pText, int nX, int nY, DWORD flags, int nMarginX, int nMarginY)
		{
			RectangleStruct box;
			RectangleStruct* p_box=&box;

			PUSH_VAR32(nMarginY);		//X Margin
			PUSH_VAR32(nMarginX);		//Y Margin - should add 2, because X margin adds to 2 internally!
			PUSH_VAR32(flags);
			PUSH_VAR32(nY);
			PUSH_VAR32(nX);
			SET_REG32(edx,pText);
			SET_REG32(ecx,p_box);
			CALL(0x4A59E0);

			return box;
		}

	static RectangleStruct GetTextBox(const wchar_t* pText, int nX, int nY, int nMargin)
		{ return GetTextBox(pText, nX, nY, 0, nMargin + 2, nMargin); }

	static RectangleStruct GetTextBox(const wchar_t* pText, int nX, int nY)
		{ return GetTextBox(pText, nX, nY, 2); }

	static RectangleStruct GetTextBox(const wchar_t* pText, Point2D* pPoint)
		{ return GetTextBox(pText, pPoint->X, pPoint->Y, 2); }

	static RectangleStruct GetTextBox(const wchar_t* pText, Point2D* pPoint, int nMargin)
		{ return GetTextBox(pText, pPoint->X, pPoint->Y, nMargin); }

	//TextDimensions for text aligning
	static RectangleStruct GetTextDimensions(const wchar_t* pText)
		{
			RectangleStruct dim=GetTextBox(pText,0,0,0);

			dim.X=0;
			dim.Y=0;
			dim.Width-=4;
			dim.Height-=2;

			return dim;
		}

	// Rectangles
	static RectangleStruct Intersect(RectangleStruct* rect1, RectangleStruct* rect2, int* delta_left, int* delta_top)
	{
			RectangleStruct box;
			RectangleStruct* p_box=&box;

			PUSH_VAR32(delta_top);
			PUSH_VAR32(delta_left);
			PUSH_VAR32(rect2);
			SET_REG32(edx,rect1);
			SET_REG32(ecx,p_box);
			CALL(0x421B60);

			return box;
	}

	//Stuff

	// Converts an RGB color to a 16bit color value.
	static WORD Color16bit(const ColorStruct& color) {
		return static_cast<WORD>((color.B >> 3) | ((color.G >> 2) << 5) | ((color.R >> 3) << 11));
	}

	// Converts a 16bit color to an RGB color.
	static ColorStruct WordColor(WORD bits) {
		ColorStruct color;
		color.R = static_cast<BYTE>(((bits & 0xF800) >> 11) << 3);
		color.G = static_cast<BYTE>(((bits & 0x07E0) >> 5) << 2);
		color.B = static_cast<BYTE>((bits & 0x001F) << 3);
		return color;
	}

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
	static ABufferClass* &ABuffer;

	ABufferClass(RectangleStruct rect)
		{ JMP_THIS(0x410CE0); }

	RectangleStruct rect;
	int field_10;
	BSurface *Surface;
	byte* BufferStart;
	byte* BufferEndpoint;
	int BufferSize;
	int field_24;
	int W;
	int H;
};

class ZBufferClass {
public:
	static ZBufferClass* &ZBuffer;

	ZBufferClass(RectangleStruct rect)
		{ JMP_THIS(0x7BC970); }

	RectangleStruct rect;
	int field_10;
	BSurface *Surface;
	byte* BufferStart;
	byte* BufferEndpoint;
	int BufferSize;
	int field_24;
	int W;
	int H;
};
