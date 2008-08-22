#ifndef CCINI_H
#define CCINI_H

#include <YRPPCore.h>
#include <GenericList.h>
#include <ArrayClasses.h>

class TechnoTypeClass;

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
	byte* Read3Bytes(byte* pBuffer, const char* pSection, const char* pKey, byte* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x474B50); }

	//Writes three byte values.
	bool Write3Bytes(const char* pSection, const char* pKey, byte* pValues)
		{ PUSH_VAR32(pValues); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x474C20); }


	// C&C helpers

#define INI_READ(item, addr) \
	int Read ## item(const char* pSection, const char* pKey, int pDefault) \
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(addr); }

	// Pip= to idx ( pip strings with index < pDefault are not even scanned! )
	INI_READ(Pip, 0x4748A0);

	// PipScale= to idx
	INI_READ(PipScale, 0x474940);

	// Category= to idx
	INI_READ(Category, 0x4749E0);

	// Color=%s to idx
	INI_READ(ColorString, 0x474A90);

	// Foundation= to idx
	INI_READ(Foundation, 0x474DA0);

	// MovementZone= to idx
	INI_READ(MovementZone, 0x474E40);

	// SpeedType= to idx
	INI_READ(SpeedType, 0x476FC0);

	// [SW]Action= to idx
	INI_READ(SWAction, 0x474EE0);

	// [SW]Type= to idx
	INI_READ(SWType, 0x474F50);

	// EVA Event name to idx
	INI_READ(VoxName, 0x474FA0);

	// Factory= to idx
	INI_READ(Factory, 0x474FF0);

	INI_READ(BuildCat, 0x475060);

	// Parses a list of Countries and returns a bitfield, i.e. Owner= or RequiredHouses=
	INI_READ(HouseTypesList, 0x4750D0);

	// Parses a list of Houses and returns a bitfield, i.e. Allies= in map
	INI_READ(HousesList, 0x475260);

	INI_READ(ArmorType, 0x4753F0);

	INI_READ(LandType, 0x4754B0);

	// supports MP names (<Player @ X>) too, wtf
	// ALLOCATES if country name is not found
	// returns idx of country it reads
	INI_READ(HouseType, 0x475540);

	// ALLOCATES if name is not found
	INI_READ(Side, 0x4756F0);

	// returns index of movie with this filename
	INI_READ(Movie, 0x4757D0);

	// map theater
	INI_READ(Theater, 0x475870);

	INI_READ(Theme, 0x4758F0);

	INI_READ(Edge, 0x475980);

	INI_READ(Powerup, 0x4759F0);

	// [Anim]Layer= to idx
	INI_READ(Layer, 0x477050);

	INI_READ(VHPScan, 0x477590);

	// Color=%d,%d,%d to idx , used to parse [Colors]
	byte* ReadColorDDD(byte* pBuffer, const char* pSection, const char* pKey, byte* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x474C70); }

	// 18 bytes
	byte* ReadAbilities(byte* pBuffer, const char* pSection, const char* pKey, byte* pDefault)
		{ PUSH_VAR32(pDefault); PUSH_VAR32(pKey); PUSH_VAR32(pSection); PUSH_VAR32(pBuffer); THISCALL(0x477640); }


	TechnoTypeClass* GetTechnoType(const char* pSection, const char* pKey)
		{ PUSH_VAR32(pKey); PUSH_VAR32(pSection); THISCALL(0x476EB0); }


	// fsldargh who the fuck decided to pass structures by value here
	static TypeList<int>* GetPrerequisites(TypeList<int>* pBuffer, INIClass* pINI, 
		const char* pSection, const char* pKey, TypeList<int> Defaults)

		{ 
			/*
			int eflags; __asm{ pushf } __asm{ pop eflags }
			SUB_ESP(0x1C); __asm{ mov edi, esp } __asm{ lea esi, Defaults }
			__asm{ cld } __asm{ mov ecx, 7 } __asm{ rep movsd }
			__asm{ push eflags } __asm{ popf }
			*/

	#define GETDW() \
		val =* (DWORD* )(&Defaults + offset); \
		PUSH_VAR32(val);

			for(int offset = 6, val = 0; offset; --offset)
			{
				GETDW();
			}

			PUSH_VAR32(pKey);
			PUSH_VAR32(pSection);
			SET_REG32(ecx, pBuffer); SET_REG32(edx, pINI);
			CALL(0x4770E0);
		}

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
