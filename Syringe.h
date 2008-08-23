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

	DWORD get_EFLAGS()
		{ return flags; }
	void set_EFLAGS(DWORD value)
		{ flags = value; }

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
};

//Use this for DLL export functions
//e.g. EXPORT FunctionName(REGISTERS* R)
#define EXPORT extern "C" __declspec(dllexport) DWORD _cdecl
#define EXPORT_FUNC(name) extern "C" __declspec(dllexport) DWORD _cdecl name (REGISTERS *R)

// for exportfuncs, repeating stuff is annoying :P
#define GET(clsname, var, reg) clsname var = (clsname )R->get_ ## reg ();

#define RET_UNLESS(expr) if(!(expr)) { return 0; }
#define RETZ_UNLESS(expr) if(!(expr)) { return ; }

// please don't mix the two hashmaps in one class

// hashmap of pointers
#define EXT_P_DEFINE(clsname) \
	static stdext::hash_map<clsname*, clsname ## Data*> Ext_p;\
	static void __stdcall Create(clsname*);                   \
	static void __stdcall Delete(clsname*);                   \
	static void __stdcall Load(clsname*, IStream*);           \
	static void __stdcall Save(clsname*, IStream*);           \
	static void __stdcall LoadFromINI(clsname*, CCINIClass*);

#define EXT_P_DECLARE(clsname) \
	typedef stdext::hash_map<clsname*, clsname ## Ext::clsname ## Data*> hashext_p; \
	typedef clsname ## Ext::clsname ## Data ExtData;    \
	hashext_p clsname ## Ext :: Ext_p;

// hashmap of structures
#define EXT_V_DEFINE(clsname) \
	static stdext::hash_map<clsname*, clsname ## Data > Ext_v;\
	static void __stdcall Create(clsname*);                   \
	static void __stdcall Delete(clsname*);                   \
	static void __stdcall Load(clsname*, IStream*);           \
	static void __stdcall Save(clsname*, IStream*);           \
	static void __stdcall LoadFromINI(clsname*, CCINIClass*);

#define EXT_V_DECLARE(clsname) \
	typedef stdext::hash_map<clsname*, clsname ## Ext::clsname ## Data > hashext_v; \
	typedef clsname ## Ext::clsname ## Data ExtData;    \
	hashext_v clsname ## Ext :: Ext_v;

// I'm lazy, so sue me
#define CONTAINS(var, ptr) \
	(var.find(ptr) != var.end())

#define ALLOC(clsname, ptr) \
	clsname *ptr = new clsname();

#define DEALLOC(var, ptr) \
	delete var[ptr]; \
	var.erase(var.find(ptr));

#endif
