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
	static SwizzleManagerClass* SwizzleManager()
		{ SwizzleManagerClass* pSwizzleMgr; MEM_READ32(pSwizzleMgr, 0xB0C110); return pSwizzleMgr; }

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject) R0;

	virtual ULONG _stdcall AddRef() R0;
	virtual ULONG _stdcall Release() R0;

	//ISwizzle
	virtual HRESULT _stdcall Reset() R0;

	virtual HRESULT _stdcall Swizzle(void** pointer) R0;

	virtual HRESULT _stdcall Fetch_Swizzle_ID(void* pointer, long* id) R0;

	virtual HRESULT _stdcall Here_I_Am(long id, void* pointer) R0;

	virtual HRESULT _stdcall Save_Interface(IStream* stream, IUnknown* pointer) R0;
	virtual HRESULT _stdcall Load_Interface(IStream* stream, GUID* riid, void** pointer) R0;

	virtual HRESULT _stdcall Get_Save_Size(int* psize) R0;

	//CTOR / DTOR
	SwizzleManagerClass() JMP_THIS(0x6CF180);
	virtual ~SwizzleManagerClass() RX;

	//Properties
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, SwizzlePointers1);
	PROPERTY_STRUCT(DynamicVectorClass<SwizzlePointerClass>, SwizzlePointers2);

};

#endif
