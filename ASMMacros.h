#ifndef ASMMACROS_H
#define ASMMACROS_H

#ifdef _MSC_VER

/*
MSVC++
*/

//Jump
#define JMP(address) \
	_asm{mov eax, address} \
	_asm{jmp eax}

//MSVC++ stackframes
#define EPILOG_THISCALL \
	_asm{pop ecx} \
	_asm{mov esp, ebp} \
	_asm{pop ebp}

#define JMP_THIS(address) \
	{ EPILOG_THISCALL; \
	JMP(address); }

#define EPILOG_STDCALL \
	_asm{mov esp, ebp} \
	_asm{pop ebp}

#define JMP_STD(address) \
	{ EPILOG_STDCALL; \
	JMP(address); }

//Get/set register to a variable
#define GET_REG32(dst,reg) _asm{mov dst, reg}
#define SET_REG32(reg,src) _asm{mov reg, src}

#define ZERO_REG(reg) _asm{xor reg, reg}

#define GET_REG8(dst,reg) _asm{mov dst, reg}
#define SET_REG8(reg,src) _asm{mov reg, src}

//Stack pointer operations
#define ADD_ESP(i) _asm{add esp, i}
#define SUB_ESP(i) _asm{sub esp, i}

//Push immediate value
#define PUSH_IMM(i) _asm{push i}

//Push / Pop register
#define PUSH_REG(r) _asm{push r}
#define POP_REG(r) _asm{pop r}

//Push a pointer to a variable
#define PUSH_PTR(v) \
		_asm{lea eax, v}\
		_asm{push eax}

//Push a variable
#define PUSH_VAR32(v) \
		_asm{mov eax, v}\
		_asm{push eax}

//Push 16bit variable
#define PUSH_VAR16(v) \
		_asm{movzx eax, v}\
		_asm{push eax}

//Push 8bit variable
#define PUSH_VAR8(v) \
		_asm{movzx eax, v}\
		_asm{push eax}

//Push 64bit variable
#define PUSH_VAR64(pv) \
		_asm{mov eax, pv}\
		_asm{mov ecx, [eax+4]}\
		_asm{mov eax, [eax]}\
		_asm{push ecx}\
		_asm{push eax}

//call
#define CALL(pFunction) \
		_asm{mov eax, pFunction}\
		_asm{call eax}

//THISCALL macros
#define THISCALL(pFunction) \
		_asm{mov ecx, this}\
		_asm{mov eax, pFunction}\
		_asm{call eax}

#define THISCALL_EX(pThis,pFunction) \
		_asm{mov ecx, pThis}\
		_asm{mov eax, pFunction}\
		_asm{call eax}

#define THISCALL_VT(vt_offs) \
		_asm{mov ecx, this}\
		_asm{mov eax, [ecx]}\
		_asm{call dword ptr [eax+vt_offs]}

#define CALL_VT(vt_offs) \
		_asm{mov eax, [ecx]}\
		_asm{call dword ptr [eax+vt_offs]}

#define THISCALL_EX_VT(pThis,vt_offs) \
		_asm{mov ecx, pThis}\
		_asm{mov edx, [ecx]}\
		_asm{call dword ptr [edx+vt_offs]}

//read or write memory
#define MEM_READ8(dst,mem) \
		_asm{mov dl, byte ptr ds:mem}\
		_asm{mov dst, dl}
#define MEM_WRITE8(mem,src) \
		_asm{mov dl, dst}\
		_asm{mov byte ptr ds:mem, dl}

#define MEM_READ16(dst,mem) \
		_asm{mov dx, word ptr ds:mem}\
		_asm{mov dst, dx}
#define MEM_WRITE16(mem,src) \
		_asm{mov dx, src}\
		_asm{mov word ptr ds:mem, dx}

#define MEM_READ32(dst,mem) \
		_asm{mov edx, dword ptr ds:mem}\
		_asm{mov dst, edx}
#define MEM_WRITE32(mem,src) \
		_asm{mov edx, src}\
		_asm{mov dword ptr ds:mem, edx}

#define MEM_WRITEIMM8(mem,imm)	_asm{mov byte ptr ds:mem, imm}
#define MEM_WRITEIMM16(mem,imm)	_asm{mov word ptr ds:mem, imm}
#define MEM_WRITEIMM32(mem,imm)	_asm{mov dword ptr ds:mem, imm}

#define VAR32_REG(type,name,reg) type name;_asm{mov name, reg}
#define VAR8_REG(type,name,reg) type name;_asm{mov name, reg}

#else

#ifdef __GNUC__
//error GCC is not supported! See <yrpp>/gcc_fixes.h for the reason why.
#define JMP(address)
#define EPILOG_THISCALL
#define JMP_THIS(address)
#define EPILOG_STDCALL
#define JMP_STD(address)
#define GET_REG32(dst,reg)
#define SET_REG32(reg,src)
#define ZERO_REG(reg)
#define GET_REG8(dst,reg)
#define SET_REG8(reg,src)
#define ADD_ESP(i)
#define SUB_ESP(i)
#define PUSH_IMM(i)
#define PUSH_REG(r)
#define POP_REG(r)
#define PUSH_PTR(v)
#define PUSH_VAR32(v)
#define PUSH_VAR16(v)
#define PUSH_VAR8(v)
#define PUSH_VAR64(pv)
#define CALL(pFunction)
#define THISCALL(pFunction)
#define THISCALL_EX(pThis,pFunction)
#define THISCALL_VT(vt_offs)
#define CALL_VT(vt_offs)
#define THISCALL_EX_VT(pThis,vt_offs)
#define MEM_READ8(dst,mem)
#define MEM_WRITE8(mem,src)
#define MEM_READ16(dst,mem)
#define MEM_WRITE16(mem,src)
#define MEM_READ32(dst,mem)
#define MEM_WRITE32(mem,src)
#define MEM_WRITEIMM8(mem,imm)
#define MEM_WRITEIMM16(mem,imm)
#define MEM_WRITEIMM32(mem,imm)
#define VAR32_REG(type,name,reg)
#define VAR8_REG(type,name,reg)
#else
#error Unsupported compiler! Supported: Microsoft Visual Studio.
#endif // if !msvc

#endif

#endif
