/*
	Base class for WHAT?? I DUNNO =(
*/

#pragma once

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
	virtual RadioCommand SendToFirstLink(RadioCommand command) RT(RadioCommand);
	virtual RadioCommand SendCommand(RadioCommand command, TechnoClass* pRecipient) RT(RadioCommand);
	virtual RadioCommand SendCommandWithData(RadioCommand command, AbstractClass* &pInOut, TechnoClass* pRecipient) RT(RadioCommand);
	virtual void SendToEachLink(RadioCommand command) RX;

	TechnoClass* GetNthLink(int idx) const {
		return this->RadioLinks[idx];
	}

	//Constructor
	RadioClass() : MissionClass(false)
		{ JMP_THIS(0x65A750); }

protected:
	RadioClass(bool) : MissionClass(false) { }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	RadioCommand LastCommands[3]; // new command updates these
	VectorClass<TechnoClass*> RadioLinks;	//Docked units etc
};
