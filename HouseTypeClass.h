/*
	ObjectTypes are initialized by INI files.
*/

#ifndef HOUSETYPE_H
#define HOUSETYPE_H

#include <AbstractTypeClass.h>

class AircraftTypeClass;
class InfantryTypeClass;
class UnitTypeClass;

class HouseTypeClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(HouseTypeClass);

	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL_RET(0x5125A0, HRESULT); }

	virtual ULONG _stdcall AddRef()
		{ return 1; }
	virtual ULONG _stdcall Release()
		{ return 1; }

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x512640, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall IsDirty()
		{ return S_FALSE; }
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x512290, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x512480, HRESULT); }
	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize)
		{ PUSH_VAR32(pcbSize); PUSH_VAR32(this); CALL_RET(0x512570, HRESULT); }

	//Destructor
	virtual ~HouseTypeClass()
		{ THISCALL(0x5116A0); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_HouseType; }
	virtual int Size()
		{ return sizeof(HouseTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x512170); }
	virtual int GetArrayIndex()
		{ return ArrayIndex; }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL_RET(0x511850, bool); }

	//Constructor
	HouseTypeClass(const char* pID):AbstractTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x5113F0); }

protected:
	HouseTypeClass():AbstractTypeClass(false)
		{ }
	HouseTypeClass(bool X):AbstractTypeClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRING(ParentCountry, 0x18);
	PROTECTED_PROPERTY(BYTE, zero_B0);

	PROPERTY(int,            ArrayIndex);
	PROPERTY(int,            ArrayIndex2); //dunno why
	PROPERTY(int,            SideIndex);
	PROPERTY(int,            ColorSchemeIndex);
private: DWORD align_C4;

	//are these unused TS leftovers?
	PROPERTY(double,         FirepowerMult);
	PROPERTY(double,         GroundspeedMult);
	PROPERTY(double,         AirspeedMult);
	PROPERTY(double,         ArmorMult);
	PROPERTY(double,         ROFMult);
	PROPERTY(double,         CostMult);
	PROPERTY(double,         BuildtimeMult);
	//---

	PROPERTY(float,          ArmorInfantryMult);
	PROPERTY(float,          ArmorUnitsMult);
	PROPERTY(float,          ArmorAircraftMult);
	PROPERTY(float,          ArmorBuildingsMult);
	PROPERTY(float,          ArmorDefensesMult);

	PROPERTY(float,          CostInfantryMult);
	PROPERTY(float,          CostUnitsMult);
	PROPERTY(float,          CostAircraftMult);
	PROPERTY(float,          CostBuildingsMult);
	PROPERTY(float,          CostDefensesMult);

	PROPERTY(float,          SpeedInfantryMult);
	PROPERTY(float,          SpeedUnitsMult);
	PROPERTY(float,          SpeedAircraftMult);

	PROPERTY(float,          BuildtimeInfantryMult);
	PROPERTY(float,          BuildtimeUnitsMult);
	PROPERTY(float,          BuildtimeAircraftMult);
	PROPERTY(float,          BuildtimeBuildingsMult);
	PROPERTY(float,          BuildtimeDefensesMult);

	PROPERTY(float,          IncomeMult);

	PROPERTY_STRUCT(TypeList<InfantryTypeClass*>, VeteranInfantry);
	PROPERTY_STRUCT(TypeList<UnitTypeClass*>, VeteranUnits);
	PROPERTY_STRUCT(TypeList<AircraftTypeClass*>, VeteranAircraft);

	PROPERTY_STRING(Suffix,  4);

	PROPERTY(char,           Prefix);
	PROPERTY(bool,           Multiplay);
	PROPERTY(bool,           MultiplayPassive);
	PROPERTY(bool,           WallOwner);
	PROPERTY(bool,           SmartAI); //"smart"?
private: DWORD align_1A4;
};

#endif
