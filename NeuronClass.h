/*
	I have not the slightest idea what this is good for...
*/

#pragma once

#include <AbstractClass.h>

class NOVTABLE NeuronClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::Neuron;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~NeuronClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);

	virtual int Size() const R0;

	//Constructor
	NeuronClass() noexcept
		: NeuronClass(noinit_t())
	{ JMP_THIS(0x43A350); }

protected:
	explicit __forceinline NeuronClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	void* unknown_ptr_24;
	void* unknown_ptr_28;
	void* unknown_ptr_2C;
	TimerStruct unknown_timer_30;
};

//Even more questions marks on the use of this... >.<
class BrainClass
{
public:
	virtual ~BrainClass() RX;

	BrainClass()
		{ THISCALL(0x43A600); }

	//Properties
	VectorClass<NeuronClass*> Neurons;	//???
};
