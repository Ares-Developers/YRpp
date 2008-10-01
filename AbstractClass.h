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
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG _stdcall AddRef() R0;
	virtual ULONG _stdcall Release() R0;

	//IPersist
    virtual HRESULT _stdcall GetClassID(CLSID* pClassID) = 0;

	//IPersistStream
	virtual HRESULT _stdcall IsDirty() R0;
	virtual HRESULT _stdcall Load(IStream* pStm) = 0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) = 0;

	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//IRTTITypeInfo
	virtual eAbstractType _stdcall What_Am_I() R0;
	virtual int _stdcall Fetch_ID() R0;
	virtual void _stdcall Create_ID() RX;

	//INoticeSink
	virtual bool _stdcall INoticeSink_Unknown(DWORD dwUnknown) R0;
	
	//INoticeSource
	virtual void _stdcall INoticeSource_Unknown() RX;

	//Destructor
	virtual ~AbstractClass() RX;

	//AbstractClass
	virtual void Init() RX;
	virtual void PointerExpired(void* p,bool bUnknown) RX;
	virtual eAbstractType WhatAmI() = 0;
	virtual int	Size() = 0;
	virtual void CalculateChecksum(void* pChkSum) RX;
	virtual int GetOwningHouseIndex() R0;
	virtual HouseClass* GetOwningHouse() R0;
	virtual int	GetArrayIndex() R0;
	virtual bool IsDead() R0;
	virtual CoordStruct* GetCoords(CoordStruct* pCrd) R0;
	virtual CoordStruct* GetCoords_(CoordStruct* pCrd) R0;
	virtual bool IsOnFloor() R0;
	virtual bool IsInAir() R0;
	virtual CoordStruct* GetCoords__(CoordStruct* pCrd) R0;
	virtual void Update() RX;

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
