#ifndef CCFILE_H
#define CCFILE_H

#include <GeneralDefinitions.h>
#include <YRAllocator.h>
#include <YRPPCore.h>
#include <GenericList.h>

enum class FileAccessMode : unsigned int {
	Any = 0,
	Read = 1,
	Write = 2
};

enum class FileSeekMode : unsigned int {
	Set = 0, // SEEK_SET
	Current = 1, // SEEK_CUR
	End = 2 // SEEK_END
};

//--------------------------------------------------------------------
//Abstract File class
//--------------------------------------------------------------------
class NOVTABLE FileClass
{
public:
	//Destructor
	virtual	~FileClass() RX;
	//FileClass
	virtual const char* GetFileName() = 0;
	virtual const char* SetFileName(const char* pFileName) = 0;
	virtual int CreateFile() = 0;
	virtual int DeleteFile() = 0;
	virtual bool Exists(const char* pFileName) = 0; //If pFileName is NULL, use own.
	virtual bool HasHandle() = 0;
	virtual bool Open(FileAccessMode access) = 0;
	virtual bool OpenEx(const char* pFileName, FileAccessMode access) = 0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) = 0; //Returns number of bytes read.
	virtual int MoveFilePointer(int nDistance, FileSeekMode seek) = 0;
	virtual int GetFileSize() = 0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes) = 0; //Returns number of bytes written.
	virtual void Close() = 0;
	virtual DWORD GetFileTime() R0; //LoWORD = FatTime, HiWORD = FatDate
	virtual bool SetFileTime(DWORD FileTime) R0;
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) = 0;

	FileClass() { };

	void * ReadWholeFile()
		{ JMP_THIS(0x4A3890); }

protected:
	FileClass(bool) { }

	//Properties

public:

	bool SkipCDCheck;
	int FileAccess;
};

//--------------------------------------------------------------------
//Files in the game directory
//--------------------------------------------------------------------
class NOVTABLE RawFileClass : public FileClass
{
public:
	//Destructor
	virtual ~RawFileClass() RX;
	//FileClass
	//FileClass
	virtual const char* GetFileName() override R0;
	virtual const char* SetFileName(const char* pFileName) override R0;
	virtual int CreateFile() override R0;
	virtual int DeleteFile() override R0;
	virtual bool Exists(const char* pFileName) override R0;
	virtual bool HasHandle() override R0;
	virtual bool Open(FileAccessMode access) override R0;
	virtual bool OpenEx(const char* pFileName, FileAccessMode access) override R0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) override R0;
	virtual int MoveFilePointer(int nDistance, FileSeekMode seek) override R0;
	virtual int GetFileSize() override R0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes) override R0;
	virtual void Close() override RX;
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) override RX;

	//Constructor
	RawFileClass(const char* pFileName) : FileClass(false)
		{ JMP_THIS(0x65CA80); }

protected:
	RawFileClass(bool X) : FileClass(X) { }
	RawFileClass() : FileClass(false) { }

	//Properties

public:

	int FilePointer;
	int FileSize;
	HANDLE Handle;
	const char* FileName;
	short unknown_short_1C;	//FatTime?
	short unknown_short_1E;	//FatDate?
	bool FileNameAllocated;
};

//--------------------------------------------------------------------
//Files that get buffered in some way?
//--------------------------------------------------------------------
class NOVTABLE BufferIOFileClass : public RawFileClass
{
public:
	//Destructor
	virtual ~BufferIOFileClass() RX;
	//FileClass

	//Constructor
	BufferIOFileClass() : RawFileClass(false)
		{ JMP_THIS(0x431B20); }

protected:
	BufferIOFileClass(bool X) : RawFileClass(X) { }

	//Properties

public:

	bool unknown_bool_24;
	bool unknown_bool_25;
	bool unknown_bool_26;
	bool unknown_bool_27;
	bool unknown_bool_28;
	bool unknown_bool_29;
	DWORD unknown_2C;
	DWORD unknown_30;
	DWORD unknown_34;
	DWORD unknown_38;
	DWORD unknown_3C;
	DWORD unknown_40;
	int unknown_int_44;
	int unknown_int_48;
	DWORD unknown_4C;
	DWORD unknown_50;
};

//--------------------------------------------------------------------
//Files on a CD?
//--------------------------------------------------------------------
class NOVTABLE CDFileClass : public BufferIOFileClass
{
public:
	//Destructor
	virtual ~CDFileClass() RX;
	//FileClass

	//Constructor
	CDFileClass() : BufferIOFileClass(false)
		{ JMP_THIS(0x47AA30); }

protected:
	CDFileClass(bool X) : BufferIOFileClass(X) { }

	//Property

public:

	DWORD unknown_54;
};

//--------------------------------------------------------------------
//Files in MIXes
//--------------------------------------------------------------------
class NOVTABLE CCFileClass : public CDFileClass
{
public:
	//Destructor
	virtual ~CCFileClass() RX;
	//FileClass

	//Constructor
	CCFileClass() : CDFileClass(false) { }
	CCFileClass(const char* pFileName) : CDFileClass(false)
		{ JMP_THIS(0x4739F0); }

	//Properties

public:

	MemoryBuffer Buffer;
	DWORD unknown_64;
	DWORD unknown_68;
};

//TO BE CREATED WHEN NEEDED
//class RAMFileClass : public FileClass{/*...*/};

#endif
