/*
	AnimTypes are initialized by INI files.
*/

#pragma once

#include <ObjectTypeClass.h>

//forward declarations
class OverlayTypeClass;
class ParticleTypeClass;
class WarheadTypeClass;

class NOVTABLE AnimTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::AnimType;

	//Array
	ABSTRACTTYPE_ARRAY(AnimTypeClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0; // ! this just returns NULL instead of creating the anim, fucking slackers

	//AnimTypeClass
	virtual SHPStruct* LoadImage() R0;
	virtual void Load2DArt() RX;

	//Destructor
	virtual ~AnimTypeClass() RX;

	//Constructor
	AnimTypeClass(const char* pID) noexcept
		: AnimTypeClass(noinit_t())
	{ JMP_THIS(0x427530); }

protected:
	explicit __forceinline AnimTypeClass(noinit_t) noexcept
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int ArrayIndex;
	int MiddleFrameIndex;
	int MiddleFrameWidth;
	int MiddleFrameHeight;
	BYTE unknown_2A4;
	double Damage;
	int Rate;
	int Start;
	int LoopStart;
	int LoopEnd;
	int End;
	int LoopCount;
	AnimTypeClass* Next;
	int SpawnsParticle; // index of that ParticleTypeClass
	int NumParticles;
	int DetailLevel;
	int TranslucencyDetailLevel;
	RandomStruct RandomLoopDelay;
	RandomStruct RandomRate;
	int Translucency;
	AnimTypeClass* Spawns;
	int SpawnCount;
	int Report;		//VocClass index
	int StopSound;		//VocClass index
	AnimTypeClass* BounceAnim;
	AnimTypeClass* ExpireAnim;
	AnimTypeClass* TrailerAnim;
	int TrailerSeperation;	//MISTYPE BY WESTWOOD!
	double Elasticity;
	double MinZVel;
	double unknown_double_320;
	double MaxXYVel;
	WarheadTypeClass* Warhead;
	int DamageRadius;
	OverlayTypeClass* TiberiumSpawnType;
	int TiberiumSpreadRadius;
	int YSortAdjust;
	int YDrawOffset;
	int ZAdjust;
	int MakeInfantry;
	int RunningFrames;
	bool IsFlamingGuy;
	bool IsVeins;
	bool IsMeteor;
	bool TiberiumChainReaction;
	bool IsTiberium;
	bool HideIfNoOre;
	bool Bouncer;
	bool Tiled;
	bool ShouldUseCellDrawer;
	bool UseNormalLight;
	bool DemandLoad; // not loaded from ini anymore
	bool FreeLoad;  // not loaded from ini anymore
	bool IsAnimatedTiberium;
	bool AltPalette;
	bool Normalized;
	Layer Layer;
	bool DoubleThick;
	bool Flat;
	bool Translucent;
	bool Scorch;
	bool Flamer;
	bool Crater;
	bool ForceBigCraters;
	bool Sticky;
	bool PingPong;
	bool Reverse;
	bool Shadow;
	bool PsiWarning;
	bool ShouldFogRemove;
};
