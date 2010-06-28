/*
	[Colors]
*/

#ifndef COLORSCHEME_H
#define COLORSCHEME_H

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
	static DynamicVectorClass<ColorScheme*>* Array;
/*
 * trap! most schemes are duplicated - ShadeCount 1 and ShadeCount 53
*/
	static ColorScheme* Find(const char* find_id, int ShadeCount = 1)
		{
//			ColorScheme* current=NULL;
			for(int i = 0; i < Array->Count; ++i) {
				ColorScheme *CS = Array->GetItem(i);
				if(!_strcmpi(CS->ID, find_id)) {
					if(CS->ShadeCount == ShadeCount) {
						return Array->GetItem(i);
					}
				}
			}
			return NULL;
		}

	static int FindIndex(const char* find_id)
		{
//			ColorScheme* current=NULL;
			for(int i = 0; i < Array->Count; ++i) {
				if(!_strcmpi(Array->GetItem(i)->ID,find_id)) {
					return i;
				}
			}
			return -1;
		}

	static ColorScheme * __fastcall FindByName(const char *Name, ColorStruct *BaseColor, BytePalette *Pal1, BytePalette *Pal2, int ShadeCount)
		{ JMP_THIS(0x68C9C0); }

	//Constructor, Destructor
	ColorScheme(const char* pID, ColorStruct* BaseColor, DWORD arg8, DWORD argC, DWORD arg10, DWORD arg14)
		{ JMP_THIS(0x68C710); }

	~ColorScheme()
		{ JMP_THIS(0x68C8D0); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int                ArrayIndex;

	BytePalette Colors;

	char*              ID;
	ColorStruct BaseColor;
	LightConvertClass* LightConvert;	//??? remap - indices #16-#31 are changed to mathefuckikally derived shades of BaseColor, think unittem.pal
	int   ShadeCount;
	PROTECTED_PROPERTY(BYTE,     unknown_314[0x1C]);
	int   MainShadeIndex;
	PROTECTED_PROPERTY(BYTE,     unknown_334[0x8]);
};

#endif
