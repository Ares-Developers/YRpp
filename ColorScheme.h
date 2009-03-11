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
	//global array
	static DynamicVectorClass<ColorScheme*>* Array;
	static ColorScheme* Find(const char* find_id)
		{
//			ColorScheme* current=NULL;
			for(int i = 0; i < Array->Count; ++i) {
				if(!_strcmpi(Array->GetItem(i)->ID, find_id)) {
					return Array->GetItem(i);
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

	//Constructor, Destructor
	ColorScheme(const char* pID, ColorStruct* BaseColor, DWORD arg8, DWORD argC, DWORD arg10, DWORD arg14)
		JMP_THIS(0x68C710);

	~ColorScheme()
		JMP_THIS(0x68C8D0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,                ArrayIndex);

	protected:
		ColorStruct                Colors[0x100];
	public:
		ColorStruct    get_Color(int i)
			{ return Colors[i]; }
		void           set_Color(int i, ColorStruct value)
			{ Colors[i] = value; }

	PROPERTY(char*,              ID);
	PROPERTY_STRUCT(ColorStruct,        BaseColor);
	PROPERTY(LightConvertClass*, LightConvert);	//???
	PROTECTED_PROPERTY(BYTE,     unknown_310[0x2C]);
};

//ColorScheme indices, since they are hardcoded all over the exe, why shan't we do it as well?
#define	CS_YELLOW		3
#define	CS_WHITE		5
#define	CS_GREY			7
#define	CS_RED			11
#define	CS_ORANGE		13
#define	CS_PINK			15
#define	CS_PURPLE		17
#define	CS_BLUE			21
#define	CS_GREEN		29

#endif
