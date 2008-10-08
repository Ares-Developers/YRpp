#ifndef MIXFILE_H
#define MIXFILE_H

struct MixHeaderData
{
	DWORD ID;
	DWORD Offset;
	DWORD Size;
};

class MixFileClass : public Node<MixFileClass*>
{
public:
	static List<MixFileClass*>* MIXes;

	virtual ~MixFileClass() RX;

	MixFileClass(const char* pFileName) : Node(false)
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
