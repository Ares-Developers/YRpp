/*
	Base class for all game objects.
*/

#ifndef OBJECT_H
#define OBJECT_H

#include <AbstractClass.h>
#include <Audio.h>

#include <Helpers/Template.h>

struct SHPStruct;
class LightConvertClass;

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

class HouseTypeClass;

class LineTrail;
struct WeaponStruct;

class ObjectClass : public AbstractClass
{
public:
	enum {AbsDerivateID = ABSFLAGS_ISOBJECT};

	//global arrays
	static DynamicVectorClass<ObjectClass*>* CurrentObjects;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;

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

 /*
  	Building returns if it is 1x1 and has UndeploysInto
  	inf returns 0
  	unit returns !NonVehicle
  	Aircraft returns IsOnFloor()

  users include:
  452656 - is this building click-repairable
  440C26 - should this building get considered in BaseSpacing
  445A8E - -""-
  51E7D1 - can a VehicleThief be clicked to steal this unit
  51E4D9 - can an engi be clicked to enter this to fix/takeover
  51F0D3 - -""-
  51EA06 - can this building be C4'd?
  51E243 - can a VehicleThief steal this on his own decision
  4F93F3 - should this building's damage raise a BaseUnderAttack?
  442286 - -""-
  44296A - -""-
  741117 - can this be healed by a vehicle?
  6F8242 - can this aircraft be auto-target
  6F85BE - can this aircraft be auto-attacked
  */
	virtual bool IsStrange() R0;

	virtual TechnoTypeClass* GetTechnoType() R0;
	virtual ObjectTypeClass* GetType() R0;
	virtual IndexBitfield<HouseTypeClass *> GetTypeOwners() R0;
	virtual wchar_t* GetUIName() R0;
	virtual bool CanBeRepaired() R0;
	virtual bool CanBeSold() R0;
	virtual bool IsActive() R0;
	virtual bool IsControllable() R0;

	// stupid! return this->GetCoords(pCrd);
	virtual CoordStruct* GetPosition_0(CoordStruct* pCrd) R0;

	// stupid! return this->GetCoords(pCrd); again
	virtual CoordStruct* GetPosition_1(CoordStruct* pCrd, DWORD dwUnk) R0;

	// stupid! guess what happens again?
	virtual CoordStruct* GetPosition_2(CoordStruct* pCrd) R0;
	virtual CoordStruct* GetFLH(CoordStruct *pDest, int idxWeapon, CoordStruct BaseCoords) R0;
	virtual CoordStruct* GetExitCoords(CoordStruct* pCrd, DWORD dwUnk) R0;
	virtual int vt_entry_B8() R0;
	virtual bool vt_entry_BC(DWORD dwUnk) R0;
	virtual bool vt_entry_C0() R0;
	virtual bool IsDisguised() R0;
	virtual bool IsDisguisedAs(HouseClass *target) R0; // only works correctly on infantry!
	virtual ObjectTypeClass* GetDisguise(bool DisguisedAgainstAllies) R0;
	virtual HouseClass* GetDisguiseHouse(bool DisguisedAgainstAllies) R0;

	// remove object from the map
	virtual bool Remove() R0;

	// place the object on the map
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir) R0;

	// cleanup things (lose line trail, deselect, etc)
	virtual void ReachedEndOfLife(bool Silently) RX;

	virtual void RegisterDestruction(TechnoClass *Destroyer) RX;

	 // maybe Object instead of Techno? Raises Map Events, grants veterancy, increments house kill counters
	virtual void RegisterKill(HouseClass *Destroyer) RX; // ++destroyer's kill counters , etc

	virtual bool SpawnParachuted(CoordStruct *coords) R0;
	virtual void vt_entry_EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) RX;
	virtual void UnmarkAllOccupationBits(CoordStruct *coords) RX;
	virtual void MarkAllOccupationBits(CoordStruct *coords) RX;
	virtual void UnInit() RX;
	virtual void Uncloak2() RX;// just calls this->Uncloak(0) on TechnoClass and higher
	virtual int KickOutUnit(TechnoClass* pTechno, CellStruct *pCell) R0;
	virtual bool DrawIfVisible(RectangleStruct *VisibleArea, bool EvenIfCloaked, DWORD dwUnk3) R0;
	virtual DWORD GetFoundationData(bool IncludeBib) R0;
	virtual void vt_entry_10C(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual void DrawExtras(DWORD dwUnk, DWORD dwUnk2) RX; // draws ivan bomb, health bar, talk bubble, etc
	virtual void Draw(Point2D* pCoords, DWORD dwUnk) RX;
	virtual void DrawAgain(Point2D* pCoords, DWORD dwUnk) RX; // just forwards the call to Draw
	virtual void vt_entry_11C() RX;
	virtual void See(DWORD dwUnk, DWORD dwUnk2) RX;
	virtual bool SetLayer(eLayer value) R0;
	virtual RectangleStruct* vt_entry_128(RectangleStruct* pRect) R0;
	virtual RectangleStruct* vt_entry_12C(RectangleStruct* pRect) R0;
	virtual void DrawRadialIndicator(DWORD dwUnk) RX;
	virtual void vt_entry_134() RX;
	virtual bool CanBeSelected() R0;
	virtual bool CanBeSelectedNow() R0;
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4) R0;
	virtual bool ClickedAction(eAction Action, ObjectClass *Target, bool bUnk) R0;
	virtual void Flash(int Duration) RX;
	virtual bool Select() R0;
	virtual void Deselect() RX;
	virtual void IronCurtain(int nDuration, HouseClass *pSource, bool ForceShield) RX;
	virtual void StopAirstrikeTimer() RX;
	virtual void StartAirstrikeTimer(int Duration) RX;
	virtual bool IsIronCurtained() R0;
	virtual bool IsCloseEnough3D(DWORD dwUnk, DWORD dwUnk2) R0;
	virtual int GetWeaponRange(int idxWeapon) R0;
	virtual eDamageState ReceiveDamage(int* pDamage, int DistanceFromEpicenter, WarheadTypeClass* pWH,
	  ObjectClass* Attacker, BOOL IgnoreDefenses, BOOL PreventPassengerEscape, HouseClass* pAttackingHouse) R0;
	virtual void Destroy() RX;
	virtual void Scatter(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3) RX;
	virtual bool Ignite() R0;
	virtual void vt_entry_17C() RX;
	virtual DWORD GetPointsValue() R0;
	virtual eMission GetCurrentMission() R0;
	virtual void vt_entry_188(DWORD dwUnk) RX;
	virtual void UpdatePosition(int dwUnk) RX;
	virtual BuildingTypeClass* GetFactoryType(bool bOverridePrereqs, bool bOverridePower) R0;
	virtual void ReceiveCommand(TechnoClass *From, eRadioCommands rcDoThis, DWORD dwUnk3) RX;
	virtual bool UpdateOwner(HouseClass *pHouse) R0;
	virtual void vt_entry_19C(DWORD dwUnk) RX;
	virtual void Sell(DWORD dwUnk) RX;
	virtual void AssignPlanningPath(signed int idxPath, signed char idxWP) RX;
	virtual void vt_entry_1A8(DWORD dwUnk) RX;
	virtual int IsCellOccupied(CellClass *Cell, signed int Facing, int Level, DWORD dwUnk4, DWORD dwUnk5) R0;
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

	int DistanceFrom(ObjectClass *that)
		{ JMP_THIS(0x5F6440); }


	bool IsRedHP()
		{ JMP_THIS(0x5F5CD0); }

	bool IsYellowHP()
		{ JMP_THIS(0x5F5D20); }

	bool IsGreenHP()
		{ JMP_THIS(0x5F5D90); }

	HealthState GetHealthStatus()
		{ JMP_THIS(0x5F5DD0); }


	//Constructor
	ObjectClass() : AbstractClass(false)
		{ JMP_THIS(0x5F3900); }

protected:
	ObjectClass(bool) : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	PROTECTED_PROPERTY(BYTE,     unknown_24[0x8]);
	int                FallRate; //how fast is it falling down? only works if FallingDown is set below, and actually positive numbers will move the thing UPWARDS
	ObjectClass*       NextObject;	//Next Object in the same cell or transport. This is a linked list of Objects.
	PROTECTED_PROPERTY(DWORD,    AttachedTag); //Should be TagClass , TODO: change when implemented
	BombClass*         AttachedBomb; //Ivan's little friends.

	AudioController Audio1; // the "mofo" struct, evil evil stuff
	AudioController Audio2; // the "mofo" struct, evil evil stuff

	int                unknown_64;		//idx of OverlayType this is posing as (Mirage Tank)
	bool               BombVisible; // In range of player's bomb seeing units, so should draw it
	int                Health;		//The current Health.
	DWORD              unknown_70;
	DWORD              unknown_74;
	DWORD              unknown_78;
	DWORD              unknown_7C;
	bool               IsSensed; // Sensed by sensors
	bool               InLimbo; // act as if it doesn't exist - e.g., post mortem state before being deleted
	bool               InOpenToppedTransport;
	bool               IsSelected;	//Has the player selected this Object?
	bool               HasParachute;	//Is this Object parachuting?
	AnimClass*         Parachute;		//Current parachute Anim.
	bool               OnBridge;
	bool               IsFallingDown;
	bool               unknown_8E;
	bool               IsABomb; // if set, will explode after FallingDown brings it to contact with the ground
	bool               IsAlive;		//Self-explanatory.
	PROTECTED_PROPERTY(BYTE,     unknown_91[0xB]);
	CoordStruct Location;		//Absolute current 3D location (in leptons?)
	LineTrail*         LineTrailer;
 };

#endif
