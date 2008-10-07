/*
	EVA Messages!
*/

#ifndef VOX_H
#define VOX_H

#include <ArrayClasses.h>
#include <GeneralDefinitions.h>

class VoxClass
{
public:
	static DynamicVectorClass<VoxClass*>* Array;
	static VoxClass* Find(const char* pName)
	{
		for(int i = 0; i < Array->get_Count(); i++)
			if(!_strcmpi((*Array)[i]->get_Name(),pName))return (*Array)[i];
		return NULL;
	}
	static int FindIndex(const char* pName)
	{
		for(int i = 0; i < Array->get_Count(); i++)
			if(!_strcmpi((*Array)[i]->get_Name(),pName))return i;
		return -1;
	}

	static void __fastcall Play(const char* pName, int nUnk = -1, int nUnk2 = -1)
		JMP_STD(0x752700);

	static void __fastcall PlayIndex(int index, int nUnk = -1, int nUnk2 = -1)
		JMP_STD(0x752480);

	static void __fastcall PlayAtPos(int index, CoordStruct *pCoords, DWORD dwUnk = 0)
		JMP_STD(0x750E20);

	// no idea what this does, but Super::Launch uses it on "SW Ready" events right after firing said SW
	static void __fastcall SilenceIndex(int index)
		JMP_STD(0x752A40);

	//Properties
	PROPERTY_STRING(Name, 0x28);

	PROPERTY(float, Volume);			//as in eva.ini
	PROPERTY_STRING(Yuri, 0x9);			//as in eva.ini
	PROPERTY_STRING(Russian, 0x9);		//as in eva.ini
	PROPERTY_STRING(Allied, 0x9);		//as in eva.ini
	PROPERTY(eSoundPriority, Priority);	//as in eva.ini
	PROPERTY(eSoundType, Type);	//as in eva.ini
	PROPERTY(int, unknown_int_50);

private:	//constructor and destructor should never be needed
	VoxClass(){}
	~VoxClass(){}
};


#endif
