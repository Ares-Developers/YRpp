/*
	Use this to print a message on the screen!
*/

#ifndef MSGLIST_H
#define MSGLIST_H

#include <wchar.h>
#include <ASMMacros.h>

class MessageListClass
{
public:
	static void PrintMessage(const wchar_t* pMessage, int nColorSchemeIndex)
		{
			PUSH_IMM(0);
			PUSH_IMM(0x96);
			PUSH_IMM(0x4046);
			PUSH_VAR32(nColorSchemeIndex);
			PUSH_VAR32(pMessage);
			PUSH_IMM(0);
			PUSH_IMM(0);
			THISCALL_EX(0xA8BC60,0x5D3BA0);
		}

	static void PrintMessage(const wchar_t* pMessage)
		{ PrintMessage(pMessage, 3); }
};

#endif
