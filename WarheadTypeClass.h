/*
	Warheads
*/

#ifndef WARHEADTYPE_H
#define WARHEADTYPE_H

#include <AbstractTypeClass.h>

//forward declarations
class AnimTypeClass;
class ParticleTypeClass;
class VoxelAnimTypeClass;

class WarheadTypeClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_WarheadType};

	//Array
	ABSTRACTTYPE_ARRAY(WarheadTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~WarheadTypeClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//AbstractTypeClass

	//Constructor
	WarheadTypeClass(const char* pID) : AbstractTypeClass(false)
		JMP_THIS(0x75CEC0);

protected:
	WarheadTypeClass() : AbstractTypeClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(double,  Deform);

	PROPERTY_ARRAY(double, Verses, 0xB);
/*
	//MISTYPE BY WESTWOOD!
	protected: double Verses[0x0B]; //access using the Armor Type definitions
	public: double get_Verses(int ArmorType)
		{ return Verses[ArmorType]; }
				void set_Verses(int ArmorType, double value)
		{ Verses[ArmorType] = value; }
*/

	PROPERTY(double,  ProneDamage);
	PROPERTY(int,     DeformTreshold);

	PROPERTY_STRUCT(TypeList<AnimTypeClass*>, AnimList);

	PROPERTY(int,     InfDeath);
	PROPERTY(float,   CellSpread);
	PROPERTY(float,   CellInset);
	PROPERTY(float,   PercentAtMax);
	PROPERTY(bool,    CausesDelayKill);
	PROPERTY(int,     DelayKillFrames);
	PROPERTY(float,   DelayKillAtMax);
	PROPERTY(float,   CombatLightSize);
	PROPERTY(ParticleTypeClass*, Particle);
	PROPERTY(bool,    Wall);
	PROPERTY(bool,    WallAbsoluteDestroyer);
	PROPERTY(bool,    PenetratesBunker);
	PROPERTY(bool,    Wood);
	PROPERTY(bool,    Tiberium);
	PROPERTY(bool,    unknown_bool_149);
	PROPERTY(bool,    Sparky);
	PROPERTY(bool,    Sonic);
	PROPERTY(bool,    Fire);
	PROPERTY(bool,    Conventional);
	PROPERTY(bool,    Rocker);
	PROPERTY(bool,    DirectRocker);
	PROPERTY(bool,    Bright);
	PROPERTY(bool,    CLDisableRed);
	PROPERTY(bool,    CLDisableGreen);
	PROPERTY(bool,    CLDisableBlue);
	PROPERTY(bool,    EMEffect);
	PROPERTY(bool,    MindControl);
	PROPERTY(bool,    Poison);
	PROPERTY(bool,    IvanBomb);
	PROPERTY(bool,    ElectricAssault);
	PROPERTY(bool,    Parasite);
	PROPERTY(bool,    Temporal);
	PROPERTY(bool,    IsLocomotor);
	PROPERTY(_GUID,   Locomotor);
	PROPERTY(bool,    Airstrike);
	PROPERTY(bool,    Psychedelic);
	PROPERTY(bool,    BombDisarm);
	PROPERTY(int,     Paralyzes);
	PROPERTY(bool,    Culling);
	PROPERTY(bool,    MakesDisguise);
	PROPERTY(bool,    NukeMaker);
	PROPERTY(bool,    Radiation);
	PROPERTY(bool,    PsychicDamage);
	PROPERTY(bool,    AffectsAllies);
	PROPERTY(bool,    Bullets);
	PROPERTY(bool,    Veinhole);
	PROPERTY(int,     ShakeXlo);
	PROPERTY(int,     ShakeXhi);
	PROPERTY(int,     ShakeYlo);
	PROPERTY(int,     ShakeYhi);

	PROPERTY_STRUCT(TypeList<VoxelAnimTypeClass*>, DebrisTypes);
	PROPERTY_STRUCT(TypeList<int>, DebrisMaximums);

	PROPERTY(int,     MaxDebris);
	PROPERTY(int,     MinDebris);
	PROTECTED_PROPERTY(DWORD, unused_1CC); //???
};

#endif
