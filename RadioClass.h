/*
	Base class for WHAT?? I DUNNO =(
*/

#ifndef RADIO_H
#define RADIO_H

#include <MissionClass.h>

//forward declarations
class TechnoClass;

class RadioClass : public MissionClass
{
public:
	//IPersistStream
	virtual HRESULT _stdcall Load(IStream* pStm) R0;
	virtual HRESULT _stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~RadioClass() RX;

	//ObjectClass

	//RadioClass

	// these are oogly, westwood themselves admitted it, so it's probably even more of a wtf than the rest

	virtual eRadioCommands SendToFirstLink(eRadioCommands rcDoThis) R0;
	virtual eRadioCommands SendCommand(eRadioCommands rcDoThis, TechnoClass *Link) R0;
	virtual int LinkWith(eRadioCommands rcDoThis, TechnoClass *Target, TechnoClass *Link) R0;
	virtual void SendToEachLink(eRadioCommands rcDoThis) RX;

	TechnoClass* GetNthLink(int idx) R0;

	//Constructor
	RadioClass():MissionClass(false)
		{ THISCALL(0x65A750); }

protected:
	RadioClass(bool X):MissionClass(X){}

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY_ARRAY(eRadioCommands, LastCommands, 3); // new command updates these
	PROPERTY_STRUCT(VectorClass<TechnoClass*>,	RadioLinks);	//Docked units etc
};

#endif
