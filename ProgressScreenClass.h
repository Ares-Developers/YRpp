#pragma once

#include <GeneralDefinitions.h>
#include <LoadProgressManager.h>
#include <FileFormats/SHP.h>
#include <Helpers/CompileTime.h>

class ProgressScreenClass {
public:

	static constexpr reference<ProgressScreenClass, 0xAC4F58u> const Instance{};

	void SetSide(int idx)
		{ JMP_THIS(0x642B10); }

	int GetSide()
		{ JMP_THIS(0x642B20); }


	int field_0;
	LoadProgressManager *LoadManager;
	double PlayerProgresses[8];
	int MainProgress;
	int field_4C;
	void *PlayerStartSpot; // bah, I have multiple definitions of this in my IDB, can't be bothered to fix it now
	SHPStruct *someSHP;
	char field_58;
	char field_59;
	char field_5A;
	char field_5B;
	int field_5C;
	char field_60;
	byte TotalPlayers;
	char field_62;
	char field_63;
	HWND hWnd;
	int field_68;
	int field_6C;
	char field_70;
	char field_71;
	char field_72;
	char field_73;
	int field_74;
	int field_78;
	int field_7C;
	int PlayerSide; // !! this is set to campaign -> CD for singleplay

protected:
	ProgressScreenClass(){};
};
