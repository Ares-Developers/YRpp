#ifndef __GCCFIXES_H__
#define __GCCFIXES_H__

#ifdef __GNUC__

#undef stdcall
#undef _stdcall
#undef __stdcall
#define stdcall __attribute__((stdcall))
#define _stdcall stdcall
#define __stdcall stdcall

#undef cdecl
#undef _cdecl
#undef __cdecl
#define cdecl __attribute__((cdecl))
#define _cdecl cdecl
#define __cdecl cdecl

#undef fastcall
#undef _fastcall
#undef __fastcall
#define fastcall __attribute__((fastcall))
#define _fastcall fastcall
#define __fastcall fastcall

#include <cstddef>

#endif

#endif
