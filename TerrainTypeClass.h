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
	//Array
	ABSTRACTTYPE_ARRAY(TerrainTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TerrainTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Constructor
	TerrainTypeClass(const char* pID = NULL) : ObjectTypeClass(false)
		JMP_THIS(0x71DA80);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,			ArrayIndex);
	PROPERTY(int,			Foundation);
	PROPERTY_STRUCT(ColorStruct,	RadarColor);
	PROPERTY(int,			AnimationRate);
	PROPERTY(float,			AnimationProbability);
	PROPERTY(int,			TemperateOccupationBits);
	PROPERTY(int,			SnowOccupationBits);
	PROPERTY(bool,			WaterBound);
	PROPERTY(bool,			SpawnsTiberium);
	PROPERTY(bool,			IsFlammable);
	PROPERTY(bool,			IsAnimated);
	PROPERTY(bool,			IsVeinhole);
	PROPERTY(CellStruct*,	FoundationData);
};

#endif
