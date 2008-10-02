/*
	SmudgeTypes are initialized by INI files.
*/

#ifndef SMUDGETYPE_H
#define SMUDGETYPE_H

#include <ObjectTypeClass.h>

class SmudgeTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(SmudgeTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm) R0;
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~SmudgeTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;

	//SmudgeTypeClass
	virtual void vt_entry_A0(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,DWORD dwUnk5) RX;

	//Constructor
	SmudgeTypeClass(const char* pID):ObjectTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x6B5260); }

protected:
	SmudgeTypeClass(bool X):ObjectTypeClass(X){};
	SmudgeTypeClass():ObjectTypeClass(false){};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,  ArrayIndex);
	PROPERTY(int,  Width);
	PROPERTY(int,  Height);
	PROPERTY(bool, Crater);
	PROPERTY(bool, Burn);
};

#endif
