#ifndef SPAWNMANAGER_H
#define SPAWNMANAGER_H

#include <AbstractClass.h>

class HouseClass;
class TechnoClass;

struct SpawnNode
{
	TechnoClass* Unit;
	enum eSpawnState {
				state_Idle = 0,
				state_Launching = 1,
				state_Approaching = 2,
				state_Firing = 3,
				state_Returning = 4,
				state_Dead = 7
		} Status;
	TimerStruct SpawnTimer;
	bool IsSpawnMissile;
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

	void SpawnMissingNodes()
		{ JMP_THIS(0x6B7BB0); }

	int CountReadySpawns1() const
		{ JMP_THIS(0x6B7D30); }

	int CountReadySpawns2() const
		{ JMP_THIS(0x6B7D50); }

	int CountReadySpawns3() const
		{ JMP_THIS(0x6B7D80); }

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
	TimerStruct UnknownTimer;
	TimerStruct SpawnTimer;
	int Destination;
	int Target;
	int SomeTimestamp;
};

#endif
