/*
	Aircraft
*/

#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <FootClass.h>
#include <AircraftTypeClass.h>

//forward declarations

//What are these?
class StageClass : public IFlyControl{ };
class FlasherClass : public StageClass{ };

//AircraftClass
class AircraftClass : public FootClass, public FlasherClass
{
public:
	enum {AbsID = abs_Aircraft};

	//Static
	static DynamicVectorClass<AircraftClass*>* Array;

	//IFlyControl
	virtual int __stdcall Landing_Altitude() R0;
	virtual int __stdcall Landing_Direction() R0;
	virtual long __stdcall Is_Loaded() R0;
	virtual long __stdcall Is_Strafe() R0;
	virtual long __stdcall Is_Fighter() R0;
	virtual long __stdcall Is_Locked() R0;

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//Destructor
	virtual ~AircraftClass() RX;

	//Constructor
	AircraftClass(AircraftTypeClass* pType, HouseClass* pOwner) : FootClass(false)
		{ JMP_THIS(0x413D20); }

protected:
	AircraftClass() : FootClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(AircraftTypeClass*, Type);
	PROPERTY(bool, unknown_bool_6C8);
	PROPERTY(bool, HasPassengers);	//parachutes
	PROPERTY(bool, IsCrashing); // when crashing down, duh
	PROPERTY(DWORD, unknown_6CC);
	PROPERTY(bool, unknown_bool_6D0);
	PROPERTY(bool, unknown_bool_6D1);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(char, unknown_char_6D3);
	PROPERTY(bool, unknown_bool_6D4);
	PROPERTY(bool, unknown_bool_6D5);
};

#endif
