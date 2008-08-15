#ifndef ASMMACROS_H
#define ASMMACROS_H

#ifdef _MSC_VER

/*
MSVC++
*/

//Set return location - only do it if you know why you do it!

//Push/Pop General Purpose Registers
#define PUSH_GP_REGISTERS	_asm{push eax}\
	_asm{push ecx}\
	_asm{push edx}

#define POP_GP_REGISTERS	_asm{pop edx}\
	_asm{pop ecx}\
	_asm{pop eax}

//Get/set register to a variable
#define GET_REG32(dst,reg)	_asm{mov dst, reg}
#define SET_REG32(reg,src)	_asm{mov reg, src}

#define ZERO_REG(reg)		_asm{xor reg, reg}

#define GET_REG8(dst,reg)	_asm{mov dst, reg}
#define SET_REG8(reg,src)	_asm{mov reg, src}

//Stack pointer operations
#define ADD_ESP(i)		_asm{add esp, i}
#define SUB_ESP(i)		_asm{sub esp, i}

//Push immediate value
#define PUSH_IMM(i)		_asm{push i}

//Push / Pop register
#define PUSH_REG(r)		_asm{push r}
#define POP_REG(r)		_asm{pop r}

//Push a pointer to a variable
#define PUSH_PTR(v)		_asm{lea eax, v}\
		_asm{push eax}

//Push a variable
#define PUSH_VAR32(v)		_asm{mov eax, v}\
		_asm{push eax}
//Push 16bit variable
#define PUSH_VAR16(v)		_asm{movzx eax, v}\
		_asm{push eax}
//Push 8bit variable
#define PUSH_VAR8(v)		_asm{movzx eax, v}\
		_asm{push eax}

//Push 64bit variable
#define PUSH_VAR64(pv)		_asm{mov eax, pv}\
		_asm{mov ecx, [eax+4]}\
		_asm{mov eax, [eax]}\
		_asm{push ecx}\
		_asm{push eax}

//call
#define CALL(pFunction)		_asm{mov eax, pFunction}\
		_asm{call eax}

//redirect a call to an address, keeping the arguments intact
#define REDIRECT_CALL(pFunction)	_asm{add esp, 4}\
		_asm{mov eax, pFunction}\
		_asm{call eax}

//THISCALL macros
#define THISCALL(pFunction)	_asm{mov ecx, this}\
		_asm{mov eax, pFunction}\
		_asm{call eax}

#define THISCALL_EX(pThis,pFunction)\
		_asm{mov ecx, pThis}\
		_asm{mov eax, pFunction}\
		_asm{call eax}

#define THISCALL_VT(vt_offs)_asm{mov ecx, this}\
		_asm{mov eax, [ecx]}\
		_asm{call dword ptr [eax+vt_offs]}

#define THISCALL_EX_VT(pThis,vt_offs)	_asm{mov ecx, pThis}\
		_asm{mov edx, [ecx]}\
		_asm{call dword ptr [edx+vt_offs]}

//read or write memory
#define MEM_READ8(dst,mem)		_asm{mov dl, byte ptr ds:mem}\
		_asm{mov dst, dl}
#define MEM_WRITE8(mem,src)		_asm{mov dl, dst}\
		_asm{mov byte ptr ds:mem, dl}

#define MEM_READ16(dst,mem)		_asm{mov dx, word ptr ds:mem}\
		_asm{mov dst, dx}
#define MEM_WRITE16(mem,src)	_asm{mov dx, src}\
		_asm{mov word ptr ds:mem, dx}

#define MEM_READ32(dst,mem)		_asm{mov edx, dword ptr ds:mem}\
		_asm{mov dst, edx}
#define MEM_WRITE32(mem,src)	_asm{mov edx, src}\
		_asm{mov dword ptr ds:mem, edx}
#define MEM_WRITEIMM8(mem,imm)	_asm{mov byte ptr ds:mem, imm}
#define MEM_WRITEIMM16(mem,imm)	_asm{mov word ptr ds:mem, imm}
#define MEM_WRITEIMM32(mem,imm)	_asm{mov dword ptr ds:mem, imm}

#define VAR32_REG(type,name,reg) type name;_asm{mov name, reg}
#define VAR8_REG(type,name,reg) type name;_asm{mov name, reg}

#else

#ifdef __GNUC__

/*
GCC
*/

	//Push/Pop General Purpose Registers
	/*
	define PUSH_GP_REGISTERS	asm("push eax\n");\
		asm("push ecx\n");\
		asm("push edx\n");
	*/
	#define PUSH_GP_REGISTERS   \
	  asm(" push edx \n"        \
	      " push ecx \n"        \
	      " push eax \n"        \
	      :                     \
	      :                     \
	      : )

	/*
	define POP_GP_REGISTERS	asm("pop edx\n");\
		asm("pop ecx\n");\
		asm("pop eax\n");
	*/
	#define POP_GP_REGISTERS   \
	  asm(" pop edx \n"        \
	      " pop ecx \n"        \
	      " pop eax \n"        \
	      :                    \
	      :                    \
	      : )

	//Get/set register to a variable
	//define GET_REG32(dst,reg)	asm("mov dst, reg\n");
	#define GET_REG32(dst, reg) \
	  asm(" mov %0, "#reg "\n"  \
	      : "=r"(dst)           \
	      :                     \
	      : )

	//define SET_REG32(reg,src)	asm("mov reg, src\n");
	#define SET_REG32(reg, src) \
	  asm(" mov "#reg", %0 \n"  \
	      :                     \
	      : "r"(src)            \
	      : #reg)

	//define ZERO_REG(reg)		_asm{xor reg, reg}
	#define ZERO_REG(reg)           \
	  asm(" xor "#reg", "#reg" \n"  \
	      :                         \
	      :                         \
	      : #reg)


	//define GET_REG8(dst,reg)	asm("mov dst, reg\n");
	#define GET_REG8(dst, reg) \
	  asm(" mov %0, "#reg" \n" \
	      : "=q"(dst)          \
	      :                    \
	      : )

	//define SET_REG8(reg,src)	asm("mov reg, src\n");
	#define SET_REG8(reg, src) \
	  asm(" mov "#reg", %0 \n" \
	      :                    \
	      : "q"((byte)src)     \
	      : )

	//Stack pointer operations
	//define ADD_ESP(i)		asm("add esp, i\n");
	#define ADD_ESP(i)       \
	  asm(" add esp, %0\n"   \
	      :                  \
	      : "i"(i)           \
	      : )

	//define SUB_ESP(i)		asm("sub esp, i\n");
	#define SUB_ESP(i)       \
	  asm(" sub esp, %0\n"   \
	      :                  \
	      : "i"(i)           \
	      : )

	//Push immediate value
	//define PUSH_IMM(i)		asm("push i\n");
	#define PUSH_IMM(i)      \
	  asm(" push %0\n"       \
	      :                  \
	      : "r"(i)           \
	      : "0")

	//Push / Pop register
	//define PUSH_REG(r)		asm("push r\n");
	#define PUSH_REG(r)      \
	  asm(" push "#r"\n"     \
	      :                  \
	      :                  \
	      : )

	//define POP_REG(r)		asm("pop r\n");
	#define POP_REG(r)       \
	  asm(" pop "#r"\n"      \
	      :                  \
	      :                  \
	      : )

	//Push a pointer to a variable
	/*
	define PUSH_PTR(v)		asm("lea eax, v\n");\
		asm("push eax\n");
	*/
	#define PUSH_PTR(v)      \
	  asm(" push eax\n"      \
	      :                  \
	      : "a"(&v)          \
	      : )

	//Push a variable
	/*
	define PUSH_VAR32(v)		asm("mov eax, v\n");\
		asm("push eax\n");
	*/
	#define PUSH_VAR32(v)      \
	  asm(" push %0\n"         \
	      :                    \
	      : "q"(v)             \
	      : )

	//Push 16bit variable
	/*
	define PUSH_VAR16(v)		asm("movzx eax, v\n");\
		asm("push eax\n");
	*/
	#define PUSH_VAR16(v)      \
	  asm(" movzx eax , %0 \n" \
	      " push eax\n"        \
	      :                    \
	      : "q"((short)v)      \
	      : "eax")

	//Push 8bit variable
	/*define PUSH_VAR8(v)		asm("movzx eax, v\n");\
		asm("push eax\n");
	*/
	#define PUSH_VAR8(v)       \
	  asm(" movzx eax , %0 \n" \
	      " push eax\n"        \
	      :                    \
	      : "q"((byte)v)       \
	      : "eax")

	//Push 64bit variable
	/*
	define PUSH_VAR64(pv)		asm("mov eax, pv\n");\
		asm("mov ecx, [eax+4]\n");\
		asm("mov eax, [eax]\n");\
		asm("push ecx\n");\
		asm("push eax\n");
	*/
	#define PUSH_VAR64(pv)       \
	  asm(" mov eax , %0 \n"     \
	      " mov ecx , [eax+4]\n" \
	      " mov eax , [eax]\n"   \
	      " push ecx\n"          \
	      " push eax\n"          \
	      :                      \
	      : "r"(pv)              \
	      : "ecx", "eax")

	//call
	/*
	define CALL(pFunction)		asm("mov eax, pFunction\n");\
		asm("call eax\n");
	*/
	#define CALL(pFunction)   \
	  asm(" call %0\n"        \
	      :                   \
	      : "r"(pFunction)    \
	      : )

	//redirect a call to an address, keeping the arguments intact
	/*
	define REDIRECT_CALL(pFunction)	asm("add esp, 4\n");\
		asm("mov eax, pFunction\n");\
		asm("call eax\n");
	*/
	#define REDIRECT_CALL(pFunction)  \
	  asm(" add esp , 4 \n"           \
	      " mov eax , %0 \n"          \
	      " call eax\n"               \
	      :                           \
	      : "i"(pFunction)            \
	      : "ecx", "eax")

	//THISCALL macros
	/*
	define THISCALL(pFunction)	asm("mov ecx, this\n");\
		asm("mov eax, pFunction\n");\
		asm("call eax\n");
	*/
	#define THISCALL(pFunction)          \
	  asm(" mov ecx , %0 \n"             \
	      " mov eax , %1 \n"             \
	      " call eax\n"                  \
	      :                              \
	      : "r"(this), "i"(pFunction)    \
	      : "ecx", "eax", "edx")

	/*
	define THISCALL_EX(pThis,pFunction)\
		asm("mov ecx, pThis\n");\
		asm("mov eax, pFunction\n");\
		asm("call eax\n");
	*/
	#define THISCALL_EX(pThis, pFunction)   \
	  asm(" mov ecx , %0 \n"                \
	      " mov eax , %1 \n"                \
	      " call eax\n"                     \
	      :                                 \
	      : "r"(pThis), "i"(pFunction)      \
	      : "ecx", "eax")

	/*
	define THISCALL_VT(vt_offs)asm("mov ecx, this\n");\
		asm("mov eax, [ecx]\n");\
		asm("call dword ptr [eax+vt_offs]\n");
	*/
	#define THISCALL_VT(vt_offs)         \
	  asm(" mov ecx , %0 \n"             \
	      " mov eax, [ecx]\n"            \
	      " call dword ptr [eax+%1]\n"   \
	      :                              \
	      : "r"(this), "i"(vt_offs)      \
	      : "edx", "ecx", "eax")

	/*
	define THISCALL_EX_VT(pThis,vt_offs)	\
	                  asm("mov ecx, pThis\n");\
		asm("mov edx, [ecx]\n");\
		asm("call dword ptr [edx+vt_offs]\n");
	*/
	#define THISCALL_EX_VT(pThis, vt_offs)  \
	  asm(" mov ecx , %0 \n"                \
	      " mov edx, [ecx]\n"               \
	      " call dword ptr [edx+%1]\n"      \
	      :                                 \
	      : "r"(pThis), "i"(vt_offs)        \
	      : "edx", "ecx", "eax")

	//read or write memory
	/*
	define MEM_READ8(dst,mem)		asm("mov dl, byte ptr ds:mem\n");\
		asm("mov dst, dl\n");
	*/
	#define MEM_READ8(dst, mem)          \
	  asm(" mov dl , byte ptr ds:%1 \n"  \
	      " mov %0 , dl\n"               \
	      : "=m"(dst)                    \
	      : "m"(mem)                     \
	      : "edx")

	/*
	define MEM_WRITE8(mem,src)		asm("mov dl, dst\n");\
		asm("mov byte ptr ds:mem, dl\n");
	*/
	#define MEM_WRITE8(mem, src)         \
	  asm(" mov edx, %1\n"               \
	      " mov byte ptr ds: %0, edx\n"  \
	      : "=m"(mem)                    \
	      : "q"(src)                     \
	      : "edx")

	/*
	define MEM_READ16(dst,mem)		asm("mov dx, word ptr ds:mem\n");\
		asm("mov dst, dx\n");
	*/
	#define MEM_READ16(dst, mem)         \
	  asm(" mov dx , word ptr ds:%1 \n"  \
	      " mov %0 , dx\n"               \
	      : "=m"(dst)                    \
	      : "m"(mem)                     \
	      : "edx")


	/*
	define MEM_WRITE16(mem,src)	asm("mov dx, src\n");\
		asm("mov word ptr ds:mem, dx\n");
	*/
	#define MEM_WRITE16(mem, src)        \
	  asm(" mov dx, %1\n"                \
	      " mov word ptr ds: %0, edx\n"  \
	      : "=m"(mem)                    \
	      : "r"(src)                     \
	      : "edx")

	/*
	define MEM_READ32(dst,mem)		asm("mov edx, dword ptr ds: #mem \n");\
		asm("mov dst, edx\n");
	*/
	#define MEM_READ32(dst, mem)         \
	  asm(" mov edx, dword ptr [ds:%1] \n" \
	      " mov %0 , edx\n"              \
	      : "=a"(dst)                    \
	      : "a"(mem)                     \
	      : "edx")

	/*
	define MEM_WRITE32(mem,src)	asm("mov edx, src\n");\
		asm("mov dword ptr ds:mem, edx\n");
	*/
	#define MEM_WRITE32(mem, src)        \
	  asm(" mov edx, %1\n"               \
	      " mov dword ptr ds: %0, edx\n" \
	      : "=m"(mem)                    \
	      : "r"(src)                     \
	      : "edx")

	//define MEM_WRITEIMM8(mem,imm)	asm("mov byte ptr ds:mem, imm\n");
	#define MEM_WRITEIMM8(mem, imm)      \
	  asm(" mov byte ptr ds:%0, %1\n"    \
	      : "=m"(mem)                    \
	      : "q"(byte(imm))               \
	      : )

	//define MEM_WRITEIMM16(mem,imm)	asm("mov word ptr ds:mem, imm\n");
	#define MEM_WRITEIMM16(mem, imm)     \
	  asm(" mov word ptr ds:%0, %1\n"    \
	      : "=m"(mem)                    \
	      : "r"(short(imm))              \
	      : )

	//define MEM_WRITEIMM32(mem,imm)	asm("mov dword ptr ds:mem, imm\n");
	#define MEM_WRITEIMM32(mem, imm)     \
	  asm(" mov dword ptr ds:%0, %1\n"   \
	      : "=m"(mem)                    \
	      : "r"(imm)                     \
	      : )

	//define VAR32_REG(type,name,reg) type name;asm("mov name, reg\n");
	#define VAR32_REG(type, name, reg)   \
		type name;                         \
	  asm(" mov %0, "#reg" \n"           \
	      : "=&r"(name)                  \
	      :                              \
	      : )

	//define VAR8_REG(type,name,reg) type name;asm("mov name, reg\n");
	#define VAR8_REG(type, name, reg)    \
		type name;                         \
	  asm(" mov %0, "#reg" \n"           \
	      : "=&q"(name)                  \
	      :                              \
	      : )

#else
#error Unsupported compiler! Supported: Visual Studio, GCC (3.x series so far).
#endif // if gcc

#endif // if !msvc

#endif
