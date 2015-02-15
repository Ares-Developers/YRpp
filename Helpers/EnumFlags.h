#pragma once

#include <type_traits>

template <typename T>
struct EnumFlagHelper {
	using type = std::underlying_type_t<T>;

	EnumFlagHelper(T value) {
		this->value = static_cast<type>(value);
	}

	explicit operator bool() const {
		return value != type();
	}

	operator T() const {
		return static_cast<T>(this->value);
	}

	explicit operator type() const {
		return value;
	}

private:

	type value;
};

#define MAKE_ENUM_FLAGS(FLAG_ENUM_NAME) \
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator& (EnumFlagHelper<FLAG_ENUM_NAME> lhs, EnumFlagHelper<FLAG_ENUM_NAME> rhs) { \
		using type = std::underlying_type_t<FLAG_ENUM_NAME>; \
		return static_cast<FLAG_ENUM_NAME>(static_cast<type>(lhs) & static_cast<type>(rhs)); \
	} \
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator& (EnumFlagHelper<FLAG_ENUM_NAME> lhs, FLAG_ENUM_NAME rhs) { \
		return lhs & EnumFlagHelper<FLAG_ENUM_NAME>(rhs); \
	} \
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator& (FLAG_ENUM_NAME lhs, EnumFlagHelper<FLAG_ENUM_NAME> rhs) { \
		return EnumFlagHelper<FLAG_ENUM_NAME>(lhs) & rhs; \
	} \
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator& (FLAG_ENUM_NAME lhs, FLAG_ENUM_NAME rhs) { \
		return EnumFlagHelper<FLAG_ENUM_NAME>(lhs) & rhs; \
	} \
	\
	inline FLAG_ENUM_NAME& operator&= (FLAG_ENUM_NAME &lhs, FLAG_ENUM_NAME rhs) { \
		return lhs = EnumFlagHelper<FLAG_ENUM_NAME>(lhs) & rhs; \
	} \
	\
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator| (EnumFlagHelper<FLAG_ENUM_NAME> lhs, EnumFlagHelper<FLAG_ENUM_NAME> rhs) { \
		using type = std::underlying_type_t<FLAG_ENUM_NAME>; \
		return static_cast<FLAG_ENUM_NAME>(static_cast<type>(lhs) | static_cast<type>(rhs)); \
	} \
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator| (EnumFlagHelper<FLAG_ENUM_NAME> lhs, FLAG_ENUM_NAME rhs) { \
		return lhs | EnumFlagHelper<FLAG_ENUM_NAME>(rhs); \
	} \
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator| (FLAG_ENUM_NAME lhs, EnumFlagHelper<FLAG_ENUM_NAME> rhs) { \
		return EnumFlagHelper<FLAG_ENUM_NAME>(lhs) | rhs; \
	} \
	 \
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator| (FLAG_ENUM_NAME lhs, FLAG_ENUM_NAME rhs) { \
		return EnumFlagHelper<FLAG_ENUM_NAME>(lhs) | rhs; \
	} \
	\
	inline FLAG_ENUM_NAME& operator|= (FLAG_ENUM_NAME &lhs, FLAG_ENUM_NAME rhs) { \
		return lhs = EnumFlagHelper<FLAG_ENUM_NAME>(lhs) | rhs; \
	} \
	\
	\
	inline EnumFlagHelper<FLAG_ENUM_NAME> operator~ (FLAG_ENUM_NAME rhs) { \
		using type = std::underlying_type_t<FLAG_ENUM_NAME>; \
		return static_cast<FLAG_ENUM_NAME>(~static_cast<type>(rhs)); \
	} \

