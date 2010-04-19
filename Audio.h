#ifndef AUDIO_H_
#define AUDIO_H_

#include <GeneralDefinitions.h>
class RawFileClass;
class CCFileClass;

class AudioIDXHeader {
	unsigned int Magic;
	unsigned int Version;
	unsigned int numSamples;
};

class AudioIDXEntry { // assert (IDXHeader.version != 1);
	char Name[16];
	unsigned int Offset;
	unsigned int Size;
	unsigned int SampleRate;
	unsigned int Flags;
	unsigned int ChunkSize;
};

class AudioIDXData {
public:
	static AudioIDXData * &IDX;

	static AudioIDXData* __fastcall Create(const char *Filename, const char *extra)
		{ JMP_STD(0x4011C0); };

	~AudioIDXData()
		{ JMP_THIS(0x401580); }

	unsigned int __fastcall FindSampleIndex(const char *SoundName)
		{ JMP_STD(0x4015C0); }

	const char * __fastcall GetSampleName(unsigned int SoundIndex)
		{ JMP_STD(0x401600); }

	unsigned int __fastcall GetSampleSize(unsigned int SoundIndex)
		{ JMP_STD(0x401620); }

	AudioIDXEntry *Samples;
	unsigned int cntSamples;
	DWORD field_08;
	DWORD field_0C;
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
	DWORD field_3C;
	DWORD field_40;
	DWORD field_44;
	DWORD field_48;
	DWORD field_4C;
	DWORD field_50;
	DWORD field_54;
	DWORD field_58;
	DWORD field_5C;
	DWORD field_60;
	DWORD field_64;
	DWORD field_68;
	DWORD field_6C;
	DWORD field_70;
	DWORD field_74;
	DWORD field_78;
	DWORD field_7C;
	DWORD field_80;
	DWORD field_84;
	DWORD field_88;
	DWORD field_8C;
	DWORD field_90;
	DWORD field_94;
	DWORD field_98;
	DWORD field_9C;
	DWORD field_A0;
	DWORD field_A4;
	DWORD field_A8;
	DWORD field_AC;
	DWORD field_B0;
	DWORD field_B4;
	DWORD field_B8;
	DWORD field_BC;
	DWORD field_C0;
	DWORD field_C4;
	DWORD field_C8;
	DWORD field_CC;
	DWORD field_D0;
	DWORD field_D4;
	DWORD field_D8;
	DWORD field_DC;
	DWORD field_E0;
	DWORD field_E4;
	DWORD field_E8;
	DWORD field_EC;
	DWORD field_F0;
	DWORD field_F4;
	DWORD field_F8;
	DWORD field_FC;
	DWORD field_100;
	DWORD field_104;
	DWORD field_108;
	CCFileClass *File;
	DWORD field_110; // something with a vtable
	DWORD field_114;
	DWORD field_118;
	DWORD field_11C;
	DWORD field_120;
};

class Audio {
public:

	static bool __fastcall ReadWAVFile(RawFileClass *file, void *AudioSample, int *result)
		{ JMP_STD(0x408610); }
};

class AudioStream {
public:
	static AudioStream* &Instance;

	bool __fastcall PlayWAV(const char * filename, bool bUnk)
		{ JMP_STD(0x407B60); }
};

struct TauntDataStruct {
	DWORD tauntIdx: 4;
	DWORD countryIdx :4;
};

struct AudioController
{
	static DWORD * &Audio_IDX_Container;

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

	// no idea how these differ really
	void DTOR_0()
		{ JMP_THIS(0x405C00); }

	void DTOR_1()
		{ JMP_THIS(0x405D40); }

	void DTOR_2()
		{ JMP_THIS(0x405FD0); }

	void ShutUp()
		{ JMP_THIS(0x406060); }

	void __fastcall sub_4060F0(int a1, int a2)
		{ JMP_STD(0x4060F0); }

	void sub_406130()
		{ JMP_THIS(0x406130); }

	void sub_406170()
		{ JMP_THIS(0x406170); }

	void __fastcall sub_4061D0(unsigned int arg)
		{ JMP_STD(0x4061D0); }

	void __fastcall sub_406270(unsigned int arg)
		{ JMP_THIS(0x406270); }

	void sub_406310()
		{ JMP_THIS(0x406310); }
};

#endif
