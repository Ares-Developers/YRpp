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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x438B00);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x438B40);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x438BD0);}
	
	//Destructor
	virtual ~BombClass()		{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x4393F0);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_Bomb;}
	virtual int					Size(){return sizeof(BombClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x438A90);}

	void				Detonate()	{THISCALL(0x438720);}
	void				Disarm()	{THISCALL(0x4389B0);}

	void				IsDeathBomb()	{THISCALL(0x4389F0);}
	void				GetCurrentFlickerFrame()	{THISCALL(0x438A00);} // which frame of the ticking bomb to draw
	void				TimeToExplode()	{THISCALL(0x438A70);} 


protected:
	//Constructor
	//Bombs have a special constructor that just should not be called like this...
	BombClass():AbstractClass(false){}
	BombClass(bool X):AbstractClass(X){}

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
