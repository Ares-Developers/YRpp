#pragma once

#include <AbstractClass.h>
#include <ArrayClasses.h>
#include <BombClass.h>

//forward declarations
class ObjectClass;
class TechnoClass;

//this class contains a vector of BombClass, a vector of bomb-revealing TechnoClass, and some other properties
class BombListClass
{
public:
	static BombListClass* const Instance;

	// draws all the visible bombs, expires the outdated ones
 	void Update()
		{ JMP_THIS(0x438BF0); }

	// the main one, ivan planting a bomb (creates a BombClass inside)
	void Plant(TechnoClass *SourceObject, ObjectClass *TargetObject)
		{ JMP_THIS(0x438E70); }

	// duh
	void AddDetector(TechnoClass *Detector)
		{ JMP_THIS(0x439080); }

	// duh
	void RemoveDetector(TechnoClass *Detector)
		{ JMP_THIS(0x4390D0); }

	void PointerGotInvalid(AbstractClass* pInvalid)
		{ JMP_THIS(0x439150); }

protected:
	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DynamicVectorClass<BombClass *> Bombs;				//all the BombClass instances on the map
	DynamicVectorClass<TechnoClass *> Detectors;		//all the BombSight'ed objects currently on the map
	int UpdateDelay; // defaults to 100, some iterators set it to 1
};
