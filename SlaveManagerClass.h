#ifndef SLAVEMANAGER_H
#define SLAVEMANAGER_H

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;
class InfantryClass;

class SlaveManagerClass : public AbstractClass
{
public:

	struct SlaveControl {
		public:
		InfantryClass * Slave;
		enum eSlaveState {
				state_Unknown = 0,
				state_ScanningForTiberium = 1,
				state_MovingToTiberium = 2,
				state_Harvesting = 3,
				state_BringingItBack = 4,
				state_Respawning = 5,
				state_Dead = 6,
		}State;
		TimerStruct RespawnTimer;
	};

	static DynamicVectorClass<SlaveManagerClass *>* Array;

	enum {AbsID = abs_SlaveManager};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SlaveManagerClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	SlaveManagerClass(TechnoClass *Owner, InfantryTypeClass *Slave, int num, int RegenRate, int ReloadRate) : AbstractClass(false)
		{ JMP_THIS(0x6AF1A0); }

	// non-virtual
	void SetOwner(TechnoClass *NewOwner)
		{ JMP_THIS(0x6AF580); }

	void CreateSlave(SlaveControl *Node)
		{ JMP_THIS(0x6AF650); }

	void LostSlave(InfantryClass *Slave)
		{ JMP_THIS(0x6B0A20); }

	void Killed(TechnoClass *Killer, HouseClass * ForcedOwnerHouse = NULL)
		{ JMP_THIS(0x6B0AE0); }

	bool ShouldWakeUpNow()
		{ JMP_THIS(0x6B1020); }

	SlaveManagerClass() : AbstractClass(false) { }

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
	enum eSlaveManagerState {
			state_Ready = 0,
			state_Scanning = 1,
			state_Travelling = 2,
			state_Deploying = 3,
			state_Working = 4,
			state_ScanningAgain = 5,
			state_PackingUp = 6,
	} State;
	int LastScanFrame;
};

#endif
