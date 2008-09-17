/*
	SYRINGE.H
	---------
	Holds macros, structures, classes that are necessary to interact with Syringe correctly.
																						-pd
*/

#ifndef SYRINGE_H
#define SYRINGE_H

#include <windows.h>

//General typedefs
typedef unsigned char BYTE;
typedef unsigned short WORD;

//Macros to make the following a lot easier
#define REG_FUNCS1(n32, n16, n8hi, n8lo, idx) \
	DWORD get_ ## n32 ()\
		{ return regs[idx]; }\
	WORD get_## n16 ()\
		{ return (WORD)(regs[idx] & 0xFFFF); }\
	BYTE get_## n8hi ()\
		{ return (BYTE)((regs[idx] & 0xFFFF) >> 8); }\
	BYTE get_## n8lo ()\
		{ return (BYTE)(regs[idx] & 0xFF); }\
	void set_## n32 (DWORD value)\
		{ regs[idx] = value; }\
	void set_## n16 (WORD value)\
		{ ((WORD*)&regs[idx])[0] = value; }\
	void set_## n8hi (BYTE value)\
		{ ((BYTE*)&regs[idx])[1] = value; }\
	void set_## n8lo (BYTE value)\
		{ ((BYTE*)&regs[idx])[0] = value; }

#define REG_FUNCS2(n32, n16, idx)\
	DWORD get_ ## n32 ()\
		{ return regs[idx]; }\
	WORD get_## n16 ()\
		{ return (WORD)(regs[idx] & 0xFFFF); }\
	void set_## n32 (DWORD value)\
		{ regs[idx] = value; }\
	void set_## n16 (WORD value)\
		{ ((WORD*)&regs[idx])[0] = value; }

//A pointer to this class is passed as an argument to EXPORT functions
class REGISTERS
{
private:
	DWORD	origin;
	DWORD	flags;
	DWORD	regs[8];

public:
	REG_FUNCS1(EAX, AX, AH, AL, 7);
	REG_FUNCS1(ECX, CX, CH, CL, 6);
	REG_FUNCS1(EDX, DX, DH, DL, 5);
	REG_FUNCS1(EBX, BX, BH, BL, 4);
	REG_FUNCS2(ESP, SP, 3);
	REG_FUNCS2(EBP, BP, 2);
	REG_FUNCS2(ESI, SI, 1);
	REG_FUNCS2(EDI, DI, 0);

	DWORD get_Origin()
		{ return origin; }

	DWORD get_EFLAGS()
		{ return flags; }
	void set_EFLAGS(DWORD value)
		{ flags = value; }

	DWORD lea_StackVar(int offset)
		{ return regs[3] + offset; }
	DWORD get_StackVar32(int offset)
		{ return *((DWORD*)regs[3] + (offset >> 2)); }
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
};

//Use this for DLL export functions
//e.g. EXPORT FunctionName(REGISTERS* R)
#define EXPORT extern "C" __declspec(dllexport) DWORD _cdecl
#define EXPORT_FUNC(name) extern "C" __declspec(dllexport) DWORD _cdecl name (REGISTERS *R)

#endif
