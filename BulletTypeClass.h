/*
	Projectiles
*/

#ifndef BULLETTYPE_H
#define BULLETTYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;
class ColorScheme;
class WeaponTypeClass;

class BulletTypeClass : public ObjectTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(BulletTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x46C750); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this);CALL(0x46C6A0); }

	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x46C730);}

	//Destructor
	virtual ~BulletTypeClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x46C890); }

	//AbstractClass
	virtual void PointerExpired(void* p,bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x46C820); }

	virtual eAbstractType WhatAmI()
		{ return abs_BulletType; }

	virtual int Size()
		{ return sizeof(BulletTypeClass); }

	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x46C560); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x427D00); }

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest,CoordStruct* pSrc)
		{ PUSH_VAR32(pSrc); PUSH_VAR32(pDest); THISCALL(0x46C4F0);}

	virtual bool SpawnAtMapCoords(CellStruct* mcoords,HouseClass* owner)
		{ return false; }
	
	virtual ObjectClass* CreateObject(HouseClass* owner)
		{ return NULL; }

	//Constructor
	BulletTypeClass(const char* pID) : ObjectTypeClass(false)
		{ PUSH_VAR32(pID); THISCALL(0x46BBC0); }

	BulletClass* CreateBullet(CellClass* Target, TechnoClass* Owner, int Damage, 
		WarheadTypeClass *WH, int Speed, bool Bright)
			{ PUSH_VAR8(Bright); PUSH_VAR32(Speed); PUSH_VAR32(WH); PUSH_VAR32(Owner); SET_REG32(EDX, Target); 
				THISCALL(0x46B050); }

protected:
	BulletTypeClass() {};
	BulletTypeClass(bool X) : ObjectTypeClass(false) {};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(bool,				Airburst);
	PROPERTY(bool,				Floater);
	PROPERTY(bool,				SubjectToCliffs);
	PROPERTY(bool,				SubjectToElevation);
	PROPERTY(bool,				SubjectToWalls);
	PROPERTY(bool,				VeryHigh);
	PROPERTY(bool,				Shadow);
	PROPERTY(bool,				Arcing);
	PROPERTY(bool,				Dropping);
	PROPERTY(bool,				Level);
	PROPERTY(bool,				Inviso);
	PROPERTY(bool,				Proximity);
	PROPERTY(bool,				Ranged);
	PROPERTY(bool,				Rotates);
	PROPERTY(bool,				Inaccurate);
	PROPERTY(bool,				FlakScatter);
	PROPERTY(bool,				AA);
	PROPERTY(bool,				AG);
	PROPERTY(bool,				Degenerates);
	PROPERTY(bool,				Bouncy);
	PROPERTY(bool,				AnimPalette);
	PROPERTY(bool,				FirersPalette);
	PROPERTY(int,				Cluster);
	PROPERTY(WeaponTypeClass*,	AirburstWeapon);
	PROPERTY(WeaponTypeClass*,	ShrapnelWeapon);
	PROPERTY(int,				ShrapnelCount);
	PROPERTY(int,				DetonationAltitude);
	PROPERTY(bool,				Vertical);
private: DWORD align_2C4;
	PROPERTY(double,			Elasticity);
	PROPERTY(int,				Acceleration);
	PROPERTY(ColorScheme*,		Color);
	PROPERTY(AnimTypeClass*,	Trailer);
	PROPERTY(int,				ROT);
	PROPERTY(int,				CourseLockDuration);
	PROPERTY(int,				SpawnDelay);
	PROPERTY(int,				unknown_int_2E8);	//Related to SpawnDelay
	PROPERTY(bool,				Scalable);
	PROPERTY(int,				Arm);
	PROPERTY(char,				AnimLow);
	PROPERTY(char,				AnimHigh);
	PROPERTY(char,				AnimRate);
	PROPERTY(bool,				Flat);
};

#endif
