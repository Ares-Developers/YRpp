#pragma once

#include <GeneralDefinitions.h>
#include <CCINIClass.h>

class NOVTABLE CampaignClass : public AbstractTypeClass {

public:
	static const AbstractType AbsID = AbstractType::Campaign;

	CampaignClass(const char *name) noexcept
		: CampaignClass(noinit_t())
	{ JMP_THIS(0x46CB60); }

protected:
	explicit __forceinline CampaignClass(noinit_t) noexcept
		: AbstractTypeClass(noinit_t())
	{ }

public:
	static void __fastcall CreateFromINIList(CCINIClass *pINI)
		{ JMP_STD(0x46CE10); }

	static signed int __fastcall FindIndex(const char* name)
		{ JMP_STD(0x46CC90); }

public:
	int idxCD;
	char Scenario[512];
	int FinalMovie;
	wchar_t Description[128];
};
