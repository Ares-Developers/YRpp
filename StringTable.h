/*
	StringTable related stuff
*/

#ifndef STRINGTABLE_H
#define STRINGTABLE_H

#include <GeneralDefinitions.h>

class StringTable
{
public:
	static const wchar_t* __fastcall LoadString(
		const char* pLabel,
		wchar_t* pOutExtraData = NULL, //is this Unicode or not? :S
		int nSourceCodeFileLine = 0,
		const char* pSourceCodeFileName = "YR++")
			JMP_STD(0x734E60);

	/*
	static const wchar_t* LoadString(const char* pLabel)
	{
		const char* pSourceFile = "YR++";
		PUSH_VAR32(pSourceFile);
		PUSH_IMM(0);
		ZERO_REG(edx);
		SET_REG32(ecx, pLabel);
		CALL(0x734E60);
	}*/
};

#endif
