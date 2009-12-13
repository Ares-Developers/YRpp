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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

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
		JMP_THIS(0x424B50);

	//Constructor
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

	PROPERTY(int, CurrentFrame); //Current animation frame.
	PROPERTY(DWORD, unknown_B0);
	PROPERTY_STRUCT(TimerStruct, IterationTimer); // Duration == Type->Rate, each expiration decrements remainingIterations
	PROPERTY(int, Rate);
	PROPERTY(DWORD, unknown_C4);
	PROPERTY(AnimTypeClass*, Type); //The AnimType.
	PROPERTY(ObjectClass *,	OwnerObject); // set by AnimClass::SetOwnerObject (0x424B50)
	PROPERTY(DWORD, unknown_D0);
	PROPERTY(LightConvertClass*, LightConvert);	 //Palette?
	PROPERTY(int, LightConvertIndex); // assert( (*ColorScheme::Array)[this->LightConvertIndex] == this->LightConvert );
	PROPERTY(BYTE, unknown_DC);
	PROPERTY(DWORD, unknown_E0);
	PROPERTY(DWORD, unknown_E4);
	PROPERTY(DWORD, unknown_E8);
	PROPERTY(DWORD, unknown_EC);
	PROPERTY(DWORD, unknown_F0);
	PROPERTY(DWORD, unknown_F4);
	PROPERTY(DWORD, unknown_F8);
	PROPERTY(int, TintColor);
	PROPERTY(int, ZAdjust);
	PROPERTY(int, YSortAdjust); // same as YSortAdjust from Type
	PROPERTY(DWORD, unknown_108);
	PROPERTY(DWORD, unknown_10C);
	PROPERTY(DWORD, unknown_110);
	PROPERTY(DWORD, unknown_114);
	PROPERTY(BYTE, unknown_118);
	PROPERTY(bool, UnderTemporal); // temporal'd building's active anims
	PROPERTY(DWORD, unknown_11C);
	PROPERTY(DWORD, unknown_120);
	PROPERTY(DWORD, unknown_124);
	PROPERTY(DWORD, unknown_128);
	PROPERTY(DWORD, unknown_12C);
	PROPERTY(DWORD, unknown_130);
	PROPERTY(DWORD, unknown_134);
	PROPERTY(DWORD, unknown_138);
	PROPERTY(DWORD, unknown_13C);
	PROPERTY(CoordStruct, ExpireAnimCoords);
	PROPERTY(DWORD, unknown_14C);
	PROPERTY(DWORD, unknown_150);
	PROPERTY(DWORD, unknown_154);
	PROPERTY(DWORD, unknown_158);
	PROPERTY(DWORD, unknown_15C);
	PROPERTY(DWORD, unknown_160);
	PROPERTY(DWORD, unknown_164);
	PROPERTY(DWORD, unknown_168);
	PROPERTY(DWORD, unknown_16C);
	PROPERTY(DWORD, unknown_170);
	PROPERTY(DWORD, unknown_174);
	PROPERTY(BYTE, TranslucencyLevel); // on a scale of 1 - 100
	PROPERTY(bool, TimeToDie); // or something to that effect, set just before UnInit
	PROPERTY(BulletClass*, AttachedBullet);
	PROPERTY(HouseClass*, Owner); //Used for remap (AltPalette).
	PROPERTY(DWORD, unknown_184);
	PROPERTY(double, Damage); // defaults to 1.0 , added to Type->Damage in some cases 
//	PROPERTY(DWORD, unknown_18C);
	PROPERTY(eBlitterFlags, AnimFlags); // argument that's 0x600 most of the time
	PROPERTY(byte, unknown_194);
	PROPERTY(byte, RemainingIterations); // defaulted to deleteAfterIterations, when reaches zero, UnInit() is called
	PROPERTY(byte, unknown_196);
	PROPERTY(byte, unknown_197);
	PROPERTY(bool, IsPlaying);
	PROPERTY(bool, IsFogged);
	PROPERTY(byte, unknown_19A);
	PROPERTY(byte, CellOccupied); // dunno, that's the name my IDB gives
	PROPERTY(byte, unknown_19C);
	PROPERTY(bool, Invisible); // don't draw, but Update state anyway 
	PROPERTY(byte, unknown_19E);
	PROPERTY(byte, unknown_19F);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio3);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio4);
};

#endif
