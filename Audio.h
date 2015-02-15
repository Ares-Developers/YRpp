#pragma once

#include <GeneralDefinitions.h>

class RawFileClass;
class CCFileClass;
class VocClass;

struct AudioIDXHeader {
	unsigned int Magic;
	unsigned int Version;
	unsigned int numSamples;
};

struct AudioIDXEntry { // assert (IDXHeader.version != 1);
	char Name[16];
	int Offset;
	int Size;
	unsigned int SampleRate;
	unsigned int Flags;
	unsigned int ChunkSize;

	bool operator < (const AudioIDXEntry& rhs) const {
		return _strcmpi(this->Name, rhs.Name) < 0;
	}
};

struct AudioSampleData {
	AudioSampleData() :
		Data(0),
		Format(0),
		SampleRate(0),
		NumChannels(0),
		BytesPerSample(0),
		ByteRate(0),
		BlockAlign(0),
		Flags(0)
	{ }

	unsigned int Data;
	unsigned int Format;
	unsigned int SampleRate;
	unsigned int NumChannels;
	unsigned int BytesPerSample;
	unsigned int ByteRate;
	unsigned int BlockAlign;
	unsigned int Flags;
};

class AudioIDXData {
public:
	static AudioIDXData* &Instance;

	static AudioIDXData* __fastcall Create(const char* pFilename, const char* pPath)
		{ JMP_STD(0x4011C0); };

	AudioIDXData() {
		memset(this, 0, sizeof(*this));
	}

	~AudioIDXData()
		{ JMP_THIS(0x401580); }

	void ClearCurrentSample()
		{ JMP_THIS(0x401910); }

	int __fastcall FindSampleIndex(const char* pName) const
		{ JMP_STD(0x4015C0); }

	const char* __fastcall GetSampleName(int index) const
		{ JMP_STD(0x401600); }

	int __fastcall GetSampleSize(int index) const
		{ JMP_STD(0x401620); }

	AudioSampleData* __fastcall GetSampleInformation(int index, AudioSampleData* pBuffer) const
		{ JMP_STD(0x401640); }

	AudioIDXEntry* Samples;
	int SampleCount;
	char Path[MAX_PATH];
	CCFileClass* BagFile;
	RawFileClass* ExternalFile;
	BOOL PathFound;
	RawFileClass* CurrentSampleFile;
	int CurrentSampleSize;
	DWORD unknown_120;
};

class Audio {
public:

	static bool __fastcall ReadWAVFile(RawFileClass* pFile, AudioSampleData* pAudioSample, int* pDataSize)
		{ JMP_STD(0x408610); }
};

class AudioStream {
public:
	static AudioStream* &Instance;

	bool __fastcall PlayWAV(const char* pFilename, bool bUnk)
		{ JMP_STD(0x407B60); }
};

struct TauntDataStruct {
	DWORD tauntIdx : 4;
	DWORD countryIdx : 4;
};

struct AudioController
{
	void* f_0;
	DWORD f_4;
	VocClass* Voice;
	AudioIDXData** AudioIndex;
	DWORD f_10;

	AudioController() :
		f_0(nullptr),
		f_4(0),
		Voice(nullptr),
		AudioIndex(&AudioIDXData::Instance),
		f_10(0)
	{ }

	~AudioController() 
		{ JMP_THIS(0x405C00); }

	// no idea how these differ really
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
