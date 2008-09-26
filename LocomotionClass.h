//Here we go!

#ifndef LOCO_H
#define LOCO_H

#include <Interfaces.h>
#include <FootClass.h>

class LocomotionClass : public IPersistStream, public ILocomotion
{
public:
	//IUnknown
	virtual HRESULT _stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ PUSH_VAR32(ppvObject); PUSH_VAR32(iid); PUSH_VAR32(this); CALL(0x55A9B0); }

	virtual ULONG _stdcall AddRef()
		{ PUSH_VAR32(this); CALL(0x55A950); }

	virtual ULONG _stdcall Release()
		{ PUSH_VAR32(this); CALL(0x55A970); }

	//ILocomotion

	virtual HRESULT _stdcall Link_To_Object(void* pointer)
		{ PUSH_VAR32(pointer); PUSH_VAR32(this); CALL(0x55A710); }

	virtual bool _stdcall Is_Moving()
		{ return false; }

	virtual CoordStruct* _stdcall Destination(CoordStruct* pcoord)
		{
			pcoord->X = 0;
			pcoord->Y = 0;
			pcoord->Z = 0;
			return pcoord;
		}

	virtual CoordStruct* _stdcall Head_To_Coord(CoordStruct* pcoord)
		{
			pcoord->X = LinkedTo->get_Location()->X;
			pcoord->Y = LinkedTo->get_Location()->Y;
			pcoord->Z = LinkedTo->get_Location()->Z;
			return pcoord;
		}

	virtual eMove _stdcall Can_Enter_Cell(CellStruct cell)
		{ return move_OK; }

	virtual bool _stdcall Is_To_Have_Shadow()
		{ return true; }

	virtual Matrix3DStruct* _stdcall Draw_Matrix(Matrix3DStruct* pMatrix, int* key)
		{ PUSH_VAR32(key); PUSH_VAR32(pMatrix); PUSH_VAR32(this); CALL(0x55A730); }

	virtual Matrix3DStruct* _stdcall Shadow_Matrix(Matrix3DStruct* pMatrix, int* key)
		{ PUSH_VAR32(key); PUSH_VAR32(pMatrix); PUSH_VAR32(this); CALL(0x55A7D0); }

	virtual Point2D* _stdcall Draw_Point(Point2D* pPoint)
		{ 
			pPoint->X = 0;
			pPoint->Y = 0;
			return pPoint;
		}

	virtual Point2D* _stdcall Shadow_Point(Point2D* pPoint)
		{ PUSH_VAR32(pPoint); PUSH_VAR32(this); CALL(0x55A8C0); }

	virtual eVisualType _stdcall Visual_Character(VARIANT_BOOL flag)
		{ return vt_Normal; }

	virtual int _stdcall Z_Adjust()
		{ return 0; }

	virtual eZGradient _stdcall Z_Gradient()
		{ return zgrad_90Deg; }

	virtual bool _stdcall Process()
		{ return true; }

	virtual void _stdcall Move_To(CoordStruct to) { }
	virtual void _stdcall Stop_Moving() { }
	virtual void _stdcall Do_Turn(DirStruct coord) { }
	virtual void _stdcall Unlimbo() { }
	virtual void _stdcall Tilt_Pitch_AI() { }

	virtual bool _stdcall Power_On()
		{ Powered = true; return Is_Powered(); }

	virtual bool _stdcall Power_Off()
		{ Powered = false; return Is_Powered(); }

	virtual bool _stdcall Is_Powered()
		{ return Powered; }
	
	virtual bool _stdcall Is_Ion_Sensitive()
		{ return false; }

	virtual bool _stdcall Push(DirStruct dir)
		{ return false; }

	virtual bool _stdcall Shove(DirStruct dir)
		{ return false; }

	virtual void _stdcall Force_Track(int track, CoordStruct coord) { }

	//In_Which_Layer is not overloaded by LocomotionClass!

	virtual void _stdcall Force_Immediate_Destination(CoordStruct coord) { }
	virtual void _stdcall Force_New_Slope(int ramp){ }

	virtual bool _stdcall Is_Moving_Now()
		{ return Is_Moving(); }

	virtual int _stdcall Apparent_Speed()
		{ return LinkedTo->GetCurrentSpeed(); }

	virtual int _stdcall Drawing_Code()
		{ return 0; }

	virtual eFireError _stdcall Can_Fire() 
		{ return fire_OK; }

	virtual int _stdcall Get_Status()
		{ return 0; }

	virtual void _stdcall Acquire_Hunter_Seeker_Target() { }

	virtual bool _stdcall Is_Surfacing()
		{ return false; }

	virtual void _stdcall Mark_All_Occupation_Bits(int mark) { }

	virtual bool _stdcall Is_Moving_Here(CoordStruct to)
		{ return false; }

	virtual bool _stdcall Will_Jump_Tracks()
		{ return false; }

	virtual bool _stdcall Is_Really_Moving_Now()
		{ return Is_Moving_Now(); }

	virtual void _stdcall Stop_Movement_Animation() { }
	virtual void _stdcall Lock() { }
	virtual void _stdcall Unlock() { }
	virtual void _stdcall ILocomotion_B8() { }

	virtual int _stdcall Get_Track_Number()
		{ return -1; }

	virtual int _stdcall Get_Track_Index()
		{ return -1; }

	virtual int _stdcall Get_Speed_Accum()
		{ return -1; }

	//IPersistStream
	virtual HRESULT _stdcall IsDirty()
		{ return Dirty ? S_OK: S_FALSE; }

	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ PUSH_VAR32(fClearDirty); PUSH_VAR32(pStm); PUSH_VAR32(this); CALL(0x55AA60); }
	
	virtual HRESULT _stdcall GetSizeMax(ULARGE_INTEGER* pcbSize)
		{ PUSH_VAR32(pcbSize); PUSH_VAR32(this); CALL(0x55AB40); }

	//Destructor
	virtual ~LocomotionClass()
		{ THISCALL(0x55A6F0); }

	//LocomotionClass
	virtual	int Size() = 0;

	// blargh fsssds
	// LocomotionClass *Dummy = NULL;
	// Xchg(&foot->Locomotion, &Dummy);
	// foot's loco is now NULL, Dummy contains a pointer to its old content
	static HRESULT Xchg(LocomotionClass **Old, LocomotionClass **New)
		{ PUSH_VAR32(New); SET_REG32(ECX, Old); CALL(0x45AF20); }

	static HRESULT CreateInstance(LocomotionClass **ppv, CLSID *rclsid, LPUNKNOWN pUnkOuter, int arg)
		{ PUSH_VAR32(arg); PUSH_VAR32(pUnkOuter); PUSH_VAR32(rclsid); SET_REG32(ECX, ppv); CALL(0x41C250); }

	// these two are identical, why do they both exist...
	static void AddRef1(LocomotionClass **Loco)
		{ SET_REG32(ECX, Loco); CALL(0x45A170); }

	static void AddRef2(LocomotionClass **Loco)
		{ SET_REG32(ECX, Loco); CALL(0x6CE270); }

	//Constructor
	LocomotionClass()
		{ THISCALL(0x55A6C0); }

protected:
	LocomotionClass(bool) { }	//Hack to make child functions not call the base class constructor

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(DWORD,				unknown_08);
	PROPERTY(FootClass*,		LinkedTo);	//This Locomotor is linked to this object.
	PROPERTY(bool,				Powered);	//Does this Locomotor currently have power?
	PROPERTY(bool,				Dirty);		//bIsDirty - Has something changed?
	PROPERTY(DWORD,				unknown_14);
};

#endif
