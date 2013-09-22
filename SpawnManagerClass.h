#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;

class SpawnManagerStatus {
public:
	typedef unsigned int Value;
	enum {
		Idle = 0, // no target or out of range
		Launching = 1, // one launch in progress
		CoolDown = 2 // waiting for launch to complete
	};
};

class SpawnNodeStatus {
public:
	typedef unsigned int Value;
	enum {
		Idle = 0, // docked, waiting for target
		TakeOff = 1, // missile tilting and launch
		Preparing = 2, // gathering, waiting
		Attacking = 3, // attacking until no ammo
		Returning = 4, // return to carrier
		//Unused_5, // not used
		Reloading = 6, // docked, reloading ammo and health
		Dead = 7 // respawning
	};
};

struct SpawnNode
{
	TechnoClass* Unit;
	SpawnNodeStatus:: Value Status;
	TimerStruct SpawnTimer;
	BOOL IsSpawnMissile;
};

class SpawnManagerClass : public AbstractClass
{
public:

	static DynamicVectorClass<SpawnManagerClass *>* Array;

	enum {AbsID = abs_SpawnManager};

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~SpawnManagerClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() const R0;
	virtual int Size() const R0;

	//Constructor
	SpawnManagerClass(TechnoClass* pOwner, AircraftTypeClass *SpawnType, int nMaxNodes, int RegenRate, int ReloadRate) : AbstractClass(false)
		{ JMP_THIS(0x6B6C90); }

	// non-virtual
	void KillNodes()
		{ JMP_THIS(0x6B7100); }

	void SetTarget(AbstractClass *Target)
		{ JMP_THIS(0x6B7B90); }

	bool UpdateTarget()
		{ JMP_THIS(0x6B7C40); }

	void ResetTarget()
		{ JMP_THIS(0x6B7BB0); }

	int CountAliveSpawns() const
		{ JMP_THIS(0x6B7D30); }

	int CountDockedSpawns() const
		{ JMP_THIS(0x6B7D50); }

	int CountLaunchingSpawns() const
		{ JMP_THIS(0x6B7D80); }

	void UnlinkPointer()
		{ JMP_THIS(0x6B7C60); }

protected:
	SpawnManagerClass() : AbstractClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	TechnoClass* Owner;
	AircraftTypeClass* SpawnType;
	int SpawnCount;
	int RegenRate;
	int ReloadRate;
	DynamicVectorClass<SpawnNode*> SpawnedNodes;
	TimerStruct UpdateTimer;
	TimerStruct SpawnTimer;
	AbstractClass* Target;
	AbstractClass* NewTarget;
	SpawnManagerStatus::Value Status;
};

#endif
