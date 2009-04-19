/*
	Drawing related static class.
	This provides access to the game's Surfaces, color value conversion
	and text aligning helpers.
*/

#ifndef DRAWING_H
#define DRAWING_H

#include <GeneralDefinitions.h>
#include <Surface.h>

class Drawing
{
public:
	//Retrieve Surfaces
	#define DECL_GET_SURFACE(name,address)\
	static DSurface* GetSurface_ ## name ()\
		{ DSurface* pSurf; MEM_READ32(pSurf,address); return pSurf; }
	
	static DSurface *&DSurface_Tile;
	static DSurface *&DSurface_Sidebar;
	static DSurface *&DSurface_Primary;
	static DSurface *&DSurface_Hidden;
	static DSurface *&DSurface_Alternate;
	static DSurface *&DSurface_Hidden_2;
	static DSurface *&DSurface_Composite;

	//TextBox dimensions for tooltip-style boxes
	static RectangleStruct GetTextBox(const wchar_t* pText, int nX, int nY, int nMargin)
		{
			RectangleStruct box;
			RectangleStruct* p_box=&box;

			int ymarg=nMargin+2;
			PUSH_IMM(nMargin);		//X Margin
			PUSH_IMM(ymarg);		//Y Margin - should add 2, because X margin adds to 2 internally!
			PUSH_IMM(0);			//X Offset
			PUSH_VAR32(nY);
			PUSH_VAR32(nX);
			SET_REG32(edx,pText);
			SET_REG32(ecx,p_box);
			CALL(0x4A59E0);

			return box;
		}

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

	//Stuff

	// RGB
	static WORD Color16bit(ColorStruct* pColor)	//Converts an RGB color to a 16bit color value.
		{ return (pColor->B >> 3) | ((pColor->G >> 2) << 5) | ((pColor->R >> 3) << 11); }

	static ColorStruct WordColor(WORD bits)
		{ ColorStruct color;
			color.R = ((bits & 0xF800) >> 11) << 3;
			color.G = (BYTE)((bits & 0x07E0) >> 5) << 2; // msvc stupid warning
			color.B = (bits & 0x001F) << 3;
		return color; }
};

//A few preset 16bit colors.
#define		COLOR_BLACK		0x0000
#define		COLOR_WHITE		0xFFFF

#define		COLOR_RED		0xF800
#define		COLOR_GREEN		0x07E0
#define		COLOR_BLUE		0x001F

class ABufferClass {

	static ABufferClass* &ABuffer;

	ABufferClass(RectangleStruct rect)
		JMP_THIS(0x410CE0);

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

	static ZBufferClass* &ZBuffer;

	ZBufferClass(RectangleStruct rect)
		JMP_THIS(0x7BC970);

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

#endif
