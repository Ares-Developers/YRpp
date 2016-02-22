#pragma once

#include <YRPPCore.h>
#include <ArrayClasses.h>
#include <Interfaces.h>

#include <Helpers/CompileTime.h>

class SwizzlePointerClass
{
	DWORD unknown_0; //no idea, only found it being zero
	void* pAnything; //the pointer, to literally any object type

public:
	bool operator==(const SwizzlePointerClass& tOther) const
		{
		return
			(unknown_0 == tOther.unknown_0) &&
			(pAnything == tOther.pAnything);
	}
};

class NOVTABLE SwizzleManagerClass : public ISwizzle
{
public:
	static constexpr reference<SwizzleManagerClass, 0xB0C110u> const Instance{};

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;

	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//ISwizzle
	virtual HRESULT __stdcall Reset() R0;

	virtual HRESULT __stdcall Swizzle(void** pointer) R0;

	virtual HRESULT __stdcall Fetch_Swizzle_ID(void* pointer, long* id) const R0;

	virtual HRESULT __stdcall Here_I_Am(long id, void* pointer) R0;

	virtual HRESULT __stdcall Save_Interface(IStream* stream, IUnknown* pointer) R0;
	virtual HRESULT __stdcall Load_Interface(IStream* stream, GUID* riid, void** pointer) R0;

	virtual HRESULT __stdcall Get_Save_Size(int* psize) const R0;

	//DTOR
	virtual ~SwizzleManagerClass() RX;

	//CTOR
	SwizzleManagerClass()
		: SwizzleManagerClass(noinit_t())
	{ JMP_THIS(0x6CF180); }

protected:
	explicit __forceinline SwizzleManagerClass(noinit_t)
	{ }

public:

	DynamicVectorClass<SwizzlePointerClass> Swizzles_Old;
	DynamicVectorClass<SwizzlePointerClass> Swizzles_New;

};
