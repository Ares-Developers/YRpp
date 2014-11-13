#ifndef YRMATH_H
#define YRMATH_H

#include <YRPPCore.h>

#define MATH_FUNC(name, address)\
	inline __declspec(naked) double __cdecl name(double value)\
	{\
		JMP(address);\
	}

namespace Math
{
	const double Pi = 3.1415926535897932384626433832795;
	const double TwoPi = 6.283185307179586476925286766559;
	const double HalfPi = 1.5707963267948966192313216916398;

	const double Sqrt2 = 1.4142135623730950488016887242097;

	MATH_FUNC(sqrt,	 0x4CAC40);
	MATH_FUNC(sin,	 0x4CACB0);
	MATH_FUNC(cos,	 0x4CAD00);
	MATH_FUNC(tan,	 0x4CAD50);
	MATH_FUNC(asin,	 0x4CAD80);
	MATH_FUNC(acos,	 0x4CADB0);
	MATH_FUNC(atan,	 0x4CADE0);

	inline __declspec(naked) double __cdecl arctanfoo(double a, double b)
	{
		JMP(0x4CAE30);
	}

	inline double rad2deg(double rad)
	{
		return rad * 180.0 / Pi;
	}

	inline double deg2rad(double deg)
	{
		return deg * Pi / 180.0;
	}
};

#endif
