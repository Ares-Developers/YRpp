//Class to show a YR-style Message Box ingame

#pragma once

#include <YRPPCore.h>
#include <StringTable.h>

typedef int eMessageBoxResult;
#define MESSAGEBOXRESULT_OK			0
#define MESSAGEBOXRESULT_CANCEL		1

#define MESSAGEBOXRESULT_BUTTON0	0
#define MESSAGEBOXRESULT_BUTTON1	1

class MessageBox
{
public:
	static eMessageBoxResult Show(const wchar_t* pMessage, const wchar_t* pButton1Text, const wchar_t* pButton2Text)
		{
			wchar_t* pTitle=reinterpret_cast<wchar_t*>(0x82083C);	//Title?
			wchar_t** ppTitle=&pTitle;

			PUSH_IMM(0);
			PUSH_IMM(0);
			PUSH_VAR32(pButton2Text);
			PUSH_VAR32(pButton1Text);
			PUSH_VAR32(pMessage);
			SET_REG32(ecx,ppTitle);
			CALL(0x5D3490);
		}

	static eMessageBoxResult Show(const wchar_t* pMessage)
		{ return Show(pMessage, StringTable::LoadString("TXT_OK"), StringTable::LoadString("TXT_CANCEL")); }
};
