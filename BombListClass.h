#ifndef BOMBLIST_H
#define BOMBLIST_H

#include <AbstractClass.h>
#include <ArrayClasses.h>
#include <BombClass.h>

//forward declarations
class TechnoClass;

//this class contains a vector of BombClass, a vector of bomb-revealing TechnoClass, and some other properties
class BombListClass
{
public:
	// get the one static instance:
	static BombListClass* Global()
		{ return (BombListClass*)0x87F5D8; }

	// draws all the visible bombs, expires the outdated ones
 	void Update()
		{ THISCALL(0x438BF0); }
	
	// the main one, ivan planting a bomb (creates a BombClass inside)
	void Plant(TechnoClass *SourceObject, TechnoClass *TargetObject)	
		{ PUSH_VAR32(TargetObject); PUSH_VAR32(SourceObject); THISCALL(0x438E70); }

	// duh
	void AddDetector(TechnoClass *Detector)
		{ PUSH_VAR32(Detector); THISCALL(0x439080); }

	// duh
	void RemoveDetector(TechnoClass *Detector)
		{ PUSH_VAR32(Detector); THISCALL(0x4390D0); }

protected:
	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_STRUCT(DynamicVectorClass<BombClass *>,	Bombs);				//all the BombClass instances on the map
	PROPERTY_STRUCT(DynamicVectorClass<TechnoClass *>,	Detectors);		//all the BombSight'ed objects currently on the map
	PROPERTY(int,		SomeArgument); // defaults to 100, some iterators set it to 1
};

#endif
