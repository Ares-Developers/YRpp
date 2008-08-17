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
	//Array
	ABSTRACTTYPE_ARRAY(AnimTypeClass);

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL_RET(0x428990, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
		{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x428800, HRESULT); }
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
		{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL_RET(0x428970, HRESULT); }

	//AbstractClass
	virtual void				PointerExpired(void* p,bool bUnknown)
								{PUSH_VAR8(bUnknown);PUSH_VAR32(p);THISCALL(0x428C10);}
	virtual eAbstractType		WhatAmI(){return abs_AnimType;}
	virtual int					Size(){return sizeof(AnimTypeClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x4289D0);}
	virtual int					GetArrayIndex(){return ArrayIndex;}

	//AbstractTypeClass
	virtual void				LoadTheaterSpecificArt(eTheater th_type)
								{PUSH_VAR32(th_type);THISCALL(0x427A80);}
	virtual bool LoadFromINI(CCINIClass* ini)
		{PUSH_VAR32(ini);THISCALL_RET(0x427D00, bool); }

	//ObjectTypeClass
	virtual bool				SpawnAtMapCoords(CellStruct* mcoords,HouseClass* owner){return false;}
	virtual ObjectClass*		CreateObject(HouseClass* owner){return NULL;}

	//AnimTypeClass
	virtual SHPStruct* LoadImage()
		{THISCALL_RET(0x428C30, SHPStruct*); }
	virtual void				Load2DArt(){THISCALL(0x427B50);}

	//Destructor
	virtual ~AnimTypeClass()			{THISCALL(0x427880);};

	//Constructor
	AnimTypeClass(const char* id):ObjectTypeClass(false)
										{PUSH_VAR32(id);THISCALL(0x427530);}

protected:
	AnimTypeClass(){};
	AnimTypeClass(bool X):ObjectTypeClass(false){};

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
//	PROPERTY(ParticleTypeClass*,SpawnsParticle);
	PROPERTY(int ,SpawnsParticle); // index of that ParticleTypeClass
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
