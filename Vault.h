/*
	This is the Vault.
	Put unused definitions here, be it WIP stuff or simply things there is no use for at the moment,
	so we have them ready if we should need them some time.

	Don't include this anywhere.
*/

#if 0

class MapRegionClass
{
	//Properties
	DWORD							unknown_00;
	DWORD							unknown_04;
	int								ArrayIndex;
	int								NumValidCells;	//Amount of cells that are not 0,0
	int								Level;	//0x10
	bool							Wet; //0x14
	bool							GreenTile;	//0x15
	CellStruct						BaseCellCoords;	//0x16!
	bool							unknown_bool_1A;
	bool							unknown_bool_1B;
	DWORD							unknown_1C;
	DWORD							unknown_20;
	bool							unknown_24;
	DynamicVectoClass<CellStruct>	Cells;
	DWORD							unknown_40;
	DWORD							unknown_44;
	DWORD							unknown_48;
	DWORD							unknown_4C;
};

struct RMGCellDataStruct
{
	CellStruct		Coords;
	DWORD			unknown_04;
	DWORD			unknown_08;
	DWORD			unknown_0C;
	DWORD			unknown_10;
	DWORD			unknown_14;
	DWORD			unknown_18;
	DWORD			unknown_1C;
	DWORD			unknown_20;
	DWORD			unknown_24;
	DWORD			unknown_28;
	DWORD			unknown_2C;
	DWORD			unknown_30;
	DWORD			unknown_34;
	int				MapRegionIndex;	//belongs to this map region. -1 means none
	int				unknown_int_3C;
	int				unknown_int_40;
	bool			unknown_bool_44;
	bool			unknown_bool_45;
	bool			unknown_bool_46;
	bool			unknown_bool_47;
	bool			unknown_bool_48;
	bool			unknown_bool_49;
	bool			unknown_bool_4A;
	bool			unknown_bool_4B;
	DWORD			unknown_4C;
};

typedef int eIngameGUIElements;
// mousemove functions use this signature:
// void(?) RadarClass_MouseMove(signed int *elementID, dwXY *mouseCoords);
// these are values for elementID
#define egui_ACB_Collapser 0x80F0 // the edge of the Advanced Command Bar, click to collapse ACB
#define egui_ACB_Covered  0x80F1 // the block overlaying the ACB when it's "collapsed", click to expand

#define egui_ACB_BUTTON00 0xD6 // up to 11 buttons on the ACB, ltr
#define egui_ACB_BUTTON01 0xD7 // which of them corresponds to which function is modifiable via uimd.ini
#define egui_ACB_BUTTON02 0xD8
#define egui_ACB_BUTTON03 0xD9
#define egui_ACB_BUTTON04 0xDA
#define egui_ACB_BUTTON05 0xDB
#define egui_ACB_BUTTON06 0xDC
#define egui_ACB_BUTTON07 0xDD
#define egui_ACB_BUTTON08 0xDE
#define egui_ACB_BUTTON09 0xDF
#define egui_ACB_BUTTON0A 0xE0

#define egui_TAB_HEADING00 0x80CB
#define egui_TAB_HEADING01 0x80CC
#define egui_TAB_HEADING02 0x80CD
#define egui_TAB_HEADING03 0x80CE

#define egui_BUTTON_REPAIR 0x8065
#define egui_BUTTON_SELL   0x8066

// BLITTERS

class AlphaLightingRemapClass
{
	public:
		static AlphaLightingRemapClass *FindOrAllocate(int Level)
			JMP_STD(0x420140);

	protected:
		AlphaLightingRemapClass() {};

  WORD data[0x10000];
  DWORD TranslucencyLevel;
  DWORD RefCount;
};

class Blitter
{
	public:
		Blitter() {};
		virtual ~Blitter() {};

	virtual void Blit(byte *buf1, byte *buf2, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11);
	virtual void CallBlit(byte *buf1, byte *buf2, byte Length, int EncodedLen, int a6, int a7, int a8, int a9, int a10, int a11, DWORD useless);

	byte *Data; // LightConvertClass's byte buffer
};



#endif
