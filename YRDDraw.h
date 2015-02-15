#pragma once

#include <YRPPCore.h>

//We don't want YR++ to depend on the DirectX7 SDK (yet), so
//here are a few definitions taken from the MSDN:

//DDPIXELFORMAT
typedef struct _DDPIXELFORMAT {
  DWORD  dwSize;
  DWORD  dwFlags;
  DWORD  dwFourCC;
union {
  DWORD  dwRGBBitCount;
  DWORD  dwYUVBitCount;
  DWORD  dwZBufferBitDepth;
  DWORD  dwAlphaBitDepth;
  DWORD  dwLuminanceBitCount;
  DWORD  dwBumpBitCount;
  DWORD  dwPrivateFormatBitCount;
} ;
union {
  DWORD  dwRBitMask;
  DWORD  dwYBitMask;
  DWORD  dwStencilBitDepth;
  DWORD  dwLuminanceBitMask;
  DWORD  dwBumpDuBitMask;
  DWORD  dwOperations;
} ;
union {
  DWORD  dwGBitMask;
  DWORD  dwUBitMask;
  DWORD  dwZBitMask;
  DWORD  dwBumpDvBitMask;
  struct {
    WORD wFlipMSTypes;
    WORD wBltMSTypes;
  } MultiSampleCaps;
} ;
union {
  DWORD  dwBBitMask;
  DWORD  dwVBitMask;
  DWORD  dwStencilBitMask;
  DWORD  dwBumpLuminanceBitMask;
} ;
union {
  DWORD  dwRGBAlphaBitMask;
  DWORD  dwYUVAlphaBitMask;
  DWORD  dwLuminanceAlphaBitMask;
  DWORD  dwRGBZBitMask;
  DWORD  dwYUVZBitMask;
} ;
} DDPIXELFORMAT, FAR* LPDDPIXELFORMAT;

//DDSCAPS2
typedef struct _DDSCAPS2 {
  DWORD  dwCaps;
  DWORD  dwCaps2;
  DWORD  dwCaps3;
  DWORD  dwCaps4;
} DDSCAPS2, FAR* LPDDSCAPS2;

//DDCOLORKEY
typedef struct _DDCOLORKEY{
  DWORD dwColorSpaceLowValue;
  DWORD dwColorSpaceHighValue;
} DDCOLORKEY,FAR *LPDDCOLORKEY;

//DDSURFACEDESC2
typedef struct _DDSURFACEDESC2 {
  DWORD  dwSize;
  DWORD  dwFlags;
  DWORD  dwHeight;
  DWORD  dwWidth;
  union {
  LONG  lPitch;
  DWORD  dwLinearSize;
  } ;
  DWORD  dwBackBufferCount;
  union {
  DWORD  dwMipMapCount;
  DWORD  dwRefreshRate;
  DWORD  dwSrcVBHandle;
  } ;
  DWORD  dwAlphaBitDepth;
  DWORD  dwReserved;
  LPVOID  lpSurface;
  union {
  DDCOLORKEY  ddckCKDestOverlay;
  DWORD  dwEmptyFaceColor;
  } ;
  DDCOLORKEY  ddckCKDestBlt;
  DDCOLORKEY  ddckCKSrcOverlay;
  DDCOLORKEY  ddckCKSrcBlt;
  union {
  DDPIXELFORMAT  ddpfPixelFormat;
  DWORD  dwFVF;
  } ;
  DDSCAPS2  ddsCaps;
  DWORD  dwTextureStage;
} DDSURFACEDESC2;

//IDirectDrawSurface
interface IDirectDrawSurface;

class eDDCoopLevel {
public:
	enum E {
	/*
	 * Exclusive mode owner will be responsible for the entire primary surface.
	 * GDI can be ignored. used with DD
	 */
	DDSCL_FULLSCREEN = 0x00000001l,

	/*
	 * allow CTRL_ALT_DEL to work while in fullscreen exclusive mode
	 */
	DDSCL_ALLOWREBOOT = 0x00000002l,

	/*
	 * prevents DDRAW from modifying the application window.
	 * prevents DDRAW from minimize/restore the application window on activation.
	 */
	DDSCL_NOWINDOWCHANGES = 0x00000004l,

	/*
	 * app wants to work as a regular Windows application
	 */
	DDSCL_NORMAL = 0x00000008l,

	/*
	 * app wants exclusive access
	 */
	DDSCL_EXCLUSIVE = 0x00000010l,


	/*
	 * app can deal with non-windows display modes
	 */
	DDSCL_ALLOWMODEX = 0x00000040l,

	/*
	 * this window will receive the focus messages
	 */
	DDSCL_SETFOCUSWINDOW = 0x00000080l,

	/*
	 * this window is associated with the DDRAW object and will
	 * cover the screen in fullscreen mode
	 */
	DDSCL_SETDEVICEWINDOW = 0x00000100l,

	/*
	 * app wants DDRAW to create a window to be associated with the
	 * DDRAW object
	 */
	DDSCL_CREATEDEVICEWINDOW = 0x00000200l,

	/*
	 * App explicitly asks DDRAW/D3D to be multithread safe. This makes D3D
	 * take the global crtisec more frequently.
	 */
	DDSCL_MULTITHREADED = 0x00000400l,

	/*
	 * App specifies that it would like to keep the FPU set up for optimal Direct3D
	 * performance (single precision and exceptions disabled) so Direct3D
	 * does not need to explicitly set the FPU each time. This is assumed by
	 * default in DirectX 7. See also DDSCL_FPUPRESERVE
	 */
	DDSCL_FPUSETUP = 0x00000800l,

	/*
	 * App specifies that it needs either double precision FPU or FPU exceptions
	 * enabled. This makes Direct3D explicitly set the FPU state eah time it is
	 * called. Setting the flag will reduce Direct3D performance. The flag is
	 * assumed by default in DirectX 6 and earlier. See also DDSCL_FPUSETUP
	 */
	DDSCL_FPUPRESERVE = 0x00001000l,
	} _;
public:
	eDDCoopLevel(int val) { this->_ = static_cast<E>(val); };
	operator int() { return this->_; };
};

class DirectDrawWrap {
public:
	static HRESULT WINAPI DDCreate(GUID *lpGUID, DirectDrawWrap **lplpDD, IUnknown *pUnkOuter)
		{ JMP_STD(0x7C89D4); }

	static void Restore()
		{ JMP_STD(0x4A44F0); }

	static void DisposeOfStuff()
		{ JMP_STD(0x6BB8E0); }

	static DirectDrawWrap* &lpDD;

	static byte &DoSmth;

	virtual HRESULT __stdcall QueryInterface(DWORD riid, LPVOID *ppvObj);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	virtual HRESULT __stdcall Compact();
	virtual HRESULT __stdcall CreateClipper(DWORD, /* _LPDIRECTDRAWCLIPPER ** */DWORD, IUnknown *);
	virtual HRESULT __stdcall CreatePalette(DWORD, /* LPPALETTEENTRY */DWORD, /* LPDIRECTDRAWPALETTE * */DWORD, IUnknown *);
	virtual HRESULT __stdcall CreateSurface(/* LPDDSURFACEDESC */DWORD, /* _LPDIRECTDRAWSURFACE * */DWORD, IUnknown *);
	virtual HRESULT __stdcall DuplicateSurface(/* LPDIRECTDRAWSURFACE */DWORD, /* _LPDIRECTDRAWSURFACE * */DWORD);
	virtual HRESULT __stdcall EnumDisplayModes(DWORD, /* LPDDSURFACEDESC */DWORD, LPVOID, /* LPDDENUMMODESCALLBACK */DWORD);
	virtual HRESULT __stdcall EnumSurfaces(DWORD, /* LPDDSURFACEDESC */DWORD, LPVOID, /* LPDDENUMSURFACESCALLBACK */DWORD);
	virtual HRESULT __stdcall FlipToGDISurface();
	virtual HRESULT __stdcall GetCaps(/* _LPDDCAPS */DWORD, /* _LPDDCAPS */DWORD);
	virtual HRESULT __stdcall GetDisplayMode(/* LPDDSURFACEDESC */DWORD);
	virtual HRESULT __stdcall GetFourCCCodes(/* LPDWORD */DWORD, /* LPDWORD */DWORD);
	virtual HRESULT __stdcall GetGDISurface(/* _LPDIRECTDRAWSURFACE * */DWORD);
	virtual HRESULT __stdcall GetMonitorFrequency(/* LPDWORD */DWORD);
	virtual HRESULT __stdcall GetScanLine(/* LPDWORD */DWORD);
	virtual HRESULT __stdcall GetVerticalBlankStatus(/* LPBOOL */DWORD);
	virtual HRESULT __stdcall Initialize(GUID *);
	virtual HRESULT __stdcall RestoreDisplayMode();
	virtual HRESULT __stdcall SetCooperativeLevel(HWND, eDDCoopLevel);
	virtual HRESULT __stdcall SetDisplayMode(DWORD Width, DWORD Height, DWORD BitDepth);
	virtual HRESULT __stdcall WaitForVerticalBlank(DWORD, HANDLE);

};

