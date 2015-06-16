/*
	[Colors]
*/

#pragma once

#include <ArrayClasses.h>
#include <GeneralStructures.h>

class LightConvertClass;

class ColorScheme
{
public:
	enum {
		//ColorScheme indices, since they are hardcoded all over the exe, why shan't we do it as well?
		Yellow  =   3,
		White   =   5,
		Grey    =   7,
		Red     =  11,
		Orange  =  13,
		Pink    =  15,
		Purple  =  17,
		Blue    =  21,
		Green   =  29,
	};

	//global array
	static DynamicVectorClass<ColorScheme*>* const Array;
/*
 * trap! most schemes are duplicated - ShadeCount 1 and ShadeCount 53
*/
	static ColorScheme* Find(const char* pID, int ShadeCount = 1) {
		int index = FindIndex(pID, ShadeCount);
		return Array->GetItemOrDefault(index);
	}

	static int FindIndex(const char* pID, int ShadeCount = 1) {
		for(int i = 0; i < Array->Count; ++i) {
			ColorScheme* pItem = Array->GetItem(i);
			if(!_strcmpi(pItem->ID, pID)) {
				if(pItem->ShadeCount == ShadeCount) {
					return i;
				}
			}
		}
		return -1;
	}

	static ColorScheme * __fastcall FindByName(const char* pID, const ColorStruct &BaseColor, const BytePalette &Pal1, const BytePalette &Pal2, int ShadeCount)
		{ JMP_THIS(0x68C9C0); }

	//Constructor, Destructor
	ColorScheme(const char* pID, const ColorStruct &BaseColor, const BytePalette &Pal1, const BytePalette &Pal2, int ShadeCount, bool AddToArray)
		{ JMP_THIS(0x68C710); }

	~ColorScheme()
		{ JMP_THIS(0x68C8D0); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int                ArrayIndex; // this is off by one (always one higher than the actual index). that's because consistency and reason suck.

	BytePalette Colors;

	char*              ID;
	ColorStruct BaseColor;
	LightConvertClass* LightConvert;	//??? remap - indices #16-#31 are changed to mathefuckikally derived shades of BaseColor, think unittem.pal
	int   ShadeCount;
	PROTECTED_PROPERTY(BYTE,     unknown_314[0x1C]);
	int   MainShadeIndex;
	PROTECTED_PROPERTY(BYTE,     unknown_334[0x8]);
};
