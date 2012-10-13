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
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~BulletClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//BulletClass
	virtual BYTE GetAnimRate() const R0;
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
		bool Bright)
		{ JMP_THIS(0x4664C0); }

	// spawns the actual projectile onto the map
	void Fire(CoordStruct *Target)
		{ JMP_THIS(0x4690B0); }

	void Detonate(bool bUnknown)
		{ JMP_STD(0x468D80); }

	// spawns off the proper amount of shrapnel projectiles
	void Shrapnel()
		{ JMP_THIS(0x46A310); }

	static void ApplyRadiationToCell(CellStruct coords, double *radius, int amount)
		{ JMP_STD(0x46ADE0); }

	// this bullet will miss and hit the ground instead.
	// if the original target is in air, it will disappear.
	void LoseTarget()
		{ JMP_THIS(0x468430); }

	bool IsHoming() const
		{ return this->Type->ROT > 0; }

	void SetWeaponType(WeaponTypeClass *weapon)
		{ this->WeaponType = weapon; }

	WeaponTypeClass * GetWeaponType() const
		{ return this->WeaponType; }

	// only called in UnitClass::Fire if Type->Scalable
	void InitScalable()
		{ JMP_THIS(0x46B280); }

	// call only after the target, args, etc., have been set
	void NukeMaker()
		{ JMP_THIS(0x46B310); }

	// helpers
	void GetTargetCoords(CoordStruct * Coords) const {
		if(this->Target) {
			this->Target->GetCoords(Coords);
		} else {
			this->GetCoords(Coords);
		}
	}

	//Constructor
protected:
	BulletClass() : ObjectClass(false)
		{ JMP_THIS(0x466380); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	BulletTypeClass* Type;
	TechnoClass* Owner;
	bool unknown_B4;
	BulletData Data;
	bool Bright;
	DWORD unknown_E4;
	BulletVelocity Velocity;
	DWORD unknown_100;
	bool unknown_104;
	DWORD unknown_108;
	AbstractClass* Target;
	int Speed;
	int InheritedColor;
	DWORD unknown_118;
	DWORD unknown_11C;
	double unknown_120;
	WarheadTypeClass* WH;
	byte AnimRate;
	byte unknown_12D; // AnimRate from Type
	WeaponTypeClass* WeaponType;
	CoordStruct posSrc;
	CoordStruct posTgt;
	CellStruct unknown_14C;
	int DamageMultiplier;
	AnimClass* NextAnim;
	bool SpawnNextAnim;
	DWORD unknown_15C;
};

#endif
