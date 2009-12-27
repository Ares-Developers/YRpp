#ifndef MIXFILE_H
#define MIXFILE_H

#include <GenericList.h>

struct MixHeaderData
{
	DWORD ID;
	DWORD Offset;
	DWORD Size;
};

class MixFileClass : public Node<MixFileClass*>
{
	struct GenericMixFiles
	{
		MixFileClass* RA2MD;
		MixFileClass* RA2;
		MixFileClass* LANGUAGE;
		MixFileClass* LANGMD;
		MixFileClass* THEATER_TEMPERAT;
		MixFileClass* THEATER_TEMPERATMD;
		MixFileClass* THEATER_TEM;
		MixFileClass* GENERIC;
		MixFileClass* GENERMD;
		MixFileClass* THEATER_ISOTEMP;
		MixFileClass* THEATER_ISOTEM;
		MixFileClass* ISOGEN;
		MixFileClass* ISOGENMD;
		MixFileClass* MOVIES02D;
		MixFileClass* UNKNOWN_1;
		MixFileClass* MAIN;
		MixFileClass* CONQMD;
		MixFileClass* CONQUER;
		MixFileClass* CAMEOMD;
		MixFileClass* CAMEO;
		MixFileClass* CACHEMD;
		MixFileClass* CACHE;
		MixFileClass* LOCALMD;
		MixFileClass* LOCAL;
		MixFileClass* NTRLMD;
		MixFileClass* NEUTRAL;
		MixFileClass* MAPSMD02D;
		MixFileClass* MAPS02D;
		MixFileClass* UNKNOWN_2;
		MixFileClass* UNKNOWN_3;
		MixFileClass* SIDEC02DMD;
		MixFileClass* SIDEC02D;
	};

public:
	static List<MixFileClass*>* MIXes;
	static DynamicVectorClass<MixFileClass*>* Array;
	static DynamicVectorClass<MixFileClass*>* Array_Alt;
	static DynamicVectorClass<MixFileClass*>* Maps;
	static DynamicVectorClass<MixFileClass*>* Movies;
	static MixFileClass* MULTIMD;
	static MixFileClass* MULTI;

	static GenericMixFiles* Generics;

	static void Bootstrap()
	{
		JMP_THIS(0x5301A0);
	}

	virtual ~MixFileClass() RX;

	MixFileClass(const char* pFileName) : Node<MixFileClass *>(false)
	{
		PUSH_IMM(0x886980);
		PUSH_VAR32(pFileName);
		THISCALL(0x5B3C20);
	}

protected:
	/*PROPERTY(MixFileClass*, Next);
	PROPERTY(MixFileClass*, Prev);*/
	PROPERTY(const char*, FileName);
	PROPERTY(bool, Blowfish);
	PROPERTY(bool, Encryption);
	PROPERTY(int, CountFiles);
	PROPERTY(int, FileSize);
	PROPERTY(int, FileStartOffset);
	PROPERTY(MixHeaderData*, Headers);
	PROPERTY(int, field_24);
};

#endif
