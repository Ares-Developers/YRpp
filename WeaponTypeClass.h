/*
	Weapons
*/

#pragma once

#include <AbstractTypeClass.h>

//forward declarations
class AnimTypeClass;
class BulletTypeClass;
class ParticleSystemTypeClass;
class WarheadTypeClass;

class NOVTABLE WeaponTypeClass : public AbstractTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::WeaponType;

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
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//AbstractTypeClass

	void CalculateSpeed()
		{ JMP_THIS(0x7729F0); }

	//Constructor
	WeaponTypeClass(const char* pID = nullptr)
		: WeaponTypeClass(noinit_t())
	{ JMP_THIS(0x771C70); }

protected:
	explicit __forceinline WeaponTypeClass(noinit_t)
		: AbstractTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int AmbientDamage;
	int Burst;
	BulletTypeClass* Projectile;
	int Damage;
	int Speed;
	WarheadTypeClass* Warhead;
	int ROF;
	int Range; // int(256 * ini value)
	int MinimumRange; // int(256 * ini value)
	TypeList<int> Report;		//sound indices
	TypeList<int> DownReport;	//sound indices
	TypeList<AnimTypeClass*> Anim;
	AnimTypeClass* OccupantAnim;
	AnimTypeClass* AssaultAnim;
	AnimTypeClass* OpenToppedAnim;
	ParticleSystemTypeClass* AttachedParticleSystem;
	ColorStruct LaserInnerColor;
	ColorStruct LaserOuterColor;
	ColorStruct LaserOuterSpread;
	bool UseFireParticles;
	bool UseSparkParticles;
	bool OmniFire;
	bool DistributedWeaponFire;
	bool IsRailgun;
	bool Lobber;
	bool Bright;
	bool IsSonic;
	bool Spawner;
	bool LimboLaunch;
	bool DecloakToFire;
	bool CellRangefinding;
	bool FireOnce;
	bool NeverUse;
	bool RevealOnFire;
	bool TerrainFire;
	bool SabotageCursor;
	bool MigAttackCursor;
	bool DisguiseFireOnly;
	int DisguiseFakeBlinkTime;
	bool InfiniteMindControl;
	bool FireWhileMoving;
	bool DrainWeapon;
	bool FireInTransport;
	bool Suicide;
	bool TurboBoost;
	bool Supress;
	bool Camera;
	bool Charges;
	bool IsLaser;
	bool DiskLaser;
	bool IsLine;
	bool IsBigLaser;
	bool IsHouseColor;
	char LaserDuration;
	bool IonSensitive;
	bool AreaFire;
	bool IsElectricBolt;
	bool DrawBoltAsLaser;
	bool IsAlternateColor;
	bool IsRadBeam;
	bool IsRadEruption;
	int RadLevel;
	bool IsMagBeam;
};
