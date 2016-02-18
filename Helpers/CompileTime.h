#pragma once

// defines a compile time pointer to a known memory address
template <typename T, unsigned int Address>
struct constant_ptr {
	using value_type = T*;

	constexpr constant_ptr() noexcept = default;
private:
	// mere presence "fixes" C2100: illegal indirection
	constexpr constant_ptr(noinit_t) noexcept {}
public:

	value_type get() const noexcept {
		return reinterpret_cast<value_type>(Address);
	}

	operator value_type() const noexcept {
		return get();
	}

	value_type operator()() const noexcept {
		return get();
	}

	value_type operator->() const noexcept {
		return get();
	}

	T& operator*() const noexcept {
		return *get();
	}
};
