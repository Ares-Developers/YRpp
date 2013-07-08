#ifndef BOMB_H
#define BOMB_H

#include <AbstractClass.h>
#include <Audio.h>

//forward declarations
class TechnoClass;
class HouseClass;

class BombClass : public AbstractClass
{
public:
	enum {AbsID = abs_Bomb};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~BombClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	void Detonate()
		{ JMP_THIS(0x438720); }

	void Disarm()
		{ JMP_THIS(0x4389B0); }

	BOOL IsDeathBomb() const
		{ JMP_THIS(0x4389F0); }

	int GetCurrentFlickerFrame() const // which frame of the ticking bomb to draw
		{ JMP_THIS(0x438A00); }

	bool TimeToExplode() const
		{ JMP_THIS(0x438A70); }


protected:
	//Constructor
	//Bombs have a special constructor that just should not be called like this...
	BombClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TechnoClass* OwnerObject;		//Most likely Ivan.
	HouseClass* OwnerHouse;
	TechnoClass* TargetUnit;
	BOOL DeathBomb; // unused - if so, [General]CanDetonateDeathBomb applies instead of CanDetonateTimeBomb
	int PlantingFrame;
	int DetonationFrame;
	AudioController Audio;
	int TickSound;
	BOOL ShouldPlayTickingSound; // seems so
	bool Harmless; // (mostly) set to 0 on plant, 1 on detonation/removal ?
};

#endif
