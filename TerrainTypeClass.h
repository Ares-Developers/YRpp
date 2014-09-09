/*
	TerrainTypes are initialized by INI files.
*/

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: VTABLE NEEDS TO BE DONE!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H

#include <ObjectTypeClass.h>

class TerrainTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::TerrainType;

	//Array
	ABSTRACTTYPE_ARRAY(TerrainTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TerrainTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Constructor
	TerrainTypeClass(const char* pID) : ObjectTypeClass(false)
		{ JMP_THIS(0x71DA80); }

protected:
	TerrainTypeClass() : ObjectTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int ArrayIndex;
	int Foundation;
	ColorStruct RadarColor;
	int AnimationRate;
	float AnimationProbability;
	int TemperateOccupationBits;
	int SnowOccupationBits;
	bool WaterBound;
	bool SpawnsTiberium;
	bool IsFlammable;
	bool IsAnimated;
	bool IsVeinhole;
	CellStruct* FoundationData;
};

#endif
