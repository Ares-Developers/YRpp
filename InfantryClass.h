/*
	Infantry
*/

#ifndef INFANTRY_H
#define INFANTRY_H

#include <FootClass.h>
#include <InfantryTypeClass.h>

class InfantryClass : public FootClass
{
public:
	enum {AbsID = abs_Infantry};

	//Static
	static DynamicVectorClass<InfantryClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~InfantryClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//InfantryClass
	virtual bool IsDeployed() R0;
	virtual bool PlayAnim(int nAnimNumber, bool bUnk, DWORD dwUnk) R0;

	//Constructor
	InfantryClass(InfantryTypeClass* pType, HouseClass* pOwner) : FootClass(false)
		{ JMP_THIS(0x517A50); }

protected:
	InfantryClass() : FootClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(InfantryTypeClass*, Type);
	PROPERTY(int,            SequenceAnim); //which is currently playing
	PROPERTY_STRUCT(TimerStruct,    unknown_Timer_6C8);
	PROPERTY(DWORD,          PanicDurationLeft); // set in ReceiveDamage on panicky units
	PROPERTY(bool,           unknown_bool_6D8);
	PROPERTY(bool,           Technician);
	PROPERTY(bool,           unknown_bool_6DA);
	PROPERTY(bool,           Crawling);
	PROPERTY(bool,           unknown_bool_6DC);
	PROPERTY(bool,           unknown_bool_6DD);
	PROPERTY(DWORD,          unknown_6E0);
	PROPERTY(bool,           unknown_bool_6E4);
	PROPERTY(int,            unknown_int_6E8);
	PROTECTED_PROPERTY(DWORD, unused_6EC); //??
};

#endif
