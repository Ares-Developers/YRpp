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

	void SetOwnerObject(ObjectClass *Owner)
		{ PUSH_VAR32(Owner); THISCALL(0x424B50); }

	//Constructor
	AnimClass(AnimTypeClass* pAnimType,CoordStruct Location):ObjectClass(false)
	{
		//VTABLE_BACKUP;
		PUSH_IMM(0);		//???
		PUSH_IMM(0);		//ZAdjust
		PUSH_IMM(0x600);	// certain calls use 0x1600 or 0x2600 instead, iow bitfield
		PUSH_IMM(1);		//deleteAfterIterations
		PUSH_IMM(0);		//???
		PUSH_PTR(Location);
		PUSH_VAR32(pAnimType);
		THISCALL(0x421EA0);
		//VTABLE_RESTORE;
	}

protected:
	AnimClass():ObjectClass(false){}
	AnimClass(bool X):ObjectClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY(int,					CurrentFrame);		//Current animation frame.
	PROPERTY(DWORD,					unknown_B0);
	PROPERTY_STRUCT(TimerStruct,			IterationTimer); // Duration == Type->Rate, each expiration decrements remainingIterations
	PROPERTY(DWORD,					unknown_C0);
	PROPERTY(DWORD,					unknown_C4);
	PROPERTY(AnimTypeClass*,		Type);				//The AnimType.
	PROPERTY(ObjectClass *,	OwnerObject); // set by AnimClass::SetOwnerObject (0x424B50)
	PROPERTY(DWORD,					unknown_D0);
	PROPERTY(LightConvertClass*,	LightConvert);		//Palette?
	PROPERTY(DWORD,				unknown_D8);
	PROPERTY(DWORD,				unknown_DC);
	PROPERTY(DWORD,				unknown_E0);
	PROPERTY(DWORD,				unknown_E4);
	PROPERTY(DWORD,				unknown_E8);
	PROPERTY(DWORD,				unknown_EC);
	PROPERTY(DWORD,				unknown_F0);
	PROPERTY(DWORD,				unknown_F4);
	PROPERTY(DWORD,				unknown_F8);
	PROPERTY(DWORD,				unknown_FC);
	PROPERTY(int,				ZAdjust);
	PROPERTY(int,				YSortAdjust); // same as YSortAdjust from Type
	PROPERTY(DWORD,				unknown_108);
	PROPERTY(DWORD,				unknown_10C);
	PROPERTY(DWORD,				unknown_110);
	PROPERTY(DWORD,				unknown_114);
	PROPERTY(DWORD,				unknown_118);
	PROPERTY(DWORD,				unknown_11C);
	PROPERTY(DWORD,				unknown_120);
	PROPERTY(DWORD,				unknown_124);
	PROPERTY(DWORD,				unknown_128);
	PROPERTY(DWORD,				unknown_12C);
	PROPERTY(DWORD,				unknown_130);
	PROPERTY(DWORD,				unknown_134);
	PROPERTY(DWORD,				unknown_138);
	PROPERTY(DWORD,				unknown_13C);
	PROPERTY(DWORD,				unknown_140);
	PROPERTY(DWORD,				unknown_144);
	PROPERTY(DWORD,				unknown_148);
	PROPERTY(DWORD,				unknown_14C);
	PROPERTY(DWORD,				unknown_150);
	PROPERTY(DWORD,				unknown_154);
	PROPERTY(DWORD,				unknown_158);
	PROPERTY(DWORD,				unknown_15C);
	PROPERTY(DWORD,				unknown_160);
	PROPERTY(DWORD,				unknown_164);
	PROPERTY(DWORD,				unknown_168);
	PROPERTY(DWORD,				unknown_16C);
	PROPERTY(DWORD,				unknown_170);
	PROPERTY(DWORD,				unknown_174);
	PROPERTY(byte,				TranslucencyLevel); // on a scale of 1 - 100
	PROPERTY(bool,				TimeToDie); // or something to that effect, set just before UnInit
	PROPERTY(BulletClass*,			AttachedBullet);
	PROPERTY(HouseClass*,			Owner);				//Used for remap (AltPalette).
//	PROTECTED_PROPERTY(BYTE,		unknown_184[0x44]); // DC - removing since not true
	PROPERTY(DWORD,				unknown_184);
	PROPERTY(double,			Damage); // defaults to 1.0 , added to Type->Damage in some cases 
//	PROPERTY(DWORD,				unknown_18C);
	PROPERTY(DWORD,				animFlags); // argument that's 0x600 most of the time
	PROPERTY(byte,				unknown_194);
	PROPERTY(byte,				remainingIterations); // defaulted to deleteAfterIterations, when reaches zero, UnInit() is called
	PROPERTY(byte,				unknown_196);
	PROPERTY(byte,				unknown_197);
	PROPERTY(bool,				IsPlaying);
	PROPERTY(byte,				unknown_199);
	PROPERTY(byte,				unknown_19A);
	PROPERTY(byte,				unknown_19B);
	PROPERTY(byte,				unknown_19C);
	PROPERTY(bool,				Invisible); // don't draw, but Update state anyway 
	PROPERTY(byte,				unknown_19E);
	PROPERTY(byte,				unknown_19F);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio3);
	PROPERTY_STRUCT(Unsorted::AudioController, Audio4);
};

#endif
