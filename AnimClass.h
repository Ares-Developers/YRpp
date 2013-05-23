/*
	Animations
*/

#ifndef ANIM_H
#define ANIM_H

#include <ObjectClass.h>
#include <AnimTypeClass.h>

//forward declarations
class AnimTypeClass;
class BulletClass;
class HouseClass;
class LightConvertClass;

class AnimClass : public ObjectClass
{
public:
	enum {AbsID = abs_Anim};

	//Static
	static DynamicVectorClass<AnimClass*>* Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~AnimClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int	Size() const R0;

	//ObjectClass
	//AnimClass
	virtual int AnimExtras() R0; // tumbling for IsMeteor and Bouncer anims
	virtual int GetEnd() const R0; //End tag from the AnimType

	void SetOwnerObject(ObjectClass *pOwner)
		{ JMP_THIS(0x424B50); }

	//Constructor
	// TODO fix
	AnimClass(AnimTypeClass* pAnimType, CoordStruct* pLocation, int LoopDelay = 0,
		int LoopCount = 1, DWORD flags = 0x600, int ForceZAdjust = 0, bool reverse = false)
			: ObjectClass(false)
	{
		JMP_THIS(0x421EA0);
	}

protected:
	AnimClass() : ObjectClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int CurrentFrame; //Current animation frame.
	DWORD unknown_B0;
	TimerStruct IterationTimer; // Duration == Type->Rate, each expiration decrements remainingIterations
	int Rate;
	int FrameDelta; // the delta to the next frame. 1 is playing forward, -1 for playing backwards (PingPong, Reverse)
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
	BYTE unknown_118;
	bool UnderTemporal; // temporal'd building's active anims
	BYTE unknown_11A;
	BYTE unknown_11B;
	DWORD unknown_11C;
	bool Reverse; // anim is forced to be played from end to start
	DWORD unknown_124;
	DWORD unknown_128;
	DWORD unknown_12C;
	DWORD unknown_130;
	DWORD unknown_134;
	DWORD unknown_138;
	DWORD unknown_13C;
	CoordStruct ExpireAnimCoords;
	DWORD unknown_14C;
	DWORD unknown_150;
	DWORD unknown_154;
	DWORD unknown_158;
	DWORD unknown_15C;
	DWORD unknown_160;
	DWORD unknown_164;
	DWORD unknown_168;
	DWORD unknown_16C;
	DWORD unknown_170;
	DWORD unknown_174;
	BYTE TranslucencyLevel; // on a scale of 1 - 100
	bool TimeToDie; // or something to that effect, set just before UnInit
	BulletClass* AttachedBullet;
	HouseClass* Owner; //Used for remap (AltPalette).
	int LoopDelay; // randomized value, depending on RandomLoopDelay
	double Damage; // defaults to 1.0 , added to Type->Damage in some cases
	eBlitterFlags AnimFlags; // argument that's 0x600 most of the time
	bool HasExtras; // enables IsMeteor and Bouncer special behavior (AnimExtras)
	byte RemainingIterations; // defaulted to deleteAfterIterations, when reaches zero, UnInit() is called
	byte unknown_196;
	byte unknown_197;
	bool IsPlaying;
	bool IsFogged;
	bool FlamingGuyExpire; // finish animation and remove
	byte CellOccupied; // dunno, that's the name my IDB gives
	byte unknown_19C;
	bool Invisible; // don't draw, but Update state anyway
	byte unknown_19E;
	byte unknown_19F;
	AudioController Audio3;
	AudioController Audio4;
};

#endif
