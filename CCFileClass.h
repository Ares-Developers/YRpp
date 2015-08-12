#pragma once

#include <GeneralDefinitions.h>
#include <YRAllocator.h>
#include <YRPPCore.h>
#include <GenericList.h>

enum class FileAccessMode : unsigned int {
	None = 0,
	Read = 1,
	Write = 2,
	ReadWrite = 3
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
	virtual const char* GetFileName() const = 0;
	virtual const char* SetFileName(const char* pFileName) = 0;
	virtual BOOL CreateFile() = 0;
	virtual BOOL DeleteFile() = 0;
	virtual bool Exists(bool writeShared = false) = 0;
	virtual bool HasHandle() = 0;
	virtual bool Open(FileAccessMode access) = 0;
	virtual bool OpenEx(const char* pFileName, FileAccessMode access) = 0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) = 0; //Returns number of bytes read.
	virtual int Seek(int offset, FileSeekMode seek) = 0;
	virtual int GetFileSize() = 0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes) = 0; //Returns number of bytes written.
	virtual void Close() = 0;
	virtual DWORD GetFileTime() R0; //LoWORD = FatTime, HiWORD = FatDate
	virtual bool SetFileTime(DWORD FileTime) R0;
	virtual void CDCheck(DWORD errorCode, bool bUnk, const char* pFilename) = 0;

	void* ReadWholeFile()
		{ JMP_THIS(0x4A3890); }

	template <typename T>
	bool Read(T& obj, int size = sizeof(T)) {
		return this->ReadBytes(&obj, size) == size;
	}

	template <typename T>
	bool Write(T& obj, int size = sizeof(T)) {
		return this->WriteBytes(&obj, size) == size;
	}

protected:
	explicit __forceinline FileClass(noinit_t)
	{ }

	//Properties

public:
	bool SkipCDCheck;
private:
	BYTE padding_5[3];
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
	virtual const char* GetFileName() const override R0;
	virtual const char* SetFileName(const char* pFileName) override R0;
	virtual BOOL CreateFile() override R0;
	virtual BOOL DeleteFile() override R0;
	virtual bool Exists(bool writeShared = false) override R0;
	virtual bool HasHandle() override R0;
	virtual bool Open(FileAccessMode access) override R0;
	virtual bool OpenEx(const char* pFileName, FileAccessMode access) override R0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes) override R0;
	virtual int Seek(int offset, FileSeekMode seek) override R0;
	virtual int GetFileSize() override R0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes) override R0;
	virtual void Close() override RX;
	virtual void CDCheck(DWORD errorCode, bool lUnk, const char* pFilename) override RX;

	//Constructor
	RawFileClass(const char* pFileName)
		: RawFileClass(noinit_t())
	{ JMP_THIS(0x65CA80); }

protected:
	explicit __forceinline RawFileClass(noinit_t)
		: FileClass(noinit_t())
	{ }

	//Properties

public:
	FileAccessMode FileAccess;
	int FilePointer;
	int FileSize;
	HANDLE Handle;
	const char* FileName;
	short unknown_short_1C;	//FatTime?
	short unknown_short_1E;	//FatDate?
	bool FileNameAllocated;
private:
	BYTE padding_21[3];
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
	BufferIOFileClass()
		: BufferIOFileClass(noinit_t())
	{ JMP_THIS(0x431B20); }

protected:
	explicit __forceinline BufferIOFileClass(noinit_t)
		: RawFileClass(noinit_t())
	{ }

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
	CDFileClass()
		: CDFileClass(noinit_t())
	{ JMP_THIS(0x47AA30); }

protected:
	explicit __forceinline CDFileClass(noinit_t)
		: BufferIOFileClass(noinit_t())
	{ }

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
	CCFileClass(const char* pFileName)
		: CCFileClass(noinit_t())
	{ JMP_THIS(0x4739F0); }

protected:
	explicit __forceinline CCFileClass(noinit_t)
		: CDFileClass(noinit_t())
	{ }

	//Properties

public:
	MemoryBuffer Buffer;
	DWORD unknown_64;
	DWORD unknown_68;
};

//TO BE CREATED WHEN NEEDED
//class RAMFileClass : public FileClass{/*...*/};
