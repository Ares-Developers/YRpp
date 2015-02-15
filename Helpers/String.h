#pragma once

// because every project needs an own string implementation...

template <size_t Capacity, typename T = char>
struct FixedString {
	static const size_t Size = Capacity;

	static_assert(Capacity > 0, "Capacity cannot be 0.");

	typedef T data_type[Capacity];

	explicit FixedString(const T* value = nullptr) {
		*this = value;
	}

	/* this is not how the game does it. it most likely has an operator= that
	*  takes a const FixedString&, then memcpys the entire contents over. this
	*  implementation does the same, but gets rid of the temporary object in
	*  case a pointer is passed.
	*/

	const FixedString& operator= (const T* value) {
		if(value != this->chars) {
			if(value) {
				this->assign(value);
			} else {
				this->chars[0] = 0;
			}
		}
		return *this;
	}

	explicit operator bool() {
		return this->chars[0] != 0;
	}

	explicit operator bool() const {
		return this->chars[0] != 0;
	}

	bool operator !() const {
		return this->chars[0] == 0;
	}

	operator const T* () const {
		return this->chars;
	}

	operator T* () {
		return this->chars;
	}

	data_type& data() {
		return this->chars;
	}

	const data_type& data() const {
		return this->chars;
	}

private:
	void assign(const char* value) {
		strncpy_s(this->chars, value, Size - 1);
	}

	void assign(const wchar_t* value) {
		wcsncpy_s(this->chars, value, Size - 1);
	}

	data_type chars;
};

template <size_t Capacity>
using FixedWString = FixedString<Capacity, wchar_t>;
