#ifndef LOADPROGRESSMGR_H
#define LOADPROGRESSMGR_H

#include <YRPP.h>

struct SHPStruct;
class Surface;

class LoadProgressManager
{
	public:
		static LoadProgressManager * Global;

	PROPERTY(DWORD, field_4);
	PROPERTY(DWORD, field_8);
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
