#ifndef BOMB_H
#define BOMB_H

#include <AbstractClass.h>

//forward declarations
class TechnoClass;
class HouseClass;

struct BombInfoStruct // this or some compatible struct is marked elsewhere as BYTE unknown_structure3[0x14]; needs more info
{
	int unk[3];
	void *Audio_IDX_Container; // no idea what this struct does, IDX_Container is the struct that contains the voc sounds, TODO: define
};

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
	PROPERTY(int,				Timer);
	PROPERTY_STRUCT(BombInfoStruct,	BombAudio);
	PROPERTY(DWORD,					unknown_4C);
	PROPERTY(int,					TickSound);
	PROPERTY(DWORD,					ShouldPlayTickingSound); // seems so
	PROPERTY(byte,					Harmless); // (mostly) set to 0 on plant, 1 on detonation/removal ?
};

#endif
