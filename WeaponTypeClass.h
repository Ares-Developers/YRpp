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
	enum {AbsID = abs_WeaponType};

	//Array
	ABSTRACTTYPE_ARRAY(WeaponTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~WeaponTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass

	void CalculateSpeed()
		{ JMP_THIS(0x7729F0); }

	//Constructor
	WeaponTypeClass(const char* pID = NULL) : AbstractTypeClass(false)
		{ JMP_THIS(0x771C70); }

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
