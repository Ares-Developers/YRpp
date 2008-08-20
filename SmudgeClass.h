/*
	Smudges
*/

#ifndef SMUDGE_H
#define SMUDGE_H

#include <ObjectClass.h>
#include <SmudgeTypeClass.h>

class SmudgeClass : public ObjectClass
{
public:
	//Static
	static DynamicVectorClass<SmudgeClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x6B4F50);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6B4EA0);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x6B4F00);}

	//Destructor
	virtual ~SmudgeClass()		{THISCALL(0x6B4B40);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_Smudge;}
	virtual int					Size(){return sizeof(SmudgeClass);}

	//ObjectClass
	virtual ObjectTypeClass*	GetType(){return Type;}
	virtual void				Draw(Point2D* pCoords,DWORD dwUnk){}
	virtual bool				SetLayer(eLayer value){PUSH_VAR32(value);THISCALL(0x6B4BE0);}

	//Constructor
	SmudgeClass(SmudgeTypeClass* stype):ObjectClass(false)
													{
													PUSH_VAR32(stype);
													THISCALL(0x6B4A50);
													}

protected:
	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(SmudgeTypeClass*,	Type);

};

#endif
