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

	// get specific link
	TechnoClass* const& GetNthLink(int idx = 0) const {
		return this->RadioLinks[idx];
	}

	// whether any link is pLink
	bool ContainsLink(TechnoClass const* pLink) const
		{ JMP_THIS(0x65AD50); }

	// note: null pointers will always return -1
	int FindLinkIndex(TechnoClass const* pLink) const
		{ JMP_THIS(0x65AD90); }

	// iow: not full
	bool HasFreeLink() const
		{ JMP_THIS(0x65ADC0); }

	// iow: not full; consider pIgnore's link empty
	bool HasFreeLink(TechnoClass const* pIgnore) const
		{ JMP_THIS(0x65ADF0); }

	// iow. at least one link used
	bool HasAnyLink() const
		{ JMP_THIS(0x65AE30); }

	// resizes the vector and nulls the new elements
	void SetLinkCount(int count)
		{ JMP_THIS(0x65AE60); }

	//Constructor
	RadioClass() noexcept
		: RadioClass(noinit_t())
	{ JMP_THIS(0x65A750); }

protected:
	explicit __forceinline RadioClass(noinit_t) noexcept
		: MissionClass(noinit_t())
	{ }

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================

public:

	RadioCommand LastCommands[3]; // new command updates these
	VectorClass<TechnoClass*> RadioLinks;	//Docked units etc
};
