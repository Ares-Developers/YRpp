/*
	Players
*/

#pragma once

#include <AircraftTypeClass.h>
#include <BuildingClass.h>
#include <InfantryTypeClass.h>
#include <HouseTypeClass.h>
#include <SessionClass.h>
#include <SideClass.h>
#include <UnitClass.h>
#include <UnitTypeClass.h>

//forward declarations
class AnimClass;
class BulletClass;
class CellClass;
class FactoryClass;
class ObjectClass;
class SuperClass;
class TagClass;
class WaypointPathClass;
class WaypointClass;

//--- ScoreStruct - might as well have been a class, but I didn't find any proof for that.
struct ScoreStruct
{
	int Counts[0x200];
	int NumCounts;	//should maximally be 0x200 !!!
	int	ByteOrder;	//BYTEORDER_HOST or BYTEORDER_NETWORK
};
//-----

struct StartingTechnoStruct
{
	TechnoTypeClass *  Unit;
	CellStruct         Cell;
};

// that's how WW calls it, seems to track levels of how much it hates other houses... typical ww style, with bugs
struct AngerStruct
{
	HouseClass * House;
	int          AngerLevel;

	//need to define a == operator so it can be used in array classes
	bool operator == (const AngerStruct& tAnger) const
	{
		return (House == tAnger.House &&
				AngerLevel == tAnger.AngerLevel);
	}
};

struct ScoutStruct
{
	HouseClass * House;
	bool         IsPreferred;

	//need to define a == operator so it can be used in array classes
	bool operator == (const ScoutStruct& tScout) const
	{
		return (House == tScout.House &&
				IsPreferred == tScout.IsPreferred);
	}
};

//--- BaseNodeClass
class BaseNodeClass
{
public:
	//need to define a == operator so it can be used in array classes
	bool operator == (const BaseNodeClass& tBaseNode) const
	{
		return
			(BuildingTypeIndex == tBaseNode.BuildingTypeIndex) &&
			(MapCoords == tBaseNode.MapCoords) &&
			(Placed == tBaseNode.Placed) &&
			(Attempts == tBaseNode.Attempts);
	}

	int        BuildingTypeIndex;
	CellStruct MapCoords;
	bool       Placed;
	int        Attempts;
};

//--- BaseClass - holds information about a player's base!
class HouseClass;	//forward declaration needed

class BaseClass
{
public:
	BaseClass()
		{ JMP_THIS(0x42E6F0); }

	//VTable
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm) R0;
	virtual void CalculateChecksum(Checksummer& checksum) const RX;

	//virtual ~BaseClass() { /*???*/ }; // gcc demands a virtual since virtual funcs exist

	int FailedToPlaceNode(BaseNodeClass *Node) // called after AI fails to place building, obviously
		{ JMP_THIS(0x42F380); }

	//Properties
	DynamicVectorClass<BaseNodeClass> BaseNodes;
	int                               PercentBuilt;
	DynamicVectorClass<CellStruct>    Cells_24;
	DynamicVectorClass<CellStruct>    Cells_38;
	CellStruct Center;

	PROTECTED_PROPERTY(BYTE,                    unknown_54[0x20]);

	HouseClass*                       Owner;

#pragma warning(suppress : 4265)
};

// used for each of the 3 drop ships. has more functions that are not reproduced here yet
struct DropshipStruct
{
	TimerStruct      Timer;
	BYTE             unknown_C;
	PROTECTED_PROPERTY(BYTE, align_D[3]);
	int              Count;
	TechnoTypeClass* Types[5];
	int              TotalCost;
};

//--- Here we go, finally...
class NOVTABLE HouseClass : public AbstractClass, public IHouse, public IPublicHouse, public IConnectionPointContainer
{
public:
	static const AbstractType AbsID = AbstractType::House;

	// <Player @ A> and friends map to these constants
	enum {PlayerAtA = 4475, PlayerAtB, PlayerAtC, PlayerAtD, PlayerAtE, PlayerAtF, PlayerAtG, PlayerAtH};

	//Static
	static DynamicVectorClass<HouseClass*>* const Array;

	static HouseClass *&Player;
	static HouseClass *&Observer;

	//IConnectionPointContainer
	virtual HRESULT __stdcall EnumConnectionPoints(IEnumConnectionPoints** ppEnum) R0;
	virtual HRESULT __stdcall FindConnectionPoint(GUID* riid, IConnectionPoint** ppCP) R0;

	//IPublicHouse
	virtual long __stdcall Apparent_Category_Quantity(Category category) const override R0;
	virtual long __stdcall Apparent_Category_Power(Category category) const override R0;
	virtual CellStruct __stdcall Apparent_Base_Center() const RT(CellStruct);
	virtual bool __stdcall Is_Powered() const R0;

	//IHouse
	virtual long __stdcall ID_Number() const override R0;
	virtual BSTR __stdcall Name() const override R0;
	virtual IApplication* __stdcall Get_Application() override R0;
	virtual long __stdcall Available_Money() const override R0;
	virtual long __stdcall Available_Storage() const override R0;
	virtual long __stdcall Power_Output() const override R0;
	virtual long __stdcall Power_Drain() const override R0;
	virtual long __stdcall Category_Quantity(Category category) const override R0;
	virtual long __stdcall Category_Power(Category category) const override R0;
	virtual CellStruct __stdcall Base_Center() const override RT(CellStruct);
	virtual HRESULT __stdcall Fire_Sale() const override R0;
	virtual HRESULT __stdcall All_To_Hunt() override R0;

	//IUnknown
	virtual HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) R0;
	virtual ULONG __stdcall AddRef() R0;
	virtual ULONG __stdcall Release() R0;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~HouseClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int	Size() const R0;

	bool IsAlliedWith(int idxHouse) const {
		//JMP_THIS(0x4F9A10);
		if(idxHouse == this->ArrayIndex) {
			return true;
		}
		if(idxHouse != -1) {
			return ((1u << idxHouse) & this->Allies) != 0u;
		}
		return false;
	}

	bool IsAlliedWith(HouseClass const* pHouse) const {
		//JMP_THIS(0x4F9A50);
		return pHouse && (pHouse == this || this->IsAlliedWith(pHouse->ArrayIndex));
	}

	bool IsAlliedWith(ObjectClass const* pObject) const {
		//JMP_THIS(0x4F9A90);
		return pObject && this->IsAlliedWith(pObject->GetOwningHouse());
	}

	bool IsAlliedWith(AbstractClass const* pAbstract) const {
		//JMP_THIS(0x4F9AF0);
		return this->IsAlliedWith(abstract_cast<const ObjectClass*>(pAbstract));
	}

	void MakeAlly(int iHouse, bool bAnnounce)
		{ JMP_THIS(0x4F9B50); }
	void MakeAlly(HouseClass* pWho, bool bAnnounce)
		{ JMP_THIS(0x4F9B70); }
	void MakeEnemy(HouseClass* pWho, bool bAnnounce)
		{ JMP_THIS(0x4F9F90); }

	void AllyAIHouses()
		{ JMP_THIS(0x501640); }

	// no explosions, just poooof
	void SDDTORAllAndTriggers()
		{ JMP_THIS(0x4FB920); }

	void AcceptDefeat()
		{ JMP_THIS(0x4FC0B0); }

	// every matching object takes damage and explodes
	void DestroyAll()
		{ JMP_THIS(0x4FC6D0); }
	void DestroyAllBuildings()
		{ JMP_THIS(0x4FC790); }
	void DestroyAllNonBuildingsNonNaval()
		{ JMP_THIS(0x4FC820); }
	void DestroyAllNonBuildingsNaval()
		{ JMP_THIS(0x4FC8D0); }

	void RespawnStartingBuildings()
		{ JMP_THIS(0x50D320); }
	void RespawnStartingForces()
		{ JMP_THIS(0x50D440); }

	BYTE Win(bool bSavourSomething)
		{ JMP_THIS(0x4FC9E0); }
	BYTE Lose(bool bSavourSomething)
		{ JMP_THIS(0x4FCBD0); }

	bool CanAlly(HouseClass* pOther) const
		{ JMP_THIS(0x501540); }

	bool CanOverpower(TechnoClass *pTarget) const
		{ JMP_THIS(0x4F9AF0); }

	// warning: logic pretty much broken
	void LostPoweredCenter(TechnoTypeClass *pTechnoType)
		{ JMP_THIS(0x50E0E0); }
	void GainedPoweredCenter(TechnoTypeClass *pTechnoType)
		{ JMP_THIS(0x50E1B0); }

	bool DoInfantrySelfHeal() const
		{ return this->InfantrySelfHeal > 0; }
	int GetInfSelfHealStep() const
		{ JMP_THIS(0x50D9E0); }

	bool DoUnitsSelfHeal() const
		{ return this->UnitsSelfHeal > 0; }
	int GetUnitSelfHealStep() const
		{ JMP_THIS(0x50D9F0); }

	void UpdatePower()
		{ JMP_THIS(0x508C30); }
	void CreatePowerOutage(int duration)
		{ JMP_THIS(0x50BC90); }
	double GetPowerPercentage() const
		{ JMP_THIS(0x4FCE30); }

	bool HasFullPower() const {
		return this->PowerOutput >= this->PowerDrain || !this->PowerDrain;
	}

	bool HasLowPower() const {
		return this->PowerOutput < this->PowerDrain && this->PowerDrain;
	}

	void CreateRadarOutage(int duration)
		{ JMP_THIS(0x50BCD0); }

	// won't work if has spysat
	void ReshroudMap()
		{ JMP_THIS(0x50BD10); }

	void Cheer()
		{ JMP_THIS(0x50C8C0); }

	void BuildingUnderAttack(BuildingClass *pBld)
		{ JMP_THIS(0x4F93E0); }

	void TakeMoney(int amount)
		{ JMP_THIS(0x4F9790); }
	void GiveMoney(int amount)
		{ JMP_THIS(0x4F9950); }

	inline bool CanTransactMoney(int amount) const {
		return amount > 0 || this->Available_Money() >= -amount;
	}

	inline void TransactMoney(int amount) {
		if(amount > 0) {
			this->GiveMoney(amount);
		} else {
			this->TakeMoney(-amount);
		}
	}

	void GiveTiberium(float amount, int type)
		{ JMP_THIS(0x4F9610); }
	void UpdateAllSilos(int prevStorage, int prevTotalStorage)
		{ JMP_THIS(0x4F9970); }
	double GetStoragePercentage()
		{ JMP_THIS(0x4F6E70); }

	// no LostThreatNode() , this gets called also when node building dies! BUG
	void AcquiredThreatNode()
		{ JMP_THIS(0x509130); }

	// these are for mostly for map actions - HouseClass* foo = IsMP() ? Find_YesMP() : Find_NoMP();
	static bool __fastcall Index_IsMP(int idx)
		{ JMP_STD(0x510F60); }
	static HouseClass * __fastcall FindByCountryIndex(int HouseType) // find first house of this houseType
		{ JMP_STD(0x502D30); }
	static HouseClass * __fastcall FindByIndex(int idxHouse) // find house at given index
		{ JMP_STD(0x510ED0); }                    // 0..15 map to ScenarioClass::HouseIndices, also supports PlayerAtA and up
	static signed int __fastcall FindIndexByName(const char *name)
		{ JMP_STD(0x50C170); }

	// gets the first house of a type with this name
	static HouseClass* FindByCountryName(const char* name) {
		auto idx = HouseTypeClass::FindIndexOfName(name);
		return FindByCountryIndex(idx);
	}

	// gets the first house of a type with name Neutral
	static HouseClass* FindNeutral() {
		return FindByCountryName("Neutral");
	}

	// gets the first house of a type with name Special
	static HouseClass* FindSpecial() {
		return FindByCountryName("Special");
	}

	// gets the first house of a side with this name
	static HouseClass* FindBySideIndex(int index) {
		for(auto pHouse : *Array) {
			if(pHouse->Type->SideIndex == index) {
				return pHouse;
			}
		}
		return nullptr;
	}

	// gets the first house of a type with this name
	static HouseClass* FindBySideName(const char* name) {
		auto idx = SideClass::FindIndex(name);
		return FindBySideIndex(idx);
	}

	// gets the first house of a type from the Civilian side
	static HouseClass* FindCivilianSide() {
		return FindBySideName("Civilian");
	}

	static void __fastcall LoadFromINIList(CCINIClass *pINI)
		{ JMP_STD(0x5009B0); }


	WaypointClass * GetPlanningWaypointAt(CellStruct *coords)
		{ JMP_THIS(0x5023B0); }
	bool GetPlanningWaypointProperties(WaypointClass *wpt, int &idxPath, BYTE &idxWP)
		{ JMP_THIS(0x502460); }

	// calls WaypointPathClass::WaypointPathClass() if needed
	void EnsurePlanningPathExists(int idx)
		{ JMP_THIS(0x504740); }

	// call after the availability of a factory has changed.
	void Update_FactoriesQueues(AbstractType factoryOf, bool isNaval, BuildCat buildCat) const
		{ JMP_THIS(0x509140); }

	// returns the factory owned by this house, having pItem in production right now, not queued
	FactoryClass* GetFactoryProducing(TechnoTypeClass const* pItem) const
		{ JMP_THIS(0x4F83C0); }

	// finds a buildingtype from the given array that this house can build
	// this checks whether the Owner=, Required/ForbiddenHouses= , AIBasePlanningSide= match and if SuperWeapon= (not SW2=) is not forbidden
	BuildingTypeClass* FirstBuildableFromArray(DynamicVectorClass<BuildingTypeClass*> const& items)
		{ JMP_THIS(0x5051E0); }

	// are all prereqs for Techno listed in vectorBuildings[0..vectorLength]. Yes, the length is needed (the vector is used for breadth-first search)
	bool AllPrerequisitesAvailable(TechnoTypeClass const* pItem, DynamicVectorClass<BuildingTypeClass*> const& vectorBuildings, int vectorLength)
		{ JMP_THIS(0x505360); }

	// whether any human player controls this house
	bool ControlledByHuman() const { // { JMP_THIS(0x50B730); }
		bool result = this->CurrentPlayer;
		if(SessionClass::Instance->GameMode == GameMode::Campaign) {
			result = result || this->PlayerControl;
		}
		return result;
	}

	// whether the human player on this PC can control this house
	bool ControlledByPlayer() const { // { JMP_THIS(0x50B6F0); }
		if(SessionClass::Instance->GameMode != GameMode::Campaign) {
			return this->IsPlayer();
		}
		return this->CurrentPlayer || this->PlayerControl;
	}

	// Target ought to be Object, I imagine, but cell doesn't work then
	void __fastcall SendSpyPlanes(int AircraftTypeIdx, int AircraftAmount, Mission SetMission, AbstractClass *Target, ObjectClass *Destination)
		{ JMP_STD(0x65EAB0); }

	// registering in prereq counters (all technoes get logged, but only buildings get checked on validation... wtf)
	void RegisterGain(TechnoClass* pTechno, bool ownerChange)
		{ JMP_THIS(0x502A80); }

	void RegisterLoss(TechnoClass* pTechno, bool keepTiberium)
		{ JMP_THIS(0x5025F0); }

	BuildingClass* FindBuildingOfType(int idx, int sector = -1) const
		{ JMP_THIS(0x4FD060); }

	AnimClass * __fastcall PsiWarn(CellClass *pTarget, BulletClass *Bullet, char *AnimName)
		JMP_THIS(0x43B5E0);

	bool Fire_LightningStorm(SuperClass* pSuper)
		{ JMP_THIS(0x509E00); }

	bool Fire_ParaDrop(SuperClass* pSuper)
		{ JMP_THIS(0x509CD0); }

	bool Fire_PsyDom(SuperClass* pSuper)
		{ JMP_THIS(0x50A150); }

	bool Fire_GenMutator(SuperClass* pSuper)
		{ JMP_THIS(0x509F60); }

	bool IonSensitivesShouldBeOffline() const
		{ JMP_THIS(0x53A130); }

	const char *get_ID() const {
		return this->Type->get_ID();
	}

	int FindSuperWeaponIndex(SuperWeaponType type) const;

	SuperClass* FindSuperWeapon(SuperWeaponType type) const;

	// I don't want to talk about these
	// read the code <_<

	//  Count owned now
	int CountOwnedNow(TechnoTypeClass const* pItem) const;

	int CountOwnedNow(BuildingTypeClass const* const pItem) const {
		return this->OwnedBuildingTypes.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedNow(AircraftTypeClass const* const pItem) const {
		return this->OwnedAircraftTypes.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedNow(InfantryTypeClass const* const pItem) const {
		return this->OwnedInfantryTypes.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedNow(UnitTypeClass const* const pItem) const {
		return this->OwnedUnitTypes.GetItemCount(pItem->ArrayIndex);
	}

	// Count owned and present
	int CountOwnedAndPresent(TechnoTypeClass const* pItem) const;

	int CountOwnedAndPresent(BuildingTypeClass const* const pItem) const {
		return this->OwnedBuildingTypes1.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedAndPresent(AircraftTypeClass const* const pItem) const {
		return this->OwnedAircraftTypes1.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedAndPresent(InfantryTypeClass const* const pItem) const {
		return this->OwnedInfantryTypes1.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedAndPresent(UnitTypeClass const* const pItem) const {
		return this->OwnedUnitTypes1.GetItemCount(pItem->ArrayIndex);
	}

	// Count owned ever
	int CountOwnedEver(TechnoTypeClass const* pItem) const;

	int CountOwnedEver(BuildingTypeClass const* const pItem) const {
		return this->OwnedBuildingTypes2.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedEver(AircraftTypeClass const* const pItem) const {
		return this->OwnedAircraftTypes2.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedEver(InfantryTypeClass const* const pItem) const {
		return this->OwnedInfantryTypes2.GetItemCount(pItem->ArrayIndex);
	}

	int CountOwnedEver(UnitTypeClass const* const pItem) const {
		return this->OwnedUnitTypes2.GetItemCount(pItem->ArrayIndex);
	}


	bool HasFromSecretLab(const TechnoTypeClass* const pItem) const {
		for(const auto& pLab : this->SecretLabs) {
			if(pLab->GetSecretProduction() == pItem) {
				return true;
			}
		}
		return false;
	}

	bool HasAllStolenTech(const TechnoTypeClass* const pItem) const {
		if(pItem->RequiresStolenAlliedTech && !this->Side0TechInfiltrated) { return false; }
		if(pItem->RequiresStolenSovietTech && !this->Side1TechInfiltrated) { return false; }
		if(pItem->RequiresStolenThirdTech && !this->Side2TechInfiltrated) { return false; }
		return true;
	}

	bool HasFactoryForObject(const TechnoTypeClass* const pItem) const {
		auto const abs = pItem->WhatAmI();
		auto const naval = pItem->Naval;
		for(auto const& pBld : this->Buildings) {
			auto pType = pBld->Type;
			if(pType->Factory == abs && pType->Naval == naval) {
				return true;
			}
		}
		return false;
	}

	bool CanExpectToBuild(const TechnoTypeClass* pItem) const;

	bool CanExpectToBuild(const TechnoTypeClass* pItem, int idxParent) const;

	bool InOwners(const TechnoTypeClass* const pItem) const {
		auto const idxParentCountry = this->Type->FindParentCountryIndex();
		return pItem->InOwners(1u << idxParentCountry);
	}

	bool InRequiredHouses(const TechnoTypeClass* const pItem) const {
		return pItem->InRequiredHouses(1u << this->Type->ArrayIndex2);
	}

	bool InForbiddenHouses(const TechnoTypeClass* const pItem) const {
		return pItem->InForbiddenHouses(1u << this->Type->ArrayIndex2);
	}

	int CanBuild(TechnoTypeClass const* pItem, bool buildLimitOnly, bool includeInProduction) const
		{ JMP_THIS(0x4F7870); }

	int AI_BaseConstructionUpdate()
		{ JMP_THIS(0x4FE3E0); }

	void AI_TryFireSW()
		{ JMP_THIS(0x5098F0); }

	bool Fire_SW(int idx, const CellStruct &coords)
		{ JMP_THIS(0x4FAE50); }

	CellStruct* PickTargetByType(CellStruct &outBuffer, TargetType targetType) const
		{ JMP_THIS(0x50D170); }

	CellStruct PickTargetByType(TargetType targetType) const {
		CellStruct outBuffer;
		this->PickTargetByType(outBuffer, targetType);
		return outBuffer;
	}

	CellStruct* PickIonCannonTarget(CellStruct &outBuffer) const
		{ JMP_THIS(0x50CBF0); }

	CellStruct PickIonCannonTarget() const {
		CellStruct outBuffer;
		this->PickIonCannonTarget(outBuffer);
		return outBuffer;
	}

	bool IsIonCannonEligibleTarget(const TechnoClass* pTechno) const;

	void UpdateFlagCoords(UnitClass *NewCarrier, DWORD dwUnk)
		{ JMP_THIS(0x4FBE40); }

	void DroppedFlag(CellStruct *Where, UnitClass *Who)
		{ JMP_THIS(0x4FBF60); }

	char PickedUpFlag(UnitClass *Who, DWORD dwUnk)
		{ JMP_THIS(0x4FC060); }

	FactoryClass* GetPrimaryFactory(AbstractType absID, bool naval, BuildCat buildCat) const
		{ JMP_THIS(0x500510); }

	void SetPrimaryFactory(FactoryClass* pFactory, AbstractType absID, bool naval, BuildCat buildCat)
		{ JMP_THIS(0x500850); }

	const CellStruct& GetBaseCenter() const {
		if(this->BaseCenter != CellStruct::Empty) {
			return this->BaseCenter;
		} else {
			return this->BaseSpawnCell;
		}
	}

	unsigned int GetAIDifficultyIndex() const {
		return static_cast<unsigned int>(this->AIDifficulty);
	}

	/*!
		At the moment, this function is really just a more intuitively named mask for
		this->Type->MultiplayPassive, but it might be expanded into something more
		complicated later.

		Primarily used to check if something is owned by the neutral house.
		\return true if house is passive in multiplayer, false if not.
		\author Renegade
		\date 01.03.10
	*/
	bool IsNeutral() const {
		return this->Type->MultiplayPassive;
	}

	// whether this house is equal to Player
	bool IsPlayer() const {
		return this == Player;
	}

	// whether this house is equal to Observer
	bool IsObserver() const {
		return this == Observer;
	}

	// whether Player is equal to Observer
	static bool IsPlayerObserver() {
		return Player && Player->IsObserver();
	}

	//Constructor
	HouseClass(HouseTypeClass* pCountry) noexcept
		: HouseClass(noinit_t())
	{ JMP_THIS(0x4F54A0); }

protected:
	explicit __forceinline HouseClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	int                   ArrayIndex;
	HouseTypeClass*       Type;
	DynamicVectorClass<TagClass*> RelatedTags;
	DynamicVectorClass<BuildingClass*> ConYards;
	DynamicVectorClass<BuildingClass*> Buildings;
	DynamicVectorClass<BuildingClass*> UnitRepairStations;
	DynamicVectorClass<BuildingClass*> Grinders;
	DynamicVectorClass<BuildingClass*> Absorbers;
	DynamicVectorClass<BuildingClass*> Bunkers;
	DynamicVectorClass<BuildingClass*> Occupiables;
	DynamicVectorClass<BuildingClass*> CloningVats;
	DynamicVectorClass<BuildingClass*> SecretLabs;
	DynamicVectorClass<BuildingClass*> PsychicDetectionBuildings;
	DynamicVectorClass<BuildingClass*> FactoryPlants;
	int                   CountResourceGatherers;
	int                   CountResourceDestinations;
	int                   CountWarfactories;
	int                   InfantrySelfHeal;
	int                   UnitsSelfHeal;
	DynamicVectorClass<StartingTechnoStruct*> StartingUnits;
	AIDifficulty          AIDifficulty; // be advised that it's reverse, Hard == 0 and Easy == 2. I'm sure Westwood has a good reason for this. Yep.
	double                FirepowerMultiplier; // used
	double                GroundspeedMultiplier; // unused ...
	double                AirspeedMultiplier;
	double                ArmorMultiplier;
	double                ROFMultiplier;
	double                CostMultiplier;
	double                BuildTimeMultiplier; // ... unused ends
	double                RepairDelay;
	double                BuildDelay;
	int                   IQLevel;
	int                   TechLevel;
	PROTECTED_PROPERTY(DWORD,       AltAllies); // ask question, receive brain damage
	int                   StartingCredits;	//not sure how these are used // actual credits = this * 100
	Edge                  StartingEdge;
	DWORD                 unknown_1E4;
	int                   SideIndex;
	bool                  CurrentPlayer;		//is controlled by the player at this computer
	bool                  PlayerControl;		//a human controls this House
	bool                  Production;		//AI production has begun
	bool                  AutocreateAllowed;
	PROTECTED_PROPERTY(BYTE,        unknown_1F0[2]);
	bool                  AITriggersActive;
	bool                  AutoBaseBuilding;
	bool                  DiscoveredByPlayer;
	bool                  Defeated;
	bool                  IsGameOver;
	bool                  IsWinner;
	bool                  IsLoser;
	bool                  CiviliansEvacuated; // used by the CivEvac triggers
	bool                  FirestormActive;
	bool                  HasThreatNode;
	bool                  RecheckTechTree;
	PROTECTED_PROPERTY(BYTE,        unknown_1FD[0x0F]);
	int                   SelectedPathIndex;
	WaypointPathClass* PlanningPaths [0x0C]; // 12 paths for "planning mode"
	char                  Visionary;			//??? exe says so
	bool                  MapIsClear;
	bool                  unknown_bool_242;
	bool                  unknown_bool_243;
	bool                  HasBeenThieved; // Something of this house has been entered by a Thief/VehicleThief
	bool                  Repairing; // BuildingClass::Repair, handholder for hurr durf AI
	bool                  unknown_bool_246;
	bool                  unknown_bool_247;
	bool                  unknown_bool_248;
	bool                  AllToHunt;
	bool                  unknown_bool_24A;
	bool                  unknown_bool_24B;
	int                   IQLevel2;			//no idea why we got this twice
	AIMode                AIMode;
	DynamicVectorClass<SuperClass*> Supers;
	int                   LastBuiltBuildingType;
	int                   LastBuiltInfantryType;
	int                   LastBuiltAircraftType;
	int                   LastBuiltVehicleType;
	int                   AllowWinBlocks; // some ra1 residue map trigger-fu, should die a painful death
	TimerStruct RepairTimer; // for AI
	TimerStruct unknown_timer_28C;
	TimerStruct SavourTimer;
	TimerStruct PowerBlackoutTimer;
	TimerStruct RadarBlackoutTimer;
	bool                  Side2TechInfiltrated; // asswards! whether this player has infiltrated stuff
	bool                  Side1TechInfiltrated; // which is listed in [AI]->BuildTech
	bool                  Side0TechInfiltrated; // and has the appropriate AIBasePlanningSide
	bool                  BarracksInfiltrated;
	bool                  WarFactoryInfiltrated;

		// these four are unused horrors
		// checking prerequisites:
		/*
		if(1 << this->Country->IndexInArray & item->RequiredHouses
			|| (item->WhatAmI == abs_InfantryType && (item->RequiredHouses & this->InfantryAltOwner))
			|| (item->WhatAmI == abs_UnitType && (item->RequiredHouses & this->UnitAltOwner))
			|| (item->WhatAmI == abs_AircraftType && (item->RequiredHouses & this->AircraftAltOwner))
			|| (item->WhatAmI == abs_BuildingType && (item->RequiredHouses & this->BuildingAltOwner))
		)
			{ can build }
		 */
	DWORD InfantryAltOwner;
	DWORD UnitAltOwner;
	DWORD AircraftAltOwner;
	DWORD BuildingAltOwner;

	int                   AirportDocks;
	int                   PoweredUnitCenters;
	DWORD unknown_2DC;
	DWORD unknown_2E0;
	DWORD unknown_2E4;
	int                   OwnedUnits;
	int                   OwnedNavy;
	int                   OwnedBuildings;
	int                   OwnedInfantry;
	int                   OwnedAircraft;
	OwnedTiberiumStruct   OwnedTiberium;
	int                   Balance;
	int                   TotalStorage; // capacity of all building Storage
	OwnedTiberiumStruct   OwnedWeed;
	DWORD unknown_324;
	ScoreStruct BuiltInfantryTypes;
	ScoreStruct BuiltUnitTypes;
	ScoreStruct BuiltAircraftTypes;
	ScoreStruct BuiltBuildingTypes;
	ScoreStruct KilledInfantryTypes;
	ScoreStruct KilledUnitTypes;
	ScoreStruct KilledAircraftTypes;
	ScoreStruct KilledBuildingTypes;
	ScoreStruct UnknownScores;
	ScoreStruct CollectedPowerups;	//YES, THIS IS HOW WW WASTES TONS OF RAM
	int                   NumAirpads;
	int                   NumBarracks;
	int                   NumWarFactories;
	int                   NumConYards;
	int                   NumShipyards;
	int                   NumOrePurifiers;
	float                 CostInfantryMult;
	float                 CostUnitsMult;
	float                 CostAircraftMult;
	float                 CostBuildingsMult;
	float                 CostDefensesMult;
	int                   PowerOutput;
	int                   PowerDrain;
	FactoryClass*         Primary_ForAircraft;
	FactoryClass*         Primary_ForInfantry;
	FactoryClass*         Primary_ForVehicles;
	FactoryClass*         Primary_ForShips;
	FactoryClass*         Primary_ForBuildings;
	FactoryClass*         Primary_Unused1;
	FactoryClass*         Primary_Unused2;
	FactoryClass*         Primary_Unused3;
	FactoryClass*         Primary_ForDefenses;
	BYTE unknown_53D0;
	BYTE unknown_53D1;
	BYTE unknown_53D2;
	BYTE unknown_53D3;
	BYTE unknown_53D4;
	BYTE unknown_53D5;
	BYTE unknown_53D6;
	BYTE unknown_53D7;
	BYTE unknown_53D8;
	BYTE unknown_53D9;
	BYTE unknown_53DA;
	BYTE unknown_53DB;
	UnitClass* OurFlagCarrier;
	CellStruct  OurFlagCoords;
	//for endgame score screen
	int KilledUnitsOfHouses [0x14];		// 20 Houses only!
	int                   TotalKilledUnits;
	int KilledBuildingsOfHouses [0x14];	// 20 Houses only!
	int                   TotalKilledBuildings;
	DWORD                 unknown_548C;
	CellStruct            BaseSpawnCell;
	CellStruct            BaseCenter; // set by map action 137 and 138
	DWORD unknown_5498;
	DWORD unknown_549C;
	DWORD unknown_54A0;
	DWORD unknown_54A4;
	DWORD unknown_54A8;
	DWORD unknown_54AC;
	DWORD unknown_54B0;
	DWORD unknown_54B4;
	DWORD unknown_54B8;
	DWORD unknown_54BC;
	DWORD unknown_54C0;
	DWORD unknown_54C4;
	DWORD unknown_54C8;
	DWORD unknown_54CC;
	DWORD unknown_54D0;
	DWORD unknown_54D4;
	DWORD unknown_54D8;
	DWORD unknown_54DC;
	DWORD unknown_54E0;
//	IndexBitfield<HouseTypeClass *> RadarVisibleTo; // these house types(!?!, fuck you WW) can see my radar
	IndexBitfield<HouseClass *> RadarVisibleTo; // this crap is being rewritten to use house indices instead of house types
	int                   SiloMoney;
	TargetType PreferredTargetType; // Set via map action 35. The preferred object type to attack.
	CellStruct PreferredTargetCell; // Set via map action 135 and 136. Used to override firing location of targettable SWs.
	CellStruct PreferredDefensiveCell; // Set via map action 140 and 141, or when an AIDefendAgainst SW is launched.
	CellStruct PreferredDefensiveCell2; // No known function sets this to a real value, but it would take precedence over the other.
	int PreferredDefensiveCellStartTime; // The frame the PreferredDefensiveCell was set. Used to fire the Force Shield.

		// Used for: Counting objects ever owned
		// altered on each object's loss or gain
		// BuildLimit > 0 validation uses this
	CounterClass OwnedBuildingTypes;
	CounterClass OwnedUnitTypes;
	CounterClass OwnedInfantryTypes;
	CounterClass OwnedAircraftTypes;

		// Used for: Counting objects currently owned and on the map
		// altered on each object's loss or gain
		// AITriggerType condition uses this
		// original PrereqOverride check uses this
		// original Prerequisite check uses this
		// AuxBuilding check uses this
	CounterClass OwnedBuildingTypes1;
	CounterClass OwnedUnitTypes1;
	CounterClass OwnedInfantryTypes1;
	CounterClass OwnedAircraftTypes1;

		// Used for: Counting objects produced from Factory
		// not altered when things get taken over or removed
		// BuildLimit < 0 validation uses this
	CounterClass OwnedBuildingTypes2;
	CounterClass OwnedUnitTypes2;
	CounterClass OwnedInfantryTypes2;
	CounterClass OwnedAircraftTypes2;

	DWORD unknown_55F0;
	DWORD unknown_55F4;
	int                   AttackDelayA;
	int                   AttackDelayB; // both unused
	int                   EnemyHouseIndex;
	DynamicVectorClass<AngerStruct> AngerNodes; //arghghghgh bugged
	DynamicVectorClass<ScoutStruct> ScoutNodes; // filled with data which is never used, jood gob WW
	TimerStruct unkTimer3;
	TimerStruct unkTimer4;
	int                   ProducingBuildingTypeIndex;
	int                   ProducingUnitTypeIndex;
	int                   ProducingInfantryTypeIndex;
	int                   ProducingAircraftTypeIndex;
	int                   RatioAITriggerTeam;
	int                   RatioTeamAircraft;
	int                   RatioTeamInfantry;
	int                   RatioTeamBuildings;
	int                   BaseDefenseTeamCount;
	DropshipStruct        DropshipData[3];
	int                   CurrentDropshipIndex;
	byte          HasCloakingRanges; // don't ask
	ColorStruct Color;
	ColorStruct LaserColor; // my idb says so
	byte          padding;
	BaseClass Base;
	bool                  RecheckPower;
	bool                  RecheckRadar;
	bool                  SpySatActive;
	bool                  IsBeingDrained;
	Edge                  Edge;
	CellStruct EMPTarget;
	CellStruct NukeTarget;
	DWORD                 Allies;	//flags, one bit per HouseClass instance
	                                        	//-> 32 players possible here
	TimerStruct DamageDelayTimer;
	TimerStruct TeamDelayTimer; // for AI attacks
	TimerStruct unknown_timer_A;
	TimerStruct unknown_timer_B;
	TimerStruct unknown_timer_C;
	TimerStruct unknown_timer_D;
	TimerStruct unknown_timer_E;
	DWORD unknown_57DC;

	unsigned int                    ThreatPosedEstimates[130][130]; // BLARGH

	char PlainName [0x15]; // this defaults to the owner country's name in SP or <human player><computer player> in MP. Used as owner for preplaced map objects
	char UINameString [0x20]; // this contains the UIName= text from the INI! or
	wchar_t UIName [0x15]; // this contains the CSF string from UIName= above, or a copy of the country's UIName if not defined. Take note that this is shorter than the country's UIName can be...
	int                   ColorSchemeIndex;
	CellStruct StartingCell;
	DWORD                 StartingAllies;
	DWORD                 unknown_16060;
	DynamicVectorClass<IConnectionPoint*> WaypointPath;
	DWORD unknown_1607C;
	DWORD unknown_16080;
	DWORD unknown_16084;
	double unused_16088;
	double unused_16090;
	DWORD padding_16098;
	float PredictionEnemyArmor; // defaults to 0.33, AIForcePredictionFudge'd later
	float PredictionEnemyAir;
	float PredictionEnemyInfantry;
	int TotalOwnedInfantryCost;
	int TotalOwnedVehicleCost;
	int TotalOwnedAircraftCost;
	DWORD unknown_160B4;
};
