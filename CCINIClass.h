#ifndef CCINI_H
#define CCINI_H

#include <YRPPCore.h>
#include <GenericList.h>

//Basic INI class
class INIClass
{
public:
	struct INIEntry{ }; //nothing known about this
	struct INISection{ }; //nothing known about this

	INIClass(){ THISCALL(0x535AA0); }
	virtual ~INIClass(){ THISCALL(0x5256F0); }

	void Reset(){ THISCALL(0x526B00); }

	INISection* GetSection(const char* pSection)
		{ PUSH_VAR32(pSection); THISCALL(0x526810); }

	int GetKeyCount(const char* pSection) //Get the amount of keys in a section.
		{ PUSH_VAR32(pSection); THISCALL(0x526960); }
	const char* GetKeyName(const char* pSection, int nKeyIndex) //Get the name of a key number in a section.
		{ PUSH_VAR32(nKeyIndex); PUSH_VAR32(pSection); THISCALL(0x526CC0); }

	//Reads an ANSI string. Returns the string's length.
	int ReadString(const char* pSection, const char* pKey, const char* pDefault, char* pBuffer, size_t szBufferSize)
		{ PUSH_VAR32(szBufferSize); PUSH_VAR32(pBuffer); PUSH_VAR32(pDefault); PUSH_VAR32(pKey);
			PUSH_VAR32(pSection); THISCALL(0x528A10); }
	//Writes an ANSI string.
	bool WriteString(const char* pSection, const char* pKey, const char* pString)
		{ PUSH_VAR32(pString); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x528660); }

	//Reads an boolean value.
	bool ReadBool(const char* pSection, const char* pKey, bool bDefault)
		{ PUSH_VAR8(bDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5295F0); }
	//Writes an boolean value.
	bool WriteBool(const char* pSection, const char* pKey, bool bValue)
		{ PUSH_VAR8(bValue); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x529560); }

	//Reads an integer value.
	int ReadInteger(const char* pSection, const char* pKey, int nDefault)
		{ PUSH_VAR32(nDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5276D0); }
	//Writes an integer value.
	bool WriteInteger(const char* pSection, const char* pKey, int nValue, bool bHex)
		{ PUSH_VAR8(bHex); PUSH_VAR32(nValue); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5276D0); }

	//Reads a decimal value.
	double ReadDouble(const char* pSection, const char* pKey, double dDefault)
		{
			double* pdDefault = &dDefault;
			PUSH_VAR64(pdDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5283D0);
		}
	//Writes a decimal value.
	bool WriteDouble(const char* pSection, const char* pKey, double dValue)
		{
			double* pdValue=&dValue;
			PUSH_VAR64(pdValue); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5285B0);
		}

	//Reads two integer values.
	int* Read2Integers(int* pBuffer, const char* pSection, const char* pKey, int* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x529880); }
	//Writes two integer values.
	bool Write2Integers(const char* pSection, const char* pKey, int* pValues)
		{ PUSH_VAR32(pValues); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x5297E0); }

	//Reads three integer values.
	int* Read3Integers(int* pBuffer, const char* pSection, const char* pKey, int* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x529CA0); }

	//Reads three byte values.
	int* Read3Bytes(byte* pBuffer, const char* pSection, const char* pKey, byte* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x474B50); }

	//Writes three byte values.
	bool Write3Bytes(const char* pSection, const char* pKey, byte* pValues)
		{ PUSH_VAR32(pValues); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x474C20); }


	//Properties
	PROPERTY(DWORD, unknown_4);
	PROPERTY(DWORD, unknown_8);
	PROPERTY_STRUCT(GenericList<INISection>, Sections);
	PROPERTY(DWORD, unknown_28);
	PROPERTY(DWORD, unknown_2C);
	PROPERTY(DWORD, unknown_30);
	PROPERTY(bool, unknown_bool_34);
	PROPERTY(DWORD, unknown_38);
	PROPERTY(DWORD, unknown_3C);
};

//Extended INI class specified for C&C use
class CCINIClass : public INIClass
{
public:
	//STATIC
	static CCINIClass* INI_AI; //0x887128
	static CCINIClass* INI_Art; //0x887180
	static CCINIClass* INI_Rules; //0x887048
	
	//non-static
	CCINIClass() { unknown_bool_40 = false; }
	virtual ~CCINIClass() { THISCALL(0x5256F0); }

	//Parses an INI file from a CCFile
	CCINIClass* ReadCCFile(CCFileClass* pCCFile)
		{ PUSH_IMM(0); PUSH_IMM(0); PUSH_VAR32(pCCFile); THISCALL(0x4741F0); }

	//Copies the string table entry pointed to by the INI value into pBuffer.
	int ReadStringtableEntry(const char* pSection, const char* pKey, wchar_t* pBuffer, size_t szBufferSize)
		{
		  PUSH_VAR32(szBufferSize);
		  PUSH_VAR32(pBuffer);
		  PUSH_VAR32(pKey);
		  PUSH_VAR32(pSection);
		  THISCALL(0x0529160);
		}

	//Properties
	PROPERTY(bool, unknown_bool_40);
	
protected:
	DWORD align_44, align_48, align_4C, align_50, align_54;
};

#endif
