#ifndef UNSORTED_H
#define UNSORTED_H

class ObjectClass;

// things that I can't put into nice meaningful classes
class Game
{
public:
	static void RaiseError(HRESULT err)
		JMP_STD(0x7DC720);

	// the magic checksum for version validation - linked in StaticInits
	static DWORD &Savegame_Magic;

	static int &CurrentFrameRate;
	static int GetMinFrameRate()
		JMP_STD(0x55AF60);
};

class MovieInfo
{
	public:
		char *Name; // yes, only that
		static DynamicVectorClass<MovieInfo> *Array;

	bool operator== (MovieInfo &rhs)
		{ return !strcmp(rhs.Name, this->Name); }

	MovieInfo(const char *fname)
		{ this->Name = _strdup(fname); }

	MovieInfo()
		{}

	~MovieInfo()
		{ delete this->Name; }
};

namespace Unsorted
{
	static DWORD &Savegame_Magic     = *(DWORD *)0x83D560;

	static int &CurrentFrame     = *(int *)0xA8ED84;

	// if != 0, EVA_SWxxxActivated is skipped
	static int &MuteSWLaunches   = *(int *)0xA8B538;

	static byte &ArmageddonMode  = *(byte *)0xA8ED6B;
	static byte &WTFMode  = *(byte *)0xA8E9A0;

	static DynamicVectorClass<ObjectClass *>** vec_ObjectsInLayers = (DynamicVectorClass<ObjectClass *>**)0x8A0360;

// checkbox states, afaik
	static byte &Bases = *(byte *)0xA8B258;
	static byte &BridgeDestruction = *(byte *)0xA8B260;
	static byte &Crates = *(byte *)0xA8B261;
	static byte &ShortGame = *(byte *)0xA8B262;
	static byte &SWAllowed = *(byte *)0xA8B263;
	static byte &MultiEngineer = *(byte *)0xA8B26C;
	static byte &AlliesAllowed = *(byte *)0xA8B31C;
	static byte &HarvesterTruce = *(byte *)0xA8B31D;
	static byte &CTF = *(byte *)0xA8B31E;
	static byte &FOW = *(byte *)0xA8B31F;
	static byte &MCVRedeploy = *(byte *)0xA8B320;


struct ColorPacker
{
	int _R_SHL;
	int _R_SHR;
	int _B_SHL;
	int _B_SHR;
	int _G_SHL;
	int _G_SHR;
};

	static ColorPacker *ColorPackData = (ColorPacker *)0x8A0DD0;

	static CellStruct *CellSpreadTable = (CellStruct *)0xABD490;

	static int &CurrentSWType = *(int *)0x8809A0;

	static const int except_txt_length = 0xFFFF;
	static char *except_txt_content = (char *)0x8A3A08;

	static DWORD *Audio_IDX_Container = (DWORD*)0x87E294;

struct AudioController
{
	DWORD f_0;
	DWORD f_4;
	DWORD f_8;
	DWORD *f_C;
	DWORD f_10;

	AudioController()
	{
		this->f_0 = this->f_4 = this->f_8 = 0;
		this->f_C = Audio_IDX_Container;
	}

	void DTOR_0()
		JMP_THIS(0x405C00);

	void DTOR_1()
		JMP_THIS(0x405D40);

	void DTOR_2()
		JMP_THIS(0x405FD0);

	void DTOR_3()
		JMP_THIS(0x406060);

	void __fastcall sub_4060F0(int a1, int a2)
		JMP_STD(0x4060F0);

	void sub_406130()
		JMP_THIS(0x406130);

	void sub_406170()
		JMP_THIS(0x406170);

	void __fastcall sub_4061D0(unsigned int arg)
		JMP_STD(0x4061D0);

	void __fastcall sub_406270(unsigned int arg)
		JMP_THIS(0x406270);

	void sub_406310()
		JMP_THIS(0x406310);

};

/*
 * This thing is ridiculous
 * all xxTypeClass::Create functions use it:

  InfantryTypeClass *foo = something;
  ++SomeMutex;
  InfantryClass *obj = something->CreateObject();
  --SomeMutex;

  ++SomeMutex;
  obj->Put(blah);
  --SomeMutex;
  
  AI base node generation uses it:
  int level = SomeMutex;
  SomeMutex = 0;
  House->GenerateAIBuildList();
  SomeMutex = level;
  
  Building destruction uses it:
  if(!SomeMutex) {
  	Building->ShutdownSensorArray();
  	Building->ShutdownDisguiseSensor();
  }
  
  Building placement uses it:
  if(!SomeMutex) {
  	UnitTypeClass *freebie = Building->Type->FreeUnit;
  	if(freebie) {
  		freebie->CreateObject(blah);
  	}
  }
  
  Building state animations use it:
  if(SomeMutex) {
  	// foreach attached anim
  	// update anim state (normal | damaged | garrisoned) if necessary, play anim
  }
  
  building selling uses it:
  if(blah) {
  	++SomeMutex;
  	this->Type->UndeploysInto->CreateAtMapCoords(blah);
  	--SomeMutex;
  }

  Robot Control Centers use it:
  if ( !SomeMutex ) {
  	VoxClass::PlayFromName("EVA_RobotTanksOffline/BackOnline", -1, -1);
  }

  and so on...
 */
	static int &SomeMutex = *(int *)0xA8E7AC;
}

#endif
