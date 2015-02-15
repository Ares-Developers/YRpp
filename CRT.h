#pragma once

#include <wchar.h>

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


		// memory management
		static void *__cdecl malloc(size_t sz)
			{ JMP_STD(0x7C9430); }

		static void __cdecl free(const void* p)
			{ JMP_STD(0x7C93E8); }

		static void *__cdecl _new(size_t sz)
			{ JMP_STD(0x7C8E17); }

		static void __cdecl _delete(void *p)
			{ JMP_STD(0x7C8B3D); }


		// strings
		static char* __cdecl strdup(const char *Src)
			{ JMP_STD(0x7D5408); }

		static int __cdecl strcmpi(const char *lhs, const char *rhs)
			{ JMP_STD(0x7C8D20); }

		static int __cdecl strcmp(const char *lhs, const char *rhs)
			{ JMP_STD(0x7CDA90); }

		static char *__cdecl strchr(const char *Str, int Val)
			{ JMP_STD(0x7CAF30); }

		static char *__cdecl strrchr(const char *Str, int Ch)
			{ JMP_STD(0x7C8DF0); }

		static char *__cdecl strncpy(char *Dest, const char *Source, size_t Count)
			{ JMP_STD(0x7C91D0); }

		static char *__cdecl strstr(const char *Str, const char *SubStr)
			{ JMP_STD(0x7CA4B0); }

		static int __cdecl sscanf(const char *, const char *, ...)
			{ JMP_STD(0x7CA530); }

		static char *__cdecl strncat(char *Dest, const char *Source, size_t Count)
			{ JMP_STD(0x7CB550); }

		static int __cdecl sprintf(char *Buffer, const char *Format, ...)
			{ JMP_STD(0x7C8EF4); }

		static int __cdecl vsprintf(char *, const char *, va_list)
			{ JMP_STD(0x7CB7BA); }


		// misc
		static void *__cdecl memcpy(void *Dst, const void *Src, size_t Size)
			{ JMP_STD(0x7CA090); }

		static void __cdecl qsort(void *buf, size_t num, size_t size, int (__cdecl *compare)(const void *lhs, const void *rhs))
			{ JMP_STD(0x7C8B48); }

		static void *__cdecl bsearch(const void *, const void *, size_t, size_t, int (__cdecl *)(const void *, const void *))
			{ JMP_STD(0x7C8E25); }


		// files
		static FILE *__cdecl fopen(const char *, const char *)
			{ JMP_STD(0x7CA845); }

		static size_t __cdecl fread(void *, size_t, size_t, FILE *)
			{ JMP_STD(0x7C94EB); }

		static size_t __cdecl fwrite(const void *, size_t, size_t, FILE *)
			{ JMP_STD(0x7C9602); }

		static int __cdecl fprintf(FILE *, const char *, ...)
			{ JMP_STD(0x7CA7D8); }

		static int __cdecl vfprintf(FILE *File, const char *Format, va_list ArgList)
			{ JMP_STD(0x7CB302); }

		static int __cdecl fflush(FILE *)
			{ JMP_STD(0x7CB19C); }

		static int __cdecl fclose(FILE *)
			{ JMP_STD(0x7CA75B); }


};
