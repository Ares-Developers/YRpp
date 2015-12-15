#pragma once

#include <PowerClass.h>
#include <ProgressTimer.h>

class ColorScheme;
class FactoryClass;

// sizeof() == 0x34
struct CameoDataStruct
{
	int               ItemIndex{ -1 };
	AbstractType      ItemType{ AbstractType::None };
	bool              IsAlt{ false }; // set on buildings that go on tab 2
	FactoryClass*     CurrentFactory{ nullptr };
	DWORD             unknown_10{ 0 };
	ProgressTimer     Progress{}; // 0 to 54, how much of this object is constructed (gclock anim level)
	int               FlashEndFrame{ 0 };

	CameoDataStruct() = default;

	CameoDataStruct(int itemIndex, AbstractType itemType) :
		ItemIndex(itemIndex),
		ItemType(itemType)
	{ /*JMP_THIS(0x6AC7C0);*/ }

	bool operator == (const CameoDataStruct &rhs) const {
		return ItemIndex == rhs.ItemIndex && ItemType == rhs.ItemType;
	}

	bool operator != (const CameoDataStruct &rhs) const {
		return ItemIndex != rhs.ItemIndex || ItemType != rhs.ItemType;
	}

	bool operator < (const CameoDataStruct &rhs) const {
		return SortsBefore(this->ItemType, this->ItemIndex, rhs.ItemType, rhs.ItemIndex);
	}

	static bool __stdcall SortsBefore(AbstractType leftType, int leftIndex, AbstractType rightType, int rightIndex)
		{ JMP_STD(0x6A8420); }
};

// sizeof() == 0xF94
struct TabDataStruct
{
	ProgressTimer     Progress;
	DWORD             unknown_1C;
	DWORD             unknown_20;
	DWORD             unknown_24;
	DWORD             unknown_28;
	DWORD             unknown_2C;
	DWORD             unknown_30;
	DWORD             unknown_34;
	DWORD             unknown_38;
	BYTE              unknown_3C;
	BYTE              unknown_3D;
	BYTE              unknown_3E;
	BYTE              unknown_3F;
	DWORD             unknown_40;
	int               TopRowIndex; // scroll position, which row is topmost visible
	DWORD             unknown_48;
	DWORD             unknown_4C;
	DWORD             unknown_50;
	int               CameoCount; // filled cameos
	CameoDataStruct   Cameos[75];
};

class NOVTABLE SidebarClass : public PowerClass
{
public:
	//Static
	static SidebarClass* Global()
		{ return reinterpret_cast<SidebarClass*>(0x87F7E8); }

	enum {TooltipLength = 0x42};

	static wchar_t * const TooltipBuffer;

	void SidebarNeedsRepaint(int unk = 0)
		{
			// yeah, unknown voodoo magic shticks
			this->unknown_bool_53A6 = this->unknown_bool_53A7 = true;
			this->Tabs[this->ActiveTabIndex].unknown_1C = this->Tabs[this->ActiveTabIndex].unknown_3C = 1;
			this->RedrawSidebar(unk);
			SidebarClass::Draw(1);
		}

	void RepaintSidebar(int tab = 0)
		{ JMP_THIS(0x6A60A0); }

	bool AddCameo(AbstractType absType, int idxType)
		{ JMP_THIS(0x6A6300); }

	virtual void Draw(DWORD dwUnk) override
		{ JMP_THIS(0x6A6C30); }

	//Destructor
	virtual ~SidebarClass() RX;

	//SidebarClass
	virtual bool vt_entry_D8(int nUnknown) R0;

	//Non-virtual

	// which tab does the 'th object of that type belong in?
	static int __fastcall GetObjectTabIdx(AbstractType abs, int idxType, int unused)
		{ JMP_STD(0x6ABC60); }

	// which tab does the 'th object of that type belong in?
	static int __fastcall GetObjectTabIdx(AbstractType abs, BuildCat buildCat, bool isNaval)
		{ JMP_STD(0x6ABCD0); }

protected:
	//Constructor
	SidebarClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	TabDataStruct Tabs[0x4];
	DWORD unknown_5394;
	DWORD unknown_5398;
	int ActiveTabIndex;
	DWORD unknown_53A0;
	bool HideObjectNameInTooltip; // see 0x6A9343
	bool unknown_bool_53A5;
	bool unknown_bool_53A6;
	bool unknown_bool_53A7;
	bool unknown_bool_53A8;

	//Information for the Diplomacy menu, I believe
	HouseClass* DiplomacyHouses[0x8];		//8 players max!
	int DiplomacyKills[0x8];		//total amount of kills per house
	int DiplomacyOwned[0x8];		//total amount of currently owned unit/buildings per house
	int DiplomacyPowerDrain[0x8];	//current power drain per house
	ColorScheme* DiplomacyColors[0x8];		//color scheme per house
	DWORD unknown_544C[0x8];			//??? per house - unused
	DWORD unknown_546C[0x8];			//??? per house - unused
	DWORD unknown_548C[0x8];			//??? per house - unused
	DWORD unknown_54AC[0x8];			//??? per house - unused
	DWORD unknown_54CC[0x8];			//??? per house - unused
	DWORD unknown_54EC[0x8];			//??? per house - unused
	BYTE unknown_550C;
	int DiplomacyNumHouses;			//possibly?

	bool unknown_bool_5514;
	bool unknown_bool_5515;
	PROTECTED_PROPERTY(BYTE, padding_5516[2]);
};
