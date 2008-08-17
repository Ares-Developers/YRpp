//Locomotor = {4A582747-9839-11d1-B709-00A024DDAFD1}

#ifndef TELE_LOCO_H
#define TELE_LOCO_H

#include <LocomotionClass.h>

class TeleportLocomotionClass : public LocomotionClass, public IPiggyback
{
public:
	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL_RET(0x719E30, HRESULT); }
	virtual ULONG _stdcall AddRef()
		{ PUSH_VAR32(this); CALL_RET(0x55A950, ULONG); }
	virtual ULONG _stdcall Release()
		{ PUSH_VAR32(this); CALL_RET(0x55A970, ULONG); }

	//IPiggyback
	virtual HRESULT _stdcall Begin_Piggyback(ILocomotion* pointer)
		{ PUSH_VAR32(pointer); PUSH_VAR32(this); CALL_RET(0x719E90, HRESULT); }
	virtual HRESULT _stdcall End_Piggyback(ILocomotion** pointer)
		{ PUSH_VAR32(pointer); PUSH_VAR32(this); CALL_RET(0x719EE0, HRESULT); }
	virtual bool _stdcall Is_Ok_To_End()
		{ PUSH_VAR32(this); CALL_RET(0x719F30, bool); }
	virtual HRESULT _stdcall Piggyback_CLSID(GUID* classid)
		{ PUSH_VAR32(classid); PUSH_VAR32(this); CALL_RET(0x719F80, HRESULT); }
	virtual bool _stdcall Is_Piggybacking()
		{ PUSH_VAR32(this); CALL_RET(0x71A100, bool); }

	//ILocomotion
	virtual bool _stdcall Is_Moving()
		{ return Moving; }

	virtual CoordStruct* _stdcall Destination(CoordStruct* pcoord)
		{
			if(Is_Moving())
			{
				pcoord->X = MovingDestination.X;
				pcoord->Y = MovingDestination.Y;
				pcoord->Z = MovingDestination.Z;
			}
			else
			{
				pcoord->X = LinkedTo->get_Location()->X;
				pcoord->Y = LinkedTo->get_Location()->Y;
				pcoord->Z = LinkedTo->get_Location()->Z;
			}
			return pcoord;
		}
	virtual bool _stdcall Process()
		{ PUSH_VAR32(this); CALL_RET(0x7192F0, bool); }

	virtual void _stdcall Move_To(CoordStruct to)
		{
			PUSH_VAR32(to.Z);
			PUSH_VAR32(to.Y);
			PUSH_VAR32(to.X);
			PUSH_VAR32(this);
			CALL(0x718100);
		}

	virtual void _stdcall Stop_Moving()
		{ PUSH_VAR32(this); CALL(0x718230); }

	// .Facing because otherwise gcc gets confused when trying to fit this in 16 bits
	virtual void _stdcall Do_Turn(DirStruct coord)
		{ PUSH_VAR16(coord.Facing); CALL(0x7192C0); }

	virtual eLayer _stdcall In_Which_Layer()
		{ return lyr_Ground; }

	virtual void _stdcall Mark_All_Occupation_Bits(int mark)
		{ PUSH_VAR32(mark); PUSH_VAR32(this); CALL(0x71A090); }

	virtual void _stdcall ILocomotion_B8() { }

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID)
		{ PUSH_VAR32(pClassID); PUSH_VAR32(this); CALL_RET(0x719C60, HRESULT); }

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x719CA0, HRESULT); }
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x719D40, HRESULT); }

	//Destructor
	virtual ~TeleportLocomotionClass()
		{ PUSH_IMM(SDDTOR_NODELETE); THISCALL(0x71A130); }

	//LocomotionClass
	virtual	int Size()
		{ return sizeof(TeleportLocomotionClass); }

	//TeleportLocomotionClass
	virtual void vt_entry_28(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x719BF0); }

	virtual bool IsStill()
		{ return !Is_Moving(); }

	//Constructor
	TeleportLocomotionClass() : LocomotionClass(false)
		{ THISCALL(0x718000); }

protected:
	TeleportLocomotionClass(bool X) : LocomotionClass(X) { }

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
