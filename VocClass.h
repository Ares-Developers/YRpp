/*
	Sound effects!
*/

#ifndef VOC_H
#define VOC_H

#include <ArrayClasses.h>
#include <GeneralDefinitions.h>

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
	static DynamicVectorClass<VocClass*>* Array;
	static VocClass* Find(const char* pName)
	{
		for(int i = 0; i < Array->Count; ++i) {
			if(!_strcmpi(Array->Items[i]->Name, pName)) {
				return Array->Items[i];
			}
		}
		return NULL;
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
	static void __fastcall PlayGlobal(int n, float Volume, int Panning, DWORD dwUnk = 0)
		{ JMP_STD(0x750920); }

	/* Play a sound at a certain Position.
       n = Index of VocClass in Array to be played */
	static void __fastcall PlayAt(int n, CoordStruct* pCoords, Unsorted::AudioController *ctrl)
		{ JMP_STD(0x7509E0); }

	//Properties
	PROPERTY(VocClass*,			Next);	//Linked list of VocClass instances
	PROPERTY(VocClass*,			unknown_04);	//not sure whether this is "Previous"?
	PROPERTY(VocClass*,			unknown_08);	//no idea, some invalid
	PROPERTY(int,				SamplesOK);	//0 or 1, determines whether all samples are OK to use
	PROPERTY(DWORD,				unknown_10);
	PROPERTY(eSoundType,		Type);
	PROPERTY_STRUCT(VolumeStruct,		Volume);
	PROPERTY(DWORD,				unknown_38);
	PROPERTY(DWORD,				unknown_3C);
	PROPERTY(eSoundPriority,	Priority);
	PROPERTY(DWORD,				unknown_44);
	PROPERTY(int,				Limit);	//as in sound.ini
	PROPERTY(int,				Loop);	//as in sound.ini
	PROPERTY(int,				Range);	//as in sound.ini
	PROPERTY(float,				MinVolume);	//as in sound.ini
	PROPERTY(int,				MinDelay);	//as in sound.ini
	PROPERTY(int,				MaxDelay);	//as in sound.ini
	PROPERTY(int,				MinFDelta);	//as in sound.ini
	PROPERTY(int,				MaxFDelta);	//as in sound.ini
	PROPERTY(int,				VShift);	//as in sound.ini
	PROPERTY_STRING(Name,0x1F); //as in sound.ini
	PROPERTY(DWORD,				unknown_8C);
	PROPERTY(DWORD,				unknown_90);
	PROPERTY(DWORD,				unknown_94);
	PROPERTY(DWORD,				unknown_98);
	PROPERTY(DWORD,				unknown_9C);
	PROPERTY(DWORD,				unknown_A0);
	PROPERTY(DWORD,				unknown_A4);
	PROPERTY(DWORD,				unknown_A8);
	PROPERTY(DWORD,				unknown_AC);
	PROPERTY(DWORD,				unknown_B0);

	PROPERTY_ARRAY(int, SampleIndex, 0x20);

	PROPERTY(int,				NumSamples);
	PROPERTY(int,				Attack);
	PROPERTY(int,				Decay);
	PROPERTY(DWORD,				unknown_140);
	PROPERTY(DWORD,				unknown_144);

private:	//constructor and destructor should never be needed
	VocClass(){}
	~VocClass(){}
};

#endif

