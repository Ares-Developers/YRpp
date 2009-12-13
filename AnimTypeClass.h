/*
	AnimTypes are initialized by INI files.
*/

#ifndef ANIMTYPE_H
#define ANIMTYPE_H

#include <ObjectTypeClass.h>

//forward declarations
class OverlayTypeClass;
class ParticleTypeClass;
class WarheadTypeClass;

class AnimTypeClass : public ObjectTypeClass
{
public:
	enum {AbsID = abs_AnimType};

	//Array
	ABSTRACTTYPE_ARRAY(AnimTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//ObjectTypeClass
	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords,HouseClass* pOwner) R0;
	virtual ObjectClass* CreateObject(HouseClass* owner) R0;

	//AnimTypeClass
	virtual SHPStruct* LoadImage() R0;
	virtual void Load2DArt() RX;

	//Destructor
	virtual ~AnimTypeClass() RX;

	//Constructor
	AnimTypeClass(const char* pID) : ObjectTypeClass(false)
		JMP_THIS(0x427530);

protected:
	AnimTypeClass() : ObjectTypeClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(int,				ArrayIndex);
	PROPERTY(DWORD,				unknown_298);
	PROPERTY(DWORD,				unknown_29C);
	PROPERTY(DWORD,				unknown_2A0);
	PROPERTY(DWORD,				unknown_2A4);
	PROPERTY(double,			Damage);
	PROPERTY(int,				Rate);
	PROPERTY(int,				Start);
	PROPERTY(int,				LoopStart);
	PROPERTY(int,				LoopEnd);
	PROPERTY(int,				End);
	PROPERTY(int,				LoopCount);
	PROPERTY(AnimTypeClass*,	Next);
	PROPERTY(int, SpawnsParticle); // index of that ParticleTypeClass
	PROPERTY(int,				NumParticles);
	PROPERTY(int,				DetailLevel);
	PROPERTY(int,				TranslucencyDetailLevel);
	PROPERTY(RandomStruct,		RandomLoopDelay);
	PROPERTY(RandomStruct,		RandomRate);
	PROPERTY(int,				Translucency);
	PROPERTY(AnimTypeClass*,	Spawns);
	PROPERTY(int,				SpawnCount);
	PROPERTY(int,				Report);		//VocClass index
	PROPERTY(int,				StopSound);		//VocClass index
	PROPERTY(AnimTypeClass*,	BounceAnim);
	PROPERTY(AnimTypeClass*,	ExpireAnim);
	PROPERTY(AnimTypeClass*,	TrailerAnim);
	PROPERTY(int,				TrailerSeperation);	//MISTYPE BY WESTWOOD!
	PROPERTY(double,			Elasticity);
	PROPERTY(double,			MinZVel);
	PROPERTY(double,			unknown_double_320);
	PROPERTY(double,			MaxXYVel);
	PROPERTY(WarheadTypeClass*,	Warhead);
	PROPERTY(int,				DamageRadius);
	PROPERTY(OverlayTypeClass*,	TiberiumSpawnType);
	PROPERTY(int,				TiberiumSpreadRadius);
	PROPERTY(int,				YSortAdjust);
	PROPERTY(int,				YDrawOffset);
	PROPERTY(int,				ZAdjust);
	PROPERTY(int,				MakeInfantry);
	PROPERTY(int,				RunningFrames);
	PROPERTY(bool,				IsFlamingGuy);
	PROPERTY(bool,				IsVeins);
	PROPERTY(bool,				IsMeteor);
	PROPERTY(bool,				TiberiumChainReaction);
	PROPERTY(bool,				IsTiberium);
	PROPERTY(bool,				HideIfNoOre);
	PROPERTY(bool,				Bouncer);
	PROPERTY(bool,				Tiled);
	PROPERTY(bool,				ShouldUseCellDrawer);
	PROPERTY(bool,				UseNormalLight);
	PROPERTY(bool,				DemandLoad); // not loaded from ini anymore
	PROPERTY(bool,				FreeLoad);  // not loaded from ini anymore
	PROPERTY(bool,				IsAnimatedTiberium);
	PROPERTY(bool,				AltPalette);
	PROPERTY(bool,				Normalized);
	PROPERTY(int,				Layer);
	PROPERTY(bool,				DoubleThick);
	PROPERTY(bool,				Flat);
	PROPERTY(bool,				Translucent);
	PROPERTY(bool,				Scorch);
	PROPERTY(bool,				Flamer);
	PROPERTY(bool,				Crater);
	PROPERTY(bool,				ForceBigCraters);
	PROPERTY(bool,				Sticky);
	PROPERTY(bool,				PingPong);
	PROPERTY(bool,				Reverse);
	PROPERTY(bool,				Shadow);
	PROPERTY(bool,				PsiWarning);
	PROPERTY(bool,				ShouldFogRemove);
};

#endif
