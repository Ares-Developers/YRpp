#ifndef DCODER_H
#define DCODER_H

#include <Syringe.h>

// In this file: Alternatives to CTRL + H...

#include <hash_map>
// macros DCoder uses and pd dislikes :)

#define GET(clsname, var, reg) \
	clsname var = R->reg<clsname>();

// it's really not a good idea to GET_STACK(not_a_pointer)
// no, really
#define LEA_STACK(clsname, var, offset) \
	clsname var = R->lea_Stack<clsname>(offset);

#define GET_STACK(clsname, var, offset) \
	clsname var = R->Stack<clsname>(offset);

#define GET_BASE(clsname, var, offset) \
	clsname var = R->Base<clsname>(offset);

#define RET_UNLESS(expr) \
	if(!(expr)) { return 0; }
#define RETZ_UNLESS(expr) \
	if(!(expr)) { return ; }


// buffer length for tags containing a list such as AnimToInfantry=
#define BUFLEN 2048


//define ABS_IS_OBJECT(var) \
//	((var->AbstractFlags & ABSFLAGS_ISOBJECT) != 0)

//define ABS_IS_TECHNO(var) \
//	((var->AbstractFlags & ABSFLAGS_ISTECHNO) != 0)

//define ABS_IS_FOOT(var) \
//	((var->AbstractFlags & ABSFLAGS_ISFOOT) != 0)

// swizzle shorthand
#define SWIZZLE(var) \
	SwizzleManagerClass::Instance.Swizzle((void **)&var);

// debug logging
#ifdef DEBUGBUILD
#define DEBUGLOG(...) \
	Debug::Log(__VA_ARGS__)
#else
#define DEBUGLOG(...) \
	
#endif


// float cmp
#define CLOSE_ENOUGH(x, y) \
	(abs(x - y) < 0.001)

#endif
