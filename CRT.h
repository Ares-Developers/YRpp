#ifndef CRT_H_
#define CRT_H_

#include <wchar.h>
#include <xcompile.h>

// contains functions that are part of the C runtime library and have been declared ingame
// just declaring them so we don't need to include our own duplicates

class CRT {
public:
		// unicode manipulations - "wcs" stands for "wide char string" or wchar_t equivalent of "str"

		static wchar_t * __cdecl wcscpy(wchar_t * Dest, const wchar_t *Src)
			{ JMP_STD(0x7CA489); }

		static wchar_t * __cdecl wcsncpy(wchar_t *Dest, const wchar_t *Source, size_t Count)
			{ JMP_STD(0x7CA422); }

		static wchar_t *__cdecl wcsrchr(const wchar_t *Str, wchar_t Ch)
			{ JMP_STD(0x7CA3C5); }

		static size_t __cdecl wcslen(const wchar_t *Str)
			{ JMP_STD(0x7CA405); }

		static wchar_t *__cdecl wcscat(wchar_t *Dest, const wchar_t *Source)
			{ JMP_STD(0x7CA45F); }

		static int __cdecl wcscmp(const wchar_t *Str1, const wchar_t *Str2)
			{ JMP_STD(0x7CA5D3); }

		static int __cdecl swprintf(wchar_t *Buffer, const wchar_t *Format, ...)
			{ JMP_STD(0x7CA564); }

};

#endif
