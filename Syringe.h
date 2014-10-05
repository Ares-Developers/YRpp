/*
	SYRINGE.H
	---------
	Holds macros, structures, classes that are necessary to interact with Syringe correctly.
																						-pd
*/

#ifndef SYRINGE_H
#define SYRINGE_H

#include <GeneralDefinitions.h>

#include <Compiler Specifics/hashmap.h>

#include <windows.h>

class LimitedRegister {
protected:
	DWORD data;

	WORD * wordData() {
		return reinterpret_cast<WORD *>(&this->data);
	}

	BYTE * byteData() {
		return reinterpret_cast<BYTE *>(&this->data);
	}

public:
	WORD Get16() {
		return *this->wordData();
	}

	template<typename T>
		inline T Get() {
			return *reinterpret_cast<T*>(&this->data);
		}

	template<typename T>
		inline void Set(T value) {
			this->data = DWORD(value);
		}

	void Set16(WORD value) {
		*this->wordData() = value;
	}

};

class ExtendedRegister : public LimitedRegister {
public:
	BYTE Get8Hi() {
		return (this->byteData())[1];
	}

	BYTE Get8Lo() {
		return (this->byteData())[0];
	}

	void Set8Hi(BYTE value) {
		(this->byteData())[1] = value;
	}

	void Set8Lo(BYTE value) {
		(this->byteData())[0] = value;
	}
};

class StackRegister : public ExtendedRegister {
public:
	template<typename T>
		inline T * lea(signed int byteOffset) {
		return reinterpret_cast<T *>(static_cast<int>(this->data) + byteOffset);
	}

	inline DWORD lea(signed int byteOffset) {
		return static_cast<DWORD>(static_cast<int>(this->data) + byteOffset);
	}

	template<typename T>
		inline T At(signed int byteOffset) {
		return *reinterpret_cast<T *>(static_cast<int>(this->data) + byteOffset);
	}

	template<typename T>
		inline void At(signed int byteOffset, T value) {
		*reinterpret_cast<T *>(static_cast<int>(this->data) + byteOffset) = value;
	}
};

//Macros to make the following a lot easier
#define REG_FUNCS1(n32, n16, n8hi, n8lo, idx) \
public: \
	DWORD get_ ## n32 ()\
		{ return regs[idx]; }\
	WORD get_## n16 ()\
		{ return (WORD)(regs[idx] & 0xFFFF); }\
	BYTE get_## n8hi ()\
		{ return (BYTE)((regs[idx] & 0xFFFF) >> 8); }\
	BYTE get_## n8lo ()\
		{ return (BYTE)(regs[idx] & 0xFF); }\
private: \
	void _set_## n32 (DWORD value)\
		{ regs[idx] = value; }\
	void _set_## n16 (WORD value)\
		{ ((WORD*)&regs[idx])[0] = value; }\
	void _set_## n8hi (BYTE value)\
		{ ((BYTE*)&regs[idx])[1] = value; }\
	void _set_## n8lo (BYTE value)\
		{ ((BYTE*)&regs[idx])[0] = value; }\
public: \
	template <typename T> inline void Set_## n32(T value)\
		{ regs[idx] = reinterpret_cast<DWORD>(value); } \
	template <typename T> inline void Set_## n16(T value)\
		{ ((WORD*)&regs[idx])[0] = reinterpret_cast<WORD>(value); } \
	template <typename T> inline void Set_## n8hi(T value)\
		{ ((BYTE*)&regs[idx])[1] = reinterpret_cast<BYTE>(value); } \
	template <typename T> inline void Set_## n8lo(T value)\
		{ ((BYTE*)&regs[idx])[0] = reinterpret_cast<BYTE>(value); } \

#define REG_FUNCS2(n32, n16, idx) \
public: \
	DWORD Get_ ## n32 () \
		{ return regs[idx]; } \
	WORD Get_## n16 () \
		{ return (WORD)(regs[idx] & 0xFFFF); } \
private: \
	void set_## n32 (DWORD value) \
		{ regs[idx] = value; } \
	void set_## n16 (WORD value) \
		{ ((WORD*)&regs[idx])[0] = value; } \
public: \
	template <typename T> inline void Set_## n32(T value)\
		{ regs[idx] = reinterpret_cast<DWORD>(value); } \
	template <typename T> inline void Set_## n16(T value)\
		{ ((WORD*)&regs[idx])[0] = reinterpret_cast<WORD>(value); } \

#define REG_SHORTCUTS(reg) \
	inline DWORD reg() \
		{ return this->_ ## reg.Get<DWORD>(); } \
	template<typename T> inline T reg() \
		{ return this->_ ## reg.Get<T>(); } \
	template<typename T> inline void reg(T value) \
		{ this->_ ## reg.Set<T>(value); } \

#define REG_SHORTCUTS_X(r) \
	DWORD r ## X() \
		{ return this->_E ## r ## X.Get16(); } \
	void r ## X(WORD value) \
		{ this->_E ## r ## X.Set16(value); } \

#define REG_SHORTCUTS_HL(r) \
	DWORD r ## H() \
		{ return this->_E ## r ## X.Get8Hi(); } \
	void r ## H(BYTE value) \
		{ this->_E ## r ## X.Set8Hi(value); } \
	DWORD r ## L() \
		{ return this->_E ## r ## X.Get8Lo(); } \
	void r ## L(BYTE value) \
		{ this->_E ## r ## X.Set8Lo(value); } \

#define REG_SHORTCUTS_XHL(r) \
	REG_SHORTCUTS_X(r); \
	REG_SHORTCUTS_HL(r); \

//A pointer to this class is passed as an argument to EXPORT functions
class REGISTERS
{
private:
	DWORD	origin;
	DWORD	flags;
//	DWORD	regs[8];

	LimitedRegister _EDI;
	LimitedRegister _ESI;
	StackRegister _EBP;
	StackRegister _ESP;
	ExtendedRegister _EBX;
	ExtendedRegister _EDX;
	ExtendedRegister _ECX;
	ExtendedRegister _EAX;

public:
/*
	REG_FUNCS1(EAX, AX, AH, AL, 7);
	REG_FUNCS1(ECX, CX, CH, CL, 6);
	REG_FUNCS1(EDX, DX, DH, DL, 5);
	REG_FUNCS1(EBX, BX, BH, BL, 4);
	REG_FUNCS2(ESP, SP, 3);
	REG_FUNCS2(EBP, BP, 2);
	REG_FUNCS2(ESI, SI, 1);
	REG_FUNCS2(EDI, DI, 0);
*/

	DWORD get_Origin()
		{ return this->origin; }

	DWORD EFLAGS()
		{ return this->flags; }
	void EFLAGS(DWORD value)
		{ this->flags = value; }

	REG_SHORTCUTS(EAX);
	REG_SHORTCUTS(EBX);
	REG_SHORTCUTS(ECX);
	REG_SHORTCUTS(EDX);
	REG_SHORTCUTS(ESI);
	REG_SHORTCUTS(EDI);
	REG_SHORTCUTS(ESP);
	REG_SHORTCUTS(EBP);

	REG_SHORTCUTS_XHL(A);
	REG_SHORTCUTS_XHL(B);
	REG_SHORTCUTS_XHL(C);
	REG_SHORTCUTS_XHL(D);

	template<typename T>
		inline T lea_Stack(signed int offset)
			{ return reinterpret_cast<T>(this->_ESP.lea(offset)); }

	template<>
		inline DWORD lea_Stack(signed int offset)
			{ return this->_ESP.lea(offset); }

	template<>
		inline int lea_Stack(signed int offset)
			{ return static_cast<int>(this->_ESP.lea(offset)); }

	template<typename T>
		inline T& ref_Stack(signed int offset)
			{ return *this->lea_Stack<T*>(offset); }

	template<typename T>
		inline T Stack(signed int offset)
			{ return this->_ESP.At<T>(offset); }

	DWORD Stack32(signed int offset)
			{ return this->_ESP.At<DWORD>(offset); }
	WORD Stack16(signed int offset)
			{ return this->_ESP.At<WORD>(offset); }
	BYTE Stack8(signed int offset)
			{ return this->_ESP.At<BYTE>(offset); }

	template<typename T>
		inline T Base(signed int offset)
			{ return this->_EBP.At<T>(offset); }

	template<typename T>
		inline void Stack(signed int offset, T value)
			{ this->_ESP.At<T>(offset, value); }

	void Stack16(signed int offset, WORD value)
			{ this->_ESP.At<WORD>(offset, value); }
	void Stack8(signed int offset, BYTE value)
			{ this->_ESP.At<BYTE>(offset, value); }

	template<typename T>
		inline void Base(signed int offset, T value)
			{ this->_EBP.At<T>(offset, value); }

/*
	DWORD lea_StackVar(int offset)
		{ return this->ESP<DWORD>() + offset; }

	DWORD get_StackVar32(int offset)
		{ return *(this->ESP() + (offset >> 2)); }
	WORD get_StackVar16(int offset)
		{ return *((WORD*)regs[3] + (offset >> 1)); }
	BYTE get_StackVar8(int offset)
		{ return *((BYTE*)regs[3] + offset); }
	void set_StackVar32(int offset, DWORD value)
		{ *((DWORD*)regs[3] + (offset >> 2)) = value; }
	void set_StackVar16(int offset, WORD value)
		{ *((WORD*)regs[3] + (offset >> 1)) = value; }
	void set_StackVar8(int offset, BYTE value)
		{ *((BYTE*)regs[3] + offset) = value; }

	DWORD lea_BaseVar(int offset)
		{ return regs[2] + offset; }
	DWORD get_BaseVar32(int offset)
		{ return *((DWORD*)regs[2] + (offset >> 2)); }
	WORD get_BaseVar16(int offset)
		{ return *((WORD*)regs[2] + (offset >> 1)); }
	BYTE get_BaseVar8(int offset)
		{ return *((BYTE*)regs[2] + offset); }
	void set_BaseVar32(int offset, DWORD value)
		{ *((DWORD*)regs[2] + (offset >> 2)) = value; }
	void set_BaseVar16(int offset, WORD value)
		{ *((WORD*)regs[2] + (offset >> 1)) = value; }
	void set_BaseVar8(int offset, BYTE value)
		{ *((BYTE*)regs[2] + offset) = value; }
*/
};

//Use this for DLL export functions
//e.g. EXPORT FunctionName(REGISTERS* R)
#define EXPORT extern "C" __declspec(dllexport) DWORD __cdecl
#define EXPORT_FUNC(name) extern "C" __declspec(dllexport) DWORD __cdecl name (REGISTERS *R)


//Handshake definitions
struct SyringeHandshakeInfo
{
	int cbSize;
	int num_hooks;
	unsigned int checksum;
	DWORD exeFilesize;
	DWORD exeTimestamp;
	unsigned int exeCRC;
	int cchMessage;
	char* Message;
};

#define SYRINGE_HANDSHAKE(pInfo) extern "C" __declspec(dllexport) HRESULT __cdecl SyringeHandshake(SyringeHandshakeInfo* pInfo)


#if SYR_VER == 2

#pragma pack(push, 16)
#pragma warning(push)
#pragma warning( disable : 4324)
__declspec(align(16)) struct hookdecl {
	unsigned int hookAddr;
	unsigned int hookSize;
	const char * hookName;
};

__declspec(align(16)) struct hostdecl {
	unsigned int hostChecksum;
	const char * hostName;
};
#pragma warning(pop)
#pragma pack(pop)

#pragma section(".syhks00", read, write)
#pragma section(".syexe00", read, write)
namespace SyringeData {
	namespace Hooks {

	};
	namespace Hosts {

	};
};

#define declhost(exename, checksum) \
namespace SyringeData { namespace Hosts { __declspec(allocate(".syexe00")) hostdecl _hst__ ## exename = { checksum, #exename }; }; };

#define declhook(hook, funcname, size) \
namespace SyringeData { namespace Hooks { __declspec(allocate(".syhks00")) hookdecl _hk__ ## hook ## funcname = { 0x ## hook, 0x ## size, #funcname }; }; };

#endif // SYR_VER == 2


// create empty macros
#ifndef declhost
#define declhost(exename, checksum)
#endif // declhost

#ifndef declhook
#define declhook(hook, funcname, size)
#endif // declhook

// injgen
// in addition to the injgen-declaration, also includes the function opening
#define DEFINE_HOOK(hook, funcname, size) \
declhook(hook, funcname, size) \
EXPORT_FUNC(funcname)
// no function opening, use for injgen-decl when repeating the same hook at multiple addrs
#define DEFINE_HOOK_AGAIN(hook, funcname, size) \
declhook(hook, funcname, size)

#endif
