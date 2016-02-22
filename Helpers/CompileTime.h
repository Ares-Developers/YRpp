#pragma once

// defines a compile time pointer to a known memory address
template <typename T, unsigned int Address>
struct constant_ptr {
	using value_type = T*;

	constexpr constant_ptr() noexcept = default;
	constant_ptr(constant_ptr&) = delete;
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

// defines a compile time reference to a known memory address
template <typename T, unsigned int Address, size_t Count = 0>
struct reference {
	using value_type = T[Count];

	static const auto Size = Count;

	constexpr reference() noexcept = default;
	reference(reference&) = delete;
private:
	// mere presence "fixes" C2100: illegal indirection
	constexpr reference(noinit_t) noexcept {}
public:

	value_type& get() const noexcept {
		// fixes" C2101: '&' on constant
		static auto const address = Address;
		return *reinterpret_cast<value_type*>(address);
	}

	operator value_type&() const noexcept {
		return get();
	}

	value_type& operator()() const noexcept {
		return get();
	}

	decltype(auto) operator&() const noexcept {
		return &get();
	}

	decltype(auto) operator*() const noexcept {
		return *get();
	}

	T& operator[](int index) const noexcept {
		return get()[index];
	}

	value_type& data() const noexcept {
		return get();
	}

	size_t size() const noexcept {
		return Size;
	}

	T* begin() const noexcept {
		return data();
	}

	T* end() const noexcept {
		return begin() + Size;
	}
};

// specializations for non-array references
template <typename T, unsigned int Address>
struct reference<T, Address, 0> {
	using value_type = T;

	constexpr reference() noexcept = default;
	reference(reference&) = delete;
private:
	// mere presence "fixes" C2100: illegal indirection
	constexpr reference(noinit_t) noexcept {}
public:

	value_type& get() const noexcept {
		return *reinterpret_cast<value_type*>(Address);
	}

	template <typename T2, typename = std::enable_if_t<std::is_assignable<T&, T2>::value>>
	T& operator=(T2&& rhs) const {
		return get() = std::forward<T2>(rhs);
	}

	operator T&() const noexcept {
		return get();
	}

	T& operator()() const noexcept {
		return get();
	}

	decltype(auto) operator&() const noexcept {
		return &get();
	}

	decltype(auto) operator->() const noexcept {
		return arrow(std::is_pointer<T>::type());
	}

	decltype(auto) operator*() const noexcept {
		return *get();
	}

	decltype(auto) operator[](int index) const noexcept {
		return get()[index];
	}

private:
	auto arrow(std::false_type) const noexcept {
		return &get();
	}

	auto arrow(std::true_type) const noexcept {
		return get();
	}
};
