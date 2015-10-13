/*
	Animations
*/

#pragma once

#include <ObjectClass.h>
#include <AnimTypeClass.h>
#include <BounceClass.h>
#include <ProgressTimer.h>

//forward declarations
class AnimTypeClass;
class BulletClass;
class HouseClass;
class LightConvertClass;

class NOVTABLE AnimClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::Anim;

	//Static
	static DynamicVectorClass<AnimClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~AnimClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	//ObjectClass
	//AnimClass
	virtual int AnimExtras() R0; // tumbling for IsMeteor and Bouncer anims
	virtual int GetEnd() const R0; //End tag from the AnimType

	void SetOwnerObject(ObjectClass *pOwner)
		{ JMP_THIS(0x424B50); }

	void Pause() {
		this->Paused = true;
		this->Unpaused = false;
		this->PausedAnimFrame = this->Animation.Value;
	}

	void Unpause() {
		this->Paused = false;
		this->Unpaused = true;
	}

	//Constructor
	// TODO fix
	AnimClass(AnimTypeClass* pAnimType, const CoordStruct& Location, int LoopDelay = 0,
		int LoopCount = 1, DWORD flags = 0x600, int ForceZAdjust = 0, bool reverse = false) noexcept
		: AnimClass(noinit_t())
	{ JMP_THIS(0x421EA0); }

protected:
	explicit __forceinline AnimClass(noinit_t) noexcept
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	ProgressTimer Animation;
	AnimTypeClass* Type; //The AnimType.
	ObjectClass * OwnerObject; // set by AnimClass::SetOwnerObject (0x424B50)
	DWORD unknown_D0;
	LightConvertClass* LightConvert;	 //Palette?
	int LightConvertIndex; // assert( (*ColorScheme::Array)[this->LightConvertIndex] == this->LightConvert ;
	char PaletteName[0x20]; // filename set for destroy anims
	int TintColor;
	int ZAdjust;
	int YSortAdjust; // same as YSortAdjust from Type
	CoordStruct FlamingGuyCoords; // the destination the anim tries to reach
	int FlamingGuyRetries; // number of failed attemts to reach water. the random destination generator stops if >= 7
	bool IsBuildingAnim; // whether this anim will invalidate on buildings, and whether it's tintable
	bool UnderTemporal; // temporal'd building's active anims
	bool Paused; // if paused, does not advance anim, does not deliver damage
	bool Unpaused; // set when unpaused
	int PausedAnimFrame; // the animation value when paused
	bool Reverse; // anim is forced to be played from end to start
	DWORD unknown_124;
	BounceClass Bounce;
	BYTE TranslucencyLevel; // on a scale of 1 - 100
	bool TimeToDie; // or something to that effect, set just before UnInit
	BulletClass* AttachedBullet;
	HouseClass* Owner; //Used for remap (AltPalette).
	int LoopDelay; // randomized value, depending on RandomLoopDelay
	double Damage; // defaults to 1.0 , added to Type->Damage in some cases
	BlitterFlags AnimFlags; // argument that's 0x600 most of the time
	bool HasExtras; // enables IsMeteor and Bouncer special behavior (AnimExtras)
	byte RemainingIterations; // defaulted to deleteAfterIterations, when reaches zero, UnInit() is called
	byte unknown_196;
	byte unknown_197;
	bool IsPlaying;
	bool IsFogged;
	bool FlamingGuyExpire; // finish animation and remove
	bool UnableToContinue; // set when something prevents the anim from going on: cell occupied, veins destoyed or unit gone, ...
	bool SkipProcessOnce; // set in constructor, cleared during Update. skips damage, veins, tiberium chain reaction and animation progress
	bool Invisible; // don't draw, but Update state anyway
	bool PowerOff; // powered animation has no power
	PROTECTED_PROPERTY(BYTE, unused_19F);
	AudioController Audio3;
	AudioController Audio4;
};
