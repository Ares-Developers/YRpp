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
	PROPERTY(bool,			SkipCDCheck);
	PROPERTY(int,			FileAccess);
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
	PROPERTY(int,			FilePointer);
	PROPERTY(int,			FileSize);
	PROPERTY(HANDLE,		Handle);
	PROPERTY(const char*,	FileName);
	PROPERTY(short,			unknown_short_1C);	//FatTime?
	PROPERTY(short,			unknown_short_1E);	//FatDate?
	PROPERTY(bool,			FileNameAllocated);
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
	PROPERTY(bool,			unknown_bool_24);
	PROPERTY(bool,			unknown_bool_25);
	PROPERTY(bool,			unknown_bool_26);
	PROPERTY(bool,			unknown_bool_27);
	PROPERTY(bool,			unknown_bool_28);
	PROPERTY(bool,			unknown_bool_29);
	PROPERTY(DWORD,			unknown_2C);
	PROPERTY(DWORD,			unknown_30);
	PROPERTY(DWORD,			unknown_34);
	PROPERTY(DWORD,			unknown_38);
	PROPERTY(DWORD,			unknown_3C);
	PROPERTY(DWORD,			unknown_40);
	PROPERTY(int,			unknown_int_44);
	PROPERTY(int,			unknown_int_48);
	PROPERTY(DWORD,			unknown_4C);
	PROPERTY(DWORD,			unknown_50);
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
	PROPERTY(DWORD,			unknown_54);
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
	PROPERTY_STRUCT(Allocator,		FileAllocator);
	PROPERTY(DWORD,			unknown_64);
	PROPERTY(DWORD,			unknown_68);
};

//TO BE CREATED WHEN NEEDED
//class RAMFileClass : public FileClass{/*...*/};

#endif
