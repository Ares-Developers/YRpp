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
struct BulletVelocity
{
 double X;
 double Y;
 double Z;
};

class BulletClass : public ObjectClass
{
public:
	static DynamicVectorClass<BulletClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x46B560, HRESULT); }

	//ARGH why
	virtual ULONG _stdcall AddRef()
		{ PUSH_VAR32(this); CALL_RET(0x46AFD0, ULONG); }
	virtual ULONG _stdcall Release()
		{ PUSH_VAR32(this); CALL_RET(0x46AFF0, ULONG); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this);CALL_RET(0x46AE70, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x46AFB0, HRESULT); }

	//Destructor
	virtual ~BulletClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x46B5C0); }

	//AbstractClass
	virtual void PointerExpired(void* p,bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x4684E0); }

	virtual eAbstractType WhatAmI()
		{ return abs_Bullet; }

	virtual int Size()
		{ return sizeof(BulletClass); }

	virtual void Update()
		{ THISCALL(0x4666E0); }

	// ObjectClass
	virtual eLayer InWhichLayer()
		{ return this->Type->get_Flat() ? 1 : 3; }

	virtual ObjectTypeClass * GetType()
		{ return this->Type; }
	virtual DWORD vt_entry_108(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x466660, DWORD); }

	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x468090); }
	virtual bool SetLayer(eLayer value)
		{ PUSH_VAR32(value); THISCALL_RET(0x4666C0, bool); }

/*
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x46C560); }
*/
	virtual byte GetAnimRate()
		{ THISCALL_RET(0x468000, byte); }

	virtual void SetTarget(ObjectClass *Target)
		{ this->set_Target(Target); }
	virtual byte MoveTo(CoordStruct *where, BulletVelocity *Velocity)
		{ PUSH_VAR32(Velocity); PUSH_VAR32(where); THISCALL_RET(0x468670, byte); }

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
	PROPERTY(DWORD, unknown_A8);
	PROPERTY(BulletTypeClass*, Type);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY(bool, unknown_B4);
	PROPERTY_STRUCT(BulletData, Data);
	PROPERTY(bool, Bright);
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
	PROPERTY(AnimClass*, NextAnim);
	PROPERTY(bool, SpawnNextAnim);
	PROPERTY(DWORD, unknown_15C);

};

#endif
