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
	enum {AbsID = abs_Abstract};

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
			if(ass->AbsType == abs) {
				return ass->Name;
			}
		}

		return NULL;
	}

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) = 0;

	//IPersistStream
	virtual HRESULT __stdcall IsDirty() R0;
	virtual HRESULT __stdcall Load(IStream* pStm) = 0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) = 0;

	virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//IRTTITypeInfo
	virtual eAbstractType __stdcall What_Am_I() R0;
	virtual int __stdcall Fetch_ID() R0;
	virtual void __stdcall Create_ID() RX;

	//INoticeSink
	virtual bool __stdcall INoticeSink_Unknown(DWORD dwUnknown) R0;

	//INoticeSource
	virtual void __stdcall INoticeSource_Unknown() RX;

	//Destructor
	virtual ~AbstractClass() RX;

	//AbstractClass
	virtual void Init() RX;
	virtual void PointerExpired(void* p,bool bUnknown) RX;
	virtual eAbstractType WhatAmI() = 0;
	virtual int Size() = 0;
	virtual void CalculateChecksum(void* pChkSum) RX;
	virtual int GetOwningHouseIndex() R0;
	virtual HouseClass* GetOwningHouse() R0;
	virtual int GetArrayIndex() R0;
	virtual bool IsDead() R0;
	virtual CoordStruct* GetCoords(CoordStruct* pCrd) R0;
	virtual CoordStruct* GetCoords_(CoordStruct* pCrd) R0;
	virtual bool IsOnFloor() R0;
	virtual bool IsInAir() R0;
	virtual CoordStruct* GetCoords__(CoordStruct* pCrd) R0;
	virtual void Update() RX;

	//Constructor
	AbstractClass()
		{ JMP_THIS(0x410170); }

	//non-virtual
	void AnnounceExpiredPointer()
		{ JMP_THIS(0x7258D0); }

protected:
	AbstractClass(bool) { }	//trick to disable further base class construction!

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_10;
	DWORD AbstractFlags;	//Flags, see ABSFLAGS definitions in GeneralDefinitions.
	DWORD unknown_18;
	DWORD unknown_1C;
	bool bIsDirty;		//For IUnknown.
};

#endif
