//fuck security, of course nothing here is secure
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <Interfaces.h>
#include <GeneralDefinitions.h>
#include <ArrayClasses.h>

//forward declarations
class HouseClass;

//--- OwnedTiberiumStruct - holds info about how much of each tiberium type is held.
struct OwnedTiberiumStruct
{
	int Tiberium1;
	int Tiberium2;
	int Tiberium3;
	int Tiberium4;
};
//---

//The AbstractClass is the base class of all game objects.
class AbstractClass : public IPersistStream, public IRTTITypeInfo, public INoticeSink, public INoticeSource
{
public:
	//static
	const char* GetClassName()
	{
		return AbstractClass::GetClassName(WhatAmI());
	}

	static const char* GetClassName(eAbstractType abs)
	{
		struct AbsTypeNameAssignment
		{
			char* Name;
			eAbstractType AbsType;
		};

		AbsTypeNameAssignment* ass;
		for(ass = (AbsTypeNameAssignment*)0x816EE0; ass < (AbsTypeNameAssignment*)0x817130; ass++)
		{
			if(ass->AbsType == abs)
				return ass->Name;
		}

		return NULL;
	}

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL(0x410260); }

	virtual ULONG _stdcall AddRef()
		{ return 1; }

	virtual ULONG _stdcall Release()
		{ return 1; }

	//IPersist
    virtual HRESULT _stdcall GetClassID(CLSID* pClassID) = 0;

	//IPersistStream
	virtual HRESULT _stdcall IsDirty()
		{ return bIsDirty ? S_OK: S_FALSE; }

	virtual HRESULT _stdcall Load(IStream* pStm) = 0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) = 0;

	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize)
		{ PUSH_VAR32(pcbSize); PUSH_VAR32(this); CALL(0x4103E0);}

	//IRTTITypeInfo
	virtual eAbstractType _stdcall 
		What_Am_I(){ PUSH_VAR32(this); CALL(0x410210); }

	virtual int _stdcall Fetch_ID()
		{ PUSH_VAR32(this); CALL(0x410220); }

	virtual void _stdcall Create_ID()
		{ PUSH_VAR32(this); CALL(0x410230); }

	//INoticeSink
	virtual bool _stdcall INoticeSink_Unknown(DWORD dwUnknown)
		{ return VARIANT_FALSE; }
	
	//INoticeSource
	virtual void _stdcall INoticeSource_Unknown() { }

	//Destructor
	virtual ~AbstractClass()
		{ THISCALL(0x4101F0); }

	//AbstractClass
	virtual void Init() { }
	virtual void PointerExpired(void* p,bool bUnknown) { }
	virtual eAbstractType WhatAmI() = 0;
	virtual int	Size() = 0;

	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x410410); }

	virtual int	GetOwningHouseIndex()
		{ return -1; }

	virtual HouseClass* GetOwningHouse()
		{ return NULL; }

	virtual int	GetArrayIndex()
		{ return 0; }

	virtual bool IsDead()
		{ return true; }

	virtual CoordStruct* GetCoords(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x4104C0); }

	virtual CoordStruct* GetCoords_(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x4104F0); }

	virtual bool IsOnFloor()
		{ return false; }

	virtual bool IsInAir()
		{ return false; }

	virtual CoordStruct* GetCoords__(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x410540);} 

	virtual void Update() { }

	//Constructor
	AbstractClass()	
		{ THISCALL(0x410170); }

	//non-virtual
	void AnnounceExpiredPointer()
		{ THISCALL(0x7258D0); }

protected:
	AbstractClass(bool){}	//trick to disable base class construction!

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(DWORD, unknown_10);
	PROPERTY(DWORD, AbstractFlags);	//Flags, see ABSFLAGS definitions in GeneralDefinitions.
	PROPERTY(DWORD, unknown_18);
	PROPERTY(DWORD, unknown_1C);
	PROPERTY(bool,  bIsDirty);		//For IUnknown.
};

#endif
