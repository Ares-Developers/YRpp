#pragma once

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
	static List<MixFileClass*>* const MIXes;
	static DynamicVectorClass<MixFileClass*>* const Array;
	static DynamicVectorClass<MixFileClass*>* const Array_Alt;
	static DynamicVectorClass<MixFileClass*>* const Maps;
	static DynamicVectorClass<MixFileClass*>* const Movies;
	static MixFileClass* const MULTIMD;
	static MixFileClass* const MULTI;

	static GenericMixFiles* const Generics;

	static void Bootstrap()
		{ JMP_THIS(0x5301A0); }

	virtual ~MixFileClass() RX;

	MixFileClass(const char* pFileName)
		: Node<MixFileClass*>(noinit_t())
	{
		PUSH_IMM(0x886980);
		PUSH_VAR32(pFileName);
		THISCALL(0x5B3C20);
	}

protected:
	/*PROPERTY(MixFileClass*, Next);
	MixFileClass* Prev;*/

public:

	const char* FileName;
	bool Blowfish;
	bool Encryption;
	int CountFiles;
	int FileSize;
	int FileStartOffset;
	MixHeaderData* Headers;
	int field_24;
};
