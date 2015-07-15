//Here we go!

/*
NOTE:
	The locos should NOT become victims of Operation: The Cleansing,
	since we will possibly want to derive classes from them!

	-pd
*/

#pragma once

#include <Interfaces.h>
#include <FootClass.h>
#include <Unsorted.h>
#include <YRCom.h>
#include <Helpers/ComPtr.h>

class NOVTABLE LocomotionClass : public IPersistStream, public ILocomotion
{
public:

	class CLSIDs {
	public:
		static const CLSID &Drive;
		static const CLSID &Jumpjet;
		static const CLSID &Hover;
		static const CLSID &Rocket;
		static const CLSID &Tunnel;
		static const CLSID &Walk;
		static const CLSID &Droppod;
		static const CLSID &Fly;
		static const CLSID &Teleport;
		static const CLSID &Mech;
		static const CLSID &Ship;
	};

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject)
		{ JMP_STD(0x55A9B0); }

	virtual ULONG __stdcall AddRef()
		{ JMP_STD(0x55A950); }

	virtual ULONG __stdcall Release()
		{ JMP_STD(0x55A970); }

	//ILocomotion

	virtual HRESULT __stdcall Link_To_Object(void* pointer)
		{ JMP_STD(0x55A710); }

	virtual bool __stdcall Is_Moving()
		{ return false; }

	virtual CoordStruct* __stdcall Destination(CoordStruct* pcoord)
		{
			pcoord->X = 0;
			pcoord->Y = 0;
			pcoord->Z = 0;
			return pcoord;
		}

	virtual CoordStruct* __stdcall Head_To_Coord(CoordStruct* pcoord)
		{
			*pcoord = LinkedTo->Location;
			return pcoord;
		}

	virtual Move __stdcall Can_Enter_Cell(CellStruct cell)
		{ return Move::OK; }

	virtual bool __stdcall Is_To_Have_Shadow()
		{ return true; }

	virtual Matrix3DStruct* __stdcall Draw_Matrix(Matrix3DStruct* pMatrix, int* key)
		{ JMP_STD(0x55A730); }

	virtual Matrix3DStruct* __stdcall Shadow_Matrix(Matrix3DStruct* pMatrix, int* key)
		{ JMP_STD(0x55A7D0); }

	virtual Point2D* __stdcall Draw_Point(Point2D* pPoint)
		{
			pPoint->X = 0;
			pPoint->Y = 0;
			return pPoint;
		}

	virtual Point2D* __stdcall Shadow_Point(Point2D* pPoint)
		{ JMP_STD(0x55A8C0); }

	virtual VisualType __stdcall Visual_Character(VARIANT_BOOL bUnused)
		{ return VisualType::Normal; }

	virtual int __stdcall Z_Adjust()
		{ return 0; }

	virtual ZGradient __stdcall Z_Gradient()
		{ return ZGradient::Deg90; }

	virtual bool __stdcall Process()
		{ return true; }

	virtual void __stdcall Move_To(CoordStruct to) { }
	virtual void __stdcall Stop_Moving() { }
	virtual void __stdcall Do_Turn(DirStruct coord) { }
	virtual void __stdcall Unlimbo() { }
	virtual void __stdcall Tilt_Pitch_AI() { }

	virtual bool __stdcall Power_On()
		{ Powered = true; return Is_Powered(); }

	virtual bool __stdcall Power_Off()
		{ Powered = false; return Is_Powered(); }

	virtual bool __stdcall Is_Powered()
		{ return Powered; }

	virtual bool __stdcall Is_Ion_Sensitive()
		{ return false; }

	virtual bool __stdcall Push(DirStruct dir)
		{ return false; }

	virtual bool __stdcall Shove(DirStruct dir)
		{ return false; }

	virtual void __stdcall Force_Track(int track, CoordStruct coord) { }

	//In_Which_Layer is not overloaded by LocomotionClass!

	virtual void __stdcall Force_Immediate_Destination(CoordStruct coord) { }
	virtual void __stdcall Force_New_Slope(int ramp){ }

	virtual bool __stdcall Is_Moving_Now()
		{ return Is_Moving(); }

	virtual int __stdcall Apparent_Speed()
		{ return LinkedTo->GetCurrentSpeed(); }

	virtual int __stdcall Drawing_Code()
		{ return 0; }

	virtual FireError __stdcall Can_Fire()
		{ return FireError::OK; }

	virtual int __stdcall Get_Status()
		{ return 0; }

	virtual void __stdcall Acquire_Hunter_Seeker_Target() { }

	virtual bool __stdcall Is_Surfacing()
		{ return false; }

	virtual void __stdcall Mark_All_Occupation_Bits(int mark) { }

	virtual bool __stdcall Is_Moving_Here(CoordStruct to)
		{ return false; }

	virtual bool __stdcall Will_Jump_Tracks()
		{ return false; }

	virtual bool __stdcall Is_Really_Moving_Now()
		{ return Is_Moving_Now(); }

	virtual void __stdcall Stop_Movement_Animation() { }
	virtual void __stdcall Lock() { }
	virtual void __stdcall Unlock() { }
	virtual void __stdcall ILocomotion_B8() { }

	virtual int __stdcall Get_Track_Number()
		{ return -1; }

	virtual int __stdcall Get_Track_Index()
		{ return -1; }

	virtual int __stdcall Get_Speed_Accum()
		{ return -1; }

	//IPersistStream
	virtual HRESULT __stdcall IsDirty()
		{ return Dirty ? S_OK: S_FALSE; }

	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty)
		{ JMP_STD(0x55AA60); }

	virtual HRESULT __stdcall GetSizeMax(ULARGE_INTEGER* pcbSize)
		{ JMP_STD(0x55AB40); }

	//Destructor
	virtual ~LocomotionClass()
		{ JMP_THIS(0x55A6F0); }

	//LocomotionClass
	virtual	int Size() = 0;

	// ---------------------------------------------------

	// wow, I was so wrong about this
	// will fill Piggy with the right pointer if the Loco supports it
	static HRESULT TryPiggyback(IPiggyback **Piggy, ILocomotion **Loco)
		{ PUSH_VAR32(Loco); SET_REG32(ECX, Piggy); CALL(0x45AF20); }

	static HRESULT CreateInstance(ILocomotion **ppv, const CLSID *rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext)
		{ PUSH_VAR32(dwClsContext); PUSH_VAR32(pUnkOuter); PUSH_VAR32(rclsid); SET_REG32(ECX, ppv); CALL(0x41C250); }

	// these two are identical, why do they both exist...
	static void AddRef1(LocomotionClass **Loco)
		{ SET_REG32(ECX, Loco); CALL(0x45A170); }

	static void AddRef2(LocomotionClass **Loco)
		{ SET_REG32(ECX, Loco); CALL(0x6CE270); }

	static void ChangeLocomotorTo(FootClass *Object, const CLSID &clsid) {
		// remember the current one
		YRComPtr<ILocomotion> Original(Object->Locomotor);

		// create a new locomotor and link it
		auto NewLoco = CreateInstance(clsid);
		NewLoco->Link_To_Object(Object);

		// get piggy interface and piggy original
		YRComPtr<IPiggyback> Piggy(NewLoco);
		Piggy->Begin_Piggyback(Original.get());

		// replace the current locomotor
		Object->Locomotor = std::move(NewLoco);
	}

	// creates a new instance by class ID. returns a pointer to ILocomotion
	static YRComPtr<ILocomotion> CreateInstance(const CLSID &rclsid) {
		return YRComPtr<ILocomotion>(rclsid, nullptr,
			CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER);
	}

	// finds out whether a locomotor is currently piggybacking and restores
	// the original locomotor. this function ignores Is_Ok_To_End().
	static bool End_Piggyback(YRComPtr<ILocomotion> &pLoco) {
		if(!pLoco) {
			Game::RaiseError(E_POINTER);
		}

		if(YRComPtr<IPiggyback> pPiggy = pLoco) {
			if(pPiggy->Is_Piggybacking()) {
				// this frees the current locomotor
				pLoco.reset(nullptr);

				// this restores the old one
				auto res = pPiggy->End_Piggyback(pLoco.pointer_to());
				if(FAILED(res)) {
					Game::RaiseError(res);
				}
				return (res == S_OK);
			}
		}

		return false;
	}

/*
	static void RestoreLocomotor(FootClass *Object) {
		ILocomotion * currentLoco = Object->Locomotor;

		DWORD lptr = reinterpret_cast<DWORD>(currentLoco);
		lptr -= 4;
		LocomotionClass* theMotion = reinterpret_cast<LocomotionClass *>(lptr); // dirty... so dirty...

		theMotion->AddRef();
		ILocomotion ** ptr = &Object->Locomotor;
		ReleaseIf(*ptr);
		*ptr = 0;
		// theMotion->EndPiggyback(ptr); only works if the locomotor supports piggyback -> should be done from inside the locomotor itself
		theMotion->Release();
	}
*/

	// ----------------------------------------------------

	//Constructor
	LocomotionClass()
		: LocomotionClass(noinit_t())
	{ JMP_THIS(0x55A6C0); }

protected:
	explicit __forceinline LocomotionClass(noinit_t)
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	DWORD unknown_08;
	FootClass* LinkedTo;	//This Locomotor is linked to this object.
	bool Powered;	//Does this Locomotor currently have power?
	bool Dirty;		//bIsDirty - Has something changed?
	LONG RefCount; // COM reference count. Don't touch.
};
