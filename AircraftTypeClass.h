#ifndef AIRCRAFTTYPE_H
#define AIRCRAFTTYPE_H

#include <TechnoTypeClass.h>

class AircraftTypeClass : public TechnoTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(AircraftTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x41CEB0); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x41CE20); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x41CE90); }

	//Destructor
	virtual ~AircraftTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x41CFE0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_AircraftType; }
	virtual int Size()
		{ return sizeof(AircraftTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x41CDB0); }
	virtual int GetArrayIndex()
		{ return ArrayIndex; }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x41CC20); }

	//ObjectTypeClass
	virtual void vt_entry_7C(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x41CBF0); }
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner)
		{ return false; }

	virtual ObjectClass* CreateObject(HouseClass* pOwner)
		{ PUSH_VAR32(pOwner); THISCALL(0x41CB20); }

	virtual void vt_entry_90(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x41CB70); }

//TechnoTypeClass
	virtual bool vt_entry_A0()
		{ return false; }

	virtual bool CanAttackMove()
		{ return false; }

	//Constructor
	AircraftTypeClass(const char* id):TechnoTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x41C8B0); }

protected:
	//default contructor, only used by polymorphism
	AircraftTypeClass():TechnoTypeClass(false)
		{ }
	AircraftTypeClass(bool X):TechnoTypeClass(false)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(bool, Carryall);
	PROPERTY(AnimTypeClass*, Trailer);
	PROPERTY(int, SpawnDelay);
	PROPERTY(bool, Rotors);
	PROPERTY(bool, CustomRotor);
	PROPERTY(bool, Landable);
	PROPERTY(bool, FlyBy);
	PROPERTY(bool, FlyBack);
	PROPERTY(bool, AirportBound);
	PROPERTY(bool, Fighter);
};

#endif
