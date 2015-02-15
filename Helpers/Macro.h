#pragma once

#include <Syringe.h>

// In this file: Alternatives to CTRL + H...

// macros DCoder uses and pd dislikes :)

#define GET(clsname, var, reg) \
	clsname var = R->reg<clsname>();

// it's really not a good idea to GET_STACK(not_a_pointer)
// no, really
#define LEA_STACK(clsname, var, offset) \
	clsname var = R->lea_Stack<clsname>(offset);

#define REF_STACK(clsname, var, offset) \
	clsname& var = R->ref_Stack<clsname>(offset);

#define GET_STACK(clsname, var, offset) \
	clsname var = R->Stack<clsname>(offset);

#define GET_BASE(clsname, var, offset) \
	clsname var = R->Base<clsname>(offset);

#define STACK_OFFS(cur_offset, wanted_offset) \
		(cur_offset - wanted_offset)


// swizzle shorthand
#define SWIZZLE(var) \
	SwizzleManagerClass::Instance.Swizzle((void **)&var);


#include <cmath>
// float cmp
#define CLOSE_ENOUGH(x, y) \
	(fabs(x - y) < 0.001)

#define LESS_EQUAL(x, y) \
	((x - y) <= 0.001)
