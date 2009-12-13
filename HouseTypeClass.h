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
	enum {AbsID = abs_HouseType};

	//Array
	ABSTRACTTYPE_ARRAY(HouseTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~HouseTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//Constructor
	HouseTypeClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x5113F0);

protected:
	HouseTypeClass() : AbstractTypeClass(false) { }

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
