#pragma once

#include <GeneralDefinitions.h>

class TechnoClass;

class NOVTABLE WaveClass : public ObjectClass
{
public:
	static const AbstractType AbsID = AbstractType::Wave;

	static DynamicVectorClass<WaveClass*>* const Array;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//Destructor
	virtual ~WaveClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	void Draw_Magnetic(const CoordStruct& xyzFrom, const CoordStruct& xyzTo)
		{ JMP_THIS(0x762070); }

	void Draw_NonMagnetic(const CoordStruct& xyzFrom, const CoordStruct& xyzTo)
		{ JMP_THIS(0x761640); }

	void Update_Wave()
		{ JMP_THIS(0x762AF0); }

	// ambient
	void DamageArea(const CoordStruct& location) const
		{ JMP_THIS(0x75F330); }

	//Constructor
	WaveClass(
		const CoordStruct& From, const CoordStruct& To, TechnoClass *Owner,
		WaveType mode, AbstractClass *Target) : WaveClass(noinit_t())
	{ JMP_THIS(0x75E950); }

protected:
	explicit __forceinline WaveClass(noinit_t)
		: ObjectClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TechnoClass* Target;
	WaveType Type;
	Point2D someCoords;
	DWORD field_BC;
	DWORD field_C0;
	DWORD field_C4;
	DWORD field_C8;
	DWORD field_CC;
	DWORD field_D0;
	DWORD field_D4;
	DWORD field_D8;
	DWORD field_DC;
	DWORD field_E0;
	DWORD field_E4;
	DWORD field_E8;
	DWORD field_EC;
	DWORD field_F0;
	DWORD field_F4;
	DWORD field_F8;
	DWORD field_FC;
	DWORD field_100;
	DWORD field_104;
	DWORD field_108;
	DWORD field_10C;
	DWORD field_110;
	DWORD field_114;
	DWORD field_118;
	DWORD field_11C;
	DWORD field_120;
	DWORD field_124;
	DWORD field_128;
	BYTE field_12C;
	BYTE field_12D;
	BYTE field_12E;
	BYTE field_12F;
	DWORD WaveIntensity; // for sonic/magna only
	DWORD field_134;
	DWORD field_138;
	DWORD field_13C;
	DWORD field_140;
	DWORD field_144;
	DWORD field_148;
	DWORD field_14C;
	DWORD field_150;
	DWORD field_154;
	DWORD field_158;
	DWORD field_15C;
	DWORD field_160;
	DWORD field_164;
	DWORD field_168;
	DWORD field_16C;
	DWORD field_170;
	DWORD field_174;
	DWORD field_178;
	DWORD field_17C;
	DWORD field_180;
	DWORD field_184;
	DWORD field_188;
	DWORD field_18C;
	DWORD field_190;
	DWORD field_194;
	DWORD field_198;
	DWORD field_19C;
	DWORD field_1A0;
	DWORD field_1A4;
	DWORD field_1A8;
	DWORD field_1AC;
	DWORD field_1B0;
	DWORD field_1B4;
	DWORD field_1B8;
	DWORD field_1BC;
	DWORD field_1C0;
	DWORD field_1C4;
	DWORD field_1C8;
	DWORD field_1CC;
	DWORD LaserIntensity; // for lasers only, ctor = 160, per frame -= 6, 32 == dtor
	TechnoClass* Owner;
	FacingStruct Facing;
	DynamicVectorClass<CellClass *> Cells;
	BYTE unknown_208 [14*4];
};
