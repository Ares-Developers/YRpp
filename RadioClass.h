/*
	Base class for WHAT?? I DUNNO =(
*/

#ifndef RADIO_H
#define RADIO_H

#include <MissionClass.h>

//forward declarations
class TechnoClass;

class NOVTABLE RadioClass : public MissionClass
{
public:
	//IPersistStream
	virtual HRESULT __stdcall Load(IStream* pStm) R0;
	virtual HRESULT __stdcall Save(IStream* pStm, BOOL fClearDirty) R0;

	//Destructor
	virtual ~RadioClass() RX;

	//RadioClass

	// these are oogly, westwood themselves admitted it, so it's probably even more of a wtf than the rest
	virtual eRadioCommands SendToFirstLink(eRadioCommands rcDoThis) R0;
	virtual eRadioCommands SendCommand(eRadioCommands rcDoThis, TechnoClass *Link) R0;
	virtual int LinkWith(eRadioCommands rcDoThis, TechnoClass *Target, TechnoClass *Link) R0;
	virtual void SendToEachLink(eRadioCommands rcDoThis) RX;

	TechnoClass* GetNthLink(int idx) const R0;

	//Constructor
	RadioClass() : MissionClass(false)
		{ JMP_THIS(0x65A750); }

protected:
	RadioClass(bool) : MissionClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	eRadioCommands LastCommands [3]; // new command updates these
	VectorClass<TechnoClass*> RadioLinks;	//Docked units etc
};

#endif
