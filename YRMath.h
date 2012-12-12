#ifndef YRMATH_H
#define YRMATH_H

#include <YRPPCore.h>

#define MATH_FUNC(name, address)\
	static __declspec(noinline) double __cdecl name(double value)\
	{\
		double* p = &value;\
		PUSH_VAR64(p);\
		CALL(address);\
		ADD_ESP(8);\
	}

class Math
{
public:
	static const double Pi;
	static const double TwoPi;
	static const double HalfPi;

	MATH_FUNC(sqrt,	 0x4CAC40);
	MATH_FUNC(sin,	 0x4CACB0);
	MATH_FUNC(cos,	 0x4CAD00);
	MATH_FUNC(tan,	 0x4CAD50);
	MATH_FUNC(asin,	 0x4CAD80);
	MATH_FUNC(acos,	 0x4CADB0);
	MATH_FUNC(atan,	 0x4CADE0);

	static __declspec(noinline) double __cdecl arctanfoo(double a, double b)
	{
		double* p = &a;
		double* r = &b;
		PUSH_VAR64(p);
		PUSH_VAR64(r);
		CALL(0x4CAE30);
		ADD_ESP(16);
	}
};

#endif
