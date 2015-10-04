/*
	RadSites
*/

#pragma once

#include <AbstractClass.h>

class LightSourceClass;
class WeaponTypeClass;

class NOVTABLE RadSiteClass : public AbstractClass
{
public:
	static const AbstractType AbsID = AbstractType::RadSite;

	//Static
	static DynamicVectorClass<RadSiteClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~RadSiteClass() RX;

	//AbstractClass
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;

	//non-virtual
public:
	// Start irradiating an area. Be sure to set the BaseCell, Spread and RadLevel first!
	void Activate()
		{ JMP_THIS(0x65B580); }

	// Remove the radiation effect of this site completely
	void Deactivate()
		{ JMP_THIS(0x65BB50); }

	// Add the radiation of this RadSite to the cells.
	void Radiate()
		{ JMP_THIS(0x65B9C0); }

	// Decrease the radiation of this RadSite by one step.
	void DecreaseRadiation()
		{ JMP_THIS(0x65BD00); }

	// Decrease the cell tint and intensity of this RadSite.
	void DecreaseLight()
		{ JMP_THIS(0x65BE90); }

	// Add this RadLevel to the current radiation.
	void Add(int nRadLevel)
		{ JMP_THIS(0x65B530); }

	// Gets the current rad level (corresponds to the RadLevel at BaseCell).
	int GetRadLevel()
		{ JMP_THIS(0x65B510); }

	// Gets the rad level applied by this RadSite to a certain cell.
	int GetRadLevelAt(CellStruct* pCell)
		{ JMP_THIS(0x65B8F0); }

	// Sets the rad level and the appropriate duration values.
	void SetRadLevel(int nRadLevel)
		{ JMP_THIS(0x65B4F0); }

	// Sets the center cell. Do not change when RadSite is activated.
	void SetBaseCell(CellStruct* pCell)
		{ JMP_THIS(0x65B4C0); }

	// Gets the spread in cells.
	void GetSpread()
		{ JMP_THIS(0x65B4B0); }

	// Sets the spread in cells. Also updates the SpreadInLeptons.
	void SetSpread(int nCells)
		{ JMP_THIS(0x65B4D0); }

	//helper methods

	// Gets the current strenght of the effect, the ratio between time left and initial duration.
	double GetEffectPercentage() {
		return (this->RadDuration <= 0) ? 0.0 :
			static_cast<double>(this->RadTimeLeft) / static_cast<double>(this->RadDuration);
	}

	//Constructor
	RadSiteClass()
		: RadSiteClass(noinit_t())
	{ JMP_THIS(0x65B1E0); }

	RadSiteClass(CellStruct nBaseCoords, int nSpread, int nRadLevel) noexcept
		: RadSiteClass()
	{
		SetBaseCell(&nBaseCoords);
		SetSpread(nSpread);
		SetRadLevel(nRadLevel);
	}

protected:
	explicit __forceinline RadSiteClass(noinit_t) noexcept
		: AbstractClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	LightSourceClass* LightSource; // the light source attached to this instance
	TimerStruct       RadLevelTimer; // used to count down RadLevelDelay
	TimerStruct       RadLightTimer; // used to count down RadLightDelay
	CellStruct        BaseCell; // center cell
	int               Spread; // range in cells
	int               SpreadInLeptons; // range in leptons
	int               RadLevel; // the radiation level, 
	int               LevelSteps; // cell's rad level reduced by (RadLevel/LevelSteps) every time RadLevelTimer elapses
	int               Intensity; // the intensity at the beginning
	TintStruct        Tint; // RadColor at the current level
	int               IntensitySteps; // the number of intensity decreases during the duration
	int               IntensityDecrement; // Intensity decremented by this every time RadLightDelay elapses
	int               RadDuration; // as currently set up, the rad site will stay for so many frames
	int               RadTimeLeft; // the remaining frames. divided by RadDuration gives the factor
};
