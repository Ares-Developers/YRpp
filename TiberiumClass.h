/*
	Tiberiums are initialized by INI files.
*/

#ifndef TIBERIUM_H
#define TIBERIUM_H

#include <AbstractTypeClass.h>

//forward declarations
class AnimTypeClass;
class OverlayTypeClass;

class TiberiumClass : public AbstractTypeClass
{
public:
	enum {AbsID = abs_Tiberium};

	//Array
	ABSTRACTTYPE_ARRAY(TiberiumClass);

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;
	virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize) R0;

	//Destructor
	virtual ~TiberiumClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//TiberiumClass

	void RegisterForGrowth(CellStruct* cell)
		{ JMP_THIS(0x7235A0); }

	//Static helpers

	static int FindIndex(int idxOverlayType) {
		SET_REG32(ecx, idxOverlayType);
		CALL(0x5FDD20);
	}

	static TiberiumClass* Find(int idxOverlayType) {
		int idx = FindIndex(idxOverlayType);
		return Array->GetItemOrDefault(idx);
	}

	//Constructor
	TiberiumClass(const char* pID) : AbstractTypeClass(false)
		{ JMP_THIS(0x7216C0); }

protected:
	TiberiumClass() : AbstractTypeClass(false) { }
	TiberiumClass(bool) : AbstractTypeClass(false) { };

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int ArrayIndex;
	int Spread;
	double SpreadPercentage;
	int Growth;
	double GrowthPercentage;
	int Value;
	int Power;
	int Color;
	TypeList<AnimTypeClass*> Debris;
	OverlayTypeClass* Image;
	int NumFrames;
	int NumImages;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	TimerStruct SpreadTimer;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	TimerStruct GrowthTimer;
};

#endif
