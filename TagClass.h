#ifndef TAG_H
#define TAG_H

#include <AbstractClass.h>
#include <TriggerClass.h>

//forward declarations
class TagTypeClass; // TODO: define

typedef int eEventKind;

class TagClass : public AbstractClass
{
public:
	enum {AbsID = abs_Tag};

	//Static
	static DynamicVectorClass<TagClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TagClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	TagClass(TagTypeClass *pType) : AbstractClass(false)
		{ JMP_THIS(0x6E4DE0); }

	bool RaiseEvent(eEventKind eventKind, ObjectClass* tagObject, CellStruct loc, bool isRepeating, TechnoClass* source)
		{ JMP_THIS(0x6E53A0); }

	bool IsTriggerRepeating()
		{ JMP_THIS(0x6E57C0); }

protected:
	TagClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TagTypeClass * Type;
	TriggerClass * AttachedTrigger;
	DWORD unknown_2C;
	CellStruct * DefaultCoords;
	char unknown_34;
	bool IsExecuting;
	char unknown_36;
	char unknown_37;
};

#endif
