#ifdef __GNUC__ 

#define stdcall __attribute__((stdcall))
#define _stdcall stdcall
#define __stdcall stdcall
#define cdecl __attribute__((cdecl))
#define _cdecl cdecl
#define __cdecl cdecl
#define fastcall __attribute__((fastcall))
#define _fastcall fastcall
#define __fastcall fastcall

#include <cstddef>

#endif
