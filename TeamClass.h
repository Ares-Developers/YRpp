#ifndef TEAM_H
#define TEAM_H

#include <TeamTypeClass.h>

class HouseClass;
class ScriptClass;

class TeamClass : public AbstractClass
{
public:
	//Static
	static DynamicVectorClass<TeamClass*>* Array;

	//IPersist
	virtual HRESULT _stdcall GetClassID(CLSID* pClassID) R0;

	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm,BOOL fClearDirty) R0;

	//Destructor
	virtual ~TeamClass() RX;

	//AbstractClass
	virtual eAbstractType WhatAmI() R0;
	virtual int Size() R0;

	//Constructor
	TeamClass(TeamTypeClass* pType = NULL) : AbstractClass(false)
		JMP_THIS(0x6E8A90);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(TeamTypeClass*, Type);
	PROPERTY(ScriptClass*, CurrentScript);
	PROPERTY(HouseClass*, Owner);
	PROPERTY(DWORD, unknown_30);
	PROPERTY(DWORD, unknown_34);
	PROPERTY(DWORD, unknown_38);
	PROPERTY(DWORD, unknown_3C);
	PROPERTY(DWORD, unknown_40);
	PROPERTY(int, unknown_44);
	PROPERTY(DWORD, unknown_48);
	PROPERTY(DWORD, unknown_4C);
	PROPERTY(int, unknown_frame_50);
	PROPERTY(DWORD, unknown_54);
	PROPERTY_STRUCT(TimerStruct, unknown_timer_60);
};

#endif
