#ifndef CCFILE_H
#define CCFILE_H

#include <GeneralDefinitions.h>
#include <YRAllocator.h>
#include <YRPPCore.h>

//--------------------------------------------------------------------
//Abstract File class
//--------------------------------------------------------------------
class FileClass
		{
public:
	//Destructor
	virtual ~FileClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x65C610); }
	//FileClass
	virtual const char* GetFileName()=0;
	virtual const char* SetFileName(const char* pFileName)=0;
	virtual int CreateFile()=0;
	virtual int DeleteFile()=0;
	virtual bool Exists(const char* pFileName)=0; //If pFileName is NULL, use own.
	virtual bool HasHandle()=0;
	virtual bool Open(int nFileAccess)=0;
	virtual bool OpenEx(const char* pFileName, int nFileAccess)=0;
	virtual int ReadBytes(void* pBuffer, int nNumBytes)=0; //Returns number of bytes read.
	virtual int MoveFilePointer(int nDistance, DWORD dwMoveMethod)=0; //dwMoveMethod:
																					//0 = SEEK_SET
																					//1 = SEEK_CUR
																					//2 = SEEK_END
	virtual int GetFileSize()=0;
	virtual int WriteBytes(void* pBuffer, int nNumBytes)=0; //Returns number of bytes written.
	virtual void Close()=0;
	virtual DWORD GetFileTime()
		{ return 0; } //LoWORD = FatTime, HiWORD = FatDate
	virtual bool SetFileTime(DWORD FileTime)
		{ return false; }
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)=0;

	FileClass()
		{ };

protected:
	FileClass(bool)
		{ }

	//Properties
	PROPERTY(bool, SkipCDCheck);
	PROPERTY(int, FileAccess); //0 = FILE_ANY_ACCESS
												//1 = FILE_READ_ACCESS
												//2 = FILE_WRITE_ACCESS
} ;

//--------------------------------------------------------------------
//Files in the game directory
//--------------------------------------------------------------------
class RawFileClass : public FileClass
		{
public:
	//Destructor
	virtual ~RawFileClass()
		{ THISCALL(0x65CA00); }
	//FileClass
	virtual const char* GetFileName()
		{ return FileName; }
	virtual const char* SetFileName(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x65CAC0, const char*); }
	virtual int CreateFile()
		{ THISCALL_RET(0x65D150, int); }
	virtual int DeleteFile()
		{ THISCALL_RET(0x65D190, int); }
	virtual bool Exists(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x65CBF0, bool); }
	virtual bool HasHandle()
		{ THISCALL_RET(0x65D420, bool); }
	virtual bool Open(int nFileAccess)
		{ PUSH_VAR32(nFileAccess); THISCALL_RET(0x65CB50, bool); }
	virtual bool OpenEx(const char* pFileName, int nFileAccess)
		{ PUSH_VAR32(nFileAccess); PUSH_VAR32(pFileName); THISCALL_RET(0x65CB30, bool); }
	virtual int ReadBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x65CCE0, int); }
	virtual int MoveFilePointer(int nDistance, DWORD dwMoveMethod)
		{ PUSH_VAR32(dwMoveMethod); PUSH_VAR32(nDistance); THISCALL_RET(0x65CF00, int); }
	virtual int GetFileSize()
		{ THISCALL_RET(0x65D0D0, int); }
	virtual int WriteBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x65CDD0, int); }
	virtual void Close()
		{ THISCALL(0x65CCA0); }
	virtual DWORD GetFileTime()
		{ THISCALL_RET(0x65D1F0, DWORD); }
	virtual bool SetFileTime(DWORD FileTime)
		{ PUSH_VAR32(FileTime); THISCALL_RET(0x65D240, bool); }
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ }

	//Constructor
	RawFileClass(const char* pFileName):FileClass(false)
		{ PUSH_VAR32(pFileName); THISCALL(0x65CA80); }

protected:
	RawFileClass(bool X):FileClass(X)
		{ }
	RawFileClass():FileClass(false)
		{ }

	//Properties
	PROPERTY(int, FilePointer);
	PROPERTY(int, FileSize);
	PROPERTY(HANDLE, Handle);
	PROPERTY(const char*, FileName);
	PROPERTY(short, unknown_short_1C); //FatTime?
	PROPERTY(short, unknown_short_1E); //FatDate?
	PROPERTY(bool, FileNameAllocated);
} ;

//--------------------------------------------------------------------
//Files that get buffered in some way?
//--------------------------------------------------------------------
class BufferIOFileClass : public RawFileClass
		{
public:
	//Destructor
	virtual ~BufferIOFileClass()
		{ THISCALL(0x431B80); }
	//FileClass
	virtual const char* SetFileName(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x431E80, const char* ); }
	virtual bool Exists(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x431F10, bool); }
	virtual bool HasHandle()
		{ THISCALL_RET(0x431F30, bool); }
	virtual bool Open(int nFileAccess)
		{ PUSH_VAR32(nFileAccess); THISCALL_RET(0x431F70, bool); }
	virtual bool OpenEx(const char* pFileName, int nFileAccess)
		{ PUSH_VAR32(nFileAccess); PUSH_VAR32(pFileName); THISCALL_RET(0x431F50, bool); }
	virtual int ReadBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x4322A0, int); }
	virtual int MoveFilePointer(int nDistance, DWORD dwMoveMethod)
		{ PUSH_VAR32(dwMoveMethod); PUSH_VAR32(nDistance); THISCALL_RET(0x4324B0, int); }
	virtual int GetFileSize()
		{ THISCALL_RET(0x4325A0, int); }
	virtual int WriteBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x432050, int); }
	virtual void Close()
		{ THISCALL(0x4325C0); }

	//Constructor
	BufferIOFileClass():RawFileClass(false)
		{ THISCALL(0x431B20); }

protected:
	BufferIOFileClass(bool X):RawFileClass(X)
		{ }

	//Properties
	PROPERTY(bool, unknown_bool_24);
	PROPERTY(bool, unknown_bool_25);
	PROPERTY(bool, unknown_bool_26);
	PROPERTY(bool, unknown_bool_27);
	PROPERTY(bool, unknown_bool_28);
	PROPERTY(bool, unknown_bool_29);
	PROPERTY(DWORD, unknown_2C);
	PROPERTY(DWORD, unknown_30);
	PROPERTY(DWORD, unknown_34);
	PROPERTY(DWORD, unknown_38);
	PROPERTY(DWORD, unknown_3C);
	PROPERTY(DWORD, unknown_40);
	PROPERTY(int, unknown_int_44);
	PROPERTY(int, unknown_int_48);
	PROPERTY(DWORD, unknown_4C);
	PROPERTY(DWORD, unknown_50);
} ;

//--------------------------------------------------------------------
//Files on a CD?
//--------------------------------------------------------------------
class CDFileClass : public BufferIOFileClass
		{
public:
	//Destructor
	virtual ~CDFileClass()
		{ THISCALL(0x535A60); }
	//FileClass
	virtual const char* SetFileName(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x47AE10, const char* ); }
	virtual bool Open(int nFileAccess)
		{ PUSH_VAR32(nFileAccess); THISCALL_RET(0x47AAB0, bool); }
	virtual bool OpenEx(const char* pFileName, int nFileAccess)
		{ PUSH_VAR32(nFileAccess); PUSH_VAR32(pFileName); THISCALL_RET(0x47AF10, bool); }

	//Constructor
	CDFileClass():BufferIOFileClass(false)
		{ THISCALL(0x47AA30); }

protected:
	CDFileClass(bool X):BufferIOFileClass(X)
		{ }

	//Property
	PROPERTY(DWORD, unknown_54);
} ;

//--------------------------------------------------------------------
//Files in MIXes
//--------------------------------------------------------------------
class CCFileClass : public CDFileClass
		{
public:
	//Destructor
	virtual ~CCFileClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x4019A0); }
	//FileClass
	virtual const char* SetFileName(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x473FC0, const char*); }
	virtual bool Exists(const char* pFileName)
		{ PUSH_VAR32(pFileName); THISCALL_RET(0x473C50, bool); }
	virtual bool HasHandle()
		{ THISCALL_RET(0x473CD0, bool); }
	virtual bool Open(int nFileAccess)
		{ PUSH_VAR32(nFileAccess); THISCALL_RET(0x473D10, bool); }
	virtual bool OpenEx(const char* pFileName, int nFileAccess)
		{ PUSH_VAR32(nFileAccess); PUSH_VAR32(pFileName); THISCALL_RET(0x401980, bool); }
	virtual int ReadBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x473B10, int); }
	virtual int MoveFilePointer(int nDistance, DWORD dwMoveMethod)
		{ PUSH_VAR32(dwMoveMethod); PUSH_VAR32(nDistance); THISCALL_RET(0x473BA0, int); }
	virtual int GetFileSize()
		{ THISCALL_RET(0x473C00, int); }
	virtual int WriteBytes(void* pBuffer, int nNumBytes)
		{ PUSH_VAR32(nNumBytes); PUSH_VAR32(pBuffer); THISCALL_RET(0x473AE0, int); }
	virtual void Close()
		{ THISCALL(0x473CE0); }
	virtual DWORD GetFileTime()
		{ THISCALL_RET(0x473E50, DWORD); }
	virtual bool SetFileTime(DWORD FileTime)
		{ PUSH_VAR32(FileTime); THISCALL_RET(0x473F00, bool); }
	virtual void CDCheck(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x473AB0); }

	//Constructor
	CCFileClass():CDFileClass(false)
		{ }
	CCFileClass(const char* pFileName):CDFileClass(false)
		{ PUSH_VAR32(pFileName); THISCALL(0x4739F0); }

protected:
	CCFileClass(bool X):CDFileClass(X)
		{ }

	//Properties
	PROPERTY_STRUCT(Allocator, FileAllocator);
	PROPERTY(DWORD, unknown_64);
	PROPERTY(DWORD, unknown_68);
} ;

//TO BE CREATED WHEN NEEDED
//class RAMFileClass : public FileClass	{ /*...*/} ;

#endif
