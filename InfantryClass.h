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
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//InfantryClass
	virtual bool IsDeployed() const R0;
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

public:

	InfantryTypeClass* Type;
	int            SequenceAnim; //which is currently playing
	TimerStruct unknown_Timer_6C8;
	DWORD          PanicDurationLeft; // set in ReceiveDamage on panicky units
	bool           unknown_bool_6D8;
	bool           Technician;
	bool           unknown_bool_6DA;
	bool           Crawling;
	bool           unknown_bool_6DC;
	bool           unknown_bool_6DD;
	DWORD          unknown_6E0;
	bool           unknown_bool_6E4;
	int            unknown_int_6E8;
	PROTECTED_PROPERTY(DWORD, unused_6EC); //??
};

#endif
