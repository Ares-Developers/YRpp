#ifndef BOMB_H
#define BOMB_H

#include <AbstractClass.h>

//forward declarations
class TechnoClass;
class HouseClass;

class BombClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;
	
	//Destructor
	virtual ~BombClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	void Detonate()
		{ THISCALL(0x438720); }

	void Disarm()
		{ THISCALL(0x4389B0); }

	void IsDeathBomb()
		{ THISCALL(0x4389F0); }

	void GetCurrentFlickerFrame() // which frame of the ticking bomb to draw
		{ THISCALL(0x438A00); }

	void TimeToExplode()
		{ THISCALL(0x438A70); }


protected:
	//Constructor
	//Bombs have a special constructor that just should not be called like this...
	BombClass() : AbstractClass(false) { }
	BombClass(bool X) : AbstractClass(X) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TechnoClass*,		OwnerObject);		//Most likely Ivan.
	PROPERTY(HouseClass*,		OwnerHouse);
	PROPERTY(TechnoClass*,		TargetUnit);
	PROPERTY(DWORD,				DeathBomb); // unused - if so, [General]CanDetonateDeathBomb applies instead of CanDetonateTimeBomb
	PROPERTY(int,				PlantingFrame);
	PROPERTY(int,				DetonationFrame);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio);
	PROPERTY(int,					TickSound);
	PROPERTY(DWORD,					ShouldPlayTickingSound); // seems so
	PROPERTY(byte,					Harmless); // (mostly) set to 0 on plant, 1 on detonation/removal ?
};

#endif
