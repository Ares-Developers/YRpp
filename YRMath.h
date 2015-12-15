#pragma once

#include <YRPPCore.h>

#include <type_traits>

#define MATH_FUNC(name, address)\
	inline __declspec(naked) double __cdecl name(double value)\
	{\
		JMP(address);\
	}

namespace Math
{
	constexpr auto const Pi = 3.1415926535897932384626433832795;
	constexpr auto const TwoPi = 6.283185307179586476925286766559;
	constexpr auto const HalfPi = 1.5707963267948966192313216916398;

	constexpr auto const Sqrt2 = 1.4142135623730950488016887242097;

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

	inline constexpr double rad2deg(double rad)
	{
		return rad * 180.0 / Pi;
	}

	inline constexpr double deg2rad(double deg)
	{
		return deg * Pi / 180.0;
	}

	template <typename T>
	inline constexpr int sgn(T val) {
		// http://stackoverflow.com/a/4609795
		return (T(0) < val) - (val < T(0));
	}

	template <typename T>
	using value_return_t = std::remove_cv_t<std::remove_reference_t<T>>;

	template <typename T, typename T2>
	inline auto min(T&& value, T2&& value2)
	{
		if(value2 < value) {
			return static_cast<value_return_t<T>>(value2);
		}
		return value;
	}

	template <typename T, typename T2>
	inline auto max(T&& value, T2&& value2)
	{
		if(value < value2) {
			return static_cast<value_return_t<T>>(value2);
		}
		return value;
	}

	template <typename T, typename TMin, typename TMax>
	inline auto clamp(T&& value, TMin&& min, TMax&& max)
	{
		if(value < min) {
			return static_cast<value_return_t<T>>(min);
		}
		if(max < value) {
			return static_cast<value_return_t<T>>(max);
		}
		return value;
	}
};
