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

	//Constructor, Destructor
	TerrainTypeClass(const char* id):ObjectTypeClass(false)
												{PUSH_VAR32(id);THISCALL(0x71DA80);}
	virtual ~TerrainTypeClass()					{THISCALL(0x71DC00);}

	//identification
	virtual eAbstractType WhatAmI(){return abs_TerrainType;}

protected:
	//default contructor, only used by polymorphism
	TerrainTypeClass(){};

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
