/*
	Base class for all game objects.
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <Drawing.h>
#include <AbstractClass.h>

//forward declarations
class AnimClass;
class BombClass;
class BuildingTypeClass;
class CellClass;
class InfantryTypeClass;
class ObjectTypeClass;
class TechnoClass;
class TechnoTypeClass;
class WarheadTypeClass;

class LineTrail;
struct WeaponStruct;

class ObjectClass : public AbstractClass
{
public:
	//global arrays
	static DynamicVectorClass<ObjectClass*>* CurrentObjects;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;

	//Destructor
	virtual ~ObjectClass() RX;

	//AbstractClass

	//ObjectClass
	virtual void AnimPointerExpired(AnimClass* pAnim) RX;
	virtual bool IsSelectable() R0;
	virtual eVisualType VisualCharacter(VARIANT_BOOL flag, DWORD dwUnk) R0;
	virtual SHPStruct* GetImage() R0;
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2) R0;
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1) R0;
	virtual eLayer InWhichLayer() R0;
	virtual bool vt_entry_7C() R0;
	virtual bool CanBeUndeployed() R0;
	virtual TechnoTypeClass* GetTechnoType() R0;
	virtual ObjectTypeClass* GetType() R0;
	virtual DWORD GetTypeOwners() R0;
	virtual wchar_t* GetUIName() R0;
	virtual bool CanBeRepaired() R0;
	virtual bool CanBeSold() R0;
	virtual bool IsActive() R0;
	virtual bool vt_entry_A0() R0;
	virtual CoordStruct* vt_entry_A4(CoordStruct* pCrd) R0;
	virtual CoordStruct* vt_entry_A8(CoordStruct* pCrd, DWORD dwUnk) R0;
	virtual CoordStruct* vt_entry_AC(CoordStruct* pCrd) R0;
	virtual CoordStruct* GetFLH(CoordStruct *pDest, int idxWeapon, int nFLH_X, int nFLH_Y, int nFLH_Z) R0;
	virtual CoordStruct* GetExitCoords(CoordStruct* pCrd, DWORD dwUnk) R0;
	virtual int vt_entry_B8() R0;
	virtual bool vt_entry_BC(DWORD dwUnk) R0;
	virtual bool vt_entry_C0() R0;
	virtual bool IsDisguised() R0;
	virtual bool IsDisguisedAs(HouseClass *target) R0;
	virtual ObjectTypeClass* GetDisguise(bool DisguisedAgainstAllies) R0;
	virtual HouseClass* GetDisguiseHouse(bool DisguisedAgainstAllies) R0;
	virtual bool vt_entry_D4() R0;
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir) R0;
	virtual void vt_entry_DC(DWORD dwUnk) RX;
	virtual void RegisterDestruction(TechnoClass *Destroyer) RX;
	 // maybe Object instead of Techno? Raises Map Events, grants veterancy, increments house kill counters
	virtual void RegisterDestruction(HouseClass *Destroyer) RX; // ++destroyer's kill counters , etc
	virtual bool SpawnParachuted(CoordStruct *coords) R0;
	virtual void vt_entry_EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual void vt_entry_F0(DWORD dwUnk) RX;
	virtual void vt_entry_F4(CoordStruct *coords) RX;
	virtual void UnInit() RX;
	virtual void Uncloak2() RX;// just calls this->Uncloak(0) on TechnoClass and higher
	virtual int KickOutUnit(TechnoClass* pTechno, CellStruct uCell) R0;
	virtual bool vt_entry_104(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual DWORD vt_entry_108(DWORD dwUnk) R0;
	virtual void vt_entry_10C(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void DrawExtras(DWORD dwUnk, DWORD dwUnk2) RX; // draws ivan bomb, health bar, talk bubble, etc
	virtual void Draw(Point2D* pCoords, DWORD dwUnk) RX;
	virtual void vt_entry_118(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void vt_entry_11C() RX;
	virtual void See(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual bool SetLayer(eLayer value) R0;
	virtual RectangleStruct* vt_entry_128(RectangleStruct* pRect) R0;
	virtual RectangleStruct* vt_entry_12C(RectangleStruct* pRect) R0;
	virtual void DrawRadialIndicator(DWORD dwUnk) RX;
	virtual void vt_entry_134() RX;
	virtual bool vt_entry_138() R0;
	virtual bool vt_entry_13C() R0;
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) R0;
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) R0;
	virtual void Flash(int Duration) RX;
	virtual bool Select() R0;
	virtual void Deselect() RX;
	virtual void IronCurtain(int nDuration, HouseClass *pSource, bool ForceShield) RX;
	virtual void StopAirstrikeTimer() RX;
	virtual void StopAirstrikeTimer(int Duration) RX;
	virtual bool IsIronCurtained() R0;
	virtual bool vt_entry_164(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual int GetWeaponRange(int idxWeapon) R0;
	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH,
	  ObjectClass* pAttacker, DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse) R0;
	virtual void FreeCaptured() RX;
	virtual void Scatter(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool Ignite() R0;
	virtual void vt_entry_17C() RX;
	virtual DWORD vt_entry_180() R0;
	virtual eMission GetCurrentMission() R0;
	virtual void vt_entry_188(DWORD dwUnk) RX;
	virtual void UpdatePosition(int dwUnk) RX;
	virtual BuildingTypeClass* GetFactoryType(bool bOverridePrereqs, bool bOverridePower) R0;
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool vt_entry_198(DWORD dwUnk) R0;
	virtual void vt_entry_19C(DWORD dwUnk) RX;
	virtual void Sell(DWORD dwUnk) RX;
	virtual void AssignPlanningPath(signed int idxPath, signed char idxWP) RX;
	virtual void vt_entry_1A8(DWORD dwUnk) RX;
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5) R0;
	virtual DWORD vt_entry_1B0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5) R0;
	virtual void SetLocation(CoordStruct* pCrd) RX;

// these two work through the object's Location
	virtual CellStruct* GetMapCoords(CellStruct* pUCell) R0;
	virtual CellClass* GetCell() R0;

// these two call ::GetCoords_() instead
	virtual CellStruct* GetMapCoordsAgain(CellStruct* pUCell) R0;
	virtual CellClass* GetCellAgain() R0;

	virtual int GetHeight() R0;
	virtual void SetHeight(DWORD dwUnk) RX;
	virtual int GetZ() R0;
	virtual bool IsBeingWarpedOut() R0;
	virtual bool IsWarpingIn() R0;
	virtual bool IsWarpingSomethingOut() R0;
	virtual bool IsNotWarping() R0;
	virtual LightConvertClass *GetRemapColour() R0;

	// technically it takes an ecx<this> , but it's not used and ecx is immediately overwritten on entry
	// draws the mind control line when unit is selected
	static void DrawALinkTo(int src_X, int src_Y, int src_Z, int dst_X, int dst_Y, int dst_Z, ColorStruct color)
		{ PUSH_VAR32(color); PUSH_VAR32(dst_Z); PUSH_VAR32(dst_Y); PUSH_VAR32(dst_X); 
		  PUSH_VAR32(src_Z); PUSH_VAR32(src_Y); PUSH_VAR32(src_X); CALL(0x704E40); }

	//Constructor
	ObjectClass():AbstractClass(false)
		{ THISCALL(0x5F3900); }

protected:
	ObjectClass(bool X):AbstractClass(X)
		{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	PROTECTED_PROPERTY(BYTE,     unknown_24[0x8]);
	PROPERTY(int,                FallRate); //how fast is it falling down? only works if FallingDown is set below, and actually positive numbers will move the thing UPWARDS
	PROPERTY(ObjectClass*,       NextObject);	//Next Object in the same cell or transport. This is a linked list of Objects.
	PROTECTED_PROPERTY(DWORD,    AttachedTag); //Should be TagClass , TODO: change when implemented
	PROPERTY(BombClass*,         AttachedBomb); //Ivan's little friends.

	PROPERTY_STRUCT(Unsorted::AudioController, Audio1); // the "mofo" struct, evil evil stuff
	PROPERTY_STRUCT(Unsorted::AudioController, Audio2); // the "mofo" struct, evil evil stuff

	PROPERTY(int,                unknown_64);		//idx of OverlayType this is posing as (Mirage Tank)
	PROPERTY(bool,               BombVisible); // In range of player's bomb seeing units, so should draw it
	PROPERTY(int,                Health);		//The current Health.
	PROPERTY(DWORD,              unknown_70);
	PROPERTY(DWORD,              unknown_74);
	PROPERTY(DWORD,              unknown_78);
	PROPERTY(DWORD,              unknown_7C);
	PROPERTY(bool,               Sensed); // Sensed by sensors
	PROPERTY(bool,               InLimbo); // act as if it doesn't exist - e.g., post mortem state before being deleted
	PROPERTY(bool,               InOpenToppedTransport);
	PROPERTY(bool,               IsSelected);	//Has the player selected this Object?
	PROPERTY(bool,               HasParachute);	//Is this Object parachuting?
	PROPERTY(AnimClass*,         Parachute);		//Current parachute Anim.
	PROPERTY(bool,               OnBridge);
	PROPERTY(bool,               FallingDown);
	PROPERTY(bool,               unknown_8E);
	PROPERTY(bool,               IsABomb); // if set, will explode after FallingDown brings it to contact with the ground
	PROPERTY(bool,               IsAlive);		//Self-explanatory.
	PROTECTED_PROPERTY(BYTE,     unknown_91[0xB]);
	PROPERTY_STRUCT(CoordStruct, Location);		//Absolute current 3D location (in leptons?)
	PROPERTY(LineTrail*,         LineTrailer);
 };

#endif
