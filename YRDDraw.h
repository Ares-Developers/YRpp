#ifndef DIRECTDRAWDEF_H
#define DIRECTDRAWDEF_H

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

class DirectDrawWrap {
public:
	static HRESULT WINAPI DDCreate(GUID *lpGUID, void **lplpDD, IUnknown *pUnkOuter)
		{ JMP_STD(0x7C89D4); }

	static void* &lpDD;

	static byte &DoSmth;
};

#endif
