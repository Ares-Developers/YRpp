//Locomotor = {4A582746-9839-11d1-B709-00A024DDAFD1}

#pragma once

#include <LocomotionClass.h>

class NOVTABLE FlyLocomotionClass : public LocomotionClass
{
public:
	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//ILocomotion
	virtual bool __stdcall Is_Moving() R0;
	virtual CoordStruct* __stdcall Destination(CoordStruct* pcoord) R0;
	virtual bool __stdcall Process() R0;
	virtual void __stdcall Move_To(CoordStruct to) RX;
	virtual void __stdcall Stop_Moving() RX;
	virtual void __stdcall Do_Turn(DirStruct coord) RX;
	virtual Layer __stdcall In_Which_Layer() RT(Layer);
	virtual void __stdcall Mark_All_Occupation_Bits(int mark) RX;
	virtual void __stdcall ILocomotion_B8() RX;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~FlyLocomotionClass() RX;

	//LocomotionClass
	virtual	int Size() R0;

	//FlyLocomotionClass

	//Constructor
	FlyLocomotionClass()
		: LocomotionClass(noinit_t())
	{ JMP_THIS(0x4CC9A0); }

protected:
	explicit __forceinline FlyLocomotionClass(noinit_t)
		: LocomotionClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	bool AirportBound;
	CoordStruct MovingDestination;
	CoordStruct XYZ2;
	bool HasMoveOrder;
	int FlightLevel;
	double TargetSpeed;
	double CurrentSpeed;
	char IsTakingOff;
	bool IsLanding;
	bool WasLanding;
	bool unknown_bool_53;
	DWORD unknown_54;
	DWORD unknown_58;
	bool IsElevating;
	bool unknown_bool_5D;
	bool unknown_bool_5E;
	bool unknown_bool_5F;
};
