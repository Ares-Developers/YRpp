#pragma once

#include <ObjectTypeClass.h>

class NOVTABLE IsometricTileTypeClass : public ObjectTypeClass
{
public:
	static const AbstractType AbsID = AbstractType::IsotileType;

	//Array
	static DynamicVectorClass<IsometricTileTypeClass*>* const Array;

	//IPersist
	virtual HRESULT __stdcall GetClassID(CLSID* pClassID) R0;

	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//AbstractClass
	virtual void PointerExpired(AbstractClass* pAbstract, bool removed) RX;
	virtual AbstractType WhatAmI() const RT(AbstractType);
	virtual int Size() const R0;
	virtual void CalculateChecksum(Checksummer& checksum) const RX;

	virtual int GetArrayIndex() const R0;

	//ObjectTypeClass
	virtual CoordStruct* vt_entry_6C(CoordStruct* pDest, CoordStruct* pSrc) const R0;

	virtual bool SpawnAtMapCoords(CellStruct* pMapCoords, HouseClass* pOwner) R0;

	virtual ObjectClass* CreateObject(HouseClass* pOwner) R0;
	virtual void vt_entry_90(DWORD dwUnk) RX;

	virtual SHPStruct* GetImage() const R0;

	//Destructor
	virtual ~IsometricTileTypeClass() RX;

	//Constructor
	IsometricTileTypeClass(int ArrayIndex, int Minus65, int Zero1,
		const char* pName, int Zero2) noexcept
		: IsometricTileTypeClass(noinit_t())
	{ JMP_THIS(0x5447C0); }

protected:
	explicit __forceinline IsometricTileTypeClass(noinit_t) noexcept
		: ObjectTypeClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:
	int ArrayIndex;
	int MarbleMadnessTile;
	int NonMarbleMadnessTile;
	DWORD unk_2A0;
	DynamicVectorClass<Color16Struct*> unk_2A4;
	DWORD unk_2BC;
	int ToSnowTheater;
	int ToTemperateTheater;
	int TileAnimIndex; //Tile%02dAnim, actually an AnimTypeClass array index...
	int TileXOffset; //Tile%02dXOffset
	int TileYOffset; //Tile%02dYOffset
	int TileAttachesTo; //Tile%02dAttachesTo, iso tile index?
	int TileZAdjust; //Tile%02dZAdjust
	DWORD unk_2DC; //0xBF
	bool Morphable;
	bool ShadowCaster;
	bool AllowToPlace; //default true
	bool RequiredByRMG;
	DWORD unk_2E4;
	DWORD unk_2E8;
	DWORD unk_2EC;
	int unk_2F0; //default 1, no idea
	bool unk_2F4; //like always true
	char FileName[0xE]; // WARNING! Westwood strncpy's 0xE bytes into this buffer without NULL terminating it.
	bool AllowBurrowing;
	bool AllowTiberium;
	DWORD unk_308;
};
