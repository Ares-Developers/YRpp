#ifndef SWIZZLEMGR_H
#define SWIZZLEMGR_H

#include <YRPPCore.h>
#include <ArrayClasses.h>

class SwizzlePointerClass
{
	PROPERTY(DWORD, unknown_0); //no idea, only found it being zero
	PROPERTY(void*, pAnything); //the pointer, to literally any object type

public:
	bool operator==(SwizzlePointerClass tOther)
		{
		return
			(unknown_0 == tOther.get_unknown_0()) &&
			(pAnything == tOther.get_pAnything());
	}
};

class SwizzleManagerClass : public ISwizzle
{
public:
	static SwizzleManagerClass* SwizzleManager()
		{ SwizzleManagerClass* pSwizzleMgr; MEM_READ32(pSwizzleMgr, 0xB0C110); return pSwizzleMgr; }

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL(0x6CF430); }

	virtual ULONG _stdcall AddRef(){ return 1; }
	virtual ULONG _stdcall Release(){ return 1; }

	//ISwizzle
	virtual HRESULT _stdcall Reset()
		{ PUSH_VAR32(this); THISCALL(0x6CF230); }

	virtual HRESULT _stdcall Swizzle(void** pointer)
		{ PUSH_VAR32(pointer); PUSH_VAR32(this); THISCALL(0x6CF240); }

	virtual HRESULT _stdcall Fetch_Swizzle_ID(void* pointer, long* id)
		{ PUSH_VAR32(id); PUSH_VAR32(pointer); PUSH_VAR32(this); CALL(0x6CF490); }

	virtual HRESULT _stdcall Here_I_Am(long id, void* pointer)
		{ PUSH_VAR32(pointer); PUSH_VAR32(id); PUSH_VAR32(this); CALL(0x6CF2C0); }

	virtual HRESULT _stdcall Save_Interface(IStream* stream, IUnknown* pointer){ return E_NOTIMPL; }
		virtual HRESULT _stdcall Load_Interface(IStream* stream, GUID* riid, void** pointer){ return E_NOTIMPL; }

	virtual HRESULT _stdcall Get_Save_Size(int* psize)
		{ PUSH_VAR32(psize); PUSH_VAR32(this); THISCALL(0x6CF410); }

	//CTOR / DTOR
	SwizzleManagerClass(){ THISCALL(0x6CF180); }
	virtual ~SwizzleManagerClass(){ THISCALL(0x6CF1D0); } // gcc requires

	//Properties
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, SwizzlePointers1);
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, SwizzlePointers2);

};

#endif
