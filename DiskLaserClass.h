/*
	DiskLasers are the floating disks' purple lasers.
*/

#ifndef DISKLASER_H
#define DISKLASER_H

#include <AbstractClass.h>

class LaserDrawClass;
class TechnoClass;
class WeaponTypeClass;

class DiskLaserClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::DiskLaser;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~DiskLaserClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//Constructor
	DiskLaserClass() : AbstractClass(false)
		JMP_THIS(0x4A7A30);

	//non-virtual
	void Fire(TechnoClass* pOwner, TechnoClass* pTarget, WeaponTypeClass* pWeapon, int nDamage)
		{ JMP_THIS(0x4A71A0); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TechnoClass* Owner;
	TechnoClass* Target;
	WeaponTypeClass* Weapon;
	DWORD unknown_30;
	DWORD unknown_34;
	DWORD unknown_38;
	int Damage;
};

#endif
