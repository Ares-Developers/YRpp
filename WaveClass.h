#ifndef WAVE_H
#define WAVE_H

#include <GeneralDefinitions.h>

class TechnoClass;

class WaveClass : public ObjectClass
{
public:
	static DynamicVectorClass<WaveClass*>* Array;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~WaveClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	void Draw_Magnetic(CoordStruct* xyzFrom, CoordStruct* xyzTo)
		{ PUSH_VAR32(xyzTo); PUSH_VAR32(xyzFrom); THISCALL(0x762070); }

	void Draw_NonMagnetic(CoordStruct* xyzFrom, CoordStruct* xyzTo)
		{ PUSH_VAR32(xyzTo); PUSH_VAR32(xyzFrom); THISCALL(0x761640); }

	void Update_Wave()
		{ THISCALL(0x762AF0); }

	// ambient
	void DamageArea(CoordStruct *location)
		{ PUSH_VAR32(location); THISCALL(0x75F330); }

	WaveClass(CoordStruct *From, CoordStruct *To, TechnoClass *Owner, int mode, AbstractClass *Target)
		{ PUSH_VAR32(Target); PUSH_VAR32(mode); PUSH_VAR32(Owner); PUSH_VAR32(To); PUSH_VAR32(From);
		  THISCALL(0x75E950); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(TechnoClass*, Target);
	PROPERTY(eWaveType, Type);
	PROPERTY(Point2D, someCoords);
	PROPERTY(DWORD, field_BC);
	PROPERTY(DWORD, field_C0);
	PROPERTY(DWORD, field_C4);
	PROPERTY(DWORD, field_C8);
	PROPERTY(DWORD, field_CC);
	PROPERTY(DWORD, field_D0);
	PROPERTY(DWORD, field_D4);
	PROPERTY(DWORD, field_D8);
	PROPERTY(DWORD, field_DC);
	PROPERTY(DWORD, field_E0);
	PROPERTY(DWORD, field_E4);
	PROPERTY(DWORD, field_E8);
	PROPERTY(DWORD, field_EC);
	PROPERTY(DWORD, field_F0);
	PROPERTY(DWORD, field_F4);
	PROPERTY(DWORD, field_F8);
	PROPERTY(DWORD, field_FC);
	PROPERTY(DWORD, field_100);
	PROPERTY(DWORD, field_104);
	PROPERTY(DWORD, field_108);
	PROPERTY(DWORD, field_10C);
	PROPERTY(DWORD, field_110);
	PROPERTY(DWORD, field_114);
	PROPERTY(DWORD, field_118);
	PROPERTY(DWORD, field_11C);
	PROPERTY(DWORD, field_120);
	PROPERTY(DWORD, field_124);
	PROPERTY(DWORD, field_128);
	PROPERTY(BYTE, field_12C);
	PROPERTY(BYTE, field_12D);
	PROPERTY(BYTE, field_12E);
	PROPERTY(BYTE, field_12F);
	PROPERTY(DWORD, WaveIntensity); // for sonic/magna only
	PROPERTY(DWORD, field_134);
	PROPERTY(DWORD, field_138);
	PROPERTY(DWORD, field_13C);
	PROPERTY(DWORD, field_140);
	PROPERTY(DWORD, field_144);
	PROPERTY(DWORD, field_148);
	PROPERTY(DWORD, field_14C);
	PROPERTY(DWORD, field_150);
	PROPERTY(DWORD, field_154);
	PROPERTY(DWORD, field_158);
	PROPERTY(DWORD, field_15C);
	PROPERTY(DWORD, field_160);
	PROPERTY(DWORD, field_164);
	PROPERTY(DWORD, field_168);
	PROPERTY(DWORD, field_16C);
	PROPERTY(DWORD, field_170);
	PROPERTY(DWORD, field_174);
	PROPERTY(DWORD, field_178);
	PROPERTY(DWORD, field_17C);
	PROPERTY(DWORD, field_180);
	PROPERTY(DWORD, field_184);
	PROPERTY(DWORD, field_188);
	PROPERTY(DWORD, field_18C);
	PROPERTY(DWORD, field_190);
	PROPERTY(DWORD, field_194);
	PROPERTY(DWORD, field_198);
	PROPERTY(DWORD, field_19C);
	PROPERTY(DWORD, field_1A0);
	PROPERTY(DWORD, field_1A4);
	PROPERTY(DWORD, field_1A8);
	PROPERTY(DWORD, field_1AC);
	PROPERTY(DWORD, field_1B0);
	PROPERTY(DWORD, field_1B4);
	PROPERTY(DWORD, field_1B8);
	PROPERTY(DWORD, field_1BC);
	PROPERTY(DWORD, field_1C0);
	PROPERTY(DWORD, field_1C4);
	PROPERTY(DWORD, field_1C8);
	PROPERTY(DWORD, field_1CC);
	PROPERTY(DWORD, LaserIntensity); // for lasers only, ctor = 160, per frame -= 6, 32 == dtor
	PROPERTY(TechnoClass*, Owner);
	PROPERTY_STRUCT(FacingStruct, Facing);
	PROPERTY_STRUCT(DynamicVectorClass<CellClass *>, Cells);
	PROPERTY_ARRAY(BYTE, unknown_208, 14*4);
};

#endif