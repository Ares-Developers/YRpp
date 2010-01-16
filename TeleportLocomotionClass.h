//Locomotor = {4A582747-9839-11d1-B709-00A024DDAFD1}

#ifndef TELE_LOCO_H
#define TELE_LOCO_H

#include <LocomotionClass.h>

class TeleportLocomotionClass : public LocomotionClass, public IPiggyback
{
public:
	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IPiggyback
	virtual HRESULT __stdcall Begin_Piggyback(ILocomotion* pointer) R0;
	virtual HRESULT __stdcall End_Piggyback(ILocomotion** pointer) R0;
	virtual bool __stdcall Is_Ok_To_End() R0;
	virtual HRESULT __stdcall Piggyback_CLSID(GUID* classid) R0;
	virtual bool __stdcall Is_Piggybacking() R0;

	//ILocomotion
	virtual bool __stdcall Is_Moving() R0;
	virtual CoordStruct* __stdcall Destination(CoordStruct* pcoord) R0;
	virtual bool __stdcall Process() R0;
	virtual void __stdcall Move_To(CoordStruct to) RX;
	virtual void __stdcall Stop_Moving() RX;
	virtual void __stdcall Do_Turn(DirStruct coord) RX;
	virtual eLayer __stdcall In_Which_Layer() R0;
	virtual void __stdcall Mark_All_Occupation_Bits(int mark) RX;
	virtual void __stdcall ILocomotion_B8() RX;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeleportLocomotionClass() RX;

	//LocomotionClass
	virtual	int Size() R0;

	//TeleportLocomotionClass
	virtual void vt_entry_28(DWORD dwUnk) RX;
	virtual bool IsStill() R0;

	//Constructor
	TeleportLocomotionClass() : LocomotionClass(false)
		{ JMP_THIS(0x718000); }

protected:
	TeleportLocomotionClass(bool) : LocomotionClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROPERTY_STRUCT(CoordStruct,	MovingDestination);	//Current destination
	PROPERTY_STRUCT(CoordStruct,	unknown_coords_28);
	PROPERTY(bool,			Moving);	//Is currently moving
	PROPERTY(bool,			unknown_bool_35);
	PROPERTY(bool,			unknown_bool_36);
	PROPERTY(DWORD,			unknown_38);
	PROPERTY_STRUCT(TimerStruct,	unknown_timer_3C);
	PROPERTY(DWORD,			unknown_48);
};

#endif
