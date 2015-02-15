#pragma once

#include <Objbase.h>

class YRComHelpers {
public:
	// releases the object and clears the pointer
	template<typename T>
	static void Release(T* &ptr) {
		if(ptr) {
			ptr->Release();
			ptr = nullptr;
		}
	}

	// copies an object from source to target, maintaining
	// a proper reference count.
	template<typename T>
	static void Copy(T* &target, T* &source) {
		auto old = target;
		if(target != source) {
			target = source;
			if(source) {
				source->AddRef();
			}
			Release(old);
		}
	}

	// moves an object from source to target and clears the source
	template<typename T>
	static void Move(T* &target, T* &source) {
		Copy(target, source);
		Release(source);
	}

	template <typename T>
	static HRESULT CreateInstance(const IID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, T* &rpv) {
		static_assert(std::is_base_of<IUnknown, T>::value, "T has to be derived from IUnknown.");

		Release(rpv);
		return CreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(T), reinterpret_cast<LPVOID*>(&rpv));
	}

	static HRESULT CreateInstance(const IID& rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, const IID& riid, LPVOID* ppv) {
		if(dwClsContext & (CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)) {
			IUnknown* pIUnknown = nullptr;
			HRESULT hr = CoCreateInstance(rclsid, pUnkOuter, dwClsContext, __uuidof(IUnknown), reinterpret_cast<LPVOID*>(&pIUnknown));
			if(SUCCEEDED(hr)) {
				hr = OleRun(pIUnknown);
				if(SUCCEEDED(hr)) {
					hr = pIUnknown->QueryInterface(riid, ppv);
				}
				pIUnknown->Release();
			}
			return hr;
		} else {
			return CoCreateInstance(rclsid, pUnkOuter, dwClsContext, riid, ppv);
		}
	}
};
