/*
	StringTable related stuff
*/

#pragma once

#include <GeneralDefinitions.h>

#define CSF_SIGNATURE 0x43534620 //" FSC"
#define CSF_LABEL_SIGNATURE 0x4C424C20 //" LBL"
#define CSF_VALUE_SIGNATURE 0x53545220 //" RTS"
#define CSF_EXVALUE_SIGNATURE 0x53545257 //"WRTS"

enum class CSFLanguages : unsigned int {
	US = 0,
	UK = 1,
	German = 2,
	French = 3,
	Spanish = 4,
	Italian = 5,
	Japanese = 6,
	Jabberwockie = 7,
	Korean = 8,
	Chinese = 9,
	Unknown = 10
};

struct CSFHeader
{
	DWORD Signature; //should be CSF_SIGNATURE
	int CSFVersion; //RA2 uses 3
	int NumLabels;
	int NumValues;
	DWORD unused_0xC;
	CSFLanguages Language; //CSF_LANG_*, forced to US if CSFVersion < 2
};

struct CSFLabel
{
	char Name[0x20]; //limits the label name length to 31
	int NumValues; //one label can have multiple values attached, that's never used though
	int FirstValueIndex; //in the global StringTable::Values() array
};

struct CSFString
{
	CSFString *PreviousEntry;
	wchar_t Text[102];

	CSFString() : PreviousEntry(nullptr) {
		*Text = 0;
	}
};

struct CSFLanguage
{
	CSFLanguages Index; // one of the language constants
	char* Name; // the display name
	char* Short; // two letter language code
	char* Letter; // one letter language code
};

class StringTable
{
public:
	static CSFString * &LastLoadedString;
	static int &MaxLabelLen;
	static int &LabelCount;
	static int &ValueCount;
	static CSFLanguages &Language;
	static bool &IsLoaded;
	static char* &FileName;
	static CSFLabel* &Labels;
	static wchar_t** &Values;
	static char** &ExtraValues;

	static const wchar_t* __fastcall LoadString(
		const char* pLabel,
		char* pOutExtraData = nullptr,
		int nSourceCodeFileLine = 0,
		const char* pSourceCodeFileName = "YR++")
			{ JMP_STD(0x734E60); }

	static bool __fastcall LoadFile(const char* pFileName)
		{ JMP_STD(0x7346A0); }
	static bool __fastcall ReadFile(const char* pFileName)
		{ JMP_STD(0x734990); }

	static CSFLanguage* __fastcall GetLanguage(CSFLanguages language)
		{ JMP_STD(0x734640); }
	static const char* __fastcall GetLanguageName(CSFLanguages language)
		{ JMP_STD(0x734670); }

	static void Unload()
		{ JMP_STD(0x734D30); }
};
