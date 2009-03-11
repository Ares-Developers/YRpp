#ifndef INTERFACES_H
#define INTERFACES_H

#include <objidl.h>
#include <GeneralDefinitions.h>

interface ISwizzle : IUnknown{
    virtual HRESULT _stdcall Reset()=0;
    virtual HRESULT _stdcall Swizzle(void** pointer)=0;
    virtual HRESULT _stdcall Fetch_Swizzle_ID( void* pointer,long* id)=0;
    virtual HRESULT _stdcall Here_I_Am(long id,void* pointer)=0;
    virtual HRESULT _stdcall Save_Interface(IStream* stream,IUnknown* pointer)=0;
    virtual HRESULT _stdcall Load_Interface(IStream* stream,GUID* riid,void** pointer)=0;
    virtual HRESULT _stdcall Get_Save_Size(int* size)=0;
};

interface IApplication : IUnknown
{
    virtual HRESULT _stdcall FullName(BSTR* retval)=0;
    virtual HRESULT _stdcall Name(BSTR* retval)=0;
    virtual HRESULT _stdcall Quit()=0;
    virtual HRESULT _stdcall ScenarioName(BSTR* retval)=0;
    virtual HRESULT _stdcall FrameCount(long* retval)=0;
	virtual HRESULT _stdcall Swizzle_Interface(ISwizzle** pVal)=0;
};

interface INoticeSource
{
	virtual void _stdcall INoticeSource_Unknown()=0;
};

interface INoticeSink
{
	virtual bool _stdcall INoticeSink_Unknown(DWORD dwUnknown)=0;
};

interface IRTTITypeInfo : IUnknown
{
    virtual eAbstractType _stdcall What_Am_I()=0;
    virtual int _stdcall Fetch_ID()=0;
    virtual void _stdcall Create_ID()=0;
};

interface IHouse : IUnknown
{
	virtual long _stdcall				ID_Number()=0;
    virtual BSTR _stdcall				Name()=0;
    virtual IApplication* _stdcall		Get_Application()=0;
    virtual long _stdcall				Available_Money()=0;
    virtual long _stdcall				Available_Storage()=0;
    virtual long _stdcall				Power_Output()=0;
    virtual long _stdcall				Power_Drain()=0;
    virtual long _stdcall				Category_Quantity(eCategory category)=0;
    virtual long _stdcall				Category_Power(eCategory category)=0;
    virtual CellStruct _stdcall			Base_Center()=0;
    virtual HRESULT _stdcall			Fire_Sale()=0;
    virtual HRESULT _stdcall			All_To_Hunt()=0;
};

interface IPublicHouse : IUnknown
{
    virtual long _stdcall			ID_Number()=0;
    virtual BSTR _stdcall			Name()=0;
    virtual long _stdcall			Apparent_Category_Quantity(eCategory category)=0;
    virtual long _stdcall			Apparent_Category_Power(eCategory category)=0;
    virtual CellStruct _stdcall		Apparent_Base_Center()=0;
    virtual bool _stdcall	Is_Powered()=0;
};

typedef struct tagCONNECTDATA
{ 
	IUnknown* pUnk;  
	unsigned long dwCookie;
}	CONNECTDATA;

interface IEnumConnections : IUnknown
{
    virtual HRESULT _stdcall RemoteNext(unsigned long cConnections,CONNECTDATA* rgcd,unsigned long* pcFetched)=0;
    virtual HRESULT _stdcall Skip(unsigned long cConnections)=0;
    virtual HRESULT _stdcall Reset()=0;
    virtual HRESULT _stdcall Clone(IEnumConnections** ppEnum)=0;
};

interface IConnectionPointContainer;
interface IConnectionPoint : IUnknown
{
    virtual HRESULT _stdcall GetConnectionInterface(GUID* pIID)=0;
    virtual HRESULT _stdcall GetConnectionPointContainer(IConnectionPointContainer** ppCPC)=0;
    virtual HRESULT _stdcall Advise(IUnknown* pUnkSink,unsigned long* pdwCookie)=0;
    virtual HRESULT _stdcall Unadvise(unsigned long dwCookie)=0;
    virtual HRESULT _stdcall EnumConnections(IEnumConnections** ppEnum)=0;
};

interface IEnumConnectionPoints;
interface IConnectionPointContainer : IUnknown
{
    virtual HRESULT _stdcall	EnumConnectionPoints(IEnumConnectionPoints** ppEnum)=0;
    virtual HRESULT _stdcall	FindConnectionPoint(GUID* riid,IConnectionPoint** ppCP)=0;
};

interface IEnumConnectionPoints : IUnknown
{
    virtual HRESULT _stdcall RemoteNext(unsigned long cConnections,IConnectionPoint** ppCP,unsigned long* pcFetched)=0;
    virtual HRESULT _stdcall Skip(unsigned long cConnections)=0;
    virtual HRESULT _stdcall Reset()=0;
    virtual HRESULT _stdcall Clone(IEnumConnectionPoints** ppEnum)=0;
};

interface IGameMap : IUnknown
{
    virtual long _stdcall Is_Visible(CellStruct cell) = 0;
};

interface ILinkStream : IUnknown
{
	virtual HRESULT _stdcall Link_Stream(IUnknown* stream)=0;
	virtual HRESULT _stdcall Unlink_Stream(IUnknown** stream)=0;
};

interface IFlyControl : IUnknown
{
    virtual int _stdcall Landing_Altitude() = 0;
    virtual int _stdcall Landing_Direction() = 0;
    virtual long _stdcall Is_Loaded() = 0;
    virtual long _stdcall Is_Strafe() = 0;
    virtual long _stdcall Is_Fighter() = 0;
    virtual long _stdcall Is_Locked() = 0;
};

interface ILocomotion : IUnknown
{
    virtual HRESULT _stdcall Link_To_Object(void* pointer) = 0; //Links object to locomotor.
	virtual bool _stdcall Is_Moving() = 0;	//Sees if object is moving.
    virtual CoordStruct* _stdcall Destination(CoordStruct* pcoord) = 0;	//Fetches destination coordinate.
    virtual CoordStruct* _stdcall Head_To_Coord(CoordStruct* pcoord) = 0; // Fetches immediate (next cell) destination coordinate.
    virtual eMove _stdcall Can_Enter_Cell(CellStruct cell) = 0; //Determine if specific cell can be entered.
    virtual bool _stdcall Is_To_Have_Shadow() = 0;	//Should object cast a shadow?
    virtual Matrix3DStruct* _stdcall Draw_Matrix(Matrix3DStruct* pMatrix, int* key) = 0; //Fetch voxel draw matrix.
    virtual Matrix3DStruct* _stdcall Shadow_Matrix(Matrix3DStruct* pMatrix, int* key) = 0;	//Fetch shadow draw matrix.
    virtual Point2D* _stdcall Draw_Point(Point2D* pPoint) = 0;	//Draw point center location.
    virtual Point2D* _stdcall Shadow_Point(Point2D* pPoint) = 0;	//Shadow draw point center location.
    virtual eVisualType _stdcall Visual_Character(VARIANT_BOOL flag) = 0;	//Visual character for drawing.
    virtual int _stdcall Z_Adjust() = 0;	//Z adjust control value.
    virtual eZGradient _stdcall Z_Gradient() = 0;	//Z gradient control value.
    virtual bool _stdcall Process() = 0;	//Process movement of object.]
    virtual void _stdcall Move_To(CoordStruct to) = 0;	//Instruct to move to location specified.
    virtual void _stdcall Stop_Moving() = 0;	//Stop moving at first opportunity.
    virtual void _stdcall Do_Turn(DirStruct coord) = 0;	//Try to face direction specified.
    virtual void _stdcall Unlimbo() = 0;	//Object is appearing in the world.
    virtual void _stdcall Tilt_Pitch_AI() = 0;	//Special tilting AI function.
    virtual bool _stdcall Power_On() = 0;	//Locomotor becomes powered.
    virtual bool _stdcall Power_Off() = 0;	//Locomotor loses power.
    virtual bool _stdcall Is_Powered() = 0;	//Is locomotor powered?
    virtual bool _stdcall Is_Ion_Sensitive() = 0;	//Is locomotor sensitive to ion storms?
    virtual bool _stdcall Push(DirStruct dir) = 0;	//Push object in direction specified.
    virtual bool _stdcall Shove(DirStruct dir) = 0;	//Shove object (with spin) in direction specified.
    virtual void _stdcall Force_Track(int track, CoordStruct coord) = 0;	//Force drive track -- special case only.
    virtual eLayer _stdcall In_Which_Layer() = 0;	//What display layer is it located in.
    virtual void _stdcall Force_Immediate_Destination(CoordStruct coord) = 0;	//Don't use this function.
    virtual void _stdcall Force_New_Slope(int ramp) = 0;	//Force a voxel unit to a given slope. Used in cratering.
    virtual bool _stdcall Is_Moving_Now() = 0;	//Is it actually moving across the ground this very second?
    virtual int _stdcall Apparent_Speed() = 0;	//Actual current speed of object expressed as leptons per game frame.
    virtual int _stdcall Drawing_Code() = 0;	//Special drawing feedback code (locomotor specific meaning)
    virtual eFireError _stdcall Can_Fire() = 0;	//Queries if any locomotor specific state prevents the object from firing.
    virtual int _stdcall Get_Status() = 0;	//Queries the general state of the locomotor.
    virtual void _stdcall Acquire_Hunter_Seeker_Target() = 0;	//Forces a hunter seeker droid to find a target.
    virtual bool _stdcall Is_Surfacing() = 0;	//Is this object surfacing?
    virtual void _stdcall Mark_All_Occupation_Bits(int mark) = 0;	//Lifts all occupation bits associated with the object off the map
    virtual bool _stdcall Is_Moving_Here(CoordStruct to) = 0;	//Is this object in the process of moving into this coord.
    virtual bool _stdcall Will_Jump_Tracks() = 0;	//Will this object jump tracks?
    virtual bool _stdcall Is_Really_Moving_Now() = 0;	//Infantry moving query function
    virtual void _stdcall Stop_Movement_Animation() = 0;	//Falsifies the IsReallyMoving flag in WalkLocomotionClass
    virtual void _stdcall Lock() = 0;	//Locks the locomotor from being deleted
    virtual void _stdcall Unlock() = 0;	//Unlocks the locomotor from being deleted
	virtual void _stdcall ILocomotion_B8() = 0;	//Unknown, must have been added after LOCOS.TLB was generated. -pd
    virtual int _stdcall Get_Track_Number() = 0;	//Queries internal variables
    virtual int _stdcall Get_Track_Index() = 0;	//Queries internal variables
    virtual int _stdcall Get_Speed_Accum() = 0;	//Queries internal variables
};

interface IPiggyback : IUnknown //'Piggyback' one locomotor onto another.
{
    virtual HRESULT _stdcall Begin_Piggyback(ILocomotion* pointer) = 0;	//Piggybacks a locomotor onto this one.
    virtual HRESULT _stdcall End_Piggyback(ILocomotion** pointer) = 0;	//End piggyback process and restore locomotor interface pointer.
    virtual bool _stdcall Is_Ok_To_End() = 0;	//Is it ok to end the piggyback process?
    virtual HRESULT _stdcall Piggyback_CLSID(GUID* classid) = 0;	//Fetches piggybacked locomotor class ID.
    virtual bool _stdcall Is_Piggybacking() = 0;	//Is it currently piggy backing another locomotor?
};

#endif
