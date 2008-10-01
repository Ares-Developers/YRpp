/*
	Projectiles
*/

#ifndef BULLET_H
#define BULLET_H

#include <ObjectClass.h>
#include <BulletTypeClass.h>

class TechnoClass;
class ObjectClass;
class WarheadTypeClass;

struct BulletData
{
 TimerStruct UnknownTimer;
 TimerStruct ArmTimer;
 CoordStruct Location;
 int         Distance;
};

// the velocities along the axes, or something like that
typedef Vector3D<double> BulletVelocity; // :3 -pd
/*
struct BulletVelocity
{
 double X;
 double Y;
 double Z;
};*/

class BulletClass : public ObjectClass
{
public:
	//Array
	static DynamicVectorClass<BulletClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~BulletClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//BulletClass
	virtual BYTE GetAnimRate() R0;
	virtual void SetTarget(ObjectClass *Target) RX;
	virtual BYTE MoveTo(CoordStruct *where, BulletVelocity *Velocity) R0;


	// non-virtual
	// after CoCreateInstance creates a bullet, this configures it
	void Construct(BulletTypeClass *pType, ObjectClass *Target, TechnoClass *Owner, int Damage, 
		WarheadTypeClass *WH, int Speed, bool Bright)
		{ PUSH_VAR8(Bright); PUSH_VAR32(Speed); PUSH_VAR32(WH); PUSH_VAR32(Damage);
			PUSH_VAR32(Owner); PUSH_VAR32(Target); PUSH_VAR32(pType); THISCALL(0x4664C0); }

	// spawns the actual projectile onto the map
	void Fire(CoordStruct *Target)
		{ PUSH_VAR32(Target); THISCALL(0x4690B0); }

	// spawns off the proper amount of shrapnel projectiles
	void Shrapnel()
		{ THISCALL(0x46A310); }

	static void ApplyRadiationToCell(CellStruct coords, double *radius, int amount)
		{ PUSH_VAR32(amount); PUSH_VAR32(radius); PUSH_VAR32(coords); CALL(0x46DAE0); }

	bool IsHoming()
		{ return this->Type->get_ROT() > 0; }

	void SetWeaponType(WeaponTypeClass *weapon)
		{ this->WeaponType = weapon; }

	WeaponTypeClass * GetWeaponType()
		{ return this->WeaponType; }

	// only called in UnitClass::Fire if Type->Scalable
	void InitScalable()
		{ THISCALL(0x46B280); }

	// call only after the target, args, etc., have been set
	void NukeMaker()
		{ THISCALL(0x46B310); }

	//Constructor
protected:
	BulletClass() : ObjectClass(false)
		{ THISCALL(0x466380); }


	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(BulletTypeClass*, Type);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(bool, unknown_B4);
	PROPERTY_STRUCT(BulletData, Data);
	PROPERTY(bool, Bright);
	PROPERTY(DWORD, unknown_E4);
	PROPERTY_STRUCT(BulletVelocity, Velocity);
	PROPERTY(DWORD, unknown_100);
	PROPERTY(bool, unknown_104);
	PROPERTY(DWORD, unknown_108);
	PROPERTY(ObjectClass*, Target);
	PROPERTY(DWORD, unknown_110);
	PROPERTY(DWORD, InheritedColor);
	PROPERTY(DWORD, unknown_118);
	PROPERTY(DWORD, unknown_11C);
	PROPERTY(DWORD, unknown_120);
	PROPERTY(DWORD, unknown_124);
	PROPERTY(WarheadTypeClass*, WH);
	PROPERTY(byte, AnimRate);
	PROPERTY(WeaponTypeClass*, WeaponType);
	PROPERTY_STRUCT(CoordStruct, posSrc);
	PROPERTY_STRUCT(CoordStruct, posTgt);
	PROPERTY_STRUCT(CellStruct, unknown_14C);
	PROPERTY(int, DamageMultiplier);
	PROPERTY(AnimClass*, NextAnim);
	PROPERTY(bool, SpawnNextAnim);
	PROPERTY(DWORD, unknown_15C);

};

#endif
