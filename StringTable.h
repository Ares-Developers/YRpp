/*
	StringTable related stuff
*/

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <GeneralDefinitions.h>

#define CSF_SIGNATURE 0x43534620 //" FSC"
#define CSF_LABEL_SIGNATURE 0x4C424C20 //" LBL"
#define CSF_VALUE_SIGNATURE 0x53545220 //" RTS"
#define CSF_EXVALUE_SIGNATURE 0x53545257 //"WRTS"

#define CSF_LANG_US 0x0
#define CSF_LANG_UK 0x1
#define CSF_LANG_GERMAN 0x2
#define CSF_LANG_FRENCH 0x3
#define CSF_LANG_SPANISH 0x4
#define CSF_LANG_ITALIAN 0x5
#define CSF_LANG_JAPANESE 0x6
#define CSF_LANG_JABBERWOCKIE 0x7
#define CSF_LANG_KOREAN 0x8
#define CSF_LANG_CHINESE 0x9
#define CSF_LANG_UNKNOWN 0xA

struct CSFHeader
{
	DWORD Signature; //should be CSF_SIGNATURE
	int CSFVersion; //RA2 uses 3
	int NumLabels;
	int NumValues;
	DWORD unused_0xC;
	int Language; //CSF_LANG_*, forced to US if CSFVersion < 2
};

struct CSFLabel
{
	char Name[0x20]; //limits the label name length to 31
	int NumValues; //one label can have multiple values attached, that's never used though
	int FirstValueIndex; //in the global StringTable::Values() array
};

class StringTable
{
public:
	static int get_MaxLabelLen()
		{ return *((int*)0xB1CF58); }
	static int set_MaxLabelLen(int new_MaxLabelLen)
		{ *((int*)0xB1CF58) = new_MaxLabelLen; }

	static char* get_FileName()
		{ return *((char**)0xB1CF68); }

	static int get_LabelCount()
		{ return *((int*)0xB1CF6C); }
	static void set_LabelCount(int new_LabelCount)
		{ *((int*)0xB1CF6C) = new_LabelCount; }

	static int get_ValueCount()
		{ return *((int*)0xB1CF70); }
	static void set_ValueCount(int new_ValueCount)
		{ *((int*)0xB1CF70) = new_ValueCount; }

	static int get_Language()
		{ return *((int*)0x845728); }
	static void set_Language(int new_Language)
		{ *((int*)0x845728) = new_Language; }

	static bool is_Loaded()
		{ return *((bool*)0xB1CF80); }
	static void set_Loaded(bool new_Loaded)
		{ *((bool*)0xB1CF80) = new_Loaded; }

	static CSFLabel* get_Labels()
		{ return *((CSFLabel**)0xB1CF74); }
	static void set_Labels(CSFLabel* new_Labels) //do NOT play with this!
		{ *((CSFLabel**)0xB1CF74) = new_Labels; }

	static wchar_t** get_Values()
		{ return *((wchar_t***)0xB1CF78); }
	static void set_Values(wchar_t** new_Values) //do NOT play with this!
		{ *((wchar_t***)0xB1CF78) = new_Values; }

	static char** get_ExtraValues()
		{ return *((char***)0xB1CF7C); }
	static void set_ExtraValues(char** new_ExtraValues) //do NOT play with this!
		{ *((char***)0xB1CF7C) = new_ExtraValues; }

	static const wchar_t* __fastcall LoadString(
		const char* pLabel,
		char* pOutExtraData = NULL,
		int nSourceCodeFileLine = 0,
		const char* pSourceCodeFileName = "YR++")
			JMP_STD(0x734E60);

	static bool __fastcall LoadFile(const char* pFileName)
		JMP_STD(0x7346A0);
	static bool __fastcall ReadFile(const char* pFileName)
		JMP_STD(0x734990);
};

#endif
