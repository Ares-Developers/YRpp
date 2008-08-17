/*
	I have not the slightest idea what this is good for...
*/

#ifndef NEURON_H
#define NEURON_H

#include <AbstractClass.h>

class NeuronClass : public AbstractClass
{
public:
	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{PUSH_VAR32(pClassID);PUSH_VAR32(this);CALL_RET(0x43A500, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x43A540, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x43A5B0, HRESULT); }

	//Destructor
	virtual ~NeuronClass()	
		{ THISCALL(0x43A440); }

	//AbstractClass
	virtual eAbstractType WhatAmI()
		{ return abs_Neuron; }

	virtual int	Size()
		{ return sizeof(NeuronClass); }

	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x43A5D0); }

	//Constructor
	NeuronClass() : AbstractClass(false)
		{ THISCALL(0x43A350); }

protected:
	NeuronClass(bool X):AbstractClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(void*,			unknown_ptr_24);
	PROPERTY(void*,			unknown_ptr_28);
	PROPERTY(void*,			unknown_ptr_2C);
	PROPERTY(TimerStruct,	unknown_timer_30);
};

//Even more questions marks on the use of this... >.<
class BrainClass
{
public:
	virtual ~BrainClass()
	{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x43AA90); }

	BrainClass()
	{ THISCALL(0x43A600); }

	//Properties
	PROPERTY(VectorClass<NeuronClass*>, Neurons);	//???
};

#endif
