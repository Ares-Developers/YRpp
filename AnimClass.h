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
	virtual eAbstractType WhatAmI() R0;
	virtual int	Size() R0;

	//ObjectClass
	//AnimClass
	virtual int AnimExtras() R0; // no idea what this does
	virtual int GetEnd() R0; //End tag from the AnimType

	void SetOwnerObject(ObjectClass *pOwner)
		{ JMP_THIS(0x424B50); }

	//Constructor
	// TODO fix
	AnimClass(AnimTypeClass* pAnimType, CoordStruct* pLocation) : ObjectClass(false)
	{
		PUSH_IMM(0); //???
		PUSH_IMM(0); //ZAdjust
		PUSH_IMM(0x600); // eBlitterFlags , certain calls use 0x1600 or 0x2600 instead, iow bitfield
		PUSH_IMM(1); //deleteAfterIterations
		PUSH_IMM(0); //???
		PUSH_VAR32(pLocation);
		PUSH_VAR32(pAnimType);
		THISCALL(0x421EA0);
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
	DWORD unknown_C4;
	AnimTypeClass* Type; //The AnimType.
	ObjectClass * OwnerObject; // set by AnimClass::SetOwnerObject (0x424B50)
	DWORD unknown_D0;
	LightConvertClass* LightConvert;	 //Palette?
	int LightConvertIndex; // assert( (*ColorScheme::Array)[this->LightConvertIndex] == this->LightConvert ;
	BYTE unknown_DC;
	DWORD unknown_E0;
	DWORD unknown_E4;
	DWORD unknown_E8;
	DWORD unknown_EC;
	DWORD unknown_F0;
	DWORD unknown_F4;
	DWORD unknown_F8;
	int TintColor;
	int ZAdjust;
	int YSortAdjust; // same as YSortAdjust from Type
	DWORD unknown_108;
	DWORD unknown_10C;
	DWORD unknown_110;
	DWORD unknown_114;
	BYTE unknown_118;
	bool UnderTemporal; // temporal'd building's active anims
	DWORD unknown_11C;
	DWORD unknown_120;
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
	DWORD unknown_184;
	double Damage; // defaults to 1.0 , added to Type->Damage in some cases
//	DWORD unknown_18C;
	eBlitterFlags AnimFlags; // argument that's 0x600 most of the time
	byte unknown_194;
	byte RemainingIterations; // defaulted to deleteAfterIterations, when reaches zero, UnInit() is called
	byte unknown_196;
	byte unknown_197;
	bool IsPlaying;
	bool IsFogged;
	byte unknown_19A;
	byte CellOccupied; // dunno, that's the name my IDB gives
	byte unknown_19C;
	bool Invisible; // don't draw, but Update state anyway
	byte unknown_19E;
	byte unknown_19F;
	AudioController Audio3;
	AudioController Audio4;
};

#endif
