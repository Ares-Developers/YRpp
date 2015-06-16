/*
	Use this to print a message on the screen!
*/

#pragma once

#include <wchar.h>
#include <ASMMacros.h>
#include <ColorScheme.h>

class MessageListClass
{
public:
	static MessageListClass* const Instance;

	// if pLabel is given, the message will be {$pLabel}:{$pMessage}
	// else it will be just {$pMessage}

	void PrintMessage(const wchar_t* pLabel, DWORD dwUnk1, const wchar_t* pMessage, int nColorSchemeIndex = ColorScheme::Yellow,
		DWORD dwUnk2 = 0x4046, int duration = 0x96, bool bSilent = false)
		{ JMP_THIS(0x5D3BA0); };

	void PrintMessage(const wchar_t* pMessage, int durationFrames = 0x96, int nColorSchemeIndex = ColorScheme::White, bool bSilent = false)
		{ this->PrintMessage(nullptr, 0, pMessage, nColorSchemeIndex, 0x4046, durationFrames, bSilent); }

	void PrintMessage(const wchar_t* pMessage, double durationMinutes, int nColorSchemeIndex = ColorScheme::White, bool bSilent = false)
		{ this->PrintMessage(nullptr, 0, pMessage, nColorSchemeIndex, 0x4046, static_cast<int>(durationMinutes * 900), bSilent); }
};
