#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <PowerClass.h>

// sizeof() == 0x34
struct CameoDataStruct
{
	int               ItemIndex;
	eAbstractType     ItemType;
	bool              IsAlt; // set on buildings that go on tab 2
	FactoryClass*     CurrentFactory;
	DWORD             unknown_10;
	int               Progress; // 0 to 54, how much of this object is constructed (gclock anim level)
	bool              unknown_18;
	TimerStruct       ProcessingTimer;
	int               RemainingTime;
	int               unknown_2C;
	int               unknown_30;
};

// sizeof() == 0xF94
struct TabDataStruct
{
	DWORD             unknown_00;
	DWORD             unknown_04;
	DWORD             unknown_08;
	DWORD             unknown_0C;
	DWORD             unknown_10;
	DWORD             unknown_14;
	DWORD             unknown_18;
	DWORD             unknown_1C;
	DWORD             unknown_20;
	DWORD             unknown_24;
	DWORD             unknown_28;
	DWORD             unknown_2C;
	DWORD             unknown_30;
	DWORD             unknown_34;
	DWORD             unknown_38;
	DWORD             unknown_3C;
	DWORD             unknown_40;
	int               TopRowIndex; // scroll position, which row is topmost visible
	DWORD             unknown_48;
	DWORD             unknown_4C;
	DWORD             unknown_50;
	int               CameoCount; // filled cameos
	CameoDataStruct   Cameos[75];
};

class SidebarClass : public PowerClass
{
public:
	//Static
	static SidebarClass* Global()
		{ return (SidebarClass*)0x87F7E8; }

	//Destructor
	virtual ~SidebarClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x6AC7F0); }

	//GScreenClass
	virtual void One_Time()
		{ THISCALL(0x6A5000); }

	virtual void Init_Clear()
		{ THISCALL(0x6A5030); }

	virtual void vt_entry_20()
		{ THISCALL(0x6A5310); }

	virtual void Update(DWORD dwUnk1, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk1); THISCALL(0x6A7780); }

	virtual void Draw(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x6A6C30); }

	//DisplayClass
	virtual void Load(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x6AC5D0);}

	virtual void Save(IStream* pStm)
		{ PUSH_VAR32(pStm); THISCALL(0x6AC5E0);}

	virtual const wchar_t* GetToolTip(UINT nDlgID)
		{ PUSH_VAR32(nDlgID); THISCALL_RET(0x6AC210, const wchar_t*); }

	virtual void CloseWindow()	//???
		{ THISCALL(0x6ABD30); }

	//RadarClass
	virtual void DisposeOfArt()
		{ THISCALL(0x6A5BF0); }

	virtual void Init_For_House()
		{ THISCALL(0x6A5840); }

	//SidebarClass
	virtual bool vt_entry_138(int nUnknown)
		{ PUSH_VAR32(nUnknown); THISCALL_RET(0x6A7D70, bool); }

	//Non-virtual

protected:
	//Constructor
	SidebarClass() {}	//don't need this

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRUCT_ARRAY(TabDataStruct, Tabs, 0x4);
	PROPERTY(DWORD,				unknown_5394);
	PROPERTY(DWORD,				unknown_5398);
	PROPERTY(DWORD,				unknown_539C);
	PROPERTY(DWORD,				unknown_53A0);
	PROPERTY(bool,				unknown_bool_53A4);
	PROPERTY(bool,				unknown_bool_53A5);
	PROPERTY(bool,				unknown_bool_53A6);
	PROPERTY(bool,				unknown_bool_53A7);
	PROPERTY(bool,				unknown_bool_53A8);

	//Information for the Diplomacy menu, I believe
	PROPERTY_ARRAY(HouseClass*,		DiplomacyHouses, 0x8);		//8 players max!
	PROPERTY_ARRAY(int,				DiplomacyKills, 0x8);		//total amount of kills per house
	PROPERTY_ARRAY(int,				DiplomacyOwned, 0x8);		//total amount of currently owned unit/buildings per house
	PROPERTY_ARRAY(int,				DiplomacyPowerDrain, 0x8);	//current power drain per house
	PROPERTY_ARRAY(ColorScheme*,	DiplomacyColors, 0x8);		//color scheme per house
	PROPERTY_ARRAY(DWORD,			unknown_544C, 0x8);			//??? per house - unused
	PROPERTY_ARRAY(DWORD,			unknown_546C, 0x8);			//??? per house - unused
	PROPERTY_ARRAY(DWORD,			unknown_548C, 0x8);			//??? per house - unused
	PROPERTY_ARRAY(DWORD,			unknown_54AC, 0x8);			//??? per house - unused
	PROPERTY_ARRAY(DWORD,			unknown_54CC, 0x8);			//??? per house - unused
	PROPERTY_ARRAY(DWORD,			unknown_54EC, 0x8);			//??? per house - unused
	PROPERTY(BYTE,				unknown_550C);
	PROPERTY(int,				DiplomacyNumHouses);			//possibly?

	PROPERTY(bool,				unknown_bool_5514);
	PROPERTY(bool,				unknown_bool_5515);

};

#endif
