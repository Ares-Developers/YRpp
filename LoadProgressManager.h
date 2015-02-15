#pragma once

#include <YRPP.h>

struct SHPStruct;
class Surface;

class LoadProgressManager
{
public:
	static LoadProgressManager* &LPMgr;

	static void DrawText(const wchar_t* pText,int X,int Y,DWORD dwColor) {
		if(LoadProgressManager::LPMgr) {
			if(Surface * S = LoadProgressManager::LPMgr->ProgressSurface) {
				S->DrawText(pText, X, Y, dwColor);
			}
		}
	}

	LoadProgressManager()
		{ JMP_THIS(0x552A40); }

	virtual ~LoadProgressManager()
		{ JMP_THIS(0x552AA0); }

	void Draw()
		{ JMP_THIS(0x552D60); }

	DWORD field_4;
	DWORD field_8;
	DWORD field_C;
	DWORD field_10;
	DWORD field_14;
	DWORD field_18;
	DWORD field_1C;
	DWORD field_20;
	DWORD field_24;
	DWORD field_28;
	DWORD field_2C;
	DWORD field_30;
	DWORD field_34;
	DWORD field_38;
	wchar_t* LoadMessage;
	wchar_t* LoadBriefing;
	SHPStruct * TitleBarSHP;
	SHPStruct * LoadBarSHP;
	SHPStruct * BackgroundSHP;
	bool TitleBarSHP_loaded;
	bool LoadBarSHP_loaded;
	bool BackgroundSHP_loaded;
	DWORD field_54;
	DWORD field_58;
	DWORD field_5C;
	Surface * ProgressSurface;
};
