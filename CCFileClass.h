#ifndef CCFILE_H
#define CCFILE_H

#include <GeneralDefinitions.h>
#include <YRAllocator.h>
#include <YRPPCore.h>
#include <GenericList.h>

class eFileMode {
	public:
		enum FileAccess {
			Any = 0,
			Read = 1,
			Write = 2
		};
	public:
		enum MoveMethod {
			FromBeginning = 0,
			FromCurrent= 1,
			FromEnd = 2
		};
};

//--------------------------------------------------------------------
//Abstract File class
//--------------------------------------------------------------------
class FileClass
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
	virtual bool Open(eFileMode::FileAccess nFileMode) = 0;
	virtual bool OpenEx(const char* pFileName, eFileMode::FileAccess nFileAccess) = 0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) = 0; //Returns number of bytes read.
	virtual int MoveFilePointer(int nDistance, eFileMode::MoveMethod nMoveMethod) = 0;
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
class RawFileClass : public FileClass
{
public:
	//Destructor
	virtual ~RawFileClass() RX;
	//FileClass
	//FileClass
	virtual const char* GetFileName() R0;
	virtual const char* SetFileName(const char* pFileName) R0;
	virtual int CreateFile() R0;
	virtual int DeleteFile() R0;
	virtual bool Exists(const char* pFileName) R0;
	virtual bool HasHandle() R0;
	virtual bool Open(eFileMode::FileAccess nFileAccess) R0;
	virtual bool OpenEx(const char* pFileName, eFileMode::FileAccess nFileAccess) R0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) R0;
	virtual int MoveFilePointer(int nDistance, eFileMode::MoveMethod dwMoveMethod) R0;
	virtual int GetFileSize() R0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes) R0;
	virtual void Close() RX;
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;

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
class BufferIOFileClass : public RawFileClass
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
class CDFileClass : public BufferIOFileClass
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
class CCFileClass : public CDFileClass
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

	Allocator FileAllocator;
	DWORD unknown_64;
	DWORD unknown_68;
};

//TO BE CREATED WHEN NEEDED
//class RAMFileClass : public FileClass{/*...*/};

#endif
