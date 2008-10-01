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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	//Destructor
	virtual ~BulletTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass
	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

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
