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
#include <Helpers/CompileTime.h>

#include <utility>

class ConvertClass;
struct SHPStruct;

// once the meaning is known, replace
#define SURFACE_SETTING_ONE bOption1
#define SURFACE_SETTING_TWO bOption2
#define SURFACE_SETTING_THREE dwUnknown

class Surface	//abstract
{
public:
	//Destructor
	//Constructor
//	Surface(int Width, int Height, bool BackBuffer, bool Force3D) {/* ??? */}

	virtual ~Surface()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x4115D0); }

	//Surface
	virtual bool BlitWhole(
		Surface* pSrc,
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) = 0;

	virtual bool BlitPart(
		RectangleStruct const& rectDest,
		Surface* pSrc,
		RectangleStruct const& rectSrc,
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) = 0;

	virtual bool Blit(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectClip2,	//again? hmm
		Surface* pSrc,
		RectangleStruct const& rectDest,	//desired dest rect of pSrc ? (stretched? clipped?)
		RectangleStruct const& rectSrc,	//desired source rect of pSrc ?
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) = 0;

	virtual bool FillRectEx(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectFill,
		DWORD dwColor) = 0;

	virtual bool FillRect(
		RectangleStruct const& rectFill,
		DWORD dwColor) = 0;

	virtual bool Fill(
		DWORD dwColor) = 0;

	virtual bool vt_entry_1C(
		RectangleStruct const& rectClip,
		ColorStruct Color,
		int nUnknown) = 0;

	virtual bool vt_entry_20(	//No visible results :(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
		DWORD dwUnk9) = 0;

	virtual bool SetPixel(
		Point2D const& point,
		DWORD dwColor) = 0;

	virtual DWORD GetPixel(
		Point2D const& point) = 0;

	virtual bool DrawLineEx(
		RectangleStruct const& rectClip,
		Point2D const& point1,
		Point2D const& point2,
		DWORD dwColor) = 0;

	virtual bool DrawLine(
		Point2D const& point1,
		Point2D const& point2,
		DWORD dwColor) = 0;

	virtual bool vt_entry_34(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) = 0;

	virtual bool vt_entry_38(	//similar to 34
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) = 0;

	virtual bool vt_entry_3C(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
		DWORD dwUnk9, DWORD dwUnk10, DWORD dwUnk11) = 0;

	virtual bool vt_entry_40(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) = 0;

	virtual bool vt_entry_44(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) = 0;

	virtual bool vt_entry_48(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) = 0;

	virtual bool vt_entry_4C(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6) = 0;

	virtual bool vt_entry_50(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) = 0;

	virtual bool DrawRectEx(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectDraw,
		DWORD dwColor) = 0;

	virtual bool DrawRect(
		RectangleStruct const& rectDraw,
		DWORD dwColor) = 0;

	virtual void* Lock(int X, int Y) = 0;

	virtual bool Unlock() = 0;

	virtual bool vt_entry_64(DWORD dwUnk1, DWORD dwUnk2) = 0;

	virtual bool vt_entry_68(DWORD dwUnk1, DWORD dwUnk2) = 0;

	virtual bool vt_entry_6C() = 0;

	virtual int GetBytesPerPixel() const = 0;

	virtual int GetPitch() const = 0;	//Bytes per scanline

	virtual RectangleStruct* GetRect(RectangleStruct* pRect) const final
	{
		pRect->X = 0;
		pRect->Y = 0;
		pRect->Width = Width;
		pRect->Height = Height;
		return pRect;
	}

	virtual int GetWidth() const final
		{ return Width; }

	virtual int GetHeight() const final
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
	RectangleStruct GetRect() const {
		RectangleStruct buffer;
		this->GetRect(&buffer);
		return buffer;
	}

	void DrawSHP(
		ConvertClass* pPalette, SHPStruct* pSHP, int idxFrame, Point2D location)
	{
		DrawSHP(
			pPalette, pSHP, idxFrame, location, this->GetRect(),
			BlitterFlags::None, 0, 0, 0, 1000, 0, nullptr, 0, 0, 0);
	}

	void __fastcall DrawSHP(
		ConvertClass* pPalette, SHPStruct* pSHP, int idxFrame,
		Point2D const& pos, RectangleStruct const& bounds, BlitterFlags flags,
		DWORD arg7, int arg8, DWORD arg9, DWORD argA, int TintColor,
		SHPStruct* BUILDINGZ_SHA, DWORD argD, int ZS_X, int ZS_Y)
			{ JMP_STD(0x4AED70); }

	/**
	 * Text drawing
	 */
	static Point2D* __fastcall DrawText(
		Point2D* pOutBuffer, wchar_t const* pText, Surface* pSurface,
		RectangleStruct const& bounds, Point2D const& location, WORD color,
		DWORD SURFACE_SETTING_THREE, DWORD flags, DWORD unknown9)
			{ JMP_STD(0x4A5EB0); }

	static Point2D DrawText(
		wchar_t const* pText, Surface* pSurface, RectangleStruct const& bounds,
		Point2D const& location, WORD color, DWORD SURFACE_SETTING_THREE,
		DWORD flags, DWORD unknown9)
	{
		Point2D buffer;
		Surface::DrawText(
			&buffer, pText, pSurface, bounds, location, color,
			SURFACE_SETTING_THREE, flags, unknown9);
		return buffer;
	}

	static Point2D* __stdcall DrawFormattedText(
		Point2D* pOutBuffer, wchar_t const* pText, Surface* pSurface,
		RectangleStruct const& bounds, Point2D const& location, WORD color,
		DWORD SURFACE_SETTING_THREE, DWORD flags, ...)
			{ JMP_STD(0x4A60E0); }

	template <typename... Args>
	static Point2D DrawFormattedText(
		const wchar_t* pText, Surface* pSurface, RectangleStruct const& bounds,
		Point2D const& location, WORD color, DWORD SURFACE_SETTING_THREE,
		DWORD flags, Args&&... args)
	{
		Point2D buffer;
		Surface::DrawFormattedText(
			&buffer, pText, pSurface, bounds, location, color,
			SURFACE_SETTING_THREE, flags, std::forward<Args>(args)...);
		return buffer;
	}

	Point2D DrawText(
		const wchar_t* pText, RectangleStruct const& bounds,
		Point2D const& location, WORD color, DWORD SURFACE_SETTING_THREE = 0,
		DWORD flags = 0x16)
	{
		return DrawText(
			pText, this, bounds, location, color, SURFACE_SETTING_THREE,
			flags, 1);
	}

	Point2D DrawText(
		const wchar_t* pText, Point2D location, WORD dwColor,
		DWORD SURFACE_SETTING_THREE = 0, DWORD flags = 0x16)
	{
		return DrawText(
			pText, this->GetRect(), location, dwColor,
			SURFACE_SETTING_THREE, flags);
	}
};

//WIP - Will the define these properly some other time
//actual DirectDraw surfaces
class DSurface : public Surface {
public:
	static constexpr reference<DSurface*, 0x8872FCu> const Tile{};
	static constexpr reference<DSurface*, 0x887300u> const Sidebar{};
	static constexpr reference<DSurface*, 0x887308u> const Primary{};
	static constexpr reference<DSurface*, 0x88730Cu> const Hidden{};
	static constexpr reference<DSurface*, 0x887310u> const Alternate{};
	static constexpr reference<DSurface*, 0x887314u> const Hidden_2{};
	static constexpr reference<DSurface*, 0x88731Cu> const Composite{};

	static constexpr reference<RectangleStruct, 0x886F90u> const SidebarBounds{};
	static constexpr reference<RectangleStruct, 0x886FA0u> const ViewBounds{};
	static constexpr reference<RectangleStruct, 0x886FB0u> const WindowBounds{};

	DSurface(int Width, int Height, bool BackBuffer, bool Force3D)
		{ JMP_THIS(0x4BA5A0); }

	virtual bool BlitWhole(
		Surface* pSrc,
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) override R0;

	virtual bool BlitPart(
		RectangleStruct const& rectDest,
		Surface* pSrc,
		RectangleStruct const& rectSrc,
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) override R0;

	virtual bool Blit(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectClip2,	//again? hmm
		Surface* pSrc,
		RectangleStruct const& rectDest,	//desired dest rect of pSrc ? (stretched? clipped?)
		RectangleStruct const& rectSrc,	//desired source rect of pSrc ?
		bool SURFACE_SETTING_ONE,
		bool SURFACE_SETTING_TWO) override R0;

	virtual bool FillRectEx(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectFill,
		DWORD dwColor) override R0;

	virtual bool FillRect(
		RectangleStruct const& rectFill,
		DWORD dwColor) override R0;

	virtual bool Fill(
		DWORD dwColor) override R0;

	virtual bool vt_entry_1C(
		RectangleStruct const& rectClip,
		ColorStruct Color,
		int nUnknown) override R0;

	virtual bool vt_entry_20(	//No visible results :(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
		DWORD dwUnk9) override R0;

	virtual bool SetPixel(
		Point2D const& point,
		DWORD dwColor) override R0;

	virtual DWORD GetPixel(
		Point2D const& point) override R0;

	virtual bool DrawLineEx(
		RectangleStruct const& rectClip,
		Point2D const& point1,
		Point2D const& point2,
		DWORD dwColor) override R0;

	virtual bool DrawLine(
		Point2D const& point1,
		Point2D const& point2,
		DWORD dwColor) override R0;

	virtual bool vt_entry_34(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) override R0;

	virtual bool vt_entry_38(	//similar to 34
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) override R0;

	virtual bool vt_entry_3C(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8,
		DWORD dwUnk9, DWORD dwUnk10, DWORD dwUnk11) override R0;

	virtual bool vt_entry_40(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7) override R0;

	virtual bool vt_entry_44(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) override R0;

	virtual bool vt_entry_48(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) override R0;

	virtual bool vt_entry_4C(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
		DWORD dwUnk5, DWORD dwUnk6) override R0;

	virtual bool vt_entry_50(
		DWORD dwUnk1, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) override R0;

	virtual bool DrawRectEx(
		RectangleStruct const& rectClip,
		RectangleStruct const& rectDraw,
		DWORD dwColor) override R0;

	virtual bool DrawRect(
		RectangleStruct const& rectDraw,
		DWORD dwColor) override R0;

	virtual void* Lock(int X, int Y) override R0;

	virtual bool Unlock() override R0;

	virtual bool vt_entry_64(DWORD dwUnk1, DWORD dwUnk2) override R0;

	virtual bool vt_entry_68(DWORD dwUnk1, DWORD dwUnk2) override R0;

	virtual bool vt_entry_6C() override R0;

	virtual int GetBytesPerPixel() const override R0;

	virtual int GetPitch() const override R0;
};

class XSurface : public Surface {};		//WW's custom surfaces? (abstract)
class BSurface : public XSurface {};	//WW's custom surfaces? (abstract)
