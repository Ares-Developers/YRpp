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
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
	{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL(0x426540);}

	//IPersistStream
	virtual HRESULT _stdcall	Load(IStream* pStm)
								{PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x425280);}
	virtual HRESULT _stdcall	Save(IStream* pStm,BOOL fClearDirty)
								{PUSH_VAR32(fClearDirty);PUSH_VAR32(pStm);PUSH_VAR32(this);CALL(0x4253B0);}

	//Destructor
	virtual ~AnimClass()		{THISCALL(0x4228E0);}

	//AbstractClass
	virtual void				PointerExpired(void* p,bool bUnknown)
								{PUSH_VAR8(bUnknown);PUSH_VAR32(p);THISCALL(0x425150);}
	virtual eAbstractType		WhatAmI(){return abs_Anim;}
	virtual int					Size(){return sizeof(AnimClass);}
	virtual void				CalculateChecksum(void* pChkSum){PUSH_VAR32(pChkSum);THISCALL(0x425410);}
	virtual CoordStruct*		GetCoords(CoordStruct* pCrd){PUSH_VAR32(pCrd);THISCALL(0x422BE0);}
	virtual void				Update(){THISCALL(0x423AC0);}

	//ObjectClass
	virtual eLayer				InWhichLayer(){THISCALL(0x424CB0);}
	virtual ObjectTypeClass*	GetType(){return Type;}

	virtual int					vt_entry_B8(){THISCALL(0x422BC0);}
	virtual bool				vt_entry_D4(){THISCALL(0x425530);}
	virtual void				vt_entry_F0(DWORD dwUnk){PUSH_VAR32(dwUnk);THISCALL(0x426270);}
	virtual void				vt_entry_F4(DWORD dwUnk){PUSH_VAR32(dwUnk);THISCALL(0x426300);}
	virtual void				UnInit(){THISCALL(0x4255B0);}
	virtual bool				vt_entry_104(DWORD dwUnk,DWORD dwUnk2,DWORD dwUnk3)
								{PUSH_VAR32(dwUnk3);PUSH_VAR32(dwUnk2);PUSH_VAR32(dwUnk);THISCALL(0x422C70);}
	virtual DWORD				vt_entry_108(DWORD dwUnk){PUSH_VAR32(dwUnk);THISCALL(0x4238D0);}

	virtual void				Draw(Point2D* pCoords,DWORD dwUnk)
	{PUSH_VAR32(dwUnk);PUSH_VAR32(pCoords);THISCALL(0x422CA0);}
	virtual bool				SetLayer(eLayer nValue){PUSH_VAR32(nValue);THISCALL(0x4238B0);}
	virtual int					GetZ(){THISCALL(0x425630);}

	//AnimClass
	virtual void			AnimExtras(){};
	virtual int				GetEnd(){return Type->get_End();}	//End tag from the AnimType

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
	PROPERTY(DWORD,				unknown_1A0); // some struct { int x, y, z; void *ptr; } 
	PROPERTY(DWORD,				unknown_1A4); // also present in other classes, init'd at 0x405BE0
	PROPERTY(DWORD,				unknown_1A8); //
	PROPERTY(DWORD,				unknown_1AC); //
	PROPERTY(DWORD,				unknown_1B0);
	PROPERTY(DWORD,				unknown_1B4); // same struct
	PROPERTY(DWORD,				unknown_1B8); //
	PROPERTY(DWORD,				unknown_1BC); //
	PROPERTY(DWORD,				unknown_1C0); //
	PROPERTY(DWORD,				unknown_1C4);
};

#endif
