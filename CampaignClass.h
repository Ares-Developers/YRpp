#ifndef CAMPAIGNCLASS_H_
#define CAMPAIGNCLASS_H_

#include <GeneralDefinitions.h>
#include <CCINIClass.h>

class CampaignClass : public AbstractTypeClass {

public:
	CampaignClass(const char *name)
		{ JMP_THIS(0x46CB60); }

	static void __fastcall CreateFromINIList(CCINIClass *pINI)
		{ JMP_STD(0x46CE10); }

public:
	int idxCD;
	char Scenario[512];
	int FinalMovie;
	wchar_t Description[128];
};

#endif
