#ifndef WAVE_H
#define WAVE_H

#include <GeneralDefinitions.h>

class TechnoClass;

class WaveClass : ObjectClass
{
public:
	static DynamicVectorClass<WaveClass*>* Array;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this);CALL(0x75F650); }
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x75F7D0); }

	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL(0x75F840); }

	//Destructor
	virtual ~WaveClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x763200); }

	//AbstractClass
	virtual void PointerExpired(void* p,bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x75F610); }

	virtual eAbstractType WhatAmI()
		{ return abs_Wave; }

	virtual int Size()
		{ return sizeof(WaveClass); }

	virtual void Update()
		{ THISCALL(0x760F50); }

	virtual ObjectTypeClass * GetType()
		{ return NULL; }

	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCoords); THISCALL(0x75F9F0); }

	WaveClass(CoordStruct *From, CoordStruct *To, TechnoClass *Owner, int mode, TechnoClass *Target)
		{ PUSH_VAR32(Target); PUSH_VAR32(mode); PUSH_VAR32(Owner); PUSH_VAR32(To); PUSH_VAR32(From);
		  THISCALL(0x75E950); }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	
	PROPERTY(DWORD, unknown_A8);
	PROPERTY(TechnoClass*, Target);
	PROPERTY(int, Type);
	PROPERTY(Point2D, someCoords);
	PROPERTY_ARRAY(BYTE, unknown_BC, 73*4);
	PROPERTY(TechnoClass*, Owner);
	PROPERTY_STRUCT(FacingStruct, Facing);
	PROPERTY_STRUCT(DynamicVectorClass<CellClass *>, Cells);
	PROPERTY_ARRAY(BYTE, unknown_208, 14*4);
};

#endif