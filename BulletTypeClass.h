/*
	Projectiles
*/

#ifndef BULLETTYPE_H
#define BULLETTYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class AnimTypeClass;
class BulletClass;
class ColorScheme;
class CellClass;
class TechnoClass;
class WeaponTypeClass;
class WarheadTypeClass;

class BulletTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::BulletType;

	//Array
	ABSTRACTTYPE_ARRAY(BulletTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~BulletTypeClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//AbstractTypeClass
	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//Constructor
	BulletTypeClass(const char* pID) : ObjectTypeClass(false)
		{ JMP_THIS(0x46BBC0); }

	BulletClass* __fastcall CreateBullet(
		AbstractClass* Target,
		TechnoClass* Owner,
		int Damage,
		WarheadTypeClass *WH,
		int Speed,
		bool Bright)
		{ JMP_STD(0x46B050); }

protected:
	BulletTypeClass() : ObjectTypeClass(false) {};

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	bool Airburst;
	bool Floater;
	bool SubjectToCliffs;
	bool SubjectToElevation;
	bool SubjectToWalls;
	bool VeryHigh;
	bool Shadow;
	bool Arcing;
	bool Dropping;
	bool Level;
	bool Inviso;
	bool Proximity;
	bool Ranged;
	bool Rotates;
	bool Inaccurate;
	bool FlakScatter;
	bool AA;
	bool AG;
	bool Degenerates;
	bool Bouncy;
	bool AnimPalette;
	bool FirersPalette;
	int Cluster;
	WeaponTypeClass* AirburstWeapon;
	WeaponTypeClass* ShrapnelWeapon;
	int ShrapnelCount;
	int DetonationAltitude;
	bool Vertical;
	double Elasticity;
	int Acceleration;
	ColorScheme* Color;
	AnimTypeClass* Trailer;
	int ROT;
	int CourseLockDuration;
	int SpawnDelay;
	int unknown_int_2E8; //Related to SpawnDelay
	bool Scalable;
	int Arm;
	char AnimLow;
	char AnimHigh;
	char AnimRate;
	bool Flat;
};

#endif
