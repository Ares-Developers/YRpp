/*
	Ground & Naval Vehicles
*/

#ifndef UNIT_H
#define UNIT_H

#include <FootClass.h>
#include <UnitTypeClass.h>

//forward declarations
class EBolt;

class UnitClass : public FootClass
{
public:
	//Static
	static DynamicVectorClass<UnitClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~UnitClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectClass
	//MissionClass

	//TechnoClass

	//FootClass

	//UnitClass
	virtual void DrawVXL(
	  DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
	  DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8)
		{
			PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7); PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5);
			PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
			THISCALL(0x73B470);
		}

	virtual void DrawSHP(
	  DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4,
	  DWORD dwUnk5, DWORD dwUnk6, DWORD dwUnk7, DWORD dwUnk8)
	{
		PUSH_VAR32(dwUnk8); PUSH_VAR32(dwUnk7); PUSH_VAR32(dwUnk6); PUSH_VAR32(dwUnk5);
		PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk);
		THISCALL(0x73C5F0);
	}
	
	//Constructor
	UnitClass(UnitTypeClass* pType, HouseClass* pOwner):FootClass(false)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x7353C0); }

protected:
	UnitClass():FootClass()
		{ }
	UnitClass(bool X):FootClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int, unknown_int_6C0);
	PROPERTY(UnitTypeClass*, Type);
	PROPERTY(DWORD, unknown_6C8);
	PROPERTY(int, FlagHouseIndex); //Carrying the flag of this House
	PROPERTY(bool, Deployed);
	PROPERTY(bool, Unloading);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(bool, unknown_bool_6D3);
	PROPERTY(int, unknown_int_6D4);
	PROPERTY(int, unknown_int_6D8);
	PROPERTY(EBolt*, ElectricBolt); //Unit is the owner of this
	PROPERTY(bool, unknown_bool_6E0);
	PROPERTY(bool, unknown_bool_6E1);
	PROPERTY(bool, unknown_bool_6E2);
	
// isn't this what PROPERTY_UNICODE was for?
protected:
	wchar_t ToolTipText[0x100];

public:
	const wchar_t* get_ToolTipText()
		{ return ToolTipText; }
	void set_ToolTipText(const wchar_t* src)
		{ wcsncpy(ToolTipText, src, 0x100); }
};

#endif
