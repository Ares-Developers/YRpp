// --- WORK IN PROGRESS ---
// --- WORK IN PROGRESS ---
// --- WORK IN PROGRESS --- i need some sleep now

/*
	DirectDraw Surface classes
	Note: dwColor is always given as a 16bit color value (high word should be zero)
*/

#pragma once

#include <GeneralStructures.h>
#include <YRDDraw.h>
#include <YRAllocator.h>

class ConvertClass;
struct SHPStruct;

class Surface	//abstract
{
public:
	//Destructor
	//Constructor
//	Surface(int Width, int Height, bool BackBuffer, bool Force3D) {/* ??? */}

	virtual ~Surface()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x4115D0); }

	//Surface
	virtual bool BlitWhole(Surface* pSrc,bool bUnk1,bool bUnk2) = 0;

	virtual bool BlitPart(
		RectangleStruct* pClipRect, //ignored and retrieved again...
		Surface* pSrc,
		RectangleStruct* pSrcRect,	//desired source rect of pSrc ?
		bool bUnk1,
		bool bUnk2) = 0;

	virtual bool Blit(
		RectangleStruct* pClipRect,
		RectangleStruct* pClipRect2,	//again? hmm
		Surface* pSrc,
		RectangleStruct* pDestRect,	//desired dest rect of pSrc ? (stretched? clipped?)
		RectangleStruct* pSrcRect,	//desired source rect of pSrc ?
		bool bUnk1,
		bool bUnk2) = 0;

	virtual bool FillRectEx(
		RectangleStruct* pClipRect,
		RectangleStruct* pFillRect,
		DWORD dwColor) = 0;

	virtual bool FillRect(
		RectangleStruct* pFillRect,
		DWORD dwColor) = 0;

	virtual bool Fill(
		DWORD dwColor) = 0;

	virtual bool vt_entry_1C(
		RectangleStruct* pClipRect,
		ColorStruct Color,
		int nUnknown) = 0;

	virtual bool vt_entry_20(	//No visible results :(
		RectangleStruct ClipRect,
		RectangleStruct Rect,	//no idea what this represents
		DWORD dwColor) = 0;

	virtual bool SetPixel(
		Point2D* pPoint,
		DWORD dwColor) = 0;

	virtual DWORD GetPixel(
		Point2D* pPoint) = 0;

	virtual bool DrawLineEx(
		RectangleStruct* pClipRect,
		Point2D* pPoint1,
		Point2D* pPoint2,
		DWORD dwColor) = 0;

	virtual bool DrawLine(
		Point2D* pPoint1,
		Point2D* pPoint2,
		DWORD dwColor) = 0;

	virtual bool vt_entry_34(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) = 0;

	virtual bool vt_entry_38(	//similar to 34
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) = 0;

	virtual bool vt_entry_3C(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7,DWORD dwUnk8,
		DWORD dwUnk9,DWORD dwUnk10,DWORD dwUnk11) = 0;

	virtual bool vt_entry_40(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) = 0;

	virtual bool vt_entry_44(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) = 0;

	virtual bool vt_entry_48(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) = 0;

	virtual bool vt_entry_4C(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6) = 0;

	virtual bool vt_entry_50(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) = 0;

	virtual bool DrawRectEx(
		RectangleStruct* pClipRect,
		RectangleStruct* pDrawRect,
		DWORD dwColor) = 0;

	virtual bool DrawRect(
		RectangleStruct* pDrawRect,
		DWORD dwColor) = 0;

	virtual void* Lock(int X,int Y) = 0;

	virtual bool Unlock() = 0;

	virtual bool vt_entry_64(DWORD dwUnk1,DWORD dwUnk2) = 0;

	virtual bool vt_entry_68(DWORD dwUnk1,DWORD dwUnk2) = 0;

	virtual bool vt_entry_6C() = 0;

	virtual int GetBytesPerPixel() = 0;

	virtual int GetPitch() = 0;	//Bytes per scanline

	virtual RectangleStruct* GetRect(RectangleStruct* pRect)
	{
		pRect->X = 0;
		pRect->Y = 0;
		pRect->Width = Width;
		pRect->Height = Height;
		return pRect;
	}

	virtual int GetWidth()
		{ return Width; }

	virtual int GetHeight()
		{ return Height; }

	virtual bool vt_entry_84()
		{ return false; }

public:
	//Properties
	int Width;
	int Height;
	int LockLevel;
	int BytesPerPixel;
//	Allocator PixelData;
	void * Buffer;
	bool Allocated;
	bool VRAMmed;
	BYTE unknown_1A;
	BYTE unknown_1B;
	IDirectDrawSurface* Surf;
	DDSURFACEDESC2* SurfDesc;

	//Helper functions
public:
	void DrawSHP(SHPStruct* pSHP,int nFrame,ConvertClass* pPalette,int X,int Y)
	{
		Point2D P = {X, Y};
		DrawSHP(pSHP, nFrame, pPalette, &P);
	}
	void DrawSHP(SHPStruct* pSHP,int nFrame,ConvertClass* pPalette,Point2D* pPoint)
	{
		RectangleStruct rect={0,0,0,0};
		PUSH_PTR(rect);
		THISCALL(0x411510);

	/*
	 (void *DSurface<ecx>, ConvertClass *Palette, SHPStruct *SHP, int frameIdx,
			Point2D *pos, _DWORD arg5, _DWORD arg6, _DWORD arg7,
			_DWORD arg8, _DWORD arg9, _DWORD argA, int TintColor,
			SHPStruct *BUILDINGZ_SHA, _DWORD argD, int ZS_X, int ZS_Y)
	*/

		PUSH_IMM(0);PUSH_IMM(0);PUSH_IMM(0);PUSH_IMM(0);
		PUSH_IMM(0);PUSH_IMM(0x3E8);PUSH_IMM(0);PUSH_IMM(0);
		PUSH_IMM(0);PUSH_IMM(0);
		PUSH_PTR(rect);
		PUSH_PTR(pPoint);
		PUSH_VAR32(nFrame);
		PUSH_VAR32(pSHP);
		SET_REG32(edx, pPalette);
		THISCALL(0x4AED70);
	}

	void __fastcall DrawSHP(ConvertClass *Palette, SHPStruct *SHP, int frameIdx,
		Point2D *pos, RectangleStruct *boundingRect, BlitterFlags flags, DWORD arg7,
		signed int arg8, DWORD arg9, DWORD argA, int TintColor,
		SHPStruct *BUILDINGZ_SHA, DWORD argD, int ZS_X, int ZS_Y)

			{ JMP_STD(0x4AED70); }

	void DrawText(const wchar_t* pText, RectangleStruct *pBounds, Point2D *pLocation, DWORD dwColor, DWORD unknown5, DWORD flags)
	{
		Point2D tmp = {0, 0};

		PUSH_VAR32(flags);
		PUSH_VAR32(unknown5);		//???
		PUSH_VAR32(dwColor);
		PUSH_VAR32(pLocation);
		PUSH_VAR32(pBounds);
		PUSH_VAR32(this);
		PUSH_VAR32(pText);
		PUSH_PTR(tmp);
		CALL(0x4A60E0);

		ADD_ESP(0x20);
	}

	void DrawText(const wchar_t* pText, Point2D* pLoction, DWORD dwColor)
	{
		RectangleStruct rect = {0, 0, 0, 0};
		PUSH_PTR(rect);
		THISCALL(0x411510);

		DrawText(pText, &rect, pLoction, dwColor, 0, 0x16);
	}

	void DrawText(const wchar_t* pText,int X,int Y,DWORD dwColor)
	{
		Point2D P = {X ,Y};
		DrawText(pText, &P, dwColor);
	}
};

//WIP - Will the define these properly some other time
//actual DirectDraw surfaces
class DSurface : public Surface {
public:
	static DSurface *&Tile;
	static DSurface *&Sidebar;
	static DSurface *&Primary;
	static DSurface *&Hidden;
	static DSurface *&Alternate;
	static DSurface *&Hidden_2;
	static DSurface *&Composite;


	DSurface(int Width, int Height, bool BackBuffer, bool Force3D)
		{ JMP_THIS(0x4BA5A0); }

	virtual bool BlitWhole(Surface* pSrc,bool bUnk1,bool bUnk2) R0;

	virtual bool BlitPart(
		RectangleStruct* pClipRect, //ignored and retrieved again...
		Surface* pSrc,
		RectangleStruct* pSrcRect,	//desired source rect of pSrc ?
		bool bUnk1,
		bool bUnk2) R0;

	virtual bool Blit(
		RectangleStruct* pClipRect,
		RectangleStruct* pClipRect2,	//again? hmm
		Surface* pSrc,
		RectangleStruct* pDestRect,	//desired dest rect of pSrc ? (stretched? clipped?)
		RectangleStruct* pSrcRect,	//desired source rect of pSrc ?
		bool bUnk1,
		bool bUnk2) R0;

	virtual bool FillRectEx(
		RectangleStruct* pClipRect,
		RectangleStruct* pFillRect,
		DWORD dwColor) R0;

	virtual bool FillRect(
		RectangleStruct* pFillRect,
		DWORD dwColor) R0;

	virtual bool Fill(
		DWORD dwColor) R0;

	virtual bool vt_entry_1C(
		RectangleStruct* pClipRect,
		ColorStruct Color,
		int nUnknown) R0;

	virtual bool vt_entry_20(	//No visible results :(
		RectangleStruct ClipRect,
		RectangleStruct Rect,	//no idea what this represents
		DWORD dwColor) R0;

	virtual bool SetPixel(
		Point2D* pPoint,
		DWORD dwColor) R0;

	virtual DWORD GetPixel(
		Point2D* pPoint) R0;

	virtual bool DrawLineEx(
		RectangleStruct* pClipRect,
		Point2D* pPoint1,
		Point2D* pPoint2,
		DWORD dwColor) R0;

	virtual bool DrawLine(
		Point2D* pPoint1,
		Point2D* pPoint2,
		DWORD dwColor) R0;

	virtual bool vt_entry_34(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) R0;

	virtual bool vt_entry_38(	//similar to 34
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) R0;

	virtual bool vt_entry_3C(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7,DWORD dwUnk8,
		DWORD dwUnk9,DWORD dwUnk10,DWORD dwUnk11) R0;

	virtual bool vt_entry_40(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6,DWORD dwUnk7) R0;

	virtual bool vt_entry_44(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) R0;

	virtual bool vt_entry_48(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) R0;

	virtual bool vt_entry_4C(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,
		DWORD dwUnk5,DWORD dwUnk6) R0;

	virtual bool vt_entry_50(
		DWORD dwUnk1,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4) R0;

	virtual bool DrawRectEx(
		RectangleStruct* pClipRect,
		RectangleStruct* pDrawRect,
		DWORD dwColor) R0;

	virtual bool DrawRect(
		RectangleStruct* pDrawRect,
		DWORD dwColor) R0;

	virtual void* Lock(int X,int Y) R0;

	virtual bool Unlock() R0;

	virtual bool vt_entry_64(DWORD dwUnk1,DWORD dwUnk2) R0;

	virtual bool vt_entry_68(DWORD dwUnk1,DWORD dwUnk2) R0;

	virtual bool vt_entry_6C() R0;

	virtual int GetBytesPerPixel() R0;

	virtual int GetPitch() R0;

};

class XSurface : public Surface {};		//WW's custom surfaces? (abstract)
class BSurface : public XSurface {};	//WW's custom surfaces? (abstract)
