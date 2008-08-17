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
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL_RET(0x4A7C30, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x4A7B90, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x4A7C10, HRESULT); }

	//Destructor
	virtual ~DiskLaserClass()				{PUSH_IMM(SDDTOR_NODELETE);THISCALL(0x4A7C90);}

	//AbstractClass
	virtual eAbstractType		WhatAmI(){return abs_DiskLaser;}
	virtual int					Size(){return sizeof(DiskLaserClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x4A7B80);}
	virtual void				Update(){THISCALL(0x4A7340);}

	//Constructor
	DiskLaserClass():AbstractClass(false){THISCALL(0x4A7A30);}

	//non-virtual
	void Fire(TechnoClass* pOwner,TechnoClass* pTarget,WeaponTypeClass* pWeapon,int nDamage)
	{PUSH_VAR32(nDamage);PUSH_VAR32(pWeapon);PUSH_VAR32(pTarget);PUSH_VAR32(pOwner);THISCALL(0x4A71A0);}

protected:
	DiskLaserClass(bool X):AbstractClass(X){}

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
