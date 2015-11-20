/*
	Sound effects!
*/

#pragma once

#include <ArrayClasses.h>
#include <GeneralDefinitions.h>
#include <Audio.h>

struct VocClassHeader {
	VocClassHeader* Next;
	VocClassHeader* Prev;
	DWORD Magic;
};

struct VolumeStruct	//pretty uncreative name, but it's all I can come up with atm
{
	int			Volume;		//Between 0 and 16384, lowest bit is forced to 1, default is 0
	DWORD		unknown_4;	//uninitialized
	int			unknown_int_8;	//Volume * 1024, default is unknown_int_1C * 1024
	int			unknown_int_C;	//default is 1073741
	int			unknown_int_10;	//default is 1000
	int			unknown_int_14;	//default is 0
	DWORD		unknown_18;		//default is ds:87E848h
	int			unknown_int_1C;	//default is 16384
};

class VocClass
{
public:
	static DynamicVectorClass<VocClass*>* const Array;

	static bool& VoicesEnabled;

	static VocClass* Find(const char* pName)
	{
		for(int i = 0; i < Array->Count; ++i) {
			if(!_strcmpi(Array->Items[i]->Name, pName)) {
				return Array->Items[i];
			}
		}
		return nullptr;
	}
/* dunno what gives, but this doesn't work, the one below does
	static int FindIndexOf(const char* pName)
	{
		for(int i = 0; i < Array->get_Count(); i++)
			if(!_strcmpi((*Array)[i]->get_Name(),pName))return i;
		return -1;
	}
*/
	static int __fastcall FindIndex(const char *pName)
		{ JMP_STD(0x7514D0); }

	/* Play a sound independant of the position.
	   n = Index of VocClass in Array to be played
	   Volume = 0.0f to 1.0f
	   Panning = 0x0000 (left) to 0x4000 (right) (0x2000 is center)
	   */
	static void __fastcall PlayGlobal(int n, int Panning, float Volume, AudioController* pCtrl = nullptr)
		{ JMP_STD(0x750920); }

	/* Play a sound at a certain Position.
       n = Index of VocClass in Array to be played */
	static void __fastcall PlayAt(int n, const CoordStruct &coords, AudioController* pCtrl = nullptr)
		{ JMP_STD(0x7509E0); }

	// calls the one above ^ - probably sanity checks and whatnot
	static void __fastcall PlayIndexAtPos(int n, const CoordStruct &coords, int a3 = 0)
		{ JMP_STD(0x750E20); }

	//Properties

public:

	VocClassHeader Header;
	int SamplesOK;	//0 or 1, determines whether all samples are OK to use
	SoundControl Control;
	SoundType Type;
	VolumeStruct Volume;
	DWORD unknown_38;
	DWORD unknown_3C;
	SoundPriority Priority;
	DWORD unknown_44;
	int Limit;	//as in sound.ini
	int Loop;	//as in sound.ini
	int Range;	//as in sound.ini
	float MinVolume;	//as in sound.ini
	int MinDelay;	//as in sound.ini
	int MaxDelay;	//as in sound.ini
	int MinFDelta;	//as in sound.ini
	int MaxFDelta;	//as in sound.ini
	int VShift;	//as in sound.ini
	char Name [0x20]; //as in sound.ini
	DWORD unknown_8C;
	DWORD unknown_90;
	DWORD unknown_94;
	DWORD unknown_98;
	DWORD unknown_9C;
	DWORD unknown_A0;
	DWORD unknown_A4;
	DWORD unknown_A8;
	DWORD unknown_AC;
	DWORD unknown_B0;

	int SampleIndex [0x20];

	int NumSamples;
	int Attack;
	int Decay;
	DWORD unknown_140;
	DWORD unknown_144;

	//constructor and destructor should never be needed
	VocClass() = delete;
	~VocClass() = delete;
};
