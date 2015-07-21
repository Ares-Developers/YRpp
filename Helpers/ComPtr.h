#pragma once

#include <YRCom.h>
#include <Unsorted.h>

#include <type_traits>

// a managed COM pointer like the game uses it

template <typename T>
struct YRComPtr {
	using pointer = T*;

	static_assert(std::is_base_of<IUnknown, T>::value, "T has to be derived from IUnknown.");

	YRComPtr() : value(pointer()) { }

	explicit YRComPtr(T* pInterface) : value(_addref(pInterface)) { }

	template <typename TIn>
	explicit YRComPtr(TIn* pIUnknown) : value(pointer()) {
		static_assert(std::is_base_of<IUnknown, TIn>::value, "TIn has to be derived from IUnknown.");

		if(pIUnknown) {
			auto hr = pIUnknown->QueryInterface(__uuidof(T), reinterpret_cast<void**>(&this->value));
			this->raise_if_failed(hr);
		}
	}

	YRComPtr(const IID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext = CLSCTX_INPROC_SERVER
		| CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER) : value(pointer())
	{
		HRESULT hr = YRComHelpers::CreateInstance<T>(rclsid, pUnkOuter, dwClsContext, this->value);
		this->raise_if_failed(hr);
	}

	template <typename TIn>
	YRComPtr(const YRComPtr<TIn>& other) : YRComPtr(other.get()) {	}

	YRComPtr(const YRComPtr& other) : YRComPtr(other.value) { }

	YRComPtr(YRComPtr&& other) : value(other.release()) { }

	~YRComPtr() {
		this->_release();
	}

	YRComPtr& operator = (const YRComPtr& other) {
		this->reset(other.value);
		return *this;
	}

	YRComPtr& operator = (YRComPtr&& other) {
		this->_release();
		this->value = other.release();
		return *this;
	}

	explicit operator bool() const {
		return this->value != pointer();
	}

	__forceinline T* operator -> () const {
		this->raise_if_empty();
		return this->value;
	}

	__forceinline T& operator * () const {
		this->raise_if_empty();
		return *this->value;
	}

	T* get() const {
		return this->value;
	}

	T** pointer_to() {
		return &this->value;
	}

	void reset(T* pInterface = pointer()) {
		auto pNew = this->_addref(pInterface);
		this->_release();
		this->value = pNew;
	}

	T* release() {
		auto ret = this->value;
		this->value = pointer();
		return ret;
	}

private:
	T* _addref(T* ptr) {
		if(ptr) {
			ptr->AddRef();
		}
		return ptr;
	}

	void _release() {
		if(this->value) {
			this->value->Release();
		}
	}

	void raise_if_failed(HRESULT hr) const {
		if(FAILED(hr) && hr != E_NOINTERFACE) {
			Game::RaiseError(hr);
		}
	}

	void raise_if_empty() const {
		if(!this->value) {
			Game::RaiseError(E_POINTER);
		}
	}

	T* value;
};
