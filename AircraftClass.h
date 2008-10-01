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
	//Static
	static DynamicVectorClass<AircraftClass*>* Array;

	//IFlyControl
	virtual int _stdcall Landing_Altitude() R0;
	virtual int _stdcall Landing_Direction() R0;
	virtual long _stdcall Is_Loaded() R0;
	virtual long _stdcall Is_Strafe() R0;
	virtual long _stdcall Is_Fighter() R0;
	virtual long _stdcall Is_Locked() R0;

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG _stdcall AddRef() R0;
	virtual ULONG _stdcall Release() R0;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~AircraftClass() RX;

	//AbstractClass
	//ObjectClass
	//MissionClass
	//TechnoClass
	//FootClass

	//Constructor
	AircraftClass(AircraftTypeClass* pType, HouseClass* pOwner):FootClass(false)
		{ PUSH_VAR32(pOwner); PUSH_VAR32(pType); THISCALL(0x413D20); }

protected:
	AircraftClass():FootClass() {}
	AircraftClass(bool X):FootClass(X) {}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(AircraftTypeClass*, Type);
	PROPERTY(bool, unknown_bool_6C8);
	PROPERTY(bool, HasPassengers);	//parachutes
	PROPERTY(bool, unknown_bool_6CA);
	PROPERTY(DWORD, unknown_6CC);
	PROPERTY(bool, unknown_bool_6D0);
	PROPERTY(bool, unknown_bool_6D1);
	PROPERTY(bool, unknown_bool_6D2);
	PROPERTY(char, unknown_char_6D3);
	PROPERTY(bool, unknown_bool_6D4);
	PROPERTY(bool, unknown_bool_6D5);
};

#endif
