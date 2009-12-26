#ifndef SWIZZLEMGR_H
#define SWIZZLEMGR_H

#include <YRPPCore.h>
#include <ArrayClasses.h>
#include <Interfaces.h>

class SwizzlePointerClass
{
	PROPERTY(DWORD, unknown_0); //no idea, only found it being zero
	PROPERTY(void*, pAnything); //the pointer, to literally any object type

public:
	bool operator==(SwizzlePointerClass tOther)
		{
		return
			(unknown_0 == tOther.unknown_0) &&
			(pAnything == tOther.pAnything);
	}
};

class SwizzleManagerClass : public ISwizzle
{
public:
	static SwizzleManagerClass& Instance;

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;

	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//ISwizzle
	virtual HRESULT __stdcall Reset() R0;

	virtual HRESULT __stdcall Swizzle(void** pointer) R0;

	virtual HRESULT __stdcall Fetch_Swizzle_ID(void* pointer, long* id) R0;

	virtual HRESULT __stdcall Here_I_Am(long id, void* pointer) R0;

	virtual HRESULT __stdcall Save_Interface(IStream* stream, IUnknown* pointer) R0;
	virtual HRESULT __stdcall Load_Interface(IStream* stream, GUID* riid, void** pointer) R0;

	virtual HRESULT __stdcall Get_Save_Size(int* psize) R0;

	//CTOR / DTOR
	SwizzleManagerClass() JMP_THIS(0x6CF180);
	virtual ~SwizzleManagerClass() RX;

	//Properties
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, Swizzles_Old);
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, Swizzles_New);

};

#endif
