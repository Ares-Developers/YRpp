#pragma once

#include <ArrayClasses.h>
#include <GeneralDefinitions.h>

//forward declarations
class AircraftClass;
class CellClass;

class Kamikaze {
public:
	struct KamikazeControl {
		AircraftClass* Item;
		CellClass* Cell;
	};

	static Kamikaze* const Instance;

	Kamikaze() noexcept : UpdateTimer(100), Nodes()
	{ }

	~Kamikaze()
		{ JMP_THIS(0x54E690); }

	void Add(AircraftClass* pAircraft)
		{ JMP_THIS(0x54E3B0); }

	void Remove(AircraftClass* pAircraft)
		{ JMP_THIS(0x54E590); }

	void Update()
		{ JMP_THIS(0x54E4D0); }

	void Clear()
		{ JMP_THIS(0x54E6F0); }

	HRESULT Save(IStream* pStm)
		{ JMP_THIS(0x54E750); }

	HRESULT Load(IStream* pStm)
		{ JMP_THIS(0x54E7B0); }

	TimerStruct UpdateTimer;
	DynamicVectorClass<KamikazeControl*> Nodes;
};
