/*
	Use this to print a message on the screen!
*/

#ifndef MSGLIST_H
#define MSGLIST_H

#include <wchar.h>
#include <ASMMacros.h>
#include <ColorScheme.h>

class MessageListClass
{
public:
	static MessageListClass * Instance;

	// if pLabel is given, the message will be {$pLabel}:{$pMessage}
	// else it will be just {$pMessage}

	void PrintMessage(const wchar_t * pLabel, DWORD dwUnk1, const wchar_t* pMessage, int nColorSchemeIndex = 3,
		DWORD dwUnk2 = 0x4046, DWORD dwUnk3 = 0x96, bool bSilent = false)
		{ JMP_THIS(0x5D3BA0); };

	void PrintMessage(const wchar_t* pLabel, const wchar_t* pMessage, int nColorSchemeIndex = ColorScheme::White)
		{ this->PrintMessage(pLabel, 0, pMessage, nColorSchemeIndex); }

	void PrintMessage(const wchar_t* pMessage, int nColorSchemeIndex = ColorScheme::White)
		{ this->PrintMessage(nullptr, 0, pMessage, nColorSchemeIndex); }

};

#endif
