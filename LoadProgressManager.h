#ifndef LOADPROGRESSMGR_H
#define LOADPROGRESSMGR_H

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

	PROPERTY(DWORD, field_4);
	PROPERTY(DWORD, field_8);
	PROPERTY(DWORD, field_C);
	PROPERTY(DWORD, field_10);
	PROPERTY(DWORD, field_14);
	PROPERTY(DWORD, field_18);
	PROPERTY(DWORD, field_1C);
	PROPERTY(DWORD, field_20);
	PROPERTY(DWORD, field_24);
	PROPERTY(DWORD, field_28);
	PROPERTY(DWORD, field_2C);
	PROPERTY(DWORD, field_30);
	PROPERTY(DWORD, field_34);
	PROPERTY(DWORD, field_38);
	PROPERTY(wchar_t*, LoadMessage);
	PROPERTY(wchar_t*, LoadBriefing);
	PROPERTY(SHPStruct *, TitleBarSHP);
	PROPERTY(SHPStruct *, LoadBarSHP);
	PROPERTY(SHPStruct *, BackgroundSHP);
	PROPERTY(bool, TitleBarSHP_loaded);
	PROPERTY(bool, LoadBarSHP_loaded);
	PROPERTY(bool, BackgroundSHP_loaded);
	PROPERTY(DWORD, field_54);
	PROPERTY(DWORD, field_58);
	PROPERTY(DWORD, field_5C);
	PROPERTY(Surface *, ProgressSurface);
};

#endif
