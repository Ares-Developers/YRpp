/*
	Weapons
*/

#ifndef WEAPONTYPE_H
#define WEAPONTYPE_H

#include <AbstractTypeClass.h>

//forward declarations
class AnimTypeClass;
class BulletTypeClass;
class ParticleSystemTypeClass;
class WarheadTypeClass;

class WeaponTypeClass : public AbstractTypeClass
{
public:
	//Array
	ABSTRACTTYPE_ARRAY(WeaponTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x772C90); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x772CD0); }
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x772EB0); }

	//Destructor
	virtual ~WeaponTypeClass()
		{ THISCALL(0x771F50); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_WeaponType; }
	virtual int Size()
		{ return sizeof(WeaponTypeClass); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x772AE0); }

	//AbstractTypeClass
	virtual bool LoadFromINI(CCINIClass* pINI)
		{ PUSH_VAR32(pINI); THISCALL(0x772080); }

	void CalculateSpeed()
		{ THISCALL(0x7729F0); }

	//Constructor
	WeaponTypeClass(const char* id):AbstractTypeClass(false)
		{ PUSH_VAR32(id); THISCALL(0x771C70); }

protected:
	WeaponTypeClass():AbstractTypeClass(false){}
	WeaponTypeClass(bool X):AbstractTypeClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,					AmbientDamage);
	PROPERTY(int,					Burst);
	PROPERTY(BulletTypeClass*,		Projectile);
	PROPERTY(int,					Damage);
	PROPERTY(int,					Speed);
	PROPERTY(WarheadTypeClass*,		Warhead);
	PROPERTY(int,					ROF);
	PROPERTY(float,					Range);
	PROPERTY(float,					MinimumRange);
	PROPERTY_STRUCT(TypeList<int>,			Report);		//sound indices
	PROPERTY_STRUCT(TypeList<int>,			DownReport);	//sound indices
	PROPERTY_STRUCT(TypeList<AnimTypeClass*>,	Anim);
	PROPERTY(AnimTypeClass*,		OccupantAnim);
	PROPERTY(AnimTypeClass*,		AssaultAnim);
	PROPERTY(AnimTypeClass*,		OpenToppedAnim);
	PROPERTY(ParticleSystemTypeClass*,	AttachedParticleSystem);
	PROPERTY_STRUCT(ColorStruct,			LaserInnerColor);
	PROPERTY_STRUCT(ColorStruct,			LaserOuterColor);
	PROPERTY_STRUCT(ColorStruct,			LaserOuterSpread);
	PROPERTY(bool,					UseFireParticles);
	PROPERTY(bool,					UseSparkParticles);
	PROPERTY(bool,					OmniFire);
	PROPERTY(bool,					DistributedWeaponFire);
	PROPERTY(bool,					IsRailgun);
	PROPERTY(bool,					Lobber);
	PROPERTY(bool,					Bright);
	PROPERTY(bool,					IsSonic);
	PROPERTY(bool,					Spawner);
	PROPERTY(bool,					LimboLaunch);
	PROPERTY(bool,					DecloakToFire);
	PROPERTY(bool,					CellRangefinding);
	PROPERTY(bool,					FireOnce);
	PROPERTY(bool,					NeverUse);
	PROPERTY(bool,					RevealOnFire);
	PROPERTY(bool,					TerrainFire);
	PROPERTY(bool,					SabotageCursor);
	PROPERTY(bool,					MigAttackCursor);
	PROPERTY(bool,					DisguiseFireOnly);
	PROPERTY(int,					DisguiseFakeBlinkTime);
	PROPERTY(bool,					InfiniteMindControl);
	PROPERTY(bool,					FireWhileMoving);
	PROPERTY(bool,					DrainWeapon);
	PROPERTY(bool,					FireInTransport);
	PROPERTY(bool,					Suicide);
	PROPERTY(bool,					TurboBoost);
	PROPERTY(bool,					Supress);
	PROPERTY(bool,					Camera);
	PROPERTY(bool,					Charges);
	PROPERTY(bool,					IsLaser);
	PROPERTY(bool,					DiskLaser);
	PROPERTY(bool,					IsLine);
	PROPERTY(bool,					IsBigLaser);
	PROPERTY(bool,					IsHouseColor);
	PROPERTY(char,					LaserDuration);
	PROPERTY(bool,					IonSensitive);
	PROPERTY(bool,					AreaFire);
	PROPERTY(bool,					IsElectricBolt);
	PROPERTY(bool,					DrawBoltAsLaser);
	PROPERTY(bool,					IsAlternateColor);
	PROPERTY(bool,					IsRadBeam);
	PROPERTY(bool,					IsRadEruption);
	PROPERTY(int,					RadLevel);
	PROPERTY(bool,					IsMagBeam);
};

#endif
