#pragma once

#include <AbstractClass.h>

class HouseClass;
class InfantryClass;

enum class SlaveManagerStatus : unsigned int {
	Ready = 0,
	Scanning = 1,
	Travelling = 2,
	Deploying = 3,
	Working = 4,
	ScanningAgain = 5,
	PackingUp = 6
};

enum class SlaveControlStatus : unsigned int {
	Unknown = 0,
	ScanningForTiberium = 1,
	MovingToTiberium = 2,
	Harvesting = 3,
	BringingItBack = 4,
	Respawning = 5,
	Dead = 6
};

class NOVTABLE SlaveManagerClass : public AbstractClass
{
public:

	struct SlaveControl {
		InfantryClass* Slave;
		SlaveControlStatus State;
		TimerStruct RespawnTimer;
	};

	static DynamicVectorClass<SlaveManagerClass *>* const Array;

	static const AbstractType AbsID = AbstractType::SlaveManager;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SlaveManagerClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	// non-virtual
	void SetOwner(TechnoClass *NewOwner)
		{ JMP_THIS(0x6AF580); }

	void CreateSlave(SlaveControl *Node)
		{ JMP_THIS(0x6AF650); }

	void LostSlave(InfantryClass *Slave)
		{ JMP_THIS(0x6B0A20); }

	// switches the slaves to the killer house with cheers and hoorahs
	// note that this->Owner will be NULL once this function is done
	void Killed(TechnoClass *Killer, HouseClass * ForcedOwnerHouse = nullptr)
		{ JMP_THIS(0x6B0AE0); }

	bool ShouldWakeUpNow()
		{ JMP_THIS(0x6B1020); }

	// the slaves will become free citizens without any announcements or cheers, if you don't call Killed() beforehand
	void ZeroOutSlaves();

	// stops scanning, spawning slaves and driving around.
	void SuspendWork() {
		this->RespawnTimer.StartTime = -1;
		if(!this->RespawnTimer.TimeLeft) {
			this->RespawnTimer.TimeLeft = 1;
		}
	}

	// resumes to harvest automatically.
	void ResumeWork() {
		this->RespawnTimer.Resume();
	}

	//Constructor
	SlaveManagerClass(
		TechnoClass* pOwner, InfantryTypeClass* pSlave, int num, int RegenRate,
		int ReloadRate) noexcept : SlaveManagerClass(noinit_t())
	{ JMP_THIS(0x6AF1A0); }

protected:
	explicit __forceinline SlaveManagerClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

public:

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

	TechnoClass* Owner;
	InfantryTypeClass* SlaveType;
	int SlaveCount;
	int RegenRate;
	int ReloadRate;
	DynamicVectorClass<SlaveControl*> SlaveNodes;
	TimerStruct RespawnTimer;
	SlaveManagerStatus State;
	int LastScanFrame;
};
