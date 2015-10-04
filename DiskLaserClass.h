/*
	DiskLasers are the floating disks' purple lasers.
*/

#pragma once

#include <AbstractClass.h>

class LaserDrawClass;
class TechnoClass;
class WeaponTypeClass;

class NOVTABLE DiskLaserClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::DiskLaser;

	// static
	static DynamicVectorClass<DiskLaserClass*>* const Array;

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

	//non-virtual
	void Fire(TechnoClass* pOwner, TechnoClass* pTarget, WeaponTypeClass* pWeapon, int nDamage)
		{ JMP_THIS(0x4A71A0); }

	void PointerGotInvalid(AbstractClass* pInvalid)
		{ JMP_THIS(0x4A7900); }

	//Constructor
	DiskLaserClass() noexcept
		: DiskLaserClass(noinit_t())
	{ JMP_THIS(0x4A7A30); }

protected:
	explicit __forceinline DiskLaserClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

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
