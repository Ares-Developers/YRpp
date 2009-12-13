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
	enum {AbsID = abs_DiskLaser};

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~DiskLaserClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	DiskLaserClass() : AbstractClass(false)
		JMP_THIS(0x4A7A30);

	//non-virtual
	void Fire(TechnoClass* pOwner, TechnoClass* pTarget, WeaponTypeClass* pWeapon, int nDamage)
		JMP_THIS(0x4A71A0);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(TechnoClass*,		Owner);
	PROPERTY(TechnoClass*,		Target);
	PROPERTY(WeaponTypeClass*,	Weapon);
	PROPERTY(DWORD,				unknown_30);
	PROPERTY(DWORD,				unknown_34);
	PROPERTY(DWORD,				unknown_38);
	PROPERTY(int,				Damage);
};

#endif
