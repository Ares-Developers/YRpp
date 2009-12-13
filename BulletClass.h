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
	int Distance;
};

// the velocities along the axes, or something like that
typedef Vector3D<double> BulletVelocity; // :3 -pd

class BulletClass : public ObjectClass
{
public:
	enum {AbsID = abs_Bullet};

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
	void Construct(
		BulletTypeClass *pType,
		ObjectClass *Target,
		TechnoClass *Owner,
		int Damage, 
		WarheadTypeClass *WH,
		int Speed,
		bool Bright) JMP_THIS(0x4664C0);

	// spawns the actual projectile onto the map
	void Fire(CoordStruct *Target)
		JMP_THIS(0x4690B0);

	void Detonate(bool bUnknown)
		JMP_STD(0x468D80);

	// spawns off the proper amount of shrapnel projectiles
	void Shrapnel()
		JMP_THIS(0x46A310);

	static void ApplyRadiationToCell(CellStruct coords, double *radius, int amount)
		JMP_STD(0x46ADE0);

	bool IsHoming()
		{ return this->Type->ROT > 0; }

	void SetWeaponType(WeaponTypeClass *weapon)
		{ this->WeaponType = weapon; }

	WeaponTypeClass * GetWeaponType()
		{ return this->WeaponType; }

	// only called in UnitClass::Fire if Type->Scalable
	void InitScalable()
		JMP_THIS(0x46B280);

	// call only after the target, args, etc., have been set
	void NukeMaker()
		JMP_THIS(0x46B310);

	//Constructor
protected:
	BulletClass() : ObjectClass(false)
		JMP_THIS(0x466380);


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
