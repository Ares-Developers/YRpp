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
struct WeaponStruct;

class ObjectClass : public AbstractClass
{
public:
	//global arrays
	static DynamicVectorClass<ObjectClass*>* CurrentObjects;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm)
		{ PUSH_VAR32(pStm); PUSH_VAR32(this); CALL_RET(0x5F5E80, HRESULT); }

	//Destructor
	virtual ~ObjectClass()
		{ THISCALL(0x5F3B80); }

	//AbstractClass
	virtual void PointerExpired(void* p, bool bUnknown)
		{ PUSH_VAR8(bUnknown); PUSH_VAR32(p); THISCALL(0x5F5230); }
	virtual void CalculateChecksum(void* pChkSum)
		{ PUSH_VAR32(pChkSum); THISCALL(0x5F6250); }
	virtual bool IsDead()
		{ return !IsAlive; }
	virtual CoordStruct* GetCoords(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x5F65A0, CoordStruct*); }
	virtual bool IsOnFloor()
		{ THISCALL_RET(0x5F6B60, bool); }
	virtual bool IsInAir()
		{ THISCALL_RET(0x5F6B90, bool); }
	virtual void Update()
		{ THISCALL(0x5F3E70); }

	//ObjectClass
	virtual void AnimPointerExpired(AnimClass* pAnim)
		{ PUSH_VAR32(pAnim); THISCALL(0x5F6DA0); }
	virtual bool IsSelectable()
		{ return false; }
	virtual eVisualType VisualCharacter(VARIANT_BOOL flag, DWORD dwUnk)
		{ return vt_Normal; }
	virtual SHPStruct* GetImage()
		{ THISCALL_RET(0x5F3E30, SHPStruct*); }
	virtual eAction MouseOverCell(CellStruct uCell, bool bUnk1, bool bUnk2)
		{ return act_None; }
	virtual eAction MouseOverObject(ObjectClass* pObj, bool bUnk1)
		{ return act_None; }
	virtual eLayer InWhichLayer()
		{ THISCALL_RET(0x5F4260, eLayer); }
	virtual bool vt_entry_7C()
		{ THISCALL_RET(0x5F6C10, bool); }
	virtual bool CanBeUndeployed()
		{ return false; }
	virtual ObjectTypeClass* GetType_()
		{ return NULL; }	//???
	virtual ObjectTypeClass* GetType()
		{ return NULL; }
	virtual DWORD GetTypeOwners()
		{ return 0x7FFFFFFF; }
	virtual wchar_t* GetUIName()
		{ return (wchar_t*)0x8182E0; }
	virtual bool CanBeRepaired()
		{ return false; }
	virtual bool CanBeSold()
		{ return false; }
	virtual bool IsActive()
		{ return false; }
	virtual bool vt_entry_A0()
		{ return false; }
	virtual CoordStruct* vt_entry_A4(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x41BDD0, CoordStruct*); }
	virtual CoordStruct* vt_entry_A8(CoordStruct* pCrd, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); PUSH_VAR32(pCrd); THISCALL_RET(0x5F6C80, CoordStruct*); }
	virtual CoordStruct* vt_entry_AC(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL_RET(0x41BE00, CoordStruct*); }
	virtual CoordStruct* GetFLH(CoordStruct *pDest, int idxWeapon, int nFLH_X, int nFLH_Y, int nFLH_Z)
		{ PUSH_VAR32(nFLH_Z); PUSH_VAR32(nFLH_Y); PUSH_VAR32(nFLH_X);
		  PUSH_VAR32(idxWeapon); PUSH_VAR32(pDest); THISCALL_RET(0x4263D0, CoordStruct*); }
	virtual CoordStruct* GetExitCoords(CoordStruct* pCrd, DWORD dwUnk)
		{ PUSH_VAR32(dwUnk);PUSH_VAR32(pCrd);THISCALL_RET(0x41BE30, CoordStruct*); }
	virtual int vt_entry_B8()
		{ THISCALL_RET(0x5F6BD0, int); }
	virtual bool vt_entry_BC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x5F6A70, bool); }
	virtual bool vt_entry_C0()
		{ return true; }
	virtual bool IsDisguised()
		{ return false; }
	virtual bool IsDisguisedAs(HouseClass *target)
		{ return false; }
	virtual ObjectTypeClass* GetDisguise(bool DisguisedAgainstAllies)
		{ return 0; }
	virtual HouseClass* GetDisguiseHouse(bool DisguisedAgainstAllies)
		{ return 0; }
	virtual bool vt_entry_D4()
		{ THISCALL_RET(0x5F4D30, bool); }
	virtual bool Put(CoordStruct* pCrd, eDirection dFaceDir)
		{ PUSH_VAR32(dFaceDir); PUSH_VAR32(pCrd); THISCALL_RET(0x5F4EC0, bool); }
	virtual void vt_entry_DC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk);THISCALL(0x5F5280); }
	virtual void RegisterDestruction(TechnoClass *Destroyer)
		{ } // maybe Object instead of Techno? Raises Map Events, grants veterancy, increments house kill counters
	virtual void RegisterDestruction(HouseClass *Destroyer)
		{ } // ++destroyer's kill counters , etc
	virtual bool vt_entry_E8(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x5F5940, bool); }
	virtual void vt_entry_EC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ PUSH_VAR32(dwUnk4); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x5F4160); }
	virtual void vt_entry_F0(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5F60A0); }
	virtual void vt_entry_F4(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5F6120); }
	virtual void UnInit()
		{ THISCALL(0x5F65F0); }
	virtual void Uncloak2()
		{ } // just calls this->Uncloak(0) on TechnoClass and higher
	virtual int	 KickOutUnit(TechnoClass* pTechno, CellStruct uCell)
		{ return 0; }
	virtual bool vt_entry_104(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL_RET(0x5F4B10, bool); }
	virtual DWORD vt_entry_108(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x5F5B90, DWORD); }
	virtual void vt_entry_10C(DWORD dwUnk, DWORD dwUnk2)
		{ }
	virtual void DrawExtras(DWORD dwUnk, DWORD dwUnk2)
		{ } // draws ivan bomb, health bar, talk bubble, etc
	virtual void Draw(Point2D* pCoords, DWORD dwUnk)
		{ }
	virtual void vt_entry_118(DWORD dwUnk, DWORD dwUnk2)
		{ PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x5F65D0); }
	virtual void vt_entry_11C()
		{ }
	virtual void See(DWORD dwUnk, DWORD dwUnk2)
		{ }
	virtual bool SetLayer(eLayer value)
		{ PUSH_VAR32(value); THISCALL_RET(0x5F5850, bool); }
	virtual RectangleStruct* vt_entry_128(RectangleStruct* pRect)
		{ PUSH_VAR32(pRect); THISCALL_RET(0x5F4730, RectangleStruct*); }
	virtual RectangleStruct* vt_entry_12C(RectangleStruct* pRect)
		{ PUSH_VAR32(pRect); THISCALL_RET(0x5F4870, RectangleStruct*); }
	virtual void DrawRadialIndicator(DWORD dwUnk)
		{ } // nop in all except BuildingClass
	virtual void vt_entry_134()
		{ THISCALL(0x5F4D10); }
	virtual bool vt_entry_138()
		{ THISCALL_RET(0x5F6C30, bool); }
	virtual bool vt_entry_13C()
		{ THISCALL_RET(0x5F6C30, bool); }
	virtual bool vt_entry_140(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4)
		{ return false; }
	virtual bool vt_entry_144(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ return false; }
	virtual void Flash(int Duration)
		{ }
	virtual bool Select()
		{ THISCALL_RET(0x5F4520, bool); }
	virtual void Deselect()
		{ THISCALL(0x5F44A0); }
	virtual void IronCurtain(int nDuration, DWORD dwUnused, bool bUnk)
		{ }
	virtual void vt_entry_158()
		{ }
	virtual void vt_entry_15C(DWORD dwUnk)
		{ }
	virtual bool IsIronCurtained()
		{ return false; }
	virtual bool vt_entry_164(DWORD dwUnk, DWORD dwUnk2)
		{ return false; }
	virtual int GetWeaponRange(int idxWeapon)
		{ return 0; }
	virtual eDamageState ReceiveDamage(int* pDamage, DWORD dwUnk1, WarheadTypeClass* pWH,
	  ObjectClass* pAttacker, DWORD dwUnk2, DWORD dwUnk3, HouseClass* pAttackingHouse)
		{ PUSH_VAR32(pAttackingHouse); PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(pAttacker);
		  PUSH_VAR32(pWH); PUSH_VAR32(dwUnk1); PUSH_VAR32(pDamage); THISCALL_RET(0x5F5390, eDamageState); }
	virtual void FreeCaptured()
		{ }
	virtual void Scatter(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ }
	virtual bool Ignite()
		{ return false; }
	virtual void vt_entry_17C()
		{ }
	virtual DWORD vt_entry_180()
		{ return 0; }
	virtual eMission GetCurrentMission()
		{ return mission_None; }
	virtual void vt_entry_188(DWORD dwUnk)
		{ }
	virtual void UpdatePosition(int dwUnk)
		{ }
	virtual BuildingTypeClass* GetFactoryType(bool bOverridePrereqs, bool bOverridePower)
		{ PUSH_VAR8(bOverridePower); PUSH_VAR8(bOverridePrereqs); THISCALL_RET(0x5F5C20, BuildingTypeClass*); }
	virtual void vt_entry_194(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3)
		{ PUSH_VAR32(dwUnk3); PUSH_VAR32(dwUnk2); PUSH_VAR32(dwUnk); THISCALL(0x5F5320); }
	virtual bool vt_entry_198(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL_RET(0x5F5930, bool); }
	virtual void vt_entry_19C(DWORD dwUnk)
		{ }
	virtual void Sell(DWORD dwUnk)
		{ }
	virtual void AssignPlanningPath(signed int idxPath, signed char idxWP)
		{ }
	virtual void vt_entry_1A8(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5F4410); }
	virtual DWORD vt_entry_1AC(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ return 0; }
	virtual DWORD vt_entry_1B0(DWORD dwUnk, DWORD dwUnk2, DWORD dwUnk3, DWORD dwUnk4, DWORD dwUnk5)
		{ return 0; }
	virtual void SetLocation(CoordStruct* pCrd)
		{ PUSH_VAR32(pCrd); THISCALL(0x5F6940); }
	virtual CellStruct* GetMapCoords(CellStruct* pUCell)
		{ PUSH_VAR32(pUCell); THISCALL_RET(0x41BEA0, CellStruct*); }
	virtual CellClass* GetCell()
		{ THISCALL_RET(0x5F6960, CellClass*); }
	virtual CellStruct* vt_entry_1C0(CellStruct* pUCell)
		{ PUSH_VAR32(pUCell); THISCALL_RET(0x5F69C0, CellStruct*); }
	virtual CellClass* vt_entry_1C4()
		{ THISCALL_RET(0x5F6A10, CellClass*); }
	virtual int vt_entry_1C8()
		{ THISCALL_RET(0x5F5F40, int); }
	virtual void vt_entry_1CC(DWORD dwUnk)
		{ PUSH_VAR32(dwUnk); THISCALL(0x5F5FA0); }
	virtual int GetZ()
		{ return Location.Z; }
	virtual bool IsBeingWarpedOut()
		{ return false; }
	virtual bool IsWarpingIn()
		{ return false; }
	virtual bool IsWarpingSomethingOut()
		{ return false; }
	virtual bool IsNotWarping()
		{ return true; }
	virtual DWORD vt_entry_1E4()
		{ return 0; }

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

	PROTECTED_PROPERTY(BYTE,     unknown_24[0xC]);
	PROPERTY(ObjectClass*,       NextObject);	//Next Object in the same cell or transport. This is a linked list of Objects.
	PROTECTED_PROPERTY(DWORD,    AttachedTag); //Should be TagClass , TODO: change when implemented
	PROPERTY(BombClass*,         AttachedBomb); //Ivan's little friends.
	PROTECTED_PROPERTY(BYTE,     unknown_3C[0x8]);
	PROPERTY(int,                DisguisedAsOverlay);		//idx of OverlayType this is posing as (Mirage Tank)
	PROTECTED_PROPERTY(BYTE,     unknown_48[0x20]);
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
	PROTECTED_PROPERTY(DWORD,    unknown_8C);
	PROPERTY(bool,               IsAlive);		//Self-explanatory.
	PROTECTED_PROPERTY(BYTE,     unknown_91[0xB]);
	PROPERTY_STRUCT(CoordStruct,        Location);		//Absolute current 3D location (in leptons?)
	PROTECTED_PROPERTY(DWORD,    unknown_A8);
 };

#endif
