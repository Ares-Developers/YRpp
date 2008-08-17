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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL_RET(0x6B58D0, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x6B5850, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x6B58B0, HRESULT); }

	//Destructor
	virtual ~SmudgeTypeClass()	{THISCALL(0x6B53A0);};

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_SmudgeType;}
	virtual int					Size(){return sizeof(SmudgeTypeClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x6B57F0);}
	virtual int					GetArrayIndex(){return ArrayIndex;}

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{PUSH_VAR32(pINI);THISCALL_RET(0x6B56D0, bool); }

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner)
		{PUSH_VAR32(pOwner);PUSH_VAR32(pMapCoords);THISCALL_RET(0x6B5550, bool); }
	virtual ObjectClass* CreateObject(HouseClass* pOwner)
		{PUSH_VAR32(pOwner);THISCALL_RET(0x6B55C0, ObjectClass*); }

	//SmudgeTypeClass
	virtual void				vt_entry_A0(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3,DWORD dwUnk4,DWORD dwUnk5)
								{PUSH_VAR32(dwUnk5);PUSH_VAR32(dwUnk4);PUSH_VAR32(dwUnk3);PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);
								THISCALL(0x6B55F0);}

	//Constructor
	SmudgeTypeClass(const char* pID):ObjectTypeClass(false)
										{PUSH_VAR32(pID);THISCALL(0x6B5260);}

protected:
	SmudgeTypeClass(bool X):ObjectTypeClass(X){};
	SmudgeTypeClass():ObjectTypeClass(false){};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,				ArrayIndex);
	PROPERTY(int,				Width);
	PROPERTY(int,				Height);
	PROPERTY(bool,				Crater);
	PROPERTY(bool,				Burn);
};

#endif
