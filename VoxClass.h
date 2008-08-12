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

	static void Play(const char* pName)
	{
		PUSH_IMM(0xFFFFFFFF);
		SET_REG32(edx,0xFFFFFFFF);
		SET_REG32(ecx,pName);
		CALL(0x752700);
	}

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
